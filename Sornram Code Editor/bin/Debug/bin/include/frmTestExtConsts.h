// frmTestExtConsts.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestExtConsts)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CfrmTestExtConsts dialog
class CfrmTestExtConsts : public CDialog
{
// Construction
public:
	CfrmTestExtConsts(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestExtConsts *InstancePtr() {
		extern CfrmTestExtConsts *frmTestExtConsts;
		if (!frmTestExtConsts) frmTestExtConsts = new CfrmTestExtConsts();
		return frmTestExtConsts;
	}

// Dialog Data
	enum { IDD = IDDfrmTestExtConsts };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestExtConsts)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOptAll();
	afx_msg void OnOptWarningOnly();
	afx_msg void OnCmdRunTest();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestExtConsts)
	CStatic	m_Label1;
	CListBox	m_ListBoxMsg;
	CButton	m_CmdRunTest;
	CButton	m_Frame1;
	CButton	m_OptAll;
	CButton	m_OptWarningOnly;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestExtConsts)

public:	CFileDialog	*m_CommonDialog1;
	
	bool flOutWarningOnly;
	 int nWarn;
	
	void Form_Load();
	void CmdRunTest_Click();
	void VerifyConst(CString cName, int iCorrectValue, CComVariant vCurrentValue);
	void RunTest();
	//}}VBto_Converter_Class_Public

};

extern CfrmTestExtConsts *frmTestExtConsts;
