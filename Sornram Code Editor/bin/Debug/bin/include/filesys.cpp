// filesys.cpp -- filesystem support functions
#include <yvals.h>

#include <filesystem>

 #if __EDG__
#pragma diag_suppress=161	/* unknown pragma */
#pragma diag_suppress=174	/* expression has no effect */
#pragma diag_suppress=177	/* variable declared but never references */
#pragma diag_suppress=748	/* calling convention specified more than once */
#pragma diag_suppress=940	/* missing return statement */
 #endif /* __EDG__ */

#include <wrapwin.h>

#include <direct.h>
#include <string.h>
#include <io.h>
#include <awint.h>

#define _FILE_ATTRIBUTE_REGULAR	\
	(FILE_ATTRIBUTE_ARCHIVE \
	| FILE_ATTRIBUTE_COMPRESSED \
	| FILE_ATTRIBUTE_ENCRYPTED \
	| FILE_ATTRIBUTE_HIDDEN \
	| FILE_ATTRIBUTE_NORMAL \
	| FILE_ATTRIBUTE_NOT_CONTENT_INDEXED \
	| FILE_ATTRIBUTE_OFFLINE \
	| FILE_ATTRIBUTE_READONLY \
	| FILE_ATTRIBUTE_SPARSE_FILE \
	| FILE_ATTRIBUTE_SYSTEM \
	| FILE_ATTRIBUTE_TEMPORARY)

_STD_BEGIN
namespace tr2 {
	namespace sys {
static file_type _Map_mode(int _Mode)
	{	// map Windows file attributes to file_status
	if ((_Mode & FILE_ATTRIBUTE_DIRECTORY) != 0)
		return (directory_file);
	else if ((_Mode & _FILE_ATTRIBUTE_REGULAR) != 0)
		return (regular_file);
	else
		return (type_unknown);
	}

_FS_DLL void __CLRCALL_PURE_OR_CDECL _Close_dir(void *_Handle)
	{	// close a directory
	FindClose((HANDLE)_Handle);
	}

 #define FILESYS_WIDE	1
 #include "filesys.h"

 #define FILESYS_WIDE	0
 #include "filesys.h"

	}	//namespace sys
}	// namespace tr2
_STD_END

/*
 * Copyright (c) 1992-2012 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V6.00:0009 */
