// frmTestEvents.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestEvents)
//}}VBto_Converter_Includes

#include "frmTestEvents.h"
CfrmTestEvents *frmTestEvents = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestEvents dialog



CfrmTestEvents::CfrmTestEvents(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestEvents::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestEvents) frmTestEvents = this;
}

void CfrmTestEvents::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestEvents)
	DDX_Control(pDX, Label1, m_Label1);
	DDX_Control(pDX, Label3, m_Label3);
	DDX_Control(pDX, Slider2, m_Slider2);
	DDX_Control(pDX, ListViewEvents, m_ListViewEvents);
	DDX_Control(pDX, Command1, m_Command1);
	DDX_Control(pDX, CommandClear, m_CommandClear);
	DDX_Control(pDX, Text1, m_Text1);
	DDX_Control(pDX, Slider1, m_Slider1);
	DDX_Control(pDX, HScroll1, m_HScroll1);
	DDX_Control(pDX, ListBoxEvents, m_ListBoxEvents);
	DDX_Control(pDX, HScroll2, m_HScroll2);
	DDX_Control(pDX, VScroll1, m_VScroll1);
	DDX_Control(pDX, Slider3, m_Slider3);
	DDX_Control(pDX, List1, m_List1);
	DDX_Control(pDX, Combo1, m_Combo1);
	DDX_Control(pDX, Picture1, m_Picture1);
	DDX_Control(pDX, ProgressBar1, m_ProgressBar1);
	DDX_Control(pDX, Frame1, m_Frame1);
	DDX_Control(pDX, UpDown1, m_UpDown1);
	DDX_Control(pDX, Option2, m_Option2);
	DDX_Control(pDX, Option1, m_Option1);
	DDX_Control(pDX, Check1, m_Check1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestEvents, CDialog)
	//{{AFX_MSG_MAP(CfrmTestEvents)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(Check1, OnCheck1)
	ON_BN_CLICKED(CommandClear, OnCommandClear)
	ON_BN_CLICKED(Command1, OnCommand1)
	ON_WM_SHOWWINDOW()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_SIZE()
	ON_BN_CLICKED(Frame1, OnFrame1)
	ON_BN_DOUBLECLICKED(Frame1, DoubleclickedFrame1)
	ON_BN_CLICKED(Label1, OnLabel1)
	ON_BN_CLICKED(Option1, OnOption1)
	ON_BN_CLICKED(Option2, OnOption2)
	ON_EN_CHANGE(Text1, ChangeText1)
	ON_EN_SETFOCUS(Text1, SetfocusText1)
	ON_EN_KILLFOCUS(Text1, KillfocusText1)
	ON_CBN_EDITCHANGE(Combo1, EditchangeCombo1)
	ON_CBN_SELCHANGE(Combo1, SelchangeCombo1)
	ON_LBN_SELCHANGE(List1, SelchangeList1)
	ON_BN_CLICKED(Picture1, OnPicture1)
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestEvents message handlers

BOOL CfrmTestEvents::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestEvents)
	m_Slider2	.SetRange(0, 10, true);
	m_ListViewEvents	.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_ListViewEvents	.InsertColumn(0, "N",	LVCFMT_LEFT,	24, -1);
	m_ListViewEvents	.InsertColumn(1, "Object:",	LVCFMT_LEFT,	97, -1);
	m_ListViewEvents	.InsertColumn(2, "Event:",	LVCFMT_LEFT,	134, -1);
	m_ListViewEvents	.InsertColumn(3, "Info:",	LVCFMT_LEFT,	134, -1);
	
	m_Text1	.SetWindowText("Text1");
	m_Slider1	.SetRange(0, 50, true);
	{
	SCROLLINFO si;	si.cbSize=sizeof(SCROLLINFO);
	si.nMin=0;	si.nMax=32767;
	si.fMask = SIF_RANGE;
	m_HScroll1.SetScrollInfo(&si);
	}
	{
	SCROLLINFO si;	si.cbSize=sizeof(SCROLLINFO);
	si.nMin=1000;	si.nMax=9000;
	si.nPos=3000;
	si.fMask = SIF_RANGE | SIF_POS;
	m_HScroll2.SetScrollInfo(&si);
	}
	{
	SCROLLINFO si;	si.cbSize=sizeof(SCROLLINFO);
	si.nMin=0;	si.nMax=1000;
	si.nPos=200;
	si.fMask = SIF_RANGE | SIF_POS;
	m_VScroll1.SetScrollInfo(&si);
	}
	m_Slider3	.SetRange(100, 1000, true);
	m_Slider3	.SetTicFreq(75);
	m_Slider3	.SetPos(300);
	
	m_List1	.AddString("ListBox Item 1");
	m_List1	.AddString("ListBox Item 2");
	m_List1	.AddString("ListBox Item 3");
	
	m_Combo1	.SetWindowText("ComboBox.  Click Me !!!");
	m_Combo1	.AddString("ComboBox Item 1");
	m_Combo1	.AddString("ComboBox Item 2");
	m_Combo1	.AddString("ComboBox Item 3");
	
	m_ProgressBar1	.SetRange(0, 100);
	m_UpDown1	.SetRange(20, 30);
	m_UpDown1	.SetPos(25);
	
	
	fm_Picture1.Set(GetDlgItem(Picture1), GetSysColor(COLOR_WINDOWTEXT), RGB(0,0,255));
	
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestEvents::OnPaint() 
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
HCURSOR CfrmTestEvents::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================

// VBto upgrade warning: AddInfo As CString	OnWrite(CString, TextBox)
void CfrmTestEvents::AddEventToList(CString nameObj, CString EventStr, CString AddInfo)
{
	if ((int)m_ListBoxEvents.m_hWnd==NULL) return;

	 CString S; 
	S = "Object: "+nameObj+"      Event: "+EventStr;
	if (AddInfo!="") {
		S += CString("      AddInfo: ")+AddInfo;
	}
	m_ListBoxEvents.AddString(S);
	m_ListBoxEvents.SetCurSel(m_ListBoxEvents.GetCount()-1);
	// ListBoxEvents.Selected(ListBoxEvents.ListCount - 1) = True

	// Dim itm As ListItem
	// Dim nE As Integer
	// nE = ListViewEvents.ListItems.Count + 1
	// Set itm = ListViewEvents.ListItems.Add
	// itm.Text = Format(nE)
	// itm.SubItems(1) = nameObj
	// itm.SubItems(2) = EventStr
	// itm.SubItems(3) = AddInfo
	// itm.Selected = True
	// itm.EnsureVisible
}

void CfrmTestEvents::OnCheck1()
{
	// TODO: Add your control notification handler code here
	 CString State; 
	State = "?";
	if (m_Check1.GetCheck()==BST_CHECKED) State = "Checked";
	if (m_Check1.GetCheck()==BST_CHECKED) {
		State = "Checked";
	}
	if (m_Check1.GetCheck()==BST_UNCHECKED) State = "Unchecked";
	AddEventToList("Check1", "Click", "State: "+State);
}

void CfrmTestEvents::OnCommandClear()
{
	// TODO: Add your control notification handler code here
	m_ListBoxEvents.ResetContent();
	// ListViewEvents.ListItems.Clear
}

void CfrmTestEvents::OnCommand1()
{
	// TODO: Add your control notification handler code here
	AddEventToList("Command1", "Click");
}

void CfrmTestEvents::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialog::OnShowWindow(bShow, nStatus);

	// TODO: Add your message handler code here and/or call default
	m_Slider1.SetRangeMin(1);
	m_Slider1.SetRangeMax(51);
	SetRangeMin(m_HScroll1, 100);
	SetRangeMax(m_HScroll1, 31000);
	SetRangeMin(m_ProgressBar1, 0);
	SetRangeMax(m_ProgressBar1, 300);

	m_Slider1.SetPos(20);
	m_Slider2.SetPos(7);
	m_Slider3.SetPos(800);
	m_VScroll1.SetScrollPos(200);
	m_HScroll1.SetScrollPos(27000);
	m_HScroll2.SetScrollPos(3000);
	m_ProgressBar1.SetPos(0);
}

void CfrmTestEvents::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	AddEventToList("Form", "Click");
	CDialog::OnLButtonUp(nFlags, point);
}

void CfrmTestEvents::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	AddEventToList("Form", "DblClick");
	CDialog::OnLButtonDblClk(nFlags, point);
}

void CfrmTestEvents::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here and/or call default

	AddEventToList("Form", "Resize");
}

void CfrmTestEvents::OnFrame1()
{
	// TODO: Add your control notification handler code here
	AddEventToList("Frame1", "Click");
}
void CfrmTestEvents::DoubleclickedFrame1()
{
	// TODO: Add your control notification handler code here
	AddEventToList("Frame1", "DblClick");
}
void CfrmTestEvents::Frame1_MouseDown(short& Button, short& Shift, float& x, float& y)
{
	AddEventToList("Frame1", "MouseDown");
}
void CfrmTestEvents::Frame1_MouseMove(short& Button, short& Shift, float& x, float& y)
{
	// AddEventToList "Frame1", "MouseMove"
}
void CfrmTestEvents::Frame1_MouseUp(short& Button, short& Shift, float& x, float& y)
{
	AddEventToList("Frame1", "MouseUp");
}

void CfrmTestEvents::OnLabel1()
{
	// TODO: Add your control notification handler code here
	AddEventToList("Label1", "Click", ::GetWindowText(m_Label1));
}

void CfrmTestEvents::OnOption1()
{
	// TODO: Add your control notification handler code here
	 CString State; 
	State = "Unchecked";
	if (m_Option1.GetCheck()) State = "Checked";
	AddEventToList("Option1", "Click", "State: "+State);
}
void CfrmTestEvents::OnOption2()
{
	// TODO: Add your control notification handler code here
	 CString State; 
	State = "Checked";
	if (!m_Option2.GetCheck()) State = "Unchecked";
	AddEventToList("Option2", "Click", "State: "+State);
}

void CfrmTestEvents::ChangeText1()
{
	// TODO: Add your control notification handler code here
	AddEventToList("Text1", "Change");
}
void CfrmTestEvents::SetfocusText1()
{
	// TODO: Add your control notification handler code here
	AddEventToList("Text1", "GotFocus", ::GetWindowText(m_Text1));
}
void CfrmTestEvents::KillfocusText1()
{
	// TODO: Add your control notification handler code here
	AddEventToList("Text1", "LostFocus", ::GetWindowText(m_Text1));
}

void CfrmTestEvents::UpDown1_Change()
{
	 float pos; 
	pos = m_UpDown1.GetPos32();
	AddEventToList("UpDown1", "Change", "Value: "+FormatVB(pos));
}

void CfrmTestEvents::Slider1_Click()
{
	ProgressBarSetValue(m_Slider1.GetRangeMin(), m_Slider1.GetRangeMax(), m_Slider1.GetPos());
	// VBto upgrade warning: pos As short	OnWrite(int)
	 short pos; 
	pos = m_Slider1.GetPos();
	AddEventToList("Slider1", "Click", "Position: "+Str(pos));
}
void CfrmTestEvents::Slider2_Click()
{
	ProgressBarSetValue(m_Slider2.GetRangeMin(), m_Slider2.GetRangeMax(), m_Slider2.GetPos());
	// VBto upgrade warning: pos As short	OnWrite(int)
	 short pos; 
	pos = m_Slider2.GetPos();
	AddEventToList("Slider2", "Click", "Position: "+Str(pos));
}
void CfrmTestEvents::Slider3_Click()
{
	ProgressBarSetValue(m_Slider3.GetRangeMin(), m_Slider3.GetRangeMax(), m_Slider3.GetPos());
	// VBto upgrade warning: pos As short	OnWrite(int)
	 short pos; 
	pos = m_Slider3.GetPos();
	AddEventToList("Slider3", "Click", "Position: "+Str(pos));
}

void CfrmTestEvents::VScroll1_Change()
{
	ProgressBarSetValue(GetRangeMin(m_VScroll1), GetRangeMax(m_VScroll1), m_VScroll1.GetScrollPos());
	// VBto upgrade warning: pos As short	OnWrite(int)
	 short pos; 
	pos = m_VScroll1.GetScrollPos();
	AddEventToList("VScroll1", "Change", "Position: "+Str(pos));
}
void CfrmTestEvents::HScroll1_Change()
{
	ProgressBarSetValue(GetRangeMin(m_HScroll1), GetRangeMax(m_HScroll1), m_HScroll1.GetScrollPos());
	// VBto upgrade warning: pos As short	OnWrite(int)
	 short pos; 
	pos = m_HScroll1.GetScrollPos();
	AddEventToList("HScroll1", "Change", "Position: "+Str(pos));
}
void CfrmTestEvents::HScroll2_Change()
{
	ProgressBarSetValue(GetRangeMin(m_HScroll2), GetRangeMax(m_HScroll2), m_HScroll2.GetScrollPos());
	// VBto upgrade warning: pos As short	OnWrite(int)
	 short pos; 
	pos = m_HScroll2.GetScrollPos();
	AddEventToList("HScroll2", "Change", "Position: "+Str(pos));
}

void CfrmTestEvents::ProgressBarSetValue(int Min, int Max, int Val)
{
	// VBto upgrade warning: pos As short	OnWrite(float)
	 float ValSingle,  z; short pos; 
	ValSingle = (float)(Val);
	z = (ValSingle-Min)/(Max-Min);
	pos = Round(GetRangeMin(m_ProgressBar1)+z*(GetRangeMax(m_ProgressBar1)-GetRangeMin(m_ProgressBar1)));
	m_ProgressBar1.SetPos(pos);
}
void CfrmTestEvents::ProgressBar1_Click()
{
	AddEventToList("ProgressBar1", "Click");
}
void CfrmTestEvents::ProgressBar1_MouseDown(short& Button, short& Shift, float& x, float& y)
{
	AddEventToList("ProgressBar1", "MouseDown");
}
void CfrmTestEvents::ProgressBar1_MouseMove(short& Button, short& Shift, float& x, float& y)
{
	// AddEventToList "ProgressBar1", "MouseMove"
}
void CfrmTestEvents::ProgressBar1_MouseUp(short& Button, short& Shift, float& x, float& y)
{
	AddEventToList("ProgressBar1", "MouseUp");
}

void CfrmTestEvents::EditchangeCombo1()
{
	// TODO: Add your message handler code here and/or call default
	AddEventToList("Combo1", "Change");
}
void CfrmTestEvents::SelchangeCombo1()
{
	// TODO: Add your control notification handler code here
	AddEventToList("Combo1", "Click");
}

void CfrmTestEvents::SelchangeList1()
{
	// TODO: Add your control notification handler code here
	AddEventToList("List1", "Click");
}

void CfrmTestEvents::OnPicture1()
{
	// TODO: Add your control notification handler code here
	AddEventToList("Picture1", "Click");
}
void CfrmTestEvents::Picture1_MouseMove(short& Button, short& Shift, float& x, float& y)
{
	AddEventToList("Picture1", "MouseMove");
}


void CfrmTestEvents::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: Add your message handler code here and/or call default

	short Button, Shift; float x, y;
	Button = Shift = 0;
	x = y = 0;

	switch(pScrollBar->GetDlgCtrlID())
	{
		case Slider1: {
			if (nSBCode==SB_ENDSCROLL) {
				Slider1_Click();
				break;
			}

			break;
		}

		case Slider2: {
			if (nSBCode==SB_ENDSCROLL) {
				Slider2_Click();
				break;
			}

			break;
		}

		case HScroll1: {
			if (nSBCode==SB_ENDSCROLL) {
				HScroll1_Change();
				break;
			}

			break;
		}

		case HScroll2: {
			if (nSBCode==SB_ENDSCROLL) {
				HScroll2_Change();
				break;
			}

			break;
		}

	}

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CfrmTestEvents::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: Add your message handler code here and/or call default

	short Button, Shift; float x, y;
	Button = Shift = 0;
	x = y = 0;

	switch(pScrollBar->GetDlgCtrlID())
	{
		case UpDown1: {
			if (nSBCode==SB_ENDSCROLL) {
				UpDown1_Change();
				break;
			}

			break;
		}

		case Slider3: {
			if (nSBCode==SB_ENDSCROLL) {
				Slider3_Click();
				break;
			}

			break;
		}

		case VScroll1: {
			if (nSBCode==SB_ENDSCROLL) {
				VScroll1_Change();
				break;
			}

			break;
		}

	}

	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}
HBRUSH CfrmTestEvents::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch(pWnd->GetDlgCtrlID()) {
		case Picture1:	return fm_Picture1	.OnCtlColor(pDC);
	}
	return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}
