// frmTestDate.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestDate)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CfrmTestDate dialog
class CfrmTestDate : public CDialog
{
// Construction
public:
	CfrmTestDate(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestDate *InstancePtr() {
		extern CfrmTestDate *frmTestDate;
		if (!frmTestDate) frmTestDate = new CfrmTestDate();
		return frmTestDate;
	}

// Dialog Data
	enum { IDD = IDDfrmTestDate };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestDate)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestDate)
	CStatic	m_Label1;
	CEdit	m_Text1;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestDate)

public:	VBtoTimer TimerNow;
	
	VBtoFontAttribute fm_Text1;
	CString myDateToString(DATE dt);
	void TimerNow_Timer();
	void TestTypecastDate();
	//}}VBto_Converter_Class_Public

};

extern CfrmTestDate *frmTestDate;
