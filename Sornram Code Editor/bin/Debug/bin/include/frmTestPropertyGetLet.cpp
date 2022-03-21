// frmTestPropertyGetLet.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestPropertyGetLet)
//}}VBto_Converter_Includes

#include "frmTestPropertyGetLet.h"
CfrmTestPropertyGetLet *frmTestPropertyGetLet = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestPropertyGetLet dialog



CfrmTestPropertyGetLet::CfrmTestPropertyGetLet(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestPropertyGetLet::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestPropertyGetLet) frmTestPropertyGetLet = this;
}

void CfrmTestPropertyGetLet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestPropertyGetLet)
	DDX_Control(pDX, Label0, m_Label0);
	DDX_Control(pDX, Label1, m_Label1);
	DDX_Control(pDX, Label2, m_Label2);
	DDX_Control(pDX, Label3, m_Label3);
	DDX_Control(pDX, cmdPropertyLetGet, m_cmdPropertyLetGet);
	DDX_Control(pDX, EdtFirstName, m_EdtFirstName);
	DDX_Control(pDX, EdtLastName, m_EdtLastName);
	DDX_Control(pDX, EdtSalary, m_EdtSalary);
	DDX_Control(pDX, TextOutputInformation, m_TextOutputInformation);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestPropertyGetLet, CDialog)
	//{{AFX_MSG_MAP(CfrmTestPropertyGetLet)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(cmdPropertyLetGet, OncmdPropertyLetGet)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestPropertyGetLet message handlers

BOOL CfrmTestPropertyGetLet::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestPropertyGetLet)
	m_EdtFirstName	.SetWindowText("Valeriy");
	m_EdtLastName	.SetWindowText("Nikolaevich");
	m_EdtSalary	.SetWindowText("1000");
	
	FirstName	.mParent = this;
	LastName	.mParent = this;
	InfoString	.mParent = this;
	Salary	.mParent = this;
	EditItem	.mParent = this;
	
	fm_Label0.Set(GetDlgItem(Label0), RGB(255,0,0), GetSysColor(COLOR_BTNFACE));
	
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestPropertyGetLet::OnPaint() 
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
HCURSOR CfrmTestPropertyGetLet::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================
// Option Explicit







CString CfrmTestPropertyGetLet::GetFirstName()
{
	CString FirstName;
	FirstName = mPerson.Name1;
	return FirstName;
}
void CfrmTestPropertyGetLet::SetFirstName(CString S)
{
	mPerson.Name1 = Trim(S);
}

void CfrmTestPropertyGetLet::SetLastName(CString S)
{
	mPerson.Name2 = S;
}
CString CfrmTestPropertyGetLet::GetLastName()
{
	CString LastName;
	LastName = mPerson.Name2;
	return LastName;
}




CComVariant CfrmTestPropertyGetLet::GetInfoString()
{
	CComVariant InfoString;
	InfoString = prepareInfo(12);
	return InfoString;
}

void CfrmTestPropertyGetLet::SetSalary(double Sal)
{
	mPerson.Sal = Sal;
}

CString CfrmTestPropertyGetLet::prepareInfo(int unusePar1)
{
	CString prepareInfo;
	prepareInfo = FirstName()+" "+LastName()+"; Salary="+Str(mPerson.Sal);
	return prepareInfo;
}

void CfrmTestPropertyGetLet::OncmdPropertyLetGet()
{
	// TODO: Add your control notification handler code here
	// VBto upgrade warning: fName As CComVariant --> As CString
	 CString fName;	// - "AutoDim" 

	fName = ::GetWindowText(m_EdtFirstName);

	 CString S; 

	FirstName = ::GetWindowText(m_EdtFirstName);
	LastName = ::GetWindowText(m_EdtLastName);
	Salary = Val(::GetWindowText(m_EdtSalary));

	FirstName = ::GetWindowText(m_EdtFirstName);
	LastName = ::GetWindowText(m_EdtLastName);
	Salary = Val(::GetWindowText(m_EdtSalary));

	this->FirstName = ::GetWindowText(m_EdtFirstName);
	this->LastName = ::GetWindowText(m_EdtLastName);
	this->Salary = Val(::GetWindowText(m_EdtSalary));

	S = S+CString("Property FirstName= ")+FirstName()+"\r\n";
	S = S+CString("Property LastName= ")+LastName()+"\r\n";
	S = S+CString("Property InfoString= ")+Str(InfoString());


#if !VBtoDelphi
	 const double xVal=200.1; 
	extProp = xVal;
	if (extProp()!=2*xVal) {
		MessageBeep(-1);
		S = S+CString("\r\n")+"!!! Error on external Property !!!";
	}

	extPropI = 123;
	if (3*123!=extPropI()) {
		MessageBeep(-1);
		S = S+CString("\r\n")+"!!! Error on external Property !!!";
	}
	if (extPropI()!=3*123) {
		MessageBeep(-1);
		S = S+CString("\r\n")+"!!! Error on external Property !!!";
	}

#endif

	m_TextOutputInformation.SetWindowText(S);
	m_TextOutputInformation.ShowWindow(SW_SHOW);

	xSub1(11);
	// xSub2 12

}

CComVariant CfrmTestPropertyGetLet::GetEditItem()
{
	CComVariant EditItem;
	EditItem = mEditItem;
	return EditItem;
}
void CfrmTestPropertyGetLet::SetEditItem(CComVariant Value)
{
	mEditItem = Value;
}




//#define defUse_unUseFun
#ifdef defUse_unUseFun
CString CfrmTestPropertyGetLet::unUseFun(int par1)
{
	CString unUseFun;
	return unUseFun;
}
#endif

//#define defUse_unUseSub
#ifdef defUse_unUseSub
// VBto upgrade warning: v1 As CComVariant --> As CString
// VBto upgrade warning: v2 As CComVariant --> As short
// VBto upgrade warning: v3 As CComVariant --> As double
void CfrmTestPropertyGetLet::unUseSub(CString& v1, short& v2, double& v3)
{
	// VBto upgrade warning: S As CComVariant --> As CString
	// VBto upgrade warning: n As CComVariant --> As short
	 CString S; short n;	// - "AutoDim" 

	 short qqx; 
	S = "str";
	n = 12;
	v1 = "s";
	v2 = n;
	v3 = sin(3.14);
	 CString ssx; 
}
#endif

HBRUSH CfrmTestPropertyGetLet::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch(pWnd->GetDlgCtrlID()) {
		case Label0:	return fm_Label0	.OnCtlColor(pDC);
	}
	return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}
