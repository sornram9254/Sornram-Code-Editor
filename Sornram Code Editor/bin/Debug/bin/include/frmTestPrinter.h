// frmTestPrinter.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestPrinter)
#include "VBto_Converter.h"
#include "math.h"
//}}VBto_Converter_Class_Global


// CfrmTestPrinter dialog
class CfrmTestPrinter : public CDialog
{
// Construction
public:
	CfrmTestPrinter(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestPrinter *InstancePtr() {
		extern CfrmTestPrinter *frmTestPrinter;
		if (!frmTestPrinter) frmTestPrinter = new CfrmTestPrinter();
		return frmTestPrinter;
	}

// Dialog Data
	enum { IDD = IDDfrmTestPrinter };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestPrinter)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCheckBoxPageA();
	afx_msg void OnCheckBoxPageB();
	afx_msg void OncmdPrint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestPrinter)
	CStatic	m_Label3;
	CButton	m_cmdPrint;
	CButton	m_CheckBoxPageB;
	CButton	m_CheckBoxPageA;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestPrinter)

public:	
	VBtoFontAttribute fm_Label3;
	CString getFontInfo();
	void CheckBoxesClick();
	void PrintPageA();
	void PrintPageB();
	//}}VBto_Converter_Class_Public

};

extern CfrmTestPrinter *frmTestPrinter;
