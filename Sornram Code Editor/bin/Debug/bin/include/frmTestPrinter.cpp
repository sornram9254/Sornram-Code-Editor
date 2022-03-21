// frmTestPrinter.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestPrinter)
//}}VBto_Converter_Includes

#include "frmTestPrinter.h"
CfrmTestPrinter *frmTestPrinter = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestPrinter dialog



CfrmTestPrinter::CfrmTestPrinter(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestPrinter::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestPrinter) frmTestPrinter = this;
}

void CfrmTestPrinter::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestPrinter)
	DDX_Control(pDX, Label3, m_Label3);
	DDX_Control(pDX, cmdPrint, m_cmdPrint);
	DDX_Control(pDX, CheckBoxPageB, m_CheckBoxPageB);
	DDX_Control(pDX, CheckBoxPageA, m_CheckBoxPageA);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestPrinter, CDialog)
	//{{AFX_MSG_MAP(CfrmTestPrinter)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(CheckBoxPageA, OnCheckBoxPageA)
	ON_BN_CLICKED(CheckBoxPageB, OnCheckBoxPageB)
	ON_BN_CLICKED(cmdPrint, OncmdPrint)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestPrinter message handlers

BOOL CfrmTestPrinter::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestPrinter)
	m_CheckBoxPageA	.SetCheck(BST_CHECKED);
	
	fm_Label3.Set(GetDlgItem(Label3), RGB(0,0,255), GetSysColor(COLOR_BTNFACE));
	
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestPrinter::OnPaint() 
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
HCURSOR CfrmTestPrinter::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================

CString CfrmTestPrinter::getFontInfo()
{
	CString getFontInfo;
	 CString S; 
	S = "FontName=\""+VBtoPrinter.GetFontName()+"\"";
	S = S+CString(";  FontSize=")+Str(VBtoPrinter.GetFontSize());
	S = S+CString(";  FontBold=")+Str(VBtoPrinter.GetFontBold());
	S = S+CString(";  FontItalic=")+Str(VBtoPrinter.GetFontItalic());
	getFontInfo = "("+S+")";
	return getFontInfo;
}

void CfrmTestPrinter::CheckBoxesClick()
{
	 CString S; 
	if ((m_CheckBoxPageA.GetCheck()==BST_CHECKED) && (m_CheckBoxPageB.GetCheck()==BST_CHECKED)) {
		S = "(pages 1, 2)";
	} else if (m_CheckBoxPageA.GetCheck()==BST_CHECKED) {
		S = "(page N 1 only)";
	} else if (m_CheckBoxPageB.GetCheck()==BST_CHECKED) {
		S = "(page N 2 only)";
	}
	m_cmdPrint.SetWindowText("Print "+S);
	m_cmdPrint.EnableWindow((m_CheckBoxPageA.GetCheck()==BST_CHECKED) || (m_CheckBoxPageB.GetCheck()==BST_CHECKED));
}
void CfrmTestPrinter::OnCheckBoxPageA()
{
	// TODO: Add your control notification handler code here
	CheckBoxesClick();
}
void CfrmTestPrinter::OnCheckBoxPageB()
{
	// TODO: Add your control notification handler code here
	CheckBoxesClick();
}

void CfrmTestPrinter::PrintPageA()
{
	VBtoPrinter.SetCurrentX(800);
	VBtoPrinter.SetCurrentY(500+4000*0);

	// ---------------------
	 CString S; 
	S = "";

#if VB6
	S = "VB6";

#elif VBtoVBNET
	S = "VB.NET";

#elif VBtoCSNET
	S = "C#";

#elif VBtoVCNET
	S = "VC.NET";

#elif VBtoVCMFC
	S = "VC++";

#elif VBtoBuilder
	S = "Borland C++ Builder";

#elif VBtoDelphi
	S = "Borland Delphi";

#elif VBtoJSNET
	S = "MS J#";

#endif
	S = CString(' ',5)+"www.vbto.net   VBto Converter   (test "+S+")";

	VBtoPrinter.SetFontSize(12);
	VBtoPrinter.SetFontBold(true);
	VBtoPrinter.Print(S);
	VBtoPrinter.Print("");

	// ---------------------
	VBtoPrinter.SetFontItalic(true);
	VBtoPrinter.Print("Test string A  "+getFontInfo());

	VBtoPrinter.SetFontBold(false);
	VBtoPrinter.Print("Test string B  "+getFontInfo());

	VBtoPrinter.SetFontSize(8);
	VBtoPrinter.Print("Test string C  "+getFontInfo());

	VBtoPrinter.SetFontItalic(false);
	VBtoPrinter.Print("Test string D  "+getFontInfo());

	VBtoPrinter.SetFontName("Courier New");
	VBtoPrinter.SetFontBold(true);
	VBtoPrinter.Print("Test string E  "+getFontInfo());

	VBtoPrinter.SetFontItalic(true);
	VBtoPrinter.Print("Test string F  "+getFontInfo());

	VBtoPrinter.SetFontBold(false);
	VBtoPrinter.SetFontItalic(false);
	VBtoPrinter.Print("Test string G  "+getFontInfo());

	// ---------------------
	 int n,  i,  j; 
	 float r,  xC,  yC; 
	r = 1600;
	xC = (float)(r*1.9);
	yC = (float)(VBtoPrinter.GetCurrentY()+r*1.1);

	VBtoPrinter.Circle((xC), yC, r*1.1, 0xFF00FF);
	VBtoPrinter.Circle((xC), yC, r, 0);

	n = 7;
	 double angle; 
	angle = 2*3.1415926/n;

	for(i=1; i<=n-1; i++) {
		 double fi; float xi,  yi,  xj,  yj; 
		fi = angle*i;

		if ((i %  2)==1) {
			VBtoPrinter.Arc((xC), yC, r*(0.5+0.5*(double)i / n), fi, fi+angle, 0);
		} else {
			VBtoPrinter.Arc((xC), yC, r*(0.5+0.5*(double)i / n), fi, fi+angle, 0xFF);
		}

		xi = (float)(xC+r*cos(fi));
		yi = (float)(yC+r*sin(fi));

		for(j=i+1; j<=n; j++) {
			fi = angle*j;
			xj = (float)(xC+r*cos(fi));
			yj = (float)(yC+r*sin(fi));
			VBtoPrinter.Line((xi), yi, xj, yj, 0xFF00);
		}

	}

	// ---------------------
	VBtoPrinter.PSet((xC), yC, 0);
	VBtoPrinter.LineTo((xC+r*0.1), yC);
	VBtoPrinter.LineTo(Round((xC+r*0.1)), Round(yC), 0xFF0000);
	VBtoPrinter.PSet((xC), yC, 0);
	VBtoPrinter.LineTo(Round((xC)), Round(yC-r*0.1), 0xFF00);
	VBtoPrinter.Print("0");

	// ---------------------
	// VBto upgrade warning: X1 As int	OnWrite(double)
	 int X1; 
	X1 = Round(xC+r*1.4);
	VBtoPrinter.Rectangle((X1+200), Round(yC+200), X1+500, Round(yC+r-200), RGB(100, 100, 100));
	VBtoPrinter.Line((X1), yC, X1+700, yC+r, 0);
	VBtoPrinter.Rectangle((X1), Round(yC), X1+700, Round(yC+r), 0xFFFF00);
	VBtoPrinter.Print("Page 'A';  Printer.Page="+Str(VBtoPrinter.GetPageNumber()));

	// ---------------------
	// VBto upgrade warning: yL As int	OnWrite(float, int)
	 int yL,  rr; 
	yL = Round(VBtoPrinter.GetCurrentY()+200);
	for(i=0; i<=5; i++) {
		VBtoPrinter.DrawStyle = i;
		yL += 300;
		VBtoPrinter.Line((400), yL, 4800, yL, 0);
		VBtoPrinter.Print("DrawStyle = "+Str(VBtoPrinter.DrawStyle));
	} // i
	VBtoPrinter.DrawStyle = 0;

	// ---------------------
	yL += 200;
	for(i=0; i<=2; i++) {
		VBtoPrinter.DrawWidth = 1+3*i;
		yL += 300;
		VBtoPrinter.Line((400), yL, 4800, yL, 0);
		VBtoPrinter.Print("DrawWidth = "+Str(VBtoPrinter.DrawWidth));
	} // i
	VBtoPrinter.DrawWidth = 1;

	// ---------------------
	rr = 600;
	yL += rr;
	VBtoPrinter.FillColor = 0xFFFF;
	VBtoPrinter.FillStyle = 0;
	VBtoPrinter.Circle((2*rr), yL, rr*0.6, 0);

	VBtoPrinter.FillStyle = 1;
	VBtoPrinter.Circle((4*rr), yL, rr*0.8, 0);

}

void CfrmTestPrinter::PrintPageB()
{
	VBtoPrinter.Rectangle((1100), 1100, 2400, 2000, 0);
	VBtoPrinter.Rectangle((1000), 1000, 2500, 2100, 0xFF00);
	VBtoPrinter.Print("Page 'B';  Printer.Page="+Str(VBtoPrinter.GetPageNumber()));
}

void CfrmTestPrinter::OncmdPrint()
{
	// TODO: Add your control notification handler code here
	if (m_CheckBoxPageA.GetCheck()==BST_CHECKED) {
		PrintPageA();
	}

	if (m_CheckBoxPageB.GetCheck()==BST_CHECKED) {
		if (m_CheckBoxPageA.GetCheck()==BST_CHECKED) VBtoPrinter.NewPage();
		PrintPageB();
	}

	VBtoPrinter.EndDoc();
}

HBRUSH CfrmTestPrinter::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch(pWnd->GetDlgCtrlID()) {
		case Label3:	return fm_Label3	.OnCtlColor(pDC);
	}
	return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}
