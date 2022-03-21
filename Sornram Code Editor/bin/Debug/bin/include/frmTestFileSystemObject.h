// frmTestFileSystemObject.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestFileSystemObject)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CfrmTestFileSystemObject dialog
class CfrmTestFileSystemObject : public CDialog
{
// Construction
public:
	CfrmTestFileSystemObject(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestFileSystemObject *InstancePtr() {
		extern CfrmTestFileSystemObject *frmTestFileSystemObject;
		if (!frmTestFileSystemObject) frmTestFileSystemObject = new CfrmTestFileSystemObject();
		return frmTestFileSystemObject;
	}

// Dialog Data
	enum { IDD = IDDfrmTestFileSystemObject };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestFileSystemObject)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnSaveFile();
	afx_msg void OnBtnReadFile();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestFileSystemObject)
	CButton	m_BtnSaveFile;
	CButton	m_BtnReadFile;
	CEdit	m_TextLog;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestFileSystemObject)

public:	
	CString sFileName; IFileSystemPtr MainFSO1,  MainFSO2;
	
	void AddToLog(CString msg);
	void Form_Load();
	//}}VBto_Converter_Class_Public

};

extern CfrmTestFileSystemObject *frmTestFileSystemObject;
