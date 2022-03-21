// frmTestMisc_SSTab1_Page1.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestMisc_SSTab1_Page1)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CfrmTestMisc_SSTab1_Page1 dialog
class CfrmTestMisc_SSTab1_Page1 : public CPropertyPage
{
// Construction
public:
	CfrmTestMisc_SSTab1_Page1();	// standard constructor

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
	static CfrmTestMisc_SSTab1_Page1 *InstancePtr() {
		extern CfrmTestMisc_SSTab1_Page1 *frmTestMisc_SSTab1_Page1;
		if (!frmTestMisc_SSTab1_Page1) frmTestMisc_SSTab1_Page1 = new CfrmTestMisc_SSTab1_Page1();
		return frmTestMisc_SSTab1_Page1;
	}

// Dialog Data
	enum { IDD = IDDfrmTestMisc_SSTab1_Page1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestMisc_SSTab1_Page1)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCmdCurDir();
	afx_msg void OnCmdChDir();
	afx_msg void OnCmdDir();
	afx_msg void OnCmdMkDir();
	afx_msg void OnCmdRmDir();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestMisc_SSTab1_Page1)
	CButton	m_CmdDir;
	CEdit	m_TextDir;
	CEdit	m_TextMaskFiles;
	CEdit	m_TextChDir;
	CButton	m_CmdMkDir;
	CButton	m_CmdRmDir;
	CButton	m_CmdCurDir;
	CButton	m_CmdChDir;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestMisc_SSTab1_Page1)

public:	CToolTipCtrl	m_tooltip;
	
	VBtoFontAttribute fm_Label1;
	//}}VBto_Converter_Class_Public

};

extern CfrmTestMisc_SSTab1_Page1 *frmTestMisc_SSTab1_Page1;
