// frmTestMsgBox.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestMsgBox)
//}}VBto_Converter_Includes

#include "frmTestMsgBox.h"
CfrmTestMsgBox *frmTestMsgBox = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestMsgBox dialog



CfrmTestMsgBox::CfrmTestMsgBox(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestMsgBox::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestMsgBox) frmTestMsgBox = this;
}

void CfrmTestMsgBox::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestMsgBox)
	DDX_Control(pDX, Label1, m_Label1);
	DDX_Control(pDX, Command1, m_Command1);
	DDX_Control(pDX, Command2, m_Command2);
	DDX_Control(pDX, Command3, m_Command3);
	DDX_Control(pDX, Command4, m_Command4);
	DDX_Control(pDX, Command5, m_Command5);
	DDX_Control(pDX, Command6, m_Command6);
	DDX_Control(pDX, Command7, m_Command7);
	DDX_Control(pDX, Command8, m_Command8);
	DDX_Control(pDX, Command9, m_Command9);
	DDX_Control(pDX, Command10, m_Command10);
	DDX_Control(pDX, Command11, m_Command11);
	DDX_Control(pDX, Command0, m_Command0);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestMsgBox, CDialog)
	//{{AFX_MSG_MAP(CfrmTestMsgBox)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(Command0, OnCommand0)
	ON_BN_CLICKED(Command1, OnCommand1)
	ON_BN_CLICKED(Command2, OnCommand2)
	ON_BN_CLICKED(Command3, OnCommand3)
	ON_BN_CLICKED(Command4, OnCommand4)
	ON_BN_CLICKED(Command5, OnCommand5)
	ON_BN_CLICKED(Command6, OnCommand6)
	ON_BN_CLICKED(Command7, OnCommand7)
	ON_BN_CLICKED(Command8, OnCommand8)
	ON_BN_CLICKED(Command9, OnCommand9)
	ON_BN_CLICKED(Command10, OnCommand10)
	ON_BN_CLICKED(Command11, OnCommand11)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestMsgBox message handlers

BOOL CfrmTestMsgBox::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestMsgBox)
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestMsgBox::OnPaint() 
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
HCURSOR CfrmTestMsgBox::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================

void CfrmTestMsgBox::OnCommand0()
{
	// TODO: Add your control notification handler code here
	AfxMessageBox("Hello N 0");
}
void CfrmTestMsgBox::OnCommand1()
{
	// TODO: Add your control notification handler code here
	AfxMessageBox(("Hello N 1"));
}
void CfrmTestMsgBox::OnCommand2()
{
	// TODO: Add your control notification handler code here
	AfxMessageBox("Hello "+CString("N ")+"2",MB_ICONSTOP);
}
void CfrmTestMsgBox::OnCommand3()
{
	// TODO: Add your control notification handler code here
	::MessageBox(NULL, ("Hello "+CString("N 3")),"My Title",MB_ICONINFORMATION);
}
void CfrmTestMsgBox::OnCommand4()
{
	// TODO: Add your control notification handler code here
	::MessageBox(NULL, "Hello N 4","My Title",MB_ICONQUESTION);
}
void CfrmTestMsgBox::OnCommand5()
{
	// TODO: Add your control notification handler code here
	::MessageBox(NULL, "Hello N 5","My Title !!",MB_OK);
}

// VBto upgrade warning: ret As VbMsgBoxResult	OnWrite(VbMsgBoxResult, int)
void CfrmTestMsgBox::retOut(int ret)
{
	 CString S; 
	switch (ret) {
		case IDABORT:
		{

			S = "Selected: "+CString("vbAbort");
			AfxMessageBox(" "+S+" ");
			return;
		}
		case IDCANCEL:
		{
			S = "vbCancel";
			break;
		}
		case IDIGNORE:
		{
			S = "vbIgnore";
			break;
		}
		case IDNO:
		{
			S = "vbNo";
			break;
		}
		case IDOK:
		{
			S = "vbOK";
			break;
		}
		case IDRETRY:
		{
			S = "vbRetry";
			break;
		}
		case IDYES:
		{
			S = "vbYes";
			break;
		}
		default: {
			S = "Unknown";
			break;
		}
	} //end switch
	AfxMessageBox("Selected: "+S);
}

void CfrmTestMsgBox::OnCommand6()
{
	// TODO: Add your control notification handler code here
	// VBto upgrade warning: ret As VbMsgBoxResult	OnWrite(int)
	 int ret; 
	ret = ::MessageBox(NULL, "Prompt (vbYesNo)","Title",MB_YESNO);
	retOut(ret);
}
void CfrmTestMsgBox::OnCommand7()
{
	// TODO: Add your control notification handler code here
	retOut(::MessageBox(NULL, "Prompt (vbYesNoCancel)","Title",MB_YESNOCANCEL));
}
void CfrmTestMsgBox::OnCommand8()
{
	// TODO: Add your control notification handler code here
	retOut((::MessageBox(NULL, "Prompt (vbOKCancel)","Title",MB_OKCANCEL)));
}
void CfrmTestMsgBox::OnCommand9()
{
	// TODO: Add your control notification handler code here
	retOut((::MessageBox(NULL, "Prompt (vbRetryCancel + vbExclamation)","Title",MB_RETRYCANCEL+MB_ICONEXCLAMATION)));
}
void CfrmTestMsgBox::OnCommand10()
{
	// TODO: Add your control notification handler code here
	retOut(((::MessageBox(NULL, "Prompt (vbAbortRetryIgnore)","Title",MB_ABORTRETRYIGNORE+MB_ICONINFORMATION))));
}
void CfrmTestMsgBox::OnCommand11()
{
	// TODO: Add your control notification handler code here
	 CString Prompt,  Title; 
	Prompt = "Prompt (vbOKOnly+vbQuestion)";
	Title = "My Title";
	retOut(::MessageBox(NULL, Prompt,Title,MB_OK+MB_ICONQUESTION));
}
