// frmTestCursor.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestCursor)
//}}VBto_Converter_Includes

#include "frmTestCursor.h"
CfrmTestCursor *frmTestCursor = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestCursor dialog



CfrmTestCursor::CfrmTestCursor(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestCursor::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestCursor) frmTestCursor = this;
}

void CfrmTestCursor::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestCursor)
	DDX_Control(pDX, Label1, m_Label1);
	DDX_Control(pDX, ListCurPointer, m_ListCurPointer);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestCursor, CDialog)
	//{{AFX_MSG_MAP(CfrmTestCursor)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_LBN_SELCHANGE(ListCurPointer, SelchangeListCurPointer)
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestCursor message handlers

BOOL CfrmTestCursor::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestCursor)
	
	Form_Load();
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestCursor::OnPaint() 
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
HCURSOR CfrmTestCursor::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================

void CfrmTestCursor::Form_Load()
{

	m_ListCurPointer.AddString("vbArrow");
	m_ListCurPointer.AddString("vbArrowHourglass");
	m_ListCurPointer.AddString("vbArrowQuestion");
	m_ListCurPointer.AddString("vbCrosshair");
	m_ListCurPointer.AddString("vbCustom");
	m_ListCurPointer.AddString("vbDefault");
	m_ListCurPointer.AddString("vbHourglass");
	m_ListCurPointer.AddString("vbIbeam");
	m_ListCurPointer.AddString("vbIconPointer");
	m_ListCurPointer.AddString("vbNoDrop");
	m_ListCurPointer.AddString("vbSizeAll");
	m_ListCurPointer.AddString("vbSizeNESW");
	m_ListCurPointer.AddString("vbSizeNS");
	m_ListCurPointer.AddString("vbSizeNWSE");
	m_ListCurPointer.AddString("vbSizePointer");
	m_ListCurPointer.AddString("vbSizeWE");
	m_ListCurPointer.AddString("vbUpArrow");

}

void CfrmTestCursor::SelchangeListCurPointer()
{
	// TODO: Add your control notification handler code here

	if (GetText(m_ListCurPointer)=="vbArrow") SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (GetText(m_ListCurPointer)=="vbArrowHourglass") SetCursor(AfxGetApp()->LoadStandardCursor(IDC_APPSTARTING));
	if (GetText(m_ListCurPointer)=="vbArrowQuestion") SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HELP));
	if (GetText(m_ListCurPointer)=="vbCrosshair") SetCursor(AfxGetApp()->LoadStandardCursor(IDC_CROSS));
	if (GetText(m_ListCurPointer)=="vbCustom") SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (GetText(m_ListCurPointer)=="vbDefault") SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (GetText(m_ListCurPointer)=="vbHourglass") SetCursor(AfxGetApp()->LoadStandardCursor(IDC_WAIT));
	if (GetText(m_ListCurPointer)=="vbIbeam") SetCursor(AfxGetApp()->LoadStandardCursor(IDC_IBEAM));
	if (GetText(m_ListCurPointer)=="vbIconPointer") SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (GetText(m_ListCurPointer)=="vbNoDrop") SetCursor(AfxGetApp()->LoadStandardCursor(IDC_NO));
	if (GetText(m_ListCurPointer)=="vbSizeAll") SetCursor(AfxGetApp()->LoadStandardCursor(IDC_SIZEALL));
	if (GetText(m_ListCurPointer)=="vbSizeNESW") SetCursor(AfxGetApp()->LoadStandardCursor(IDC_SIZENESW));
	if (GetText(m_ListCurPointer)=="vbSizeNS") SetCursor(AfxGetApp()->LoadStandardCursor(IDC_SIZENS));
	if (GetText(m_ListCurPointer)=="vbSizeNWSE") SetCursor(AfxGetApp()->LoadStandardCursor(IDC_SIZENWSE));
	if (GetText(m_ListCurPointer)=="vbSizePointer") SetCursor(AfxGetApp()->LoadStandardCursor(IDC_SIZEALL));
	if (GetText(m_ListCurPointer)=="vbSizeWE") SetCursor(AfxGetApp()->LoadStandardCursor(IDC_SIZEWE));
	if (GetText(m_ListCurPointer)=="vbUpArrow") SetCursor(AfxGetApp()->LoadStandardCursor(IDC_UPARROW));

}
