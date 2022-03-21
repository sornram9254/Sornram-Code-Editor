// frmTestMath.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestMath)
//}}VBto_Converter_Includes

#include "frmTestMath.h"
CfrmTestMath *frmTestMath = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestMath dialog



CfrmTestMath::CfrmTestMath(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestMath::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestMath) frmTestMath = this;
}

void CfrmTestMath::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestMath)
	DDX_Control(pDX, Label2, m_Label2);
	DDX_Control(pDX, Label1, m_Label1);
	DDX_Control(pDX, Label4, m_Label4);
	DDX_Control(pDX, Label3, m_Label3);
	DDX_Control(pDX, Label5, m_Label5);
	DDX_Control(pDX, TextX, m_TextX);
	DDX_Control(pDX, TextResult, m_TextResult);
	DDX_Control(pDX, ListFunction, m_ListFunction);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestMath, CDialog)
	//{{AFX_MSG_MAP(CfrmTestMath)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_LBN_SELCHANGE(ListFunction, SelchangeListFunction)
	ON_EN_CHANGE(TextX, ChangeTextX)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestMath message handlers

BOOL CfrmTestMath::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestMath)
	m_TextX	.SetWindowText("3");
	m_ListFunction	.AddString("Sqr(X)");
	m_ListFunction	.AddString("Cos(X)");
	m_ListFunction	.AddString("Sin(X)");
	m_ListFunction	.AddString("Tan(X)");
	m_ListFunction	.AddString("Atn(X)");
	m_ListFunction	.AddString("Exp(X)");
	m_ListFunction	.AddString("Log(X)");
	m_ListFunction	.AddString("Sgn(X)");
	m_ListFunction	.AddString("Abs(X)");
	m_ListFunction	.AddString("Round(X)");
	m_ListFunction	.AddString("Round(X,1)");
	m_ListFunction	.AddString("Rnd()");
	m_ListFunction	.AddString("(X+1)*(X+1)-X*X-2*X");
	m_ListFunction	.AddString("RowCos(X)");
	m_ListFunction	.AddString("RowSin(X)");
	m_ListFunction	.AddString("CalcPI");
	
	
	fm_Label3.Set(GetDlgItem(Label3), GetSysColor(COLOR_BTNTEXT), GetSysColor(COLOR_BTNFACE),"MS Sans Serif",8.25,true,false,false,false,RUSSIAN_CHARSET);
	fm_Label5.Set(GetDlgItem(Label5), RGB(255,0,0), GetSysColor(COLOR_BTNFACE));
	
	
	Form_Load();
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestMath::OnPaint() 
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
HCURSOR CfrmTestMath::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================

void CfrmTestMath::Form_Load()
{
	m_TextX.SetWindowText(Str(3.14));
}

double CfrmTestMath::RowCos(double x)
{
	double RowCos = 0;

	RowCos = 1;
	 double m; int i; double Eps; 
	Eps = 0.000000000001;
	m = 1;

	for(i=1; i<=500; i++) {
		m = -m*x*x/((2*i-1)*2*i);
		RowCos += m;

		if ((m<=Eps) && (m>=-Eps)) return RowCos;
		if (!((m>Eps) || (m<-Eps))) return RowCos;


#if !VBtoJSNET
		if ((m>Eps) || (m<-Eps)) goto Contin;
		return RowCos;
	Contin: ;

#endif

	}

	return RowCos;
}

double CfrmTestMath::RowSin(double x)
{
	double RowSin = 0;
	RowSin = x;
	 double m; int i; bool flPlus; 
	m = x;
	flPlus = false;
	for(i=3; i<=500; i+=2) {
		m = m*x*x/((i-1)*i);
		RowSin += (flPlus ? m : -m);
		flPlus = !flPlus;
	} // i
	return RowSin;
}

double CfrmTestMath::CalcPI()
{
	double CalcPI = 0;
	 int j; 
	CalcPI = 1;
	for(j=1; j<=1000; j++) {
		 double p; 
		p = 1/(1-1/(4.*j*j));
		CalcPI *= p;
		if (p<1.000001) break;
	} // j
	CalcPI *= 2;
	return CalcPI;
}

double CfrmTestMath::CalcFunction(double x)
{
	double CalcFunction = 0;
	 CString strFunc; 
	strFunc = GetText(m_ListFunction);
	if (strFunc=="Sqr(X)") {
		CalcFunction = sqrt(x);
	} else if (strFunc=="Cos(X)") {
		CalcFunction = cos(x);
	} else if (strFunc=="Sin(X)") {
		CalcFunction = sin(x);
	} else if (strFunc=="Tan(X)") {
		CalcFunction = tan(x);
	} else if (strFunc=="Atn(X)") {
		CalcFunction = atan(x);
	} else if (strFunc=="Exp(X)") {
		CalcFunction = exp(x);
	} else if (strFunc=="Log(X)") {
		CalcFunction = log(x);
	} else if (strFunc=="Sgn(X)") {
		CalcFunction = Sign(x);
	} else if (strFunc=="Abs(X)") {
		CalcFunction = abs(x);
	} else if (strFunc=="Round(X)") {
		CalcFunction = Round(x);
	} else if (strFunc=="Round(X,1)") {
		CalcFunction = Round(x, 1);
	} else if (strFunc=="Rnd()") {
		Randomize();
		CalcFunction = Rnd();
	} else if (strFunc=="(X+1)*(X+1)-X*X-2*X") {
		CalcFunction = (x+1)*(x+1)-x*x-2*x; // identically 1
	} else if (strFunc=="RowCos(X)") {
		CalcFunction = RowCos(x);
	} else if (strFunc=="RowSin(X)") {
		CalcFunction = RowSin(x);
	} else if (strFunc=="CalcPI") {
		CalcFunction = CalcPI();
	} else {
		CalcFunction = x;
	}
	return CalcFunction;
}

void CfrmTestMath::Action()
{

	if (m_ListFunction.GetCurSel()<0) {
		m_TextResult.SetWindowText("Please, select function");
		return;
	}

	// If (Not IsNumeric(TextX.Text)) Then
	// TextResult.Text = "Invalid X"
	// Exit Sub
	// End If

	 double x,  Result; 
	x = Val(::GetWindowText(m_TextX));
	Result = CalcFunction(x);
	m_TextResult.SetWindowText(FormatVB(Result));

}

void CfrmTestMath::SelchangeListFunction()
{
	// TODO: Add your control notification handler code here
	Action();
}
void CfrmTestMath::ChangeTextX()
{
	// TODO: Add your control notification handler code here
	Action();
}

HBRUSH CfrmTestMath::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch(pWnd->GetDlgCtrlID()) {
		case Label3:	return fm_Label3	.OnCtlColor(pDC);
		case Label5:	return fm_Label5	.OnCtlColor(pDC);
	}
	return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}
