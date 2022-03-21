// Form3_SSTab1_Page3.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CForm3_SSTab1_Page3)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CForm3_SSTab1_Page3 dialog
class CForm3_SSTab1_Page3 : public CPropertyPage
{
// Construction
public:
	CForm3_SSTab1_Page3();	// standard constructor

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
	static CForm3_SSTab1_Page3 *InstancePtr() {
		extern CForm3_SSTab1_Page3 *Form3_SSTab1_Page3;
		if (!Form3_SSTab1_Page3) Form3_SSTab1_Page3 = new CForm3_SSTab1_Page3();
		return Form3_SSTab1_Page3;
	}

// Dialog Data
	enum { IDD = IDDForm3_SSTab1_Page3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CForm3_SSTab1_Page3)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CForm3_SSTab1_Page3)
	CStatic	m_Label2;
	CSpinButtonCtrl	m_UpDownParam1;
	CEdit	m_TextParam1;
	CButton	m_Frame2;
	CStatic	m_Label1;
	CButton	m_Command2;
	CButton	m_Command1;
	CButton	m_Check1;
	CButton	m_Check2;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CForm3_SSTab1_Page3)

public:	
	VBtoFontAttribute fm_Label3, fm_Label4, fm_Frame1;
	//}}VBto_Converter_Class_Public

};

extern CForm3_SSTab1_Page3 *Form3_SSTab1_Page3;
