// Class1Name.cpp : implementation file

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CClass1Name)
//}}VBto_Converter_Includes

#include "Class1Name.h"



	//=========================================================


struct myTypePrivate_Class1
{
	 float x; 
	 int c; 
	 CString S; 
};

//? void Class1Name::myEvent(CString p0);

// ! Public
void Class1Name::Method1(double p)
{
	// 
}

void Class1Name::PublicMethod1(int p1, CVBtoArray <float> &p2)
{
	// 
}

void Class1Name::PrivateMethod1(int p1, CString p2)
{
	// 
}

bool Class1Name::PrivateFunction1(int p1, CString p2)
{
	bool PrivateFunction1 = false;
	PrivateFunction1 = true;
	return PrivateFunction1;
}

// ! Public
double Class1Name::Function1(double p, double pV, double& pR)
{
	double Function1 = 0;
	Function1 = p+pV+pR;
	pR = Function1;
	return Function1;
}

CString Class1Name::PublicFunction1(int p1, CString p2)
{
	CString PublicFunction1;
	PublicFunction1 = "Hello from PublicFunction1";
	return PublicFunction1;
}

void Class1Name::SetXYZ(float Value)
{
	xx = Value;
	yy = Value;
	zz = yy;
}

// ! Public
double Class1Name::GetDist()
{
	double GetDist = 0;
	GetDist = sqrt(xx*xx+yy*yy+zz*zz);
	return GetDist;
}

// ---------- STARTUP/SHUTDOWN ---------------------------------------------

Class1Name::Class1Name()
{
	AfxMessageBox("Class1Name.Class_Initialize()");
}

Class1Name::~Class1Name()
{
	AfxMessageBox("Class1Name.Class_Terminate()");
}
