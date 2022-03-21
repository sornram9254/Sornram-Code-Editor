// frmTestTabStrip_SSTab1_Page1.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestTabStrip_SSTab1_Page1)
//}}VBto_Converter_Includes

#include "frmTestTabStrip_SSTab1_Page1.h"
CfrmTestTabStrip_SSTab1_Page1 *frmTestTabStrip_SSTab1_Page1 = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestTabStrip_SSTab1_Page1 dialog



CfrmTestTabStrip_SSTab1_Page1::CfrmTestTabStrip_SSTab1_Page1()
	: CPropertyPage(CfrmTestTabStrip_SSTab1_Page1::IDD)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestTabStrip_SSTab1_Page1) frmTestTabStrip_SSTab1_Page1 = this;
}

void CfrmTestTabStrip_SSTab1_Page1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestTabStrip_SSTab1_Page1)
	DDX_Control(pDX, Command1, m_Command1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestTabStrip_SSTab1_Page1, CPropertyPage)
	//{{AFX_MSG_MAP(CfrmTestTabStrip_SSTab1_Page1)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestTabStrip_SSTab1_Page1 message handlers

BOOL CfrmTestTabStrip_SSTab1_Page1::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestTabStrip_SSTab1_Page1)
	
	fm_Label4.Set(GetDlgItem(Label4), RGB(0,0,255), GetSysColor(COLOR_BTNFACE));
	
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestTabStrip_SSTab1_Page1::OnPaint() 
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
HCURSOR CfrmTestTabStrip_SSTab1_Page1::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================















// 













HBRUSH CfrmTestTabStrip_SSTab1_Page1::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch(pWnd->GetDlgCtrlID()) {
		case Label4:	return fm_Label4	.OnCtlColor(pDC);
	}
	return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}
