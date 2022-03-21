// frmTestTimer.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestTimer)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CfrmTestTimer dialog
class CfrmTestTimer : public CDialog
{
// Construction
public:
	CfrmTestTimer(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestTimer *InstancePtr() {
		extern CfrmTestTimer *frmTestTimer;
		if (!frmTestTimer) frmTestTimer = new CfrmTestTimer();
		return frmTestTimer;
	}

// Dialog Data
	enum { IDD = IDDfrmTestTimer };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestTimer)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OncbTimer1();
	afx_msg void OncbTimer2();
	afx_msg void OnCommandReset();
	afx_msg void OnCmdStart();
	afx_msg void OnCmdReset();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestTimer)
	CStatic	m_Label3;
	CButton	m_Frame1;
	CStatic	m_Label2;
	CStatic	m_Label1;
	CButton	m_CommandReset;
	CButton	m_cbTimer2;
	CEdit	m_txtTimer2;
	CEdit	m_txtTimer2Interval;
	CEdit	m_txtTimer1Interval;
	CEdit	m_txtTimer1;
	CButton	m_cbTimer1;
	CButton	m_Frame2;
	CStatic	m_IDC_TIME;
	CButton	m_CmdReset;
	CButton	m_CmdStart;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestTimer)

public:	VBtoTimer Timer2;
	VBtoTimer Timer1;
	VBtoTimer TimerClock;
	
	int CounterTimer1,  CounterTimer2;
	 int lTime;
	
	VBtoFontAttribute fm_Label3, fm_IDC_TIME;
	void Form_Load();
	void ResetInterval();
	void Timer1_Timer();
	void Timer2_Timer();
	void TimerClock_Timer();
	void ShowTime();
	//}}VBto_Converter_Class_Public

};

extern CfrmTestTimer *frmTestTimer;
