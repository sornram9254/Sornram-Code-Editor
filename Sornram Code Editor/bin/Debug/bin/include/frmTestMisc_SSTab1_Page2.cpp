// frmTestMisc_SSTab1_Page2.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestMisc_SSTab1_Page2)
//}}VBto_Converter_Includes

#include "frmTestMisc_SSTab1_Page2.h"
CfrmTestMisc_SSTab1_Page2 *frmTestMisc_SSTab1_Page2 = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestMisc_SSTab1_Page2 dialog



CfrmTestMisc_SSTab1_Page2::CfrmTestMisc_SSTab1_Page2()
	: CPropertyPage(CfrmTestMisc_SSTab1_Page2::IDD)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestMisc_SSTab1_Page2) frmTestMisc_SSTab1_Page2 = this;
}

void CfrmTestMisc_SSTab1_Page2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestMisc_SSTab1_Page2)
	DDX_Control(pDX, TextMaskFile, m_TextMaskFile);
	DDX_Control(pDX, CmdCreateFile, m_CmdCreateFile);
	DDX_Control(pDX, CmdKillFiles, m_CmdKillFiles);
	DDX_Control(pDX, CmdFileCopy, m_CmdFileCopy);
	DDX_Control(pDX, CmdReadTextFile, m_CmdReadTextFile);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestMisc_SSTab1_Page2, CPropertyPage)
	//{{AFX_MSG_MAP(CfrmTestMisc_SSTab1_Page2)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(CmdCreateFile, OnCmdCreateFile)
	ON_BN_CLICKED(CmdReadTextFile, OnCmdReadTextFile)
	ON_BN_CLICKED(CmdKillFiles, OnCmdKillFiles)
	ON_BN_CLICKED(CmdFileCopy, OnCmdFileCopy)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestMisc_SSTab1_Page2 message handlers

BOOL CfrmTestMisc_SSTab1_Page2::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestMisc_SSTab1_Page2)
	m_TextMaskFile	.SetWindowText("~*.~tmp");
	m_tooltip	.Create(this);
	m_tooltip	.Activate(TRUE);
	m_tooltip	.AddTool(&m_CmdKillFiles, "Deletes files from a disk");
	
	fm_Label1.Set(GetDlgItem(Label1), RGB(0,128,0), GetSysColor(COLOR_BTNFACE),"MS Sans Serif",8.25,true,false,false,false,RUSSIAN_CHARSET);
	
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestMisc_SSTab1_Page2::OnPaint() 
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
HCURSOR CfrmTestMisc_SSTab1_Page2::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================



















// ==============================================================

void CfrmTestMisc_SSTab1_Page2::OnCmdCreateFile()
{
	// TODO: Add your control notification handler code here

	HANDLE H1 = CreateFile("~HandleInt.~tmp", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	 int mf; 
	mf = 1/*indifferently*/;
	HANDLE Hmf = CreateFile("~HandleIdent"+CString(".~tmp"), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	 CString s; 
	s = "Any Output "+CString("Text ...");

	 short i; 
	for(i=1; i<=5; i++) {
		::PrintLine(H1, Str(FormatVB(i)+": "+s));
		::PrintLine(Hmf, Str(FormatVB(i)+": "+s));
		DoEvents();
	}

	CloseHandle(H1);
	CloseHandle(Hmf);
}

void CfrmTestMisc_SSTab1_Page2::OnCmdReadTextFile()
{
	// TODO: Add your control notification handler code here
	 CString namf; 
	namf = Dir(::GetWindowText(m_TextMaskFile));

	if (namf=="") {
		AfxMessageBox("\""+::GetWindowText(m_TextMaskFile)+"\" files does not exist",MB_ICONSTOP);
		return;
	}

	 CString AllLines,  curLine; short i; 
	AllLines = "";

	HANDLE H1 = CreateFile(namf, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
	for(i=1; i<=20; i++) {
		if (::IsEOF(H1)) break;
		LineInput(H1, curLine);
		AllLines += curLine+"\r\n";
	}
	CloseHandle(H1);

	::MessageBox(NULL, AllLines,"\""+namf+"\"  file:",MB_ICONINFORMATION);
}

void CfrmTestMisc_SSTab1_Page2::OnCmdKillFiles()
{
	// TODO: Add your control notification handler code here
	 CString maskFile; 
	maskFile = ::GetWindowText(m_TextMaskFile);
	Kill(maskFile); // Deletes files from a disk !!!
}

void CfrmTestMisc_SSTab1_Page2::OnCmdFileCopy()
{
	// TODO: Add your control notification handler code here
	 CString namf; 
	namf = Dir(::GetWindowText(m_TextMaskFile));

	if (namf=="") {
		AfxMessageBox("\""+::GetWindowText(m_TextMaskFile)+"\" file does not exist",MB_ICONSTOP);
		return;
	}

	CopyFile(namf, namf+"~", false);
}

// ==============================================================






HBRUSH CfrmTestMisc_SSTab1_Page2::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch(pWnd->GetDlgCtrlID()) {
		case Label1:	return fm_Label1	.OnCtlColor(pDC);
	}
	return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}
