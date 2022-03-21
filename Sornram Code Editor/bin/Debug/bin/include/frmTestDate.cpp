// frmTestDate.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestDate)
//}}VBto_Converter_Includes

#include "frmTestDate.h"
CfrmTestDate *frmTestDate = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestDate dialog



CfrmTestDate::CfrmTestDate(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestDate::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestDate) frmTestDate = this;
}

void CfrmTestDate::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestDate)
	DDX_Control(pDX, Label1, m_Label1);
	DDX_Control(pDX, Text1, m_Text1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestDate, CDialog)
	//{{AFX_MSG_MAP(CfrmTestDate)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestDate message handlers

BOOL CfrmTestDate::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestDate)
	TimerNow.Set(m_hWnd, IDC_TimerNow, 300, true);
	
	fm_Text1.Set(GetDlgItem(Text1), GetSysColor(COLOR_WINDOWTEXT), GetSysColor(COLOR_WINDOW),"Courier",9.75,false,false,false,false,RUSSIAN_CHARSET);
	
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestDate::OnPaint() 
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
HCURSOR CfrmTestDate::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================
// This is a part of the VBto Converter (www.vbto.net)
// Copyright (C) 2005-2009 StressSoft Company Ltd. All rights reserved.


CString CfrmTestDate::myDateToString(DATE dt)
{
	CString myDateToString;
	 CString ds,  ts; 
	ds = Str(COleDateTime(dt).GetDay())+"/"+Str(COleDateTime(dt).GetMonth())+"/"+Str(COleDateTime(dt).GetYear());
	ts = Str(COleDateTime(dt).GetHour())+":"+Str(COleDateTime(dt).GetMinute())+":"+Str(COleDateTime(dt).GetSecond());
	myDateToString = ds+"  "+ts;
	return myDateToString;
}

void CfrmTestDate::TimerNow_Timer()
{
	// VBto upgrade warning: D As DATE	OnWrite(double, DATE)
	 CString S; DATE D; CString wd; 

	 /*? On Error Resume Next  */

	S = "Time:      "+myDateToString(vbTime());
	S += CString("\r\n")+"Date:      "+myDateToString(vbDate());

	D = vbDate()+vbTime();
	S += CString("\r\n")+"Date+Time: "+myDateToString(D);

	D = COleDateTime::GetCurrentTime();
	S += CString("\r\n")+"Now:       "+myDateToString(D);

	switch ((int)COleDateTime(D).GetDayOfWeek()) {
		case vbSunday:
		{

			wd = "Sunday";
			break;
		}
		case vbMonday:
		{
			wd = "Monday";
			break;
		}
		case vbTuesday:
		{
			wd = "Tuesday";
			break;
		}
		case vbWednesday:
		{
			wd = "Wednesday";
			break;
		}
		case vbThursday:
		{
			wd = "Thursday";
			break;
		}
		case vbFriday:
		{
			wd = "Friday";
			break;
		}
		case vbSaturday:
		{
			wd = "Saturday";
			break;
		}
		default: {
			wd = "UnknownDay";
			break;
		}
	} //end switch

	S += CString("\r\n")+"Weekday: "+wd;

	S += CString("\r\n")+"Date$:   "+vbDateStr();
	S += CString("\r\n")+"Time$:   "+vbTimeStr();

	m_Text1.SetWindowText(S);

	TestTypecastDate();

	S += "x";
	S = "x"+S;
	S = "a"+CString("x");
}

void CfrmTestDate::TestTypecastDate()
{
	// VBto upgrade warning: D As DATE	OnWrite(DATE, int, double, CString)
	 DATE D; CString S; 
	// VBto upgrade warning: lD As int	OnWrite(DATE)
	// VBto upgrade warning: fD As float	OnWrite(DATE)
	// VBto upgrade warning: dD As double	OnWrite(DATE)
	// VBto upgrade warning: sD As CString	OnWrite(DATE)
	 int lD; float fD; double dD; CString sD; short iD; 

	D = COleDateTime::GetCurrentTime();
	S += CString("\r\n")+"Str(Now)  :  "+DATEtoCString(D);
	S += CString("\r\n")+"Str(Now)  :  "+DATEtoCString(COleDateTime::GetCurrentTime());

	dD = D;
	fD = float(D);
	lD = int(D);
	sD = COleDateTime(D).Format();

	S += CString("\r\n")+"Now to Long:    "+Str(lD);
	S += CString("\r\n")+"Now to Single:  "+Str(fD);
	S += CString("\r\n")+"Now to Double:  "+Str(dD);
	S += CString("\r\n")+"Now to String:   "+sD;
	S += "\r\n";

	D = 22848;
	iD = 22848; D = iD;
	S += CString("\r\n")+"Typecast from 22848:   "+myDateToString(D);

	D = lD;
	S += CString("\r\n")+"Typecast from Long:    "+myDateToString(D);

	D = fD;
	S += CString("\r\n")+"Typecast from Single:  "+myDateToString(D);

	D = dD;
	S += CString("\r\n")+"Typecast from Double:  "+myDateToString(D);

	D = StrToDATE(sD);
	S += CString("\r\n")+"Typecast from String:  "+myDateToString(D);

	m_Text1.SetWindowText(::GetWindowText(m_Text1)+CString("\r\n")+S);
}



void CfrmTestDate::OnTimer(UINT nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	switch(nIDEvent)
	{
		case IDC_TimerNow: {
			TimerNow_Timer();
			break;
		}

	}

	CDialog::OnTimer(nIDEvent);
}
HBRUSH CfrmTestDate::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch(pWnd->GetDlgCtrlID()) {
		case Text1:	return fm_Text1	.OnCtlColor(pDC);
	}
	return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}
