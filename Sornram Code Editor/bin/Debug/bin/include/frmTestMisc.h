// frmTestMisc.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestMisc)
#include "frmTestMisc_SSTab1_Page1.h"
#include "frmTestMisc_SSTab1_Page2.h"
#include "frmTestMisc_SSTab1_Page3.h"
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CfrmTestMisc dialog
class CfrmTestMisc : public CDialog
{
// Construction
public:
	CfrmTestMisc(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestMisc *InstancePtr() {
		extern CfrmTestMisc *frmTestMisc;
		if (!frmTestMisc) frmTestMisc = new CfrmTestMisc();
		return frmTestMisc;
	}

// Dialog Data
	enum { IDD = IDDfrmTestMisc };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestMisc)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCmdTestPrintToFile();
	afx_msg void OnCmdTestPrintToDebug();
	afx_msg void OnCmdTestPrintToForm();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestMisc)
	CStatic	m_Label1;
	CButton	m_CmdTestPrintToDebug;
	CButton	m_CmdTestPrintToFile;
	CButton	m_CmdTestPrintToForm;
	CButton	m_FrameCommandLineArguments;
	CEdit	m_TextCommandLineArguments;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestMisc)

public:	CfrmTestMisc_SSTab1_Page1	m_frmTestMisc_SSTab1_Page1;
	CfrmTestMisc_SSTab1_Page2	m_frmTestMisc_SSTab1_Page2;
	CfrmTestMisc_SSTab1_Page3	m_frmTestMisc_SSTab1_Page3;
	CPropertySheet	m_frmTestMisc_SSTab1;
	
	VBtoFontAttribute fm_Label1;
	void Form_Load();
	//}}VBto_Converter_Class_Public

};

extern CfrmTestMisc *frmTestMisc;
