// frmTestString.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestString)
//}}VBto_Converter_Includes

#include "frmTestString.h"
CfrmTestString *frmTestString = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestString dialog



CfrmTestString::CfrmTestString(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestString::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestString) frmTestString = this;
}

void CfrmTestString::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestString)
	DDX_Control(pDX, LabelSource, m_LabelSource);
	DDX_Control(pDX, Label2, m_Label2);
	DDX_Control(pDX, LabelParam1, m_LabelParam1);
	DDX_Control(pDX, LabelParam2, m_LabelParam2);
	DDX_Control(pDX, Label3, m_Label3);
	DDX_Control(pDX, TextSource, m_TextSource);
	DDX_Control(pDX, ComboBoxActionText, m_ComboBoxActionText);
	DDX_Control(pDX, FrameResultText, m_FrameResultText);
	DDX_Control(pDX, LabelResultText, m_LabelResultText);
	DDX_Control(pDX, TextResultText, m_TextResultText);
	DDX_Control(pDX, CheckResultText, m_CheckResultText);
	DDX_Control(pDX, OptionResultText, m_OptionResultText);
	DDX_Control(pDX, CommandResultText, m_CommandResultText);
	DDX_Control(pDX, TextParam1, m_TextParam1);
	DDX_Control(pDX, TextParam2, m_TextParam2);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestString, CDialog)
	//{{AFX_MSG_MAP(CfrmTestString)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(TextParam1, ChangeTextParam1)
	ON_EN_CHANGE(TextParam2, ChangeTextParam2)
	ON_EN_CHANGE(TextSource, ChangeTextSource)
	ON_CBN_SELCHANGE(ComboBoxActionText, SelchangeComboBoxActionText)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestString message handlers

BOOL CfrmTestString::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestString)
	m_TextSource	.SetWindowText("1\" 2\"\" 3\"\"\" /\\~!@#$%^&*()-+';:|?");
	m_ComboBoxActionText	.AddString("Copy");
	m_ComboBoxActionText	.AddString("UCase");
	m_ComboBoxActionText	.AddString("LCase");
	m_ComboBoxActionText	.AddString("StrReverse");
	m_ComboBoxActionText	.AddString("Trim");
	m_ComboBoxActionText	.AddString("LTrim");
	m_ComboBoxActionText	.AddString("RTrim");
	m_ComboBoxActionText	.AddString("Mid");
	m_ComboBoxActionText	.AddString("Left");
	m_ComboBoxActionText	.AddString("Right");
	m_ComboBoxActionText	.AddString("InStr");
	m_ComboBoxActionText	.AddString("InStrRev");
	m_ComboBoxActionText	.AddString("Len");
	m_ComboBoxActionText	.AddString("Asc");
	m_ComboBoxActionText	.AddString("Hex");
	m_ComboBoxActionText	.AddString("Oct");
	m_ComboBoxActionText	.AddString("String");
	m_ComboBoxActionText	.AddString("Space");
	
	
	Form_Load();
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestString::OnPaint() 
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
HCURSOR CfrmTestString::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================



CString CfrmTestString::GetNewString(CString S)
{
	CString GetNewString;
	 int Start,  Leng; 

	if (::GetWindowText(m_ComboBoxActionText)=="Copy") {
		GetNewString = S;
		return GetNewString;
	}

	 CString cs; 
	cs = ::GetWindowText(m_ComboBoxActionText);

	if (cs=="UCase") GetNewString = UCase(S);
	if (cs=="UCase") return GetNewString;

	if (cs=="LCase") { GetNewString = LCase(S); return GetNewString; }

	if (cs=="StrReverse") {
		GetNewString = StrReverse(S);
		return GetNewString;
	} else if (::GetWindowText(m_ComboBoxActionText)=="Trim") {
		GetNewString = Trim(S);
		return GetNewString;
	} else if (cs=="LTrim") {
		GetNewString = LTrim(S);
		return GetNewString;
	} else if (cs=="RTrim") {
		GetNewString = RTrim(S);
		return GetNewString;
	}

	if ((cs=="Mid")) {

		if (!IsNumeric(strStart)) {
			GetNewString = "Inavlid \"Start\"";
			return GetNewString;
		}

		Start = CLng(strStart);
		if (Start<=0) {
			GetNewString = "Inavlid \"Start\"";
			return GetNewString;
		}

		if (IsNumeric(strLength)) {
			Leng = CLng(strLength);
			if (Leng<0) {
				GetNewString = "Inavlid \"Start\"";
				return GetNewString;
			}
			GetNewString = CString(S).Mid(Start-1, Leng);
		} else {
			GetNewString = CString(S).Mid(Start-1);
		}

		return GetNewString;
	}

	if ((cs=="Left") || (cs=="Right") || (cs=="Space") || (cs=="Hex") || (cs=="Oct") || (cs=="String") || (cs=="Asc")) {

		if (!IsNumeric(strLength)) {
			GetNewString = "Inavlid \"Length\"";
			return GetNewString;
		}

		Leng = CLng(strLength);
		if (Leng<0) {
			GetNewString = "Inavlid \"Length\"";
			return GetNewString;
		}

		if (cs=="Right") GetNewString = S.Right(Leng);
		if (cs=="Left") GetNewString = S.Left(Leng);

		if (cs=="Space") GetNewString = "Space("+FormatVB(Leng)+") = \""+CString(' ',Leng)+"\"";
		if (cs=="String") GetNewString = "String("+FormatVB(Leng)+", \""+S+"\") = \""+CString(S[0], Leng)+"\"";
		if (cs=="Hex") GetNewString = "Hex("+FormatVB(Leng)+") = "+Hex(Leng);
		if (cs=="Oct") GetNewString = "Oct("+FormatVB(Leng)+") = "+Oct(Leng);
		if (cs=="Asc") GetNewString = "Asc(\""+S+"\") = "+Str(Asc(S));

		return GetNewString;

	} else if ((cs=="InStr") || (cs=="InStrRev")) {

		if (!IsNumeric(strStart)) {
			GetNewString = "Inavlid \"Start\"";
			return GetNewString;
		}

		Start = CLng(strStart);
		if (Start<=0) {
			GetNewString = "Inavlid \"Start\"";
			return GetNewString;
		}

		 short ps; 

		if (cs=="InStr") {
			ps = (1+S.Find(strFind));
			ps = (1+S.Find(strFind, Start-1));
			ps = (1+S.Find(strFind, Start-1) /*? , vbTextCompare */ );
		} else {
			ps = InStrRev(S, strFind);
			ps = InStrRev(S, strFind, Start);
			ps = InStrRev(S, strFind, Start /*? , vbTextCompare */ );
		}

		GetNewString = "pos ="+Str(ps);

	} else if (cs=="Len") {
		// VBto upgrade warning: n As short	OnWrite(int)
		 short n; 
		n = S.GetLength();
		GetNewString = "Len(\""+S+"\")="+Str(n);

	}

	return GetNewString;
}

void CfrmTestString::ActionText()
{
	 CString sResult; 
	sResult = GetNewString(::GetWindowText(m_TextSource));

	m_FrameResultText.SetWindowText(sResult);
	m_TextResultText.SetWindowText(sResult);
	m_LabelResultText.SetWindowText(sResult);
	m_CheckResultText.SetWindowText(sResult);
	m_OptionResultText.SetWindowText(sResult);
	m_CommandResultText.SetWindowText(sResult);

}

void CfrmTestString::ChangeTextParam1()
{
	// TODO: Add your control notification handler code here
	 CString cs; 
	cs = ::GetWindowText(m_ComboBoxActionText);
	if ((cs=="Mid") || (cs=="InStr") || (cs=="InStrRev")) {
		strStart = ::GetWindowText(m_TextParam1);
	}

	ActionText();
}
void CfrmTestString::ChangeTextParam2()
{
	// TODO: Add your control notification handler code here
	 CString cs; 
	cs = ::GetWindowText(m_ComboBoxActionText);
	if ((cs=="Mid") || (cs=="Left") || (cs=="Right") || (cs=="Space") || (cs=="Hex") || (cs=="Oct") || (cs=="String")) {
		strLength = ::GetWindowText(m_TextParam2);
	}
	if ((cs=="InStr") || (cs=="InStrRev")) {
		strFind = ::GetWindowText(m_TextParam2);
	}

	ActionText();
}

void CfrmTestString::ChangeTextSource()
{
	// TODO: Add your control notification handler code here
	ActionText();
}

void CfrmTestString::SelchangeComboBoxActionText()
{
	// TODO: Add your control notification handler code here
	 CString cs; 
	cs = ::GetWindowText(m_ComboBoxActionText);

	m_TextSource.ShowWindow(!((cs=="Space") || (cs=="Hex") || (cs=="Oct")) ? SW_SHOW : SW_HIDE);
	m_LabelSource.ShowWindow(m_TextSource.IsWindowVisible() ? SW_SHOW : SW_HIDE);

	if (cs=="Mid") {
		m_LabelParam1.SetWindowText("Start:"); m_TextParam1.SetWindowText(strStart);
		m_LabelParam2.SetWindowText("Length (or empty):"); m_TextParam2.SetWindowText(strLength);
		m_LabelParam1.ShowWindow(SW_SHOW); m_TextParam1.ShowWindow(SW_SHOW);
		m_LabelParam2.ShowWindow(SW_SHOW); m_TextParam2.ShowWindow(SW_SHOW);
		m_TextParam1.SetFocus();
	} else if ((cs=="Left") || (cs=="Right") || (cs=="Space") || (cs=="String")) {
		m_LabelParam1.ShowWindow(SW_HIDE); m_TextParam1.ShowWindow(SW_HIDE);
		m_LabelParam2.SetWindowText("Length:"); m_TextParam2.SetWindowText(strLength);
		m_LabelParam2.ShowWindow(SW_SHOW); m_TextParam2.ShowWindow(SW_SHOW);
		m_TextParam2.SetFocus();
	} else if ((cs=="InStr") || (cs=="InStrRev")) {
		m_LabelParam1.SetWindowText("Start:"); m_TextParam1.SetWindowText(strStart);
		m_LabelParam2.SetWindowText("Find string:"); m_TextParam2.SetWindowText(strFind);
		m_LabelParam1.ShowWindow(SW_SHOW); m_TextParam1.ShowWindow(SW_SHOW);
		m_LabelParam2.ShowWindow(SW_SHOW); m_TextParam2.ShowWindow(SW_SHOW);
		m_TextParam2.SetFocus();
	} else if ((cs=="Hex") || (cs=="Oct")) {
		m_LabelParam2.SetWindowText("Number:"); m_TextParam2.SetWindowText(strLength);
		m_LabelParam1.ShowWindow(SW_HIDE); m_TextParam1.ShowWindow(SW_HIDE);
		m_LabelParam2.ShowWindow(SW_SHOW); m_TextParam2.ShowWindow(SW_SHOW);
		m_TextParam2.SetFocus();
	} else {
		m_TextSource.SetFocus();
		m_LabelParam1.ShowWindow(SW_HIDE); m_TextParam1.ShowWindow(SW_HIDE);
		m_LabelParam2.ShowWindow(SW_HIDE); m_TextParam2.ShowWindow(SW_HIDE);
	}

	ActionText();

}

void CfrmTestString::Form_Load()
{

	 const CString PatternStr="1\" 2\"\" 3\"\"\" /\\~!@#$%^&*()-+';:|?"; 
	if (::GetWindowText(m_TextSource)!=PatternStr) {
		 CString S; 
		S = "Error on compare following strings:";
		S += CString("\r\n")+PatternStr;
		S += CString("\r\n")+Str(::GetWindowText(m_TextSource));
		AfxMessageBox(S,MB_ICONSTOP);
	}
	m_TextSource.SetWindowText("  Text Any Text 1234567890 !  ");


	 CString lS,  rS; 
	rS = "1234";

	lS = "Input String";
	RSet(lS, rS);
	if (lS!="        1234") AfxMessageBox("Error on RSet",MB_ICONSTOP);

	lS = "Input String";
	LSet(lS, rS);
	if (lS!="1234        ") AfxMessageBox("Error on LSet",MB_ICONSTOP);

	rS = "12Input String34";
	lS = "Input String";
	RSet(lS, rS);
	if (lS!="12Input Stri") AfxMessageBox("Error on RSet",MB_ICONSTOP);

	lS = "Input String";
	LSet(lS, rS);
	if (lS!="12Input Stri") AfxMessageBox("Error on LSet",MB_ICONSTOP);


	strStart = "9";
	strLength = "6";
	strFind = "xt";

	// ComboBoxActionText.ListIndex = 1
	// ActionText
}

