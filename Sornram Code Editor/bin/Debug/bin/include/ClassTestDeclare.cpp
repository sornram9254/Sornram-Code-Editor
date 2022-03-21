// ClassTestDeclare.cpp : implementation file

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CClassTestDeclare)
//}}VBto_Converter_Includes

#include "ClassTestDeclare.h"



	//=========================================================


 typedef	bool (WINAPI*GetComputerName_ClassPrivateTD)(char* lpBuffer, int* nSize);
 GetComputerName_ClassPrivateTD GetComputerName_ClassPrivatePtr;
bool GetComputerName_ClassPrivateWrp(CString& lpBuffer, int& nSize) {
	bool ret = GetComputerName_ClassPrivatePtr(lpBuffer.LockBuffer(), &nSize);
	lpBuffer.UnlockBuffer();
	return ret;
}

CString ClassTestDeclare::TestDeclareFromClass()
{
	CString TestDeclareFromClass;
	 CString sC,  sM2; int sz; 

	sC = CString(' ',512);
	sz = sC.GetLength();
	GetComputerName_ClassPrivateWrp(sC, sz);
	sC = sC.Left(sz);

	sM2 = CString(' ',512);
	sz = sM2.GetLength();
	GetComputerName_ModulePublicWrp(sM2, sz);
	sM2 = sM2.Left(sz);

	if (sC==sM2) {
		TestDeclareFromClass = sC; // All Ok
	} else {
		TestDeclareFromClass = "Error in TestDeclareFromClass";
	}
	return TestDeclareFromClass;
}

//========================================================
class OnStartupGetProcAddress_ClassTestDeclareCLS {
public:
	OnStartupGetProcAddress_ClassTestDeclareCLS() {
		GetComputerName_ClassPrivatePtr = (GetComputerName_ClassPrivateTD) GetAddress("kernel32", "GetComputerNameA");
	}
} m_OnStartupGetProcAddress_ClassTestDeclareCLS;

