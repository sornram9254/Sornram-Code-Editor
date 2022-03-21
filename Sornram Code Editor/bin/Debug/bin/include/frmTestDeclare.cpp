// frmTestDeclare.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestDeclare)
//}}VBto_Converter_Includes

#include "frmTestDeclare.h"
CfrmTestDeclare *frmTestDeclare = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestDeclare dialog



CfrmTestDeclare::CfrmTestDeclare(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestDeclare::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestDeclare) frmTestDeclare = this;
}

void CfrmTestDeclare::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestDeclare)
	DDX_Control(pDX, Label1, m_Label1);
	DDX_Control(pDX, CmdShellExecute, m_CmdShellExecute);
	DDX_Control(pDX, Frame1, m_Frame1);
	DDX_Control(pDX, LabelX, m_LabelX);
	DDX_Control(pDX, LabelY, m_LabelY);
	DDX_Control(pDX, Frame2, m_Frame2);
	DDX_Control(pDX, LabelScreenArea, m_LabelScreenArea);
	DDX_Control(pDX, LabelNumberButtonsMouse, m_LabelNumberButtonsMouse);
	DDX_Control(pDX, Frame3, m_Frame3);
	DDX_Control(pDX, LabelComputerName, m_LabelComputerName);
	DDX_Control(pDX, Picture1, m_Picture1);
	DDX_Control(pDX, BtnRedraw, m_BtnRedraw);
	DDX_Control(pDX, CmdMsgBox, m_CmdMsgBox);
	DDX_Control(pDX, Frame0, m_Frame0);
	DDX_Control(pDX, Label2, m_Label2);
	DDX_Control(pDX, txtGetEnv, m_txtGetEnv);
	DDX_Control(pDX, CmdGetEnv, m_CmdGetEnv);
	DDX_Control(pDX, txtVariableName, m_txtVariableName);
	DDX_Control(pDX, CmdShellExecute2, m_CmdShellExecute2);
	DDX_Control(pDX, Frame4, m_Frame4);
	DDX_Control(pDX, LabelDate, m_LabelDate);
	DDX_Control(pDX, LabelTime, m_LabelTime);
	DDX_Control(pDX, CmdGetLocalTime, m_CmdGetLocalTime);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestDeclare, CDialog)
	//{{AFX_MSG_MAP(CfrmTestDeclare)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(txtVariableName, ChangetxtVariableName)
	ON_BN_CLICKED(CmdGetEnv, OnCmdGetEnv)
	ON_BN_CLICKED(CmdGetLocalTime, OnCmdGetLocalTime)
	ON_BN_CLICKED(BtnRedraw, OnBtnRedraw)
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(CmdMsgBox, OnCmdMsgBox)
	ON_BN_CLICKED(CmdShellExecute, OnCmdShellExecute)
	ON_BN_CLICKED(CmdShellExecute2, OnCmdShellExecute2)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestDeclare message handlers

BOOL CfrmTestDeclare::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestDeclare)
	m_tooltip	.Create(this);
	m_tooltip	.Activate(TRUE);
	m_tooltip	.AddTool(&m_txtVariableName, "Variable Name");
	m_txtVariableName	.SetWindowText("USERDOMAIN");
	
	fm_Label1.Set(GetDlgItem(Label1), RGB(0,128,0), GetSysColor(COLOR_BTNFACE),"MS Sans Serif",8.25,true,false,false,false,RUSSIAN_CHARSET);
	fm_Picture1.Set(GetDlgItem(Picture1), GetSysColor(COLOR_WINDOWTEXT), RGB(255,224,192));
	
	
	Form_Load();
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestDeclare::OnPaint() 
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
HCURSOR CfrmTestDeclare::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================

// This is a part of the VBto Converter (www.vbto.net)
// Copyright (C) 2005-2008 StressSoft Company Ltd. All rights reserved.


// --------------

 typedef	bool (WINAPI*RectangleTD)(int hdc, int x1, int y1, int x2, int y2);
 RectangleTD RectanglePtr;


 typedef	bool (WINAPI*EllipseTD)(int hdc, int x1, int y1, int x2, int y2);
 EllipseTD EllipsePtr;


 typedef	bool (WINAPI*ArcTD)(int hdc, int x1, int y1, int x2, int y2, int X3, int Y3, int X4, int Y4);
 ArcTD ArcPtr;


 typedef	bool (WINAPI*LineToTD)(int hdc, int X, int Y);
 LineToTD LineToPtr;


 typedef	bool (WINAPI*TextOutTD)(int hdc, int X, int Y, char* lpString, int nCount);
 TextOutTD TextOutPtr;
bool TextOutWrp(int hdc, int X, int Y, CString& lpString, int nCount) {
	bool ret = TextOutPtr(hdc, X, Y, lpString.LockBuffer(), nCount);
	lpString.UnlockBuffer();
	return ret;
}


 typedef	int (WINAPI*SetTextColorTD)(int hdc, int crColor);
 SetTextColorTD SetTextColorPtr;

// --------------

 typedef	int (WINAPI*GetEnvVarTD)(char* nameStr, char* buffer, int nSize);
 GetEnvVarTD GetEnvVarPtr;
int GetEnvVarWrp(CString& nameStr, CString& buffer, int nSize) {
	int ret = GetEnvVarPtr(nameStr.LockBuffer(), buffer.LockBuffer(), nSize);
	nameStr.UnlockBuffer();
	buffer.UnlockBuffer();
	return ret;
}


 typedef	bool (WINAPI*GetComputerNameTD)(char* lpBuffer, int* nSize);
 GetComputerNameTD GetComputerNamePtr;
bool GetComputerNameWrp(CString& lpBuffer, int& nSize) {
	bool ret = GetComputerNamePtr(lpBuffer.LockBuffer(), &nSize);
	lpBuffer.UnlockBuffer();
	return ret;
}



 typedef	void (WINAPI*GetLocalTimeTD)(CfrmTestDeclare::MySYSTEMTIME* lpSystemTime);
 GetLocalTimeTD GetLocalTimePtr;
void GetLocalTimeWrp(CfrmTestDeclare::MySYSTEMTIME& lpSystemTime) {
	GetLocalTimePtr(&lpSystemTime);
}

// --------------

 typedef	int (WINAPI*MsgBoxFromDLLTD)(int hWnd, char* txt, char* caption, int Typ);
 MsgBoxFromDLLTD MsgBoxFromDLLPtr;
int MsgBoxFromDLLWrp(int hWnd, CString txt, CString caption, int Typ) {
	int ret = MsgBoxFromDLLPtr(hWnd, txt.LockBuffer(), caption.LockBuffer(), Typ);
	txt.UnlockBuffer();
	caption.UnlockBuffer();
	return ret;
}

  /* const short SM_CXSCREEN=0; */ 
 const short SM_CXSCREEN0=0; 
  /* const short SM_CYSCREEN=1; */ 
  /* const short SM_CXFULLSCREEN=16; */ 
  /* const short SM_CYFULLSCREEN=17; */ 
  /* const short SM_CMOUSEBUTTONS=43; */ 

 typedef	int (WINAPI*GetSystemMetricsTD)(int nIndex);
 GetSystemMetricsTD GetSystemMetricsPtr;



 typedef	bool (WINAPI*GetCursorPosTD)(CfrmTestDeclare::POINTAPI* lpPoint);
 GetCursorPosTD GetCursorPosPtr;
bool GetCursorPosWrp(CfrmTestDeclare::POINTAPI& lpPoint) {
	bool ret = GetCursorPosPtr(&lpPoint);
	return ret;
}

// The ScreenToClient function converts the screen coordinates of a specified point on the screen to client-area coordinates

 typedef	bool (WINAPI*ScreenToClientFromDLLTD)(int hWnd, CfrmTestDeclare::POINTAPI* lpPoint);
 ScreenToClientFromDLLTD ScreenToClientFromDLLPtr;
bool ScreenToClientFromDLLWrp(int hWnd, CfrmTestDeclare::POINTAPI& lpPoint) {
	bool ret = ScreenToClientFromDLLPtr(hWnd, &lpPoint);
	return ret;
}

// --------------
// Performs an operation on a specified file
  /* const short SW_SHOWNORMAL=1; */ 
  /* const short SW_MAXIMIZE=3; */ 

 typedef	int (WINAPI*ShellExecuteTD)(int hWnd, char* lpOperation, char* lpFile, char* lpParameters, char* lpDirectory, int nShowCmd);
 ShellExecuteTD ShellExecutePtr;
int ShellExecuteWrp(int hWnd, CString lpOperation, CString lpFile, CString lpParameters, CString lpDirectory, int nShowCmd) {
	int ret = ShellExecutePtr(hWnd, lpOperation.LockBuffer(), lpFile.LockBuffer(), lpParameters.LockBuffer(), lpDirectory.LockBuffer(), nShowCmd);
	lpOperation.UnlockBuffer();
	lpFile.UnlockBuffer();
	lpParameters.UnlockBuffer();
	lpDirectory.UnlockBuffer();
	return ret;
}

// --------------

 typedef	int (WINAPI*WNetGetUserTD)(char* lpName, char* lpUserName, int* lpnLength);
 WNetGetUserTD WNetGetUserPtr;
int WNetGetUserWrp(CString lpName, CString& lpUserName, int& lpnLength) {
	int ret = WNetGetUserPtr(lpName.LockBuffer(), lpUserName.LockBuffer(), &lpnLength);
	lpName.UnlockBuffer();
	lpUserName.UnlockBuffer();
	return ret;
}

// Private Declare Function GetUserName Lib "C:\WINDOWS\system32\advapi32.dll" Alias "GetUserNameA" (ByVal lpBuffer As String, nSize As Long) As Boolean

 typedef	bool (WINAPI*GetUserNameTD)(char* lpBuffer, int* nSize);
 GetUserNameTD GetUserNamePtr;
bool GetUserNameWrp(CString& lpBuffer, int& nSize) {
	bool ret = GetUserNamePtr(lpBuffer.LockBuffer(), &nSize);
	lpBuffer.UnlockBuffer();
	return ret;
}

// --------------

void CfrmTestDeclare::ChangetxtVariableName()
{
	// TODO: Add your control notification handler code here
	m_txtGetEnv.SetWindowText("");
}
void CfrmTestDeclare::OnCmdGetEnv()
{
	// TODO: Add your control notification handler code here
	 CString varName,  buffer; 
	varName = ::GetWindowText(m_txtVariableName);
	buffer = CString(' ',4096);
	GetEnvVarWrp(varName, buffer, 4096);
	m_txtGetEnv.SetWindowText(buffer);
}

void CfrmTestDeclare::GetLocalTimeSub()
{
	// The SYSTEMTIME structure represents a date and time using individual members for the month, day, year, weekday, hour, minute, second, and millisecond.
	 MySYSTEMTIME curSystemTime; 
	GetLocalTimeWrp(curSystemTime); // - the GetLocalTime function retrieves the current local date and time
	m_LabelDate.SetWindowText("Date = "+FormatVB(curSystemTime.wDay)+"/"+FormatVB(curSystemTime.wMonth)+"/"+FormatVB(curSystemTime.wYear));
	m_LabelTime.SetWindowText("Time = "+FormatVB(curSystemTime.wHour)+":"+FormatVB(curSystemTime.wMinute)+":"+FormatVB(curSystemTime.wSecond)+"."+FormatVB(curSystemTime.wMilliseconds));
}
void CfrmTestDeclare::OnCmdGetLocalTime()
{
	// TODO: Add your control notification handler code here
	GetLocalTimeSub();
}

void CfrmTestDeclare::OnBtnRedraw()
{
	// TODO: Add your control notification handler code here
	 short L,  T; 
	L = 25; T = 128;

	fm_Picture1.SetBackColor(0xFFFF);

	EllipsePtr((int)GetHDC(this), L, T, L+30, T+50);
	RectanglePtr((int)GetHDC(this), L+60, T, L+90, T+50);
	RectanglePtr((int)GetHDC(CfrmTestDeclare::InstancePtr()), L+120, T, L+140, T+50);

	RectanglePtr((int)GetHDC(m_Picture1), 50, 10, 120, 35);
	SetTextColorPtr((int)GetHDC(m_Picture1), 182);

	 int W,  H; 
	W = GetWidth(this);
	H = GetHeight(this);

	fm_Label1.SetForeColor(0xFFFF00);
	fm_Label1.SetBackColor(0xFF0000);
}

void CfrmTestDeclare::OnMouseMove(UINT nFlags, CPoint point)
{
	LONG X = point.x;
	LONG Y = point.y;
	// TODO: Add your message handler code here and/or call default

	 POINTAPI pScreen,  pClient; CString s; 
	GetCursorPosWrp(pScreen); // - the GetCursorPos function retrieves the cursor's position, in screen coordinates
	pClient = pScreen;
	ScreenToClientFromDLLWrp((int)this->m_hWnd, pClient);
	m_LabelX.SetWindowText("X = "+Str(pScreen.X)+"  ("+FormatVB(pClient.X)+")");
	m_LabelY.SetWindowText("Y = "+Str(pScreen.Y)+"  ("+FormatVB(pClient.Y)+")");

	m_Picture1.RedrawWindow();
	s = "("+Str(pClient.X)+", "+Str(pClient.Y)+")";
	TextOutWrp((int)GetHDC(m_Picture1), 20, 50, s, s.GetLength());
	CDialog::OnMouseMove(nFlags, point);
}

void CfrmTestDeclare::OnCmdMsgBox()
{
	// TODO: Add your control notification handler code here
	MsgBoxFromDLLWrp((int)this->m_hWnd, "MessageBox from User32", "Hello !", 0);
}

void CfrmTestDeclare::OnCmdShellExecute()
{
	// TODO: Add your control notification handler code here
	 CString Param; 
	Param = "mailto:info@vbto.net";
	Param += "?subject=About VBto Converter";
	Param += CString("&body=")+"Hello support,";
	Param += CString("%0A%0A.%0A.%0A.%0A.%0A%0A")+"Regards,";

	 CString S1; int sz; CString sUserName,  sNetUserName; 
	S1 = CString(' ',512);
	sz = S1.GetLength();
	GetUserNameWrp(S1, sz); // - the GetUserName function retrieves the name of the user associated with the current thread
	sUserName = Trim(S1);

	S1 = CString(' ',512);
	sz = S1.GetLength();
	WNetGetUserWrp("", S1, sz); // - the WNetGetUser function retrieves the current default user name, or the user name used to establish a network connection
	sNetUserName = Trim(S1);

	Param += CString("%0A")+sUserName;
	if (sNetUserName!=sUserName) Param += CString(" (")+sNetUserName+")";

	ShellExecuteWrp((int)this->m_hWnd, "open", Param, "", "", SW_SHOWNORMAL);
}

void CfrmTestDeclare::OnCmdShellExecute2()
{
	// TODO: Add your control notification handler code here
	ShellExecuteWrp(0, "open", "http://www.vbto.net", "", "", SW_MAXIMIZE);

#if And_So_On
	 CString fil; 
	fil = "D:\\\\Photo\\\\";
	ShellExecuteWrp(0, "open", fil, "", "", SW_MAXIMIZE);

#endif
}

void CfrmTestDeclare::CmdTestCallFromModuleAndClass()
{
	 CString sM1,  sM2,  sC; int sz; 
	sM1 = TestDeclareFromModule();

	sM2 = CString(' ',512);
	sz = sM2.GetLength();
	GetComputerName_ModulePublicWrp(sM2, sz);
	sM2 = sM2.Left(sz);

	 ClassTestDeclare *cl=NULL; 
	VBSetNew(cl, new ClassTestDeclare);
	sC = cl->TestDeclareFromClass();

	if ((sM1.GetLength()>0) && (sM1==sM2) && (sM2==sC)) {
		// MsgBox "All Ok"
	} else {
		 CString msg; 
		msg = sM1+"\r\n"+sM2+"\r\n"+sC;
		::MessageBox(NULL, msg,"Error!",MB_ICONSTOP);
	}
}

void CfrmTestDeclare::Form_Load()
{
	 CString S1; int sz; 
	S1 = CString(' ',512);
	sz = S1.GetLength();
	GetComputerNameWrp(S1, sz); // - the GetComputerName function retrieves the NetBIOS name of the local computer
	m_LabelComputerName.SetWindowText(Trim(S1));

	// The GetSystemMetrics function retrieves various system metrics (widths and heights of display elements) and system configuration settings. All dimensions retrieved by GetSystemMetrics are in pixels
	// VBto upgrade warning: resX As short	OnWrite(int)
	// VBto upgrade warning: resY As short	OnWrite(int)
	// VBto upgrade warning: nMouseButtons As short	OnWrite(int)
	 short resX,  resY,  nMouseButtons; 
	resX = GetSystemMetricsPtr(SM_CXSCREEN);
	resY = GetSystemMetricsPtr(SM_CYSCREEN);
	nMouseButtons = GetSystemMetrics_ModulePublicPtr(SM_CMOUSEBUTTONS);
	m_LabelScreenArea.SetWindowText("Screen Area = "+FormatVB(resX)+" by "+FormatVB(resY)+" pixels");
	m_LabelNumberButtonsMouse.SetWindowText("Number of buttons on mouse = "+FormatVB(nMouseButtons));

	GetLocalTimeSub();
	CmdTestCallFromModuleAndClass();
}


HBRUSH CfrmTestDeclare::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch(pWnd->GetDlgCtrlID()) {
		case Label1:	return fm_Label1	.OnCtlColor(pDC);
		case Picture1:	return fm_Picture1	.OnCtlColor(pDC);
	}
	return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}

//========================================================
class OnStartupGetProcAddress_frmTestDeclareFRM {
public:
	OnStartupGetProcAddress_frmTestDeclareFRM() {
		RectanglePtr = (RectangleTD) GetAddress("GDI32.dll", "Rectangle");
		EllipsePtr = (EllipseTD) GetAddress("gdi32", "Ellipse");
		//? ArcPtr = (ArcTD) GetAddress("gdi32", "Arc");
		//? LineToPtr = (LineToTD) GetAddress("gdi32", "LineTo");
		TextOutPtr = (TextOutTD) GetAddress("gdi32", "TextOutA");
		SetTextColorPtr = (SetTextColorTD) GetAddress("gdi32", "SetTextColor");
		GetEnvVarPtr = (GetEnvVarTD) GetAddress("kernel32", "GetEnvironmentVariableA");
		GetComputerNamePtr = (GetComputerNameTD) GetAddress("kernel32", "GetComputerNameA");
		GetLocalTimePtr = (GetLocalTimeTD) GetAddress("kernel32", "GetLocalTime");
		MsgBoxFromDLLPtr = (MsgBoxFromDLLTD) GetAddress("User32", "MessageBoxA");
		GetSystemMetricsPtr = (GetSystemMetricsTD) GetAddress("User32", "GetSystemMetrics");
		GetCursorPosPtr = (GetCursorPosTD) GetAddress("User32", "GetCursorPos");
		ScreenToClientFromDLLPtr = (ScreenToClientFromDLLTD) GetAddress("User32", "ScreenToClient");
		ShellExecutePtr = (ShellExecuteTD) GetAddress("shell32.dll", "ShellExecuteA");
		WNetGetUserPtr = (WNetGetUserTD) GetAddress("mpr", "WNetGetUserA");
		GetUserNamePtr = (GetUserNameTD) GetAddress("advapi32.dll", "GetUserNameA");
	}
} m_OnStartupGetProcAddress_frmTestDeclareFRM;

