// frmTestLike.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestLike)
//}}VBto_Converter_Includes

#include "frmTestLike.h"
CfrmTestLike *frmTestLike = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestLike dialog



CfrmTestLike::CfrmTestLike(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestLike::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestLike) frmTestLike = this;
}

void CfrmTestLike::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestLike)
	DDX_Control(pDX, ListBoxResults, m_ListBoxResults);
	DDX_Control(pDX, CmdTest, m_CmdTest);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestLike, CDialog)
	//{{AFX_MSG_MAP(CfrmTestLike)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(CmdTest, OnCmdTest)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestLike message handlers

BOOL CfrmTestLike::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestLike)
	
	Form_Load();
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestLike::OnPaint() 
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
HCURSOR CfrmTestLike::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================

void CfrmTestLike::Form_Load()
{
	m_ListBoxResults.ResetContent();
	TestLike();
}

void CfrmTestLike::OnCmdTest()
{
	// TODO: Add your control notification handler code here
	m_ListBoxResults.ResetContent();
	TestLike();
}

void CfrmTestLike::AddResult(CString Test, bool Result, bool ResultOk)
{
	 CString Mess; 

	if (Result==ResultOk) {
		Mess = "Ok on test:    ";
	} else {
		Mess = "Error on test  ";
	}

	Mess += Test+" = ";
	if (ResultOk) {
		Mess += "True";
	} else {
		Mess += "False";
	}

	m_ListBoxResults.AddString(Mess);
}

void CfrmTestLike::TestLike()
{

	// Like Operator Example
	// This example uses the Like operator to compare a string to a pattern
	// The pattern-matching features allow you to use wildcard characters, character lists, or character ranges, in any combination, to match strings. The following table shows the characters allowed in pattern and what they match:
	// Characters in pattern   Matches in string
	// ?   Any single character.
	// *   Zero or more characters.
	// #   Any single digit (0-9).
	// [charlist]  Any single character in charlist.
	// [!charlist] Any single character not in charlist.

	 bool MyCheck; CString S; 
	S = "abcd";

	MyCheck = Like(S, "ab"); // Returns False
	AddResult("\"abcd\" Like \"ab\"", MyCheck, false);

	MyCheck = Like(S, "ab*"); // Returns True
	AddResult("\"abcd\" Like \"ab*\"", MyCheck, true);

	MyCheck = Like(S, "AB*"); // Returns False
	AddResult("\"abcd\" Like \"AB*\"", MyCheck, false);

	MyCheck = Like("aBBBa", "a*a"); // Returns True
	AddResult("\"aBBBa\" Like \"a*a\"", MyCheck, true);

	MyCheck = Like("F", "[A-Z]"); // Returns True
	AddResult("\"F\" Like \"[A-Z]\"", MyCheck, true);

	MyCheck = Like("F", "[!A-Z]"); // Returns False
	AddResult("\"F\" Like \"[!A-Z]\"", MyCheck, false);

	MyCheck = Like("a2a", "a#a"); // Returns True
	AddResult("\"a2a\" Like \"a#a\"", MyCheck, true);

	MyCheck = Like("aM5b", "a[L-P]#[!c-e]"); // Returns True
	AddResult("\"aM5b\" Like \"a[L-P]#[!c-e]\"", MyCheck, true);

	MyCheck = Like("BAT123khg", "B?T*"); // Returns True
	AddResult("\"BAT123khg\" Like \"B?T*\"", MyCheck, true);

	MyCheck = Like("CAT123khg", "B?T*"); // Returns False
	AddResult("\"CAT123khg\" Like \"B?T*\"", MyCheck, false);

}
