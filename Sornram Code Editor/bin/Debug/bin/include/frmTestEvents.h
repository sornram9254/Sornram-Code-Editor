// frmTestEvents.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestEvents)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CfrmTestEvents dialog
class CfrmTestEvents : public CDialog
{
// Construction
public:
	CfrmTestEvents(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestEvents *InstancePtr() {
		extern CfrmTestEvents *frmTestEvents;
		if (!frmTestEvents) frmTestEvents = new CfrmTestEvents();
		return frmTestEvents;
	}

// Dialog Data
	enum { IDD = IDDfrmTestEvents };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestEvents)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCheck1();
	afx_msg void OnCommandClear();
	afx_msg void OnCommand1();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnFrame1();
	afx_msg void DoubleclickedFrame1();
	afx_msg void OnLabel1();
	afx_msg void OnOption1();
	afx_msg void OnOption2();
	afx_msg void ChangeText1();
	afx_msg void SetfocusText1();
	afx_msg void KillfocusText1();
	afx_msg void EditchangeCombo1();
	afx_msg void SelchangeCombo1();
	afx_msg void SelchangeList1();
	afx_msg void OnPicture1();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestEvents)
	CStatic	m_Label1;
	CStatic	m_Label3;
	CSliderCtrl	m_Slider2;
	CListCtrl	m_ListViewEvents;
	CButton	m_Command1;
	CButton	m_CommandClear;
	CEdit	m_Text1;
	CSliderCtrl	m_Slider1;
	CScrollBar	m_HScroll1;
	CListBox	m_ListBoxEvents;
	CScrollBar	m_HScroll2;
	CScrollBar	m_VScroll1;
	CSliderCtrl	m_Slider3;
	CListBox	m_List1;
	CComboBox	m_Combo1;
	CStatic	m_Picture1;
	CProgressCtrl	m_ProgressBar1;
	CButton	m_Frame1;
	CSpinButtonCtrl	m_UpDown1;
	CButton	m_Option2;
	CButton	m_Option1;
	CButton	m_Check1;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestEvents)

public:	
	VBtoFontAttribute fm_Picture1;
	void AddEventToList(CString nameObj, CString EventStr, CString AddInfo="");
	void Frame1_MouseDown(short& Button, short& Shift, float& x, float& y);
	void Frame1_MouseMove(short& Button, short& Shift, float& x, float& y);
	void Frame1_MouseUp(short& Button, short& Shift, float& x, float& y);
	void UpDown1_Change();
	void Slider1_Click();
	void Slider2_Click();
	void Slider3_Click();
	void VScroll1_Change();
	void HScroll1_Change();
	void HScroll2_Change();
	void ProgressBarSetValue(int Min, int Max, int Val);
	void ProgressBar1_Click();
	void ProgressBar1_MouseDown(short& Button, short& Shift, float& x, float& y);
	void ProgressBar1_MouseMove(short& Button, short& Shift, float& x, float& y);
	void ProgressBar1_MouseUp(short& Button, short& Shift, float& x, float& y);
	void Picture1_MouseMove(short& Button, short& Shift, float& x, float& y);
	//}}VBto_Converter_Class_Public

};

extern CfrmTestEvents *frmTestEvents;
