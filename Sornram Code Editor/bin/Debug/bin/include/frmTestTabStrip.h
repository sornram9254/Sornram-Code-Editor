// frmTestTabStrip.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestTabStrip)
#include "frmTestTabStrip_SSTab1_Page1.h"
#include "frmTestTabStrip_SSTab1_Page2.h"
#include "frmTestTabStrip_SSTab1_Page3.h"
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CfrmTestTabStrip dialog
class CfrmTestTabStrip : public CDialog
{
// Construction
public:
	CfrmTestTabStrip(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestTabStrip *InstancePtr() {
		extern CfrmTestTabStrip *frmTestTabStrip;
		if (!frmTestTabStrip) frmTestTabStrip = new CfrmTestTabStrip();
		return frmTestTabStrip;
	}

// Dialog Data
	enum { IDD = IDDfrmTestTabStrip };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestTabStrip)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCmdAdd1();
	afx_msg void OnCmdAdd2();
	afx_msg void OnCmdAdd3();
	afx_msg void OnCmdRemove();
	afx_msg void OnCmdClear();
	afx_msg void OnCmdNewSelectedItemCaption();
	afx_msg void OnCmdNewSelectedItemIndex();
	afx_msg void SelchangingTabStrip1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void SelchangeTabStrip1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void KeydownTabStrip1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestTabStrip)
	CStatic	m_Label4;
	CTabCtrl	m_TabStrip1;
	CButton	m_Frame1;
	CStatic	m_LabelIndex;
	CStatic	m_LabelCount;
	CStatic	m_LabelCaption;
	CStatic	m_LabelTag;
	CStatic	m_LabelDefault;
	CButton	m_Frame2;
	CStatic	m_Label1;
	CStatic	m_Label2;
	CEdit	m_txtAddCaption;
	CButton	m_CmdAdd3;
	CButton	m_CmdAdd2;
	CButton	m_CmdAdd1;
	CEdit	m_txtAddIndex;
	CButton	m_Frame3;
	CStatic	m_Label3;
	CButton	m_CmdClear;
	CButton	m_CmdRemove;
	CEdit	m_txtRemoveIndex;
	CButton	m_Frame4;
	CButton	m_CmdNewSelectedItemIndex;
	CEdit	m_txtNewSelectedItemIndex;
	CButton	m_CmdNewSelectedItemCaption;
	CEdit	m_txtNewSelectedItemCaption;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestTabStrip)

public:	CfrmTestTabStrip_SSTab1_Page1	m_frmTestTabStrip_SSTab1_Page1;
	CfrmTestTabStrip_SSTab1_Page2	m_frmTestTabStrip_SSTab1_Page2;
	CfrmTestTabStrip_SSTab1_Page3	m_frmTestTabStrip_SSTab1_Page3;
	CPropertySheet	m_frmTestTabStrip_SSTab1;
	
	VBtoFontAttribute fm_Label4;
	void ShowState();
	void TabStrip1_GotFocus();
	void TabStrip1_KeyDown(short& KeyCode, short& Shift);
	void TabStrip1_KeyUp(short& KeyCode, short& Shift);
	void TabStrip1_LostFocus();
	void TabStrip1_MouseDown(short& Button, short& Shift, float& x, float& y);
	void TabStrip1_MouseUp(short& Button, short& Shift, float& x, float& y);
	void TabStrip1_MouseMove(short& Button, short& Shift, float& x, float& y);
	//}}VBto_Converter_Class_Public

};

extern CfrmTestTabStrip *frmTestTabStrip;
