// frmTestControlArrays.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestControlArrays)
//}}VBto_Converter_Includes

#include "frmTestControlArrays.h"
CfrmTestControlArrays *frmTestControlArrays = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestControlArrays dialog



CfrmTestControlArrays::CfrmTestControlArrays(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestControlArrays::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestControlArrays) frmTestControlArrays = this;
}

void CfrmTestControlArrays::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestControlArrays)
	DDX_Control(pDX, Frame1_0, m_Frame1_0);
	DDX_Control(pDX, Label1_0, m_Label1_0);
	DDX_Control(pDX, Image1_0, m_Image1_0);
	DDX_Control(pDX, Slider1_0, m_Slider1_0);
	DDX_Control(pDX, ProgressBar1_0, m_ProgressBar1_0);
	DDX_Control(pDX, Command1_0, m_Command1_0);
	DDX_Control(pDX, EdtText_0, m_EdtText_0);
	DDX_Control(pDX, Check1_0, m_Check1_0);
	DDX_Control(pDX, Picture1_0, m_Picture1_0);
	DDX_Control(pDX, HScroll1_0, m_HScroll1_0);
	DDX_Control(pDX, Frame1_3, m_Frame1_3);
	DDX_Control(pDX, Label1_3, m_Label1_3);
	DDX_Control(pDX, Image1_3, m_Image1_3);
	DDX_Control(pDX, Slider1_3, m_Slider1_3);
	DDX_Control(pDX, ProgressBar1_3, m_ProgressBar1_3);
	DDX_Control(pDX, Command1_3, m_Command1_3);
	DDX_Control(pDX, EdtText_3, m_EdtText_3);
	DDX_Control(pDX, Check1_3, m_Check1_3);
	DDX_Control(pDX, Picture1_3, m_Picture1_3);
	DDX_Control(pDX, HScroll1_3, m_HScroll1_3);
	DDX_Control(pDX, EdtEvents, m_EdtEvents);
	DDX_Control(pDX, Frame2, m_Frame2);
	DDX_Control(pDX, Option1_0, m_Option1_0);
	DDX_Control(pDX, Option1_1, m_Option1_1);
	DDX_Control(pDX, Option1_2, m_Option1_2);
	DDX_Control(pDX, Option1_3, m_Option1_3);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestControlArrays, CDialog)
	//{{AFX_MSG_MAP(CfrmTestControlArrays)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SHOWWINDOW()
	ON_WM_CLOSE()
	ON_COMMAND(pmIndexedItem_0, OnpmIndexedItem_0)
	ON_COMMAND(pmIndexedItem_2, OnpmIndexedItem_2)
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(Frame1_3, OnFrame1_3)
	ON_BN_CLICKED(Frame1_0, OnFrame1_0)
	ON_BN_CLICKED(Label1_3, OnLabel1_3)
	ON_BN_CLICKED(Label1_0, OnLabel1_0)
	ON_EN_CHANGE(EdtText_3, ChangeEdtText_3)
	ON_EN_CHANGE(EdtText_0, ChangeEdtText_0)
	ON_BN_CLICKED(Check1_3, OnCheck1_3)
	ON_BN_CLICKED(Check1_0, OnCheck1_0)
	ON_BN_CLICKED(Picture1_3, OnPicture1_3)
	ON_BN_CLICKED(Picture1_0, OnPicture1_0)
	ON_BN_CLICKED(Image1_3, OnImage1_3)
	ON_BN_CLICKED(Image1_0, OnImage1_0)
	ON_BN_CLICKED(Command1_3, OnCommand1_3)
	ON_BN_CLICKED(Command1_0, OnCommand1_0)
	ON_BN_CLICKED(Option1_3, OnOption1_3)
	ON_BN_CLICKED(Option1_2, OnOption1_2)
	ON_BN_CLICKED(Option1_1, OnOption1_1)
	ON_BN_CLICKED(Option1_0, OnOption1_0)
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestControlArrays message handlers

BOOL CfrmTestControlArrays::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestControlArrays)
	
	ZeroMemory(m_Option1, sizeof(m_Option1));
	m_Option1[3] = &m_Option1_3;
	m_Option1[2] = &m_Option1_2;
	m_Option1[1] = &m_Option1_1;
	m_Option1[0] = &m_Option1_0;
	
	ZeroMemory(m_Frame1, sizeof(m_Frame1));
	m_Frame1[3] = &m_Frame1_3;
	m_Frame1[0] = &m_Frame1_0;
	
	ZeroMemory(m_HScroll1, sizeof(m_HScroll1));
	m_HScroll1[3] = &m_HScroll1_3;
	m_HScroll1[0] = &m_HScroll1_0;
	
	ZeroMemory(m_Picture1, sizeof(m_Picture1));
	m_Picture1[3] = &m_Picture1_3;
	m_Picture1[0] = &m_Picture1_0;
	
	ZeroMemory(m_Check1, sizeof(m_Check1));
	m_Check1[3] = &m_Check1_3;
	m_Check1[0] = &m_Check1_0;
	
	ZeroMemory(m_EdtText, sizeof(m_EdtText));
	m_EdtText[3] = &m_EdtText_3;
	m_EdtText[0] = &m_EdtText_0;
	
	ZeroMemory(m_Command1, sizeof(m_Command1));
	m_Command1[3] = &m_Command1_3;
	m_Command1[0] = &m_Command1_0;
	
	ZeroMemory(m_ProgressBar1, sizeof(m_ProgressBar1));
	m_ProgressBar1[3] = &m_ProgressBar1_3;
	m_ProgressBar1[0] = &m_ProgressBar1_0;
	
	ZeroMemory(m_Slider1, sizeof(m_Slider1));
	m_Slider1[3] = &m_Slider1_3;
	m_Slider1[0] = &m_Slider1_0;
	
	ZeroMemory(m_Image1, sizeof(m_Image1));
	m_Image1[3] = &m_Image1_3;
	m_Image1[0] = &m_Image1_0;
	
	ZeroMemory(m_Label1, sizeof(m_Label1));
	m_Label1[3] = &m_Label1_3;
	m_Label1[0] = &m_Label1_0;
	m_Slider1_0	.SetRange(0, 10, true);
	m_ProgressBar1_0	.SetRange(0, 10);
	m_EdtText_0	.SetWindowText("000");
	{
	SCROLLINFO si;	si.cbSize=sizeof(SCROLLINFO);
	si.nMin=0;	si.nMax=10;
	si.fMask = SIF_RANGE;
	m_HScroll1_0.SetScrollInfo(&si);
	}
	m_Slider1_3	.SetRange(0, 100, true);
	m_Slider1_3	.SetTicFreq(20);
	
	m_ProgressBar1_3	.SetRange(0, 100);
	m_EdtText_3	.SetWindowText("333");
	{
	SCROLLINFO si;	si.cbSize=sizeof(SCROLLINFO);
	si.nMin=0;	si.nMax=100;
	si.fMask = SIF_RANGE;
	m_HScroll1_3.SetScrollInfo(&si);
	}
	iOGO = 0;
	
	Form_Load();
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestControlArrays::OnPaint() 
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
HCURSOR CfrmTestControlArrays::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================

// This is a part of the VBto Converter (www.vbto.net)
// Copyright (C) 2005-2007 StressSoft Company Ltd. All rights reserved.




void CfrmTestControlArrays::Form_Initialize()
{
	// Form_Initialize
}

void CfrmTestControlArrays::Form_Load()
{
	// Form_Load
}

void CfrmTestControlArrays::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialog::OnShowWindow(bShow, nStatus);

	// TODO: Add your message handler code here and/or call default
	// Form_Activate
}

void CfrmTestControlArrays::Form_Unload(short& Cancel)
{
	if (IDYES!=AfxMessageBox("Do you want to unload the form?",MB_ICONQUESTION+MB_YESNO)) Cancel = 1;
}

void CfrmTestControlArrays::OnClose()
{
	short Cancel = 0;

	Form_Unload(Cancel);
	if (!Cancel) CDialog::OnClose();	// OnOK();
}

void CfrmTestControlArrays::pmIndexedItem_(short Index)
{
	// TODO: Add your command handler code here
	if (Index==2) {
		PostMessage(WM_CLOSE,0,0);
	}
}
void CfrmTestControlArrays::OnpmIndexedItem_0()
{
	// TODO: Add your command handler code here
	pmIndexedItem_(0);
}
void CfrmTestControlArrays::OnpmIndexedItem_2()
{
	// TODO: Add your command handler code here
	pmIndexedItem_(2);
}

void CfrmTestControlArrays::OutInfo(CString obj, short Index, CString Ev)
{
	m_EdtEvents.SetWindowText("Control \""+obj+"["+FormatVB(Index)+"]\",  Event \""+Ev+"\"");
}

void CfrmTestControlArrays::OnMouseMove(UINT nFlags, CPoint point)
{
	LONG X = point.x;
	LONG Y = point.y;
	// TODO: Add your message handler code here and/or call default

	m_EdtEvents.SetWindowText("");
	CDialog::OnMouseMove(nFlags, point);
}

void CfrmTestControlArrays::Frame1_MouseMove(short Index, short& Button, short& Shift, float& X, float& Y)
{
	OutInfo("Frame", Index, "MouseMove");
}
void CfrmTestControlArrays::Frame1_(short Index)
{
	// TODO: Add your control notification handler code here
	OutInfo("Frame", Index, "Click");
}
void CfrmTestControlArrays::OnFrame1_3()
{
	// TODO: Add your control notification handler code here
	Frame1_(3);
}
void CfrmTestControlArrays::OnFrame1_0()
{
	// TODO: Add your control notification handler code here
	Frame1_(0);
}

void CfrmTestControlArrays::Label1_MouseMove(short Index, short& Button, short& Shift, float& X, float& Y)
{
	OutInfo("Label", Index, "MouseMove");
}
void CfrmTestControlArrays::Label1_(short Index)
{
	// TODO: Add your control notification handler code here
	OutInfo("Label", Index, "Click");
}
void CfrmTestControlArrays::OnLabel1_3()
{
	// TODO: Add your control notification handler code here
	Label1_(3);
}
void CfrmTestControlArrays::OnLabel1_0()
{
	// TODO: Add your control notification handler code here
	Label1_(0);
}

void CfrmTestControlArrays::EdtText_MouseMove(short Index, short& Button, short& Shift, float& X, float& Y)
{
	OutInfo("TextBox", Index, "MouseMove");
}
void CfrmTestControlArrays::EdtText_Click(short Index)
{
	OutInfo("TextBox", Index, "Click");
}
void CfrmTestControlArrays::EdtText_Change(short Index)
{
	// TODO: Add your control notification handler code here
	m_Label1[Index]->SetWindowText(::GetWindowText(m_EdtText[Index]));
	m_Label1[Index]->SetWindowText(::GetWindowText(m_EdtText[Index]));
	OutInfo("TextBox", Index, "Change");
}
void CfrmTestControlArrays::ChangeEdtText_3()
{
	// TODO: Add your control notification handler code here
	EdtText_Change(3);
}
void CfrmTestControlArrays::ChangeEdtText_0()
{
	// TODO: Add your control notification handler code here
	EdtText_Change(0);
}

void CfrmTestControlArrays::Slider1_MouseMove(short Index, short& Button, short& Shift, float& X, float& Y)
{
	OutInfo("Slider", Index, "MouseMove");
}
void CfrmTestControlArrays::Slider1_Change(short Index)
{

#if VB6 || VBtoVCMFC || VBtoBuilder || VBtoDelphi
	m_ProgressBar1[Index]->SetPos(m_Slider1[Index]->GetPos());

#else
	// Sorry (VBtoVBNET VBtoCSNET VBtoVCNET VBtoJSNET)

#endif
	OutInfo("Slider", Index, "Change");
}

void CfrmTestControlArrays::HScroll1_Change(short Index)
{
	m_ProgressBar1[Index]->SetPos(m_HScroll1[Index]->GetScrollPos());
	OutInfo("HScroll", Index, "Change");
}

void CfrmTestControlArrays::ProgressBar1_MouseMove(short Index, short& Button, short& Shift, float& X, float& Y)
{
	OutInfo("ProgressBar", Index, "MouseMove");
}
void CfrmTestControlArrays::ProgressBar1_MouseDown(short Index, short& Button, short& Shift, float& X, float& Y)
{
	OutInfo("ProgressBar", Index, "MouseDown");
}

void CfrmTestControlArrays::Check1_(short Index)
{
	// TODO: Add your control notification handler code here
	OutInfo("Check", Index, "Click");
}
void CfrmTestControlArrays::OnCheck1_3()
{
	// TODO: Add your control notification handler code here
	Check1_(3);
}
void CfrmTestControlArrays::OnCheck1_0()
{
	// TODO: Add your control notification handler code here
	Check1_(0);
}
void CfrmTestControlArrays::Picture1_DblClick(short Index)
{
	OutInfo("Check", Index, "DblClick");
}

void CfrmTestControlArrays::Picture1_MouseMove(short Index, short& Button, short& Shift, float& X, float& Y)
{
	OutInfo("Picture", Index, "MouseMove");
}
void CfrmTestControlArrays::Picture1_(short Index)
{
	// TODO: Add your control notification handler code here
	m_Check1[Index]->SetCheck((m_Check1[Index]->GetCheck()==BST_CHECKED ? BST_UNCHECKED : BST_CHECKED));
	OutInfo("Picture", Index, "Click");
}
void CfrmTestControlArrays::OnPicture1_3()
{
	// TODO: Add your control notification handler code here
	Picture1_(3);
}
void CfrmTestControlArrays::OnPicture1_0()
{
	// TODO: Add your control notification handler code here
	Picture1_(0);
}

void CfrmTestControlArrays::Image1_MouseMove(short Index, short& Button, short& Shift, float& X, float& Y)
{
	OutInfo("Image", Index, "MouseMove");
}
void CfrmTestControlArrays::Image1_(short Index)
{
	// TODO: Add your control notification handler code here
	m_Check1[Index]->SetCheck((m_Check1[Index]->GetCheck()==BST_CHECKED ? BST_UNCHECKED : BST_CHECKED));
	OutInfo("Image", Index, "Click");
}
void CfrmTestControlArrays::OnImage1_3()
{
	// TODO: Add your control notification handler code here
	Image1_(3);
}
void CfrmTestControlArrays::OnImage1_0()
{
	// TODO: Add your control notification handler code here
	Image1_(0);
}

void CfrmTestControlArrays::Command1_MouseMove(short Index, short& Button, short& Shift, float& X, float& Y)
{
	OutInfo("Command", Index, "MouseMove");
}
void CfrmTestControlArrays::Command1_(short Index)
{
	// TODO: Add your control notification handler code here
	m_EdtText[Index]->SetWindowText(::GetWindowText(m_EdtText[Index])+",");
	m_EdtText[Index]->SetWindowText(Str(::GetWindowText(m_EdtText[Index]))+".");
	OutInfo("Command", Index, "Click");
}
void CfrmTestControlArrays::OnCommand1_3()
{
	// TODO: Add your control notification handler code here
	Command1_(3);
}
void CfrmTestControlArrays::OnCommand1_0()
{
	// TODO: Add your control notification handler code here
	Command1_(0);
}

void CfrmTestControlArrays::Option1_MouseMove(short Index, short& Button, short& Shift, float& X, float& Y)
{
	OutInfo("Option", Index, "MouseMove");
}
void CfrmTestControlArrays::Option1_(short Index)
{
	// TODO: Add your control notification handler code here
	OutInfo("Option", Index, "Click");
}
void CfrmTestControlArrays::OnOption1_3()
{
	// TODO: Add your control notification handler code here
	Option1_(3);
}
void CfrmTestControlArrays::OnOption1_2()
{
	// TODO: Add your control notification handler code here
	Option1_(2);
}
void CfrmTestControlArrays::OnOption1_1()
{
	// TODO: Add your control notification handler code here
	Option1_(1);
}
void CfrmTestControlArrays::OnOption1_0()
{
	// TODO: Add your control notification handler code here
	Option1_(0);
}


void CfrmTestControlArrays::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: Add your message handler code here and/or call default

	short Button, Shift; float x, y;
	Button = Shift = 0;
	x = y = 0;

	switch(pScrollBar->GetDlgCtrlID())
	{
		case Slider1_3: {
			if (nSBCode==SB_ENDSCROLL) {
				Slider1_Change(3);
				break;
			}

			break;
		}

		case Slider1_0: {
			if (nSBCode==SB_ENDSCROLL) {
				Slider1_Change(0);
				break;
			}

			break;
		}

		case HScroll1_3: {
			if (nSBCode==SB_ENDSCROLL) {
				HScroll1_Change(3);
				break;
			}

			break;
		}

		case HScroll1_0: {
			if (nSBCode==SB_ENDSCROLL) {
				HScroll1_Change(0);
				break;
			}

			break;
		}

	}

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}