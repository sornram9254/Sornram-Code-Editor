// frmTestDoWhile.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestDoWhile)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CfrmTestDoWhile dialog
class CfrmTestDoWhile : public CDialog
{
// Construction
public:
	CfrmTestDoWhile(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestDoWhile *InstancePtr() {
		extern CfrmTestDoWhile *frmTestDoWhile;
		if (!frmTestDoWhile) frmTestDoWhile = new CfrmTestDoWhile();
		return frmTestDoWhile;
	}

// Dialog Data
	enum { IDD = IDDfrmTestDoWhile };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestDoWhile)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCmdRunAllTest();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestDoWhile)
	CStatic	m_Label1;
	CListBox	m_ListBoxResults;
	CButton	m_CmdRunAllTest;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestDoWhile)

public:	
	void AddResult(CString Test, int Result, int ResultOk);
	void RunAllTests();
	void Form_Load();
	//}}VBto_Converter_Class_Public

};

extern CfrmTestDoWhile *frmTestDoWhile;
