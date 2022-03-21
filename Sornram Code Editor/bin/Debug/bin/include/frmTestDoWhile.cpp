// frmTestDoWhile.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestDoWhile)
//}}VBto_Converter_Includes

#include "frmTestDoWhile.h"
CfrmTestDoWhile *frmTestDoWhile = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestDoWhile dialog



CfrmTestDoWhile::CfrmTestDoWhile(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestDoWhile::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestDoWhile) frmTestDoWhile = this;
}

void CfrmTestDoWhile::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestDoWhile)
	DDX_Control(pDX, Label1, m_Label1);
	DDX_Control(pDX, ListBoxResults, m_ListBoxResults);
	DDX_Control(pDX, CmdRunAllTest, m_CmdRunAllTest);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestDoWhile, CDialog)
	//{{AFX_MSG_MAP(CfrmTestDoWhile)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(CmdRunAllTest, OnCmdRunAllTest)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestDoWhile message handlers

BOOL CfrmTestDoWhile::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestDoWhile)
	
	Form_Load();
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestDoWhile::OnPaint() 
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
HCURSOR CfrmTestDoWhile::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================

// Const A1 = 10, nA As Integer = 4, StepA As Integer = 7

void CfrmTestDoWhile::AddResult(CString Test, int Result, int ResultOk)
{
	 CString Mess; 
	if (Result==ResultOk) {
		Mess = "Ok on test \""+Test+"\"";
	} else {
		Mess = "False on test \""+Test+"\" :  Result="+FormatVB(Result)+"   ResultOk="+Str(ResultOk);
	}
	m_ListBoxResults.AddString(Mess);
}

void CfrmTestDoWhile::RunAllTests()
{
	// VBto upgrade warning: Sum As int	OnWrite(int, double)
	// VBto upgrade warning: SumOk As int	OnWrite(double)
	// VBto upgrade warning: Member As short	OnWrite(int)
	 int Sum,  SumOk; short Member; int i; 

	 const short A1=10,  nA=4,  StepA=7; 

	SumOk = Round(A1*nA+StepA*(nA-1)*(double)nA / 2);

	Sum = 0;
	i = 0;
	while (i<nA) {
		Member = A1+StepA*i;
		Sum += Member;
		i += 1;
	}
	AddResult("Do While ... Loop", Sum, SumOk);

	Sum = 0;
	i = 0;
	while (!(i>=nA)) {
		Member = A1+StepA*i;
		Sum += Member;
		i += 1;
	}
	AddResult("Do Until ... Loop", Sum, SumOk);

	Sum = 0;
	i = 0;
	do {
		Sum += (A1+StepA*i);
		i += 1;
	} while (i<nA);
	AddResult("Do ... Loop While", Sum, SumOk);

	Sum = 0;
	i = 0;
	do {
		Sum += (A1+StepA*i);
		i += 1;
	} while (!(i>=nA));
	AddResult("Do ... Loop Until 1", Sum, SumOk);

	Sum = 0;
	i = 0;
	do {
		Sum += (A1+StepA*i);
		i += 1;
		if (i>=nA) break;
	} while (!false);
	AddResult("Do ... Loop Until 2", Sum, SumOk);

	i = 1;
	Sum = 0;
	for(;;) {
		if (i>nA) break;
		Member = A1+StepA*(i-1);
		Sum += Member;
		i += 1;
	}
	AddResult("Do ... Loop", Sum, SumOk);

	Sum = 0;
	i = 0;
	while (i<nA) {
		Member = A1+StepA*i;
		Sum += Member;
		i += 1;
	}
	AddResult("While ... Wend", Sum, SumOk);

	Sum = 0;
	for(i=1; i<=nA; i++) {
		Member = A1+StepA*(i-1);
		Sum += Member;
	}
	AddResult("For 1", Sum, SumOk);

	Sum = 0;
	for(i=1; i<=32000; i++) {
		if (i>nA) break;
		Member = A1+StepA*(i-1);
		Sum += Member;
	}
	AddResult("For 1A", Sum, SumOk);

	Sum = 0;
	for(i=nA; i>=1; i--) {
		Member = A1+StepA*(i-1);
		Sum += Member;
	}
	AddResult("For 2", Sum, SumOk);

	 int Aend; 
	Aend = A1+StepA*(nA-1);
	Sum = 0;
	for(i=A1; i<=Aend; i+=StepA) {
		Sum += i;
	}
	AddResult("For 3", Sum, SumOk);

	Sum = 0;
	for(i=Aend; i>=A1; i+=-StepA) {
		Sum += i;
	}
	AddResult("For 4", Sum, SumOk);

	Sum = 0;
	for(i=1; i<=nA; i++) {
		 short j; 
		j = 0;
		while (j<nA) {
			Member = A1+StepA*j;
			Sum += Member;
			j += 1;
		}
	}
	Sum /= nA;
	AddResult("For & While", Sum, SumOk);



#if !VBtoJSNET
	// --- Test GoTo Label ---
	Sum = 0; i = 0;

iLabel3: i += 1;
	Sum += i;
	if (i<3) goto iLabel3;

iLabel6: Sum += i;
	i += 1;
	if (i<6) goto iLabel6;

m9: Sum += i;
	i += 1;
	if (i<9) goto m9;

	AddResult("GoTo Label", Sum, 39);

#endif



#if VB6 || VBtoVBNET || VBtoCSNET
	 short Ar[2+1];
	memset(Ar,0,sizeof(Ar)); 
	Ar[0] = 1; Ar[1] = 2; Ar[2] = 3;
	Sum = 0;

#if VB6 || VBtoVBNET
	 CComVariant m; 

#endif
	foreach (short m in Ar) {
		Sum += m;
	} // m
	AddResult("For Each", Sum, 6); // 6 = 1+2+3

#endif

}

void CfrmTestDoWhile::OnCmdRunAllTest()
{
	// TODO: Add your control notification handler code here
	m_ListBoxResults.ResetContent();
	RunAllTests();
}

void CfrmTestDoWhile::Form_Load()
{
	RunAllTests();

	 short i,  j,  k; 
	for(i=1; i<=10; i++) {
		for(j=1; j<=20; j+=2) {
			for(k=30; k>=0; k--) {
				// ...
			} // k
		} // j
	} // i // ;-)

}
