// frmTestMisc_SSTab1_Page3.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestMisc_SSTab1_Page3)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CfrmTestMisc_SSTab1_Page3 dialog
class CfrmTestMisc_SSTab1_Page3 : public CPropertyPage
{
// Construction
public:
	CfrmTestMisc_SSTab1_Page3();	// standard constructor

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
	static CfrmTestMisc_SSTab1_Page3 *InstancePtr() {
		extern CfrmTestMisc_SSTab1_Page3 *frmTestMisc_SSTab1_Page3;
		if (!frmTestMisc_SSTab1_Page3) frmTestMisc_SSTab1_Page3 = new CfrmTestMisc_SSTab1_Page3();
		return frmTestMisc_SSTab1_Page3;
	}

// Dialog Data
	enum { IDD = IDDfrmTestMisc_SSTab1_Page3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestMisc_SSTab1_Page3)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCmdShell();
	afx_msg void OnCmdBeep();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestMisc_SSTab1_Page3)
	CButton	m_CmdBeep;
	CButton	m_CmdShell;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestMisc_SSTab1_Page3)

public:	
	VBtoFontAttribute fm_Label1;
	//}}VBto_Converter_Class_Public

};

extern CfrmTestMisc_SSTab1_Page3 *frmTestMisc_SSTab1_Page3;
