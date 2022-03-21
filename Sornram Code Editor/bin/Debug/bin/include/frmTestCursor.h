// frmTestCursor.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestCursor)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CfrmTestCursor dialog
class CfrmTestCursor : public CDialog
{
// Construction
public:
	CfrmTestCursor(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestCursor *InstancePtr() {
		extern CfrmTestCursor *frmTestCursor;
		if (!frmTestCursor) frmTestCursor = new CfrmTestCursor();
		return frmTestCursor;
	}

// Dialog Data
	enum { IDD = IDDfrmTestCursor };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestCursor)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void SelchangeListCurPointer();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)  { return TRUE; }
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestCursor)
	CStatic	m_Label1;
	CListBox	m_ListCurPointer;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestCursor)

public:	
	void Form_Load();
	//}}VBto_Converter_Class_Public

};

extern CfrmTestCursor *frmTestCursor;
