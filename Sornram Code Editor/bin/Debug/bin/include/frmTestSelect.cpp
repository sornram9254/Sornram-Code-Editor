// frmTestSelect.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestSelect)
//}}VBto_Converter_Includes

#include "frmTestSelect.h"
CfrmTestSelect *frmTestSelect = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestSelect dialog



CfrmTestSelect::CfrmTestSelect(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestSelect::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestSelect) frmTestSelect = this;
}

void CfrmTestSelect::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestSelect)
	DDX_Control(pDX, LabelMess, m_LabelMess);
	DDX_Control(pDX, Label2, m_Label2);
	DDX_Control(pDX, Label6, m_Label6);
	DDX_Control(pDX, Label7, m_Label7);
	DDX_Control(pDX, Label8, m_Label8);
	DDX_Control(pDX, Label1, m_Label1);
	DDX_Control(pDX, Label9, m_Label9);
	DDX_Control(pDX, TextSelect, m_TextSelect);
	DDX_Control(pDX, ComboSelect, m_ComboSelect);
	DDX_Control(pDX, ComboTestNumber, m_ComboTestNumber);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestSelect, CDialog)
	//{{AFX_MSG_MAP(CfrmTestSelect)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(ComboTestNumber, SelchangeComboTestNumber)
	ON_CBN_EDITCHANGE(ComboSelect, EditchangeComboSelect)
	ON_CBN_SELCHANGE(ComboSelect, SelchangeComboSelect)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestSelect message handlers

BOOL CfrmTestSelect::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestSelect)
	m_ComboTestNumber	.AddString("1");
	m_ComboTestNumber	.AddString("2");
	m_ComboTestNumber	.AddString("3");
	m_ComboTestNumber	.AddString("4");
	
	
	fm_LabelMess.Set(GetDlgItem(LabelMess), RGB(255,0,0), GetSysColor(COLOR_BTNFACE),"MS Sans Serif",9.75,false,false,false,false,RUSSIAN_CHARSET);
	fm_Label1.Set(GetDlgItem(Label1), GetSysColor(COLOR_HIGHLIGHT), GetSysColor(COLOR_BTNFACE),"MS Sans Serif",12,false,false,false,false,RUSSIAN_CHARSET);
	fm_TextSelect.Set(GetDlgItem(TextSelect), GetSysColor(COLOR_WINDOWTEXT), GetSysColor(COLOR_SCROLLBAR));
	
	
	Form_Load();
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestSelect::OnPaint() 
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
HCURSOR CfrmTestSelect::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================

void CfrmTestSelect::Form_Load()
{
	m_ComboTestNumber.SetCurSel(0);
	OnChangeTest();
}

void CfrmTestSelect::OnChangeTest()
{

	m_TextSelect.SetWindowText("");
	m_ComboSelect.ResetContent();
	m_LabelMess.SetWindowText("");

	switch (m_ComboTestNumber.GetCurSel()) {
		case 0:
		{


			m_TextSelect.SetWindowText("Select Case test"+CString("\r\n")+"    Case 0"+"\r\n"+"        OutMess \"0\""+"\r\n"+"    Case 7, 77"+"\r\n"+"        OutMess \"7 or 77\""+"\r\n"+"    Case 33"+"\r\n"+"        OutMess \"33\""+"\r\n"+"    Case Else"+"\r\n"+"        OutMess \"Else\""+"\r\n"+"End Select");
			m_ComboSelect.AddString("0");
			m_ComboSelect.AddString("7");
			m_ComboSelect.AddString("33");
			m_ComboSelect.AddString("51");
			m_ComboSelect.AddString("77");

#if VB6 || VBtoVBNET
			m_ComboSelect.AddString("&H21");

#endif

			break;
		}
		case 1:
		{
			m_TextSelect.SetWindowText("Select Case test"+CString("\r\n")+"    Case \"0\""+"\r\n"+"        OutMess \"0\""+"\r\n"+"    Case \"qq\""+"\r\n"+"        OutMess \"qq\""+"\r\n"+"    Case Else"+"\r\n"+"        OutMess \"Else\""+"\r\n"+"End Select");
			m_ComboSelect.AddString("0");
			m_ComboSelect.AddString("QQ");
			m_ComboSelect.AddString("qq");
			m_ComboSelect.AddString("any text");

			break;
		}
		case 2:
		{
			m_TextSelect.SetWindowText("Select Case test"+CString("\r\n")+"    Case 0"+"\r\n"+"        OutMess \"0\""+"\r\n"+"    Case 7, 77"+"\r\n"+"        OutMess \"7 or 77\""+"\r\n"+"    Case 21, 23, 33 To 53"+"\r\n"+"        OutMess \"21, 23, 33 To 53\""+"\r\n"+"    Case Else"+"\r\n"+"        OutMess \"Else\""+"\r\n"+"End Select");
			m_ComboSelect.AddString("0");
			m_ComboSelect.AddString("5");
			m_ComboSelect.AddString("7");
			m_ComboSelect.AddString("21");
			m_ComboSelect.AddString("33");
			m_ComboSelect.AddString("51");
			m_ComboSelect.AddString("77");

#if VB6 || VBtoVBNET
			m_ComboSelect.AddString("&H21");

#endif

			break;
		}
		case 3:
		{
			m_TextSelect.SetWindowText("Select Case test"+CString("\r\n")+"    Case Is < 0"+"\r\n"+"        OutMess \"Is < 0\""+"\r\n"+"    Case Is = 0"+"\r\n"+"        OutMess \"Is = 0\""+"\r\n"+"    Case 1"+"\r\n"+"        OutMess \"1\""+"\r\n"+"    Case Is > 3000"+"\r\n"+"        OutMess \"Is > 3000\""+"\r\n"+"    Case Is = 100, 200 To 205, 227, 300 To 305, Is > 400"+"\r\n"+"        OutMess \"Is = 100, 200 To 205, 227, 300 To 305, Is > 400\""+"\r\n"+"    Case Else"+"\r\n"+"        OutMess \"Else\""+"\r\n"+"End Select");
			m_ComboSelect.AddString("-1");
			m_ComboSelect.AddString("0");
			m_ComboSelect.AddString("3000");
			m_ComboSelect.AddString("3001");
			m_ComboSelect.AddString("100");
			m_ComboSelect.AddString("203");
			m_ComboSelect.AddString("300");
			m_ComboSelect.AddString("400");
			m_ComboSelect.AddString("401");

			break;
		}
	} //end switch

}

void CfrmTestSelect::SelchangeComboTestNumber()
{
	// TODO: Add your control notification handler code here
	OnChangeTest();
}

void CfrmTestSelect::OutMess(CString Mess)
{
	m_LabelMess.SetWindowText("Selected \""+Mess+"\"");
}

void CfrmTestSelect::Test0(CString TestExpression)
{
	if (!IsNumeric(TestExpression)) {
		m_LabelMess.SetWindowText("Please, input only numbers");
		return;
	}
	 int ii; 
	ii = CLng(TestExpression);
	switch (ii) {
		case 0:
		{

			OutMess("0");
			break;
		}
		case 7:
		case 77:
		{
			OutMess("7 or 77");
			break;
		}
		case 33:
		{
			OutMess("33");
			break;
		}
	} //end switch
	// -----------------
	switch (ii) {
		case 0:
		{

			OutMess("0");
			break;
		}
		case 7:
		case 77:
		{
			OutMess("7 or 77");
			break;
		}
		case 33:
		{
			OutMess("33");
			break;
		}
		default: {
			OutMess("Else");
			break;
		}
	} //end switch
}

void CfrmTestSelect::Test1(CString TestExpression)
{
	if (TestExpression=="0")
	{

		OutMess("0");
	}
	else if (TestExpression=="qq")
	{
		OutMess("qq");
	}
	// -----------------
	if (TestExpression=="0")
	{

		OutMess("0");
	}
	else if (TestExpression=="qq")
	{
		OutMess("qq");
	}
	else 
	{
		OutMess("Else");
	}
}

void CfrmTestSelect::Test2Int(short TestExpressionInt)
{
	if (TestExpressionInt==0)
	{

		OutMess("0");
	}
	else if ((TestExpressionInt==7) || (TestExpressionInt==77))
	{
		OutMess("7 or 77");
	}
	else if (TestExpressionInt>=33 && TestExpressionInt<=53)
	{
		OutMess("33 To 53");
	}
	// -----------------
	const short VBtoVar = TestExpressionInt+1-1;
	if (VBtoVar==0)
	{

		OutMess("0");
	}
	else if ((VBtoVar==7) || (VBtoVar==77))
	{
		OutMess("7 or 77");
	}
	else if ((VBtoVar==21) || (VBtoVar==23) || (VBtoVar>=33 && VBtoVar<=53))
	{
		OutMess("21, 23, 33 To 53");
	}
	else 
	{
		OutMess("Else");
	}

}
void CfrmTestSelect::Test2(CString TestExpression)
{
	if (!IsNumeric(TestExpression)) { m_LabelMess.SetWindowText("Please, input only numbers"); return; }
	Test2Int((CInt(TestExpression)));
}

void CfrmTestSelect::Test3(CString TestExpression)
{
	if (!IsNumeric(TestExpression)) { m_LabelMess.SetWindowText("Please, input only numbers"); return; }

	 double D; 
	D = CDbl(TestExpression);

	if (D==-1-D*D/2)
	{

		OutMess("Unresolved");
	}
	else if (D<0)
	{
		OutMess("Is < 0");
	}
	else if (D==0)
	{
		OutMess("Is = 0");
	}
	else if (D==1)
	{
		OutMess("1");
	}
	else if (D>3000)
	{
		OutMess("Is > 3000");
	}
	else if ((D==100) || (D>=200 && D<=205) || (D==227) || (D>=300 && D<=305) || (D>400))
	{
		OutMess("Is = 100, 200 To 205, 227, 300 To 305, Is > 400");
		// Case Else
		// OutMess "Else"
	}
	// -----------------
	const double VBtoVar = D+1-1;
	if (VBtoVar==-1-D*D/2)
	{

		OutMess("Unresolved");
	}
	else if (VBtoVar<0)
	{
		OutMess("Is < 0");
	}
	else if (VBtoVar==0)
	{
		OutMess("Is = 0");
	}
	else if (VBtoVar==1)
	{
		OutMess("1");
	}
	else if (VBtoVar>3000)
	{
		OutMess("Is > 3000");
	}
	else if ((VBtoVar==100) || (VBtoVar>=200 && VBtoVar<=205) || (VBtoVar==227) || (VBtoVar>=300 && VBtoVar<=305) || (VBtoVar>400))
	{
		OutMess("Is = 100, 200 To 205, 227, 300 To 305, Is > 400");
	}
	else 
	{
		OutMess("Else");
	}
	// -----------------
	const double VBtoVar1 = D+2-2;
	if (VBtoVar1==-1-D*D/2)
	{

		OutMess("Unresolved");
	}
	else if (VBtoVar1<0)
	{
		OutMess("Is < 0");
	}
	else if (VBtoVar1==0)
	{
		OutMess("Is = 0");
	}
	else if (VBtoVar1==1)
	{
		OutMess("1");
	}
	else if (VBtoVar1>3000)
	{
		OutMess("Is > 3000");
	}
	else if ((VBtoVar1==100) || (VBtoVar1>=200 && VBtoVar1<=205) || (VBtoVar1==227) || (VBtoVar1>=300 && VBtoVar1<=305) || (VBtoVar1>400))
	{
		OutMess("Is = 100, 200 To 205, 227, 300 To 305, Is > 400");
	}
	else 
	{
		OutMess("Else");
	}

}

void CfrmTestSelect::EditchangeComboSelect()
{
	// TODO: Add your message handler code here and/or call default
	switch (m_ComboTestNumber.GetCurSel()) {
		case 0:
		{

			Test0(::GetWindowText(m_ComboSelect));
			break;
		}
		case 1:
		{
			Test1(::GetWindowText(m_ComboSelect));
			break;
		}
		case 2:
		{
			Test2(::GetWindowText(m_ComboSelect));
			break;
		}
		case 3:
		{
			Test3(::GetWindowText(m_ComboSelect));
			break;
		}
	} //end switch
}
void CfrmTestSelect::SelchangeComboSelect()
{
	// TODO: Add your control notification handler code here

	switch (m_ComboTestNumber.GetCurSel()) {
		case 0:
		{


			Test0(GetText(m_ComboSelect, m_ComboSelect.GetCurSel()));

			break;
		}
		case 1:
		{
			Test1(GetText(m_ComboSelect, m_ComboSelect.GetCurSel()));

			break;
		}
		case 2:
		{
			// VBto upgrade warning: ind As short	OnWrite(int)
			 short ind; 
			ind = m_ComboSelect.GetCurSel();
			Test2(GetText(m_ComboSelect, ind));

			break;
		}
		case 3:
		{
			 CString TestExpression; 
			TestExpression = GetText(m_ComboSelect, m_ComboSelect.GetCurSel());
			Test3(TestExpression);

			break;
		}
	} //end switch

}

HBRUSH CfrmTestSelect::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch(pWnd->GetDlgCtrlID()) {
		case LabelMess:	return fm_LabelMess	.OnCtlColor(pDC);
		case Label1:	return fm_Label1	.OnCtlColor(pDC);
		case TextSelect:	return fm_TextSelect	.OnCtlColor(pDC);
	}
	return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}
