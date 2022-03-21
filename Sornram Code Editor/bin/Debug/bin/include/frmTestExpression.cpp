// frmTestExpression.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestExpression)
//}}VBto_Converter_Includes

#include "frmTestExpression.h"
CfrmTestExpression *frmTestExpression = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestExpression dialog



CfrmTestExpression::CfrmTestExpression(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestExpression::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestExpression) frmTestExpression = this;
}

void CfrmTestExpression::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestExpression)
	DDX_Control(pDX, CmdTest, m_CmdTest);
	DDX_Control(pDX, ListBoxResults, m_ListBoxResults);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestExpression, CDialog)
	//{{AFX_MSG_MAP(CfrmTestExpression)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(CmdTest, OnCmdTest)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestExpression message handlers

BOOL CfrmTestExpression::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestExpression)
	
	Form_Load();
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestExpression::OnPaint() 
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
HCURSOR CfrmTestExpression::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================

void CfrmTestExpression::Form_Load()
{
	RunAllTest();
}

void CfrmTestExpression::OnCmdTest()
{
	// TODO: Add your control notification handler code here
	RunAllTest();
}

void CfrmTestExpression::RunAllTest()
{
	ErrorsString = "";
	m_ListBoxResults.ResetContent();

	TestMod();
	TestPow();
	m_ListBoxResults.AddString("---------------------------------------------------------");
	TestBoolean();
	m_ListBoxResults.AddString("---------------------------------------------------------");
	TestBitwise();
	m_ListBoxResults.AddString("---------------------------------------------------------");
	TestConversionToC();

	if (ErrorsString!="") {
		AfxMessageBox(ErrorsString,MB_ICONEXCLAMATION);
	} else {
		::MessageBox(NULL, "Congratulation:"+CString("\r\n")+"\r\n"+"All Tests is Ok !!!","VBto Converter Test",MB_ICONINFORMATION);
	}
}

void CfrmTestExpression::TestMod()
{

	 short i,  j; int nErr; 
	nErr = 0;
	for(i=-121; i<=121; i++) {
		for(j=1; j<=11; j++) {
			 float m1,  m2,  r; double delta; 

			m1 = i /  j;
			m1 = (int)(CSng(i)) /  j;
			m1 = i / (int)( CSng(j));
			m1 = (float)((int)(CSng(i)) / (int)( CDbl(j)));

			m2 = i %  j;

#if !VBtoVCNET
			m2 = i % (int)( CSng(j));
			m2 = (int)(CSng(i)) %  j;
			m2 = (float)((int)(CSng(i)) % (int)( CDbl(j)));

#endif

			r = j*(i /  j)+i %  j;
			delta = abs(r-i);
			if (delta>=0.00001) nErr += 1;
		}
	}

	 CString Mess; 
	if (nErr==0) {
		Mess = "Ok on test:    ";
	} else {
		Mess = "Error on test  ";
	}

	Mess += "\"j * (i \\ j) + i Mod j  =  i\"";
	m_ListBoxResults.AddString(Mess);

}

void CfrmTestExpression::TestPow()
{

	 float m1,  m2; double r,  delta; 
	m1 = 2;
	m2 = 5;
	// r = 2 ^ 5
	// r = 2 ^ 5#
	r = pow(2., 5);
	r = pow(2., 5.);
	r = pow(m1,  m2);
	delta = abs(r-32);

	 CString Mess; 
	if (delta<=0.00001) {
		Mess = "Ok on test:    ";
	} else {
		Mess = "Error on test  ";
	}

	Mess += "\"2 ^ 5 = 32\"";
	m_ListBoxResults.AddString(Mess);

}

void CfrmTestExpression::TestBoolean()
{
	 bool b1,  b2; 
	b1 = 6>-2; // True
	VerifyBooleanValues("6 > -2", b1, true);

	b2 = !(6>-2);
	VerifyBooleanValues("Not (6 > -2)", b2, false);

	VerifyBooleanValues("b1 And b2", b1 && b2, false);
	VerifyBooleanValues("b1 Or b2", b1 || b2, true);
	VerifyBooleanValues("b1 Xor b2", b1 ^ b2, true);

}

void CfrmTestExpression::TestBitwise()
{
	// VBto upgrade warning: ir As short	OnWrite(int)
	 short i1,  i2,  ir; 
	i1 = 3; // 0 + 2 + 1
	i2 = 6; // 4 + 2 + 0

	ir = i1 & i2;
	VerifyIntValues("i1 And i2", ir, 2);

	ir = i1 | i2;
	VerifyIntValues("i1 Or i2", ir, 7);

	ir = i1 ^ i2;
	VerifyIntValues("i1 Xor i2", ir, 5);
	VerifyIntValues("i1 Xor i2", i1 ^ i2, 5);

	ir =  ~( ~i1);
	VerifyIntValues("Not (Not i1)", ir, 3);

}

void CfrmTestExpression::TestConversionToC()
{
	// VBto upgrade warning: A As short	OnWrite(short, double)
	 short A; CString S; 

	A = 5;
	A += 2;
	VerifyIntValues("A += 2", A, 7);

	A -= 3;
	VerifyIntValues("A -= 3", A, 4);

	A *= 5;
	VerifyIntValues("A *= 5", A, 20);

	A /= 4;
	VerifyIntValues("A /= 4", A, 5);

	A += 2+7*3;
	VerifyIntValues("A += 2 + 7 * 3", A, 28);

	A += -3+9;
	VerifyIntValues("A += - 3 + 9", A, 34);

	A = A*5+2;
	VerifyIntValues("A = A * 5 + 2", A, 172);

	A = Round((double)A / 4+1);
	VerifyIntValues("A = A / 4 + 1", A, 44);

	A /= 11;
	VerifyIntValues("A /= 11", A, 4);

	S = "ab";
	S += "cd";
	VerifyStrValues("S += \"cd\"", S, "abcd");

	S += CString("12")+"34";
	VerifyStrValues("S += \"12\" + \"34\"", S, "abcd1234");

	S = "!"+S;
	VerifyStrValues("S = \"!\" + S", S, "!abcd1234");

}

void CfrmTestExpression::VerifyBooleanValues(CString TestName, bool pB, bool vB)
{

	if (pB!=vB) {
		 CString errS; 
		errS = "Error on test \""+TestName+"\"   ";

		if (ErrorsString!="") ErrorsString += CString("\r\n")+"\r\n";
		ErrorsString += errS;

		m_ListBoxResults.AddString(errS);
	} else {
		m_ListBoxResults.AddString("Ok on test \""+TestName+"\"");
	}

}

void CfrmTestExpression::VerifyIntValues(CString TestName, short pI, short vI)
{

	if (pI!=vI) {
		 CString errS; 
		errS = "Error on test \""+TestName+"\"   "+Str(pI)+" <> "+Str(vI);

		if (ErrorsString!="") ErrorsString += CString("\r\n")+"\r\n";
		ErrorsString += errS;

		m_ListBoxResults.AddString(errS);
	} else {
		m_ListBoxResults.AddString("Ok on test \""+TestName+"\"");
	}

}

void CfrmTestExpression::VerifyStrValues(CString TestName, CString ps, CString vS)
{

	if (ps!=vS) {
		 CString errS; 
		errS = "Error on test \""+TestName+"\"   \""+ps+"\" <> \""+vS+"\"";

		if (ErrorsString!="") ErrorsString += CString("\r\n")+"\r\n";
		ErrorsString += errS;

		m_ListBoxResults.AddString(errS);
	} else {
		m_ListBoxResults.AddString("Ok on test \""+TestName+"\"");
	}

}
