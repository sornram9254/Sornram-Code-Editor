// frmTestInputBox.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestInputBox)
//}}VBto_Converter_Includes

#include "frmTestInputBox.h"
CfrmTestInputBox *frmTestInputBox = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestInputBox dialog



CfrmTestInputBox::CfrmTestInputBox(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestInputBox::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestInputBox) frmTestInputBox = this;
}

void CfrmTestInputBox::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestInputBox)
	DDX_Control(pDX, Label1, m_Label1);
	DDX_Control(pDX, Frame1, m_Frame1);
	DDX_Control(pDX, Label2, m_Label2);
	DDX_Control(pDX, Label3, m_Label3);
	DDX_Control(pDX, Label4, m_Label4);
	DDX_Control(pDX, Label5, m_Label5);
	DDX_Control(pDX, Label6, m_Label6);
	DDX_Control(pDX, CmdInputBox1, m_CmdInputBox1);
	DDX_Control(pDX, txtPrompt, m_txtPrompt);
	DDX_Control(pDX, txtTitle, m_txtTitle);
	DDX_Control(pDX, txtDefault, m_txtDefault);
	DDX_Control(pDX, txtResult, m_txtResult);
	DDX_Control(pDX, CmdInputBox2, m_CmdInputBox2);
	DDX_Control(pDX, CmdInputBox3, m_CmdInputBox3);
	DDX_Control(pDX, CmdInputBox5, m_CmdInputBox5);
	DDX_Control(pDX, txtXPos, m_txtXPos);
	DDX_Control(pDX, txtYPos, m_txtYPos);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestInputBox, CDialog)
	//{{AFX_MSG_MAP(CfrmTestInputBox)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(CmdInputBox1, OnCmdInputBox1)
	ON_BN_CLICKED(CmdInputBox2, OnCmdInputBox2)
	ON_BN_CLICKED(CmdInputBox3, OnCmdInputBox3)
	ON_BN_CLICKED(CmdInputBox5, OnCmdInputBox5)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestInputBox message handlers

BOOL CfrmTestInputBox::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestInputBox)
	m_txtPrompt	.SetWindowText("prompt ...");
	m_txtTitle	.SetWindowText("title ...");
	m_txtDefault	.SetWindowText("default value ...");
	m_txtXPos	.SetWindowText("20");
	m_txtYPos	.SetWindowText("40");
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestInputBox::OnPaint() 
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
HCURSOR CfrmTestInputBox::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================

// Displays a prompt in a dialog box and returns user input text
// Function InputBox(Prompt, [Title], [Default], [XPos], [YPos], [HelpFile], [Context]) As String

void CfrmTestInputBox::OnCmdInputBox1()
{
	// TODO: Add your control notification handler code here
	m_txtResult.SetWindowText(InputBox(::GetWindowText(m_txtPrompt)));
}

void CfrmTestInputBox::OnCmdInputBox2()
{
	// TODO: Add your control notification handler code here
	m_txtResult.SetWindowText(InputBox(::GetWindowText(m_txtPrompt), ::GetWindowText(m_txtTitle)));
}

void CfrmTestInputBox::OnCmdInputBox3()
{
	// TODO: Add your control notification handler code here
	m_txtResult.SetWindowText(InputBox(::GetWindowText(m_txtPrompt), ::GetWindowText(m_txtTitle), ::GetWindowText(m_txtDefault)));
}

void CfrmTestInputBox::OnCmdInputBox5()
{
	// TODO: Add your control notification handler code here
	// VBto upgrade warning: iXPos As int	OnWrite(double)
	// VBto upgrade warning: iYPos As int	OnWrite(double)
	 int iXPos,  iYPos; 
	iXPos = Round(Val(::GetWindowText(m_txtXPos)));
	iYPos = Round(Val(::GetWindowText(m_txtYPos)));
	m_txtResult.SetWindowText(InputBox(::GetWindowText(m_txtPrompt), ::GetWindowText(m_txtTitle), ::GetWindowText(m_txtDefault), iXPos, iYPos));
}
