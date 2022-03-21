// Form1.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CForm1)
//}}VBto_Converter_Includes

#include "Form1.h"
CForm1 *Form1 = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CForm1 dialog



CForm1::CForm1(CWnd* pParent /*=NULL*/)
	: CDialog(CForm1::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!Form1) Form1 = this;
}

void CForm1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CForm1)
	DDX_Control(pDX, Shape1, m_Shape1);
	DDX_Control(pDX, Line1, m_Line1);
	DDX_Control(pDX, Line2, m_Line2);
	DDX_Control(pDX, Image1, m_Image1);
	DDX_Control(pDX, Label2, m_Label2);
	DDX_Control(pDX, Label1_0, m_Label1_0);
	DDX_Control(pDX, Frame1, m_Frame1);
	DDX_Control(pDX, Label1_1, m_Label1_1);
	DDX_Control(pDX, Text1_1, m_Text1_1);
	DDX_Control(pDX, Option1, m_Option1);
	DDX_Control(pDX, Option2, m_Option2);
	DDX_Control(pDX, Check1, m_Check1);
	DDX_Control(pDX, Frame2, m_Frame2);
	DDX_Control(pDX, Command2, m_Command2);
	DDX_Control(pDX, Option22, m_Option22);
	DDX_Control(pDX, Option21, m_Option21);
	DDX_Control(pDX, Option23, m_Option23);
	DDX_Control(pDX, Check2, m_Check2);
	DDX_Control(pDX, Check3, m_Check3);
	DDX_Control(pDX, Command1, m_Command1);
	DDX_Control(pDX, Combo1, m_Combo1);
	DDX_Control(pDX, List1, m_List1);
	DDX_Control(pDX, HScroll1, m_HScroll1);
	DDX_Control(pDX, VScroll1, m_VScroll1);
	DDX_Control(pDX, Command3, m_Command3);
	DDX_Control(pDX, Picture1, m_Picture1);
	DDX_Control(pDX, Text1_0, m_Text1_0);
	DDX_Control(pDX, CommandIndex_0, m_CommandIndex_0);
	DDX_Control(pDX, CommandIndex_5, m_CommandIndex_5);
	DDX_Control(pDX, CommandIndex_7, m_CommandIndex_7);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CForm1, CDialog)
	//{{AFX_MSG_MAP(CForm1)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_BN_CLICKED(CommandIndex_7, OnCommandIndex_7)
	ON_BN_CLICKED(CommandIndex_5, OnCommandIndex_5)
	ON_BN_CLICKED(CommandIndex_0, OnCommandIndex_0)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CForm1 message handlers

BOOL CForm1::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CForm1)
	
	ZeroMemory(m_CommandIndex, sizeof(m_CommandIndex));
	m_CommandIndex[7] = &m_CommandIndex_7;
	m_CommandIndex[5] = &m_CommandIndex_5;
	m_CommandIndex[0] = &m_CommandIndex_0;
	
	ZeroMemory(m_Text1, sizeof(m_Text1));
	m_Text1[0] = &m_Text1_0;
	m_Text1[1] = &m_Text1_1;
	
	ZeroMemory(m_Label1, sizeof(m_Label1));
	m_Label1[1] = &m_Label1_1;
	m_Label1[0] = &m_Label1_0;
	m_Text1_1	.SetWindowText("Text1(1).Text");
	m_Option1	.SetCheck(BST_CHECKED);
	m_Option22	.SetCheck(BST_CHECKED);
	m_Check2	.SetCheck(BST_CHECKED);
	m_Check3	.SetCheck(BST_INDETERMINATE);
	m_tooltip	.Create(this);
	m_tooltip	.Activate(TRUE);
	m_tooltip	.AddTool(&m_Command1, "Hello");
	m_Combo1	.SetWindowText("ComboBox.  Click Me !!!");
	m_Combo1	.AddString("ComboBox Item 1");
	m_Combo1	.AddString("ComboBox Item 2");
	m_Combo1	.AddString("ComboBox Item 3");
	
	m_List1	.AddString("ListBox Item 1");
	m_List1	.AddString("ListBox Item 2");
	m_List1	.AddString("ListBox Item 3");
	
	{
	SCROLLINFO si;	si.cbSize=sizeof(SCROLLINFO);
	si.nMin=20;	si.nMax=99;
	si.nPos=40;
	si.fMask = SIF_RANGE | SIF_POS;
	m_HScroll1.SetScrollInfo(&si);
	}
	{
	SCROLLINFO si;	si.cbSize=sizeof(SCROLLINFO);
	si.nMin=20;	si.nMax=99;
	si.nPos=40;
	si.fMask = SIF_RANGE | SIF_POS;
	m_VScroll1.SetScrollInfo(&si);
	}
	Timer1.Set(m_hWnd, IDC_Timer1, 12000, true);
	Bmp_Command3	.LoadBitmap(Form1_Command3);
	m_Command3	.SetBitmap((HBITMAP)Bmp_Command3.GetSafeHandle());
	
	m_Text1_0	.SetWindowText("Text1(0).Text");
	
	fm_Label2.Set(GetDlgItem(Label2), GetSysColor(COLOR_INFOBK), GetSysColor(COLOR_BTNFACE),"MS Sans Serif",9.75,true,false,false,false,RUSSIAN_CHARSET);
	fm_Label1_0.Set(GetDlgItem(Label1_0), RGB(192,0,0), GetSysColor(COLOR_BTNFACE),"MS Sans Serif",9.75,true,true,false,false,RUSSIAN_CHARSET);
	fm_Frame2.Set(GetDlgItem(Frame2), GetSysColor(COLOR_BTNTEXT), RGB(192,255,192));
	
	
	Form_Load();
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CForm1::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this); // device context for painting


		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CForm1::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================

void CForm1::Form_Load()
{
	// MsgBox "Event Form_Load"
}

void CForm1::Form_Unload(short& Cancel)
{
	// MsgBox "Event Form_Unload"
}

void CForm1::OnClose()
{
	short Cancel = 0;

	Form_Unload(Cancel);
	if (!Cancel) CDialog::OnClose();	// OnOK();
}

// -----------------------------------------------------------
//#define defUse_testSub1
#ifdef defUse_testSub1
void CForm1::testSub1(float valSinglePar1 /* , Clipboard xz1 */ , short refIntegerPar2, CButton* xz2, CString refStringPar3)
{
}
#endif

//#define defUse_testSub2
#ifdef defUse_testSub2
void CForm1::testSub2(double refDoublePar1, double refDoublePar2 /* , Clipboard xz1 */ , int refLongPar2, CButton* xz2, CString refStringPar3)
{
}
#endif

//#define defUse_testSub3
#ifdef defUse_testSub3
void CForm1::testSub3(CVBtoArray <float> &refSingleM)
{
}
#endif

//#define defUse_testFunBool
#ifdef defUse_testFunBool
bool CForm1::testFunBool(bool p)
{
	bool testFunBool = false;
	return testFunBool;
}
#endif

//#define defUse_testFunInt
#ifdef defUse_testFunInt
short CForm1::testFunInt(CVBtoArray <short> &p)
{
	short testFunInt = 0;
	return testFunInt;
}
#endif

//#define defUse_testFunLong
#ifdef defUse_testFunLong
int CForm1::testFunLong(int p)
{
	int testFunLong = 0;
	return testFunLong;
}
#endif

//#define defUse_testFunSingle
#ifdef defUse_testFunSingle
float CForm1::testFunSingle(float p)
{
	float testFunSingle = 0;
	return testFunSingle;
}
#endif

//#define defUse_testFunDouble
#ifdef defUse_testFunDouble
double CForm1::testFunDouble(double p)
{
	double testFunDouble = 0;
	return testFunDouble;
}
#endif

//#define defUse_testFunByte
#ifdef defUse_testFunByte
BYTE CForm1::testFunByte(BYTE p)
{
	BYTE testFunByte = 0;
	return testFunByte;
}
#endif

//#define defUse_testFunString
#ifdef defUse_testFunString
CString CForm1::testFunString(CString p)
{
	CString testFunString;
	return testFunString;
}
#endif

//#define defUse_testFunDate
#ifdef defUse_testFunDate
DATE CForm1::testFunDate(DATE p)
{
	DATE testFunDate;
	return testFunDate;
}
#endif

//#define defUse_testFunCurrency
#ifdef defUse_testFunCurrency
double CForm1::testFunCurrency(double p)
{
	double testFunCurrency = 0;
	return testFunCurrency;
}
#endif

//#define defUse_testFunControl
#ifdef defUse_testFunControl
CWnd* CForm1::testFunControl(CWnd* p)
{
	CWnd* testFunControl = 0;
	return testFunControl;
}
#endif

//#define defUse_testFunObject
#ifdef defUse_testFunObject
CObject* CForm1::testFunObject(CObject* p)
{
	CObject* testFunObject = 0;
	return testFunObject;
}
#endif

void CForm1::CommandIndex_(short Index)
{
	// TODO: Add your control notification handler code here
	// 
}
void CForm1::OnCommandIndex_7()
{
	// TODO: Add your control notification handler code here
	CommandIndex_(7);
}
void CForm1::OnCommandIndex_5()
{
	// TODO: Add your control notification handler code here
	CommandIndex_(5);
}
void CForm1::OnCommandIndex_0()
{
	// TODO: Add your control notification handler code here
	CommandIndex_(0);
}

// =========================

//#define defUse_testFunXZ1
#ifdef defUse_testFunXZ1
Collection CForm1::testFunXZ1(CVBtoArrayPtr <Collection> &mColl)
{
	Collection testFunXZ1 = 0;
	return testFunXZ1;
}
#endif

//#define defUse_TestForm
#ifdef defUse_TestForm
CDialog* CForm1::TestForm(CDialog *p)
{
	CDialog* TestForm = NULL;
	return TestForm;
}
#endif

//#define defUse_TestLabel
#ifdef defUse_TestLabel
CStatic* CForm1::TestLabel(CStatic* p)
{
	CStatic* TestLabel = NULL;
	return TestLabel;
}
#endif

//#define defUse_TestTextBox
#ifdef defUse_TestTextBox
CEdit* CForm1::TestTextBox(CEdit* p)
{
	CEdit* TestTextBox = NULL;
	return TestTextBox;
}
#endif

//#define defUse_TestListBox
#ifdef defUse_TestListBox
CListBox* CForm1::TestListBox(CListBox* p)
{
	CListBox* TestListBox = NULL;
	return TestListBox;
}
#endif

//#define defUse_TestComboBox
#ifdef defUse_TestComboBox
CComboBox* CForm1::TestComboBox(CComboBox* p)
{
	CComboBox* TestComboBox = NULL;
	return TestComboBox;
}
#endif

//#define defUse_TestCommandButton
#ifdef defUse_TestCommandButton
CButton* CForm1::TestCommandButton(CButton* p)
{
	CButton* TestCommandButton = NULL;
	return TestCommandButton;
}
#endif

//#define defUse_TestCheckBox
#ifdef defUse_TestCheckBox
CButton* CForm1::TestCheckBox(CButton* p)
{
	CButton* TestCheckBox = NULL;
	return TestCheckBox;
}
#endif

//#define defUse_TestOptionButton
#ifdef defUse_TestOptionButton
CButton* CForm1::TestOptionButton(CButton* p)
{
	CButton* TestOptionButton = NULL;
	return TestOptionButton;
}
#endif

//#define defUse_TestFrame
#ifdef defUse_TestFrame
CButton* CForm1::TestFrame(CButton* p)
{
	CButton* TestFrame = NULL;
	return TestFrame;
}
#endif

//#define defUse_TestHScrollBar
#ifdef defUse_TestHScrollBar
CScrollBar* CForm1::TestHScrollBar(CScrollBar* p)
{
	CScrollBar* TestHScrollBar = NULL;
	return TestHScrollBar;
}
#endif

//#define defUse_TestVScrollBar
#ifdef defUse_TestVScrollBar
CScrollBar* CForm1::TestVScrollBar(CScrollBar* p)
{
	CScrollBar* TestVScrollBar = NULL;
	return TestVScrollBar;
}
#endif

//#define defUse_TestSlider
#ifdef defUse_TestSlider
CSliderCtrl* CForm1::TestSlider(CSliderCtrl* p)
{
	CSliderCtrl* TestSlider = NULL;
	return TestSlider;
}
#endif

//#define defUse_TestListView
#ifdef defUse_TestListView
CListCtrl* CForm1::TestListView(CListCtrl* p)
{
	CListCtrl* TestListView = NULL;
	return TestListView;
}
#endif

//#define defUse_TestTreeView
#ifdef defUse_TestTreeView
CTreeCtrl* CForm1::TestTreeView(CTreeCtrl* p)
{
	CTreeCtrl* TestTreeView = NULL;
	return TestTreeView;
}
#endif

//#define defUse_TestProgressBar
#ifdef defUse_TestProgressBar
CProgressCtrl* CForm1::TestProgressBar(CProgressCtrl* p)
{
	CProgressCtrl* TestProgressBar = NULL;
	return TestProgressBar;
}
#endif

//#define defUse_TestStatusBar
#ifdef defUse_TestStatusBar
CStatusBarCtrl* CForm1::TestStatusBar(CStatusBarCtrl* p)
{
	CStatusBarCtrl* TestStatusBar = NULL;
	return TestStatusBar;
}
#endif

//#define defUse_TestTimer
#ifdef defUse_TestTimer
int* CForm1::TestTimer(int* p)
{
	int* TestTimer = NULL;
	return TestTimer;
}
#endif

//#define defUse_TestDriveListBox
#ifdef defUse_TestDriveListBox
CComboBox* CForm1::TestDriveListBox(CComboBox* p)
{
	CComboBox* TestDriveListBox = NULL;
	return TestDriveListBox;
}
#endif

//#define defUse_TestDirListBox
#ifdef defUse_TestDirListBox
CListBox* CForm1::TestDirListBox(CListBox* p)
{
	CListBox* TestDirListBox = NULL;
	return TestDirListBox;
}
#endif

//#define defUse_TestFileListBox
#ifdef defUse_TestFileListBox
CListBox* CForm1::TestFileListBox(CListBox* p)
{
	CListBox* TestFileListBox = NULL;
	return TestFileListBox;
}
#endif


//#define defUse_TestToolbar
#ifdef defUse_TestToolbar
CToolBarCtrl* CForm1::TestToolbar(CToolBarCtrl* p)
{
	CToolBarCtrl* TestToolbar = NULL;
	return TestToolbar;
}
#endif

//#define defUse_TestImageList
#ifdef defUse_TestImageList
CImageList* CForm1::TestImageList(CImageList* p)
{
	CImageList* TestImageList = NULL;
	return TestImageList;
}
#endif

//#define defUse_TestPictureBox
#ifdef defUse_TestPictureBox
CStatic* CForm1::TestPictureBox(CStatic* p)
{
	CStatic* TestPictureBox = NULL;
	return TestPictureBox;
}
#endif

//#define defUse_TestImage
#ifdef defUse_TestImage
CStatic* CForm1::TestImage(CStatic* p)
{
	CStatic* TestImage = NULL;
	return TestImage;
}
#endif

//#define defUse_TestUpDown
#ifdef defUse_TestUpDown
CSpinButtonCtrl* CForm1::TestUpDown(CSpinButtonCtrl* p)
{
	CSpinButtonCtrl* TestUpDown = NULL;
	return TestUpDown;
}
#endif


HBRUSH CForm1::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch(pWnd->GetDlgCtrlID()) {
		case Label2:	return fm_Label2	.OnCtlColor(pDC);
		case Label1_0:	return fm_Label1_0	.OnCtlColor(pDC);
		case Frame2:	return fm_Frame2	.OnCtlColor(pDC);
	}
	return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}
