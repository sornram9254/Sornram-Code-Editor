// Form3_SSTab1_Page2.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CForm3_SSTab1_Page2)
//}}VBto_Converter_Includes

#include "Form3_SSTab1_Page2.h"
CForm3_SSTab1_Page2 *Form3_SSTab1_Page2 = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CForm3_SSTab1_Page2 dialog



CForm3_SSTab1_Page2::CForm3_SSTab1_Page2()
	: CPropertyPage(CForm3_SSTab1_Page2::IDD)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!Form3_SSTab1_Page2) Form3_SSTab1_Page2 = this;
}

void CForm3_SSTab1_Page2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CForm3_SSTab1_Page2)
	DDX_Control(pDX, Label3, m_Label3);
	DDX_Control(pDX, Label4, m_Label4);
	DDX_Control(pDX, TreeView1, m_TreeView1);
	DDX_Control(pDX, ListView1, m_ListView1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CForm3_SSTab1_Page2, CPropertyPage)
	//{{AFX_MSG_MAP(CForm3_SSTab1_Page2)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CForm3_SSTab1_Page2 message handlers

BOOL CForm3_SSTab1_Page2::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CForm3_SSTab1_Page2)
	
	fm_Label3.Set(GetDlgItem(Label3), GetSysColor(COLOR_BACKGROUND), GetSysColor(COLOR_BTNFACE),"Arial",9.75,false,false,false,false,RUSSIAN_CHARSET);
	fm_Label4.Set(GetDlgItem(Label4), GetSysColor(COLOR_HIGHLIGHT), GetSysColor(COLOR_BTNFACE),"Verdana",9.75,false,false,false,false,RUSSIAN_CHARSET);
	fm_Frame1.Set(GetDlgItem(Frame1), GetSysColor(COLOR_BTNTEXT), RGB(255,224,192));
	
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CForm3_SSTab1_Page2::OnPaint() 
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
HCURSOR CForm3_SSTab1_Page2::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================

HBRUSH CForm3_SSTab1_Page2::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch(pWnd->GetDlgCtrlID()) {
		case Label3:	return fm_Label3	.OnCtlColor(pDC);
		case Label4:	return fm_Label4	.OnCtlColor(pDC);
		case Frame1:	return fm_Frame1	.OnCtlColor(pDC);
	}
	return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}
