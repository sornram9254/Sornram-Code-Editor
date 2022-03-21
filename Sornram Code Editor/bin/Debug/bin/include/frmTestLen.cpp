// frmTestLen.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestLen)
//}}VBto_Converter_Includes

#include "frmTestLen.h"
CfrmTestLen *frmTestLen = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestLen dialog



CfrmTestLen::CfrmTestLen(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestLen::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestLen) frmTestLen = this;
}

void CfrmTestLen::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestLen)
	DDX_Control(pDX, LabelParam1, m_LabelParam1);
	DDX_Control(pDX, Label2, m_Label2);
	DDX_Control(pDX, Label4, m_Label4);
	DDX_Control(pDX, LabelParam2, m_LabelParam2);
	DDX_Control(pDX, LabelParam3, m_LabelParam3);
	DDX_Control(pDX, LabelParam4, m_LabelParam4);
	DDX_Control(pDX, LabelParam5, m_LabelParam5);
	DDX_Control(pDX, LabelParam6, m_LabelParam6);
	DDX_Control(pDX, LabelParam7, m_LabelParam7);
	DDX_Control(pDX, LabelParam8, m_LabelParam8);
	DDX_Control(pDX, LabelParam9, m_LabelParam9);
	DDX_Control(pDX, LabelParam10, m_LabelParam10);
	DDX_Control(pDX, Label3, m_Label3);
	DDX_Control(pDX, LenParam1, m_LenParam1);
	DDX_Control(pDX, LenParam2, m_LenParam2);
	DDX_Control(pDX, LenParam3, m_LenParam3);
	DDX_Control(pDX, LenParam4, m_LenParam4);
	DDX_Control(pDX, LenParam5, m_LenParam5);
	DDX_Control(pDX, LenParam6, m_LenParam6);
	DDX_Control(pDX, LenParam7, m_LenParam7);
	DDX_Control(pDX, LenParam8, m_LenParam8);
	DDX_Control(pDX, LenParam9, m_LenParam9);
	DDX_Control(pDX, LenParam10, m_LenParam10);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestLen, CDialog)
	//{{AFX_MSG_MAP(CfrmTestLen)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestLen message handlers

BOOL CfrmTestLen::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestLen)
	
	fm_Label2.Set(GetDlgItem(Label2), GetSysColor(COLOR_BTNTEXT), GetSysColor(COLOR_BTNFACE),"MS Sans Serif",8.25,true,false,false,false,RUSSIAN_CHARSET);
	fm_Label4.Set(GetDlgItem(Label4), GetSysColor(COLOR_BTNTEXT), GetSysColor(COLOR_BTNFACE),"MS Sans Serif",8.25,true,false,false,false,RUSSIAN_CHARSET);
	
	
	Form_Load();
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestLen::OnPaint() 
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
HCURSOR CfrmTestLen::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================





enum WorkDays {
	Saturday = 7,
	Sunday = 0,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Invalid = -1
};

void CfrmTestLen::Form_Load()
{

	m_LabelParam1.SetWindowText("\"a b\"");
	m_LenParam1.SetWindowText(Str(strlen("a b")));

	m_LabelParam2.SetWindowText("\""+::GetWindowText(m_LabelParam1)+"\"");
	m_LenParam2.SetWindowText(Str(::GetWindowText(m_LabelParam1).GetLength()));

	m_LabelParam3.SetWindowText("\"a b\" + \"c d\"");
	m_LenParam3.SetWindowText(Str(("a b"+CString("c d")).GetLength()));


#if !VBtoJSNET
	 short vInteger; int vLong; float vSingle; double vDouble; 
	vInteger = 0; vLong = 0; vSingle = 0; vDouble = 0;

	m_LabelParam4.SetWindowText("vInteger");
	m_LenParam4.SetWindowText(Str(sizeof(vInteger)));

	m_LabelParam5.SetWindowText("vLong");
	m_LenParam5.SetWindowText(Str(sizeof(vLong)));

	m_LabelParam6.SetWindowText("vSingle");
	m_LenParam6.SetWindowText(Str(sizeof(vSingle)));

	m_LabelParam7.SetWindowText("vDouble");
	m_LenParam7.SetWindowText(Str(sizeof(vDouble)));

#endif


#if !(VBtoCSNET || VBtoVCNET || VBtoJSNET)
	 myType VmyType; 
	// VmyType.vI = 11
	m_LabelParam8.SetWindowText("VmyType");
	m_LenParam8.SetWindowText(Str(sizeof(VmyType)));

	 myType2 VmyType2; 
	m_LabelParam9.SetWindowText("VmyType2");
	m_LenParam9.SetWindowText(Str(sizeof(VmyType2)));

#endif


#if !(VBtoCSNET || VBtoJSNET)
	 WorkDays WorkDay; 
	// WorkDay = Sunday
	// WorkDay = WorkDays.Saturday
	m_LabelParam10.SetWindowText("VEnum");
	m_LenParam10.SetWindowText(Str(sizeof(WorkDay)));

#endif

}

HBRUSH CfrmTestLen::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch(pWnd->GetDlgCtrlID()) {
		case Label2:	return fm_Label2	.OnCtlColor(pDC);
		case Label4:	return fm_Label4	.OnCtlColor(pDC);
	}
	return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}
