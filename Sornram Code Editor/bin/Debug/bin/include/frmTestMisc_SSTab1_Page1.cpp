// frmTestMisc_SSTab1_Page1.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestMisc_SSTab1_Page1)
//}}VBto_Converter_Includes

#include "frmTestMisc_SSTab1_Page1.h"
CfrmTestMisc_SSTab1_Page1 *frmTestMisc_SSTab1_Page1 = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestMisc_SSTab1_Page1 dialog



CfrmTestMisc_SSTab1_Page1::CfrmTestMisc_SSTab1_Page1()
	: CPropertyPage(CfrmTestMisc_SSTab1_Page1::IDD)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestMisc_SSTab1_Page1) frmTestMisc_SSTab1_Page1 = this;
}

void CfrmTestMisc_SSTab1_Page1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestMisc_SSTab1_Page1)
	DDX_Control(pDX, CmdDir, m_CmdDir);
	DDX_Control(pDX, TextDir, m_TextDir);
	DDX_Control(pDX, TextMaskFiles, m_TextMaskFiles);
	DDX_Control(pDX, TextChDir, m_TextChDir);
	DDX_Control(pDX, CmdMkDir, m_CmdMkDir);
	DDX_Control(pDX, CmdRmDir, m_CmdRmDir);
	DDX_Control(pDX, CmdCurDir, m_CmdCurDir);
	DDX_Control(pDX, CmdChDir, m_CmdChDir);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestMisc_SSTab1_Page1, CPropertyPage)
	//{{AFX_MSG_MAP(CfrmTestMisc_SSTab1_Page1)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(CmdCurDir, OnCmdCurDir)
	ON_BN_CLICKED(CmdChDir, OnCmdChDir)
	ON_BN_CLICKED(CmdDir, OnCmdDir)
	ON_BN_CLICKED(CmdMkDir, OnCmdMkDir)
	ON_BN_CLICKED(CmdRmDir, OnCmdRmDir)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestMisc_SSTab1_Page1 message handlers

BOOL CfrmTestMisc_SSTab1_Page1::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestMisc_SSTab1_Page1)
	m_tooltip	.Create(this);
	m_tooltip	.Activate(TRUE);
	m_tooltip	.AddTool(&m_CmdDir, "Dir");
	m_TextDir	.SetWindowText("VBto Converter Test MkDir and RmDir");
	m_TextMaskFiles	.SetWindowText("*.*");
	m_TextChDir	.SetWindowText("\\");
	m_tooltip	.AddTool(&m_CmdMkDir, "Make Dir");
	m_tooltip	.AddTool(&m_CmdRmDir, "Remove Dir");
	m_tooltip	.AddTool(&m_CmdCurDir, "Current Dir");
	m_tooltip	.AddTool(&m_CmdChDir, "Change Current Dir");
	
	fm_Label1.Set(GetDlgItem(Label1), RGB(0,128,0), GetSysColor(COLOR_BTNFACE),"MS Sans Serif",8.25,true,false,false,false,RUSSIAN_CHARSET);
	
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestMisc_SSTab1_Page1::OnPaint() 
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
HCURSOR CfrmTestMisc_SSTab1_Page1::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================









void CfrmTestMisc_SSTab1_Page1::OnCmdCurDir()
{
	// TODO: Add your control notification handler code here
	::MessageBox(NULL, "\""+GetCurrentDirectory()+"\"","CurDir:",MB_ICONINFORMATION);
}

void CfrmTestMisc_SSTab1_Page1::OnCmdChDir()
{
	// TODO: Add your control notification handler code here
	// VBto upgrade warning: CurDirNew As CString	OnWrite(TextBox, CString)
	 CString CurDirBefore,  CurDirNew,  Information; 
	CurDirBefore = GetCurrentDirectory();
	Information = "CurDirBefore: \""+CurDirBefore+"\"";
	CurDirNew = ::GetWindowText(m_TextChDir);
	SetCurrentDirectory(CurDirNew);
	Information += CString("\r\n")+"CurDirNew: \""+GetCurrentDirectory()+"\"";
	SetCurrentDirectory(CurDirBefore);
	Information += CString("\r\n")+"CurDirAfter: \""+GetCurrentDirectory()+"\"";
	AfxMessageBox(Information,MB_ICONINFORMATION);
}

void CfrmTestMisc_SSTab1_Page1::OnCmdDir()
{
	// TODO: Add your control notification handler code here
	// VBto upgrade warning: maskFile As CString	OnWrite(TextBox, CString)
	 CString maskFile,  namf; 
	maskFile = ::GetWindowText(m_TextMaskFiles);

	namf = Dir(maskFile);
	if (namf=="") {
		AfxMessageBox("Files does not exist",MB_ICONSTOP);
		return;
	}

	 CString ListFiles; 
	ListFiles = namf+"\r\n";

	 short i; 
	for(i=1; i<=10; i++) {
		namf = Dir();
		if (namf=="") break;
		ListFiles += namf+"\r\n";
	}

	::MessageBox(NULL, ListFiles,Str(i)+"  files:",MB_ICONINFORMATION);
}

void CfrmTestMisc_SSTab1_Page1::OnCmdMkDir()
{
	// TODO: Add your control notification handler code here
	// VBto upgrade warning: nameDir As CString	OnWrite(TextBox, CString)
	 CString nameDir; 
	nameDir = ::GetWindowText(m_TextDir);
	CreateDirectory(nameDir,NULL);
}

void CfrmTestMisc_SSTab1_Page1::OnCmdRmDir()
{
	// TODO: Add your control notification handler code here
	 CString nameDir; 
	nameDir = ::GetWindowText(m_TextDir);
	RemoveDirectory(nameDir);
}

// ==============================================================









// ==============================================================






HBRUSH CfrmTestMisc_SSTab1_Page1::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch(pWnd->GetDlgCtrlID()) {
		case Label1:	return fm_Label1	.OnCtlColor(pDC);
	}
	return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}
