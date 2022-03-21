// frmTestNamedArgs.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestNamedArgs)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CfrmTestNamedArgs dialog
class CfrmTestNamedArgs : public CDialog
{
// Construction
public:
	CfrmTestNamedArgs(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestNamedArgs *InstancePtr() {
		extern CfrmTestNamedArgs *frmTestNamedArgs;
		if (!frmTestNamedArgs) frmTestNamedArgs = new CfrmTestNamedArgs();
		return frmTestNamedArgs;
	}

// Dialog Data
	enum { IDD = IDDfrmTestNamedArgs };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestNamedArgs)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCommand1();
	afx_msg void OnCommand2();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestNamedArgs)
	CStatic	m_Label1;
	CButton	m_Command1;
	CButton	m_Command2;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestNamedArgs)

public:	
	VBtoFontAttribute fm_Label1;
	void mySub(short iArg1, CString sArg2, double dArg3, bool bArg4);
	//}}VBto_Converter_Class_Public

};

extern CfrmTestNamedArgs *frmTestNamedArgs;
