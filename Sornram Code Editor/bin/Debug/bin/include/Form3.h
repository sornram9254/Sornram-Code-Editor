// Form3.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CForm3)
#include "Form3_SSTab1_Page1.h"
#include "Form3_SSTab1_Page2.h"
#include "Form3_SSTab1_Page3.h"
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CForm3 dialog
class CForm3 : public CDialog
{
// Construction
public:
	CForm3(CWnd* pParent = NULL);	// standard constructor

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
	static CForm3 *InstancePtr() {
		extern CForm3 *Form3;
		if (!Form3) Form3 = new CForm3();
		return Form3;
	}

// Dialog Data
	enum { IDD = IDDForm3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CForm3)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CForm3)
	CStatusBarCtrl	m_StatusBar1;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CForm3)

public:	CForm3_SSTab1_Page1	m_Form3_SSTab1_Page1;
	CForm3_SSTab1_Page2	m_Form3_SSTab1_Page2;
	CForm3_SSTab1_Page3	m_Form3_SSTab1_Page3;
	CPropertySheet	m_Form3_SSTab1;
	CImageList	m_ImageList1;
	CToolBarCtrl	m_Toolbar1;
	CFileDialog	*m_CommonDialog1;
	
	VBtoFontAttribute fm_Label3, fm_Label4, fm_Frame1;
	//}}VBto_Converter_Class_Public

};

extern CForm3 *Form3;
