// frmTestTypeCast.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestTypeCast)
#include "VBto_Converter.h"
#include "mdlCommonVars.h"
//}}VBto_Converter_Class_Global


// CfrmTestTypeCast dialog
class CfrmTestTypeCast : public CDialog
{
// Construction
public:
	CfrmTestTypeCast(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestTypeCast *InstancePtr() {
		extern CfrmTestTypeCast *frmTestTypeCast;
		if (!frmTestTypeCast) frmTestTypeCast = new CfrmTestTypeCast();
		return frmTestTypeCast;
	}

// Dialog Data
	enum { IDD = IDDfrmTestTypeCast };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestTypeCast)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCmdTestTypeCast();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestTypeCast)
	CButton	m_CmdTestTypeCast;
	CListBox	m_ListBoxResults;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestTypeCast)

public:	
		// VBto upgrade warning: ppI As short	OnWrite(short, bool)
	// VBto upgrade warning: ppL As int	OnWrite(short, bool)
	// VBto upgrade warning: ppF As float	OnWrite(short, bool)
	// VBto upgrade warning: ppD As double	OnWrite(short, bool)
	// VBto upgrade warning: ppS As CString	OnWrite(short, bool)
	// VBto upgrade warning: ppC As double	OnWrite(short, bool)
	short pp0,  ppI; int ppL; float ppF; double ppD; CString ppS; double ppC;
	 // VBto upgrade warning: ppB As bool	OnWrite(short, bool)
	bool ppB;
	 BYTE ppY;
	
	void Form_Load();
	void RunAllTest();
	void Test0();
	void Test1();
	void VerifyValues(CString TestName, short pI, int vI, int pL, int vL, double pF, double vF, double pD, double vD, double pC, double vC, CString pS, CString vS, bool pB, bool vB);
	void VerifyIntValues(CString TestName, short pI, short vI);
	void VerifyStrValues(CString TestName, CString pS, CString vS);
	bool isDiff(CString pS, CString vS);
	CString AddErrLine(CString S, CString sType, CString pS, CString vS);
	//}}VBto_Converter_Class_Public

};

extern CfrmTestTypeCast *frmTestTypeCast;
