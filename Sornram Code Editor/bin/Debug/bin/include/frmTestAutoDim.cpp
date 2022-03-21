// frmTestAutoDim.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestAutoDim)
//}}VBto_Converter_Includes

#include "frmTestAutoDim.h"
CfrmTestAutoDim *frmTestAutoDim = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestAutoDim dialog



CfrmTestAutoDim::CfrmTestAutoDim(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestAutoDim::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestAutoDim) frmTestAutoDim = this;
}

void CfrmTestAutoDim::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestAutoDim)
	DDX_Control(pDX, LabelResults, m_LabelResults);
	DDX_Control(pDX, CmdClose, m_CmdClose);
	DDX_Control(pDX, TextInvisible, m_TextInvisible);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestAutoDim, CDialog)
	//{{AFX_MSG_MAP(CfrmTestAutoDim)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(CmdClose, OnCmdClose)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestAutoDim message handlers

BOOL CfrmTestAutoDim::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestAutoDim)
	m_TextInvisible	.SetWindowText("TextInvisible");
	
	fm_LabelResults.Set(GetDlgItem(LabelResults), RGB(192,0,0), GetSysColor(COLOR_BTNFACE),"MS Sans Serif",9.75,true,false,false,false,RUSSIAN_CHARSET);
	
	
	Form_Load();
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestAutoDim::OnPaint() 
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
HCURSOR CfrmTestAutoDim::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================
// !!! Option Explicit

// This is a part of the VBto Converter (www.vbto.net)
// Copyright (C) 2005-2007 StressSoft Company Ltd. All rights reserved.
// 
// This Test demonstrates the automatic creation of local variable declarations.
// The test is performed successfully, if translation was run without errors.

void CfrmTestAutoDim::Form_Load()
{
	// VBto upgrade warning: vC As double	OnWrite(short)
	// VBto upgrade warning: vU As CComVariant --> As short
	 short vI; int vL; float vF; double vD; CString vS;
	double vC; short vU,  z1,  z2,  z3;
	short z4,  z5; double X0,  X1,  X2;
	double Xe;	// - "AutoDim" 

	vI = 1; // - Integer
	vL = 5; // - Long
	vF = 60; // - Single
	vD = 70.1; // - Double
	vS = "80"; // - String


#if !VBtoJSNET
	vC = 169; // - Currency

#endif


#if !VBtoVCNET
	vU = 99; // - Unknown

#endif

	if (vI==1) {
		z1 = 1;
	} else if (vI==2) {
		z2 = 2;
	} else if (vI==3) {
		z3 = 3;
	} else if (vI==4) {
		z4 = 4;
	} else {
		z5 = 5;
	}

	switch (vI) {
		case 0:
		{

			X0 = 0;
			break;
		}
		case 1:
		{
			X1 = 1;

			break;
		}
		case 2:
		{
			X2 = 2;
			break;
		}
		default: {
			Xe = 3;
			break;
		}
	} //end switch

	Sub1(vS);
	Sub2();
}

void CfrmTestAutoDim::Sub1(CString& sp)
{
	 CString sx;	// - "AutoDim" 

	PublicD = 231; // - Declared in Module
	 CString S; 
	S = "Test AutoDim";
	sp = S;
	sx = S;
}

void CfrmTestAutoDim::Sub2()
{
	this->SetWindowText(::GetWindowText(this)+"");
	this->SetWindowText(::GetWindowText(this)+"");
	m_TextInvisible.SetWindowText("1");
	m_TextInvisible.SetWindowText(::GetWindowText(m_TextInvisible)+::GetWindowText(m_TextInvisible)+"");
}

void CfrmTestAutoDim::OnCmdClose()
{
	// TODO: Add your control notification handler code here
	PostMessage(WM_CLOSE,0,0);
}

HBRUSH CfrmTestAutoDim::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch(pWnd->GetDlgCtrlID()) {
		case LabelResults:	return fm_LabelResults	.OnCtlColor(pDC);
	}
	return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}
