// frmTestString.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestString)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CfrmTestString dialog
class CfrmTestString : public CDialog
{
// Construction
public:
	CfrmTestString(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestString *InstancePtr() {
		extern CfrmTestString *frmTestString;
		if (!frmTestString) frmTestString = new CfrmTestString();
		return frmTestString;
	}

// Dialog Data
	enum { IDD = IDDfrmTestString };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestString)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void ChangeTextParam1();
	afx_msg void ChangeTextParam2();
	afx_msg void ChangeTextSource();
	afx_msg void SelchangeComboBoxActionText();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestString)
	CStatic	m_LabelSource;
	CStatic	m_Label2;
	CStatic	m_LabelParam1;
	CStatic	m_LabelParam2;
	CStatic	m_Label3;
	CEdit	m_TextSource;
	CComboBox	m_ComboBoxActionText;
	CButton	m_FrameResultText;
	CStatic	m_LabelResultText;
	CEdit	m_TextResultText;
	CButton	m_CheckResultText;
	CButton	m_OptionResultText;
	CButton	m_CommandResultText;
	CEdit	m_TextParam1;
	CEdit	m_TextParam2;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestString)

public:	
	CString strStart,  strLength,  strFind;
	
	CString GetNewString(CString S);
	void ActionText();
	void Form_Load();
	//}}VBto_Converter_Class_Public

};

extern CfrmTestString *frmTestString;
