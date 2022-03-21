// frmTestExpression.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestExpression)
#include "VBto_Converter.h"
#include "mdlCommonVars.h"
#include "math.h"
//}}VBto_Converter_Class_Global


// CfrmTestExpression dialog
class CfrmTestExpression : public CDialog
{
// Construction
public:
	CfrmTestExpression(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestExpression *InstancePtr() {
		extern CfrmTestExpression *frmTestExpression;
		if (!frmTestExpression) frmTestExpression = new CfrmTestExpression();
		return frmTestExpression;
	}

// Dialog Data
	enum { IDD = IDDfrmTestExpression };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestExpression)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCmdTest();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestExpression)
	CButton	m_CmdTest;
	CListBox	m_ListBoxResults;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestExpression)

public:	
	void Form_Load();
	void RunAllTest();
	void TestMod();
	void TestPow();
	void TestBoolean();
	void TestBitwise();
	void TestConversionToC();
	void VerifyBooleanValues(CString TestName, bool pB, bool vB);
	void VerifyIntValues(CString TestName, short pI, short vI);
	void VerifyStrValues(CString TestName, CString ps, CString vS);
	//}}VBto_Converter_Class_Public

};

extern CfrmTestExpression *frmTestExpression;
