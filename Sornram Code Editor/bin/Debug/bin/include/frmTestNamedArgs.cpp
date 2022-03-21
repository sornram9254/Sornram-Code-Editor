// frmTestNamedArgs.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestNamedArgs)
//}}VBto_Converter_Includes

#include "frmTestNamedArgs.h"
CfrmTestNamedArgs *frmTestNamedArgs = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestNamedArgs dialog



CfrmTestNamedArgs::CfrmTestNamedArgs(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestNamedArgs::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestNamedArgs) frmTestNamedArgs = this;
}

void CfrmTestNamedArgs::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestNamedArgs)
	DDX_Control(pDX, Label1, m_Label1);
	DDX_Control(pDX, Command1, m_Command1);
	DDX_Control(pDX, Command2, m_Command2);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestNamedArgs, CDialog)
	//{{AFX_MSG_MAP(CfrmTestNamedArgs)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(Command1, OnCommand1)
	ON_BN_CLICKED(Command2, OnCommand2)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestNamedArgs message handlers

BOOL CfrmTestNamedArgs::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestNamedArgs)
	
	fm_Label1.Set(GetDlgItem(Label1), RGB(255,0,0), GetSysColor(COLOR_BTNFACE),"MS Sans Serif",12,true,false,false,false,RUSSIAN_CHARSET);
	
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestNamedArgs::OnPaint() 
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
HCURSOR CfrmTestNamedArgs::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================

void CfrmTestNamedArgs::mySub(short iArg1, CString sArg2, double dArg3, bool bArg4)
{
	m_Label1.SetWindowText("Call mySub("+Str(iArg1)+",  \""+sArg2+"\",  "+Str(dArg3)+",  "+Str(bArg4)+")");
}

void CfrmTestNamedArgs::OnCommand1()
{
	// TODO: Add your control notification handler code here
	mySub(1, "2", 3, true);
}

void CfrmTestNamedArgs::OnCommand2()
{
	// TODO: Add your control notification handler code here
	mySub(21, "22", 23, false);
}

HBRUSH CfrmTestNamedArgs::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch(pWnd->GetDlgCtrlID()) {
		case Label1:	return fm_Label1	.OnCtlColor(pDC);
	}
	return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}
