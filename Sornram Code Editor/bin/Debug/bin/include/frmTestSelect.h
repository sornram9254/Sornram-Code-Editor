// frmTestSelect.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestSelect)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CfrmTestSelect dialog
class CfrmTestSelect : public CDialog
{
// Construction
public:
	CfrmTestSelect(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestSelect *InstancePtr() {
		extern CfrmTestSelect *frmTestSelect;
		if (!frmTestSelect) frmTestSelect = new CfrmTestSelect();
		return frmTestSelect;
	}

// Dialog Data
	enum { IDD = IDDfrmTestSelect };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestSelect)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void SelchangeComboTestNumber();
	afx_msg void EditchangeComboSelect();
	afx_msg void SelchangeComboSelect();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestSelect)
	CStatic	m_LabelMess;
	CStatic	m_Label2;
	CStatic	m_Label6;
	CStatic	m_Label7;
	CStatic	m_Label8;
	CStatic	m_Label1;
	CStatic	m_Label9;
	CEdit	m_TextSelect;
	CComboBox	m_ComboSelect;
	CComboBox	m_ComboTestNumber;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestSelect)

public:	
	VBtoFontAttribute fm_LabelMess, fm_Label1, fm_TextSelect;
	void Form_Load();
	void OnChangeTest();
	void OutMess(CString Mess);
	void Test0(CString TestExpression);
	void Test1(CString TestExpression);
	void Test2Int(short TestExpressionInt);
	void Test2(CString TestExpression);
	void Test3(CString TestExpression);
	//}}VBto_Converter_Class_Public

};

extern CfrmTestSelect *frmTestSelect;
