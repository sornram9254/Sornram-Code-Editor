// frmTestFormProperty.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestFormProperty)
//}}VBto_Converter_Includes

#include "frmTestFormProperty.h"
CfrmTestFormProperty *frmTestFormProperty = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestFormProperty dialog



CfrmTestFormProperty::CfrmTestFormProperty(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestFormProperty::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestFormProperty) frmTestFormProperty = this;
}

void CfrmTestFormProperty::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestFormProperty)
	DDX_Control(pDX, Label1, m_Label1);
	DDX_Control(pDX, Label2, m_Label2);
	DDX_Control(pDX, Label3, m_Label3);
	DDX_Control(pDX, CmdSetWindowState, m_CmdSetWindowState);
	DDX_Control(pDX, CmdSetCaption, m_CmdSetCaption);
	DDX_Control(pDX, TextNewCaption, m_TextNewCaption);
	DDX_Control(pDX, CmdGetCaption, m_CmdGetCaption);
	DDX_Control(pDX, CmdGetLTWH, m_CmdGetLTWH);
	DDX_Control(pDX, TextL, m_TextL);
	DDX_Control(pDX, CmdSetLTWH, m_CmdSetLTWH);
	DDX_Control(pDX, TextT, m_TextT);
	DDX_Control(pDX, TextW, m_TextW);
	DDX_Control(pDX, TextH, m_TextH);
	DDX_Control(pDX, FrameDefaultProperties, m_FrameDefaultProperties);
	DDX_Control(pDX, dpLabel, m_dpLabel);
	DDX_Control(pDX, dpText, m_dpText);
	DDX_Control(pDX, dpCommand, m_dpCommand);
	DDX_Control(pDX, dpCheck, m_dpCheck);
	DDX_Control(pDX, dpOption, m_dpOption);
	DDX_Control(pDX, dpCombo, m_dpCombo);
	DDX_Control(pDX, HScroll1, m_HScroll1);
	DDX_Control(pDX, dpProgressBar, m_dpProgressBar);
	DDX_Control(pDX, dpSlider, m_dpSlider);
	DDX_Control(pDX, CmdMoveMe, m_CmdMoveMe);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestFormProperty, CDialog)
	//{{AFX_MSG_MAP(CfrmTestFormProperty)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(CmdGetCaption, OnCmdGetCaption)
	ON_BN_CLICKED(CmdSetCaption, OnCmdSetCaption)
	ON_BN_CLICKED(CmdGetLTWH, OnCmdGetLTWH)
	ON_BN_CLICKED(CmdSetLTWH, OnCmdSetLTWH)
	ON_BN_CLICKED(CmdSetWindowState, OnCmdSetWindowState)
	ON_BN_CLICKED(CmdMoveMe, OnCmdMoveMe)
	ON_BN_CLICKED(dpCommand, OndpCommand)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestFormProperty message handlers

BOOL CfrmTestFormProperty::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestFormProperty)
	m_TextNewCaption	.SetWindowText("New Caption");
	m_dpText	.SetWindowText("TextBox");
	m_dpCombo	.SetWindowText("ComboBox");
	{
	SCROLLINFO si;	si.cbSize=sizeof(SCROLLINFO);
	si.nMin=0;	si.nMax=7;
	si.fMask = SIF_RANGE;
	m_HScroll1.SetScrollInfo(&si);
	}
	dpTimer.Set(m_hWnd, IDC_dpTimer, 0, false);
	m_dpProgressBar	.SetRange(0, 10);
	m_dpSlider	.SetRange(0, 10, true);
	flFirst = 0;
	isBounds = 0;	boundL = boundT = boundR = boundB = 0;
	
	Form_Load();
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestFormProperty::OnPaint() 
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
HCURSOR CfrmTestFormProperty::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================
// This is a part of the VBto Converter (www.vbto.net)
// Copyright (C) 2005-2007 StressSoft Company Ltd. All rights reserved.





void CfrmTestFormProperty::Form_Load()
{
	flFirst = true;
	isBounds = false;
}

void CfrmTestFormProperty::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialog::OnShowWindow(bShow, nStatus);

	// TODO: Add your message handler code here and/or call default
	if (flFirst) {
		flFirst = false;
		GetLTWH();
	}
}

void CfrmTestFormProperty::OnCmdGetCaption()
{
	// TODO: Add your control notification handler code here
	 CString msg; 
	msg = ::GetWindowText(this);
	msg += CString("\r\n")+::GetWindowText(this);
	msg += CString("\r\n")+::GetWindowText(CfrmTestFormProperty::InstancePtr());

	msg += CString("\r\n")+::GetWindowText(this);


	msg += CString("\r\n")+::GetWindowText(CfrmTestFormProperty::InstancePtr());

	::MessageBox(NULL, msg,"Caption:",MB_ICONINFORMATION);
}

void CfrmTestFormProperty::OnCmdSetCaption()
{
	// TODO: Add your control notification handler code here
	this->SetWindowText(::GetWindowText(m_TextNewCaption));
	this->SetWindowText(::GetWindowText(m_TextNewCaption));
	CfrmTestFormProperty::InstancePtr()->SetWindowText(::GetWindowText(m_TextNewCaption));

	this->SetWindowText(::GetWindowText(m_TextNewCaption));


	CfrmTestFormProperty::InstancePtr()->SetWindowText(::GetWindowText(m_TextNewCaption));

}

void CfrmTestFormProperty::GetLTWH()
{
	m_TextL.SetWindowText(Str(GetLeft(this)));
	m_TextT.SetWindowText(Str(GetTop(this)));
	m_TextW.SetWindowText(Str(GetWidth(CfrmTestFormProperty::InstancePtr())));

	m_TextH.SetWindowText(Str(GetHeight(this)));


	m_TextH.SetWindowText(Str(GetHeight(CfrmTestFormProperty::InstancePtr())));

}
void CfrmTestFormProperty::OnCmdGetLTWH()
{
	// TODO: Add your control notification handler code here
	GetLTWH();
}

void CfrmTestFormProperty::SetLTWH()
{
	SetLeft(this, CLng(::GetWindowText(m_TextL)));
	SetTop(this, CLng(::GetWindowText(m_TextT)));

	SetTop(this, CLng(::GetWindowText(m_TextT)));

	SetWidth(CfrmTestFormProperty::InstancePtr(), CInt(::GetWindowText(frmTestFormProperty->m_TextW)));

	SetHeight(this, CInt(::GetWindowText(frmTestFormProperty->m_TextH)));

}
void CfrmTestFormProperty::OnCmdSetLTWH()
{
	// TODO: Add your control notification handler code here
	SetLTWH();
}

void CfrmTestFormProperty::OnCmdSetWindowState()
{
	// TODO: Add your control notification handler code here

	this->ShowWindow(SW_MAXIMIZE);
	this->UpdateWindow();

	CfrmTestFormProperty::InstancePtr()->ShowWindow(SW_NORMAL);
	this->UpdateWindow();


	CfrmTestFormProperty::InstancePtr()->ShowWindow(SW_MINIMIZE);



	this->ShowWindow(SW_NORMAL);


	this->ShowWindow(SW_NORMAL);

}

void CfrmTestFormProperty::OnCmdMoveMe()
{
	// TODO: Add your control notification handler code here
	if (!isBounds) {
		isBounds = true;
		boundL = GetLeft(m_CmdMoveMe);
		boundT = GetTop(m_CmdMoveMe);
		boundR = boundL+2*GetWidth(m_CmdMoveMe);
		boundB = boundT+2*GetHeight(m_CmdMoveMe);
	}

	SetLeft(m_CmdMoveMe, Round(GetLeft(m_CmdMoveMe)+(double)GetWidth(m_CmdMoveMe) / 4));
	SetTop(m_CmdMoveMe, Round(GetTop(m_CmdMoveMe)+(double)GetHeight(m_CmdMoveMe) / 3));

	if (GetLeft(m_CmdMoveMe)>boundR) SetLeft(m_CmdMoveMe, boundL);
	if (GetTop(m_CmdMoveMe)>boundB) SetTop(m_CmdMoveMe, boundT);
}

void CfrmTestFormProperty::OndpCommand()
{
	// TODO: Add your control notification handler code here
	TestDefaultProperty();
}
void CfrmTestFormProperty::TestDefaultProperty()
{
	 CString newS; bool newB; short newI; CString msg; 
	newS = "newString";
	newB = true;
	newI = 2;


#if VBtoVCNET
	msg = "";

#endif

	m_FrameDefaultProperties.SetWindowText(newS); // Caption
	if (::GetWindowText(m_FrameDefaultProperties)!=newS) msg += CString("Frame")+"\r\n";

	m_dpLabel.SetWindowText(newS); // Caption
	if (::GetWindowText(m_dpLabel)!=newS) msg += CString("Label.Caption")+"\r\n";

	m_dpText.SetWindowText(newS); // Text
	if (::GetWindowText(m_dpText)!=newS) msg += CString("TextBox.Text")+"\r\n";

	m_dpCombo.SetWindowText(newS); // Text
	if (::GetWindowText(m_dpCombo)!=newS) msg += CString("ComboBox.Text")+"\r\n";

	dpTimer.SetEnabled(newB); // Enabled
	if (dpTimer.Enabled!=newB) msg += CString("Timer.Enabled")+"\r\n";

	m_dpOption.SetCheck(newB); // Value
	if (m_dpOption.GetCheck()!=newB) msg += CString("OptionButton.Value")+"\r\n";

	m_dpCheck.SetCheck(BST_UNCHECKED); // Value
	// dpCheck = vbGrayed
	m_dpCheck.SetCheck(BST_CHECKED);
	if (m_dpCheck.GetCheck()!=BST_CHECKED) msg += CString("CheckBox.Value")+"\r\n";

	m_dpSlider.SetPos(newI); // Value
	if (m_dpSlider.GetPos()!=newI) msg += CString("Slider.Value")+"\r\n";

	m_HScroll1.SetScrollPos(newI); // Value
	if (m_HScroll1.GetScrollPos()!=newI) msg += CString("HScrollBar.Value")+"\r\n";

	m_dpProgressBar.SetPos(newI); // Value
	if (m_dpProgressBar.GetPos()!=newI) msg += CString("ProgressBar.Value")+"\r\n";

	if (msg=="") {
		AfxMessageBox("All Ok");
	} else {
		::MessageBox(NULL, msg,"Errors:",MB_ICONSTOP);
	}

}
