// frmTestExtConsts.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestExtConsts)
//}}VBto_Converter_Includes

#include "frmTestExtConsts.h"
CfrmTestExtConsts *frmTestExtConsts = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestExtConsts dialog



CfrmTestExtConsts::CfrmTestExtConsts(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestExtConsts::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestExtConsts) frmTestExtConsts = this;
}

void CfrmTestExtConsts::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestExtConsts)
	DDX_Control(pDX, Label1, m_Label1);
	DDX_Control(pDX, ListBoxMsg, m_ListBoxMsg);
	DDX_Control(pDX, CmdRunTest, m_CmdRunTest);
	DDX_Control(pDX, Frame1, m_Frame1);
	DDX_Control(pDX, OptAll, m_OptAll);
	DDX_Control(pDX, OptWarningOnly, m_OptWarningOnly);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestExtConsts, CDialog)
	//{{AFX_MSG_MAP(CfrmTestExtConsts)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(OptAll, OnOptAll)
	ON_BN_CLICKED(OptWarningOnly, OnOptWarningOnly)
	ON_BN_CLICKED(CmdRunTest, OnCmdRunTest)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestExtConsts message handlers

BOOL CfrmTestExtConsts::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestExtConsts)
	m_CommonDialog1 = new CFileDialog(TRUE);
	m_OptAll	.SetCheck(BST_CHECKED);
	flOutWarningOnly = 0;
	nWarn = 0;
	
	Form_Load();
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestExtConsts::OnPaint() 
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
HCURSOR CfrmTestExtConsts::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================
// This is a part of the VBto Converter (www.vbto.net)
// Copyright (C) 2005-2008 StressSoft Company Ltd. All rights reserved.





void CfrmTestExtConsts::Form_Load()
{
	flOutWarningOnly = false;
	 bool b; CString s; COLORREF c; 
	b = false; s = "\r\n";
	b = true; s = '\t'; c = 0xFFFF00;
	// RunTest
	CmdRunTest_Click();
}

void CfrmTestExtConsts::OnOptAll()
{
	// TODO: Add your control notification handler code here
	flOutWarningOnly = false;
	RunTest();
}
void CfrmTestExtConsts::OnOptWarningOnly()
{
	// TODO: Add your control notification handler code here
	flOutWarningOnly = true;
	RunTest();
}
void CfrmTestExtConsts::OnCmdRunTest()
{
	// TODO: Add your control notification handler code here
	RunTest();
}
void CfrmTestExtConsts::CmdRunTest_Click()
{
	OnCmdRunTest();
}


// VBto upgrade warning: vCurrentValue As CComVariant	OnWrite(VBA.VbMsgBoxStyle, VBA.VbMsgBoxResult, VBA.VbFileAttribute, VBA.VbAppWinStyle, VBA.VbDayOfWeek, VBRUN.FormBorderStyleConstants, VBRUN.KeyCodeConstants, VBRUN.ShiftConstants, VBRUN.FillStyleConstants, MSComDlg.ErrorConstants, COLORREF, , CString)
void CfrmTestExtConsts::VerifyConst(CString cName, int iCorrectValue, CComVariant vCurrentValue)
{
	 CString Mess; int iCurrentValue; 
	iCurrentValue = (int)Val(vCurrentValue);
	Mess = cName+" ("+CStr(iCorrectValue)+") ";
	if (iCorrectValue==iCurrentValue) {
		if (!flOutWarningOnly) {
			Mess += " - Ok";
			m_ListBoxMsg.AddString(Mess);
		}
	} else {
		Mess += CString(" - Warning:  <> ")+Str(iCurrentValue);
		m_ListBoxMsg.AddString(Mess);
		nWarn += 1;
	}
}

void CfrmTestExtConsts::RunTest()
{
	nWarn = 0;
	m_ListBoxMsg.ResetContent();

	VerifyConst("vbYesNoCancel", 3, MB_YESNOCANCEL);
	VerifyConst("vbYes", 6, IDYES);
	VerifyConst("vbArchive", 32, FILE_ATTRIBUTE_ARCHIVE);
	VerifyConst("vbMaximizedFocus", 3, SW_SHOWMAXIMIZED);
	VerifyConst("vbTuesday", 3, vbTuesday);
	VerifyConst("vbFixedDialog", 3, vbFixedDialog);

#if !VBtoJSNET
	VerifyConst("vbKeyF1", 112, VK_F1);
	VerifyConst("vbCtrlMask", 2, vbCtrlMask);
	VerifyConst("vbDiagonalCross", 7, vbDiagonalCross);
	VerifyConst("cdlCancel", 32755, cdlCancel);

#endif

#if VBtoVCMFC || VBtoBuilder || VBtoDelphi
	VerifyConst("vbRed", 255, 0xFF);

#endif


#if !(VB6 || VBtoJSNET)
	 int iSmart; 
	iSmart = SW_SHOWNORMAL;
	VerifyConst("myConst", 182, myConstToVCPP);
	VerifyConst("myConts1", 11, myConst1);
	VerifyConst("myConts2", 12, myConst2);
	VerifyConst("TestStringToVariant", 5, "5");

#endif

	if (nWarn>0) m_ListBoxMsg.AddString("nWarn = "+Str(nWarn));
}
