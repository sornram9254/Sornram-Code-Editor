// ModuleTestDeclare.cpp : implementation file

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CModuleTestDeclare)
//}}VBto_Converter_Includes

#include "ModuleTestDeclare.h"



	//=========================================================


 typedef	bool (WINAPI*GetComputerName_ModulePublicTD)(char* lpBuffer, int* nSize);
 GetComputerName_ModulePublicTD GetComputerName_ModulePublicPtr;
bool GetComputerName_ModulePublicWrp(CString& lpBuffer, int& nSize) {
	bool ret = GetComputerName_ModulePublicPtr(lpBuffer.LockBuffer(), &nSize);
	lpBuffer.UnlockBuffer();
	return ret;
}

 typedef	bool (WINAPI*GetComputerName_ModulePrivateTD)(char* lpBuffer, int* nSize);
 GetComputerName_ModulePrivateTD GetComputerName_ModulePrivatePtr;
bool GetComputerName_ModulePrivateWrp(CString& lpBuffer, int& nSize) {
	bool ret = GetComputerName_ModulePrivatePtr(lpBuffer.LockBuffer(), &nSize);
	lpBuffer.UnlockBuffer();
	return ret;
}

 GetSystemMetrics_ModulePublicTD GetSystemMetrics_ModulePublicPtr;

CString TestDeclareFromModule()
{
	CString TestDeclareFromModule;
	 CString sM1; int sz; 
	sM1 = CString(' ',512);
	sz = sM1.GetLength();
	GetComputerName_ModulePrivateWrp(sM1, sz);
	TestDeclareFromModule = sM1.Left(sz);
	return TestDeclareFromModule;
}

//========================================================
class OnStartupGetProcAddress_ModuleTestDeclareBAS {
public:
	OnStartupGetProcAddress_ModuleTestDeclareBAS() {
		GetComputerName_ModulePublicPtr = (GetComputerName_ModulePublicTD) GetAddress("kernel32", "GetComputerNameA");
		GetComputerName_ModulePrivatePtr = (GetComputerName_ModulePrivateTD) GetAddress("kernel32", "GetComputerNameA");
		GetSystemMetrics_ModulePublicPtr = (GetSystemMetrics_ModulePublicTD) GetAddress("User32", "GetSystemMetrics");
	}
} m_OnStartupGetProcAddress_ModuleTestDeclareBAS;

