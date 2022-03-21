// frmTestPaint.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CfrmTestPaint)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CfrmTestPaint dialog
class CfrmTestPaint : public CDialog
{
// Construction
public:
	CfrmTestPaint(CWnd* pParent = NULL);	// standard constructor

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
	static CfrmTestPaint *InstancePtr() {
		extern CfrmTestPaint *frmTestPaint;
		if (!frmTestPaint) frmTestPaint = new CfrmTestPaint();
		return frmTestPaint;
	}

// Dialog Data
	enum { IDD = IDDfrmTestPaint };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CfrmTestPaint)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnoptTools_16();
	afx_msg void OnoptTools_17();
	afx_msg void OnoptTools_15();
	afx_msg void OnoptTools_14();
	afx_msg void OnoptTools_13();
	afx_msg void OnoptTools_12();
	afx_msg void OnoptTools_11();
	afx_msg void OnoptTools_10();
	afx_msg void OnoptTools_2();
	afx_msg void OnoptTools_4();
	afx_msg void OnoptTools_5();
	afx_msg void OnoptTools_3();
	afx_msg void OnoptTools_7();
	afx_msg void OnoptTools_6();
	afx_msg void OnoptTools_8();
	afx_msg void OnoptTools_9();
	afx_msg void OnoptTools_0();
	afx_msg void OnoptTools_1();
	afx_msg void OnimgBrush_9();
	afx_msg void OnimgBrush_8();
	afx_msg void OnimgBrush_1();
	afx_msg void OnimgBrush_0();
	afx_msg void OnimgBrush_3();
	afx_msg void OnimgBrush_2();
	afx_msg void OnimgBrush_6();
	afx_msg void OnimgBrush_7();
	afx_msg void OnimgBrush_5();
	afx_msg void OnimgBrush_4();
	afx_msg void OnlblColor_25();
	afx_msg void OnlblColor_24();
	afx_msg void OnlblColor_23();
	afx_msg void OnlblColor_22();
	afx_msg void OnlblColor_21();
	afx_msg void OnlblColor_20();
	afx_msg void OnlblColor_19();
	afx_msg void OnlblColor_18();
	afx_msg void OnlblColor_17();
	afx_msg void OnlblColor_16();
	afx_msg void OnlblColor_15();
	afx_msg void OnlblColor_14();
	afx_msg void OnlblColor_13();
	afx_msg void OnlblColor_12();
	afx_msg void OnlblColor_11();
	afx_msg void OnlblColor_10();
	afx_msg void OnlblColor_9();
	afx_msg void OnlblColor_8();
	afx_msg void OnlblColor_7();
	afx_msg void OnlblColor_6();
	afx_msg void OnlblColor_5();
	afx_msg void OnlblColor_4();
	afx_msg void OnlblColor_3();
	afx_msg void OnlblColor_2();
	afx_msg void OnlblColor_1();
	afx_msg void OnlblColor_0();
	afx_msg void OnlblForeColor();
	afx_msg void OnlblFillColor();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CfrmTestPaint)
	CButton	m_fraColor;
	CStatic	m_lblColor_0;
	CStatic	m_lblColor_1;
	CStatic	m_label3;
	CStatic	m_lblFillColor;
	CStatic	m_lblForeColor;
	CStatic	m_lblColor_2;
	CStatic	m_lblColor_3;
	CStatic	m_lblColor_4;
	CStatic	m_lblColor_5;
	CStatic	m_lblColor_6;
	CStatic	m_lblColor_7;
	CStatic	m_lblColor_8;
	CStatic	m_lblColor_9;
	CStatic	m_lblColor_10;
	CStatic	m_lblColor_11;
	CStatic	m_lblColor_12;
	CStatic	m_lblColor_13;
	CStatic	m_lblColor_14;
	CStatic	m_lblColor_15;
	CStatic	m_lblColor_16;
	CStatic	m_lblColor_17;
	CStatic	m_lblColor_18;
	CStatic	m_lblColor_19;
	CStatic	m_lblColor_20;
	CStatic	m_lblColor_21;
	CStatic	m_lblColor_22;
	CStatic	m_lblColor_23;
	CStatic	m_lblColor_24;
	CStatic	m_lblColor_25;
	CButton	m_fraTools;
	CButton	m_fraOptFill;
	CStatic	m_shpRect_2;
	CStatic	m_shpRect_1;
	CStatic	m_shpRect_0;
	CStatic	m_lblFill;
	CButton	m_fraBrush;
	CStatic	m_imgBrush_4;
	CStatic	m_imgBrush_5;
	CStatic	m_imgBrush_7;
	CStatic	m_imgBrush_6;
	CStatic	m_imgBrush_2;
	CStatic	m_imgBrush_3;
	CStatic	m_imgBrush_0;
	CStatic	m_lblBrush;
	CStatic	m_imgBrush_1;
	CStatic	m_imgBrush_8;
	CStatic	m_imgBrush_9;
	CButton	m_fraOptDot;
	CStatic	m_shpDot_7;
	CStatic	m_shpDot_6;
	CStatic	m_shpDot_5;
	CStatic	m_shpDot_4;
	CStatic	m_shpDot_3;
	CStatic	m_shpDot_2;
	CStatic	m_shpDot_1;
	CStatic	m_shpDot_0;
	CStatic	m_lblDot;
	CButton	m_optTools_1;
	CButton	m_optTools_0;
	CButton	m_optTools_9;
	CButton	m_optTools_8;
	CButton	m_optTools_6;
	CButton	m_optTools_7;
	CButton	m_optTools_3;
	CButton	m_optTools_5;
	CButton	m_optTools_4;
	CButton	m_optTools_2;
	CButton	m_optTools_10;
	CButton	m_optTools_11;
	CButton	m_optTools_12;
	CButton	m_optTools_13;
	CButton	m_optTools_14;
	CButton	m_optTools_15;
	CButton	m_optTools_17;
	CButton	m_optTools_16;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CfrmTestPaint)

public:	
	CButton *m_optTools[18];
	CStatic *m_shpDot[8];
	CStatic *m_imgBrush[10];
	CStatic *m_shpRect[3];
	CStatic *m_lblColor[26];
	
	CToolTipCtrl	m_tooltip;
	CBitmap	Bmp_optTools_1;
	CBitmap	Bmp_optTools_0;
	CBitmap	Bmp_optTools_9;
	CBitmap	Bmp_optTools_8;
	CBitmap	Bmp_optTools_6;
	CBitmap	Bmp_optTools_7;
	CBitmap	Bmp_optTools_3;
	CBitmap	Bmp_optTools_5;
	CBitmap	Bmp_optTools_4;
	CBitmap	Bmp_optTools_2;
	CBitmap	Bmp_optTools_11;
	CBitmap	Bmp_optTools_12;
	CBitmap	Bmp_optTools_13;
	CBitmap	Bmp_optTools_14;
	CBitmap	Bmp_optTools_15;
	CBitmap	Bmp_optTools_17;
	CBitmap	Bmp_optTools_16;
	
	VBtoFontAttribute fm_lblColor_0, fm_lblColor_1, fm_label3, fm_lblFillColor, fm_lblForeColor, fm_lblColor_2;
	VBtoFontAttribute fm_lblColor_3, fm_lblColor_4, fm_lblColor_5, fm_lblColor_6, fm_lblColor_7, fm_lblColor_8;
	VBtoFontAttribute fm_lblColor_9, fm_lblColor_10, fm_lblColor_11, fm_lblColor_12, fm_lblColor_13;
	VBtoFontAttribute fm_lblColor_14, fm_lblColor_15, fm_lblColor_16, fm_lblColor_17, fm_lblColor_18;
	VBtoFontAttribute fm_lblColor_19, fm_lblColor_20, fm_lblColor_21, fm_lblColor_22, fm_lblColor_23;
	VBtoFontAttribute fm_lblColor_24, fm_lblColor_25, fm_shpRect_0, fm_lblBrush, fm_lblDot;
	void optTools_(short Index);
	void imgBrush_(short Index);
	void lblColor_(short Index);
	//}}VBto_Converter_Class_Public

};

extern CfrmTestPaint *frmTestPaint;
