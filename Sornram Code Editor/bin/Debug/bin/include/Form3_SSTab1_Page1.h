// Form3_SSTab1_Page1.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CForm3_SSTab1_Page1)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CForm3_SSTab1_Page1 dialog
class CForm3_SSTab1_Page1 : public CPropertyPage
{
// Construction
public:
	CForm3_SSTab1_Page1();	// standard constructor

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
	static CForm3_SSTab1_Page1 *InstancePtr() {
		extern CForm3_SSTab1_Page1 *Form3_SSTab1_Page1;
		if (!Form3_SSTab1_Page1) Form3_SSTab1_Page1 = new CForm3_SSTab1_Page1();
		return Form3_SSTab1_Page1;
	}

// Dialog Data
	enum { IDD = IDDForm3_SSTab1_Page1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CForm3_SSTab1_Page1)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CForm3_SSTab1_Page1)
	CButton	m_Frame1;
	CProgressCtrl	m_ProgressBar1;
	CSliderCtrl	m_Slider1;
	CProgressCtrl	m_ProgressBar2;
	CSliderCtrl	m_Slider2;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CForm3_SSTab1_Page1)

public:	
	VBtoFontAttribute fm_Label3, fm_Label4, fm_Frame1;
	//}}VBto_Converter_Class_Public

};

extern CForm3_SSTab1_Page1 *Form3_SSTab1_Page1;
