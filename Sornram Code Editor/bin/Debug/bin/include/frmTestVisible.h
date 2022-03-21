// frmTestVisible.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestVisible)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CfrmTestVisible dialog
class CfrmTestVisible : public CDialog
{
// Construction
public:
	CfrmTestVisible(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestVisible *InstancePtr() {
		extern CfrmTestVisible *frmTestVisible;
		if (!frmTestVisible) frmTestVisible = new CfrmTestVisible();
		return frmTestVisible;
	}

// Dialog Data
	enum { IDD = IDDfrmTestVisible };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestVisible)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCheckVisible();
	afx_msg void OnCheckEnabled();
	afx_msg void OnCheckLocked();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestVisible)
	CStatic	m_Label1;
	CStatic	m_Image1;
	CStatic	m_Label3;
	CButton	m_CheckVisible;
	CButton	m_CheckEnabled;
	CButton	m_CheckLocked;
	CEdit	m_Text1;
	CButton	m_Command1;
	CButton	m_Check1;
	CButton	m_Option1;
	CScrollBar	m_HScroll1;
	CSliderCtrl	m_Slider1;
	CComboBox	m_Combo1;
	CListBox	m_List1;
	CScrollBar	m_VScroll1;
	CProgressCtrl	m_ProgressBar1;
	CTreeCtrl	m_TreeView1;
	CListCtrl	m_ListView1;
	CStatic	m_Picture1;
	CButton	m_Frame1;
	CButton	m_CheckV;
	CButton	m_CheckE;
	CButton	m_CheckL;
	CSpinButtonCtrl	m_UpDown1;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestVisible)

public:	
	void ShowChecks();
	//}}VBto_Converter_Class_Public

};

extern CfrmTestVisible *frmTestVisible;
