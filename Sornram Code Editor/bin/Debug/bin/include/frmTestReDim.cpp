// frmTestReDim.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestReDim)
//}}VBto_Converter_Includes

#include "frmTestReDim.h"
CfrmTestReDim *frmTestReDim = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestReDim dialog



CfrmTestReDim::CfrmTestReDim(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestReDim::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestReDim) frmTestReDim = this;
}

void CfrmTestReDim::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestReDim)
	DDX_Control(pDX, Label3, m_Label3);
	DDX_Control(pDX, CommandRunTest, m_CommandRunTest);
	DDX_Control(pDX, ListBoxEvents, m_ListBoxEvents);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestReDim, CDialog)
	//{{AFX_MSG_MAP(CfrmTestReDim)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(CommandRunTest, OnCommandRunTest)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestReDim message handlers

BOOL CfrmTestReDim::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestReDim)
	
	Form_Load();
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestReDim::OnPaint() 
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
HCURSOR CfrmTestReDim::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================

void CfrmTestReDim::Form_Load()
{
	TestReDim();
}

void CfrmTestReDim::OnCommandRunTest()
{
	// TODO: Add your control notification handler code here
	m_ListBoxEvents.ResetContent();
	TestReDim();
}

void CfrmTestReDim::AddEventToList(bool flError, CString TestName, CString AddInfo)
{
	if ((int)m_ListBoxEvents.m_hWnd==NULL) return;

	 CString S; 

	if (flError) {
		S = "Error on Test";
	} else {
		S = "Ok on Test";
	}

	S += CString("  \"")+TestName+"\"";

	if (flError && (AddInfo!="")) {
		S += CString("      AddInfo: ")+AddInfo;
	}

	m_ListBoxEvents.AddString(S);
	m_ListBoxEvents.SetCurSel(m_ListBoxEvents.GetCount()-1);
}

void CfrmTestReDim::TestReDim()
{

	// VBto upgrade warning: arI As short	OnWrite(int)
	 CVBtoArray <short> arI; CVBtoArray <short> arII; short arI5[5+1]; CVBtoArray <int> arL; CVBtoArray <float> arF;
	memset(arI5,0,sizeof(arI5)); 
	 CVBtoArrayPtr <CString> arS; CString arS7[7+1]; CVBtoArray <bool> arB; int ar3[3+1],  ar34[3+1][4+1]; CVBtoArray <BYTE> arT;
	memset(ar3,0,sizeof(ar3));
	memset(ar34,0,sizeof(ar34)); 
	 double arD8[8+1]; CVBtoArray <short> arIII; CVBtoArray <double> arD; CVBtoArrayPtr <CString> arSS;
	memset(arD8,0,sizeof(arD8)); 

	 int i,  j,  k,  t; 
	 int nX,  nY,  nZ; bool flError; 

	nX = 3; nY = 5; nZ = 2;

	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	flError = false;
	for(i=0; i<=3; i++) {
		if (ar3[i]!=0) flError = true;
		ar3[i] = i;
	}

	for(i=0; i<=3; i++) {
		if (ar3[i]!=i) flError = true;
	}
	AddEventToList(flError, "ar3(i)");

	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	flError = false;
	for(i=0; i<=3; i++) {
		for(j=0; j<=4; j++) {
			if (ar34[i][j]!=0) flError = true;
			ar34[i][j] = 10*i+j;
		}
	}

	for(i=0; i<=3; i++) {
		for(j=0; j<=4; j++) {
			if (ar34[i][j]!=10*i+j) flError = true;
		}
	}
	// If LBound(ar34) <> 0 Then flError = True
	// If UBound(ar34) <> 3 Then flError = True
	// If LBound(ar34, 2) <> 0 Then flError = True
	// If UBound(ar34, 2) <> 4 Then flError = True
	AddEventToList(flError, "ar34(i,j)");


	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#if VB6 || VBtoVCMFC || VBtoBuilder
	// VBtoCSNET VBtoVBNET VBtoJSNET VBtoDelphi

	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// VBto upgrade warning: arI As short	OnWrite(int)
	 arI.ReDim(nX + 1);
	flError = false;
	for(i=0; i<=nX; i++) {
		if (arI[i]!=0) flError = true;
		arI[i] = 100+i;
	}

	for(i=0; i<=nX; i++) {
		if (arI[i]!=(100+i)) flError = true;
	}
	if (0 /*LBound(arI)*/!=0) flError = true;
	if (arI.UBound()!=nX) flError = true;
	AddEventToList(flError, "Redim arI(nX)");

	// ---------------------------------------
	// VBto upgrade warning: arI As short	OnWrite(int)
	 arI.ReDimPreserve(2*nX + 1);
	flError = false;
	for(i=nX+1; i<=2*nX; i++) {
		if (arI[i]!=0) flError = true;
		arI[i] = 100+i;
	}

	for(i=0; i<=2*nX; i++) {
		if (arI[i]!=(100+i)) flError = true;
	}
	if (0 /*LBound(arI,1)*/!=0) flError = true;
	if (arI.UBound(1)!=2*nX) flError = true;
	AddEventToList(flError, "Redim Preserve arI(2*nX)");

	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// VBto upgrade warning: arI As short	OnWrite(int)
	 arI.ReDim(nX + 1,nY + 1);
	flError = false;
	for(i=0; i<=nX; i++) {
		for(j=0; j<=nY; j++) {
			if (arI(i, j)!=0) flError = true;
			arI(i, j) = 100+i*10+j;
		}
	}

	for(i=0; i<=nX; i++) {
		for(j=0; j<=nY; j++) {
			if (arI(i, j)!=(100+i*10+j)) flError = true;
		}
	}
	if (0 /*LBound(arI,1)*/!=0) flError = true;
	if (arI.UBound(1)!=nX) flError = true;
	if (0 /*LBound(arI,2)*/!=0) flError = true;
	if (arI.UBound(2)!=nY) flError = true;
	AddEventToList(flError, "Redim arI(nX, nY)");

	// ---------------------------------------
	// VBto upgrade warning: arI As short	OnWrite(int)
	 arI.ReDimPreserve(nX + 1,2*nY + 1);
	flError = false;
	for(i=0; i<=nX; i++) {
		for(j=nY+1; j<=2*nY; j++) {
			if (arI(i, j)!=0) flError = true;
			arI(i, j) = 100+i*10+j;
		}
	}

	for(i=0; i<=nX; i++) {
		for(j=0; j<=2*nY; j++) {
			if (arI(i, j)!=(100+i*10+j)) flError = true;
		}
	}
	if (0 /*LBound(arI,1)*/!=0) flError = true;
	if (arI.UBound(1)!=nX) flError = true;
	if (0 /*LBound(arI,2)*/!=0) flError = true;
	if (arI.UBound(2)!=2*nY) flError = true;
	AddEventToList(flError, "Redim Preserve arI(nX, nY)");

	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// VBto upgrade warning: arI As short	OnWrite(int)
	 arI.ReDim(nX + 1,nY + 1,nZ + 1);
	flError = false;
	for(i=0; i<=nX; i++) {
		for(j=0; j<=nY; j++) {
			for(k=0; k<=nZ; k++) {
				if (arI(i, j, k)!=0) flError = true;
				arI(i, j, k) = i*100+j*10+k;
			}
		}
	}

	for(i=0; i<=nX; i++) {
		for(j=0; j<=nY; j++) {
			for(k=0; k<=nZ; k++) {
				if (arI(i, j, k)!=(i*100+j*10+k)) flError = true;
			}
		}
	}
	if (0 /*LBound(arI,1)*/!=0) flError = true;
	if (arI.UBound(1)!=nX) flError = true;
	if (0 /*LBound(arI,2)*/!=0) flError = true;
	if (arI.UBound(2)!=nY) flError = true;
	if (0 /*LBound(arI,3)*/!=0) flError = true;
	if (arI.UBound(3)!=nZ) flError = true;
	AddEventToList(flError, "Redim arI(nX, nY, nZ)");

	// ---------------------------------------
	// VBto upgrade warning: arI As short	OnWrite(int)
	 arI.ReDimPreserve(nX + 1,nY + 1,3*nZ + 1);
	flError = false;
	for(i=0; i<=nX; i++) {
		for(j=0; j<=nY; j++) {
			for(k=nZ+1; k<=3*nZ; k++) {
				if (arI(i, j, k)!=0) flError = true;
				arI(i, j, k) = i*100+j*10+k;
			}
		}
	}

	for(i=0; i<=nX; i++) {
		for(j=0; j<=nY; j++) {
			for(k=0; k<=3*nZ; k++) {
				if (arI(i, j, k)!=(i*100+j*10+k)) flError = true;
			}
		}
	}
	if (0 /*LBound(arI,1)*/!=0) flError = true;
	if (arI.UBound(1)!=nX) flError = true;
	if (0 /*LBound(arI,2)*/!=0) flError = true;
	if (arI.UBound(2)!=nY) flError = true;
	if (0 /*LBound(arI,3)*/!=0) flError = true;
	if (arI.UBound(3)!=3*nZ) flError = true;
	AddEventToList(flError, "Redim Preserve arI(nX, nY, 3*nZ)");

	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	 arS.ReDim(nX + 1,nY + 1,nZ + 1,nZ + 1);
	flError = false;
	for(i=0; i<=nX; i++) {
		for(j=0; j<=nY; j++) {
			for(k=0; k<=nZ; k++) {
				for(t=0; t<=nZ; t++) {
					if (arS(i, j, k, t)!="") flError = true;
					arS(i, j, k, t) = Str(i)+Str(j)+Str(k)+Str(t);
				}
			}
		}
	}

	for(i=0; i<=nX; i++) {
		for(j=0; j<=nY; j++) {
			for(k=0; k<=nZ; k++) {
				for(t=0; t<=nZ; t++) {
					if (arS(i, j, k, t)!=(Str(i)+Str(j)+Str(k)+Str(t))) flError = true;
				}
			}
		}
	}
	if (0 /*LBound(arS,1)*/!=0) flError = true;
	if (arS.UBound(1)!=nX) flError = true;
	if (0 /*LBound(arS,2)*/!=0) flError = true;
	if (arS.UBound(2)!=nY) flError = true;
	if (0 /*LBound(arS,3)*/!=0) flError = true;
	if (arS.UBound(3)!=nZ) flError = true;
	if (0 /*LBound(arS,4)*/!=0) flError = true;
	if (arS.UBound(4)!=nZ) flError = true;
	AddEventToList(flError, "Redim arS(nX, nY, nZ, nZ)");

	// ---------------------------------------
	 arS.ReDimPreserve(nX + 1,nY + 1,nZ + 1,2*nZ + 1);
	flError = false;
	for(i=0; i<=nX; i++) {
		for(j=0; j<=nY; j++) {
			for(k=0; k<=nZ; k++) {
				for(t=nZ+1; t<=2*nZ; t++) {
					if (arS(i, j, k, t)!="") flError = true;
					arS(i, j, k, t) = Str(i)+Str(j)+Str(k)+Str(t);
				}
			}
		}
	}

	for(i=0; i<=nX; i++) {
		for(j=0; j<=nY; j++) {
			for(k=0; k<=nZ; k++) {
				for(t=0; t<=2*nZ; t++) {
					if (arS(i, j, k, t)!=(Str(i)+Str(j)+Str(k)+Str(t))) flError = true;
				}
			}
		}
	}
	if (0 /*LBound(arS,1)*/!=0) flError = true;
	if (arS.UBound(1)!=nX) flError = true;
	if (0 /*LBound(arS,2)*/!=0) flError = true;
	if (arS.UBound(2)!=nY) flError = true;
	if (0 /*LBound(arS,3)*/!=0) flError = true;
	if (arS.UBound(3)!=nZ) flError = true;
	if (0 /*LBound(arS,4)*/!=0) flError = true;
	if (arS.UBound(4)!=2*nZ) flError = true;
	AddEventToList(flError, "Redim arS(nX, nY, nZ, 2*nZ)");

	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	// ?????????????
	// ReDim Preserve arS(nX, nY, nZ, 2 * nZ), arF(2 * nY), arI(nX, nY, 17 * nZ)
	// ReDim arQ1(nX, nY, nZ, 2 * nZ) As Single, arQ2(2 * nY) As Integer, arI(nX, nY, 17 * nZ, nZ): AddEventToList flError, "ar34(i,j)"
	// ReDim arI(-5 To 3 * nZ)


#else
	m_ListBoxEvents.AddString("Current version VBto Converter supported conversion ReDim only to MS VC++, C++ Builder");

#endif


	// ---------------------------------------
	 const short nS=10; 
	 CVBtoArrayPtr <CString> arS1; 
	 arS1.ReDim(nS + 1);

	for(i=0; i<=nS; i++) {
		arS1[i] = "s";
		arS1[i] = arS1[i]+Str(i);
	}

	flError = false;
	for(i=0; i<=nS; i++) {
		if (arS1[i]!=("s"+Str(i))) {
			flError = true;
		}
	}
	AddEventToList(flError, "Redim sa() As String");

	// ---------------------------------------

#if DemoOnly
	 CString p1,  p2,  p3; 
	QQ1(p1, p2, p3, arS1, arS);
	QQ2(p1, p2, p3, arS1, arS);

#endif

}

void CfrmTestReDim::QQ1(CString p1, CString p2, CString p3, CVBtoArrayPtr <CString> &m1, CVBtoArrayPtr <CString> &m2)
{
	// 
}
void CfrmTestReDim::QQ2(CString& p1, CString& p2, CString p3, CVBtoArrayPtr <CString> &m1, CVBtoArrayPtr <CString> &m2)
{
	p1 = "v";
	p2 = "v";
	p3 = "v";
}
