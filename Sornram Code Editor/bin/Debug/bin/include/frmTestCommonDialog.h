// frmTestCommonDialog.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestCommonDialog)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CfrmTestCommonDialog dialog
class CfrmTestCommonDialog : public CDialog
{
// Construction
public:
	CfrmTestCommonDialog(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestCommonDialog *InstancePtr() {
		extern CfrmTestCommonDialog *frmTestCommonDialog;
		if (!frmTestCommonDialog) frmTestCommonDialog = new CfrmTestCommonDialog();
		return frmTestCommonDialog;
	}

// Dialog Data
	enum { IDD = IDDfrmTestCommonDialog };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestCommonDialog)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OncmdSaveFile();
	afx_msg void OncmdOpenFile();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestCommonDialog)
	CStatic	m_LabelTestCommonDialog;
	CButton	m_FrameTestCommonDialog;
	CStatic	m_Label1;
	CStatic	m_Label2;
	CButton	m_Frame2;
	CEdit	m_TextSaveFile;
	CButton	m_cmdSaveFile;
	CButton	m_Frame1;
	CStatic	m_Label3;
	CStatic	m_Label4;
	CComboBox	m_cmbFilterIndex;
	CEdit	m_txtFilter;
	CButton	m_cmdOpenFile;
	CEdit	m_TextOpenFile;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestCommonDialog)

public:	CFileDialog	*m_CommonDialog0;
	CFileDialog	*m_CommonDialogDefault;
	CFileDialog	*m_CommonDialogSave;
	CFileDialog	*m_CommonDialogOpen;
	
	VBtoFontAttribute fm_FrameTestCommonDialog;
	void Form_Load();
	//}}VBto_Converter_Class_Public

};

extern CfrmTestCommonDialog *frmTestCommonDialog;
