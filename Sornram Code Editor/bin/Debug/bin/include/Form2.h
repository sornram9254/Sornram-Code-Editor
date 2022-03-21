// Form2.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CForm2)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CForm2 dialog
class CForm2 : public CDialog
{
// Construction
public:
	CForm2(CWnd* pParent = NULL);	// standard constructor

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
	static CForm2 *InstancePtr() {
		extern CForm2 *Form2;
		if (!Form2) Form2 = new CForm2();
		return Form2;
	}

// Dialog Data
	enum { IDD = IDDForm2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CForm2)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CForm2)
	CStatic	m_Label1;
	CStatic	m_Label2;
	CListCtrl	m_ListView1;
	CProgressCtrl	m_ProgressBar1;
	CSliderCtrl	m_Slider2;
	CStatusBarCtrl	m_StatusBar1;
	CSliderCtrl	m_Slider1;
	CTreeCtrl	m_TreeView1;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CForm2)

public:	CImageList	m_ImageList1;
	CToolBarCtrl	m_Toolbar1;
	
	VBtoFontAttribute fm_Label1, fm_Label2;
	//}}VBto_Converter_Class_Public

};

extern CForm2 *Form2;
