// frmTestTreeView.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestTreeView)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CfrmTestTreeView dialog
class CfrmTestTreeView : public CDialog
{
// Construction
public:
	CfrmTestTreeView(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestTreeView *InstancePtr() {
		extern CfrmTestTreeView *frmTestTreeView;
		if (!frmTestTreeView) frmTestTreeView = new CfrmTestTreeView();
		return frmTestTreeView;
	}

// Dialog Data
	enum { IDD = IDDfrmTestTreeView };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestTreeView)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCheckCheckboxes();
	afx_msg void OnCheckFullRowSelect();
	afx_msg void OnCheckHideSelection();
	afx_msg void OnCheckHotTracking();
	afx_msg void OnCheckLabelEditAutomatic();
	afx_msg void OnCheckLineStyleRootLines();
	afx_msg void OnCheckSingleSel();
	afx_msg void OnCheckSorted();
	afx_msg void OnCheckEnabled();
	afx_msg void OnCheckVisible();
	afx_msg void OnCmdSetSelText();
	afx_msg void OnCmdSetText();
	afx_msg void OnCmdSetSelected();
	afx_msg void OnCmdAddTo();
	afx_msg void OnCmdAddChild();
	afx_msg void OnCmdRemove();
	afx_msg void OnCmdClear();
	afx_msg void Selchangedtrv(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void Clicktrv(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestTreeView)
	CStatic	m_Label8;
	CTreeCtrl	m_trv;
	CSpinButtonCtrl	m_UpDownIndex;
	CButton	m_CmdSetText;
	CButton	m_CmdSetSelected;
	CButton	m_CmdRemove;
	CEdit	m_TextIndex;
	CButton	m_CmdAddChild;
	CButton	m_CmdClear;
	CEdit	m_txtNodeText;
	CButton	m_CmdAddTo;
	CButton	m_CheckCheckboxes;
	CButton	m_Frame2;
	CEdit	m_txtCurrentInfo;
	CButton	m_CheckFullRowSelect;
	CButton	m_CheckHotTracking;
	CButton	m_CheckLabelEditAutomatic;
	CButton	m_CheckSorted;
	CButton	m_CheckSingleSel;
	CButton	m_CheckHideSelection;
	CButton	m_CheckLineStyleRootLines;
	CButton	m_CheckEnabled;
	CButton	m_CheckVisible;
	CButton	m_CmdSetSelText;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestTreeView)

public:	CImageList	m_trvImages;
	
	short ind; bool b; CString s;
	
	void OutCurrentInfo();
	void trv_NodeCheck(VBtoTreeItem Node);
	void TestTranslationOnly(bool flRun);
	void Form_Load();
	//}}VBto_Converter_Class_Public

};

extern CfrmTestTreeView *frmTestTreeView;
