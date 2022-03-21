// mdlCommonVars.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(mdlCommonVars)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global

	//{{VBto_Converter_Class_Public(mdlCommonVars)
 
 void SetextProp(double xValue);
 double GetextProp();
 VBtoConverter_Property(double,extProp)
  
 short GetextPropI();
 void SetextPropI(short iValue);
 VBtoConverter_Property(short,extPropI)
  
 void xSub1(short iValue);
 void xSub2(short iValue);
 void xSub3(short iValue);
 CString unUseFun(CString par);
	//}}VBto_Converter_Class_Public
 extern CString ErrorsString;
