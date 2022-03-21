// Form2.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CForm2)
//}}VBto_Converter_Includes

#include "Form2.h"
CForm2 *Form2 = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CForm2 dialog



CForm2::CForm2(CWnd* pParent /*=NULL*/)
	: CDialog(CForm2::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!Form2) Form2 = this;
}

void CForm2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CForm2)
	DDX_Control(pDX, Label1, m_Label1);
	DDX_Control(pDX, Label2, m_Label2);
	DDX_Control(pDX, ListView1, m_ListView1);
	DDX_Control(pDX, ProgressBar1, m_ProgressBar1);
	DDX_Control(pDX, Slider2, m_Slider2);
	DDX_Control(pDX, Slider1, m_Slider1);
	DDX_Control(pDX, TreeView1, m_TreeView1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CForm2, CDialog)
	//{{AFX_MSG_MAP(CForm2)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CForm2 message handlers

BOOL CForm2::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CForm2)
	{
	m_ImageList1	.Create(16, 16, ILC_COLOR8|ILC_MASK, 10,5);
	CBitmap *pBmp = new CBitmap();
	COLORREF crMask = RGB(192,192,192);
	
	pBmp->LoadBitmap(Form2_ImageList1_1);
	m_ImageList1.Add(pBmp,crMask);
	pBmp->DeleteObject();
	
	pBmp->LoadBitmap(Form2_ImageList1_2);
	m_ImageList1.Add(pBmp,crMask);
	pBmp->DeleteObject();
	
	pBmp->LoadBitmap(Form2_ImageList1_3);
	m_ImageList1.Add(pBmp,crMask);
	pBmp->DeleteObject();
	delete pBmp;
	}
	m_ListView1	.InsertColumn(0, "N",	LVCFMT_LEFT,	18, -1);
	m_ListView1	.InsertColumn(1, "Name",	LVCFMT_RIGHT,	43, -1);
	m_ListView1	.InsertColumn(2, "Attrib",	LVCFMT_CENTER,	55, -1);
	
	m_ProgressBar1	.SetRange(0, 100);
	m_Slider2	.SetRange(5, 105, true);
	m_Slider2	.SetTicFreq(4);
	m_Slider2	.SetPos(42);
	
	m_StatusBar1.Create(WS_CHILD|SBT_OWNERDRAW|WS_VISIBLE|CCS_BOTTOM, CRect(0,0,0,0), this, 0);
	{ int statusBarPannelsWidth[3]= { 29, 99, -1 };
	m_StatusBar1.SetParts(3, statusBarPannelsWidth); }
	m_StatusBar1.SetText("Text1"	, 0, 0);
	m_StatusBar1.SetText("Text2"	, 1, 0);
	m_StatusBar1.SetText("Text3"	, 2, 0);
	
	m_Slider1	.SetRange(5, 105, true);
	m_Slider1	.SetTicFreq(4);
	m_Slider1	.SetPos(48);
	
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
	tb.iBitmap = -1;
	tb.iString = NULL;
	tb.fsState = TBSTATE_ENABLED|TBSTATE_INDETERMINATE;
	tb.fsStyle = TBSTYLE_SEP;
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
	
	
	fm_Label1.Set(GetDlgItem(Label1), RGB(0,0,255), GetSysColor(COLOR_BTNFACE),"MS Sans Serif",9.75,true,false,false,true,RUSSIAN_CHARSET);
	fm_Label2.Set(GetDlgItem(Label2), RGB(255,0,0), GetSysColor(COLOR_BTNFACE),"Arial",9.75,true,true,false,false,RUSSIAN_CHARSET);
	
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CForm2::OnPaint() 
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
HCURSOR CForm2::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================

HBRUSH CForm2::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch(pWnd->GetDlgCtrlID()) {
		case Label1:	return fm_Label1	.OnCtlColor(pDC);
		case Label2:	return fm_Label2	.OnCtlColor(pDC);
	}
	return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}
