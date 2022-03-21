// frmTestListBox.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestListBox)
//}}VBto_Converter_Includes

#include "frmTestListBox.h"
CfrmTestListBox *frmTestListBox = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestListBox dialog



CfrmTestListBox::CfrmTestListBox(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestListBox::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestListBox) frmTestListBox = this;
}

void CfrmTestListBox::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestListBox)
	DDX_Control(pDX, Label2, m_Label2);
	DDX_Control(pDX, Label3, m_Label3);
	DDX_Control(pDX, LB, m_LB);
	DDX_Control(pDX, CB, m_CB);
	DDX_Control(pDX, CmdAddToLB, m_CmdAddToLB);
	DDX_Control(pDX, CmdAddToCB, m_CmdAddToCB);
	DDX_Control(pDX, TextAdd, m_TextAdd);
	DDX_Control(pDX, CmdClearLB, m_CmdClearLB);
	DDX_Control(pDX, CmdClearCB, m_CmdClearCB);
	DDX_Control(pDX, CmdInsertToCB, m_CmdInsertToCB);
	DDX_Control(pDX, CmdInsertToLB, m_CmdInsertToLB);
	DDX_Control(pDX, TextIndex, m_TextIndex);
	DDX_Control(pDX, UpDownIndex, m_UpDownIndex);
	DDX_Control(pDX, CmdRemoveFromCB, m_CmdRemoveFromCB);
	DDX_Control(pDX, CmdRemoveFromLB, m_CmdRemoveFromLB);
	DDX_Control(pDX, CmdGetStringFromCB, m_CmdGetStringFromCB);
	DDX_Control(pDX, CmdGetStringFromLB, m_CmdGetStringFromLB);
	DDX_Control(pDX, CmdGetInfoCB, m_CmdGetInfoCB);
	DDX_Control(pDX, CmdGetInfoLB, m_CmdGetInfoLB);
	DDX_Control(pDX, CmdSetListIndexLB, m_CmdSetListIndexLB);
	DDX_Control(pDX, CmdSetListIndexCB, m_CmdSetListIndexCB);
	DDX_Control(pDX, CmdSetStringLB, m_CmdSetStringLB);
	DDX_Control(pDX, CmdSetStringCB, m_CmdSetStringCB);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestListBox, CDialog)
	//{{AFX_MSG_MAP(CfrmTestListBox)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(CmdGetInfoLB, OnCmdGetInfoLB)
	ON_BN_CLICKED(CmdGetInfoCB, OnCmdGetInfoCB)
	ON_BN_CLICKED(CmdAddToLB, OnCmdAddToLB)
	ON_BN_CLICKED(CmdAddToCB, OnCmdAddToCB)
	ON_BN_CLICKED(CmdInsertToLB, OnCmdInsertToLB)
	ON_BN_CLICKED(CmdInsertToCB, OnCmdInsertToCB)
	ON_BN_CLICKED(CmdRemoveFromLB, OnCmdRemoveFromLB)
	ON_BN_CLICKED(CmdRemoveFromCB, OnCmdRemoveFromCB)
	ON_BN_CLICKED(CmdSetStringLB, OnCmdSetStringLB)
	ON_BN_CLICKED(CmdSetStringCB, OnCmdSetStringCB)
	ON_BN_CLICKED(CmdGetStringFromLB, OnCmdGetStringFromLB)
	ON_BN_CLICKED(CmdGetStringFromCB, OnCmdGetStringFromCB)
	ON_BN_CLICKED(CmdSetListIndexLB, OnCmdSetListIndexLB)
	ON_BN_CLICKED(CmdSetListIndexCB, OnCmdSetListIndexCB)
	ON_BN_CLICKED(CmdClearLB, OnCmdClearLB)
	ON_BN_CLICKED(CmdClearCB, OnCmdClearCB)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestListBox message handlers

BOOL CfrmTestListBox::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestListBox)
	m_LB	.AddString("LB str 0");
	m_LB	.AddString("LB str 1");
	m_LB	.AddString("LB str 2");
	m_LB	.AddString("LB str 3");
	m_LB	.AddString("LB str 4");
	m_LB	.AddString("LB str 5");
	
	m_CB	.AddString("CB str 0");
	m_CB	.AddString("CB str 1");
	m_CB	.AddString("CB str 2");
	m_CB	.AddString("CB str 3");
	m_CB	.AddString("CB str 4");
	
	m_TextAdd	.SetWindowText("Add Text");
	m_TextIndex	.SetWindowText("1");	//from 'UpDownIndex'
	m_UpDownIndex	.SetBuddy(GetDlgItem(TextIndex));
	m_UpDownIndex	.SetRange(0, 4);
	m_UpDownIndex	.SetPos(1);
	
	ind = 0;
	
	Form_Load();
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestListBox::OnPaint() 
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
HCURSOR CfrmTestListBox::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================
// This is a part of the VBto Converter (www.vbto.net)
// Copyright (C) 2005-2006 StressSoft Company Ltd. All rights reserved.




void CfrmTestListBox::Form_Load()
{
	m_UpDownIndex.SetPos(2);
}

void CfrmTestListBox::OnCmdGetInfoLB()
{
	// TODO: Add your control notification handler code here
	m_LB.RedrawWindow();
	 CString s; 
	s = "ListCount: "+Str(m_LB.GetCount())+"\r\n";
	AfxMessageBox(s+"ListIndex: "+FormatVB(m_LB.GetCurSel()));
}
void CfrmTestListBox::OnCmdGetInfoCB()
{
	// TODO: Add your control notification handler code here
	m_CB.RedrawWindow();
	 CString s; 
	s = "ListCount: "+Str(m_CB.GetCount())+"\r\n";
	s += CString("ListIndex: ")+FormatVB(m_CB.GetCurSel());
	AfxMessageBox(s);
}

void CfrmTestListBox::OnCmdAddToLB()
{
	// TODO: Add your control notification handler code here
	m_LB.AddString(::GetWindowText(m_TextAdd));
}
void CfrmTestListBox::OnCmdAddToCB()
{
	// TODO: Add your control notification handler code here
	m_CB.AddString(::GetWindowText(m_TextAdd));
}

void CfrmTestListBox::OnCmdInsertToLB()
{
	// TODO: Add your control notification handler code here
	ind = m_UpDownIndex.GetPos32();
	m_LB.InsertString(ind, ::GetWindowText(m_TextAdd));
}
void CfrmTestListBox::OnCmdInsertToCB()
{
	// TODO: Add your control notification handler code here
	ind = m_UpDownIndex.GetPos32();
	if (ind>m_CB.GetCount()) return;
	m_CB.InsertString(ind, ::GetWindowText(m_TextAdd));
}

void CfrmTestListBox::OnCmdRemoveFromLB()
{
	// TODO: Add your control notification handler code here
	ind = m_UpDownIndex.GetPos32();
	m_LB.DeleteString(ind);
}
void CfrmTestListBox::OnCmdRemoveFromCB()
{
	// TODO: Add your control notification handler code here
	ind = m_UpDownIndex.GetPos32();
	m_CB.DeleteString(ind);
}

void CfrmTestListBox::OnCmdSetStringLB()
{
	// TODO: Add your control notification handler code here
	ind = m_UpDownIndex.GetPos32();
	ResetString(m_LB, ind, ::GetWindowText(m_TextAdd));
}
void CfrmTestListBox::OnCmdSetStringCB()
{
	// TODO: Add your control notification handler code here
	ind = m_UpDownIndex.GetPos32();
	ResetString(m_CB, ind, ::GetWindowText(m_TextAdd));
}

void CfrmTestListBox::OnCmdGetStringFromLB()
{
	// TODO: Add your control notification handler code here
	ind = m_UpDownIndex.GetPos32();
	AfxMessageBox(GetText(m_LB, ind));
}
void CfrmTestListBox::OnCmdGetStringFromCB()
{
	// TODO: Add your control notification handler code here
	 CString Str; 
	ind = m_UpDownIndex.GetPos32();
	Str = GetText(m_CB, ind);
	AfxMessageBox(Str);
}

void CfrmTestListBox::OnCmdSetListIndexLB()
{
	// TODO: Add your control notification handler code here
	ind = m_UpDownIndex.GetPos32();
	m_LB.SetCurSel(ind);
}
void CfrmTestListBox::OnCmdSetListIndexCB()
{
	// TODO: Add your control notification handler code here
	ind = m_UpDownIndex.GetPos32();
	m_CB.SetCurSel(ind);
}

void CfrmTestListBox::OnCmdClearLB()
{
	// TODO: Add your control notification handler code here
	m_LB.ResetContent();
}
void CfrmTestListBox::OnCmdClearCB()
{
	// TODO: Add your control notification handler code here
	m_CB.ResetContent();
}
