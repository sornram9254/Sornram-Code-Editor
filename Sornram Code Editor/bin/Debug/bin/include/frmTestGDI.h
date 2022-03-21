// frmTestGDI.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestGDI)
#include "VBto_Converter.h"
#include "math.h"
//}}VBto_Converter_Class_Global


// CfrmTestGDI dialog
class CfrmTestGDI : public CDialog
{
// Construction
public:
	CfrmTestGDI(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestGDI *InstancePtr() {
		extern CfrmTestGDI *frmTestGDI;
		if (!frmTestGDI) frmTestGDI = new CfrmTestGDI();
		return frmTestGDI;
	}

// Dialog Data
	enum { IDD = IDDfrmTestGDI };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestGDI)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCheckTimerEnabled();
	afx_msg void OnrbTimerInterval_0();
	afx_msg void OnrbTimerInterval_1();
	afx_msg void OnrbTimerInterval_2();
	afx_msg void OnCmdClear();
	afx_msg void SelchangeComboDrawWidth();
	afx_msg void SelchangeComboDrawStyle();
	afx_msg void SelchangeComboFillStyle();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestGDI)
	CStatic	m_Picture1;
	CButton	m_CmdClear;
	CButton	m_Frame1;
	CButton	m_CheckTimerEnabled;
	CButton	m_rbTimerInterval_2;
	CButton	m_rbTimerInterval_1;
	CButton	m_rbTimerInterval_0;
	CButton	m_Frame2;
	CButton	m_CheckLine;
	CButton	m_CheckPSet;
	CButton	m_CheckRectangle;
	CButton	m_CheckFillRectangle;
	CButton	m_CheckCircle;
	CButton	m_CheckArc;
	CButton	m_Frame3;
	CStatic	m_Label2;
	CStatic	m_Label3;
	CStatic	m_Label4;
	CComboBox	m_ComboFillStyle;
	CComboBox	m_ComboDrawWidth;
	CComboBox	m_ComboDrawStyle;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestGDI)

public:	
	CButton *m_rbTimerInterval[3];
	
	VBtoTimer Timer1;
	
	COLORREF col;
	
	void Form_Load();
	void rbTimerInterval_(short Index);
	void CmdClear_Click();
	COLORREF GetRndColor();
	void TestTranslationOnly(bool flRun);
	void Timer1_Timer();
	//}}VBto_Converter_Class_Public

};

extern CfrmTestGDI *frmTestGDI;
