// frmTestFormProperty.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestFormProperty)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CfrmTestFormProperty dialog
class CfrmTestFormProperty : public CDialog
{
// Construction
public:
	CfrmTestFormProperty(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestFormProperty *InstancePtr() {
		extern CfrmTestFormProperty *frmTestFormProperty;
		if (!frmTestFormProperty) frmTestFormProperty = new CfrmTestFormProperty();
		return frmTestFormProperty;
	}

// Dialog Data
	enum { IDD = IDDfrmTestFormProperty };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestFormProperty)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnCmdGetCaption();
	afx_msg void OnCmdSetCaption();
	afx_msg void OnCmdGetLTWH();
	afx_msg void OnCmdSetLTWH();
	afx_msg void OnCmdSetWindowState();
	afx_msg void OnCmdMoveMe();
	afx_msg void OndpCommand();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestFormProperty)
	CStatic	m_Label1;
	CStatic	m_Label2;
	CStatic	m_Label3;
	CButton	m_CmdSetWindowState;
	CButton	m_CmdSetCaption;
	CEdit	m_TextNewCaption;
	CButton	m_CmdGetCaption;
	CButton	m_CmdGetLTWH;
	CEdit	m_TextL;
	CButton	m_CmdSetLTWH;
	CEdit	m_TextT;
	CEdit	m_TextW;
	CEdit	m_TextH;
	CButton	m_FrameDefaultProperties;
	CStatic	m_dpLabel;
	CEdit	m_dpText;
	CButton	m_dpCommand;
	CButton	m_dpCheck;
	CButton	m_dpOption;
	CComboBox	m_dpCombo;
	CScrollBar	m_HScroll1;
	CProgressCtrl	m_dpProgressBar;
	CSliderCtrl	m_dpSlider;
	CButton	m_CmdMoveMe;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestFormProperty)

public:	VBtoTimer dpTimer;
	
	bool flFirst;
	 bool isBounds; int boundL,  boundT,  boundR,  boundB;
	
	void Form_Load();
	void GetLTWH();
	void SetLTWH();
	void TestDefaultProperty();
	//}}VBto_Converter_Class_Public

};

extern CfrmTestFormProperty *frmTestFormProperty;
