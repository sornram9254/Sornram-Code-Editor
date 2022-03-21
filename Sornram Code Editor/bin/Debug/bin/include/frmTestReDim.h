// frmTestReDim.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestReDim)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CfrmTestReDim dialog
class CfrmTestReDim : public CDialog
{
// Construction
public:
	CfrmTestReDim(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestReDim *InstancePtr() {
		extern CfrmTestReDim *frmTestReDim;
		if (!frmTestReDim) frmTestReDim = new CfrmTestReDim();
		return frmTestReDim;
	}

// Dialog Data
	enum { IDD = IDDfrmTestReDim };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestReDim)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCommandRunTest();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestReDim)
	CStatic	m_Label3;
	CButton	m_CommandRunTest;
	CListBox	m_ListBoxEvents;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestReDim)

public:	
	void Form_Load();
	void AddEventToList(bool flError, CString TestName, CString AddInfo="");
	void TestReDim();
	void QQ1(CString p1, CString p2, CString p3, CVBtoArrayPtr <CString> &m1, CVBtoArrayPtr <CString> &m2);
	void QQ2(CString& p1, CString& p2, CString p3, CVBtoArrayPtr <CString> &m1, CVBtoArrayPtr <CString> &m2);
	//}}VBto_Converter_Class_Public

};

extern CfrmTestReDim *frmTestReDim;
