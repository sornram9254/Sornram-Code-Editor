// frmTestFontProperty.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestFontProperty)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CfrmTestFontProperty dialog
class CfrmTestFontProperty : public CDialog
{
// Construction
public:
	CfrmTestFontProperty(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestFontProperty *InstancePtr() {
		extern CfrmTestFontProperty *frmTestFontProperty;
		if (!frmTestFontProperty) frmTestFontProperty = new CfrmTestFontProperty();
		return frmTestFontProperty;
	}

// Dialog Data
	enum { IDD = IDDfrmTestFontProperty };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestFontProperty)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void SelchangeComboFontName();
	afx_msg void OnCmdBackColorBlue();
	afx_msg void OnCmdBackColorCyan();
	afx_msg void OnCmdForeColorYellow();
	afx_msg void OnCmdForeColorRed();
	afx_msg void OnCmdSizePlus();
	afx_msg void OnCmdSizeMinus();
	afx_msg void OncbBold();
	afx_msg void OncbItalic();
	afx_msg void OncbStrikethrough();
	afx_msg void OncbUnderline();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestFontProperty)
	CButton	m_FrameTest;
	CStatic	m_LblTest;
	CEdit	m_EdtTest;
	CButton	m_CmdTest;
	CButton	m_CheckTest;
	CButton	m_OptTest;
	CButton	m_Frame1;
	CStatic	m_Label2;
	CButton	m_cbStrikethrough;
	CButton	m_CmdSizeMinus;
	CButton	m_CmdSizePlus;
	CButton	m_cbUnderline;
	CButton	m_cbBold;
	CButton	m_cbItalic;
	CButton	m_CmdForeColorRed;
	CButton	m_CmdForeColorYellow;
	CButton	m_CmdBackColorBlue;
	CButton	m_CmdBackColorCyan;
	CComboBox	m_ComboFontName;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestFontProperty)

public:	
		// VBto upgrade warning: bValue As bool	OnWrite(VBRUN.CheckBoxConstants)
	float Value; bool bValue;
	
	VBtoFontAttribute fm_FrameTest, fm_LblTest, fm_EdtTest, fm_CmdTest, fm_CheckTest, fm_OptTest;
	VBtoFontAttribute fm_Frame1;
	void SetBackColor(COLORREF col);
	void SetForeColor(COLORREF col);
	void ShowProps();
	//}}VBto_Converter_Class_Public

};

extern CfrmTestFontProperty *frmTestFontProperty;
