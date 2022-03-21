// frmTestCommonDialog.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestCommonDialog)
//}}VBto_Converter_Includes

#include "frmTestCommonDialog.h"
CfrmTestCommonDialog *frmTestCommonDialog = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestCommonDialog dialog



CfrmTestCommonDialog::CfrmTestCommonDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestCommonDialog::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestCommonDialog) frmTestCommonDialog = this;
}

void CfrmTestCommonDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestCommonDialog)
	DDX_Control(pDX, LabelTestCommonDialog, m_LabelTestCommonDialog);
	DDX_Control(pDX, FrameTestCommonDialog, m_FrameTestCommonDialog);
	DDX_Control(pDX, Label1, m_Label1);
	DDX_Control(pDX, Label2, m_Label2);
	DDX_Control(pDX, Frame2, m_Frame2);
	DDX_Control(pDX, TextSaveFile, m_TextSaveFile);
	DDX_Control(pDX, cmdSaveFile, m_cmdSaveFile);
	DDX_Control(pDX, Frame1, m_Frame1);
	DDX_Control(pDX, Label3, m_Label3);
	DDX_Control(pDX, Label4, m_Label4);
	DDX_Control(pDX, cmbFilterIndex, m_cmbFilterIndex);
	DDX_Control(pDX, txtFilter, m_txtFilter);
	DDX_Control(pDX, cmdOpenFile, m_cmdOpenFile);
	DDX_Control(pDX, TextOpenFile, m_TextOpenFile);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestCommonDialog, CDialog)
	//{{AFX_MSG_MAP(CfrmTestCommonDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(cmdSaveFile, OncmdSaveFile)
	ON_BN_CLICKED(cmdOpenFile, OncmdOpenFile)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestCommonDialog message handlers

BOOL CfrmTestCommonDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestCommonDialog)
	m_CommonDialog0 = new CFileDialog(TRUE);
	m_CommonDialog0->m_ofn.lpstrTitle	= "Open File:";
	m_CommonDialog0->m_ofn.lpstrInitialDir	= "c:\\Program Files/QQsoft\\Temp";
	m_CommonDialog0->m_ofn.lpstrDefExt	= "txt";
	m_CommonDialog0->m_ofn.lpstrFilter	= "Word files (*.doc)\0*.doc\0All files (*.*)\0*.*\0";
	m_CommonDialog0->m_ofn.nFilterIndex	= 2;
	strcpy(m_CommonDialog0->m_ofn.lpstrFile, "myFile");
	m_CommonDialogDefault = new CFileDialog(TRUE);
	m_CommonDialogDefault->m_ofn.lpstrTitle	= "DialogDefault Title";
	m_cmbFilterIndex	.AddString("1");
	m_cmbFilterIndex	.AddString("2");
	m_cmbFilterIndex	.AddString("3");
	m_cmbFilterIndex	.AddString("4");
	m_cmbFilterIndex	.AddString("5");
	m_cmbFilterIndex	.AddString("6");
	
	m_CommonDialogSave = new CFileDialog(TRUE);
	m_CommonDialogOpen = new CFileDialog(TRUE);
	
	fm_FrameTestCommonDialog.Set(GetDlgItem(FrameTestCommonDialog), GetSysColor(COLOR_BTNTEXT), RGB(192,192,255));
	
	
	Form_Load();
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestCommonDialog::OnPaint() 
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
HCURSOR CfrmTestCommonDialog::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================

void CfrmTestCommonDialog::Form_Load()
{

	m_txtFilter.SetWindowText("JPEG Images (*.jpg;*jpe;*.jpeg)|*.jpg;*.jpeg|"+CString("TIFF Images(*.tif,*.tiff,*.cpt)|*.tif;*.tiff;*.cpt|")+"Bitmaps (*.bmp;*.dib)|*.bmp;*.dib|"+"GIF Images (*.gif)|*.gif|"+"PNG Images (*.png)|*.png|"+"All Files (*.*)|*.*");

	m_cmbFilterIndex.SetCurSel(1);

}

void CfrmTestCommonDialog::OncmdSaveFile()
{
	// TODO: Add your control notification handler code here
	try {	// On Error GoTo exitSub


		// m_CommonDialogSave->CancelError = true;
		m_CommonDialogSave->m_ofn.lpstrTitle = "Save to File";
		m_CommonDialogSave->m_ofn.lpstrFilter = "Text Files (*.txt)\0*.txt\0RTF Files (*.rtf)\0*.rtf\0All Files (*.*)\0*.*\0";
		m_CommonDialogSave->m_ofn.nFilterIndex = 3;
		m_CommonDialogSave->m_ofn.lpstrFile = strcpy(CommonDialogStrFile, "xFile");
		m_CommonDialogSave->m_ofn.lpstrDefExt = /*?*/strdup("Au");
		m_CommonDialogSave->m_ofn.Flags |= OFN_OVERWRITEPROMPT;
		if (m_CommonDialogSave->DoModal()!=IDOK) {/*?*/};
		m_TextSaveFile.SetWindowText(m_CommonDialogSave->GetPathName());


	} catch(...) {	// exitSub:
	}
}

void CfrmTestCommonDialog::OncmdOpenFile()
{
	// TODO: Add your control notification handler code here
	try {	// On Error GoTo exitSub

		m_CommonDialogOpen->m_ofn.lpstrTitle = "Open Image File";
		m_CommonDialogOpen->m_ofn.lpstrFilter = TranslateCFileDialogFilter(::GetWindowText(m_txtFilter));
		m_CommonDialogOpen->m_ofn.Flags |= OFN_FILEMUSTEXIST;


		// m_CommonDialogOpen->CancelError = true;
		m_CommonDialogOpen->m_ofn.nFilterIndex = m_cmbFilterIndex.GetCurSel()+1;
		if (m_CommonDialogOpen->DoModal()!=IDOK) {/*?*/};
		if (m_CommonDialogOpen->GetPathName().GetLength()==0) return;
		m_cmbFilterIndex.SetCurSel(m_CommonDialogOpen->m_ofn.nFilterIndex-1);
		m_TextOpenFile.SetWindowText(m_CommonDialogOpen->GetFileTitle());
		m_TextOpenFile.SetWindowText(m_CommonDialogOpen->GetPathName());


	} catch(...) {	// exitSub:
	}
}

HBRUSH CfrmTestCommonDialog::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch(pWnd->GetDlgCtrlID()) {
		case FrameTestCommonDialog:	return fm_FrameTestCommonDialog	.OnCtlColor(pDC);
	}
	return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}
