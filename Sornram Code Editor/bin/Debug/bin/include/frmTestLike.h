// frmTestLike.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestLike)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CfrmTestLike dialog
class CfrmTestLike : public CDialog
{
// Construction
public:
	CfrmTestLike(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestLike *InstancePtr() {
		extern CfrmTestLike *frmTestLike;
		if (!frmTestLike) frmTestLike = new CfrmTestLike();
		return frmTestLike;
	}

// Dialog Data
	enum { IDD = IDDfrmTestLike };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestLike)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCmdTest();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestLike)
	CListBox	m_ListBoxResults;
	CButton	m_CmdTest;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestLike)

public:	
	void Form_Load();
	void AddResult(CString Test, bool Result, bool ResultOk);
	void TestLike();
	//}}VBto_Converter_Class_Public

};

extern CfrmTestLike *frmTestLike;
