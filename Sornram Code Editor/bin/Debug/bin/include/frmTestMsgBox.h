// frmTestMsgBox.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestMsgBox)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CfrmTestMsgBox dialog
class CfrmTestMsgBox : public CDialog
{
// Construction
public:
	CfrmTestMsgBox(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestMsgBox *InstancePtr() {
		extern CfrmTestMsgBox *frmTestMsgBox;
		if (!frmTestMsgBox) frmTestMsgBox = new CfrmTestMsgBox();
		return frmTestMsgBox;
	}

// Dialog Data
	enum { IDD = IDDfrmTestMsgBox };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestMsgBox)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCommand0();
	afx_msg void OnCommand1();
	afx_msg void OnCommand2();
	afx_msg void OnCommand3();
	afx_msg void OnCommand4();
	afx_msg void OnCommand5();
	afx_msg void OnCommand6();
	afx_msg void OnCommand7();
	afx_msg void OnCommand8();
	afx_msg void OnCommand9();
	afx_msg void OnCommand10();
	afx_msg void OnCommand11();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestMsgBox)
	CStatic	m_Label1;
	CButton	m_Command1;
	CButton	m_Command2;
	CButton	m_Command3;
	CButton	m_Command4;
	CButton	m_Command5;
	CButton	m_Command6;
	CButton	m_Command7;
	CButton	m_Command8;
	CButton	m_Command9;
	CButton	m_Command10;
	CButton	m_Command11;
	CButton	m_Command0;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestMsgBox)

public:	
	void retOut(int ret);
	//}}VBto_Converter_Class_Public

};

extern CfrmTestMsgBox *frmTestMsgBox;
