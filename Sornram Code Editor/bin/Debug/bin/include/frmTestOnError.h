// frmTestOnError.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestOnError)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CfrmTestOnError dialog
class CfrmTestOnError : public CDialog
{
// Construction
public:
	CfrmTestOnError(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestOnError *InstancePtr() {
		extern CfrmTestOnError *frmTestOnError;
		if (!frmTestOnError) frmTestOnError = new CfrmTestOnError();
		return frmTestOnError;
	}

// Dialog Data
	enum { IDD = IDDfrmTestOnError };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestOnError)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void SelchangeComboTest();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestOnError)
	CStatic	m_Label1;
	CStatic	m_LabelResult;
	CStatic	m_Label2;
	CSpinButtonCtrl	m_UpDownDenom;
	CEdit	m_TextDenom;
	CComboBox	m_ComboTest;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestOnError)

public:	
	VBtoFontAttribute fm_Label1, fm_LabelResult, fm_Label2;
	void Form_Load();
	void UpDownDenom_Change();
	void RunTest();
	void myAction();
	void myOnException(CString NameException);
	void TestRaise();
	void Test1();
	void Test2();
	//}}VBto_Converter_Class_Public

};

extern CfrmTestOnError *frmTestOnError;
