// frmTestMisc_SSTab1_Page2.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestMisc_SSTab1_Page2)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CfrmTestMisc_SSTab1_Page2 dialog
class CfrmTestMisc_SSTab1_Page2 : public CPropertyPage
{
// Construction
public:
	CfrmTestMisc_SSTab1_Page2();	// standard constructor

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
	static CfrmTestMisc_SSTab1_Page2 *InstancePtr() {
		extern CfrmTestMisc_SSTab1_Page2 *frmTestMisc_SSTab1_Page2;
		if (!frmTestMisc_SSTab1_Page2) frmTestMisc_SSTab1_Page2 = new CfrmTestMisc_SSTab1_Page2();
		return frmTestMisc_SSTab1_Page2;
	}

// Dialog Data
	enum { IDD = IDDfrmTestMisc_SSTab1_Page2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestMisc_SSTab1_Page2)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCmdCreateFile();
	afx_msg void OnCmdReadTextFile();
	afx_msg void OnCmdKillFiles();
	afx_msg void OnCmdFileCopy();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestMisc_SSTab1_Page2)
	CEdit	m_TextMaskFile;
	CButton	m_CmdCreateFile;
	CButton	m_CmdKillFiles;
	CButton	m_CmdFileCopy;
	CButton	m_CmdReadTextFile;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestMisc_SSTab1_Page2)

public:	CToolTipCtrl	m_tooltip;
	
	VBtoFontAttribute fm_Label1;
	//}}VBto_Converter_Class_Public

};

extern CfrmTestMisc_SSTab1_Page2 *frmTestMisc_SSTab1_Page2;
