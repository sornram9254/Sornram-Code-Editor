// frmTestOnError.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestOnError)
//}}VBto_Converter_Includes

#include "frmTestOnError.h"
CfrmTestOnError *frmTestOnError = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestOnError dialog



CfrmTestOnError::CfrmTestOnError(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestOnError::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestOnError) frmTestOnError = this;
}

void CfrmTestOnError::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestOnError)
	DDX_Control(pDX, Label1, m_Label1);
	DDX_Control(pDX, LabelResult, m_LabelResult);
	DDX_Control(pDX, Label2, m_Label2);
	DDX_Control(pDX, UpDownDenom, m_UpDownDenom);
	DDX_Control(pDX, TextDenom, m_TextDenom);
	DDX_Control(pDX, ComboTest, m_ComboTest);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestOnError, CDialog)
	//{{AFX_MSG_MAP(CfrmTestOnError)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(ComboTest, SelchangeComboTest)
	ON_WM_VSCROLL()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestOnError message handlers

BOOL CfrmTestOnError::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestOnError)
	m_UpDownDenom	.SetBuddy(GetDlgItem(TextDenom));
	m_UpDownDenom	.SetRange(0, 3);
	m_UpDownDenom	.SetPos(2);
	
	m_TextDenom	.SetWindowText("2");	//from 'UpDownDenom'
	
	fm_Label1.Set(GetDlgItem(Label1), GetSysColor(COLOR_BTNTEXT), GetSysColor(COLOR_BTNFACE),"MS Sans Serif",12,true,false,false,false,RUSSIAN_CHARSET);
	fm_LabelResult.Set(GetDlgItem(LabelResult), GetSysColor(COLOR_BTNTEXT), GetSysColor(COLOR_BTNFACE),"MS Sans Serif",12,true,false,false,false,RUSSIAN_CHARSET);
	fm_Label2.Set(GetDlgItem(Label2), GetSysColor(COLOR_HIGHLIGHT), GetSysColor(COLOR_BTNFACE),"MS Sans Serif",9.75,false,false,false,false,RUSSIAN_CHARSET);
	
	
	Form_Load();
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestOnError::OnPaint() 
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
HCURSOR CfrmTestOnError::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================
// This is a part of the VBto Converter (www.vbto.net)
// Copyright (C) 2005-2006 StressSoft Company Ltd. All rights reserved.


void CfrmTestOnError::Form_Load()
{
	m_ComboTest.AddString("Test \"Raise\"");
	m_ComboTest.AddString("Test1");

#if VB6 || VBtoVBNET || VBtoVCMFC	// Or VBtoCSNET Or VBtoJSNET Or VBtoBuilder Or VBtoDelphi
	m_ComboTest.AddString("Test2");

#endif

	m_ComboTest.SetCurSel(1);
	RunTest();
}
void CfrmTestOnError::SelchangeComboTest()
{
	// TODO: Add your control notification handler code here
	m_Label1.SetWindowText((m_ComboTest.GetCurSel()==1 ? "Raise" : "12  /  "));
	RunTest();
}
void CfrmTestOnError::UpDownDenom_Change()
{
	RunTest();
}

void CfrmTestOnError::RunTest()
{
	switch (m_ComboTest.GetCurSel()) {
		case 0:
		{

			TestRaise();
			break;
		}
		case 1:
		{
			Test1();
			break;
		}
		case 2:
		{
			Test2();
			break;
		}
	} //end switch
}

void CfrmTestOnError::myAction()
{
	m_LabelResult.SetWindowText("");
	DoEvents();
	// VBto upgrade warning: Res As int	OnWrite(double)
	 int Res,  Denom; 
	Denom = m_UpDownDenom.GetPos32();
	Res = Round((double)12 / Denom);
	m_LabelResult.SetWindowText("  = "+Str(Res));
}

void CfrmTestOnError::myOnException(CString NameException)
{
	 CString ErrMes; 
	ErrMes = "Exception \""+NameException+"\"";
	m_LabelResult.SetWindowText("  =  "+ErrMes);

#if VB6 || VBtoVBNET || VBtoCSNET || VBtoJSNET	// Or VBtoVCMFC Or VBtoBuilder Or VBtoDelphi
	if (Err.Number!=0) {
		ErrMes += CString("\r\n")+"Err.Number = "+Str(Err.Number); // - Returns a numeric value representing an error
		ErrMes += CString("\r\n")+"Err.Description = \""+Err.Description+"\""; // - Returns the string expression containing a descriptive string associated with an object
	}

#endif
	::MessageBox(NULL, ErrMes,NameException,MB_ICONSTOP);
}

void CfrmTestOnError::TestRaise()
{
	// ...
	try {	// On Error GoTo OnErrorRaise
		// ...
		 short iVal; 
		iVal = m_UpDownDenom.GetPos32();
		throw((0+512+iVal)) /*? ,"my Exception "+Str(iVal) */; // - Generates a run-time error

#if And_So_On
		throw(iVal);

#endif

	} catch(...) {	// OnErrorRaise:
		myOnException("OnErrorRaise");
		// ...
		return;

	}
}

void CfrmTestOnError::Test1()
{
	// ...
	try {	// On Error GoTo OnErrorLabel1
		// ...
		myAction();
		// ...
		return;

	} catch(...) {	// OnErrorLabel1:
		// ...
		myOnException("OnErrorLabel1");
		// ...
	}
}

void CfrmTestOnError::Test2()
{
	enum EnumvOnErrorGoToLabel {
	curOnErrorGoToLabel_Default = 0,
		curOnErrorGoToLabel_OnErrorLabel20,
		curOnErrorGoToLabel_OnErrorLabel21
	};
	EnumvOnErrorGoToLabel vOnErrorGoToLabel = curOnErrorGoToLabel_Default;
	try {

#if !VBtoJSNET
		// ...
		 /*? On Error GoTo 0 */
		// ...
		vOnErrorGoToLabel = curOnErrorGoToLabel_OnErrorLabel20; /* On Error GoTo OnErrorLabel20 */
		// ...
		if (2==2) goto JumpOverOnError;
		// ...
		vOnErrorGoToLabel = curOnErrorGoToLabel_OnErrorLabel21; /* On Error GoTo OnErrorLabel21 */
		// ...
	JumpOverOnError: ;
		// ...
		myAction();
		// ...
		return;

	OnErrorLabel20: ;
		myOnException("OnErrorLabel20");
		// ...
		return;

	OnErrorLabel21: ;
		myOnException("OnErrorLabel21");
		// ...

#endif

	} catch(...) {
		switch(vOnErrorGoToLabel) {
			default:
			case curOnErrorGoToLabel_Default:
				// ...
				break;
			case curOnErrorGoToLabel_OnErrorLabel20:
				//? goto OnErrorLabel20;
				break;
			case curOnErrorGoToLabel_OnErrorLabel21:
				//? goto OnErrorLabel21;
				break;
		}
	}
}

// On Error Resume Next
// Resume Next
// Err.Clear  ' - Clears all property settings of the Err object


void CfrmTestOnError::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: Add your message handler code here and/or call default

	short Button, Shift; float x, y;
	Button = Shift = 0;
	x = y = 0;

	switch(pScrollBar->GetDlgCtrlID())
	{
		case UpDownDenom: {
			if (nSBCode==SB_ENDSCROLL) {
				UpDownDenom_Change();
				break;
			}

			break;
		}

	}

	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}
HBRUSH CfrmTestOnError::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch(pWnd->GetDlgCtrlID()) {
		case Label1:	return fm_Label1	.OnCtlColor(pDC);
		case LabelResult:	return fm_LabelResult	.OnCtlColor(pDC);
		case Label2:	return fm_Label2	.OnCtlColor(pDC);
	}
	return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}
