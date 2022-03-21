// Form1.h : header file
//

#pragma once
#include "afxwin.h"

//{{VBto_Converter_Class_Global(CForm1)
#include "VBto_Converter.h"
//}}VBto_Converter_Class_Global


// CForm1 dialog
class CForm1 : public CDialog
{
// Construction
public:
	CForm1(CWnd* pParent = NULL);	// standard constructor

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
	static CForm1 *InstancePtr() {
		extern CForm1 *Form1;
		if (!Form1) Form1 = new CForm1();
		return Form1;
	}

// Dialog Data
	enum { IDD = IDDForm1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CForm1)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	afx_msg void OnCommandIndex_7();
	afx_msg void OnCommandIndex_5();
	afx_msg void OnCommandIndex_0();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//{{AFX_DATA(CForm1)
	CStatic	m_Shape1;
	CStatic	m_Line1;
	CStatic	m_Line2;
	CStatic	m_Image1;
	CStatic	m_Label2;
	CStatic	m_Label1_0;
	CButton	m_Frame1;
	CStatic	m_Label1_1;
	CEdit	m_Text1_1;
	CButton	m_Option1;
	CButton	m_Option2;
	CButton	m_Check1;
	CButton	m_Frame2;
	CButton	m_Command2;
	CButton	m_Option22;
	CButton	m_Option21;
	CButton	m_Option23;
	CButton	m_Check2;
	CButton	m_Check3;
	CButton	m_Command1;
	CComboBox	m_Combo1;
	CListBox	m_List1;
	CScrollBar	m_HScroll1;
	CScrollBar	m_VScroll1;
	CButton	m_Command3;
	CStatic	m_Picture1;
	CEdit	m_Text1_0;
	CButton	m_CommandIndex_0;
	CButton	m_CommandIndex_5;
	CButton	m_CommandIndex_7;
	//}}AFX_DATA

	//{{VBto_Converter_Class_Public(CForm1)

public:	
	CButton *m_CommandIndex[8];
	CEdit *m_Text1[2];
	CStatic *m_Label1[2];
	
	CToolTipCtrl	m_tooltip;
	VBtoTimer Timer1;
	CBitmap	Bmp_Command3;
	
	VBtoFontAttribute fm_Label2, fm_Label1_0, fm_Frame2;
	void Form_Load();
	void Form_Unload(short& Cancel);
	void testSub1(float valSinglePar1 /* , Clipboard xz1 */ , short refIntegerPar2, CButton* xz2, CString refStringPar3);
	void testSub2(double refDoublePar1, double refDoublePar2 /* , Clipboard xz1 */ , int refLongPar2, CButton* xz2, CString refStringPar3);
	void testSub3(CVBtoArray <float> &refSingleM);
	bool testFunBool(bool p);
	short testFunInt(CVBtoArray <short> &p);
	int testFunLong(int p);
	float testFunSingle(float p);
	double testFunDouble(double p);
	BYTE testFunByte(BYTE p);
	CString testFunString(CString p);
	DATE testFunDate(DATE p);
	double testFunCurrency(double p);
	CWnd* testFunControl(CWnd* p);
	CObject* testFunObject(CObject* p);
	void CommandIndex_(short Index);
//0	Collection testFunXZ1(CVBtoArrayPtr <Collection> &mColl);
	CDialog* TestForm(CDialog *p);
	CStatic* TestLabel(CStatic* p);
	CEdit* TestTextBox(CEdit* p);
	CListBox* TestListBox(CListBox* p);
	CComboBox* TestComboBox(CComboBox* p);
	CButton* TestCommandButton(CButton* p);
	CButton* TestCheckBox(CButton* p);
	CButton* TestOptionButton(CButton* p);
	CButton* TestFrame(CButton* p);
	CScrollBar* TestHScrollBar(CScrollBar* p);
	CScrollBar* TestVScrollBar(CScrollBar* p);
	CSliderCtrl* TestSlider(CSliderCtrl* p);
	CListCtrl* TestListView(CListCtrl* p);
	CTreeCtrl* TestTreeView(CTreeCtrl* p);
	CProgressCtrl* TestProgressBar(CProgressCtrl* p);
	CStatusBarCtrl* TestStatusBar(CStatusBarCtrl* p);
	int* TestTimer(int* p);
	CComboBox* TestDriveListBox(CComboBox* p);
	CListBox* TestDirListBox(CListBox* p);
	CListBox* TestFileListBox(CListBox* p);
	CToolBarCtrl* TestToolbar(CToolBarCtrl* p);
	CImageList* TestImageList(CImageList* p);
	CStatic* TestPictureBox(CStatic* p);
	CStatic* TestImage(CStatic* p);
	CSpinButtonCtrl* TestUpDown(CSpinButtonCtrl* p);
	//}}VBto_Converter_Class_Public

};

extern CForm1 *Form1;
