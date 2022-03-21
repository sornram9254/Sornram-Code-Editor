// frmTestFileSystemObject.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestFileSystemObject)
//}}VBto_Converter_Includes

#include "frmTestFileSystemObject.h"
CfrmTestFileSystemObject *frmTestFileSystemObject = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestFileSystemObject dialog



CfrmTestFileSystemObject::CfrmTestFileSystemObject(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestFileSystemObject::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestFileSystemObject) frmTestFileSystemObject = this;
}

void CfrmTestFileSystemObject::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestFileSystemObject)
	DDX_Control(pDX, BtnSaveFile, m_BtnSaveFile);
	DDX_Control(pDX, BtnReadFile, m_BtnReadFile);
	DDX_Control(pDX, TextLog, m_TextLog);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestFileSystemObject, CDialog)
	//{{AFX_MSG_MAP(CfrmTestFileSystemObject)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(BtnSaveFile, OnBtnSaveFile)
	ON_BN_CLICKED(BtnReadFile, OnBtnReadFile)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestFileSystemObject message handlers

BOOL CfrmTestFileSystemObject::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestFileSystemObject)
	MainFSO1 = IFileSystemPtr(__uuidof(FileSystemObject));
	
	
	Form_Load();
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestFileSystemObject::OnPaint() 
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
HCURSOR CfrmTestFileSystemObject::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================
// This is a part of the VBto Converter (www.vbto.net)
// Copyright (C) 2005-2011 StressSoft Company Ltd. All rights reserved.




// VBto upgrade warning: msg As CString	OnWrite(CString, ???)
void CfrmTestFileSystemObject::AddToLog(CString msg)
{
	m_TextLog.SetWindowText(::GetWindowText(m_TextLog)+CString("\r\n")+msg);
}

void CfrmTestFileSystemObject::OnBtnSaveFile()
{
	// TODO: Add your control notification handler code here
	  IFileSystemPtr FSO(__uuidof(FileSystemObject));
	 ITextStreamPtr TextFile; 

	// === 1 ===
	TextFile = FSO->CreateTextFile(_bstr_t(sFileName), true, true);
	TextFile->WriteLine(_bstr_t("FileSystemObject.WriteLine \"Hi World!\""));
	TextFile->Close();
	TextFile = NULL;

	// === 2 ===
	FSO->CopyFile(_bstr_t(sFileName), _bstr_t(sFileName+"~0"), true);
	FSO->CopyFile(_bstr_t(sFileName), _bstr_t(sFileName+"~1"), true);
	FSO->CopyFile(_bstr_t(sFileName), _bstr_t(sFileName+"~2"), true);
	FSO->DeleteFile(_bstr_t(sFileName+"~2"), true);
	FSO->MoveFile(_bstr_t(sFileName+"~0"), _bstr_t(sFileName+"~2"));

	// === 3 ===
	TextFile = FSO->OpenTextFile(_bstr_t(sFileName), ForWriting, true, TristateUseDefault);
	TextFile->WriteLine(_bstr_t("Start: "+StrFromDate(COleDateTime::GetCurrentTime())+" "+StrFromDate(vbTime())));
	 short i; 
	for(i=1; i<=3; i++) {
		TextFile->WriteLine(_bstr_t("Test FileSystemObject And TextFile, Line #"+Str(i)+" Time: "+StrFromDate(vbTime())));
	} // i
	TextFile->Close();
	TextFile = NULL;

	// === 4 ===
	TextFile = FSO->OpenTextFile(_bstr_t(sFileName), ForAppending, true, TristateUseDefault);
	TextFile->WriteLine(_bstr_t(""));
	for(i=1; i<=3; i++) {
		TextFile->WriteLine(_bstr_t("Test FileSystemObject And TextFile, Line #"+Str(i)+" Time: "+StrFromDate(vbTime())));
	} // i
	 CString buffer; 
	buffer = StrFromDate(COleDateTime::GetCurrentTime())+" "+StrFromDate(vbTime());
	TextFile->WriteLine(_bstr_t("Stop: "+buffer));
	TextFile->Close();
	TextFile = NULL;

	// === 5 ===
	FSO = NULL;
	m_TextLog.SetWindowText("");
	AddToLog("Create New File: "+buffer);
}

void CfrmTestFileSystemObject::OnBtnReadFile()
{
	// TODO: Add your control notification handler code here
	m_TextLog.SetWindowText("");

	 IFileSystemPtr FSO; 
	FSO = new IFileSystemPtr(__uuidof(FileSystemObject));

	if (FSO->FileExists(_bstr_t(sFileName))) {
		 ITextStreamPtr TextFile; 
		TextFile = FSO->OpenTextFile(_bstr_t(sFileName), ForReading, true, TristateUseDefault);
		while (!TextFile->AtEndOfStream) {
			AddToLog(CString((LPTSTR)TextFile->ReadLine()));
		}
		TextFile->Close();
		TextFile = NULL;
	} else {
		AddToLog("\""+sFileName+"\" File Not Exist");
	}

	FSO = NULL;
}

void CfrmTestFileSystemObject::Form_Load()
{
	sFileName = GetAppPath()+"\\~TestFSO.txt";

	 ITextStreamPtr TextFile; 
	TextFile = MainFSO1->CreateTextFile(_bstr_t(sFileName), true, true);
	TextFile->WriteLine(_bstr_t("Form_Load: Hi World!"));
	TextFile->Close();
	TextFile = NULL;

	MainFSO2 = new IFileSystemPtr(__uuidof(FileSystemObject));
	if (MainFSO2->FileExists(_bstr_t(sFileName))) {
	}
	MainFSO2 = NULL;
}
