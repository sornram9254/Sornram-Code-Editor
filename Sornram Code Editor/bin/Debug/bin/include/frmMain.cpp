// frmMain.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmMain)
//}}VBto_Converter_Includes

#include "frmMain.h"
CfrmMain *frmMain = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmMain dialog



CfrmMain::CfrmMain(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmMain::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmMain) frmMain = this;
}

void CfrmMain::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmMain)
	DDX_Control(pDX, Label1, m_Label1);
	DDX_Control(pDX, CmdTestEvents, m_CmdTestEvents);
	DDX_Control(pDX, CmdTestListBox, m_CmdTestListBox);
	DDX_Control(pDX, CmdTestMath, m_CmdTestMath);
	DDX_Control(pDX, CmdTestMsgBox, m_CmdTestMsgBox);
	DDX_Control(pDX, CmdTestString, m_CmdTestString);
	DDX_Control(pDX, CmdTestVisible, m_CmdTestVisible);
	DDX_Control(pDX, CmdTestFormProperty, m_CmdTestFormProperty);
	DDX_Control(pDX, CmdTestForm1, m_CmdTestForm1);
	DDX_Control(pDX, CmdTestForm2, m_CmdTestForm2);
	DDX_Control(pDX, CmdTestForm3, m_CmdTestForm3);
	DDX_Control(pDX, CmdTestDoWhile, m_CmdTestDoWhile);
	DDX_Control(pDX, CmdTestSelect, m_CmdTestSelect);
	DDX_Control(pDX, CmdTestTimer, m_CmdTestTimer);
	DDX_Control(pDX, CmdTestLen, m_CmdTestLen);
	DDX_Control(pDX, CmdTestCommonDialog, m_CmdTestCommonDialog);
	DDX_Control(pDX, CmdTestArray, m_CmdTestArray);
	DDX_Control(pDX, CmdTestMisc, m_CmdTestMisc);
	DDX_Control(pDX, CmdTestGDI, m_CmdTestGDI);
	DDX_Control(pDX, CmdTestCursor, m_CmdTestCursor);
	DDX_Control(pDX, CmdTestTypeCast, m_CmdTestTypeCast);
	DDX_Control(pDX, CmdTestLike, m_CmdTestLike);
	DDX_Control(pDX, CmdTestExpression, m_CmdTestExpression);
	DDX_Control(pDX, CmdTestModuleClass, m_CmdTestModuleClass);
	DDX_Control(pDX, CmdTestReDim, m_CmdTestReDim);
	DDX_Control(pDX, CmdTestListView, m_CmdTestListView);
	DDX_Control(pDX, CmdTestOnError, m_CmdTestOnError);
	DDX_Control(pDX, CmdTestControlArrays, m_CmdTestControlArrays);
	DDX_Control(pDX, CmdTestAutoDim, m_CmdTestAutoDim);
	DDX_Control(pDX, CmdTestInputBox, m_CmdTestInputBox);
	DDX_Control(pDX, CmdTestPropertyGetLet, m_CmdTestPropertyGetLet);
	DDX_Control(pDX, CmdTestPrinter, m_CmdTestPrinter);
	DDX_Control(pDX, CmdTestTabStrip, m_CmdTestTabStrip);
	DDX_Control(pDX, CmdTestPaint, m_CmdTestPaint);
	DDX_Control(pDX, CmdTestNamedArgs, m_CmdTestNamedArgs);
	DDX_Control(pDX, CmdTestFontProperty, m_CmdTestFontProperty);
	DDX_Control(pDX, CmdTestStatusBar, m_CmdTestStatusBar);
	DDX_Control(pDX, CmdTestTreeView, m_CmdTestTreeView);
	DDX_Control(pDX, CmdTestDeclare, m_CmdTestDeclare);
	DDX_Control(pDX, CmdTestExtConsts, m_CmdTestExtConsts);
	DDX_Control(pDX, CmdTestDate, m_CmdTestDate);
	DDX_Control(pDX, CmdTestFileSystemObject, m_CmdTestFileSystemObject);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmMain, CDialog)
	//{{AFX_MSG_MAP(CfrmMain)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_COMMAND(mmForm1, OnmmForm1)
	ON_COMMAND(mmForm2, OnmmForm2)
	ON_COMMAND(mmForm3, OnmmForm3)
	ON_COMMAND(mmClose, OnmmClose)
	ON_COMMAND(mmExit, OnmmExit)
	ON_BN_CLICKED(CmdTestForm1, OnCmdTestForm1)
	ON_BN_CLICKED(CmdTestForm2, OnCmdTestForm2)
	ON_BN_CLICKED(CmdTestForm3, OnCmdTestForm3)
	ON_BN_CLICKED(CmdTestCommonDialog, OnCmdTestCommonDialog)
	ON_BN_CLICKED(CmdTestVisible, OnCmdTestVisible)
	ON_BN_CLICKED(CmdTestFormProperty, OnCmdTestFormProperty)
	ON_BN_CLICKED(CmdTestEvents, OnCmdTestEvents)
	ON_BN_CLICKED(CmdTestListBox, OnCmdTestListBox)
	ON_BN_CLICKED(CmdTestMsgBox, OnCmdTestMsgBox)
	ON_BN_CLICKED(CmdTestString, OnCmdTestString)
	ON_BN_CLICKED(CmdTestDoWhile, OnCmdTestDoWhile)
	ON_BN_CLICKED(CmdTestSelect, OnCmdTestSelect)
	ON_BN_CLICKED(CmdTestMath, OnCmdTestMath)
	ON_BN_CLICKED(CmdTestTimer, OnCmdTestTimer)
	ON_BN_CLICKED(CmdTestLen, OnCmdTestLen)
	ON_BN_CLICKED(CmdTestArray, OnCmdTestArray)
	ON_BN_CLICKED(CmdTestMisc, OnCmdTestMisc)
	ON_BN_CLICKED(CmdTestGDI, OnCmdTestGDI)
	ON_BN_CLICKED(CmdTestCursor, OnCmdTestCursor)
	ON_BN_CLICKED(CmdTestTypeCast, OnCmdTestTypeCast)
	ON_BN_CLICKED(CmdTestLike, OnCmdTestLike)
	ON_BN_CLICKED(CmdTestExpression, OnCmdTestExpression)
	ON_BN_CLICKED(CmdTestModuleClass, OnCmdTestModuleClass)
	ON_BN_CLICKED(CmdTestReDim, OnCmdTestReDim)
	ON_BN_CLICKED(CmdTestOnError, OnCmdTestOnError)
	ON_BN_CLICKED(CmdTestListView, OnCmdTestListView)
	ON_BN_CLICKED(CmdTestControlArrays, OnCmdTestControlArrays)
	ON_BN_CLICKED(CmdTestAutoDim, OnCmdTestAutoDim)
	ON_BN_CLICKED(CmdTestInputBox, OnCmdTestInputBox)
	ON_BN_CLICKED(CmdTestPropertyGetLet, OnCmdTestPropertyGetLet)
	ON_BN_CLICKED(CmdTestPrinter, OnCmdTestPrinter)
	ON_BN_CLICKED(CmdTestTabStrip, OnCmdTestTabStrip)
	ON_BN_CLICKED(CmdTestNamedArgs, OnCmdTestNamedArgs)
	ON_BN_CLICKED(CmdTestFontProperty, OnCmdTestFontProperty)
	ON_BN_CLICKED(CmdTestPaint, OnCmdTestPaint)
	ON_BN_CLICKED(CmdTestStatusBar, OnCmdTestStatusBar)
	ON_BN_CLICKED(CmdTestTreeView, OnCmdTestTreeView)
	ON_BN_CLICKED(CmdTestDeclare, OnCmdTestDeclare)
	ON_BN_CLICKED(CmdTestExtConsts, OnCmdTestExtConsts)
	ON_BN_CLICKED(CmdTestDate, OnCmdTestDate)
	ON_BN_CLICKED(CmdTestFileSystemObject, OnCmdTestFileSystemObject)
	ON_WM_TIMER()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmMain message handlers

BOOL CfrmMain::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmMain)
	m_StatusBar1.Create(WS_CHILD|SBT_OWNERDRAW|WS_VISIBLE|CCS_BOTTOM, CRect(0,0,0,0), this, 0);
	{ int statusBarPannelsWidth[1]= { 75 };
	m_StatusBar1.SetParts(1, statusBarPannelsWidth); }
	m_StatusBar1.SetSimple();
	
	TimerNow.Set(m_hWnd, IDC_TimerNow, 300, true);
	m_tooltip	.Create(this);
	m_tooltip	.Activate(TRUE);
	m_tooltip	.AddTool(&m_CmdTestFileSystemObject, "Test FileSystemObject");
	
	fm_Label1.Set(GetDlgItem(Label1), RGB(0,0,255), GetSysColor(COLOR_BTNFACE),"MS Sans Serif",8.25,true,false,false,false,RUSSIAN_CHARSET);
	
	
	Form_Load();
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmMain::OnPaint() 
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

		HICON hBackgroundIcon = AfxGetApp()->LoadIcon(frmMain_BackgroundPicture);
		dc.DrawIcon(0,0,hBackgroundIcon);

		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CfrmMain::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================
// This is a part of the VBto Converter (www.vbto.net)
// Copyright (C) 2005-2011 StressSoft Company Ltd. All rights reserved.


void CfrmMain::Form_Load()
{


#if VB6
	this->SetWindowText(::GetWindowText(this)+" (VB6)");

#elif VBtoVBNET
	this->SetWindowText(::GetWindowText(this)+" (VB .NET)");

#elif VBtoCSNET
	this->SetWindowText(::GetWindowText(this)+" (C# .NET)");

#elif VBtoVCNET
	this->SetWindowText(::GetWindowText(this)+" (VC .NET)");

#elif VBtoVCMFC
	this->SetWindowText(::GetWindowText(this)+" (VC++ MFC)");

#elif VBtoBuilder
	this->SetWindowText(::GetWindowText(this)+" (C++ Builder)");

#elif VBtoDelphi
	this->SetWindowText(::GetWindowText(this)+" (Delphi)");

#elif VBtoJSNET
	this->SetWindowText(::GetWindowText(this)+" (J# .NET)");

#endif

}

void CfrmMain::Form_QueryUnload(short& Cancel, short UnloadMode)
{
	// Dim ret As VbMsgBoxResult
	// ret = MsgBox("Do you want to quit the program?", vbQuestion + vbYesNo, "MsgBox from ""Form_QueryUnload""")
	// If ret <> vbYes Then Cancel = 1
}

void CfrmMain::OnClose()
{
	short Cancel = 0;

	Form_QueryUnload(Cancel, 0);
	if (Cancel) return;

	Form_Unload(Cancel);
	if (!Cancel) CDialog::OnClose();	// OnOK();
}
void CfrmMain::Form_Unload(short& Cancel)
{
	// Dim ret As VbMsgBoxResult
	// ret = MsgBox("Do you want to quit the program?", vbQuestion + vbYesNo, "MsgBox from ""Form_Unload""")
	// If ret <> vbYes Then Cancel = 1
}

void CfrmMain::OnmmForm1()
{
	// TODO: Add your command handler code here
	CForm1::InstancePtr()->DoModal();
}
void CfrmMain::OnmmForm2()
{
	// TODO: Add your command handler code here
	CForm2::InstancePtr()->DoModal();
}
void CfrmMain::OnmmForm3()
{
	// TODO: Add your command handler code here
	CForm3::InstancePtr()->DoModal();
}
void CfrmMain::OnmmClose()
{
	// TODO: Add your command handler code here
	PostMessage(WM_CLOSE,0,0);
}
void CfrmMain::OnmmExit()
{
	// TODO: Add your command handler code here
	exit(0);
}

void CfrmMain::OnCmdTestForm1()
{
	// TODO: Add your control notification handler code here
	CForm1::InstancePtr()->DoModal();
}
void CfrmMain::OnCmdTestForm2()
{
	// TODO: Add your control notification handler code here
	CForm2::InstancePtr()->DoModal();
}
void CfrmMain::OnCmdTestForm3()
{
	// TODO: Add your control notification handler code here
	CForm3::InstancePtr()->DoModal();
}
void CfrmMain::OnCmdTestCommonDialog()
{
	// TODO: Add your control notification handler code here
	CfrmTestCommonDialog::InstancePtr()->DoModal();
}

void CfrmMain::OnCmdTestVisible()
{
	// TODO: Add your control notification handler code here
	CfrmTestVisible::InstancePtr()->DoModal();
}
void CfrmMain::OnCmdTestFormProperty()
{
	// TODO: Add your control notification handler code here
	CfrmTestFormProperty::InstancePtr()->DoModal();
}
void CfrmMain::OnCmdTestEvents()
{
	// TODO: Add your control notification handler code here
	CfrmTestEvents::InstancePtr()->DoModal();
}

void CfrmMain::OnCmdTestListBox()
{
	// TODO: Add your control notification handler code here
	CfrmTestListBox::InstancePtr()->DoModal();
}
void CfrmMain::OnCmdTestMsgBox()
{
	// TODO: Add your control notification handler code here
	CfrmTestMsgBox::InstancePtr()->DoModal();
}

void CfrmMain::OnCmdTestString()
{
	// TODO: Add your control notification handler code here
	CfrmTestString::InstancePtr()->DoModal();
}
void CfrmMain::OnCmdTestDoWhile()
{
	// TODO: Add your control notification handler code here
	CfrmTestDoWhile::InstancePtr()->DoModal();
}
void CfrmMain::OnCmdTestSelect()
{
	// TODO: Add your control notification handler code here
	CfrmTestSelect::InstancePtr()->DoModal();
}
void CfrmMain::OnCmdTestMath()
{
	// TODO: Add your control notification handler code here
	CfrmTestMath::InstancePtr()->DoModal();
}
void CfrmMain::OnCmdTestTimer()
{
	// TODO: Add your control notification handler code here
	CfrmTestTimer::InstancePtr()->DoModal();
}
void CfrmMain::OnCmdTestLen()
{
	// TODO: Add your control notification handler code here
	CfrmTestLen::InstancePtr()->DoModal();
}
void CfrmMain::OnCmdTestArray()
{
	// TODO: Add your control notification handler code here
	CfrmTestArray::InstancePtr()->DoModal();
}
void CfrmMain::OnCmdTestMisc()
{
	// TODO: Add your control notification handler code here
	CfrmTestMisc::InstancePtr()->DoModal();
}
void CfrmMain::OnCmdTestGDI()
{
	// TODO: Add your control notification handler code here
	CfrmTestGDI::InstancePtr()->DoModal();
}
void CfrmMain::OnCmdTestCursor()
{
	// TODO: Add your control notification handler code here
	CfrmTestCursor::InstancePtr()->DoModal();
}

void CfrmMain::OnCmdTestTypeCast()
{
	// TODO: Add your control notification handler code here
	CfrmTestTypeCast::InstancePtr()->DoModal();
}
void CfrmMain::OnCmdTestLike()
{
	// TODO: Add your control notification handler code here
	CfrmTestLike::InstancePtr()->DoModal();
}
void CfrmMain::OnCmdTestExpression()
{
	// TODO: Add your control notification handler code here
	CfrmTestExpression::InstancePtr()->DoModal();
}
void CfrmMain::OnCmdTestModuleClass()
{
	// TODO: Add your control notification handler code here
	CfrmTestModuleClass::InstancePtr()->DoModal();
}
void CfrmMain::OnCmdTestReDim()
{
	// TODO: Add your control notification handler code here
	CfrmTestReDim::InstancePtr()->DoModal();
}
void CfrmMain::OnCmdTestOnError()
{
	// TODO: Add your control notification handler code here
	CfrmTestOnError::InstancePtr()->DoModal();
}
void CfrmMain::OnCmdTestListView()
{
	// TODO: Add your control notification handler code here
	CfrmTestListView::InstancePtr()->DoModal();
}
void CfrmMain::OnCmdTestControlArrays()
{
	// TODO: Add your control notification handler code here
	CfrmTestControlArrays::InstancePtr()->DoModal();
}
void CfrmMain::OnCmdTestAutoDim()
{
	// TODO: Add your control notification handler code here
	CfrmTestAutoDim::InstancePtr()->DoModal();
}

void CfrmMain::OnCmdTestInputBox()
{
	// TODO: Add your control notification handler code here
	CfrmTestInputBox::InstancePtr()->DoModal();
}
void CfrmMain::OnCmdTestPropertyGetLet()
{
	// TODO: Add your control notification handler code here
	CfrmTestPropertyGetLet::InstancePtr()->DoModal();
}
void CfrmMain::OnCmdTestPrinter()
{
	// TODO: Add your control notification handler code here
	CfrmTestPrinter::InstancePtr()->DoModal();
}
void CfrmMain::OnCmdTestTabStrip()
{
	// TODO: Add your control notification handler code here
	CfrmTestTabStrip::InstancePtr()->DoModal();
}
void CfrmMain::OnCmdTestNamedArgs()
{
	// TODO: Add your control notification handler code here
	CfrmTestNamedArgs::InstancePtr()->DoModal();
}
void CfrmMain::OnCmdTestFontProperty()
{
	// TODO: Add your control notification handler code here
	CfrmTestFontProperty::InstancePtr()->DoModal();
}
void CfrmMain::OnCmdTestPaint()
{
	// TODO: Add your control notification handler code here
	CfrmTestPaint::InstancePtr()->DoModal();
}
void CfrmMain::OnCmdTestStatusBar()
{
	// TODO: Add your control notification handler code here
	CfrmTestStatusBar::InstancePtr()->DoModal();
}
void CfrmMain::OnCmdTestTreeView()
{
	// TODO: Add your control notification handler code here
	CfrmTestTreeView::InstancePtr()->DoModal();
}
void CfrmMain::OnCmdTestDeclare()
{
	// TODO: Add your control notification handler code here
	CfrmTestDeclare::InstancePtr()->DoModal();
}
void CfrmMain::OnCmdTestExtConsts()
{
	// TODO: Add your control notification handler code here
	CfrmTestExtConsts::InstancePtr()->DoModal();
}
void CfrmMain::OnCmdTestDate()
{
	// TODO: Add your control notification handler code here
	CfrmTestDate::InstancePtr()->DoModal();
}
void CfrmMain::OnCmdTestFileSystemObject()
{
	// TODO: Add your control notification handler code here
	CfrmTestFileSystemObject::InstancePtr()->DoModal();
}

void CfrmMain::TimerNow_Timer()
{
	m_StatusBar1.SetText(COleDateTime(COleDateTime::GetCurrentTime()).Format(), 255, 0);
	m_StatusBar1.SetText(vbDateStr()+"   "+vbTimeStr(), 255, 0);
}


void CfrmMain::OnTimer(UINT nIDEvent)
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
HBRUSH CfrmMain::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch(pWnd->GetDlgCtrlID()) {
		case Label1:	return fm_Label1	.OnCtlColor(pDC);
	}
	return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}
