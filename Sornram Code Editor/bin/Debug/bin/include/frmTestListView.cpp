// frmTestListView.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestListView)
//}}VBto_Converter_Includes

#include "frmTestListView.h"
CfrmTestListView *frmTestListView = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestListView dialog



CfrmTestListView::CfrmTestListView(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestListView::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestListView) frmTestListView = this;
}

void CfrmTestListView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestListView)
	DDX_Control(pDX, ListView1, m_ListView1);
	DDX_Control(pDX, CmdAddItem, m_CmdAddItem);
	DDX_Control(pDX, FrameView, m_FrameView);
	DDX_Control(pDX, OptionlvwIcon, m_OptionlvwIcon);
	DDX_Control(pDX, OptionlvwList, m_OptionlvwList);
	DDX_Control(pDX, OptionlvwReport, m_OptionlvwReport);
	DDX_Control(pDX, OptionlvwSmallIcon, m_OptionlvwSmallIcon);
	DDX_Control(pDX, CheckMultiSelect, m_CheckMultiSelect);
	DDX_Control(pDX, CheckCheckboxes, m_CheckCheckboxes);
	DDX_Control(pDX, CheckGridLines, m_CheckGridLines);
	DDX_Control(pDX, CheckFullRowSelect, m_CheckFullRowSelect);
	DDX_Control(pDX, CheckSorted, m_CheckSorted);
	DDX_Control(pDX, CheckHideSelection, m_CheckHideSelection);
	DDX_Control(pDX, FrameSortOrder, m_FrameSortOrder);
	DDX_Control(pDX, OptionlvwAscending, m_OptionlvwAscending);
	DDX_Control(pDX, OptionlvwDescending, m_OptionlvwDescending);
	DDX_Control(pDX, CmdInsertItem, m_CmdInsertItem);
	DDX_Control(pDX, CmdDeleteItem, m_CmdDeleteItem);
	DDX_Control(pDX, TextNewItem, m_TextNewItem);
	DDX_Control(pDX, CmdGetItem, m_CmdGetItem);
	DDX_Control(pDX, CmdGetInfo, m_CmdGetInfo);
	DDX_Control(pDX, CmdSetCurItem, m_CmdSetCurItem);
	DDX_Control(pDX, Frame1, m_Frame1);
	DDX_Control(pDX, TextItemIndex, m_TextItemIndex);
	DDX_Control(pDX, UpDownItemIndex, m_UpDownItemIndex);
	DDX_Control(pDX, Frame2, m_Frame2);
	DDX_Control(pDX, TextCurrentStyle, m_TextCurrentStyle);
	DDX_Control(pDX, CmdClear, m_CmdClear);
	DDX_Control(pDX, CmdCheckedItem, m_CmdCheckedItem);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestListView, CDialog)
	//{{AFX_MSG_MAP(CfrmTestListView)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(OptionlvwIcon, OnOptionlvwIcon)
	ON_BN_CLICKED(OptionlvwList, OnOptionlvwList)
	ON_BN_CLICKED(OptionlvwReport, OnOptionlvwReport)
	ON_BN_CLICKED(OptionlvwSmallIcon, OnOptionlvwSmallIcon)
	ON_BN_CLICKED(CheckMultiSelect, OnCheckMultiSelect)
	ON_BN_CLICKED(CheckCheckboxes, OnCheckCheckboxes)
	ON_BN_CLICKED(CheckGridLines, OnCheckGridLines)
	ON_BN_CLICKED(CheckFullRowSelect, OnCheckFullRowSelect)
	ON_BN_CLICKED(CheckHideSelection, OnCheckHideSelection)
	ON_BN_CLICKED(CheckSorted, OnCheckSorted)
	ON_BN_CLICKED(OptionlvwAscending, OnOptionlvwAscending)
	ON_BN_CLICKED(OptionlvwDescending, OnOptionlvwDescending)
	ON_BN_CLICKED(CmdGetInfo, OnCmdGetInfo)
	ON_BN_CLICKED(CmdClear, OnCmdClear)
	ON_BN_CLICKED(CmdAddItem, OnCmdAddItem)
	ON_BN_CLICKED(CmdInsertItem, OnCmdInsertItem)
	ON_BN_CLICKED(CmdDeleteItem, OnCmdDeleteItem)
	ON_BN_CLICKED(CmdGetItem, OnCmdGetItem)
	ON_BN_CLICKED(CmdSetCurItem, OnCmdSetCurItem)
	ON_BN_CLICKED(CmdCheckedItem, OnCmdCheckedItem)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestListView message handlers

BOOL CfrmTestListView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestListView)
	m_ListView1	.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_ListView1	.InsertColumn(0, "Object:",	LVCFMT_LEFT,	97, -1);
	m_ListView1	.InsertColumn(1, "AddInfo:",	LVCFMT_LEFT,	109, -1);
	m_ListView1	.InsertColumn(2, "AddInfo2:",	LVCFMT_LEFT,	73, -1);
	
	m_OptionlvwReport	.SetCheck(BST_CHECKED);
	m_CheckGridLines	.SetCheck(BST_CHECKED);
	m_CheckFullRowSelect	.SetCheck(BST_CHECKED);
	m_OptionlvwAscending	.SetCheck(BST_CHECKED);
	m_TextNewItem	.SetWindowText("New Item");
	m_TextItemIndex	.SetWindowText("3");	//from 'UpDownItemIndex'
	m_UpDownItemIndex	.SetBuddy(GetDlgItem(TextItemIndex));
	m_UpDownItemIndex	.SetRange(1, 7);
	m_UpDownItemIndex	.SetPos(3);
	
	
	Form_Load();
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestListView::OnPaint() 
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
HCURSOR CfrmTestListView::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================
// This is a part of the VBto Converter (www.vbto.net)
// Copyright (C) 2005-2006 StressSoft Company Ltd. All rights reserved.


void CfrmTestListView::Form_Load()
{
	AddToListView("Item1", "SubItems(1)");
	AddToListView("Item2", "SubItems(1)");
	AddToListView("Item3", "SubItems(1)");
	AddToListView("Item4", "SubItems(1)");
	OutCurrentStyle();
}

void CfrmTestListView::OnOptionlvwIcon()
{
	// TODO: Add your control notification handler code here
	SetViewStyle(m_ListView1, LVS_ICON);
	OutCurrentStyle();
}
void CfrmTestListView::OnOptionlvwList()
{
	// TODO: Add your control notification handler code here
	SetViewStyle(m_ListView1, LVS_LIST);
	OutCurrentStyle();
}
void CfrmTestListView::OnOptionlvwReport()
{
	// TODO: Add your control notification handler code here
	SetViewStyle(m_ListView1, LVS_REPORT);
	OutCurrentStyle();
}
void CfrmTestListView::OnOptionlvwSmallIcon()
{
	// TODO: Add your control notification handler code here
	SetViewStyle(m_ListView1, LVS_SMALLICON);
	OutCurrentStyle();
}

void CfrmTestListView::OnCheckMultiSelect()
{
	// TODO: Add your control notification handler code here
	mModifyStyle(m_ListView1, LVS_SINGLESEL, !(m_CheckMultiSelect.GetCheck()==BST_CHECKED));
	OutCurrentStyle();
}
void CfrmTestListView::OnCheckCheckboxes()
{
	// TODO: Add your control notification handler code here
	ListView_SetExtendedListViewStyleEx(m_ListView1, LVS_EX_CHECKBOXES, m_CheckCheckboxes.GetCheck()==BST_CHECKED ? LVS_EX_CHECKBOXES : 0);
	OutCurrentStyle();
}
void CfrmTestListView::OnCheckGridLines()
{
	// TODO: Add your control notification handler code here
	ListView_SetExtendedListViewStyleEx(m_ListView1, LVS_EX_GRIDLINES, m_CheckGridLines.GetCheck()==BST_CHECKED ? LVS_EX_GRIDLINES : 0);
	OutCurrentStyle();
}
void CfrmTestListView::OnCheckFullRowSelect()
{
	// TODO: Add your control notification handler code here
	ListView_SetExtendedListViewStyleEx(m_ListView1, LVS_EX_FULLROWSELECT, m_CheckFullRowSelect.GetCheck()==BST_CHECKED ? LVS_EX_FULLROWSELECT : 0);
	OutCurrentStyle();
}
void CfrmTestListView::OnCheckHideSelection()
{
	// TODO: Add your control notification handler code here
	mModifyStyle(m_ListView1, LVS_SHOWSELALWAYS, !(m_CheckHideSelection.GetCheck()==BST_CHECKED));
	OutCurrentStyle();
}
void CfrmTestListView::OnCheckSorted()
{
	// TODO: Add your control notification handler code here
	m_CheckSorted.GetCheck()==BST_CHECKED ? m_ListView1.ModifyStyle(LVS_SORTDESCENDING,LVS_SORTASCENDING) : m_ListView1.ModifyStyle(LVS_SORTASCENDING|LVS_SORTDESCENDING,0);
	if ((m_ListView1.GetStyle()&(LVS_SORTASCENDING|LVS_SORTDESCENDING))) {
		if (m_OptionlvwAscending.GetCheck()) SetSortOrder(m_ListView1, LVS_SORTASCENDING);
		if (m_OptionlvwDescending.GetCheck()) SetSortOrder(m_ListView1, LVS_SORTDESCENDING);
	}
	OutCurrentStyle();
}
void CfrmTestListView::OnOptionlvwAscending()
{
	// TODO: Add your control notification handler code here
	SetSortOrder(m_ListView1, LVS_SORTASCENDING);
	OutCurrentStyle();
}
void CfrmTestListView::OnOptionlvwDescending()
{
	// TODO: Add your control notification handler code here
	SetSortOrder(m_ListView1, LVS_SORTDESCENDING);
	OutCurrentStyle();
}

// ==================================================
void CfrmTestListView::OnCmdGetInfo()
{
	// TODO: Add your control notification handler code here
	 CString S; 
	S = "ListItems.Count: "+Str(m_ListView1.GetItemCount());
	if (!(GetVBtoSelectedItem(m_ListView1)==NULL)) {
		S += CString("\r\n")+"ListIndex: "+FormatVB(GetVBtoSelectedItem(m_ListView1).GetIndex());
	}
	AfxMessageBox(S);
}

void CfrmTestListView::AddToListView(CString itemName, CString itemInfo)
{
	 VBtoListViewItem itm; 
	itm = GetVBtoListViewItem(m_ListView1, m_ListView1.InsertItem(m_ListView1.GetItemCount(),""));
	itm.SetText(itemName);
	itm.SetSubItemText(1, itemInfo);
	itm.SetSubItemText(2, "SubItems(2)");
	itm.SetSelected(true);
	itm.EnsureVisible();
}

void CfrmTestListView::OnCmdClear()
{
	// TODO: Add your control notification handler code here
	m_ListView1.DeleteAllItems();
}

void CfrmTestListView::OnCmdAddItem()
{
	// TODO: Add your control notification handler code here
	AddToListView(::GetWindowText(m_TextNewItem), "add (Count="+Str(m_ListView1.GetItemCount())+")");
}

void CfrmTestListView::OnCmdInsertItem()
{
	// TODO: Add your control notification handler code here
	 short ii; 
	ii = m_UpDownItemIndex.GetPos32();
	if ((ii>=1) && (ii<=(m_ListView1.GetItemCount()+1))) {
		 VBtoListViewItem itm; 
		itm = GetVBtoListViewItem(m_ListView1, m_ListView1.InsertItem(ii-1, ::GetWindowText(m_TextNewItem)));
		itm.SetSubItemText(1, " - // - // - // - // - // -");
		itm.SetSubItemText(2, " ");
		itm = GetVBtoListViewItem(m_ListView1, m_ListView1.InsertItem(ii-1,""));
		itm.SetText(::GetWindowText(m_TextNewItem));
		itm.SetSubItemText(1, "insert (Index="+Str(ii)+")");
		itm.SetSubItemText(2, "S2");
		itm.SetSelected(true);
		itm.EnsureVisible();
	} else {
		MessageBeep(-1);
	}
}

void CfrmTestListView::OnCmdDeleteItem()
{
	// TODO: Add your control notification handler code here
	 short ii; 
	ii = m_UpDownItemIndex.GetPos32();
	if ((ii>=1) && (ii<=m_ListView1.GetItemCount())) {
		m_ListView1.DeleteItem(ii-1);
	} else {
		MessageBeep(-1);
	}
}

void CfrmTestListView::OnCmdGetItem()
{
	// TODO: Add your control notification handler code here
	 short ii; 
	ii = m_UpDownItemIndex.GetPos32();
	if ((ii<1) || (ii>m_ListView1.GetItemCount())) {
		MessageBeep(-1);
		return;
	}
	 VBtoListViewItem itm; 
	itm = GetVBtoListViewItem(m_ListView1, ii-1);
	 CString Mes; 
	Mes = "Text  =  \""+itm.GetText()+"\"";
	Mes += CString("\r\n")+"SubItems(1) =   \""+Str(itm.GetSubItemText(1))+"\"";
	Mes += CString("\r\n")+"SubItems(2) =   \""+Str(GetVBtoListViewItem(m_ListView1, ii-1).GetSubItemText(2))+"\"";
	::MessageBox(NULL, Mes,GetVBtoListViewItem(m_ListView1, ii-1).GetText(),MB_ICONINFORMATION);
}

void CfrmTestListView::OnCmdSetCurItem()
{
	// TODO: Add your control notification handler code here
	 short ii; 
	ii = m_UpDownItemIndex.GetPos32();
	if ((ii<1) || (ii>m_ListView1.GetItemCount())) {
		MessageBeep(-1);
		return;
	}
	 VBtoListViewItem itm; 
	itm = GetVBtoListViewItem(m_ListView1, ii-1);
	itm.SetSelected(true);
	GetVBtoListViewItem(m_ListView1, ii-1).SetSelected(true);
}

void CfrmTestListView::OnCmdCheckedItem()
{
	// TODO: Add your control notification handler code here
	 short ii; 
	ii = m_UpDownItemIndex.GetPos32();
	if ((ii<1) || (ii>m_ListView1.GetItemCount())) {
		MessageBeep(-1);
		return;
	}
	 VBtoListViewItem itm; 
	itm = GetVBtoListViewItem(m_ListView1, ii-1);
	itm.SetCheck(!itm.GetCheck());
}

void CfrmTestListView::OutCurrentStyle()
{
	 CString cs; 

	if (GetViewStyle(m_ListView1)==LVS_ICON) cs += "lvwIcon";
	if (GetViewStyle(m_ListView1)==LVS_LIST) cs += "lvwList";
	if (GetViewStyle(m_ListView1)==LVS_REPORT) cs += "lvwReport";
	if (GetViewStyle(m_ListView1)==LVS_SMALLICON) cs += "lvwSmallIcon";

	if (!(m_ListView1.GetStyle()&LVS_SINGLESEL)) cs += "  MultiSelect";
	if ((m_ListView1.GetExtendedStyle()&LVS_EX_CHECKBOXES)) cs += "  Checkboxes";
	if ((m_ListView1.GetExtendedStyle()&LVS_EX_GRIDLINES)) cs += "  GridLines";
	if ((m_ListView1.GetExtendedStyle()&LVS_EX_FULLROWSELECT)) cs += "  FullRowSelect";
	if (!(m_ListView1.GetStyle()&LVS_SHOWSELALWAYS)) cs += "  HideSelection";

	if ((m_ListView1.GetStyle()&(LVS_SORTASCENDING|LVS_SORTDESCENDING))) {
		cs += "  Sorted";
		if ((m_ListView1.GetStyle()&(LVS_SORTASCENDING|LVS_SORTDESCENDING))==LVS_SORTASCENDING) {
			cs += "/lvwAscending";
		} else {
			if ((m_ListView1.GetStyle()&(LVS_SORTASCENDING|LVS_SORTDESCENDING))==LVS_SORTDESCENDING) cs += "/lvwDescending";
		}
	}

	m_TextCurrentStyle.SetWindowText(cs);
	m_TextCurrentStyle.SetWindowText(cs);

}
