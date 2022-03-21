// frmTestTabStrip.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestTabStrip)
//}}VBto_Converter_Includes

#include "frmTestTabStrip.h"
CfrmTestTabStrip *frmTestTabStrip = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestTabStrip dialog



CfrmTestTabStrip::CfrmTestTabStrip(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestTabStrip::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestTabStrip) frmTestTabStrip = this;
}

void CfrmTestTabStrip::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestTabStrip)
	DDX_Control(pDX, Label4, m_Label4);
	DDX_Control(pDX, TabStrip1, m_TabStrip1);
	DDX_Control(pDX, Frame1, m_Frame1);
	DDX_Control(pDX, LabelIndex, m_LabelIndex);
	DDX_Control(pDX, LabelCount, m_LabelCount);
	DDX_Control(pDX, LabelCaption, m_LabelCaption);
	DDX_Control(pDX, LabelTag, m_LabelTag);
	DDX_Control(pDX, LabelDefault, m_LabelDefault);
	DDX_Control(pDX, Frame2, m_Frame2);
	DDX_Control(pDX, Label1, m_Label1);
	DDX_Control(pDX, Label2, m_Label2);
	DDX_Control(pDX, txtAddCaption, m_txtAddCaption);
	DDX_Control(pDX, CmdAdd3, m_CmdAdd3);
	DDX_Control(pDX, CmdAdd2, m_CmdAdd2);
	DDX_Control(pDX, CmdAdd1, m_CmdAdd1);
	DDX_Control(pDX, txtAddIndex, m_txtAddIndex);
	DDX_Control(pDX, Frame3, m_Frame3);
	DDX_Control(pDX, Label3, m_Label3);
	DDX_Control(pDX, CmdClear, m_CmdClear);
	DDX_Control(pDX, CmdRemove, m_CmdRemove);
	DDX_Control(pDX, txtRemoveIndex, m_txtRemoveIndex);
	DDX_Control(pDX, Frame4, m_Frame4);
	DDX_Control(pDX, CmdNewSelectedItemIndex, m_CmdNewSelectedItemIndex);
	DDX_Control(pDX, txtNewSelectedItemIndex, m_txtNewSelectedItemIndex);
	DDX_Control(pDX, CmdNewSelectedItemCaption, m_CmdNewSelectedItemCaption);
	DDX_Control(pDX, txtNewSelectedItemCaption, m_txtNewSelectedItemCaption);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestTabStrip, CDialog)
	//{{AFX_MSG_MAP(CfrmTestTabStrip)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(CmdAdd1, OnCmdAdd1)
	ON_BN_CLICKED(CmdAdd2, OnCmdAdd2)
	ON_BN_CLICKED(CmdAdd3, OnCmdAdd3)
	ON_BN_CLICKED(CmdRemove, OnCmdRemove)
	ON_BN_CLICKED(CmdClear, OnCmdClear)
	ON_BN_CLICKED(CmdNewSelectedItemCaption, OnCmdNewSelectedItemCaption)
	ON_BN_CLICKED(CmdNewSelectedItemIndex, OnCmdNewSelectedItemIndex)
	ON_NOTIFY(TCN_SELCHANGING, TabStrip1, SelchangingTabStrip1)
	ON_NOTIFY(TCN_SELCHANGE, TabStrip1, SelchangeTabStrip1)
	ON_NOTIFY(TCN_KEYDOWN, TabStrip1, KeydownTabStrip1)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestTabStrip message handlers

BOOL CfrmTestTabStrip::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestTabStrip)
	m_TabStrip1.InsertItem(0, "Caption1");	SetItemParam(m_TabStrip1, 0, new CComVariant("101"));
	m_TabStrip1.InsertItem(1, "Caption2");	SetItemParam(m_TabStrip1, 1, new CComVariant("10.2"));
	
	m_txtAddCaption	.SetWindowText("new Caption");
	m_txtAddIndex	.SetWindowText("2");
	m_txtRemoveIndex	.SetWindowText("2");
	m_txtNewSelectedItemIndex	.SetWindowText("1");
	m_txtNewSelectedItemCaption	.SetWindowText("myCaption");
	m_frmTestTabStrip_SSTab1.AddPage(&m_frmTestTabStrip_SSTab1_Page1);
	m_frmTestTabStrip_SSTab1.AddPage(&m_frmTestTabStrip_SSTab1_Page2);
	m_frmTestTabStrip_SSTab1.AddPage(&m_frmTestTabStrip_SSTab1_Page3);
	
	m_frmTestTabStrip_SSTab1.Create(this, WS_CHILD|WS_VISIBLE|WS_TABSTOP, WS_EX_CONTROLPARENT);
	CRect RectSSTab1;
	GetDlgItem(frmTestTabStrip_SSTab1)->GetWindowRect(&RectSSTab1);
	ScreenToClient(&RectSSTab1);
	m_frmTestTabStrip_SSTab1.SetWindowPos(NULL, RectSSTab1.left-6,RectSSTab1.top-7, 0,0, SWP_NOZORDER|SWP_NOSIZE|SWP_NOACTIVATE);
	m_frmTestTabStrip_SSTab1.SetActivePage(&m_frmTestTabStrip_SSTab1_Page3);
	
	
	fm_Label4.Set(GetDlgItem(Label4), RGB(0,0,255), GetSysColor(COLOR_BTNFACE));
	
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestTabStrip::OnPaint() 
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
HCURSOR CfrmTestTabStrip::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================

void CfrmTestTabStrip::ShowState()
{
	m_LabelCount.SetWindowText("Tabs.Count = "+Str(m_TabStrip1.GetItemCount()));

	m_LabelIndex.SetWindowText("");
	m_LabelCaption.SetWindowText("");
	m_LabelDefault.SetWindowText("");
	m_LabelTag.SetWindowText("");

	if (m_TabStrip1.GetItemCount()<=0) return;

	 short ii; 
	ii = m_TabStrip1.GetCurSel()+1;
	m_LabelIndex.SetWindowText("SelectedItem.Index = "+Str(ii)+" (one based)");

	if (ii<=0) return;

	if ((ii %  2)==1) {
		m_LabelCaption.SetWindowText("SelectedItem.Caption = \""+GetSelectedItemText(m_TabStrip1)+"\"");
		m_LabelDefault.SetWindowText("SelectedItem.Default = \""+Str(GetSelectedItemText(m_TabStrip1))+"\"");
		m_LabelTag.SetWindowText("SelectedItem.Tag = \""+Str(Str(GetSelectedItemParam(m_TabStrip1)))+"\"");
	} else {
		m_LabelCaption.SetWindowText("Item("+Str(ii)+").Caption = \""+GetItemText(m_TabStrip1, ii-1)+"\"");
		m_LabelDefault.SetWindowText("Item("+Str(ii)+").Default = \""+GetItemText(m_TabStrip1, ii-1)+"\"");
		m_LabelTag.SetWindowText("Item("+Str(ii)+").Tag = \""+Str(GetItemParam(m_TabStrip1, ii-1))+"\"");
	}

	SetSelectedItemParam(m_TabStrip1, new CComVariant(Str(GetItemParam(m_TabStrip1, ii-1)))); // - the same

}

void CfrmTestTabStrip::OnCmdAdd1()
{
	// TODO: Add your control notification handler code here
	m_TabStrip1.InsertItem(m_TabStrip1.GetItemCount(), "");
	SetItemParam(m_TabStrip1, m_TabStrip1.GetItemCount()-1, new CComVariant(ToString(1000+m_TabStrip1.GetItemCount())));
	ShowState();
}
void CfrmTestTabStrip::OnCmdAdd2()
{
	// TODO: Add your control notification handler code here
	m_TabStrip1.InsertItem(m_TabStrip1.GetItemCount(), ::GetWindowText(m_txtAddCaption));
	SetItemParam(m_TabStrip1, m_TabStrip1.GetItemCount()-1, new CComVariant(ToString(2000+m_TabStrip1.GetItemCount())));
	ShowState();
}
void CfrmTestTabStrip::OnCmdAdd3()
{
	// TODO: Add your control notification handler code here
	 short ind; 
	ind = CInt(::GetWindowText(m_txtAddIndex));
	m_TabStrip1.InsertItem(ind - 1, ::GetWindowText(m_txtAddCaption));
	SetItemParam(m_TabStrip1, ind-1, new CComVariant(ToString(3000+ind)));
	ShowState();
}

void CfrmTestTabStrip::OnCmdRemove()
{
	// TODO: Add your control notification handler code here
	m_TabStrip1.DeleteItem(CInt(::GetWindowText(m_txtRemoveIndex)) - 1);
	ShowState();
}
void CfrmTestTabStrip::OnCmdClear()
{
	// TODO: Add your control notification handler code here
	m_TabStrip1.DeleteAllItems();
	m_txtAddIndex.SetWindowText("1");
	ShowState();
}

void CfrmTestTabStrip::OnCmdNewSelectedItemCaption()
{
	// TODO: Add your control notification handler code here
	 CString s; 
	s = ::GetWindowText(m_txtNewSelectedItemCaption);
	SetSelectedItemText(m_TabStrip1, s);
	SetSelectedItemText(m_TabStrip1, s);
	SetItemText(m_TabStrip1, m_TabStrip1.GetCurSel()+1-1, s);
	SetItemText(m_TabStrip1, m_TabStrip1.GetCurSel()+1-1, s);
	ShowState();
}
void CfrmTestTabStrip::OnCmdNewSelectedItemIndex()
{
	// TODO: Add your control notification handler code here
	 short ii; 
	ii = CInt(::GetWindowText(m_txtNewSelectedItemIndex));
	 bool b; 
	b = !m_TabStrip1.GetCurSel()==(ii-1);
	m_TabStrip1.SetCurSel(b ? ii-1 : -1);
	m_TabStrip1.SetCurSel(false ? ii-1 : -1);
	m_TabStrip1.SetCurSel(true ? ii-1 : -1);
	ShowState();
}

void CfrmTestTabStrip::SelchangingTabStrip1(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: Add your control notification handler code here
	// TabStrip1_BeforeClick
	*pResult = 0;
}
void CfrmTestTabStrip::SelchangeTabStrip1(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: Add your control notification handler code here
	ShowState();
	*pResult = 0;
}
// 
void CfrmTestTabStrip::TabStrip1_GotFocus()
{
	// TabStrip1_GotFocus
}

void CfrmTestTabStrip::TabStrip1_KeyDown(short& KeyCode, short& Shift)
{
	// TabStrip1_KeyDown
}
void CfrmTestTabStrip::TabStrip1_KeyUp(short& KeyCode, short& Shift)
{
	// TabStrip1_KeyUp
}
void CfrmTestTabStrip::KeydownTabStrip1(NMHDR* pNMHDR, LRESULT* pResult)
{
	TC_KEYDOWN* pTCKeyDown = (TC_KEYDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	// TabStrip1_KeyPress
	*pResult = 0;
}

void CfrmTestTabStrip::TabStrip1_LostFocus()
{
	// TabStrip1_LostFocus
}

void CfrmTestTabStrip::TabStrip1_MouseDown(short& Button, short& Shift, float& x, float& y)
{
	// TabStrip1_MouseDown
}
void CfrmTestTabStrip::TabStrip1_MouseUp(short& Button, short& Shift, float& x, float& y)
{
	// TabStrip1_MouseUp
}
void CfrmTestTabStrip::TabStrip1_MouseMove(short& Button, short& Shift, float& x, float& y)
{
	// TabStrip1_MouseMove
}


HBRUSH CfrmTestTabStrip::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch(pWnd->GetDlgCtrlID()) {
		case Label4:	return fm_Label4	.OnCtlColor(pDC);
	}
	return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}
