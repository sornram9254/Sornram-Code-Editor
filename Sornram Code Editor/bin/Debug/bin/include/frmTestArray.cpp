// frmTestArray.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestArray)
//}}VBto_Converter_Includes

#include "frmTestArray.h"
CfrmTestArray *frmTestArray = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestArray dialog



CfrmTestArray::CfrmTestArray(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestArray::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestArray) frmTestArray = this;
}

void CfrmTestArray::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestArray)
	DDX_Control(pDX, Label3, m_Label3);
	DDX_Control(pDX, TextResult, m_TextResult);
	DDX_Control(pDX, CmdRecalcArray1, m_CmdRecalcArray1);
	DDX_Control(pDX, CmdRecalcArray2, m_CmdRecalcArray2);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestArray, CDialog)
	//{{AFX_MSG_MAP(CfrmTestArray)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(CmdRecalcArray1, OnCmdRecalcArray1)
	ON_BN_CLICKED(CmdRecalcArray2, OnCmdRecalcArray2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestArray message handlers

BOOL CfrmTestArray::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestArray)
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestArray::OnPaint() 
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
HCURSOR CfrmTestArray::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================






void CfrmTestArray::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialog::OnShowWindow(bShow, nStatus);

	// TODO: Add your message handler code here and/or call default

	 char SS[11]; 


#if VBtoJSNET
	m_CmdRecalcArray2.EnableWindow(false);

#endif

	// ReCalcTable1
	// ReCalcTable2
}

void CfrmTestArray::ReCalcTable1()
{
	m_TextResult.SetWindowText("");

	 const CString sss="zx"; 
	 const short n0=0,  nE=9; 

	// Dim r1() As Long, r2(0 To 99) As Long, r3 As Long
	 CVBtoArray <int> r1; int r2[99+1],  r3;
	memset(r2,0,sizeof(r2)); 

	// Dim Ar1(2 * nE + 7) As Single, Ar3(3 To (2 * nE + 7), 7, 2 To nE) As Single
	 float Ar1[2*nE+7+1],  ar3[(2*nE+7)+1][7+1][nE+1];
	memset(Ar1,0,sizeof(Ar1));
	memset(ar3,0,sizeof(ar3)); 

	// Dim i As Long, x(0 To 9) As Single, y(n0 To nE) As Double
	 int i; float x[9+1]; double y[nE+1];
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y)); 

	i = 2; i = 3;
	x[1] = 2;
	x[1] = (float)(i);
	x[2] = 3;

	// Dim pp(nE) As myPoint
	 myPoint pp[nE+1]; 
	 myPointA pA[nE+1]; 

	for(i=nE; i>=0; i--) {
		x[i] = (float)(i);
		y[i] = i*i;
	}

	for(i=nE; i>=0; i--) {
		pp[i].xx = x[i];
		pp[i].yy = y[i];
	}

	 CString TableXY; 
	TableXY = "  i    X(i)   Y(i)";
	for(i=0; i<=nE; i++) {
		pp[i].SS = Str(i)+"     "+FormatVB(pp[i].xx)+"     "+FormatVB(pp[i].yy);
		TableXY += CString("\r\n")+pp[i].SS;
	}

	AfxMessageBox(TableXY);
	m_TextResult.SetWindowText(TableXY);

}

void CfrmTestArray::ReCalcTable2()
{
	m_TextResult.SetWindowText("");


#if VBtoJSNET
	m_TextResult.SetWindowText("Unsupported");

#else
	 const short nI=10,  nJ=10; 
	 myPointA mp[nI+1][nJ+1]; int mm[nI+1][nJ+1],  i,  j;
	memset(mm,0,sizeof(mm)); 

	for(i=1; i<=nI; i++) {
		for(j=1; j<=nJ; j++) {
			mm[i][j] = i*j;
			mp[i][j].xx = (float)(i);
			mp[i][j].yy = j;
			mp[i][j].SS = Str(mm[i][j]);
		}
	}

	 CString TableXY; 
	for(i=1; i<=nI; i++) {
		for(j=1; j<=nJ; j++) {
			TableXY += CString('\t')+mp[i][j].SS;
		}
		TableXY += "\r\n";
	}

	m_TextResult.SetWindowText(TableXY);

#endif

}

void CfrmTestArray::OnCmdRecalcArray1()
{
	// TODO: Add your control notification handler code here
	ReCalcTable1();
}

void CfrmTestArray::OnCmdRecalcArray2()
{
	// TODO: Add your control notification handler code here
	ReCalcTable2();
}

