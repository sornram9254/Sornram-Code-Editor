// frmTestAutoDim.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestAutoDim)
#include "VBto_Converter.h"
#include "Module3Name.h"
//}}VBto_Converter_Class_Global


// CfrmTestAutoDim dialog
class CfrmTestAutoDim : public CDialog
{
// Construction
public:
	CfrmTestAutoDim(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestAutoDim *InstancePtr() {
		extern CfrmTestAutoDim *frmTestAutoDim;
		if (!frmTestAutoDim) frmTestAutoDim = new CfrmTestAutoDim();
		return frmTestAutoDim;
	}

// Dialog Data
	enum { IDD = IDDfrmTestAutoDim };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestAutoDim)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCmdClose();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestAutoDim)
	CStatic	m_LabelResults;
	CButton	m_CmdClose;
	CEdit	m_TextInvisible;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestAutoDim)

public:	
	VBtoFontAttribute fm_LabelResults;
	void Form_Load();
	void Sub1(CString& sp);
	void Sub2();
	//}}VBto_Converter_Class_Public

};

extern CfrmTestAutoDim *frmTestAutoDim;
