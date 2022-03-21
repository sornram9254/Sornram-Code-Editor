// frmTestModuleClass.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestModuleClass)
#include "VBto_Converter.h"
#include "Class1Name.h"
#include "Module1Name.h"
#include "Module2Name.h"
#include "Module3Name.h"
//}}VBto_Converter_Class_Global


// CfrmTestModuleClass dialog
class CfrmTestModuleClass : public CDialog
{
// Construction
public:
	CfrmTestModuleClass(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestModuleClass *InstancePtr() {
		extern CfrmTestModuleClass *frmTestModuleClass;
		if (!frmTestModuleClass) frmTestModuleClass = new CfrmTestModuleClass();
		return frmTestModuleClass;
	}

// Dialog Data
	enum { IDD = IDDfrmTestModuleClass };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestModuleClass)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCmdCallFunctionFromModule1();
	afx_msg void OnCmdCallSubFromModule2();
	afx_msg void OnCmdSetXYZtoModule3();
	afx_msg void OnCmdGetDistfromModule3();
	afx_msg void OnCmdTestClass1();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestModuleClass)
	CStatic	m_Label1;
	CButton	m_CmdCallFunctionFromModule1;
	CButton	m_CmdCallSubFromModule2;
	CButton	m_CmdSetXYZtoModule3;
	CEdit	m_TextXYZ;
	CButton	m_CmdGetDistfromModule3;
	CButton	m_CmdTestClass1;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestModuleClass)

public:	
	
	public: struct myType0
	{
		 float x; 
		 int c; 
		 CString S; 
	};

	myType0 mt1;
	 short fPublic;
	 short fPrivate;
	 short fDim;
	
	VBtoFontAttribute fm_Label1;
	void Form_Load();
	void PrivateMethod();
	void Method();
	void PublicMethod();
	//}}VBto_Converter_Class_Public

};

extern CfrmTestModuleClass *frmTestModuleClass;
