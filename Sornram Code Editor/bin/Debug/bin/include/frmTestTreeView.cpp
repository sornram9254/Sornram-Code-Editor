// frmTestTreeView.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestTreeView)
//}}VBto_Converter_Includes

#include "frmTestTreeView.h"
CfrmTestTreeView *frmTestTreeView = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestTreeView dialog



CfrmTestTreeView::CfrmTestTreeView(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestTreeView::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestTreeView) frmTestTreeView = this;
}

void CfrmTestTreeView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestTreeView)
	DDX_Control(pDX, Label8, m_Label8);
	DDX_Control(pDX, trv, m_trv);
	DDX_Control(pDX, UpDownIndex, m_UpDownIndex);
	DDX_Control(pDX, CmdSetText, m_CmdSetText);
	DDX_Control(pDX, CmdSetSelected, m_CmdSetSelected);
	DDX_Control(pDX, CmdRemove, m_CmdRemove);
	DDX_Control(pDX, TextIndex, m_TextIndex);
	DDX_Control(pDX, CmdAddChild, m_CmdAddChild);
	DDX_Control(pDX, CmdClear, m_CmdClear);
	DDX_Control(pDX, txtNodeText, m_txtNodeText);
	DDX_Control(pDX, CmdAddTo, m_CmdAddTo);
	DDX_Control(pDX, CheckCheckboxes, m_CheckCheckboxes);
	DDX_Control(pDX, Frame2, m_Frame2);
	DDX_Control(pDX, txtCurrentInfo, m_txtCurrentInfo);
	DDX_Control(pDX, CheckFullRowSelect, m_CheckFullRowSelect);
	DDX_Control(pDX, CheckHotTracking, m_CheckHotTracking);
	DDX_Control(pDX, CheckLabelEditAutomatic, m_CheckLabelEditAutomatic);
	DDX_Control(pDX, CheckSorted, m_CheckSorted);
	DDX_Control(pDX, CheckSingleSel, m_CheckSingleSel);
	DDX_Control(pDX, CheckHideSelection, m_CheckHideSelection);
	DDX_Control(pDX, CheckLineStyleRootLines, m_CheckLineStyleRootLines);
	DDX_Control(pDX, CheckEnabled, m_CheckEnabled);
	DDX_Control(pDX, CheckVisible, m_CheckVisible);
	DDX_Control(pDX, CmdSetSelText, m_CmdSetSelText);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestTreeView, CDialog)
	//{{AFX_MSG_MAP(CfrmTestTreeView)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(CheckCheckboxes, OnCheckCheckboxes)
	ON_BN_CLICKED(CheckFullRowSelect, OnCheckFullRowSelect)
	ON_BN_CLICKED(CheckHideSelection, OnCheckHideSelection)
	ON_BN_CLICKED(CheckHotTracking, OnCheckHotTracking)
	ON_BN_CLICKED(CheckLabelEditAutomatic, OnCheckLabelEditAutomatic)
	ON_BN_CLICKED(CheckLineStyleRootLines, OnCheckLineStyleRootLines)
	ON_BN_CLICKED(CheckSingleSel, OnCheckSingleSel)
	ON_BN_CLICKED(CheckSorted, OnCheckSorted)
	ON_BN_CLICKED(CheckEnabled, OnCheckEnabled)
	ON_BN_CLICKED(CheckVisible, OnCheckVisible)
	ON_BN_CLICKED(CmdSetSelText, OnCmdSetSelText)
	ON_BN_CLICKED(CmdSetText, OnCmdSetText)
	ON_BN_CLICKED(CmdSetSelected, OnCmdSetSelected)
	ON_BN_CLICKED(CmdAddTo, OnCmdAddTo)
	ON_BN_CLICKED(CmdAddChild, OnCmdAddChild)
	ON_BN_CLICKED(CmdRemove, OnCmdRemove)
	ON_BN_CLICKED(CmdClear, OnCmdClear)
	ON_NOTIFY(TVN_SELCHANGED, trv, Selchangedtrv)
	ON_NOTIFY(NM_CLICK, trv, Clicktrv)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestTreeView message handlers

BOOL CfrmTestTreeView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestTreeView)
	
	m_UpDownIndex	.SetBuddy(GetDlgItem(TextIndex));
	m_UpDownIndex	.SetRange(1, 5);
	m_UpDownIndex	.SetPos(5);
	
	m_TextIndex	.SetWindowText("5");	//from 'UpDownIndex'
	m_txtNodeText	.SetWindowText("Node Text");
	m_CheckEnabled	.SetCheck(BST_CHECKED);
	m_CheckVisible	.SetCheck(BST_CHECKED);
	{
	m_trvImages	.Create(16, 16, ILC_COLOR8|ILC_MASK, 10,5);
	CBitmap *pBmp = new CBitmap();
	COLORREF crMask = RGB(192,192,192);
	m_trvImages.Add(AfxGetApp()->LoadIcon(frmTestTreeView_trvImages_1));
	m_trvImages.Add(AfxGetApp()->LoadIcon(frmTestTreeView_trvImages_2));
	delete pBmp;
	}
	ind = 0;	b = 0;	
	
	Form_Load();
	m_trv.SetImageList(&m_trvImages, TVSIL_NORMAL);
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestTreeView::OnPaint() 
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
HCURSOR CfrmTestTreeView::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================
// This is a part of the VBto Converter (www.vbto.net)
// Copyright (C) 2005-2007 StressSoft Company Ltd. All rights reserved.




void CfrmTestTreeView::OnCheckCheckboxes()
{
	// TODO: Add your control notification handler code here

#if VBtoBuilder || VBtoDelphi
	// Borland: MSComctlLib.TreeView property trv.Checkboxes was not upgraded
	m_CheckCheckboxes.SetCheck(BST_UNCHECKED);
	m_CheckCheckboxes.EnableWindow(false);

#else
	vModifyStyle(m_trv, m_CheckCheckboxes.GetCheck()==BST_CHECKED, TVS_CHECKBOXES);

#endif
	OutCurrentInfo();
}

void CfrmTestTreeView::OnCheckFullRowSelect()
{
	// TODO: Add your control notification handler code here
	vModifyStyle(m_trv, m_CheckFullRowSelect.GetCheck()==BST_CHECKED, TVS_FULLROWSELECT);
	OutCurrentInfo();
}

void CfrmTestTreeView::OnCheckHideSelection()
{
	// TODO: Add your control notification handler code here
	vModifyStyle(m_trv, !m_CheckHideSelection.GetCheck()==BST_CHECKED, TVS_SHOWSELALWAYS);
	OutCurrentInfo();
}

void CfrmTestTreeView::OnCheckHotTracking()
{
	// TODO: Add your control notification handler code here
	vModifyStyle(m_trv, m_CheckHotTracking.GetCheck()==BST_CHECKED, TVS_TRACKSELECT);
	OutCurrentInfo();
}

void CfrmTestTreeView::OnCheckLabelEditAutomatic()
{
	// TODO: Add your control notification handler code here
	vModifyStyle(m_trv, !((m_CheckLabelEditAutomatic.GetCheck()==BST_CHECKED ? tvwAutomatic : tvwManual)), TVS_EDITLABELS); // 0 or 1
	OutCurrentInfo();
}

void CfrmTestTreeView::OnCheckLineStyleRootLines()
{
	// TODO: Add your control notification handler code here
	vModifyStyle(m_trv, (m_CheckLineStyleRootLines.GetCheck()==BST_CHECKED ? tvwRootLines : tvwTreeLines), TVS_HASLINES|TVS_LINESATROOT); // 1 or 0
	OutCurrentInfo();
}

void CfrmTestTreeView::OnCheckSingleSel()
{
	// TODO: Add your control notification handler code here

#if VBtoVBNET || VBtoCSNET || VBtoVCNET || VBtoJSNET || VBtoVCMFC
	// .NET: MSComctlLib.TreeView property trv.SingleSel was not upgraded. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="CC4C7EC0-C903-48FC-ACCC-81861D12DA4A"'
	m_CheckSingleSel.SetCheck(BST_UNCHECKED);
	m_CheckSingleSel.EnableWindow(false);

#else
	m_trv.SingleSel = m_CheckSingleSel.GetCheck()==BST_CHECKED;

#endif
	OutCurrentInfo();
}

void CfrmTestTreeView::OnCheckSorted()
{
	// TODO: Add your control notification handler code here

#if VBtoVCMFC
	// ... ... ...
	m_CheckSorted.SetCheck(BST_UNCHECKED);
	m_CheckSorted.EnableWindow(false);

#else
	m_trv.Sorted = m_CheckSorted.GetCheck()==BST_CHECKED;

#endif
	OutCurrentInfo();
}

void CfrmTestTreeView::OnCheckEnabled()
{
	// TODO: Add your control notification handler code here
	m_trv.EnableWindow(m_CheckEnabled.GetCheck()==BST_CHECKED);
	OutCurrentInfo();
}

void CfrmTestTreeView::OnCheckVisible()
{
	// TODO: Add your control notification handler code here
	m_trv.ShowWindow(m_CheckVisible.GetCheck()==BST_CHECKED ? SW_SHOW : SW_HIDE);
	OutCurrentInfo();
}

// ===========================================

void CfrmTestTreeView::OnCmdSetSelText()
{
	// TODO: Add your control notification handler code here
	if (VBtoTreeItem(m_trv,m_trv.GetSelectedItem())==NULL) return;
	m_txtCurrentInfo.SetWindowText("Previous     SelectedItem.Text = \""+m_trv.GetItemText(m_trv.GetSelectedItem())+"\"");
	m_trv.SetItemText(m_trv.GetSelectedItem(), ::GetWindowText(m_txtNodeText));
}

void CfrmTestTreeView::OnCmdSetText()
{
	// TODO: Add your control notification handler code here
	ind = m_UpDownIndex.GetPos32();
	if ((ind<1) || (ind>m_trv.GetCount())) {
		MessageBeep(-1);
		return;
	}
	m_txtCurrentInfo.SetWindowText("Previous     Nodes.Item("+Str(ind)+").Text = \""+VBtoTreeItem(m_trv,ind-1).GetText()+"\"");
	VBtoTreeItem(m_trv,ind-1).SetText(::GetWindowText(m_txtNodeText));
}

void CfrmTestTreeView::OnCmdSetSelected()
{
	// TODO: Add your control notification handler code here
	ind = m_UpDownIndex.GetPos32();
	if ((ind<1) || (ind>m_trv.GetCount())) {
		MessageBeep(-1);
		return;
	}
	if (VBtoTreeItem(m_trv,m_trv.GetSelectedItem())==NULL) {
		m_txtCurrentInfo.SetWindowText("Previous     SelectedItem Is Nothing");
	} else {
		m_txtCurrentInfo.SetWindowText("Previous     SelectedItem.Index = "+Str(VBtoTreeItem(m_trv,m_trv.GetSelectedItem()).GetIndex()+1));
	}
	VBtoTreeItem(m_trv,ind-1).SetSelected(true);
}

void CfrmTestTreeView::OnCmdAddTo()
{
	// TODO: Add your control notification handler code here
	m_trv.InsertItem(::GetWindowText(m_txtNodeText));
	OutCurrentInfo();
}

void CfrmTestTreeView::OnCmdAddChild()
{
	// TODO: Add your control notification handler code here
	if (VBtoTreeItem(m_trv,m_trv.GetSelectedItem())==NULL) return;
	ind = m_UpDownIndex.GetPos32();
	InsertItem(m_trv, VBtoTreeItem(m_trv,ind-1), tvwChild, "", ::GetWindowText(m_txtNodeText));
	if (!true) m_trv.SelectItem(NULL);
}

void CfrmTestTreeView::OnCmdRemove()
{
	// TODO: Add your control notification handler code here
	ind = m_UpDownIndex.GetPos32();
	if ((ind<1) || (ind>m_trv.GetCount())) {
		MessageBeep(-1);
		return;
	}
	m_trv.DeleteItem(GetItem(m_trv,ind-1));
	OutCurrentInfo();
}

void CfrmTestTreeView::OnCmdClear()
{
	// TODO: Add your control notification handler code here
	m_trv.DeleteAllItems();
	OutCurrentInfo();
}

// ===========================================
void CfrmTestTreeView::OutCurrentInfo()
{
	m_trv.UpdateWindow();
	SetMax(m_UpDownIndex, m_trv.GetCount());

	 CString cs; 
	cs = "Nodes.Count="+Str(m_trv.GetCount())+"\r\n";

	if (!(VBtoTreeItem(m_trv,m_trv.GetSelectedItem())==NULL)) {
		cs += CString("SelectedItem.Text=\"")+m_trv.GetItemText(m_trv.GetSelectedItem())+"\";";
		cs += CString("  Key=\"")+GetItemDataAsString(m_trv, m_trv.GetSelectedItem())+"\";";
		cs += CString("  Index=")+Str(VBtoTreeItem(m_trv,m_trv.GetSelectedItem()).GetIndex()+1)+";";
		cs += CString("  Children=")+Str(GetChildren(m_trv, m_trv.GetSelectedItem()))+";";

#if !(VBtoBuilder || VBtoDelphi)
		if (GetStyleFlags(m_trv,TVS_CHECKBOXES) && m_trv.GetCheck(m_trv.GetSelectedItem())) cs += "  Checked;";

#endif
		cs += CString("\r\n")+"FullPath=\""+GetFullPath(m_trv, m_trv.GetSelectedItem())+"\"";
	}
	cs += "\r\n";


#if !(VBtoBuilder || VBtoDelphi)
	if (GetStyleFlags(m_trv,TVS_CHECKBOXES)) cs += "Checkboxes; ";

#endif
	if (GetStyleFlags(m_trv,TVS_FULLROWSELECT)) cs += "FullRowSelect; ";
	if (!GetStyleFlags(m_trv,TVS_SHOWSELALWAYS)) cs += "HideSelection; ";
	if (GetStyleFlags(m_trv,TVS_TRACKSELECT)) cs += "HotTracking; ";
	if (!GetStyleFlags(m_trv, TVS_EDITLABELS)==tvwAutomatic) cs += "LabelEdit=tvwAutomatic; ";
	if ((GetStyleFlags(m_trv,TVS_LINESATROOT)?1:0)==tvwRootLines) cs += "LineStyle=tvwRootLines; ";

#if VB6 || VBtoBuilder || VBtoDelphi
	if (m_trv.SingleSel) cs += "SingleSel; ";

#endif

#if !VBtoVCMFC
	if (m_trv.Sorted)) cs += "Sorted; ";

#endif
	if (!m_trv.IsWindowEnabled()) cs += "Enabled=False; ";
	if (!m_trv.IsWindowVisible()) cs += "Visible=False; ";

	m_txtCurrentInfo.SetWindowText(cs);
}

void CfrmTestTreeView::Selchangedtrv(NMHDR* pNMHDR, LRESULT* pResult)
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	OutCurrentInfo();
	*pResult = 0;
}
void CfrmTestTreeView::trv_NodeCheck(VBtoTreeItem Node)
{
	OutCurrentInfo();
}
void CfrmTestTreeView::Clicktrv(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: Add your control notification handler code here
	OutCurrentInfo();
	*pResult = 0;
}

void CfrmTestTreeView::TestTranslationOnly(bool flRun)
{
	if (!flRun) return;

	ind = 1;
	 VBtoTreeItem trvNode; 
	trvNode = VBtoTreeItem(m_trv, m_trv.InsertItem(""));

	m_trv.InsertItem("");
	m_trv.InsertItem("Text");
	InsertItem(m_trv, "Key", "");
	InsertItem(m_trv, "Key", "Text");

	m_trv.InsertItem("", 1 - 1);
	m_trv.InsertItem("Text", 1 - 1);
	InsertItem(m_trv, "Key", "", 1 - 1);
	InsertItem(m_trv, "Key", "Text", 1 - 1);

	m_trv.InsertItem("", 1 - 1, 2 - 1);
	m_trv.InsertItem("Text", 1 - 1, 2 - 1);
	InsertItem(m_trv, "Key", "", 1 - 1, 2 - 1);
	InsertItem(m_trv, "Key", "Text", 1 - 1, 2 - 1);

	m_trv.InsertItem("", 2 - 1, 2 - 1);
	m_trv.InsertItem("Text", 2 - 1, 2 - 1);
	InsertItem(m_trv, "Key", "", 2 - 1, 2 - 1);
	InsertItem(m_trv, "Key", "Text", 2 - 1, 2 - 1);
	// -------------
	InsertItem(m_trv, trvNode, tvwNext, "", "");
	InsertItem(m_trv, trvNode, tvwNext, "", "Text");
	InsertItem(m_trv, trvNode, tvwNext, "Key", "");
	InsertItem(m_trv, trvNode, tvwNext, "Key", "Text");

	InsertItem(m_trv, trvNode, tvwNext, "", "", 1 - 1);
	InsertItem(m_trv, trvNode, tvwNext, "", "Text", 1 - 1);
	InsertItem(m_trv, trvNode, tvwNext, "Key", "", 1 - 1);
	InsertItem(m_trv, trvNode, tvwNext, "Key", "Text", 1 - 1);

	InsertItem(m_trv, trvNode, tvwNext, "", "", 1 - 1, 2 - 1);
	InsertItem(m_trv, trvNode, tvwNext, "Key", "", 1 - 1, 2 - 1);
	InsertItem(m_trv, trvNode, tvwNext, "", "Text", 1 - 1, 2 - 1);
	InsertItem(m_trv, trvNode, tvwNext, "Key", "Text", 1 - 1, 2 - 1);

	InsertItem(m_trv, trvNode, tvwNext, "", "", 2 - 1, 2 - 1);
	InsertItem(m_trv, trvNode, tvwNext, "Key", "", 2 - 1, 2 - 1);
	InsertItem(m_trv, trvNode, tvwNext, "", "Text", 2 - 1, 2 - 1);
	InsertItem(m_trv, trvNode, tvwNext, "Key", "Text", 2 - 1, 2 - 1);
	// -------------
	InsertItem(m_trv, "relKey", tvwNext, "", "");
	InsertItem(m_trv, "relKey", tvwNext, "Key", "");
	InsertItem(m_trv, "relKey", tvwNext, "", "Text");
	InsertItem(m_trv, "relKey", tvwNext, "Key", "Text");

	InsertItem(m_trv, "relKey", tvwNext, "", "", 1 - 1);
	InsertItem(m_trv, "relKey", tvwNext, "Key", "", 1 - 1);
	InsertItem(m_trv, "relKey", tvwNext, "", "Text", 1 - 1);
	InsertItem(m_trv, "relKey", tvwNext, "Key", "Text", 1 - 1);

	InsertItem(m_trv, "relKey", tvwNext, "", "", 1 - 1, 2 - 1);
	InsertItem(m_trv, "relKey", tvwNext, "Key", "", 1 - 1, 2 - 1);
	InsertItem(m_trv, "relKey", tvwNext, "", "Text", 1 - 1, 2 - 1);
	InsertItem(m_trv, "relKey", tvwNext, "Key", "Text", 1 - 1, 2 - 1);

	InsertItem(m_trv, "relKey", tvwNext, "", "", 2 - 1, 2 - 1);
	InsertItem(m_trv, "relKey", tvwNext, "Key", "", 2 - 1, 2 - 1);
	InsertItem(m_trv, "relKey", tvwNext, "", "Text", 2 - 1, 2 - 1);
	InsertItem(m_trv, "relKey", tvwNext, "Key", "Text", 2 - 1, 2 - 1);
	// -------------
	InsertItem(m_trv, trvNode, tvwFirst, "", "");
	InsertItem(m_trv, trvNode, tvwLast, "Key", "");
	InsertItem(m_trv, trvNode, tvwNext, "", "Text");
	InsertItem(m_trv, trvNode, tvwChild, "Key", "Text");

	InsertItem(m_trv, trvNode, tvwChild, "", "", 1 - 1);
	InsertItem(m_trv, trvNode, tvwChild, "Key", "", 1 - 1);
	InsertItem(m_trv, trvNode, tvwChild, "", "Text", 1 - 1);
	InsertItem(m_trv, trvNode, tvwChild, "Key", "Text", 1 - 1);

	InsertItem(m_trv, trvNode, tvwChild, "", "", 1 - 1, 2 - 1);
	InsertItem(m_trv, trvNode, tvwChild, "Key", "", 1 - 1, 2 - 1);
	InsertItem(m_trv, trvNode, tvwChild, "", "Text", 1 - 1, 2 - 1);
	InsertItem(m_trv, trvNode, tvwChild, "Key", "Text", 1 - 1, 2 - 1);

	InsertItem(m_trv, trvNode, tvwChild, "", "", 2 - 1, 2 - 1);
	InsertItem(m_trv, trvNode, tvwChild, "Key", "", 2 - 1, 2 - 1);
	InsertItem(m_trv, trvNode, tvwChild, "", "Text", 2 - 1, 2 - 1);
	InsertItem(m_trv, trvNode, tvwChild, "Key", "Text", 2 - 1, 2 - 1);
	// -------------
	InsertItem(m_trv, "relKey", tvwChild, "", "");
	InsertItem(m_trv, "relKey", tvwChild, "Key", "");
	InsertItem(m_trv, "relKey", tvwChild, "", "Text");
	InsertItem(m_trv, "relKey", tvwChild, "Key", "Text");

	InsertItem(m_trv, "relKey", tvwChild, "", "", 1 - 1);
	InsertItem(m_trv, "relKey", tvwChild, "Key", "", 1 - 1);
	InsertItem(m_trv, "relKey", tvwChild, "", "Text", 1 - 1);
	InsertItem(m_trv, "relKey", tvwChild, "Key", "Text", 1 - 1);

	InsertItem(m_trv, "relKey", tvwChild, "", "", 1 - 1, 2 - 1);
	InsertItem(m_trv, "relKey", tvwChild, "Key", "", 1 - 1, 2 - 1);
	InsertItem(m_trv, "relKey", tvwChild, "", "Text", 1 - 1, 2 - 1);
	InsertItem(m_trv, "relKey", tvwChild, "Key", "Text", 1 - 1, 2 - 1);

	InsertItem(m_trv, "relKey", tvwChild, "", "", 2 - 1, 2 - 1);
	InsertItem(m_trv, "relKey", tvwChild, "Key", "", 2 - 1, 2 - 1);
	InsertItem(m_trv, "relKey", tvwChild, "", "Text", 2 - 1, 2 - 1);
	InsertItem(m_trv, "relKey", tvwChild, "Key", "Text", 2 - 1, 2 - 1);

	// -------------
	b = trvNode.GetSelected();
	trvNode.SetSelected(b);
	trvNode.SetSelected(false);
	trvNode.SetSelected(true);

	b = true /*m_trv.SelectedItem.Selected*/;
	if (!b) m_trv.SelectItem(NULL);
	if (!false) m_trv.SelectItem(NULL);
	if (!true) m_trv.SelectItem(NULL);

	b = VBtoTreeItem(m_trv,ind-1).GetSelected();
	VBtoTreeItem(m_trv,ind-1).SetSelected(b);
	VBtoTreeItem(m_trv,ind-1).SetSelected(false);
	VBtoTreeItem(m_trv,ind-1).SetSelected(true);

	// -------------
	s = trvNode.GetKey();
	trvNode.SetKey(s);
	s = GetItemDataAsString(m_trv, m_trv.GetSelectedItem());
	SetItemData(m_trv, m_trv.GetSelectedItem(), s);
	s = VBtoTreeItem(m_trv,ind-1).GetKey();
	VBtoTreeItem(m_trv,ind-1).SetKey(s);
	// -------------
	s = trvNode.GetText();
	trvNode.SetText(s);
	s = m_trv.GetItemText(m_trv.GetSelectedItem());
	m_trv.SetItemText(m_trv.GetSelectedItem(), s);
	s = VBtoTreeItem(m_trv,ind-1).GetText();
	VBtoTreeItem(m_trv,ind-1).SetText(s);
	// -------------
	b = trvNode.GetExpanded();
	trvNode.SetExpanded(b);
	trvNode.SetExpanded(false);
	trvNode.SetExpanded(true);

	b = m_trv.GetItemState(m_trv.GetSelectedItem(),TVIS_EXPANDED)==TVIS_EXPANDED;
	if (!b) m_trv.SelectItem(NULL);
	if (!false) m_trv.SelectItem(NULL);
	if (!true) m_trv.SelectItem(NULL);

	b = VBtoTreeItem(m_trv,ind-1).GetExpanded();
	VBtoTreeItem(m_trv,ind-1).SetExpanded(b);
	VBtoTreeItem(m_trv,ind-1).SetExpanded(false);
	VBtoTreeItem(m_trv,ind-1).SetExpanded(true);
	// -------------
	s = trvNode.GetFullPath();
	s = GetFullPath(m_trv, m_trv.GetSelectedItem());
	s = VBtoTreeItem(m_trv,ind-1).GetFullPath();
	// -------------
	 short nn; 
	nn = trvNode.GetChildren();
	nn = GetChildren(m_trv, m_trv.GetSelectedItem());
	nn = VBtoTreeItem(m_trv,ind-1).GetChildren();
	// -------------
	nn = trvNode.GetIndex()+1;
	nn = VBtoTreeItem(m_trv,m_trv.GetSelectedItem()).GetIndex()+1;
	nn = VBtoTreeItem(m_trv,ind-1).GetIndex()+1;
	// -------------

#if !(VBtoBuilder || VBtoDelphi)
	b = trvNode.GetChecked();
	trvNode.SetChecked(b);
	b = m_trv.GetCheck(m_trv.GetSelectedItem());
	m_trv.SetCheck(m_trv.GetSelectedItem(), b);
	b = VBtoTreeItem(m_trv,ind-1).GetChecked();
	VBtoTreeItem(m_trv,ind-1).SetChecked(b);

#endif
	// -------------

#if VB6 || VBtoVBNET || VBtoVCMFC
	b = trvNode.GetBold();
	trvNode.SetBold(b);
	trvNode.SetBold(false);
	trvNode.SetBold(true);

	b = m_trv.GetItemState(m_trv.GetSelectedItem(),TVIS_BOLD)==TVIS_BOLD;
	m_trv.SetItemState(m_trv.GetSelectedItem(), TVIS_BOLD, b ? TVIS_BOLD : 0);
	m_trv.SetItemState(m_trv.GetSelectedItem(), TVIS_BOLD, false ? TVIS_BOLD : 0);
	m_trv.SetItemState(m_trv.GetSelectedItem(), TVIS_BOLD, true ? TVIS_BOLD : 0);

	b = VBtoTreeItem(m_trv,ind-1).GetBold();
	VBtoTreeItem(m_trv,ind-1).SetBold(b);
	VBtoTreeItem(m_trv,ind-1).SetBold(false);
	VBtoTreeItem(m_trv,ind-1).SetBold(true);

#endif

}

void CfrmTestTreeView::Form_Load()
{
	m_trv.InsertItem("Node1", 1 - 1, 2 - 1);
	InsertItem(m_trv, "K2", "Node2");

	 VBtoTreeItem trvNode; 
	trvNode = InsertItem(m_trv, "UnUseKey", "");
	trvNode.SetKey("Now");
	trvNode.SetText(COleDateTime(COleDateTime::GetCurrentTime()).Format());

	trvNode = InsertItem(m_trv, VBtoTreeItem(m_trv,2-1), tvwChild, "K21", "Node2 Child1");

	InsertItem(m_trv, "K21", tvwChild, "K211", "Node2 Child1 Child1");
	InsertItem(m_trv, "K211", tvwNext, "", "Node2 Child1 Child2");

	InsertItem(m_trv, VBtoTreeItem(m_trv,1-1), tvwNext, "NN", "Node under Node1");
	InsertItem(m_trv, "Now", tvwNext, "", "Node under Key \"Now\"");

	trvNode.SetSelected(true);
	trvNode.SetExpanded(true);

#if !(VBtoBuilder || VBtoDelphi)
	trvNode.EnsureVisible();

#endif

	InsertItem(m_trv, trvNode, tvwPrevious, "", "2 tvwPrevious");
	InsertItem(m_trv, trvNode, tvwFirst, "", "2 tvwFirst");
	InsertItem(m_trv, trvNode, tvwNext, "", "2 tvwNext");
	InsertItem(m_trv, trvNode, tvwLast, "", "2 tvwLast");
	InsertItem(m_trv, trvNode, tvwChild, "", "2 tvwChild");
	InsertItem(m_trv, VBtoTreeItem(m_trv,m_trv.GetSelectedItem()), tvwNext, "", "2 tvwNext (default)");


#if VB6 || VBtoVCMFC
	trvNode.SetBold(!trvNode.GetBold());

#endif

	VBtoTreeItem(m_trv,1-1).SetSelected(true);
	OutCurrentInfo();

	TestTranslationOnly(false);
}
