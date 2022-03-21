// Module3Name.cpp : implementation file

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CModule3Name)
//}}VBto_Converter_Includes

#include "Module3Name.h"



	//=========================================================

 static short DimI; // - Private
 static int Counter;
 double PublicD;
 static CString PrivateString; float PrivateSingle;
 bool GlobalB;


struct myPoint1D
{
	 float xx; 
};

// ! Public
 static myPoint3D ppp;

// Comment1
void SubCounter()
{
	Counter += 1;
}

// Comment2
void SetXYZ(float Value)
{
	ppp.xy.x = Value;
	ppp.xy.y = Value;
	ppp.zz = Value;
	SubCounter();
}

// ! Public
double GetDist()
{
	double GetDist = 0;
	Counter -= 1;
	GetDist = sqrt(ppp.xy.x*ppp.xy.x+ppp.xy.y*ppp.xy.y+ppp.zz*ppp.zz);
	return GetDist;
}
