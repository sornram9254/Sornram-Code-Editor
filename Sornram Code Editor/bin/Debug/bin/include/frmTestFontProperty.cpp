// frmTestFontProperty.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestFontProperty)
//}}VBto_Converter_Includes

#include "frmTestFontProperty.h"
CfrmTestFontProperty *frmTestFontProperty = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestFontProperty dialog



CfrmTestFontProperty::CfrmTestFontProperty(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestFontProperty::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestFontProperty) frmTestFontProperty = this;
}

void CfrmTestFontProperty::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestFontProperty)
	DDX_Control(pDX, FrameTest, m_FrameTest);
	DDX_Control(pDX, LblTest, m_LblTest);
	DDX_Control(pDX, EdtTest, m_EdtTest);
	DDX_Control(pDX, CmdTest, m_CmdTest);
	DDX_Control(pDX, CheckTest, m_CheckTest);
	DDX_Control(pDX, OptTest, m_OptTest);
	DDX_Control(pDX, Frame1, m_Frame1);
	DDX_Control(pDX, Label2, m_Label2);
	DDX_Control(pDX, cbStrikethrough, m_cbStrikethrough);
	DDX_Control(pDX, CmdSizeMinus, m_CmdSizeMinus);
	DDX_Control(pDX, CmdSizePlus, m_CmdSizePlus);
	DDX_Control(pDX, cbUnderline, m_cbUnderline);
	DDX_Control(pDX, cbBold, m_cbBold);
	DDX_Control(pDX, cbItalic, m_cbItalic);
	DDX_Control(pDX, CmdForeColorRed, m_CmdForeColorRed);
	DDX_Control(pDX, CmdForeColorYellow, m_CmdForeColorYellow);
	DDX_Control(pDX, CmdBackColorBlue, m_CmdBackColorBlue);
	DDX_Control(pDX, CmdBackColorCyan, m_CmdBackColorCyan);
	DDX_Control(pDX, ComboFontName, m_ComboFontName);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestFontProperty, CDialog)
	//{{AFX_MSG_MAP(CfrmTestFontProperty)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(ComboFontName, SelchangeComboFontName)
	ON_BN_CLICKED(CmdBackColorBlue, OnCmdBackColorBlue)
	ON_BN_CLICKED(CmdBackColorCyan, OnCmdBackColorCyan)
	ON_BN_CLICKED(CmdForeColorYellow, OnCmdForeColorYellow)
	ON_BN_CLICKED(CmdForeColorRed, OnCmdForeColorRed)
	ON_BN_CLICKED(CmdSizePlus, OnCmdSizePlus)
	ON_BN_CLICKED(CmdSizeMinus, OnCmdSizeMinus)
	ON_BN_CLICKED(cbBold, OncbBold)
	ON_BN_CLICKED(cbItalic, OncbItalic)
	ON_BN_CLICKED(cbStrikethrough, OncbStrikethrough)
	ON_BN_CLICKED(cbUnderline, OncbUnderline)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestFontProperty message handlers

BOOL CfrmTestFontProperty::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestFontProperty)
	m_EdtTest	.SetWindowText("Test Test Test Test Test Test Test Test");
	m_cbStrikethrough	.SetCheck(BST_INDETERMINATE);
	m_cbUnderline	.SetCheck(BST_INDETERMINATE);
	m_cbBold	.SetCheck(BST_INDETERMINATE);
	m_cbItalic	.SetCheck(BST_INDETERMINATE);
	m_ComboFontName	.AddString("Arial");
	m_ComboFontName	.AddString("Courier");
	m_ComboFontName	.AddString("Courier New");
	m_ComboFontName	.AddString("MS Sans Serif");
	m_ComboFontName	.AddString("Symbol");
	m_ComboFontName	.AddString("Terminal");
	m_ComboFontName	.AddString("Unknown");
	
	Value = 0;	bValue = 0;
	
	fm_FrameTest.Set(GetDlgItem(FrameTest), GetSysColor(COLOR_BTNTEXT), GetSysColor(COLOR_BTNFACE),"MS Sans Serif",8.25,true,false,false,false,RUSSIAN_CHARSET);
	fm_LblTest.Set(GetDlgItem(LblTest), RGB(128,0,128), RGB(255,128,0),"MS Sans Serif",9.75,false,true,true,false,RUSSIAN_CHARSET);
	fm_EdtTest.Set(GetDlgItem(EdtTest), GetSysColor(COLOR_INFOBK), GetSysColor(COLOR_BACKGROUND),"MS Sans Serif",12,false,false,false,true,RUSSIAN_CHARSET);
	fm_CmdTest.Set(GetDlgItem(CmdTest), GetSysColor(COLOR_BTNTEXT), GetSysColor(COLOR_BTNFACE),"Arial",9.75,true,true,false,false,RUSSIAN_CHARSET);
	fm_CheckTest.Set(GetDlgItem(CheckTest), GetSysColor(COLOR_BTNTEXT), GetSysColor(COLOR_BTNFACE),"Courier New",8.25,false,true,false,false,RUSSIAN_CHARSET);
	fm_OptTest.Set(GetDlgItem(OptTest), GetSysColor(COLOR_BTNTEXT), GetSysColor(COLOR_BTNFACE),"Arial Black",8.25,false,false,false,false,RUSSIAN_CHARSET);
	fm_Frame1.Set(GetDlgItem(Frame1), RGB(192,0,192), GetSysColor(COLOR_BTNFACE));
	
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestFontProperty::OnPaint() 
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
HCURSOR CfrmTestFontProperty::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================



void CfrmTestFontProperty::SelchangeComboFontName()
{
	// TODO: Add your control notification handler code here
	 CString sFontName; 
	sFontName = ::GetWindowText(m_ComboFontName);
	fm_FrameTest.SetFontName(sFontName);
	fm_LblTest.SetFontName(sFontName);
	fm_EdtTest.SetFontName(sFontName);
	fm_CmdTest.SetFontName(sFontName);
	fm_CheckTest.SetFontName(sFontName);
	fm_OptTest.SetFontName(sFontName);
	ShowProps();
}

void CfrmTestFontProperty::SetBackColor(COLORREF col)
{
	// ? FrameTest.BackColor = col
	fm_LblTest.SetBackColor(col);
	fm_EdtTest.SetBackColor(col);
	fm_CheckTest.SetBackColor(col);
	fm_OptTest.SetBackColor(col);

#if !(VBtoDelphi || VBtoBuilder)
	fm_CmdTest.SetBackColor(col);

#endif
	ShowProps();
}
void CfrmTestFontProperty::OnCmdBackColorBlue()
{
	// TODO: Add your control notification handler code here
	SetBackColor(0xFF0000);
}
void CfrmTestFontProperty::OnCmdBackColorCyan()
{
	// TODO: Add your control notification handler code here
	SetBackColor(0xFFFF00);
}

// VBto upgrade warning: col As int --> As COLORREF
void CfrmTestFontProperty::SetForeColor(COLORREF col)
{
	fm_FrameTest.SetForeColor(col);
	fm_LblTest.SetForeColor(col);
	fm_EdtTest.SetForeColor(col);
	fm_CheckTest.SetForeColor(col);
	fm_OptTest.SetForeColor(col);
	ShowProps();
}
void CfrmTestFontProperty::OnCmdForeColorYellow()
{
	// TODO: Add your control notification handler code here
	SetForeColor(0xFFFF);
}
void CfrmTestFontProperty::OnCmdForeColorRed()
{
	// TODO: Add your control notification handler code here
	SetForeColor(0xFF);
}

void CfrmTestFontProperty::OnCmdSizePlus()
{
	// TODO: Add your control notification handler code here
	Value = (float)(fm_LblTest.GetFontSize()+2);
	fm_FrameTest.SetFontSize(Value);
	fm_LblTest.SetFontSize(Value);
	fm_EdtTest.SetFontSize(Value);
	fm_CmdTest.SetFontSize(Value);
	fm_CheckTest.SetFontSize(Value);
	fm_OptTest.SetFontSize(Value);
	ShowProps();
}
void CfrmTestFontProperty::OnCmdSizeMinus()
{
	// TODO: Add your control notification handler code here
	Value = (float)(fm_LblTest.GetFontSize()-2);
	if (Value<2) Value = 2;
	fm_FrameTest.SetFontSize(Value);
	fm_LblTest.SetFontSize(Value);
	fm_EdtTest.SetFontSize(Value);
	fm_CmdTest.SetFontSize(Value);
	fm_CheckTest.SetFontSize(Value);
	fm_OptTest.SetFontSize(Value);
	ShowProps();
}

void CfrmTestFontProperty::OncbBold()
{
	// TODO: Add your control notification handler code here
	bValue = m_cbBold.GetCheck()==BST_CHECKED;
	fm_FrameTest.SetFontBold(bValue);
	fm_LblTest.SetFontBold(bValue);
	fm_EdtTest.SetFontBold(bValue);
	fm_CmdTest.SetFontBold(bValue);
	fm_CheckTest.SetFontBold(bValue);
	fm_OptTest.SetFontBold(bValue);
	ShowProps();
}
void CfrmTestFontProperty::OncbItalic()
{
	// TODO: Add your control notification handler code here
	bValue = m_cbItalic.GetCheck()==BST_CHECKED;
	fm_FrameTest.SetFontItalic(bValue);
	fm_LblTest.SetFontItalic(bValue);
	fm_EdtTest.SetFontItalic(bValue);
	fm_CmdTest.SetFontItalic(bValue);
	fm_CheckTest.SetFontItalic(bValue);
	fm_OptTest.SetFontItalic(bValue);
	ShowProps();
}
void CfrmTestFontProperty::OncbStrikethrough()
{
	// TODO: Add your control notification handler code here
	bValue = m_cbStrikethrough.GetCheck()==BST_CHECKED;
	fm_FrameTest.SetFontStrikeOut(bValue);
	fm_LblTest.SetFontStrikeOut(bValue);
	fm_EdtTest.SetFontStrikeOut(bValue);
	fm_CmdTest.SetFontStrikeOut(bValue);
	fm_CheckTest.SetFontStrikeOut(bValue);
	fm_OptTest.SetFontStrikeOut(bValue);
	ShowProps();
}
void CfrmTestFontProperty::OncbUnderline()
{
	// TODO: Add your control notification handler code here
	bValue = m_cbUnderline.GetCheck()==BST_CHECKED;
	fm_FrameTest.SetFontUnderline(bValue);
	fm_LblTest.SetFontUnderline(bValue);
	fm_EdtTest.SetFontUnderline(bValue);
	fm_CmdTest.SetFontUnderline(bValue);
	fm_CheckTest.SetFontUnderline(bValue);
	fm_OptTest.SetFontUnderline(bValue);
	ShowProps();
}

void CfrmTestFontProperty::ShowProps()
{
	 CString s; 
	s = "\""+fm_LblTest.GetFontName()+"\"";
	s += CString(";  Size=")+Str(fm_LblTest.GetFontSize());
	if (fm_LblTest.GetFontBold()) s = s+";  Bold";
	if (fm_LblTest.GetFontItalic()) s = s+";  Italic";
	if (fm_LblTest.GetFontStrikeOut()) s = s+";  Strikethrough";
	if (fm_LblTest.GetFontUnderline()) s = s+";  Underline";
	m_FrameTest.SetWindowText(s);
}

HBRUSH CfrmTestFontProperty::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch(pWnd->GetDlgCtrlID()) {
		case FrameTest:	return fm_FrameTest	.OnCtlColor(pDC);
		case LblTest:	return fm_LblTest	.OnCtlColor(pDC);
		case EdtTest:	return fm_EdtTest	.OnCtlColor(pDC);
		case CmdTest:	return fm_CmdTest	.OnCtlColor(pDC);
		case CheckTest:	return fm_CheckTest	.OnCtlColor(pDC);
		case OptTest:	return fm_OptTest	.OnCtlColor(pDC);
		case Frame1:	return fm_Frame1	.OnCtlColor(pDC);
	}
	return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}
