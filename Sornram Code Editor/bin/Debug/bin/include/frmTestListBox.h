// frmTestListBox.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestListBox)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CfrmTestListBox dialog
class CfrmTestListBox : public CDialog
{
// Construction
public:
	CfrmTestListBox(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestListBox *InstancePtr() {
		extern CfrmTestListBox *frmTestListBox;
		if (!frmTestListBox) frmTestListBox = new CfrmTestListBox();
		return frmTestListBox;
	}

// Dialog Data
	enum { IDD = IDDfrmTestListBox };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestListBox)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCmdGetInfoLB();
	afx_msg void OnCmdGetInfoCB();
	afx_msg void OnCmdAddToLB();
	afx_msg void OnCmdAddToCB();
	afx_msg void OnCmdInsertToLB();
	afx_msg void OnCmdInsertToCB();
	afx_msg void OnCmdRemoveFromLB();
	afx_msg void OnCmdRemoveFromCB();
	afx_msg void OnCmdSetStringLB();
	afx_msg void OnCmdSetStringCB();
	afx_msg void OnCmdGetStringFromLB();
	afx_msg void OnCmdGetStringFromCB();
	afx_msg void OnCmdSetListIndexLB();
	afx_msg void OnCmdSetListIndexCB();
	afx_msg void OnCmdClearLB();
	afx_msg void OnCmdClearCB();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestListBox)
	CStatic	m_Label2;
	CStatic	m_Label3;
	CListBox	m_LB;
	CComboBox	m_CB;
	CButton	m_CmdAddToLB;
	CButton	m_CmdAddToCB;
	CEdit	m_TextAdd;
	CButton	m_CmdClearLB;
	CButton	m_CmdClearCB;
	CButton	m_CmdInsertToCB;
	CButton	m_CmdInsertToLB;
	CEdit	m_TextIndex;
	CSpinButtonCtrl	m_UpDownIndex;
	CButton	m_CmdRemoveFromCB;
	CButton	m_CmdRemoveFromLB;
	CButton	m_CmdGetStringFromCB;
	CButton	m_CmdGetStringFromLB;
	CButton	m_CmdGetInfoCB;
	CButton	m_CmdGetInfoLB;
	CButton	m_CmdSetListIndexLB;
	CButton	m_CmdSetListIndexCB;
	CButton	m_CmdSetStringLB;
	CButton	m_CmdSetStringCB;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestListBox)

public:	
	short ind;
	
	void Form_Load();
	//}}VBto_Converter_Class_Public

};

extern CfrmTestListBox *frmTestListBox;
