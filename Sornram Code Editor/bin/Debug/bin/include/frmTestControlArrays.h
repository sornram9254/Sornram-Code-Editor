// frmTestControlArrays.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestControlArrays)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CfrmTestControlArrays dialog
class CfrmTestControlArrays : public CDialog
{
// Construction
public:
	CfrmTestControlArrays(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestControlArrays *InstancePtr() {
		extern CfrmTestControlArrays *frmTestControlArrays;
		if (!frmTestControlArrays) frmTestControlArrays = new CfrmTestControlArrays();
		return frmTestControlArrays;
	}

// Dialog Data
	enum { IDD = IDDfrmTestControlArrays };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestControlArrays)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnClose();
	afx_msg void OnpmIndexedItem_0();
	afx_msg void OnpmIndexedItem_2();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnFrame1_3();
	afx_msg void OnFrame1_0();
	afx_msg void OnLabel1_3();
	afx_msg void OnLabel1_0();
	afx_msg void ChangeEdtText_3();
	afx_msg void ChangeEdtText_0();
	afx_msg void OnCheck1_3();
	afx_msg void OnCheck1_0();
	afx_msg void OnPicture1_3();
	afx_msg void OnPicture1_0();
	afx_msg void OnImage1_3();
	afx_msg void OnImage1_0();
	afx_msg void OnCommand1_3();
	afx_msg void OnCommand1_0();
	afx_msg void OnOption1_3();
	afx_msg void OnOption1_2();
	afx_msg void OnOption1_1();
	afx_msg void OnOption1_0();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestControlArrays)
	CButton	m_Frame1_0;
	CStatic	m_Label1_0;
	CStatic	m_Image1_0;
	CSliderCtrl	m_Slider1_0;
	CProgressCtrl	m_ProgressBar1_0;
	CButton	m_Command1_0;
	CEdit	m_EdtText_0;
	CButton	m_Check1_0;
	CStatic	m_Picture1_0;
	CScrollBar	m_HScroll1_0;
	CButton	m_Frame1_3;
	CStatic	m_Label1_3;
	CStatic	m_Image1_3;
	CSliderCtrl	m_Slider1_3;
	CProgressCtrl	m_ProgressBar1_3;
	CButton	m_Command1_3;
	CEdit	m_EdtText_3;
	CButton	m_Check1_3;
	CStatic	m_Picture1_3;
	CScrollBar	m_HScroll1_3;
	CEdit	m_EdtEvents;
	CButton	m_Frame2;
	CButton	m_Option1_0;
	CButton	m_Option1_1;
	CButton	m_Option1_2;
	CButton	m_Option1_3;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestControlArrays)

public:	
	CButton *m_Option1[4];
	CButton *m_Frame1[4];
	CScrollBar *m_HScroll1[4];
	CStatic *m_Picture1[4];
	CButton *m_Check1[4];
	CEdit *m_EdtText[4];
	CButton *m_Command1[4];
	CProgressCtrl *m_ProgressBar1[4];
	CSliderCtrl *m_Slider1[4];
	CStatic *m_Image1[4];
	CStatic *m_Label1[4];
	
	
	CString sOGO;
	 short iOGO;
	
	void Form_Initialize();
	void Form_Load();
	void Form_Unload(short& Cancel);
	void pmIndexedItem_(short Index);
	void OutInfo(CString obj, short Index, CString Ev);
	void Frame1_MouseMove(short Index, short& Button, short& Shift, float& X, float& Y);
	void Frame1_(short Index);
	void Label1_MouseMove(short Index, short& Button, short& Shift, float& X, float& Y);
	void Label1_(short Index);
	void EdtText_MouseMove(short Index, short& Button, short& Shift, float& X, float& Y);
	void EdtText_Click(short Index);
	void EdtText_Change(short Index);
	void Slider1_MouseMove(short Index, short& Button, short& Shift, float& X, float& Y);
	void Slider1_Change(short Index);
	void HScroll1_Change(short Index);
	void ProgressBar1_MouseMove(short Index, short& Button, short& Shift, float& X, float& Y);
	void ProgressBar1_MouseDown(short Index, short& Button, short& Shift, float& X, float& Y);
	void Check1_(short Index);
	void Picture1_DblClick(short Index);
	void Picture1_MouseMove(short Index, short& Button, short& Shift, float& X, float& Y);
	void Picture1_(short Index);
	void Image1_MouseMove(short Index, short& Button, short& Shift, float& X, float& Y);
	void Image1_(short Index);
	void Command1_MouseMove(short Index, short& Button, short& Shift, float& X, float& Y);
	void Command1_(short Index);
	void Option1_MouseMove(short Index, short& Button, short& Shift, float& X, float& Y);
	void Option1_(short Index);
	//}}VBto_Converter_Class_Public

};

extern CfrmTestControlArrays *frmTestControlArrays;
