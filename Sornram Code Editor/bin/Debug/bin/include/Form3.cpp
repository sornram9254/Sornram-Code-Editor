// Form3.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CForm3)
//}}VBto_Converter_Includes

#include "Form3.h"
CForm3 *Form3 = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CForm3 dialog



CForm3::CForm3(CWnd* pParent /*=NULL*/)
	: CDialog(CForm3::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!Form3) Form3 = this;
}

void CForm3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CForm3)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CForm3, CDialog)
	//{{AFX_MSG_MAP(CForm3)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CForm3 message handlers

BOOL CForm3::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CForm3)
	m_Form3_SSTab1.AddPage(&m_Form3_SSTab1_Page1);
	m_Form3_SSTab1.AddPage(&m_Form3_SSTab1_Page2);
	m_Form3_SSTab1.AddPage(&m_Form3_SSTab1_Page3);
	
	m_Form3_SSTab1.Create(this, WS_CHILD|WS_VISIBLE|WS_TABSTOP, WS_EX_CONTROLPARENT);
	CRect RectSSTab1;
	GetDlgItem(Form3_SSTab1)->GetWindowRect(&RectSSTab1);
	ScreenToClient(&RectSSTab1);
	m_Form3_SSTab1.SetWindowPos(NULL, RectSSTab1.left-6,RectSSTab1.top-7, 0,0, SWP_NOZORDER|SWP_NOSIZE|SWP_NOACTIVATE);
	
	m_StatusBar1.Create(WS_CHILD|SBT_OWNERDRAW|WS_VISIBLE|CCS_BOTTOM, CRect(0,0,0,0), this, 0);
	{ int statusBarPannelsWidth[3]= { 75, 150, -1 };
	m_StatusBar1.SetParts(3, statusBarPannelsWidth); }
	m_StatusBar1.SetText("Text1"	, 0, 0);
	m_StatusBar1.SetText("Text2"	, 1, SBT_POPOUT);
	m_StatusBar1.SetText("Text3"	, 2, 0);
	
	{
	m_ImageList1	.Create(16, 16, ILC_COLOR8|ILC_MASK, 10,5);
	CBitmap *pBmp = new CBitmap();
	COLORREF crMask = RGB(192,192,192);
	
	pBmp->LoadBitmap(Form3_ImageList1_1);
	m_ImageList1.Add(pBmp,crMask);
	pBmp->DeleteObject();
	
	pBmp->LoadBitmap(Form3_ImageList1_2);
	m_ImageList1.Add(pBmp,crMask);
	pBmp->DeleteObject();
	delete pBmp;
	}
	m_Toolbar1.Create(WS_CHILD|WS_VISIBLE|CCS_TOP|TBSTYLE_TOOLTIPS, CRect(0,0,0,0), this, 0);
	m_Toolbar1.SetImageList(&m_ImageList1);
	{
	TBBUTTON tb;
	
	tb.idCommand = 0;
	tb.iBitmap = 0;
	tb.iString = NULL;
	tb.fsState = TBSTATE_ENABLED;
	tb.fsStyle = TBSTYLE_BUTTON;
	tb.dwData  = 0;
	m_Toolbar1.AddButtons(1, &tb);
	
	tb.idCommand = 0;
	tb.iBitmap = 1;
	tb.iString = NULL;
	tb.fsState = TBSTATE_ENABLED;
	tb.fsStyle = TBSTYLE_BUTTON;
	tb.dwData  = 0;
	m_Toolbar1.AddButtons(1, &tb);
	}
	
	m_CommonDialog1 = new CFileDialog(TRUE);
	m_CommonDialog1->m_ofn.lpstrTitle	= "Input File N 1";
	m_CommonDialog1->m_ofn.lpstrInitialDir	= "c:\\";
	m_CommonDialog1->m_ofn.lpstrDefExt	= "txt";
	m_CommonDialog1->m_ofn.lpstrFilter	= "Text Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0\0";
	m_CommonDialog1->m_ofn.nFilterIndex	= 1;
	strcpy(m_CommonDialog1->m_ofn.lpstrFile, "Good.txt");
	
	fm_Label3.Set(GetDlgItem(Label3), GetSysColor(COLOR_BACKGROUND), GetSysColor(COLOR_BTNFACE),"Arial",9.75,false,false,false,false,RUSSIAN_CHARSET);
	fm_Label4.Set(GetDlgItem(Label4), GetSysColor(COLOR_HIGHLIGHT), GetSysColor(COLOR_BTNFACE),"Verdana",9.75,false,false,false,false,RUSSIAN_CHARSET);
	fm_Frame1.Set(GetDlgItem(Frame1), GetSysColor(COLOR_BTNTEXT), RGB(255,224,192));
	
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CForm3::OnPaint() 
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
HCURSOR CForm3::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================

HBRUSH CForm3::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch(pWnd->GetDlgCtrlID()) {
		case Label3:	return fm_Label3	.OnCtlColor(pDC);
		case Label4:	return fm_Label4	.OnCtlColor(pDC);
		case Frame1:	return fm_Frame1	.OnCtlColor(pDC);
	}
	return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}
