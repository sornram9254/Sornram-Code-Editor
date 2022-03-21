// frmTestTabStrip_SSTab1_Page3.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestTabStrip_SSTab1_Page3)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CfrmTestTabStrip_SSTab1_Page3 dialog
class CfrmTestTabStrip_SSTab1_Page3 : public CPropertyPage
{
// Construction
public:
	CfrmTestTabStrip_SSTab1_Page3();	// standard constructor

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
	static CfrmTestTabStrip_SSTab1_Page3 *InstancePtr() {
		extern CfrmTestTabStrip_SSTab1_Page3 *frmTestTabStrip_SSTab1_Page3;
		if (!frmTestTabStrip_SSTab1_Page3) frmTestTabStrip_SSTab1_Page3 = new CfrmTestTabStrip_SSTab1_Page3();
		return frmTestTabStrip_SSTab1_Page3;
	}

// Dialog Data
	enum { IDD = IDDfrmTestTabStrip_SSTab1_Page3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestTabStrip_SSTab1_Page3)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestTabStrip_SSTab1_Page3)
	CStatic	m_Label5;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestTabStrip_SSTab1_Page3)

public:	
	VBtoFontAttribute fm_Label4;
	//}}VBto_Converter_Class_Public

};

extern CfrmTestTabStrip_SSTab1_Page3 *frmTestTabStrip_SSTab1_Page3;
