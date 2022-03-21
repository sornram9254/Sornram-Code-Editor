// frmTestVisible.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestVisible)
//}}VBto_Converter_Includes

#include "frmTestVisible.h"
CfrmTestVisible *frmTestVisible = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestVisible dialog



CfrmTestVisible::CfrmTestVisible(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestVisible::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestVisible) frmTestVisible = this;
}

void CfrmTestVisible::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestVisible)
	DDX_Control(pDX, Label1, m_Label1);
	DDX_Control(pDX, Image1, m_Image1);
	DDX_Control(pDX, Label3, m_Label3);
	DDX_Control(pDX, CheckVisible, m_CheckVisible);
	DDX_Control(pDX, CheckEnabled, m_CheckEnabled);
	DDX_Control(pDX, CheckLocked, m_CheckLocked);
	DDX_Control(pDX, Text1, m_Text1);
	DDX_Control(pDX, Command1, m_Command1);
	DDX_Control(pDX, Check1, m_Check1);
	DDX_Control(pDX, Option1, m_Option1);
	DDX_Control(pDX, HScroll1, m_HScroll1);
	DDX_Control(pDX, Slider1, m_Slider1);
	DDX_Control(pDX, Combo1, m_Combo1);
	DDX_Control(pDX, List1, m_List1);
	DDX_Control(pDX, VScroll1, m_VScroll1);
	DDX_Control(pDX, ProgressBar1, m_ProgressBar1);
	DDX_Control(pDX, TreeView1, m_TreeView1);
	DDX_Control(pDX, ListView1, m_ListView1);
	DDX_Control(pDX, Picture1, m_Picture1);
	DDX_Control(pDX, Frame1, m_Frame1);
	DDX_Control(pDX, CheckV, m_CheckV);
	DDX_Control(pDX, CheckE, m_CheckE);
	DDX_Control(pDX, CheckL, m_CheckL);
	DDX_Control(pDX, UpDown1, m_UpDown1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestVisible, CDialog)
	//{{AFX_MSG_MAP(CfrmTestVisible)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(CheckVisible, OnCheckVisible)
	ON_BN_CLICKED(CheckEnabled, OnCheckEnabled)
	ON_BN_CLICKED(CheckLocked, OnCheckLocked)
	ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestVisible message handlers

BOOL CfrmTestVisible::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestVisible)
	m_CheckVisible	.SetCheck(BST_CHECKED);
	m_CheckEnabled	.SetCheck(BST_CHECKED);
	m_Text1	.SetWindowText("Text1");
	{
	SCROLLINFO si;	si.cbSize=sizeof(SCROLLINFO);
	si.nMin=0;	si.nMax=32767;
	si.fMask = SIF_RANGE;
	m_HScroll1.SetScrollInfo(&si);
	}
	m_Slider1	.SetRange(0, 10, true);
	m_Combo1	.SetWindowText("Click Me");
	m_Combo1	.AddString("Item1");
	m_Combo1	.AddString("Item2");
	
	m_List1	.AddString("item 1");
	m_List1	.AddString("item 2");
	m_List1	.AddString("item 3");
	
	{
	SCROLLINFO si;	si.cbSize=sizeof(SCROLLINFO);
	si.nMin=0;	si.nMax=32767;
	si.fMask = SIF_RANGE;
	m_VScroll1.SetScrollInfo(&si);
	}
	m_ProgressBar1	.SetRange(0, 100);
	m_UpDown1	.SetRange(0, 10);
	
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestVisible::OnPaint() 
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
HCURSOR CfrmTestVisible::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================

void CfrmTestVisible::OnCheckVisible()
{
	// TODO: Add your control notification handler code here

	if (m_CheckVisible.GetCheck()) {
		m_Command1.ShowWindow(SW_SHOW);
		m_Text1.ShowWindow(SW_SHOW);
	} else {
		m_Command1.ShowWindow(SW_HIDE);
		m_Text1.ShowWindow(SW_HIDE);
	}
	m_Check1.ShowWindow(m_CheckVisible.GetCheck()==BST_CHECKED ? SW_SHOW : SW_HIDE);
	m_Option1.ShowWindow(BST_CHECKED==m_CheckVisible.GetCheck() ? SW_SHOW : SW_HIDE);
	// VBto upgrade warning: v As bool	OnWrite(VBRUN.CheckBoxConstants)
	 bool v; 
	v = m_CheckVisible.GetCheck()==BST_CHECKED;
	m_Label1.ShowWindow(v ? SW_SHOW : SW_HIDE);
	m_HScroll1.ShowWindow(v ? SW_SHOW : SW_HIDE);
	m_VScroll1.ShowWindow(v ? SW_SHOW : SW_HIDE);
	m_Slider1.ShowWindow(v ? SW_SHOW : SW_HIDE);
	m_Combo1.ShowWindow(v ? SW_SHOW : SW_HIDE);
	m_List1.ShowWindow(v ? SW_SHOW : SW_HIDE);
	m_Picture1.ShowWindow(v ? SW_SHOW : SW_HIDE);
	m_Image1.ShowWindow(v ? SW_SHOW : SW_HIDE);
	m_ProgressBar1.ShowWindow(v ? SW_SHOW : SW_HIDE);
	m_TreeView1.ShowWindow(v ? SW_SHOW : SW_HIDE);
	m_Frame1.ShowWindow(v ? SW_SHOW : SW_HIDE);
	m_UpDown1.ShowWindow(v ? SW_SHOW : SW_HIDE);
	m_ListView1.ShowWindow(!(!v) ? SW_SHOW : SW_HIDE);
	ShowChecks();
}

void CfrmTestVisible::OnCheckEnabled()
{
	// TODO: Add your control notification handler code here
	if (m_CheckEnabled.GetCheck()==BST_CHECKED) {
		m_Command1.EnableWindow(true);
		m_Text1.EnableWindow(true);
	} else {
		m_Command1.EnableWindow(false);
		m_Text1.EnableWindow(false);
	}
	m_Check1.EnableWindow(m_CheckEnabled.GetCheck()==BST_CHECKED);
	m_Option1.EnableWindow(BST_CHECKED==m_CheckEnabled.GetCheck());
	// VBto upgrade warning: en As bool	OnWrite(VBRUN.CheckBoxConstants)
	 bool en;  en = m_CheckEnabled.GetCheck()==BST_CHECKED;
	m_Label1.EnableWindow(en);
	m_HScroll1.EnableWindow(en);
	m_VScroll1.EnableWindow(en);
	m_Slider1.EnableWindow(en);
	m_Combo1.EnableWindow(en);
	m_List1.EnableWindow(en);
	m_Picture1.EnableWindow(en);
	m_Image1.EnableWindow(en);
	m_ProgressBar1.EnableWindow(en);
	m_TreeView1.EnableWindow(en);
	m_Frame1.EnableWindow(en);
	m_UpDown1.EnableWindow(en);
	m_ListView1.EnableWindow(!(!en));
	ShowChecks();
}

void CfrmTestVisible::OnCheckLocked()
{
	// TODO: Add your control notification handler code here

	if (m_CheckLocked.GetCheck()) {
		m_Text1.SendMessage(EM_SETREADONLY, true);
	} else {
		m_Text1.SendMessage(EM_SETREADONLY, false);
	}

	ShowChecks();

}

void CfrmTestVisible::ShowChecks()
{
	m_CheckV.SetCheck(m_CheckVisible.GetCheck());
	m_CheckE.SetCheck(m_CheckEnabled.GetCheck());
	m_CheckL.SetCheck(m_CheckLocked.GetCheck());
}

void CfrmTestVisible::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialog::OnShowWindow(bShow, nStatus);

	// TODO: Add your message handler code here and/or call default
	ShowChecks();
}
