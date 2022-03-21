// frmTestInputBox.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestInputBox)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CfrmTestInputBox dialog
class CfrmTestInputBox : public CDialog
{
// Construction
public:
	CfrmTestInputBox(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestInputBox *InstancePtr() {
		extern CfrmTestInputBox *frmTestInputBox;
		if (!frmTestInputBox) frmTestInputBox = new CfrmTestInputBox();
		return frmTestInputBox;
	}

// Dialog Data
	enum { IDD = IDDfrmTestInputBox };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestInputBox)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCmdInputBox1();
	afx_msg void OnCmdInputBox2();
	afx_msg void OnCmdInputBox3();
	afx_msg void OnCmdInputBox5();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestInputBox)
	CStatic	m_Label1;
	CButton	m_Frame1;
	CStatic	m_Label2;
	CStatic	m_Label3;
	CStatic	m_Label4;
	CStatic	m_Label5;
	CStatic	m_Label6;
	CButton	m_CmdInputBox1;
	CEdit	m_txtPrompt;
	CEdit	m_txtTitle;
	CEdit	m_txtDefault;
	CEdit	m_txtResult;
	CButton	m_CmdInputBox2;
	CButton	m_CmdInputBox3;
	CButton	m_CmdInputBox5;
	CEdit	m_txtXPos;
	CEdit	m_txtYPos;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestInputBox)

public:	
	//}}VBto_Converter_Class_Public

};

extern CfrmTestInputBox *frmTestInputBox;
