// frmTestPaint.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestPaint)
//}}VBto_Converter_Includes

#include "frmTestPaint.h"
CfrmTestPaint *frmTestPaint = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestPaint dialog



CfrmTestPaint::CfrmTestPaint(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestPaint::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(frmTestPaint_Icon);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestPaint) frmTestPaint = this;
}

void CfrmTestPaint::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestPaint)
	DDX_Control(pDX, fraColor, m_fraColor);
	DDX_Control(pDX, lblColor_0, m_lblColor_0);
	DDX_Control(pDX, lblColor_1, m_lblColor_1);
	DDX_Control(pDX, label3, m_label3);
	DDX_Control(pDX, lblFillColor, m_lblFillColor);
	DDX_Control(pDX, lblForeColor, m_lblForeColor);
	DDX_Control(pDX, lblColor_2, m_lblColor_2);
	DDX_Control(pDX, lblColor_3, m_lblColor_3);
	DDX_Control(pDX, lblColor_4, m_lblColor_4);
	DDX_Control(pDX, lblColor_5, m_lblColor_5);
	DDX_Control(pDX, lblColor_6, m_lblColor_6);
	DDX_Control(pDX, lblColor_7, m_lblColor_7);
	DDX_Control(pDX, lblColor_8, m_lblColor_8);
	DDX_Control(pDX, lblColor_9, m_lblColor_9);
	DDX_Control(pDX, lblColor_10, m_lblColor_10);
	DDX_Control(pDX, lblColor_11, m_lblColor_11);
	DDX_Control(pDX, lblColor_12, m_lblColor_12);
	DDX_Control(pDX, lblColor_13, m_lblColor_13);
	DDX_Control(pDX, lblColor_14, m_lblColor_14);
	DDX_Control(pDX, lblColor_15, m_lblColor_15);
	DDX_Control(pDX, lblColor_16, m_lblColor_16);
	DDX_Control(pDX, lblColor_17, m_lblColor_17);
	DDX_Control(pDX, lblColor_18, m_lblColor_18);
	DDX_Control(pDX, lblColor_19, m_lblColor_19);
	DDX_Control(pDX, lblColor_20, m_lblColor_20);
	DDX_Control(pDX, lblColor_21, m_lblColor_21);
	DDX_Control(pDX, lblColor_22, m_lblColor_22);
	DDX_Control(pDX, lblColor_23, m_lblColor_23);
	DDX_Control(pDX, lblColor_24, m_lblColor_24);
	DDX_Control(pDX, lblColor_25, m_lblColor_25);
	DDX_Control(pDX, fraTools, m_fraTools);
	DDX_Control(pDX, fraOptFill, m_fraOptFill);
	DDX_Control(pDX, shpRect_2, m_shpRect_2);
	DDX_Control(pDX, shpRect_1, m_shpRect_1);
	DDX_Control(pDX, shpRect_0, m_shpRect_0);
	DDX_Control(pDX, lblFill, m_lblFill);
	DDX_Control(pDX, fraBrush, m_fraBrush);
	DDX_Control(pDX, imgBrush_4, m_imgBrush_4);
	DDX_Control(pDX, imgBrush_5, m_imgBrush_5);
	DDX_Control(pDX, imgBrush_7, m_imgBrush_7);
	DDX_Control(pDX, imgBrush_6, m_imgBrush_6);
	DDX_Control(pDX, imgBrush_2, m_imgBrush_2);
	DDX_Control(pDX, imgBrush_3, m_imgBrush_3);
	DDX_Control(pDX, imgBrush_0, m_imgBrush_0);
	DDX_Control(pDX, lblBrush, m_lblBrush);
	DDX_Control(pDX, imgBrush_1, m_imgBrush_1);
	DDX_Control(pDX, imgBrush_8, m_imgBrush_8);
	DDX_Control(pDX, imgBrush_9, m_imgBrush_9);
	DDX_Control(pDX, fraOptDot, m_fraOptDot);
	DDX_Control(pDX, shpDot_7, m_shpDot_7);
	DDX_Control(pDX, shpDot_6, m_shpDot_6);
	DDX_Control(pDX, shpDot_5, m_shpDot_5);
	DDX_Control(pDX, shpDot_4, m_shpDot_4);
	DDX_Control(pDX, shpDot_3, m_shpDot_3);
	DDX_Control(pDX, shpDot_2, m_shpDot_2);
	DDX_Control(pDX, shpDot_1, m_shpDot_1);
	DDX_Control(pDX, shpDot_0, m_shpDot_0);
	DDX_Control(pDX, lblDot, m_lblDot);
	DDX_Control(pDX, optTools_1, m_optTools_1);
	DDX_Control(pDX, optTools_0, m_optTools_0);
	DDX_Control(pDX, optTools_9, m_optTools_9);
	DDX_Control(pDX, optTools_8, m_optTools_8);
	DDX_Control(pDX, optTools_6, m_optTools_6);
	DDX_Control(pDX, optTools_7, m_optTools_7);
	DDX_Control(pDX, optTools_3, m_optTools_3);
	DDX_Control(pDX, optTools_5, m_optTools_5);
	DDX_Control(pDX, optTools_4, m_optTools_4);
	DDX_Control(pDX, optTools_2, m_optTools_2);
	DDX_Control(pDX, optTools_10, m_optTools_10);
	DDX_Control(pDX, optTools_11, m_optTools_11);
	DDX_Control(pDX, optTools_12, m_optTools_12);
	DDX_Control(pDX, optTools_13, m_optTools_13);
	DDX_Control(pDX, optTools_14, m_optTools_14);
	DDX_Control(pDX, optTools_15, m_optTools_15);
	DDX_Control(pDX, optTools_17, m_optTools_17);
	DDX_Control(pDX, optTools_16, m_optTools_16);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestPaint, CDialog)
	//{{AFX_MSG_MAP(CfrmTestPaint)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(optTools_16, OnoptTools_16)
	ON_BN_CLICKED(optTools_17, OnoptTools_17)
	ON_BN_CLICKED(optTools_15, OnoptTools_15)
	ON_BN_CLICKED(optTools_14, OnoptTools_14)
	ON_BN_CLICKED(optTools_13, OnoptTools_13)
	ON_BN_CLICKED(optTools_12, OnoptTools_12)
	ON_BN_CLICKED(optTools_11, OnoptTools_11)
	ON_BN_CLICKED(optTools_10, OnoptTools_10)
	ON_BN_CLICKED(optTools_2, OnoptTools_2)
	ON_BN_CLICKED(optTools_4, OnoptTools_4)
	ON_BN_CLICKED(optTools_5, OnoptTools_5)
	ON_BN_CLICKED(optTools_3, OnoptTools_3)
	ON_BN_CLICKED(optTools_7, OnoptTools_7)
	ON_BN_CLICKED(optTools_6, OnoptTools_6)
	ON_BN_CLICKED(optTools_8, OnoptTools_8)
	ON_BN_CLICKED(optTools_9, OnoptTools_9)
	ON_BN_CLICKED(optTools_0, OnoptTools_0)
	ON_BN_CLICKED(optTools_1, OnoptTools_1)
	ON_BN_CLICKED(imgBrush_9, OnimgBrush_9)
	ON_BN_CLICKED(imgBrush_8, OnimgBrush_8)
	ON_BN_CLICKED(imgBrush_1, OnimgBrush_1)
	ON_BN_CLICKED(imgBrush_0, OnimgBrush_0)
	ON_BN_CLICKED(imgBrush_3, OnimgBrush_3)
	ON_BN_CLICKED(imgBrush_2, OnimgBrush_2)
	ON_BN_CLICKED(imgBrush_6, OnimgBrush_6)
	ON_BN_CLICKED(imgBrush_7, OnimgBrush_7)
	ON_BN_CLICKED(imgBrush_5, OnimgBrush_5)
	ON_BN_CLICKED(imgBrush_4, OnimgBrush_4)
	ON_BN_CLICKED(lblColor_25, OnlblColor_25)
	ON_BN_CLICKED(lblColor_24, OnlblColor_24)
	ON_BN_CLICKED(lblColor_23, OnlblColor_23)
	ON_BN_CLICKED(lblColor_22, OnlblColor_22)
	ON_BN_CLICKED(lblColor_21, OnlblColor_21)
	ON_BN_CLICKED(lblColor_20, OnlblColor_20)
	ON_BN_CLICKED(lblColor_19, OnlblColor_19)
	ON_BN_CLICKED(lblColor_18, OnlblColor_18)
	ON_BN_CLICKED(lblColor_17, OnlblColor_17)
	ON_BN_CLICKED(lblColor_16, OnlblColor_16)
	ON_BN_CLICKED(lblColor_15, OnlblColor_15)
	ON_BN_CLICKED(lblColor_14, OnlblColor_14)
	ON_BN_CLICKED(lblColor_13, OnlblColor_13)
	ON_BN_CLICKED(lblColor_12, OnlblColor_12)
	ON_BN_CLICKED(lblColor_11, OnlblColor_11)
	ON_BN_CLICKED(lblColor_10, OnlblColor_10)
	ON_BN_CLICKED(lblColor_9, OnlblColor_9)
	ON_BN_CLICKED(lblColor_8, OnlblColor_8)
	ON_BN_CLICKED(lblColor_7, OnlblColor_7)
	ON_BN_CLICKED(lblColor_6, OnlblColor_6)
	ON_BN_CLICKED(lblColor_5, OnlblColor_5)
	ON_BN_CLICKED(lblColor_4, OnlblColor_4)
	ON_BN_CLICKED(lblColor_3, OnlblColor_3)
	ON_BN_CLICKED(lblColor_2, OnlblColor_2)
	ON_BN_CLICKED(lblColor_1, OnlblColor_1)
	ON_BN_CLICKED(lblColor_0, OnlblColor_0)
	ON_BN_CLICKED(lblForeColor, OnlblForeColor)
	ON_BN_CLICKED(lblFillColor, OnlblFillColor)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestPaint message handlers

BOOL CfrmTestPaint::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestPaint)
	
	ZeroMemory(m_optTools, sizeof(m_optTools));
	m_optTools[16] = &m_optTools_16;
	m_optTools[17] = &m_optTools_17;
	m_optTools[15] = &m_optTools_15;
	m_optTools[14] = &m_optTools_14;
	m_optTools[13] = &m_optTools_13;
	m_optTools[12] = &m_optTools_12;
	m_optTools[11] = &m_optTools_11;
	m_optTools[10] = &m_optTools_10;
	m_optTools[2] = &m_optTools_2;
	m_optTools[4] = &m_optTools_4;
	m_optTools[5] = &m_optTools_5;
	m_optTools[3] = &m_optTools_3;
	m_optTools[7] = &m_optTools_7;
	m_optTools[6] = &m_optTools_6;
	m_optTools[8] = &m_optTools_8;
	m_optTools[9] = &m_optTools_9;
	m_optTools[0] = &m_optTools_0;
	m_optTools[1] = &m_optTools_1;
	
	ZeroMemory(m_shpDot, sizeof(m_shpDot));
	m_shpDot[0] = &m_shpDot_0;
	m_shpDot[1] = &m_shpDot_1;
	m_shpDot[2] = &m_shpDot_2;
	m_shpDot[3] = &m_shpDot_3;
	m_shpDot[4] = &m_shpDot_4;
	m_shpDot[5] = &m_shpDot_5;
	m_shpDot[6] = &m_shpDot_6;
	m_shpDot[7] = &m_shpDot_7;
	
	ZeroMemory(m_imgBrush, sizeof(m_imgBrush));
	m_imgBrush[9] = &m_imgBrush_9;
	m_imgBrush[8] = &m_imgBrush_8;
	m_imgBrush[1] = &m_imgBrush_1;
	m_imgBrush[0] = &m_imgBrush_0;
	m_imgBrush[3] = &m_imgBrush_3;
	m_imgBrush[2] = &m_imgBrush_2;
	m_imgBrush[6] = &m_imgBrush_6;
	m_imgBrush[7] = &m_imgBrush_7;
	m_imgBrush[5] = &m_imgBrush_5;
	m_imgBrush[4] = &m_imgBrush_4;
	
	ZeroMemory(m_shpRect, sizeof(m_shpRect));
	m_shpRect[0] = &m_shpRect_0;
	m_shpRect[1] = &m_shpRect_1;
	m_shpRect[2] = &m_shpRect_2;
	
	ZeroMemory(m_lblColor, sizeof(m_lblColor));
	m_lblColor[25] = &m_lblColor_25;
	m_lblColor[24] = &m_lblColor_24;
	m_lblColor[23] = &m_lblColor_23;
	m_lblColor[22] = &m_lblColor_22;
	m_lblColor[21] = &m_lblColor_21;
	m_lblColor[20] = &m_lblColor_20;
	m_lblColor[19] = &m_lblColor_19;
	m_lblColor[18] = &m_lblColor_18;
	m_lblColor[17] = &m_lblColor_17;
	m_lblColor[16] = &m_lblColor_16;
	m_lblColor[15] = &m_lblColor_15;
	m_lblColor[14] = &m_lblColor_14;
	m_lblColor[13] = &m_lblColor_13;
	m_lblColor[12] = &m_lblColor_12;
	m_lblColor[11] = &m_lblColor_11;
	m_lblColor[10] = &m_lblColor_10;
	m_lblColor[9] = &m_lblColor_9;
	m_lblColor[8] = &m_lblColor_8;
	m_lblColor[7] = &m_lblColor_7;
	m_lblColor[6] = &m_lblColor_6;
	m_lblColor[5] = &m_lblColor_5;
	m_lblColor[4] = &m_lblColor_4;
	m_lblColor[3] = &m_lblColor_3;
	m_lblColor[2] = &m_lblColor_2;
	m_lblColor[1] = &m_lblColor_1;
	m_lblColor[0] = &m_lblColor_0;
	m_tooltip	.Create(this);
	m_tooltip	.Activate(TRUE);
	m_tooltip	.AddTool(&m_optTools_1, "Pick Color");
	Bmp_optTools_1	.LoadBitmap(frmTestPaint_optTools_1);
	m_optTools_1	.SetBitmap((HBITMAP)Bmp_optTools_1.GetSafeHandle());
	
	m_tooltip	.AddTool(&m_optTools_0, "Select Area");
	Bmp_optTools_0	.LoadBitmap(frmTestPaint_optTools_0);
	m_optTools_0	.SetBitmap((HBITMAP)Bmp_optTools_0.GetSafeHandle());
	
	m_tooltip	.AddTool(&m_optTools_9, "Arrow");
	Bmp_optTools_9	.LoadBitmap(frmTestPaint_optTools_9);
	m_optTools_9	.SetBitmap((HBITMAP)Bmp_optTools_9.GetSafeHandle());
	
	m_tooltip	.AddTool(&m_optTools_8, "Text");
	Bmp_optTools_8	.LoadBitmap(frmTestPaint_optTools_8);
	m_optTools_8	.SetBitmap((HBITMAP)Bmp_optTools_8.GetSafeHandle());
	
	m_tooltip	.AddTool(&m_optTools_6, "Rectangle");
	Bmp_optTools_6	.LoadBitmap(frmTestPaint_optTools_6);
	m_optTools_6	.SetBitmap((HBITMAP)Bmp_optTools_6.GetSafeHandle());
	
	m_tooltip	.AddTool(&m_optTools_7, "Ellipse");
	Bmp_optTools_7	.LoadBitmap(frmTestPaint_optTools_7);
	m_optTools_7	.SetBitmap((HBITMAP)Bmp_optTools_7.GetSafeHandle());
	
	m_tooltip	.AddTool(&m_optTools_3, "Fill");
	Bmp_optTools_3	.LoadBitmap(frmTestPaint_optTools_3);
	m_optTools_3	.SetBitmap((HBITMAP)Bmp_optTools_3.GetSafeHandle());
	
	m_tooltip	.AddTool(&m_optTools_5, "Line");
	Bmp_optTools_5	.LoadBitmap(frmTestPaint_optTools_5);
	m_optTools_5	.SetBitmap((HBITMAP)Bmp_optTools_5.GetSafeHandle());
	
	m_tooltip	.AddTool(&m_optTools_4, "Pencil");
	Bmp_optTools_4	.LoadBitmap(frmTestPaint_optTools_4);
	m_optTools_4	.SetBitmap((HBITMAP)Bmp_optTools_4.GetSafeHandle());
	
	m_optTools_4	.SetCheck(BST_CHECKED);
	m_tooltip	.AddTool(&m_optTools_2, "Eraser");
	Bmp_optTools_2	.LoadBitmap(frmTestPaint_optTools_2);
	m_optTools_2	.SetBitmap((HBITMAP)Bmp_optTools_2.GetSafeHandle());
	
	m_tooltip	.AddTool(&m_optTools_10, "Air Brush");
	m_optTools_10	.SetIcon(AfxGetApp()->LoadIcon(frmTestPaint_optTools_10));
	m_tooltip	.AddTool(&m_optTools_11, "Rounded Rectangle");
	Bmp_optTools_11	.LoadBitmap(frmTestPaint_optTools_11);
	m_optTools_11	.SetBitmap((HBITMAP)Bmp_optTools_11.GetSafeHandle());
	
	m_tooltip	.AddTool(&m_optTools_12, "Polygon");
	Bmp_optTools_12	.LoadBitmap(frmTestPaint_optTools_12);
	m_optTools_12	.SetBitmap((HBITMAP)Bmp_optTools_12.GetSafeHandle());
	
	m_tooltip	.AddTool(&m_optTools_13, "Curve");
	Bmp_optTools_13	.LoadBitmap(frmTestPaint_optTools_13);
	m_optTools_13	.SetBitmap((HBITMAP)Bmp_optTools_13.GetSafeHandle());
	
	m_tooltip	.AddTool(&m_optTools_14, "Filter Brush");
	Bmp_optTools_14	.LoadBitmap(frmTestPaint_optTools_14);
	m_optTools_14	.SetBitmap((HBITMAP)Bmp_optTools_14.GetSafeHandle());
	
	m_tooltip	.AddTool(&m_optTools_15, "Zoom");
	Bmp_optTools_15	.LoadBitmap(frmTestPaint_optTools_15);
	m_optTools_15	.SetBitmap((HBITMAP)Bmp_optTools_15.GetSafeHandle());
	
	m_tooltip	.AddTool(&m_optTools_17, "Hand");
	Bmp_optTools_17	.LoadBitmap(frmTestPaint_optTools_17);
	m_optTools_17	.SetBitmap((HBITMAP)Bmp_optTools_17.GetSafeHandle());
	
	m_tooltip	.AddTool(&m_optTools_16, "Brush");
	Bmp_optTools_16	.LoadBitmap(frmTestPaint_optTools_16);
	m_optTools_16	.SetBitmap((HBITMAP)Bmp_optTools_16.GetSafeHandle());
	
	
	fm_lblColor_0.Set(GetDlgItem(lblColor_0), GetSysColor(COLOR_BTNTEXT), RGB(0,0,0));
	fm_lblColor_1.Set(GetDlgItem(lblColor_1), GetSysColor(COLOR_BTNTEXT), RGB(255,255,255));
	fm_label3.Set(GetDlgItem(label3), GetSysColor(COLOR_BTNTEXT), RGB(224,224,224));
	fm_lblFillColor.Set(GetDlgItem(lblFillColor), GetSysColor(COLOR_BTNTEXT), RGB(255,255,255));
	fm_lblForeColor.Set(GetDlgItem(lblForeColor), GetSysColor(COLOR_BTNTEXT), RGB(0,0,0));
	fm_lblColor_2.Set(GetDlgItem(lblColor_2), GetSysColor(COLOR_BTNTEXT), RGB(128,128,128));
	fm_lblColor_3.Set(GetDlgItem(lblColor_3), GetSysColor(COLOR_BTNTEXT), RGB(192,192,192));
	fm_lblColor_4.Set(GetDlgItem(lblColor_4), GetSysColor(COLOR_BTNTEXT), RGB(128,0,0));
	fm_lblColor_5.Set(GetDlgItem(lblColor_5), GetSysColor(COLOR_BTNTEXT), RGB(255,0,0));
	fm_lblColor_6.Set(GetDlgItem(lblColor_6), GetSysColor(COLOR_BTNTEXT), RGB(128,128,0));
	fm_lblColor_7.Set(GetDlgItem(lblColor_7), GetSysColor(COLOR_BTNTEXT), RGB(255,255,0));
	fm_lblColor_8.Set(GetDlgItem(lblColor_8), GetSysColor(COLOR_BTNTEXT), RGB(0,128,0));
	fm_lblColor_9.Set(GetDlgItem(lblColor_9), GetSysColor(COLOR_BTNTEXT), RGB(0,255,0));
	fm_lblColor_10.Set(GetDlgItem(lblColor_10), GetSysColor(COLOR_BTNTEXT), RGB(0,128,128));
	fm_lblColor_11.Set(GetDlgItem(lblColor_11), GetSysColor(COLOR_BTNTEXT), RGB(0,255,255));
	fm_lblColor_12.Set(GetDlgItem(lblColor_12), GetSysColor(COLOR_BTNTEXT), RGB(0,0,128));
	fm_lblColor_13.Set(GetDlgItem(lblColor_13), GetSysColor(COLOR_BTNTEXT), RGB(0,0,255));
	fm_lblColor_14.Set(GetDlgItem(lblColor_14), GetSysColor(COLOR_BTNTEXT), RGB(128,0,128));
	fm_lblColor_15.Set(GetDlgItem(lblColor_15), GetSysColor(COLOR_BTNTEXT), RGB(255,0,255));
	fm_lblColor_16.Set(GetDlgItem(lblColor_16), GetSysColor(COLOR_BTNTEXT), RGB(64,64,0));
	fm_lblColor_17.Set(GetDlgItem(lblColor_17), GetSysColor(COLOR_BTNTEXT), RGB(255,255,192));
	fm_lblColor_18.Set(GetDlgItem(lblColor_18), GetSysColor(COLOR_BTNTEXT), RGB(0,64,0));
	fm_lblColor_19.Set(GetDlgItem(lblColor_19), GetSysColor(COLOR_BTNTEXT), RGB(128,255,128));
	fm_lblColor_20.Set(GetDlgItem(lblColor_20), GetSysColor(COLOR_BTNTEXT), RGB(128,128,255));
	fm_lblColor_21.Set(GetDlgItem(lblColor_21), GetSysColor(COLOR_BTNTEXT), RGB(192,255,255));
	fm_lblColor_22.Set(GetDlgItem(lblColor_22), GetSysColor(COLOR_BTNTEXT), RGB(64,0,64));
	fm_lblColor_23.Set(GetDlgItem(lblColor_23), GetSysColor(COLOR_BTNTEXT), RGB(255,128,255));
	fm_lblColor_24.Set(GetDlgItem(lblColor_24), GetSysColor(COLOR_BTNTEXT), RGB(128,64,0));
	fm_lblColor_25.Set(GetDlgItem(lblColor_25), GetSysColor(COLOR_BTNTEXT), RGB(255,128,0));
	fm_shpRect_0.Set(GetDlgItem(shpRect_0), GetSysColor(COLOR_WINDOWTEXT), RGB(255,255,255));
	fm_lblBrush.Set(GetDlgItem(lblBrush), GetSysColor(COLOR_BTNTEXT), GetSysColor(COLOR_HIGHLIGHT));
	fm_lblDot.Set(GetDlgItem(lblDot), GetSysColor(COLOR_BTNTEXT), GetSysColor(COLOR_HIGHLIGHT));
	
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestPaint::OnPaint() 
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
HCURSOR CfrmTestPaint::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================

void CfrmTestPaint::optTools_(short Index)
{
	// TODO: Add your control notification handler code here
	// 
}
void CfrmTestPaint::OnoptTools_16()
{
	// TODO: Add your control notification handler code here
	optTools_(16);
}
void CfrmTestPaint::OnoptTools_17()
{
	// TODO: Add your control notification handler code here
	optTools_(17);
}
void CfrmTestPaint::OnoptTools_15()
{
	// TODO: Add your control notification handler code here
	optTools_(15);
}
void CfrmTestPaint::OnoptTools_14()
{
	// TODO: Add your control notification handler code here
	optTools_(14);
}
void CfrmTestPaint::OnoptTools_13()
{
	// TODO: Add your control notification handler code here
	optTools_(13);
}
void CfrmTestPaint::OnoptTools_12()
{
	// TODO: Add your control notification handler code here
	optTools_(12);
}
void CfrmTestPaint::OnoptTools_11()
{
	// TODO: Add your control notification handler code here
	optTools_(11);
}
void CfrmTestPaint::OnoptTools_10()
{
	// TODO: Add your control notification handler code here
	optTools_(10);
}
void CfrmTestPaint::OnoptTools_2()
{
	// TODO: Add your control notification handler code here
	optTools_(2);
}
void CfrmTestPaint::OnoptTools_4()
{
	// TODO: Add your control notification handler code here
	optTools_(4);
}
void CfrmTestPaint::OnoptTools_5()
{
	// TODO: Add your control notification handler code here
	optTools_(5);
}
void CfrmTestPaint::OnoptTools_3()
{
	// TODO: Add your control notification handler code here
	optTools_(3);
}
void CfrmTestPaint::OnoptTools_7()
{
	// TODO: Add your control notification handler code here
	optTools_(7);
}
void CfrmTestPaint::OnoptTools_6()
{
	// TODO: Add your control notification handler code here
	optTools_(6);
}
void CfrmTestPaint::OnoptTools_8()
{
	// TODO: Add your control notification handler code here
	optTools_(8);
}
void CfrmTestPaint::OnoptTools_9()
{
	// TODO: Add your control notification handler code here
	optTools_(9);
}
void CfrmTestPaint::OnoptTools_0()
{
	// TODO: Add your control notification handler code here
	optTools_(0);
}
void CfrmTestPaint::OnoptTools_1()
{
	// TODO: Add your control notification handler code here
	optTools_(1);
}

void CfrmTestPaint::imgBrush_(short Index)
{
	// TODO: Add your control notification handler code here
	// 
}
void CfrmTestPaint::OnimgBrush_9()
{
	// TODO: Add your control notification handler code here
	imgBrush_(9);
}
void CfrmTestPaint::OnimgBrush_8()
{
	// TODO: Add your control notification handler code here
	imgBrush_(8);
}
void CfrmTestPaint::OnimgBrush_1()
{
	// TODO: Add your control notification handler code here
	imgBrush_(1);
}
void CfrmTestPaint::OnimgBrush_0()
{
	// TODO: Add your control notification handler code here
	imgBrush_(0);
}
void CfrmTestPaint::OnimgBrush_3()
{
	// TODO: Add your control notification handler code here
	imgBrush_(3);
}
void CfrmTestPaint::OnimgBrush_2()
{
	// TODO: Add your control notification handler code here
	imgBrush_(2);
}
void CfrmTestPaint::OnimgBrush_6()
{
	// TODO: Add your control notification handler code here
	imgBrush_(6);
}
void CfrmTestPaint::OnimgBrush_7()
{
	// TODO: Add your control notification handler code here
	imgBrush_(7);
}
void CfrmTestPaint::OnimgBrush_5()
{
	// TODO: Add your control notification handler code here
	imgBrush_(5);
}
void CfrmTestPaint::OnimgBrush_4()
{
	// TODO: Add your control notification handler code here
	imgBrush_(4);
}

void CfrmTestPaint::lblColor_(short Index)
{
	// TODO: Add your control notification handler code here
	// 
}
void CfrmTestPaint::OnlblColor_25()
{
	// TODO: Add your control notification handler code here
	lblColor_(25);
}
void CfrmTestPaint::OnlblColor_24()
{
	// TODO: Add your control notification handler code here
	lblColor_(24);
}
void CfrmTestPaint::OnlblColor_23()
{
	// TODO: Add your control notification handler code here
	lblColor_(23);
}
void CfrmTestPaint::OnlblColor_22()
{
	// TODO: Add your control notification handler code here
	lblColor_(22);
}
void CfrmTestPaint::OnlblColor_21()
{
	// TODO: Add your control notification handler code here
	lblColor_(21);
}
void CfrmTestPaint::OnlblColor_20()
{
	// TODO: Add your control notification handler code here
	lblColor_(20);
}
void CfrmTestPaint::OnlblColor_19()
{
	// TODO: Add your control notification handler code here
	lblColor_(19);
}
void CfrmTestPaint::OnlblColor_18()
{
	// TODO: Add your control notification handler code here
	lblColor_(18);
}
void CfrmTestPaint::OnlblColor_17()
{
	// TODO: Add your control notification handler code here
	lblColor_(17);
}
void CfrmTestPaint::OnlblColor_16()
{
	// TODO: Add your control notification handler code here
	lblColor_(16);
}
void CfrmTestPaint::OnlblColor_15()
{
	// TODO: Add your control notification handler code here
	lblColor_(15);
}
void CfrmTestPaint::OnlblColor_14()
{
	// TODO: Add your control notification handler code here
	lblColor_(14);
}
void CfrmTestPaint::OnlblColor_13()
{
	// TODO: Add your control notification handler code here
	lblColor_(13);
}
void CfrmTestPaint::OnlblColor_12()
{
	// TODO: Add your control notification handler code here
	lblColor_(12);
}
void CfrmTestPaint::OnlblColor_11()
{
	// TODO: Add your control notification handler code here
	lblColor_(11);
}
void CfrmTestPaint::OnlblColor_10()
{
	// TODO: Add your control notification handler code here
	lblColor_(10);
}
void CfrmTestPaint::OnlblColor_9()
{
	// TODO: Add your control notification handler code here
	lblColor_(9);
}
void CfrmTestPaint::OnlblColor_8()
{
	// TODO: Add your control notification handler code here
	lblColor_(8);
}
void CfrmTestPaint::OnlblColor_7()
{
	// TODO: Add your control notification handler code here
	lblColor_(7);
}
void CfrmTestPaint::OnlblColor_6()
{
	// TODO: Add your control notification handler code here
	lblColor_(6);
}
void CfrmTestPaint::OnlblColor_5()
{
	// TODO: Add your control notification handler code here
	lblColor_(5);
}
void CfrmTestPaint::OnlblColor_4()
{
	// TODO: Add your control notification handler code here
	lblColor_(4);
}
void CfrmTestPaint::OnlblColor_3()
{
	// TODO: Add your control notification handler code here
	lblColor_(3);
}
void CfrmTestPaint::OnlblColor_2()
{
	// TODO: Add your control notification handler code here
	lblColor_(2);
}
void CfrmTestPaint::OnlblColor_1()
{
	// TODO: Add your control notification handler code here
	lblColor_(1);
}
void CfrmTestPaint::OnlblColor_0()
{
	// TODO: Add your control notification handler code here
	lblColor_(0);
}

void CfrmTestPaint::OnlblForeColor()
{
	// TODO: Add your control notification handler code here
	// 
}

void CfrmTestPaint::OnlblFillColor()
{
	// TODO: Add your control notification handler code here
	// 
}

HBRUSH CfrmTestPaint::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch(pWnd->GetDlgCtrlID()) {
		case lblColor_0:	return fm_lblColor_0	.OnCtlColor(pDC);
		case lblColor_1:	return fm_lblColor_1	.OnCtlColor(pDC);
		case label3:	return fm_label3	.OnCtlColor(pDC);
		case lblFillColor:	return fm_lblFillColor	.OnCtlColor(pDC);
		case lblForeColor:	return fm_lblForeColor	.OnCtlColor(pDC);
		case lblColor_2:	return fm_lblColor_2	.OnCtlColor(pDC);
		case lblColor_3:	return fm_lblColor_3	.OnCtlColor(pDC);
		case lblColor_4:	return fm_lblColor_4	.OnCtlColor(pDC);
		case lblColor_5:	return fm_lblColor_5	.OnCtlColor(pDC);
		case lblColor_6:	return fm_lblColor_6	.OnCtlColor(pDC);
		case lblColor_7:	return fm_lblColor_7	.OnCtlColor(pDC);
		case lblColor_8:	return fm_lblColor_8	.OnCtlColor(pDC);
		case lblColor_9:	return fm_lblColor_9	.OnCtlColor(pDC);
		case lblColor_10:	return fm_lblColor_10	.OnCtlColor(pDC);
		case lblColor_11:	return fm_lblColor_11	.OnCtlColor(pDC);
		case lblColor_12:	return fm_lblColor_12	.OnCtlColor(pDC);
		case lblColor_13:	return fm_lblColor_13	.OnCtlColor(pDC);
		case lblColor_14:	return fm_lblColor_14	.OnCtlColor(pDC);
		case lblColor_15:	return fm_lblColor_15	.OnCtlColor(pDC);
		case lblColor_16:	return fm_lblColor_16	.OnCtlColor(pDC);
		case lblColor_17:	return fm_lblColor_17	.OnCtlColor(pDC);
		case lblColor_18:	return fm_lblColor_18	.OnCtlColor(pDC);
		case lblColor_19:	return fm_lblColor_19	.OnCtlColor(pDC);
		case lblColor_20:	return fm_lblColor_20	.OnCtlColor(pDC);
		case lblColor_21:	return fm_lblColor_21	.OnCtlColor(pDC);
		case lblColor_22:	return fm_lblColor_22	.OnCtlColor(pDC);
		case lblColor_23:	return fm_lblColor_23	.OnCtlColor(pDC);
		case lblColor_24:	return fm_lblColor_24	.OnCtlColor(pDC);
		case lblColor_25:	return fm_lblColor_25	.OnCtlColor(pDC);
		case shpRect_0:	return fm_shpRect_0	.OnCtlColor(pDC);
		case lblBrush:	return fm_lblBrush	.OnCtlColor(pDC);
		case lblDot:	return fm_lblDot	.OnCtlColor(pDC);
	}
	return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}
