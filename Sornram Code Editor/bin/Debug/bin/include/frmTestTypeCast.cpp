// frmTestTypeCast.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestTypeCast)
//}}VBto_Converter_Includes

#include "frmTestTypeCast.h"
CfrmTestTypeCast *frmTestTypeCast = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestTypeCast dialog



CfrmTestTypeCast::CfrmTestTypeCast(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestTypeCast::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestTypeCast) frmTestTypeCast = this;
}

void CfrmTestTypeCast::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestTypeCast)
	DDX_Control(pDX, CmdTestTypeCast, m_CmdTestTypeCast);
	DDX_Control(pDX, ListBoxResults, m_ListBoxResults);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestTypeCast, CDialog)
	//{{AFX_MSG_MAP(CfrmTestTypeCast)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(CmdTestTypeCast, OnCmdTestTypeCast)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestTypeCast message handlers

BOOL CfrmTestTypeCast::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestTypeCast)
	pp0 = ppI = 0;	ppL = 0;	ppF = 0;	ppD = 0;	ppC = 0;
	ppB = 0;
	ppY = 0;
	
	Form_Load();
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestTypeCast::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this); // device context for painting


		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CfrmTestTypeCast::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================

// This is a part of the VBto Converter (www.vbto.net)
// Copyright (C) 2005-2010 StressSoft Company Ltd. All rights reserved.

 const short ccI=60; 
 const short ccL=65; 
 const double ccF=60.1; 
 const double ccD=70.1; 
 const CString ccS="80"; 
 const double ccC=169.95; 

 const short c0=50; 
 const short cI=60;  // - Integer
 const int cL=65;  // - Long
 const float cF=60.1f;  // - Single
 const double cD=70.1;  // - Double
 const CString cS="80";  // - String
 const double cC=169.95;  // - Currency
 const bool ccB=true;  // - Boolean





void CfrmTestTypeCast::Form_Load()
{
	// RunAllTest
}

void CfrmTestTypeCast::OnCmdTestTypeCast()
{
	// TODO: Add your control notification handler code here
	RunAllTest();
}

void CfrmTestTypeCast::RunAllTest()
{
	ErrorsString = "";
	m_ListBoxResults.ResetContent();

	Test0();
	Test1();

	if (ErrorsString!="") {
		AfxMessageBox(ErrorsString,MB_ICONEXCLAMATION);
	} else {
		::MessageBox(NULL, "Congratulation:"+CString("\r\n")+"\r"+"\n"+"All Tests is Ok !!!","VBto Converter Test",MB_ICONINFORMATION);
	}
}

void CfrmTestTypeCast::Test0()
{
	 short pI; 

	pI = 111;
	VerifyIntValues("Decimal 111", pI, 111);

	pI = 0x111;
	VerifyIntValues("Hex &H111", pI, 273);

	pI = 0xABC;
	VerifyIntValues("Hex &HABC", pI, 2748);

	pI = 0111;
	VerifyIntValues("Oct &O111", pI, 73);

	pI = 0123;
	VerifyIntValues("Oct &O123", pI, 83);

}

void CfrmTestTypeCast::Test1()
{

	pp0 = c0;

	ppI = cI;
	ppL = cI;
	ppF = cI;
	ppD = cI;
	ppS = ToString(cI);
	ppC = cI;
	ppB = bool(cI);

	ppI = cL;
	ppL = cL;
	ppF = (float)(cL);
	ppD = cL;
	ppS = ToString(cL);
	ppC = cL;
	ppB = 0!=(cL);

	ppI = Round(cF);
	ppL = Round(cF);
	ppF = cF;
	ppD = cF;
	ppS = ToString(cF);
	ppC = cF;
	ppB = 0!=(cF);

	ppI = Round(cD);
	ppL = Round(cD);
	ppF = (float)(cD);
	ppD = cD;
	ppS = ToString(cD);
	ppC = cD;
	ppB = 0!=(cD);

	ppI = Round(cS);
	ppL = Round(cS);
	ppF = (float)StrToDouble(cS);
	ppD = StrToDouble(cS);
	ppS = cS;
	ppC = (float)StrToDouble(cS);
	ppB = CBool(cS);

	ppI = (int)(cC);
	ppL = (int)(cC);
	ppF = (float)(cC);
	ppD = cC;
	ppS = ToString(cC);
	ppC = cC;
	ppB = 0!=(cC);

	ppI = ccB;
	ppL = ccB;
	ppF = ccB;
	ppD = ccB;
	ppS = Str(ccB);
	ppC = ccB;
	ppB = ccB;

	// VBto upgrade warning: pI As short	OnWrite(int, double, CString)
	// VBto upgrade warning: pL As int	OnWrite(int, double, CString)
	// VBto upgrade warning: pF As float	OnWrite(int, double, CString)
	// VBto upgrade warning: pD As double	OnWrite(int, double, CString)
	// VBto upgrade warning: pS As CString	OnWrite(int, double, CString)
	// VBto upgrade warning: pB As bool	OnWrite(int, double, CString, bool)
	// VBto upgrade warning: pC As double	OnWrite(int, double, CString, double)
	 short pI; int pL; float pF; double pD; CString pS; bool pB; double pC; 

	pI = 11;
	pL = 14-2;
	pF = (10+2)*2-11;
	pD = 2*7;
	pC = 10+1;
	pS = ToString(10+5);
	pB = bool(10-10);
	VerifyValues("= const Integer", pI, 11, pL, 12, pF, 13, pD, 14, pC, 11, pS, "15", pB, false);

	pI = Round(2.1);
	pL = Round(2+0.2);
	pF = (float)(2+0.3);
	pD = 2+0.4;
	pC = 2+0.49;
	pS = ToString(2+0.5);
	pB = 0!=(0.1);
	VerifyValues("= const Double A", pI, 2, pL, 2, pF, 2.3, pD, 2.4, pC, 2.49, pS, "2.5", pB, true);

	pI = Round(2+0.6);
	pL = Round(2+0.7);
	pF = (float)(2+0.8);
	pD = 2+0.9;
	pC = 10.01;
	pS = ToString(2+0.99);
	pB = 0!=(0.9);
	VerifyValues("= const Double B", pI, 3, pL, 3, pF, 2.8, pD, 2.9, pC, 10.01, pS, "2.99", pB, true);

	pI = Round(-3.1);
	pL = Round(-3.2);
	pF = (float)(-3.3);
	pD = -3.4;
	pC = -3.49;
	pS = ToString(-3.5);
	pB = 0!=(-0.1);
	VerifyValues("= - const Double A", pI, -3, pL, -3, pF, -3.3, pD, -3.4, pC, -3.49, pS, "-3.5", pB, true);

	pI = Round(-3.6);
	pL = Round(-3.7);
	pF = (float)(-3.8);
	pD = -3.9;
	pC = -3.92;
	pS = ToString(-3.99);
	pB = 0!=(-0.9);
	VerifyValues("= - const Double B", pI, -4, pL, -4, pF, -3.8, pD, -3.9, pC, -3.92, pS, "-3.99", pB, true);

	pI = Round("31");
	pL = Round("3"+CString("2"));
	pF = (float)StrToDouble("3"+CString("3"));
	pD = StrToDouble("3"+CString("4"));
	pC = 0; // ? "3"
	pS = "3"+CString("5");
	pB = CBool("True");
	VerifyValues("= const String", pI, 31, pL, 32, pF, 33, pD, 34, pC, 0, pS, "35", pB, true);

	 short cpI;  cpI = 123;
	pI = cpI;
	pL = cpI;
	pF = cpI;
	pD = cpI;
	pC = cpI;
	pS = ToString(cpI);
	pB = CBool("False");
	VerifyValues("= Integer", pI, 123, pL, 123, pF, 123, pD, 123, pC, 123, pS, "123", pB, false);

	 int cpL;  cpL = 456;
	pI = cpL;
	pL = cpL;
	pF = (float)(cpL);
	pD = cpL;
	pC = cpL;
	pS = ToString(cpL);
	pB = 0!=(cpL);
	VerifyValues("= Long", pI, 456, pL, 456, pF, 456, pD, 456, pC, 456, pS, "456", pB, true);

	 float cpF;  cpF = (float)(456.123);
	pI = Round(cpF);
	pL = Round(cpF);
	pF = cpF;
	pD = cpF;
	pC = cpF;
	pS = ToString(cpF);
	pB = 0!=(cpF);
	VerifyValues("= Single 1", pI, 456, pL, 456, pF, 456.123, pD, 456.123, pC, 456.123, pS, "456.123", pB, true);

	cpF = (float)(456.789);
	pI = Round(cpF);
	pL = Round(cpF);
	pF = cpF;
	pD = cpF;
	pC = cpF;
	pS = ToString(cpF);
	pB = 0!=(cpF);
	VerifyValues("= Single 2", pI, 457, pL, 457, pF, 456.789, pD, 456.789, pC, 456.789, pS, "456.789", pB, true);

	 double cpD;  cpD = -456.123;
	pI = Round(cpD);
	pL = Round(cpD);
	pF = (float)(cpD);
	pD = cpD;
	pC = cpD;
	pS = ToString(cpD);
	pB = 0!=(cpD-cpD);
	VerifyValues("= Double 1", pI, -456, pL, -456, pF, -456.123, pD, -456.1239, pC, -456.123, pS, "-456.123", pB, false);

	cpD = -456.789;
	pI = Round(cpD);
	pL = Round(cpD);
	pF = (float)(cpD);
	pD = cpD;
	pC = cpD;
	pS = ToString(cpD);
	pB = 0!=(cpD);
	VerifyValues("= Double 2", pI, -457, pL, -457, pF, -456.789, pD, -456.789, pC, -456.789, pS, "-456.789", pB, true);

	 CString cpS;  cpS = "91";
	pI = Round(cpS);
	pL = Round(cpS);
	pF = (float)StrToDouble(cpS);
	pD = StrToDouble(cpS);
	pC = (float)StrToDouble(cpS);
	pS = cpS;
	pB = CBool(cpS);
	VerifyValues("= String", pI, 91, pL, 91, pF, 91, pD, 91, pC, 91, pS, "91", pB, true);


	// VBto upgrade warning: cpV As CComVariant	OnWrite(short, bool)
	 CComVariant cpV; 
	cpV = cI;
	cpV = cL;
	cpV = cF;
	cpV = cD;
	cpV = cS;
	cpV = cC;
	cpV = ccB;

	cpV = 92;

	pI = (int)Val(cpV);
	pL = (int)Val(cpV);
	pF = (float)Val(cpV);
	pD = Val(cpV);
	pC = Val(cpV);
	pS = Str(cpV);
	pB = Val(cpV) ? true : false;;
	VerifyValues("= Variant", pI, 92, pL, 92, pF, 92, pD, 92, pC, 92, pS, "92", pB, true);

	// --------------------------------------------------------------------

	// Function Val(String As String) As Double   Returns the numbers contained in a string
	cpS = "182";
	pI = Round(Val(cpS));
	pL = Round(Val(cpS));
	pF = (float)(Val(cpS));
	pD = Val(cpS);
	pC = Val(cpS);
	pS = ToString(Val(cpS));
	pB = 0!=(Val(cpS));
	VerifyValues("= Val(String)", pI, 182, pL, 182, pF, 182, pD, 182, pC, 182, pS, "182", pB, true);

	// --------------------------------------------------------------------
	// Function CInt(Expression) As Integer   Converts an expression to an Integer
	// Function CLng(Expression) As Long      Converts an expression to a Long
	// Function CSng(Expression) As Single    Converts an expression to a Single
	// Function CDbl(Expression) As Double    Converts an expression to a Double
	// Function CStr(Expression) As String    Converts an expression to a String
	// Function CBool(Expression) As Boolean  Converts an expression to a Boolean
	// Function CCur(Expression) As Currency  Converts an expression to a Currency
	cpS = "18";
	pI = CInt(cpS);
	pL = CLng(cpS);
	pF = CSng(cpS);
	pD = CDbl(cpS);
	pC = CDbl(cpS);
	pS = CStr(cpS);
	pB = CBool(cpS);
	VerifyValues("= Cxxx(String)", pI, 18, pL, 18, pF, 18, pD, 18, pC, 18, pS, "18", pB, true);

	pI = CInt(19.1);
	pL = CLng(19.2);
	pF = CSng(19.3);
	pD = CDbl(19.4);
	pC = CDbl(19.5);
	pS = CStr("19.6");
	pB = CBool(0);
	VerifyValues("= Cxxx(19.1)", pI, 19, pL, 19, pF, 19.3, pD, 19.4, pC, 19.5, pS, "19.6", pB, false);

	pI = CInt(19.6);
	pL = CLng(19.7);
	pF = CSng(19.8);
	pD = CDbl(19.9);
	pC = CDbl(19.91);
	pS = CStr("19.92");
	pB = CBool(19.9);
	VerifyValues("= Cxxx(19.6)", pI, 20, pL, 20, pF, 19.8, pD, 19.9, pC, 19.91, pS, "19.92", pB, true);

	pI = CInt(-19.1);
	pL = CLng(-19.2);
	pF = CSng(-19.3);
	pD = CDbl(-19.4);
	pC = CDbl(-19.49);
	pS = CStr("-19.5");
	pB = CBool(-19.5);
	VerifyValues("= Cxxx(-19.1)", pI, -19, pL, -19, pF, -19.3, pD, -19.4, pC, -19.49, pS, "-19.5", pB, true);

	pI = CInt(-19.6);
	pL = CLng(-19.7);
	pF = CSng(-19.8);
	pD = CDbl(-19.9);
	pC = CDbl(-19.91);
	pS = CStr("-19.9");
	pB = CBool(-19.9);
	VerifyValues("= Cxxx(-19.6)", pI, -20, pL, -20, pF, -19.8, pD, -19.9, pC, -19.91, pS, "-19.9", pB, true);

	// --------------------------------------------------------------------

	// Function Int(Number)  Returns the integer portion of a number
	pI = 100+Int(21); // !!! change to 21.0 for C# VS 2005
	pL = 100+Int(21.1);
	pF = 100+Int(21.3);
	pD = 100+Int(21.6);
	pC = 100+Int(21.7);
	pS = ToString(100+Int(21.8));
	pB = CBool("true");
	VerifyValues("= Int(121)", pI, 121, pL, 121, pF, 121, pD, 121, pC, 121, pS, "121", pB, true);

	pI = -100+Int(-21); // !!! change to -21.0 for C# VS 2005
	pL = -100+Int(-21.1);
	pF = -100+Int(-21.3);
	pD = -100+Int(-21.6);
	pC = -100+Int(-21.7);
	pS = ToString(-100+Int(-21.8));
	pB = CBool("false");
	VerifyValues("= Int(-121)", pI, -121, pL, -122, pF, -122, pD, -122, pC, -122, pS, "-122", pB, false);

	// Function Fix(Number)   Returns the integer portion of a number
	pI = 200+int(31);
	pL = 200+int(31.1);
	pF = 200+int(31.3);
	pD = 200+int(31.6);
	pC = 200+int(31.8);
	pS = ToString(200+int(31.9));
	pB = CBool("fALSE");
	VerifyValues("= Fix(231)", pI, 231, pL, 231, pF, 231, pD, 231, pC, 231, pS, "231", pB, false);

	pI = -200+int(-31);
	pL = -200+int(-31.1);
	pF = -200+int(-31.3);
	pD = -200+int(-31.6);
	pC = -200+int(-31.8);
	pS = ToString(-200+int(-31.9));
	pB = CBool("tRUE");
	VerifyValues("= Fix(-31)", pI, -231, pL, -231, pF, -231, pD, -231, pC, -231, pS, "-231", pB, true);

	// Function Round(Number, [NumDigitsAfterDecimal As Long])  Round to a given number of decimal places
	pI = 300+Round(41.);
	pL = 300+Round(41.1);
	pF = 300+Round(41.3);
	pD = 300+Round(41.6);
	pC = 300+Round(41.8);
	pS = ToString(300+Round(41.9));
	pB = CBool("false");
	VerifyValues("= Round(41)", pI, 341, pL, 341, pF, 341, pD, 342, pC, 342, pS, "342", pB, false);

	pI = -300+Round(-41.);
	pL = -300+Round(-41.1);
	pF = -300+Round(-41.3);
	pD = -300+Round(-41.6);
	pC = -300+Round(-41.8);
	pS = ToString(-300+Round(-41.9));
	pB = CBool("TRUE");
	VerifyValues("= Round(41.1)", pI, -341, pL, -341, pF, -341, pD, -342, pC, -342, pS, "-342", pB, true);

	// --------------------------------------------------------------------
	pI = 101;
	pL = 102;
	pF = (float)(103.45);
	pD = 104.56;

	// Function Str(Number)  Returns a string representation of a number
	pS = Str(12);
	VerifyStrValues("Str(const Integer)", pS, " 12");

	pS = Str(-12);
	VerifyStrValues("Str(const Integer)", pS, "-12");

	pS = Str(12.34);
	VerifyStrValues("Str(const Double)", pS, " 12.34");

	pS = Str(-12.34);
	VerifyStrValues("Str(const Double)", pS, "-12.34");

	pS = Str(12+0.34);
	VerifyStrValues("Str(const Double)", pS, " 12.34");

	pS = Str(pI);
	VerifyStrValues("Str(Integer)", pS, " 101");

	pS = Str(pI+1-1);
	VerifyStrValues("Str(Integer)", pS, " 101");

	pS = Str(pL);
	VerifyStrValues("Str(Double)", pS, " 102");

	pS = Str(pF);
	VerifyStrValues("Str(Double)", pS, " 103.45");

	pS = Str(pD);
	VerifyStrValues("Str(Double)", pS, " 104.56");

	pB = true;
	pS = Str(pB);
	VerifyStrValues("Str(Boolean)", pS, " True");

	pB = false;
	pS = Str(pB);
	VerifyStrValues("Str(Boolean)", pS, " False");

	// --------------------------------------------------------------------

	// Formats an expression
	pS = FormatVB(11+1);
	VerifyStrValues("Format(const Integer)", pS, "12");

	pS = FormatVB(10+2,"#0");
	VerifyStrValues("Format(const Integer)", pS, "12");

	pS = FormatVB(12,"#000");
	VerifyStrValues("Format(const Integer)", pS, "012");


	pS = FormatVB(12.34);
	VerifyStrValues("Format(12.34)", pS, "12.34");

	pS = FormatVB(12.34,"#0.0");
	VerifyStrValues("Format(12.34, \"#0.0\")", pS, "12.3");

	pS = FormatVB(12.34,"#0.00");
	VerifyStrValues("Format(12.34, \"#0.00\")", pS, "12.34");

	pS = FormatVB(12.34,"#000.000");
	VerifyStrValues("Format(12.34, \"#000.000\")", pS, "012.340");


	pS = FormatVB(pI);
	VerifyStrValues("Format(Integer)", pS, "101");

	pS = FormatVB(pL);
	VerifyStrValues("Format(Long)", pS, "102");

	pS = FormatVB(pF);
	VerifyStrValues("Format(Single)", pS, "103.45");

	pS = FormatVB(pD);
	VerifyStrValues("Format(Double)", pS, "104.56");

	// --------------------------------------------------------------------

	// Function Space(Number As Long)    Returns a string consisting of the specified number of spaces
	pS = CString(' ',3);
	VerifyStrValues("Space(3)", pS, "   ");

	// Function String(Number As Long, Character)    Returns a repeating character string of the length specified
	pS = CString("!?"[0], 3);
	VerifyStrValues("String(3, \"!?\")", pS, "!!!");

	// Function Hex(Number)      Returns a string representing the hexadecimal value of a number
	pS = Hex(33);
	VerifyStrValues("Hex(33)", pS, "21");

	// Function Oct(Number)      Returns a string representing the octal value of a number
	pS = Oct(33);
	VerifyStrValues("Oct(33)", pS, "41");

}

// VBto upgrade warning: pF As double	OnWrite(float)
// VBto upgrade warning: vC As double	OnWrite(short, double)
void CfrmTestTypeCast::VerifyValues(CString TestName, short pI, int vI, int pL, int vL, double pF, double vF, double pD, double vD, double pC, double vC, CString pS, CString vS, bool pB, bool vB)
{

	 CString S; double delta; 
	S = "";

	if (pI!=vI) {
		S = AddErrLine(S, "Integer", FormatVB(pI), FormatVB(vI));
	}

	if (pL!=vL) {
		S = AddErrLine(S, "Long", FormatVB(pL), FormatVB(vL));
	}

	if (pF!=vF) {
		delta = pF-vF;
		if (delta<0) delta = -delta;
		if (delta>=0.001) {
			S = AddErrLine(S, "Single", FormatVB(pF), FormatVB(vF));
		}
	}

	if (pD!=vD) {
		delta = pD-vD;
		if (delta<0) delta = -delta;
		if (delta>=0.001) {
			S = AddErrLine(S, "Double", FormatVB(pD), FormatVB(vD));
		}
	}

	if (pC!=vC) {
		delta = CDbl(pC)-CDbl(vC);
		if (delta<0) delta = -delta;
		if (delta>=0.001) {
			S = AddErrLine(S, "Currency", FormatVB(pC), FormatVB(vC));
		}
	}

	if (isDiff(pS, vS)) {
		S = AddErrLine(S, "String", pS, vS);
	}

	if (pB!=vB) {
		S = AddErrLine(S, "Boolean", Str(pB), Str(vB));
	}

	if (S=="") {
		m_ListBoxResults.AddString("Ok on test \""+TestName+"\"");
	} else {
		m_ListBoxResults.AddString("Error on test \""+TestName+"\"");

		if (ErrorsString!="") ErrorsString += CString("\r\n")+"\r\n";
		ErrorsString += ("Test \""+TestName+"\":"+S);
	}

}

void CfrmTestTypeCast::VerifyIntValues(CString TestName, short pI, short vI)
{

	if (pI!=vI) {
		 CString S; 
		S = "";

		S = AddErrLine(S, "Integer", Str(pI), Str(vI));
		if (ErrorsString!="") ErrorsString += CString("\r\n")+"\r\n";
		ErrorsString += ("Test \""+TestName+"\":"+S);

		m_ListBoxResults.AddString("Error on test \""+TestName+"\"   "+Str(pI)+" <> "+Str(vI));
	} else {
		m_ListBoxResults.AddString("Ok on test \""+TestName+"\"");
	}

}

void CfrmTestTypeCast::VerifyStrValues(CString TestName, CString pS, CString vS)
{


#if VBtoJSNET || VBtoVCNET
	pS = Trim(pS);
	vS = Trim(vS);

#endif

	if (isDiff(pS, vS)) {
		m_ListBoxResults.AddString("Error on test \""+TestName+"\"");
		 CString S; 
		S = AddErrLine("", "String", pS, vS);
		if (ErrorsString!="") ErrorsString += CString("\r\n")+"\r\n";
		ErrorsString += ("Test \""+TestName+"\":"+S);
	} else {
		m_ListBoxResults.AddString("Ok on test \""+TestName+"\"");
	}

}

bool CfrmTestTypeCast::isDiff(CString pS, CString vS)
{
	bool isDiff = false;

	if (pS==vS) { isDiff = false; return isDiff; }

	if (pS.GetLength()!=vS.GetLength()) { isDiff = true; return isDiff; }

	isDiff = false;
	// VBto upgrade warning: i As short	OnWrite(int)
	 short i; CString pCh,  vCh; 
	for(i=1; i<=pS.GetLength(); i++) {
		pCh = CString(pS).Mid(i-1, 1);
		vCh = CString(vS).Mid(i-1, 1);
		if (pCh!=vCh) {
			if (((pCh!=".") && (pCh!=",")) || ((vCh!=".") && (vCh!=","))) {
				isDiff = true;
				return isDiff;
			}
		}
	}

	return isDiff;
}

CString CfrmTestTypeCast::AddErrLine(CString S, CString sType, CString pS, CString vS)
{
	CString AddErrLine;
	if (sType=="String") {
		AddErrLine = S+"\r\n"+"Error on compare "+sType+":  \""+pS+"\" <> \""+vS+"\"";
	} else {
		AddErrLine = S+"\r\n"+"Error on compare "+sType+":    "+pS+"   <>   "+vS;
	}
	return AddErrLine;
}
