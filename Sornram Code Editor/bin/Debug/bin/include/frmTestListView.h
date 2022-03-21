// frmTestListView.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestListView)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CfrmTestListView dialog
class CfrmTestListView : public CDialog
{
// Construction
public:
	CfrmTestListView(CWnd* pParent = NULL);	// standard constructor

	inline void ShowModeless() {
		void ShowModeless(CDialog *pDlg, UINT nIDTemplate);
		ShowModeless(this, this->IDD);
	}
	inline void Show(int Modal) {
		if (Modal>0) DoModal();
		else ShowModeless();
	}
	inline INT_PTR DoModal() {
		if (m_hWnd) CDialog::DestroyWindow();
		return CDialog::DoModal();
	}
	static CfrmTestListView *InstancePtr() {
		extern CfrmTestListView *frmTestListView;
		if (!frmTestListView) frmTestListView = new CfrmTestListView();
		return frmTestListView;
	}

// Dialog Data
	enum { IDD = IDDfrmTestListView };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestListView)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOptionlvwIcon();
	afx_msg void OnOptionlvwList();
	afx_msg void OnOptionlvwReport();
	afx_msg void OnOptionlvwSmallIcon();
	afx_msg void OnCheckMultiSelect();
	afx_msg void OnCheckCheckboxes();
	afx_msg void OnCheckGridLines();
	afx_msg void OnCheckFullRowSelect();
	afx_msg void OnCheckHideSelection();
	afx_msg void OnCheckSorted();
	afx_msg void OnOptionlvwAscending();
	afx_msg void OnOptionlvwDescending();
	afx_msg void OnCmdGetInfo();
	afx_msg void OnCmdClear();
	afx_msg void OnCmdAddItem();
	afx_msg void OnCmdInsertItem();
	afx_msg void OnCmdDeleteItem();
	afx_msg void OnCmdGetItem();
	afx_msg void OnCmdSetCurItem();
	afx_msg void OnCmdCheckedItem();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestListView)
	CListCtrl	m_ListView1;
	CButton	m_CmdAddItem;
	CButton	m_FrameView;
	CButton	m_OptionlvwIcon;
	CButton	m_OptionlvwList;
	CButton	m_OptionlvwReport;
	CButton	m_OptionlvwSmallIcon;
	CButton	m_CheckMultiSelect;
	CButton	m_CheckCheckboxes;
	CButton	m_CheckGridLines;
	CButton	m_CheckFullRowSelect;
	CButton	m_CheckSorted;
	CButton	m_CheckHideSelection;
	CButton	m_FrameSortOrder;
	CButton	m_OptionlvwAscending;
	CButton	m_OptionlvwDescending;
	CButton	m_CmdInsertItem;
	CButton	m_CmdDeleteItem;
	CEdit	m_TextNewItem;
	CButton	m_CmdGetItem;
	CButton	m_CmdGetInfo;
	CButton	m_CmdSetCurItem;
	CButton	m_Frame1;
	CEdit	m_TextItemIndex;
	CSpinButtonCtrl	m_UpDownItemIndex;
	CButton	m_Frame2;
	CEdit	m_TextCurrentStyle;
	CButton	m_CmdClear;
	CButton	m_CmdCheckedItem;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestListView)

public:	
	void Form_Load();
	void AddToListView(CString itemName, CString itemInfo);
	void OutCurrentStyle();
	//}}VBto_Converter_Class_Public

};

extern CfrmTestListView *frmTestListView;
