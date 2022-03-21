// Module1Name.cpp : implementation file

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CModule1Name)
//}}VBto_Converter_Includes

#include "Module1Name.h"



	//=========================================================

void PrivateSub(CString buf, CString titl)
{
	::MessageBox(NULL, buf,titl,MB_OK);
}

// ! Public
void mySub(CString buf, CString titl)
{
	PrivateSub(buf, titl);
}

bool Module1Func1(CString buf)
{
	bool Module1Func1 = false;
	 myType mtModule1Dim; 
	mtModule1Dim.Price = 12.3;

	mtModule2Public.Version = 1.1;

	mySub(buf, "from Module1");
	Module1Func1 = true;
	return Module1Func1;
}
