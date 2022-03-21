// frmTestMath.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestMath)
#include "VBto_Converter.h"
#include "math.h"
//}}VBto_Converter_Class_Global


// CfrmTestMath dialog
class CfrmTestMath : public CDialog
{
// Construction
public:
	CfrmTestMath(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestMath *InstancePtr() {
		extern CfrmTestMath *frmTestMath;
		if (!frmTestMath) frmTestMath = new CfrmTestMath();
		return frmTestMath;
	}

// Dialog Data
	enum { IDD = IDDfrmTestMath };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestMath)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void SelchangeListFunction();
	afx_msg void ChangeTextX();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestMath)
	CStatic	m_Label2;
	CStatic	m_Label1;
	CStatic	m_Label4;
	CStatic	m_Label3;
	CStatic	m_Label5;
	CEdit	m_TextX;
	CEdit	m_TextResult;
	CListBox	m_ListFunction;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestMath)

public:	
	VBtoFontAttribute fm_Label3, fm_Label5;
	void Form_Load();
	double RowCos(double x);
	double RowSin(double x);
	double CalcPI();
	double CalcFunction(double x);
	void Action();
	//}}VBto_Converter_Class_Public

};

extern CfrmTestMath *frmTestMath;
