// Module2Name.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(Module2Name)
#include "Module3Name.h"
#include "Module1Name.h"
//}}VBto_Converter_Class_Global

	//{{VBto_Converter_Class_Public(Module2Name)
 
 void Module2Sub1(CString buf);
	//}}VBto_Converter_Class_Public

struct myType
{
	 double Version; 
	 double Price; 
};

 extern myType mtModule2Public;
