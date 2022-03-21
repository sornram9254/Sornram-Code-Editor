// frmTestArray.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestArray)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CfrmTestArray dialog
class CfrmTestArray : public CDialog
{
// Construction
public:
	CfrmTestArray(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestArray *InstancePtr() {
		extern CfrmTestArray *frmTestArray;
		if (!frmTestArray) frmTestArray = new CfrmTestArray();
		return frmTestArray;
	}

// Dialog Data
	enum { IDD = IDDfrmTestArray };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestArray)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnCmdRecalcArray1();
	afx_msg void OnCmdRecalcArray2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestArray)
	CStatic	m_Label3;
	CEdit	m_TextResult;
	CButton	m_CmdRecalcArray1;
	CButton	m_CmdRecalcArray2;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestArray)

public:	
	
	public: struct myPoint
	{
		 float xx; 
		 double yy; 
		 CString SS; 
	};

	


	public: struct myPointA
	{
		 float xx; 
		 double yy; 
		 CString SS; 
	};

	void ReCalcTable1();
	void ReCalcTable2();
	//}}VBto_Converter_Class_Public

};

extern CfrmTestArray *frmTestArray;
