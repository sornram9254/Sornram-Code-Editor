/***
*dbgrpt.c - Debug CRT Reporting Functions
*
*       Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:
*
*******************************************************************************/

#ifdef _DEBUG

#include <internal.h>
#include <mtdll.h>
#include <malloc.h>
#include <mbstring.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <tchar.h>
#include <dbgint.h>
#include <signal.h>
#include <string.h>
#include <awint.h>
#include <windows.h>
#include <errno.h>
#include <intrin.h>

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

/*---------------------------------------------------------------------------
 *
 * Debug Reporting
 *
 --------------------------------------------------------------------------*/

extern _CRT_REPORT_HOOK _pfnReportHook;
extern ReportHookNode *_pReportHookList;
extern ReportHookNodeW *_pReportHookListW;
extern IMAGE_DOS_HEADER __ImageBase;

_CRTIMP int __cdecl _VCrtDbgReportA(
        int nRptType,
        void * returnAddress,
        const char * szFile,
        int nLine,
        const char * szModule,
        const char * szFormat,
        va_list arglist
        );

_CRTIMP int __cdecl _VCrtDbgReportW(
        int nRptType,
        void * returnAddress,
        const wchar_t * szFile,
        int nLine,
        const wchar_t * szModule,
        const wchar_t * szFormat,
        va_list arglist
        );

static const wchar_t * const _CrtDbgModeMsg[_CRT_ERRCNT] =
    {
        L"Warning",
        L"Error",
        L"Assertion Failed"
    };

/* We use a Unicode buffer for debug output message,
 * so both strings below are Unicode, albeit with different formatting.
 */
#ifdef _UNICODE
#define OUT_MSG_FORMAT_STRING  L"Debug %s!\n\nProgram: %s%s%s%s%s%s%s%s%s%s%s%s"   \
                               L"\n\n(Press Retry to debug the application)\n"
#else  /* _UNICODE */
#define OUT_MSG_FORMAT_STRING  L"Debug %s!\n\nProgram: %hs%s%s%hs%s%hs%s%hs%s%s%hs%s"   \
                               L"\n\n(Press Retry to debug the application)\n"
#endif  /* _UNICODE */

#define MORE_INFO_STRING       L"\n\nFor information on how your program can cause an assertion"   \
                               L"\nfailure, see the Visual C++ documentation on asserts."


/***
*_CRT_REPORT_HOOK _CrtSetReportHook2() - configure client report hook in list
*
*Purpose:
*       Install or remove a client report hook from the report list.  Exists
*       separately from _CrtSetReportHook because the older function doesn't
*       work well in an environment where DLLs that are loaded and unloaded
*       dynamically out of LIFO order want to install report hooks.
*       This function exists in 2 forms - ANSI & UNICODE
*
*Entry:
*       int mode - _CRT_RPTHOOK_INSTALL or _CRT_RPTHOOK_REMOVE
*       _CRT_REPORT_HOOK pfnNewHook - report hook to install/remove/query
*
*Exit:
*       Returns -1 if an error was encountered, with EINVAL or ENOMEM set,
*       else returns the reference count of pfnNewHook after the call.
*
*Exceptions:
*       Input parameters are validated. Refer to the validation section of the function.
*
*******************************************************************************/
_CRTIMP int __cdecl _CrtSetReportHookT2(
        int mode,
        _CRT_REPORT_HOOKT pfnNewHook
        )
{
        ReportHookNodeT *p;
        int ret = 0;

        /* validation section */
        _VALIDATE_RETURN(mode == _CRT_RPTHOOK_INSTALL || mode == _CRT_RPTHOOK_REMOVE, EINVAL, -1);
        _VALIDATE_RETURN(pfnNewHook != NULL, EINVAL, -1);

        _mlock(_DEBUG_LOCK);
        __try
        {

        /* Search for new hook function to see if it's already installed */
        for (p = _pReportHookListT; p != NULL; p = p->next)
            if (p->pfnHookFunc == pfnNewHook)
                break;

        if (mode == _CRT_RPTHOOK_REMOVE)
        {
            /* Remove request - free list node if refcount goes to zero */
            if (p != NULL)
            {
                if ((ret = --p->refcount) == 0)
                {
                    if (p->next)
                        p->next->prev = p->prev;
                    if (p->prev)
                        p->prev->next = p->next;
                    else
                        _pReportHookListT = p->next;
                    _free_crt(p);
                }
            }
            else
            {
                _ASSERTE(("The hook function is not in the list!",0));
                ret = -1;
                errno = EINVAL;
            }
        }
        else
        {
            /* Insert request */
            if (p != NULL)
            {
                /* Hook function already registered, move to head of list */
                ret = ++p->refcount;
                if (p != _pReportHookListT)
                {
                    if (p->next)
                        p->next->prev = p->prev;
                    p->prev->next = p->next;
                    p->prev = NULL;
                    p->next = _pReportHookListT;
                    _pReportHookListT->prev = p;
                    _pReportHookListT = p;
                }
            }
            else
            {
                /* Hook function not already registered, insert new node */
                p = (ReportHookNodeT *)_malloc_crt(sizeof(ReportHookNodeT));
                if (p == NULL)
                {
                    /* malloc fails: we do not assert here */
                    ret = -1;
                    errno = ENOMEM;
                }
                else
                {
                    p->prev = NULL;
                    p->next = _pReportHookListT;
                    if (_pReportHookListT)
                        _pReportHookListT->prev = p;
                    ret = p->refcount = 1;
                    p->pfnHookFunc = pfnNewHook;
                    _pReportHookListT = p;
                }
            }
        }

        }
        __finally {
            _munlock(_DEBUG_LOCK);
        }

        return ret;
}


static TCHAR * dotdotdot = _T("...");
#define MAXLINELEN 64
#define DOTDOTDOTSZ 3

/***
*int _CrtDbgReport() - primary reporting function
*
*Purpose:
*       Display a message window with the following format.
*
*       ================= Microsft Visual C++ Debug Library ================
*
*       {Warning! | Error! | Assertion Failed!}
*
*       Program: c:\test\mytest\foo.exe
*       [Module: c:\test\mytest\bar.dll]
*       [File: c:\test\mytest\bar.c]
*       [Line: 69]
*
*       {<warning or error message> | Expression: <expression>}
*
*       [For information on how your program can cause an assertion
*        failure, see the Visual C++ documentation on asserts]
*
*       (Press Retry to debug the application)
*
*       ===================================================================
*
*Entry:
*       int             nRptType    - report type
*       void *          returnAddress - return address of caller
*       const TCHAR *    szFile      - file name
*       int             nLine       - line number
*       const TCHAR *    szModule    - module name
*       const TCHAR *    szFormat    - format string
*       ...                         - var args
*
*Exit:
*       if (MessageBox)
*       {
*           Abort -> aborts
*           Retry -> return TRUE
*           Ignore-> return FALSE
*       }
*       else
*           return FALSE
*
*Exceptions:
*       If something goes wrong, we do not assert, but we return -1.
*
*******************************************************************************/
__inline int __cdecl _CrtDbgReportTV(
        int nRptType,
        void * returnAddress,
        const TCHAR * szFile,
        int nLine,
        const TCHAR * szModule,
        const TCHAR * szFormat,
        va_list arglist
        )
{
    return _VCrtDbgReportT(nRptType,returnAddress,szFile,nLine,szModule,szFormat,arglist);
}

_CRTIMP int __cdecl _CrtDbgReportT(
        int nRptType,
        const TCHAR * szFile,
        int nLine,
        const TCHAR * szModule,
        const TCHAR * szFormat,
        ...
        )
{
    int retval;
    va_list arglist;

    va_start(arglist,szFormat);

    retval = _CrtDbgReportTV(nRptType, _ReturnAddress(), szFile, nLine, szModule, szFormat, arglist);

    va_end(arglist);

    return retval;
}

/***
*int __crtMessageWindow() - report to a message window
*
*Purpose:
*       put report into message window, allow user to choose action to take
*
*Entry:
*       int             nRptType      - report type
*       const TCHAR *    szFile        - file name
*       const TCHAR *    szLine        - line number
*       const TCHAR *    szModule      - module name
*       const TCHAR *    szUserMessage - user message
*
*Exit:
*       if (MessageBox)
*       {
*           Abort -> aborts
*           Retry -> return TRUE
*           Ignore-> return FALSE
*       }
*       else
*           return FALSE
*
*Exceptions:
*       If something goes wrong, we do not assert, but we simply return -1,
*       which will trigger the debugger automatically (the same as the user
*       pressing the Retry button).
*
*******************************************************************************/

int __cdecl __crtMessageWindow(
        int nRptType,
        void * returnAddress,
        const TCHAR * szFile,
        const TCHAR * szLine,
        const TCHAR * szModule,
        const TCHAR * szUserMessage
        )
{
        int nCode;
        TCHAR *szShortProgName;
        const TCHAR *szShortModuleName = NULL ;
        TCHAR szExeName[MAX_PATH + 1];
        wchar_t szOutMessage[DBGRPT_MAX_MSG];
        int szlen = 0;
        HMODULE hModule = NULL;

        if (szUserMessage == NULL)
            return 1;

        if (!GetModuleHandleExW(GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT | GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, (LPCWSTR)returnAddress, &hModule))
        {
            hModule = NULL;
        }
#ifdef CRTDLL
        else if (hModule == (HMODULE)&__ImageBase)
        {
            // This is CRT DLL.  Use the EXE instead
            hModule = NULL;
        }
#endif  /* CRTDLL */

        /* Shorten program name */
        szExeName[MAX_PATH] = _T('\0');
        if (!GetModuleFileName(hModule, szExeName, MAX_PATH))
            _ERRCHECK(_tcscpy_s(szExeName, MAX_PATH, _T("<program name unknown>")));

        szShortProgName = szExeName;

        if (_tcslen(szShortProgName) > MAXLINELEN)
        {
        szShortProgName += _tcslen(szShortProgName) - MAXLINELEN;

        /* Only replace first (sizeof(TCHAR) * DOTDOTDOTSZ) bytes to ellipsis */
        _ERRCHECK(memcpy_s(szShortProgName, sizeof(TCHAR) * (MAX_PATH - (szShortProgName - szExeName)), dotdotdot, sizeof(TCHAR) * DOTDOTDOTSZ));
        }

        /* Shorten module name */
        if (szModule && _tcslen(szModule) > MAXLINELEN)
        {
            szShortModuleName = szModule + _tcslen(szModule) - MAXLINELEN + 3;
        }

        _ERRCHECK_SPRINTF(szlen = _snwprintf_s(szOutMessage, DBGRPT_MAX_MSG, DBGRPT_MAX_MSG - 1,
            OUT_MSG_FORMAT_STRING,
            _CrtDbgModeMsg[nRptType],
            szShortProgName,
            szModule ? L"\nModule: " : L"",
            szShortModuleName ? L"..." : L"",
            szShortModuleName ? szShortModuleName : (szModule ? szModule : _T("")),
            szFile ? L"\nFile: " : L"",
            szFile ? szFile : _T(""),
            szLine ? L"\nLine: " : L"",
            szLine ? szLine : _T(""),
            szUserMessage[0] ? L"\n\n" : L"",
            szUserMessage[0] && _CRT_ASSERT == nRptType ? L"Expression: " : L"",
            szUserMessage[0] ? szUserMessage : _T(""),
            _CRT_ASSERT == nRptType ? MORE_INFO_STRING : L""));

        if (szlen < 0)
            _ERRCHECK(wcscpy_s(szOutMessage, DBGRPT_MAX_MSG, _CRT_WIDE(DBGRPT_TOOLONGMSG)));

        /* Report the warning/error */
        nCode = __crtMessageBoxW(szOutMessage,
                             L"Microsoft Visual C++ Runtime Library",
                             MB_TASKMODAL|MB_ICONHAND|MB_ABORTRETRYIGNORE|MB_SETFOREGROUND);

        /* Abort: abort the program */
        if (IDABORT == nCode)
        {
            /* note that it is better NOT to call abort() here, because the
             * default implementation of abort() will call Watson
             */

            /* raise abort signal */
            raise(SIGABRT);

            /* We usually won't get here, but it's possible that
               SIGABRT was ignored.  So exit the program anyway. */
            _exit(3);
        }

        /* Retry: return 1 to call the debugger */
        if (IDRETRY == nCode)
            return 1;

        /* Ignore: continue execution */
        return 0;
}

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* _DEBUG */

