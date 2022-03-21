// Class1Name.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(Class1Name)
#include "VBto_Converter.h"
#include "math.h"
//}}VBto_Converter_Class_Global



class Class1Name
{
public:

	//{{VBto_Converter_Class_Public(Class1Name)
	
	void myEvent(CString p0);
	void Method1(double p);
	void PublicMethod1(int p1, CVBtoArray <float> &p2);
	void PrivateMethod1(int p1, CString p2);
	bool PrivateFunction1(int p1, CString p2);
	double Function1(double p, double pV, double& pR);
	CString PublicFunction1(int p1, CString p2);
	void SetXYZ(float Value);
	double GetDist();
	Class1Name();
	~Class1Name();
	//}}VBto_Converter_Class_Public
	 float xx;
	 float yy;
	 float zz; // Private

// To fire this event, use RaiseEvent with the following syntax:
// RaiseEvent myEvent[(arg1, arg2, ... , argn)]

};
