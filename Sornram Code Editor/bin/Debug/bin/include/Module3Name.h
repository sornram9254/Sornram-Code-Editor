// Module3Name.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(Module3Name)
#include "math.h"
//}}VBto_Converter_Class_Global

	//{{VBto_Converter_Class_Public(Module3Name)
 
 void SubCounter();
 void SetXYZ(float Value);
 double GetDist();
	//}}VBto_Converter_Class_Public
 extern double PublicD;
 extern bool GlobalB;

struct myPoint2D
{
	 float x; 
	 float y; 
};


struct myPoint3D
{
	 myPoint2D xy; 
	// VBto upgrade warning: zz As double	OnWrite(float)
	 double zz; 
};

