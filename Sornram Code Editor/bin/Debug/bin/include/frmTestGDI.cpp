// frmTestGDI.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestGDI)
//}}VBto_Converter_Includes

#include "frmTestGDI.h"
CfrmTestGDI *frmTestGDI = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestGDI dialog



CfrmTestGDI::CfrmTestGDI(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestGDI::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestGDI) frmTestGDI = this;
}

void CfrmTestGDI::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestGDI)
	DDX_Control(pDX, Picture1, m_Picture1);
	DDX_Control(pDX, CmdClear, m_CmdClear);
	DDX_Control(pDX, Frame1, m_Frame1);
	DDX_Control(pDX, CheckTimerEnabled, m_CheckTimerEnabled);
	DDX_Control(pDX, rbTimerInterval_2, m_rbTimerInterval_2);
	DDX_Control(pDX, rbTimerInterval_1, m_rbTimerInterval_1);
	DDX_Control(pDX, rbTimerInterval_0, m_rbTimerInterval_0);
	DDX_Control(pDX, Frame2, m_Frame2);
	DDX_Control(pDX, CheckLine, m_CheckLine);
	DDX_Control(pDX, CheckPSet, m_CheckPSet);
	DDX_Control(pDX, CheckRectangle, m_CheckRectangle);
	DDX_Control(pDX, CheckFillRectangle, m_CheckFillRectangle);
	DDX_Control(pDX, CheckCircle, m_CheckCircle);
	DDX_Control(pDX, CheckArc, m_CheckArc);
	DDX_Control(pDX, Frame3, m_Frame3);
	DDX_Control(pDX, Label2, m_Label2);
	DDX_Control(pDX, Label3, m_Label3);
	DDX_Control(pDX, Label4, m_Label4);
	DDX_Control(pDX, ComboFillStyle, m_ComboFillStyle);
	DDX_Control(pDX, ComboDrawWidth, m_ComboDrawWidth);
	DDX_Control(pDX, ComboDrawStyle, m_ComboDrawStyle);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestGDI, CDialog)
	//{{AFX_MSG_MAP(CfrmTestGDI)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(CheckTimerEnabled, OnCheckTimerEnabled)
	ON_BN_CLICKED(rbTimerInterval_0, OnrbTimerInterval_0)
	ON_BN_CLICKED(rbTimerInterval_1, OnrbTimerInterval_1)
	ON_BN_CLICKED(rbTimerInterval_2, OnrbTimerInterval_2)
	ON_BN_CLICKED(CmdClear, OnCmdClear)
	ON_CBN_SELCHANGE(ComboDrawWidth, SelchangeComboDrawWidth)
	ON_CBN_SELCHANGE(ComboDrawStyle, SelchangeComboDrawStyle)
	ON_CBN_SELCHANGE(ComboFillStyle, SelchangeComboFillStyle)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestGDI message handlers

BOOL CfrmTestGDI::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestGDI)
	
	ZeroMemory(m_rbTimerInterval, sizeof(m_rbTimerInterval));
	m_rbTimerInterval[0] = &m_rbTimerInterval_0;
	m_rbTimerInterval[1] = &m_rbTimerInterval_1;
	m_rbTimerInterval[2] = &m_rbTimerInterval_2;
	m_rbTimerInterval_1	.SetCheck(BST_CHECKED);
	m_CheckArc	.SetCheck(BST_CHECKED);
	m_ComboFillStyle	.AddString(" 0");
	m_ComboFillStyle	.AddString(" 1");
	m_ComboFillStyle	.AddString(" 2");
	m_ComboFillStyle	.AddString(" 3");
	m_ComboFillStyle	.AddString(" 4");
	m_ComboFillStyle	.AddString(" 5");
	m_ComboFillStyle	.AddString(" 6");
	m_ComboFillStyle	.SetItemData(0, 0);
	m_ComboFillStyle	.SetItemData(1, 1);
	m_ComboFillStyle	.SetItemData(2, 2);
	m_ComboFillStyle	.SetItemData(3, 3);
	m_ComboFillStyle	.SetItemData(4, 4);
	m_ComboFillStyle	.SetItemData(5, 5);
	m_ComboFillStyle	.SetItemData(6, 6);
	
	m_ComboDrawWidth	.AddString(" 1");
	m_ComboDrawWidth	.AddString(" 2");
	m_ComboDrawWidth	.AddString(" 3");
	m_ComboDrawWidth	.AddString(" 5");
	m_ComboDrawWidth	.AddString(" 7");
	
	Timer1.Set(m_hWnd, IDC_Timer1, 100, true);
	
	Form_Load();
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestGDI::OnPaint() 
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
HCURSOR CfrmTestGDI::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================
// This is a part of the VBto Converter (www.vbto.net)
// Copyright (C) 2005-2007 StressSoft Company Ltd. All rights reserved.




void CfrmTestGDI::Form_Load()
{

	 short i,  iMax; 


#if VBtoVBNET || VBtoCSNET || VBtoVCNET || VBtoJSNET
	iMax = 5;

#else
	iMax = 6;

#endif
	for(i=0; i<=iMax; i++) {
		m_ComboDrawStyle.AddString((Str(i)));
	}

	m_ComboDrawWidth.SetCurSel(0);
	m_ComboDrawStyle.SetCurSel(0);
	m_ComboFillStyle.SetCurSel(1);
	m_CheckTimerEnabled.SetCheck(BST_CHECKED);
}

void CfrmTestGDI::OnCheckTimerEnabled()
{
	// TODO: Add your control notification handler code here
	if (m_CheckTimerEnabled.GetCheck()==BST_CHECKED) {
		Timer1.SetEnabled(true);
	} else {
		Timer1.SetEnabled(false);
	}
	Timer1.SetEnabled(m_CheckTimerEnabled.GetCheck()==BST_CHECKED);
}

void CfrmTestGDI::rbTimerInterval_(short Index)
{
	// TODO: Add your control notification handler code here
	if (Index==0) {
		Timer1.SetInterval(10);
	} else if (Index==1) {
		Timer1.SetInterval(100);
	} else if (Index==2) {
		Timer1.SetInterval(500);
	} else {
		return;
	}
	m_CheckTimerEnabled.SetCheck(BST_CHECKED);
	Timer1.SetEnabled(true);
}
void CfrmTestGDI::OnrbTimerInterval_0()
{
	// TODO: Add your control notification handler code here
	rbTimerInterval_(0);
}
void CfrmTestGDI::OnrbTimerInterval_1()
{
	// TODO: Add your control notification handler code here
	rbTimerInterval_(1);
}
void CfrmTestGDI::OnrbTimerInterval_2()
{
	// TODO: Add your control notification handler code here
	rbTimerInterval_(2);
}

void CfrmTestGDI::OnCmdClear()
{
	// TODO: Add your control notification handler code here
	m_Picture1.RedrawWindow();
	m_Picture1.RedrawWindow();
}
void CfrmTestGDI::CmdClear_Click()
{
	OnCmdClear();
}


void CfrmTestGDI::SelchangeComboDrawWidth()
{
	// TODO: Add your control notification handler code here
	LastPictureProps.DrawWidth = CInt(::GetWindowText(m_ComboDrawWidth));
	CmdClear_Click();
}
void CfrmTestGDI::SelchangeComboDrawStyle()
{
	// TODO: Add your control notification handler code here
	LastPictureProps.DrawStyle = CInt(::GetWindowText(m_ComboDrawStyle));
	CmdClear_Click();
}
void CfrmTestGDI::SelchangeComboFillStyle()
{
	// TODO: Add your control notification handler code here
	LastPictureProps.FillStyle = m_ComboFillStyle.GetCurSel();
	CmdClear_Click();
}

COLORREF CfrmTestGDI::GetRndColor()
{
	COLORREF GetRndColor = 0;
	// VBto upgrade warning: iCol As int	OnWrite(double)
	 double fCol; int iCol; COLORREF col; 
	fCol = Round(8*Rnd());
	iCol = Round(fCol);
	GetRndColor = QBColor(iCol);
	switch (iCol) {
		case 0:
		{

			col = 0xFFFF;
			break;
		}
		case 1:
		{
			col = 0xFFFFFF;
			break;
		}
		case 2:
		{
			col = 0xFF;
			break;
		}
		case 3:
		{
			col = 0xFF00FF;
			break;
		}
		case 4:
		{
			col = 0xFF00;
			break;
		}
		case 5:
		{
			col = 0xFFFF00;
			break;
		}
		case 6:
		{
			col = 0xFF0000;
			break;
		}
		case 7:
		{
			col = 0;
			break;
		}
		default: {
			col = 0;
			break;
		}
	} //end switch
	GetRndColor = col;
	return GetRndColor;
}

void CfrmTestGDI::TestTranslationOnly(bool flRun)
{
	if (!flRun) return;

	 int xC,  yC,  rC; double fi; 
	xC = 1000; yC = 2000; rC = 700; fi = 0.7;
	DrawArcVB6xy(m_Picture1, (xC), yC, rC, fi, 2*M_PI, col);
	DrawArcVB6xy(m_Picture1, (xC), yC, rC, 0, fi, col);
}

void CfrmTestGDI::Timer1_Timer()
{
	// Dim W As Long, H As Long, D As Long
	// W = Picture1.Width
	// H = Picture1.Height
	// D = H / 20

	 const int W=7000,  H=4000; 
	 const double D=200.; 

	// Dim X1 As Double, Y1 As Double, X2 As Double, Y2 As Double
	// VBto upgrade warning: X1 As int	OnWrite(double)
	// VBto upgrade warning: Y1 As int	OnWrite(double)
	// VBto upgrade warning: X2 As int	OnWrite(double)
	// VBto upgrade warning: Y2 As int	OnWrite(double)
	 int X1,  Y1,  X2,  Y2; 
	X1 = Round(D+Rnd()*(W-2*D));
	X2 = Round(D+Rnd()*(W-2*D));
	Y1 = Round(D+Rnd()*(H-2*D));
	Y2 = Round(D+Rnd()*(H-2*D));

	col = GetRndColor();

	if (m_CheckPSet.GetCheck()) {
		DrawPointVB6xy(m_Picture1, (X1), Y1);
		DrawPointVB6xy(m_Picture1, (X2), Y2, col);
	}

	if (m_CheckLine.GetCheck()) {
		DrawLineVB6xy(m_Picture1, (X1), Y1, X2, Y2);
		DrawLineVB6xy(m_Picture1, (X1), Y1, X2, Y2, col);
	}

	if (m_CheckRectangle.GetCheck()) {
		DrawRectangleVB6xy(m_Picture1, (X1), Y1, X2, Y2, 0x0, "B");
		DrawRectangleVB6xy(m_Picture1, (X1), Y1, X2, Y2, col, "B");
	}

	if (m_CheckFillRectangle.GetCheck()) {
		DrawRectangleVB6xy(m_Picture1, (X1), Y1, X2, Y2, 0x0, "BF");
		DrawRectangleVB6xy(m_Picture1, (X1), Y1, X2, Y2, col, "BF");
	}

	if (m_CheckCircle.GetCheck() | m_CheckArc.GetCheck()) {
		// VBto upgrade warning: xC As int	OnWrite(double)
		// VBto upgrade warning: yC As int	OnWrite(double)
		 int xC,  yC; double rC2; int rC; 
		xC = Round((double)(X1+X2) / 2);
		yC = Round((double)(Y1+Y2) / 2);
		rC2 = (X2-X1)*(X2-X1)+(Y2-Y1)*(Y2-Y1);
		rC = CLng(0.6*Rnd()*sqrt(rC2));

		if (m_CheckCircle.GetCheck()) {
			LastPictureProps.FillColor = GetRndColor();
			DrawCircleVB6xy(m_Picture1, (xC), yC, rC);
			DrawCircleVB6xy(m_Picture1, (xC), yC, rC, col);
		}

		if (m_CheckArc.GetCheck()) {
			 double fi,  angle; 
			fi = Rnd()*3.1415926;
			angle = Rnd()*3.1415926;
			// xC = 4000: yC = 3000: fi = 1.4: angle = 1.32
			DrawArcVB6xy(m_Picture1, (xC), yC, rC, fi, fi+angle, 0x0);
			DrawArcVB6xy(m_Picture1, (xC), yC, rC, fi, fi+angle, col);
		}

	}

	TestTranslationOnly(false);
}


void CfrmTestGDI::OnTimer(UINT nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	switch(nIDEvent)
	{
		case IDC_Timer1: {
			Timer1_Timer();
			break;
		}

	}

	CDialog::OnTimer(nIDEvent);
}