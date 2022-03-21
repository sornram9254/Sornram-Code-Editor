// frmTestModuleClass.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestModuleClass)
//}}VBto_Converter_Includes

#include "frmTestModuleClass.h"
CfrmTestModuleClass *frmTestModuleClass = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestModuleClass dialog



CfrmTestModuleClass::CfrmTestModuleClass(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestModuleClass::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestModuleClass) frmTestModuleClass = this;
}

void CfrmTestModuleClass::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestModuleClass)
	DDX_Control(pDX, Label1, m_Label1);
	DDX_Control(pDX, CmdCallFunctionFromModule1, m_CmdCallFunctionFromModule1);
	DDX_Control(pDX, CmdCallSubFromModule2, m_CmdCallSubFromModule2);
	DDX_Control(pDX, CmdSetXYZtoModule3, m_CmdSetXYZtoModule3);
	DDX_Control(pDX, TextXYZ, m_TextXYZ);
	DDX_Control(pDX, CmdGetDistfromModule3, m_CmdGetDistfromModule3);
	DDX_Control(pDX, CmdTestClass1, m_CmdTestClass1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestModuleClass, CDialog)
	//{{AFX_MSG_MAP(CfrmTestModuleClass)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(CmdCallFunctionFromModule1, OnCmdCallFunctionFromModule1)
	ON_BN_CLICKED(CmdCallSubFromModule2, OnCmdCallSubFromModule2)
	ON_BN_CLICKED(CmdSetXYZtoModule3, OnCmdSetXYZtoModule3)
	ON_BN_CLICKED(CmdGetDistfromModule3, OnCmdGetDistfromModule3)
	ON_BN_CLICKED(CmdTestClass1, OnCmdTestClass1)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestModuleClass message handlers

BOOL CfrmTestModuleClass::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestModuleClass)
	m_TextXYZ	.SetWindowText("1");
	fPublic = 0;
	fPrivate = 0;
	fDim = 0;
	
	fm_Label1.Set(GetDlgItem(Label1), GetSysColor(COLOR_BTNTEXT), GetSysColor(COLOR_BTNFACE),"MS Sans Serif",8.25,true,false,false,false,RUSSIAN_CHARSET);
	
	
	Form_Load();
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestModuleClass::OnPaint() 
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
HCURSOR CfrmTestModuleClass::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================









void CfrmTestModuleClass::Form_Load()
{

	mt1.S = "mt1 As myType0";

	 myType0 mt2; 
	mt2.S = "mt2 As myType0";

}

//#define defUse_PrivateMethod
#ifdef defUse_PrivateMethod
void CfrmTestModuleClass::PrivateMethod()
{
	// 
}
#endif

// ! Public
//#define defUse_Method
#ifdef defUse_Method
void CfrmTestModuleClass::Method()
{
	// 
}
#endif

//#define defUse_PublicMethod
#ifdef defUse_PublicMethod
void CfrmTestModuleClass::PublicMethod()
{
	// 
}
#endif

void CfrmTestModuleClass::OnCmdCallFunctionFromModule1()
{
	// TODO: Add your control notification handler code here
	 bool ret; 
	ret = Module1Func1("Hello 1");
}

void CfrmTestModuleClass::OnCmdCallSubFromModule2()
{
	// TODO: Add your control notification handler code here
	Module2Sub1("Hello 2");
}

void CfrmTestModuleClass::OnCmdSetXYZtoModule3()
{
	// TODO: Add your control notification handler code here
	 float Value; 
	Value = CSng(::GetWindowText(m_TextXYZ));
	SetXYZ(Value);
}

void CfrmTestModuleClass::OnCmdGetDistfromModule3()
{
	// TODO: Add your control notification handler code here
	 double Dist; 
	Dist = GetDist();
	AfxMessageBox("Dist= "+Str(Dist));
}

void CfrmTestModuleClass::OnCmdTestClass1()
{
	// TODO: Add your control notification handler code here
	mtModule2Public.Price = 1;

	 Class1Name *C1=NULL,  *C2=NULL; 
	VBSetNew(C1, new Class1Name);

	 float Value; 
	Value = CSng(::GetWindowText(m_TextXYZ));

	C1->xx = Value;
	if (C1->xx!=Value) {
		::MessageBox(NULL, Str(C1->xx)+" <> "+Str(Value),"Error",MB_ICONEXCLAMATION);
	}

	C1->SetXYZ(Value);
	 double Dist; 
	Dist = C1->GetDist();
	AfxMessageBox("Dist= "+Str(Dist));

}

HBRUSH CfrmTestModuleClass::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch(pWnd->GetDlgCtrlID()) {
		case Label1:	return fm_Label1	.OnCtlColor(pDC);
	}
	return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}
