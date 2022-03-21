// frmTestLen.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestLen)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CfrmTestLen dialog
class CfrmTestLen : public CDialog
{
// Construction
public:
	CfrmTestLen(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestLen *InstancePtr() {
		extern CfrmTestLen *frmTestLen;
		if (!frmTestLen) frmTestLen = new CfrmTestLen();
		return frmTestLen;
	}

// Dialog Data
	enum { IDD = IDDfrmTestLen };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestLen)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestLen)
	CStatic	m_LabelParam1;
	CStatic	m_Label2;
	CStatic	m_Label4;
	CStatic	m_LabelParam2;
	CStatic	m_LabelParam3;
	CStatic	m_LabelParam4;
	CStatic	m_LabelParam5;
	CStatic	m_LabelParam6;
	CStatic	m_LabelParam7;
	CStatic	m_LabelParam8;
	CStatic	m_LabelParam9;
	CStatic	m_LabelParam10;
	CStatic	m_Label3;
	CEdit	m_LenParam1;
	CEdit	m_LenParam2;
	CEdit	m_LenParam3;
	CEdit	m_LenParam4;
	CEdit	m_LenParam5;
	CEdit	m_LenParam6;
	CEdit	m_LenParam7;
	CEdit	m_LenParam8;
	CEdit	m_LenParam9;
	CEdit	m_LenParam10;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestLen)

public:	
	
	public: struct myType
	{
		 short vI; 
		 int vL; 
		 float vS; 
		 double vD; 
	};

	


	public: struct myType2
	{
		 BYTE vB; 
		 myType myT1; 
		 myType myT2; 
	};

	VBtoFontAttribute fm_Label2, fm_Label4;
	void Form_Load();
	//}}VBto_Converter_Class_Public

};

extern CfrmTestLen *frmTestLen;
