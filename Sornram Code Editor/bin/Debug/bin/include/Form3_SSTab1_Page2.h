// Form3_SSTab1_Page2.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CForm3_SSTab1_Page2)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CForm3_SSTab1_Page2 dialog
class CForm3_SSTab1_Page2 : public CPropertyPage
{
// Construction
public:
	CForm3_SSTab1_Page2();	// standard constructor

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
	static CForm3_SSTab1_Page2 *InstancePtr() {
		extern CForm3_SSTab1_Page2 *Form3_SSTab1_Page2;
		if (!Form3_SSTab1_Page2) Form3_SSTab1_Page2 = new CForm3_SSTab1_Page2();
		return Form3_SSTab1_Page2;
	}

// Dialog Data
	enum { IDD = IDDForm3_SSTab1_Page2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CForm3_SSTab1_Page2)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CForm3_SSTab1_Page2)
	CStatic	m_Label3;
	CStatic	m_Label4;
	CTreeCtrl	m_TreeView1;
	CListCtrl	m_ListView1;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CForm3_SSTab1_Page2)

public:	
	VBtoFontAttribute fm_Label3, fm_Label4, fm_Frame1;
	//}}VBto_Converter_Class_Public

};

extern CForm3_SSTab1_Page2 *Form3_SSTab1_Page2;
