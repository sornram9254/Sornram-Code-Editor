// frmTestDeclare.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestDeclare)
#include "VBto_Converter.h"
#include "ClassTestDeclare.h"
#include "ModuleTestDeclare.h"
//}}VBto_Converter_Class_Global


// CfrmTestDeclare dialog
class CfrmTestDeclare : public CDialog
{
// Construction
public:
	CfrmTestDeclare(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestDeclare *InstancePtr() {
		extern CfrmTestDeclare *frmTestDeclare;
		if (!frmTestDeclare) frmTestDeclare = new CfrmTestDeclare();
		return frmTestDeclare;
	}

// Dialog Data
	enum { IDD = IDDfrmTestDeclare };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestDeclare)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void ChangetxtVariableName();
	afx_msg void OnCmdGetEnv();
	afx_msg void OnCmdGetLocalTime();
	afx_msg void OnBtnRedraw();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnCmdMsgBox();
	afx_msg void OnCmdShellExecute();
	afx_msg void OnCmdShellExecute2();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestDeclare)
	CStatic	m_Label1;
	CButton	m_CmdShellExecute;
	CButton	m_Frame1;
	CStatic	m_LabelX;
	CStatic	m_LabelY;
	CButton	m_Frame2;
	CStatic	m_LabelScreenArea;
	CStatic	m_LabelNumberButtonsMouse;
	CButton	m_Frame3;
	CStatic	m_LabelComputerName;
	CStatic	m_Picture1;
	CButton	m_BtnRedraw;
	CButton	m_CmdMsgBox;
	CButton	m_Frame0;
	CStatic	m_Label2;
	CEdit	m_txtGetEnv;
	CButton	m_CmdGetEnv;
	CEdit	m_txtVariableName;
	CButton	m_CmdShellExecute2;
	CButton	m_Frame4;
	CStatic	m_LabelDate;
	CStatic	m_LabelTime;
	CButton	m_CmdGetLocalTime;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestDeclare)

public:	CToolTipCtrl	m_tooltip;
	
	
	public: struct MySYSTEMTIME
	{
		 short wYear; 
		 short wMonth; 
		 short wDayOfWeek; 
		 short wDay; 
		 short wHour; 
		 short wMinute; 
		 short wSecond; 
		 short wMilliseconds; 
	};

	


	public: struct POINTAPI
	{
		 int X; 
		 int Y; 
	};

	VBtoFontAttribute fm_Label1, fm_Picture1;
	void GetLocalTimeSub();
	void CmdTestCallFromModuleAndClass();
	void Form_Load();
	//}}VBto_Converter_Class_Public

};

extern CfrmTestDeclare *frmTestDeclare;
