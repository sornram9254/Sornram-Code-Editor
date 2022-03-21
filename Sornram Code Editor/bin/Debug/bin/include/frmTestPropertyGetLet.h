// frmTestPropertyGetLet.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestPropertyGetLet)
#include "VBto_Converter.h"
#include "mdlCommonVars.h"
#include "math.h"
//}}VBto_Converter_Class_Global


// CfrmTestPropertyGetLet dialog
class CfrmTestPropertyGetLet : public CDialog
{
// Construction
public:
	CfrmTestPropertyGetLet(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestPropertyGetLet *InstancePtr() {
		extern CfrmTestPropertyGetLet *frmTestPropertyGetLet;
		if (!frmTestPropertyGetLet) frmTestPropertyGetLet = new CfrmTestPropertyGetLet();
		return frmTestPropertyGetLet;
	}

// Dialog Data
	enum { IDD = IDDfrmTestPropertyGetLet };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestPropertyGetLet)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OncmdPropertyLetGet();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestPropertyGetLet)
	CStatic	m_Label0;
	CStatic	m_Label1;
	CStatic	m_Label2;
	CStatic	m_Label3;
	CButton	m_cmdPropertyLetGet;
	CEdit	m_EdtFirstName;
	CEdit	m_EdtLastName;
	CEdit	m_EdtSalary;
	CEdit	m_TextOutputInformation;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestPropertyGetLet)

public:	
	
	public: struct Person
	{
		 CString Name1; 
		 CString Name2; 
		 int Age; 
		 double Sal; 
	};

	Person mPerson;
	 CComVariant mEditItem;
	
	VBtoFontAttribute fm_Label0;
	CString GetFirstName();
	void SetFirstName(CString S);
	VBtoConverter_ClassPropertyAsString(CString,FirstName,CfrmTestPropertyGetLet)
	 
	void SetLastName(CString S);
	CString GetLastName();
	VBtoConverter_ClassPropertyAsString(CString,LastName,CfrmTestPropertyGetLet)
	 
	CComVariant GetInfoString();
	VBtoConverter_ClassPropertyReadOnly(CComVariant,InfoString,CfrmTestPropertyGetLet)
	 
	void SetSalary(double Sal);
	VBtoConverter_ClassPropertyWriteOnly(double,Salary,CfrmTestPropertyGetLet)
	 
	CString prepareInfo(int unusePar1);
	CComVariant GetEditItem();
	void SetEditItem(CComVariant Value);
	VBtoConverter_ClassProperty(CComVariant,EditItem,CfrmTestPropertyGetLet)
	 
	CString unUseFun(int par1);
	void unUseSub(CString& v1, short& v2, double& v3);
	//}}VBto_Converter_Class_Public

};

extern CfrmTestPropertyGetLet *frmTestPropertyGetLet;
