// ModuleTestDeclare.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(ModuleTestDeclare)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global

	//{{VBto_Converter_Class_Public(ModuleTestDeclare)
 
 CString TestDeclareFromModule();
	//}}VBto_Converter_Class_Public

 bool GetComputerName_ModulePublicWrp(CString& lpBuffer, int& nSize);
 typedef	int (WINAPI*GetSystemMetrics_ModulePublicTD)(int nIndex);
 extern GetSystemMetrics_ModulePublicTD GetSystemMetrics_ModulePublicPtr;