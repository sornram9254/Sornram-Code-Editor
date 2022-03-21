// frmTestStatusBar.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestStatusBar)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CfrmTestStatusBar dialog
class CfrmTestStatusBar : public CDialog
{
// Construction
public:
	CfrmTestStatusBar(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestStatusBar *InstancePtr() {
		extern CfrmTestStatusBar *frmTestStatusBar;
		if (!frmTestStatusBar) frmTestStatusBar = new CfrmTestStatusBar();
		return frmTestStatusBar;
	}

// Dialog Data
	enum { IDD = IDDfrmTestStatusBar };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestStatusBar)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOptionSimple();
	afx_msg void OnOptionNormal();
	afx_msg void ChangetxtSimpleText();
	afx_msg void ChangetxtPanelText();
	afx_msg void OncbVisible();
	afx_msg void OncbEnabled();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestStatusBar)
	CStatic	m_Label4;
	CStatusBarCtrl	m_StatusBar1;
	CButton	m_Frame3;
	CStatic	m_Label3;
	CStatic	m_Label2;
	CStatic	m_Label1;
	CSpinButtonCtrl	m_UpDownPanelCount;
	CSpinButtonCtrl	m_UpDownPanelIndex;
	CEdit	m_txtPanelCount;
	CEdit	m_txtPanelText;
	CEdit	m_txtPanelIndex;
	CButton	m_Frame2;
	CEdit	m_txtSimpleText;
	CButton	m_Frame4;
	CButton	m_cbEnabled;
	CButton	m_cbVisible;
	CButton	m_Frame5;
	CButton	m_OptionNormal;
	CButton	m_OptionSimple;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestStatusBar)

public:	
	short ii;
	
	void Form_Load();
	void UpDownPanelIndex_Change();
	//}}VBto_Converter_Class_Public

};

extern CfrmTestStatusBar *frmTestStatusBar;
