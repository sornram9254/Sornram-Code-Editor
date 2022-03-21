// frmTestMisc_SSTab1_Page3.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestMisc_SSTab1_Page3)
//}}VBto_Converter_Includes

#include "frmTestMisc_SSTab1_Page3.h"
CfrmTestMisc_SSTab1_Page3 *frmTestMisc_SSTab1_Page3 = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestMisc_SSTab1_Page3 dialog



CfrmTestMisc_SSTab1_Page3::CfrmTestMisc_SSTab1_Page3()
	: CPropertyPage(CfrmTestMisc_SSTab1_Page3::IDD)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestMisc_SSTab1_Page3) frmTestMisc_SSTab1_Page3 = this;
}

void CfrmTestMisc_SSTab1_Page3::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestMisc_SSTab1_Page3)
	DDX_Control(pDX, CmdBeep, m_CmdBeep);
	DDX_Control(pDX, CmdShell, m_CmdShell);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestMisc_SSTab1_Page3, CPropertyPage)
	//{{AFX_MSG_MAP(CfrmTestMisc_SSTab1_Page3)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(CmdShell, OnCmdShell)
	ON_BN_CLICKED(CmdBeep, OnCmdBeep)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestMisc_SSTab1_Page3 message handlers

BOOL CfrmTestMisc_SSTab1_Page3::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestMisc_SSTab1_Page3)
	
	fm_Label1.Set(GetDlgItem(Label1), RGB(0,128,0), GetSysColor(COLOR_BTNFACE),"MS Sans Serif",8.25,true,false,false,false,RUSSIAN_CHARSET);
	
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestMisc_SSTab1_Page3::OnPaint() 
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
HCURSOR CfrmTestMisc_SSTab1_Page3::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================



















// ==============================================================









// ==============================================================

void CfrmTestMisc_SSTab1_Page3::OnCmdShell()
{
	// TODO: Add your control notification handler code here
	WinExec("explorer.exe",SW_SHOWNORMAL);

#if And_So_On
	WinExec("explorer.exe",SW_SHOWMAXIMIZED);
	WinExec("explorer.exe",SW_SHOWMINIMIZED);
	WinExec("explorer.exe",SW_SHOWMINNOACTIVE);
	WinExec("explorer.exe",SW_SHOWNOACTIVATE);
	WinExec("explorer.exe",SW_HIDE);
	WinExec("explorer.exe",SW_SHOWMINIMIZED);

#endif
}

void CfrmTestMisc_SSTab1_Page3::OnCmdBeep()
{
	// TODO: Add your control notification handler code here
	MessageBeep(-1);
}


HBRUSH CfrmTestMisc_SSTab1_Page3::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch(pWnd->GetDlgCtrlID()) {
		case Label1:	return fm_Label1	.OnCtlColor(pDC);
	}
	return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}
