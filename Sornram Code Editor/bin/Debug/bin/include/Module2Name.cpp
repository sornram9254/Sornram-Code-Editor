// Module2Name.cpp : implementation file

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CModule2Name)
//}}VBto_Converter_Includes

#include "Module2Name.h"



	//=========================================================

 static myType mtModule2Dim; // Private
 myType mtModule2Public;
 static myType mtModule2Private;

// Public
void Module2Sub1(CString buf)
{

	 myType mt; 
	mt.Version = 2.1;

	 myPoint2D p2; myPoint3D p3; 
	p2.x = 11;
	p3.zz = p2.x;

	mySub(buf, "from Module2");
}
