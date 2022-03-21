// frmMain.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmMain)
#include "VBto_Converter.h"
#include "Form1.h"
#include "Form2.h"
#include "Form3.h"
#include "frmTestCommonDialog.h"
#include "frmTestVisible.h"
#include "frmTestFormProperty.h"
#include "frmTestEvents.h"
#include "frmTestListBox.h"
#include "frmTestMsgBox.h"
#include "frmTestString.h"
#include "frmTestDoWhile.h"
#include "frmTestSelect.h"
#include "frmTestMath.h"
#include "frmTestTimer.h"
#include "frmTestLen.h"
#include "frmTestArray.h"
#include "frmTestMisc.h"
#include "frmTestGDI.h"
#include "frmTestCursor.h"
#include "frmTestTypeCast.h"
#include "frmTestLike.h"
#include "frmTestExpression.h"
#include "frmTestModuleClass.h"
#include "frmTestReDim.h"
#include "frmTestOnError.h"
#include "frmTestListView.h"
#include "frmTestControlArrays.h"
#include "frmTestAutoDim.h"
#include "frmTestInputBox.h"
#include "frmTestPropertyGetLet.h"
#include "frmTestPrinter.h"
#include "frmTestTabStrip.h"
#include "frmTestNamedArgs.h"
#include "frmTestFontProperty.h"
#include "frmTestPaint.h"
#include "frmTestStatusBar.h"
#include "frmTestTreeView.h"
#include "frmTestDeclare.h"
#include "frmTestExtConsts.h"
#include "frmTestDate.h"
#include "frmTestFileSystemObject.h"
//}}VBto_Converter_Class_Global


// CfrmMain dialog
class CfrmMain : public CDialog
{
// Construction
public:
	CfrmMain(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmMain *InstancePtr() {
		extern CfrmMain *frmMain;
		if (!frmMain) frmMain = new CfrmMain();
		return frmMain;
	}

// Dialog Data
	enum { IDD = IDDfrmMain };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmMain)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	afx_msg void OnmmForm1();
	afx_msg void OnmmForm2();
	afx_msg void OnmmForm3();
	afx_msg void OnmmClose();
	afx_msg void OnmmExit();
	afx_msg void OnCmdTestForm1();
	afx_msg void OnCmdTestForm2();
	afx_msg void OnCmdTestForm3();
	afx_msg void OnCmdTestCommonDialog();
	afx_msg void OnCmdTestVisible();
	afx_msg void OnCmdTestFormProperty();
	afx_msg void OnCmdTestEvents();
	afx_msg void OnCmdTestListBox();
	afx_msg void OnCmdTestMsgBox();
	afx_msg void OnCmdTestString();
	afx_msg void OnCmdTestDoWhile();
	afx_msg void OnCmdTestSelect();
	afx_msg void OnCmdTestMath();
	afx_msg void OnCmdTestTimer();
	afx_msg void OnCmdTestLen();
	afx_msg void OnCmdTestArray();
	afx_msg void OnCmdTestMisc();
	afx_msg void OnCmdTestGDI();
	afx_msg void OnCmdTestCursor();
	afx_msg void OnCmdTestTypeCast();
	afx_msg void OnCmdTestLike();
	afx_msg void OnCmdTestExpression();
	afx_msg void OnCmdTestModuleClass();
	afx_msg void OnCmdTestReDim();
	afx_msg void OnCmdTestOnError();
	afx_msg void OnCmdTestListView();
	afx_msg void OnCmdTestControlArrays();
	afx_msg void OnCmdTestAutoDim();
	afx_msg void OnCmdTestInputBox();
	afx_msg void OnCmdTestPropertyGetLet();
	afx_msg void OnCmdTestPrinter();
	afx_msg void OnCmdTestTabStrip();
	afx_msg void OnCmdTestNamedArgs();
	afx_msg void OnCmdTestFontProperty();
	afx_msg void OnCmdTestPaint();
	afx_msg void OnCmdTestStatusBar();
	afx_msg void OnCmdTestTreeView();
	afx_msg void OnCmdTestDeclare();
	afx_msg void OnCmdTestExtConsts();
	afx_msg void OnCmdTestDate();
	afx_msg void OnCmdTestFileSystemObject();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmMain)
	CStatic	m_Label1;
	CButton	m_CmdTestEvents;
	CButton	m_CmdTestListBox;
	CButton	m_CmdTestMath;
	CButton	m_CmdTestMsgBox;
	CButton	m_CmdTestString;
	CButton	m_CmdTestVisible;
	CButton	m_CmdTestFormProperty;
	CButton	m_CmdTestForm1;
	CButton	m_CmdTestForm2;
	CButton	m_CmdTestForm3;
	CButton	m_CmdTestDoWhile;
	CButton	m_CmdTestSelect;
	CButton	m_CmdTestTimer;
	CButton	m_CmdTestLen;
	CButton	m_CmdTestCommonDialog;
	CButton	m_CmdTestArray;
	CButton	m_CmdTestMisc;
	CButton	m_CmdTestGDI;
	CButton	m_CmdTestCursor;
	CButton	m_CmdTestTypeCast;
	CButton	m_CmdTestLike;
	CButton	m_CmdTestExpression;
	CButton	m_CmdTestModuleClass;
	CButton	m_CmdTestReDim;
	CButton	m_CmdTestListView;
	CButton	m_CmdTestOnError;
	CButton	m_CmdTestControlArrays;
	CButton	m_CmdTestAutoDim;
	CButton	m_CmdTestInputBox;
	CButton	m_CmdTestPropertyGetLet;
	CButton	m_CmdTestPrinter;
	CButton	m_CmdTestTabStrip;
	CButton	m_CmdTestPaint;
	CButton	m_CmdTestNamedArgs;
	CButton	m_CmdTestFontProperty;
	CButton	m_CmdTestStatusBar;
	CStatusBarCtrl	m_StatusBar1;
	CButton	m_CmdTestTreeView;
	CButton	m_CmdTestDeclare;
	CButton	m_CmdTestExtConsts;
	CButton	m_CmdTestDate;
	CButton	m_CmdTestFileSystemObject;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmMain)

public:	VBtoTimer TimerNow;
	CToolTipCtrl	m_tooltip;
	
	VBtoFontAttribute fm_Label1;
	void Form_Load();
	void Form_QueryUnload(short& Cancel, short UnloadMode);
	void Form_Unload(short& Cancel);
	void TimerNow_Timer();
	//}}VBto_Converter_Class_Public

};

extern CfrmMain *frmMain;
