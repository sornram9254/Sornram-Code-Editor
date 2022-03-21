// frmTestTimer.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestTimer)
//}}VBto_Converter_Includes

#include "frmTestTimer.h"
CfrmTestTimer *frmTestTimer = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestTimer dialog



CfrmTestTimer::CfrmTestTimer(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestTimer::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestTimer) frmTestTimer = this;
}

void CfrmTestTimer::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestTimer)
	DDX_Control(pDX, Label3, m_Label3);
	DDX_Control(pDX, Frame1, m_Frame1);
	DDX_Control(pDX, Label2, m_Label2);
	DDX_Control(pDX, Label1, m_Label1);
	DDX_Control(pDX, CommandReset, m_CommandReset);
	DDX_Control(pDX, cbTimer2, m_cbTimer2);
	DDX_Control(pDX, txtTimer2, m_txtTimer2);
	DDX_Control(pDX, txtTimer2Interval, m_txtTimer2Interval);
	DDX_Control(pDX, txtTimer1Interval, m_txtTimer1Interval);
	DDX_Control(pDX, txtTimer1, m_txtTimer1);
	DDX_Control(pDX, cbTimer1, m_cbTimer1);
	DDX_Control(pDX, Frame2, m_Frame2);
	DDX_Control(pDX, IDC_TIME, m_IDC_TIME);
	DDX_Control(pDX, CmdReset, m_CmdReset);
	DDX_Control(pDX, CmdStart, m_CmdStart);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestTimer, CDialog)
	//{{AFX_MSG_MAP(CfrmTestTimer)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(cbTimer1, OncbTimer1)
	ON_BN_CLICKED(cbTimer2, OncbTimer2)
	ON_BN_CLICKED(CommandReset, OnCommandReset)
	ON_BN_CLICKED(CmdStart, OnCmdStart)
	ON_BN_CLICKED(CmdReset, OnCmdReset)
	ON_WM_TIMER()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestTimer message handlers

BOOL CfrmTestTimer::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestTimer)
	m_cbTimer2	.SetCheck(BST_CHECKED);
	m_txtTimer2Interval	.SetWindowText("900");
	m_txtTimer1Interval	.SetWindowText("250");
	Timer2.Set(m_hWnd, IDC_Timer2, 200, true);
	m_cbTimer1	.SetCheck(BST_CHECKED);
	Timer1.Set(m_hWnd, IDC_Timer1, 200, true);
	TimerClock.Set(m_hWnd, IDC_TimerClock, 1000, false);
	CounterTimer1 = CounterTimer2 = 0;
	lTime = 0;
	
	fm_Label3.Set(GetDlgItem(Label3), RGB(128,0,0), GetSysColor(COLOR_BTNFACE));
	fm_IDC_TIME.Set(GetDlgItem(IDC_TIME), RGB(0,255,0), RGB(0,0,0),"Arial",36,false,false,false,false,ANSI_CHARSET);
	
	
	Form_Load();
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestTimer::OnPaint() 
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
HCURSOR CfrmTestTimer::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================
// This is a part of the VBto Converter (www.vbto.net)
// Copyright (C) 2005-2009 StressSoft Company Ltd. All rights reserved.





void CfrmTestTimer::Form_Load()
{
	// CounterTimer1 = 0: CounterTimer2 = 0
	ResetInterval();
	Timer1.SetEnabled(m_cbTimer1.GetCheck()==BST_CHECKED);
	Timer2.SetEnabled(BST_CHECKED==m_cbTimer2.GetCheck());
}

void CfrmTestTimer::ResetInterval()
{
	Timer1.SetInterval(CLng(::GetWindowText(m_txtTimer1Interval)));
	Timer2.SetInterval(CLng(::GetWindowText(m_txtTimer2Interval)));
}

void CfrmTestTimer::OncbTimer1()
{
	// TODO: Add your control notification handler code here
	// VBto upgrade warning: en As bool	OnWrite(VBRUN.CheckBoxConstants)
	 bool en; 
	en = m_cbTimer1.GetCheck()==BST_CHECKED;
	ResetInterval();
	Timer1.SetEnabled(en);
	m_txtTimer1.EnableWindow(en);
	m_txtTimer1Interval.EnableWindow(!m_txtTimer1.IsWindowEnabled());
}
void CfrmTestTimer::Timer1_Timer()
{
	CounterTimer1 += 1;
	m_txtTimer1.SetWindowText(Str(CounterTimer1));
}

void CfrmTestTimer::OncbTimer2()
{
	// TODO: Add your control notification handler code here
	// VBto upgrade warning: en As bool	OnWrite(VBRUN.CheckBoxConstants)
	 bool en; 
	en = m_cbTimer2.GetCheck()==BST_CHECKED;
	ResetInterval();
	Timer2.SetEnabled(en);
	m_txtTimer2.EnableWindow(en);
	m_txtTimer2Interval.EnableWindow(!m_txtTimer2.IsWindowEnabled());
}
void CfrmTestTimer::Timer2_Timer()
{
	CounterTimer2 += 1;
	m_txtTimer2.SetWindowText(Str(CounterTimer2));
}

void CfrmTestTimer::OnCommandReset()
{
	// TODO: Add your control notification handler code here
	CounterTimer1 = 0; m_txtTimer1.SetWindowText("");
	CounterTimer2 = 0; m_txtTimer2.SetWindowText("");
}


// +++++++++++++++++++++++++++++++++++++++++++++++++++
void CfrmTestTimer::OnCmdStart()
{
	// TODO: Add your control notification handler code here
	TimerClock.SetEnabled(!TimerClock.Enabled);
	if (TimerClock.Enabled) {
		m_CmdStart.SetWindowText("Stop");
	} else {
		m_CmdStart.SetWindowText("Start");
	}
}

void CfrmTestTimer::OnCmdReset()
{
	// TODO: Add your control notification handler code here
	lTime = 0;
	ShowTime();
}

void CfrmTestTimer::TimerClock_Timer()
{
	lTime += 1;
	ShowTime();
}

void CfrmTestTimer::ShowTime()
{
	 int sec,  min; 
	min = Int((double)lTime / 60);
	sec = lTime %  60;
	m_IDC_TIME.SetWindowText(FormatVB(min,"00")+":"+FormatVB(sec,"00"));
}


void CfrmTestTimer::OnTimer(UINT nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	switch(nIDEvent)
	{
		case IDC_Timer1: {
			Timer1_Timer();
			break;
		}

		case IDC_Timer2: {
			Timer2_Timer();
			break;
		}

		case IDC_TimerClock: {
			TimerClock_Timer();
			break;
		}

	}

	CDialog::OnTimer(nIDEvent);
}
HBRUSH CfrmTestTimer::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch(pWnd->GetDlgCtrlID()) {
		case Label3:	return fm_Label3	.OnCtlColor(pDC);
		case IDC_TIME:	return fm_IDC_TIME	.OnCtlColor(pDC);
	}
	return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}
