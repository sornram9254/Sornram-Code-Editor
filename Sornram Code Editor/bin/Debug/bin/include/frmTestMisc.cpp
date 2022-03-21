// frmTestMisc.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestMisc)
//}}VBto_Converter_Includes

#include "frmTestMisc.h"
CfrmTestMisc *frmTestMisc = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestMisc dialog



CfrmTestMisc::CfrmTestMisc(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestMisc::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestMisc) frmTestMisc = this;
}

void CfrmTestMisc::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestMisc)
	DDX_Control(pDX, Label1, m_Label1);
	DDX_Control(pDX, CmdTestPrintToDebug, m_CmdTestPrintToDebug);
	DDX_Control(pDX, CmdTestPrintToFile, m_CmdTestPrintToFile);
	DDX_Control(pDX, CmdTestPrintToForm, m_CmdTestPrintToForm);
	DDX_Control(pDX, FrameCommandLineArguments, m_FrameCommandLineArguments);
	DDX_Control(pDX, TextCommandLineArguments, m_TextCommandLineArguments);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestMisc, CDialog)
	//{{AFX_MSG_MAP(CfrmTestMisc)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(CmdTestPrintToFile, OnCmdTestPrintToFile)
	ON_BN_CLICKED(CmdTestPrintToDebug, OnCmdTestPrintToDebug)
	ON_BN_CLICKED(CmdTestPrintToForm, OnCmdTestPrintToForm)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestMisc message handlers

BOOL CfrmTestMisc::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestMisc)
	m_frmTestMisc_SSTab1.AddPage(&m_frmTestMisc_SSTab1_Page1);
	m_frmTestMisc_SSTab1.AddPage(&m_frmTestMisc_SSTab1_Page2);
	m_frmTestMisc_SSTab1.AddPage(&m_frmTestMisc_SSTab1_Page3);
	
	m_frmTestMisc_SSTab1.Create(this, WS_CHILD|WS_VISIBLE|WS_TABSTOP, WS_EX_CONTROLPARENT);
	CRect RectSSTab1;
	GetDlgItem(frmTestMisc_SSTab1)->GetWindowRect(&RectSSTab1);
	ScreenToClient(&RectSSTab1);
	m_frmTestMisc_SSTab1.SetWindowPos(NULL, RectSSTab1.left-6,RectSSTab1.top-7, 0,0, SWP_NOZORDER|SWP_NOSIZE|SWP_NOACTIVATE);
	
	
	fm_Label1.Set(GetDlgItem(Label1), RGB(0,128,0), GetSysColor(COLOR_BTNFACE),"MS Sans Serif",8.25,true,false,false,false,RUSSIAN_CHARSET);
	
	
	Form_Load();
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestMisc::OnPaint() 
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
HCURSOR CfrmTestMisc::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================

void CfrmTestMisc::Form_Load()
{
	m_TextCommandLineArguments.SetWindowText(vbGetCommandLine());
}

void CfrmTestMisc::OnCmdTestPrintToFile()
{
	// TODO: Add your control notification handler code here
	// === Print to File ===
	 short n; 
	n = 12;
	HANDLE H2 = CreateFile("~TestPrint.tmp", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	::PrintLine(H2, Str("A"));
	::PrintLine(H2, Str("0") + Str(n) + " " + Str(2*n) + " " + Str("5") + Str(78+14) + " " + Str("9"));
	::PrintLine(H2, Str("a") + Str("b") + Str("c"));
	::PrintLine(H2, Str("B"));
	::PrintLine(H2, Str("C") + Str("D"));
	::Print(H2, Str("E") + Str("F"));
	::PrintLine(H2, Str("G") + Str("H"));
	::PrintLine(H2);
	::PrintLine(H2, Str("I"));
	::PrintLine(H2, Str("J"));
	CloseHandle(H2);
	// Output file:
	// A
	// 0 12  24 5 92 9
	// abc
	// B
	// CD
	// EFGH
	// 
	// I
	// J
}

void CfrmTestMisc::OnCmdTestPrintToDebug()
{
	// TODO: Add your control notification handler code here
	// === Print to Debug ===
	// VBto upgrade warning: dtStr As CString	OnWrite(DATE)
	 CString dtStr; 
	dtStr = COleDateTime(COleDateTime::GetCurrentTime()).Format();
	TRACE(CString("\n")+ "Testing print to Debug" + "\t" + Str(dtStr));
}

void CfrmTestMisc::OnCmdTestPrintToForm()
{
	// TODO: Add your control notification handler code here
	// === Print to Form ===
	CurrentX = GetLeft(m_CmdTestPrintToForm)+GetWidth(m_CmdTestPrintToForm);
	CurrentY = GetTop(m_CmdTestPrintToForm)+GetHeight(m_CmdTestPrintToForm);

	CurrentX = CurrentX-CurrentX+CurrentX;
	CurrentY = CurrentY-CurrentY+CurrentY;

	DrawString(this, "Test Print to Form");
	DrawString(this, "Hello" + CString("    ") + Str("World") + "    " + Str("!"));
	DrawString(this, "Left,Top=" + CString("    ") + Str(GetLeft(this)) + "    " + Str(GetTop(this)) + "    " + Str("Width,Height=") + "    " + Str(GetWidth(this)) + "    " + Str(GetHeight(this)));
}











// ==============================================================









// ==============================================================






HBRUSH CfrmTestMisc::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch(pWnd->GetDlgCtrlID()) {
		case Label1:	return fm_Label1	.OnCtlColor(pDC);
	}
	return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}
