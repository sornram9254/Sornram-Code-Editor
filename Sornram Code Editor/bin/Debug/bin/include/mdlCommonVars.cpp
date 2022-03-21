// mdlCommonVars.cpp : implementation file

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CmdlCommonVars)
//}}VBto_Converter_Includes

#include "mdlCommonVars.h"



	//=========================================================

 CString ErrorsString;

 static double mxValue;


void SetextProp(double xValue)
{
	mxValue = xValue;
}
double GetextProp()
{
	double extProp = 0;
	extProp = 2*mxValue;
	return extProp;
}
Property_extProp extProp;


short GetextPropI()
{
	short extPropI = 0;
	extPropI = Round(3*mxValue);
	return extPropI;
}
void SetextPropI(short iValue)
{
	mxValue = iValue;
}
Property_extPropI extPropI;



void xSub1(short iValue)
{
	xSub2(iValue);
}
void xSub2(short iValue)
{
	// iValue = 23
	// xSub3 iValue
}
//#define defUse_xSub3
#ifdef defUse_xSub3
void xSub3(short iValue)
{
}
#endif

//#define defUse_unUseFun
#ifdef defUse_unUseFun
CString unUseFun(CString par)
{
	CString unUseFun;
	return unUseFun;
}
#endif
