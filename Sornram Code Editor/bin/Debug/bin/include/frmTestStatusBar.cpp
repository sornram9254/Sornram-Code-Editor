// frmTestStatusBar.cpp : implementation file
//

#include "stdafx.h"
#include "VBtoConverterTest2.h"

//{{VBto_Converter_Includes(CfrmTestStatusBar)
//}}VBto_Converter_Includes

#include "frmTestStatusBar.h"
CfrmTestStatusBar *frmTestStatusBar = NULL;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfrmTestStatusBar dialog



CfrmTestStatusBar::CfrmTestStatusBar(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmTestStatusBar::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	if (!frmTestStatusBar) frmTestStatusBar = this;
}

void CfrmTestStatusBar::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CfrmTestStatusBar)
	DDX_Control(pDX, Label4, m_Label4);
	DDX_Control(pDX, Frame3, m_Frame3);
	DDX_Control(pDX, Label3, m_Label3);
	DDX_Control(pDX, Label2, m_Label2);
	DDX_Control(pDX, Label1, m_Label1);
	DDX_Control(pDX, UpDownPanelCount, m_UpDownPanelCount);
	DDX_Control(pDX, UpDownPanelIndex, m_UpDownPanelIndex);
	DDX_Control(pDX, txtPanelCount, m_txtPanelCount);
	DDX_Control(pDX, txtPanelText, m_txtPanelText);
	DDX_Control(pDX, txtPanelIndex, m_txtPanelIndex);
	DDX_Control(pDX, Frame2, m_Frame2);
	DDX_Control(pDX, txtSimpleText, m_txtSimpleText);
	DDX_Control(pDX, Frame4, m_Frame4);
	DDX_Control(pDX, cbEnabled, m_cbEnabled);
	DDX_Control(pDX, cbVisible, m_cbVisible);
	DDX_Control(pDX, Frame5, m_Frame5);
	DDX_Control(pDX, OptionNormal, m_OptionNormal);
	DDX_Control(pDX, OptionSimple, m_OptionSimple);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CfrmTestStatusBar, CDialog)
	//{{AFX_MSG_MAP(CfrmTestStatusBar)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(OptionSimple, OnOptionSimple)
	ON_BN_CLICKED(OptionNormal, OnOptionNormal)
	ON_EN_CHANGE(txtSimpleText, ChangetxtSimpleText)
	ON_EN_CHANGE(txtPanelText, ChangetxtPanelText)
	ON_BN_CLICKED(cbVisible, OncbVisible)
	ON_BN_CLICKED(cbEnabled, OncbEnabled)
	ON_WM_VSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CfrmTestStatusBar message handlers

BOOL CfrmTestStatusBar::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//{{VBto_Converter_OnInitDialog(CfrmTestStatusBar)
	m_StatusBar1.Create(WS_CHILD|SBT_OWNERDRAW|WS_VISIBLE|CCS_BOTTOM, CRect(0,0,0,0), this, 0);
	m_StatusBar1.SetText("SimpleText ..." , 255, 0);
	{ int statusBarPannelsWidth[4]= { 75, 150, 225, 300 };
	m_StatusBar1.SetParts(4, statusBarPannelsWidth); }
	m_StatusBar1.SetText("text1"	, 0, 0);
	m_StatusBar1.SetText("text2"	, 1, SBT_POPOUT);
	m_StatusBar1.SetText("text3"	, 2, 0);
	m_StatusBar1.SetText("text4"	, 3, 0);
	m_StatusBar1.SetSimple();
	
	m_UpDownPanelCount	.SetBuddy(GetDlgItem(txtPanelCount));
	m_UpDownPanelCount	.SetRange(1, 7);
	m_UpDownPanelCount	.SetPos(3);
	
	m_UpDownPanelIndex	.SetBuddy(GetDlgItem(txtPanelIndex));
	m_UpDownPanelIndex	.SetRange(1, 7);
	m_UpDownPanelIndex	.SetPos(1);
	
	m_txtPanelCount	.SetWindowText("3");	//from 'UpDownPanelCount'
	m_txtPanelText	.SetWindowText("...");
	m_txtPanelIndex	.SetWindowText("1");	//from 'UpDownPanelIndex'
	m_txtSimpleText	.SetWindowText("SimpleText ..");
	m_cbEnabled	.SetCheck(BST_CHECKED);
	m_cbVisible	.SetCheck(BST_CHECKED);
	m_OptionSimple	.SetCheck(BST_CHECKED);
	ii = 0;
	
	Form_Load();
	//}}VBto_Converter_OnInitDialog

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfrmTestStatusBar::OnPaint() 
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
HCURSOR CfrmTestStatusBar::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	//=========================================================



void CfrmTestStatusBar::Form_Load()
{
	m_txtSimpleText.SetWindowText(::GetWindowText(m_StatusBar1));

	ii = m_StatusBar1.GetParts(0,NULL);
	SetMax(m_UpDownPanelCount, ii);
	m_UpDownPanelCount.SetPos(GetMax(m_UpDownPanelCount));
	SetMax(m_UpDownPanelIndex, ii);
}

void CfrmTestStatusBar::OnOptionSimple()
{
	// TODO: Add your control notification handler code here
	m_StatusBar1.SetSimple(true); // 1
	m_txtSimpleText.SetWindowText(::GetWindowText(m_StatusBar1));
}
void CfrmTestStatusBar::OnOptionNormal()
{
	// TODO: Add your control notification handler code here
	m_StatusBar1.SetSimple(false); // 0
	UpDownPanelIndex_Change();
}

void CfrmTestStatusBar::ChangetxtSimpleText()
{
	// TODO: Add your control notification handler code here
	if ((m_StatusBar1.IsSimple()?1:0)!=sbrSimple) return;
	m_StatusBar1.SetText(::GetWindowText(m_txtSimpleText), 255, 0);
}

void CfrmTestStatusBar::UpDownPanelIndex_Change()
{
	ii = m_UpDownPanelIndex.GetPos32();
	m_txtPanelText.SetWindowText(m_StatusBar1.GetText(ii-1, NULL));
}

void CfrmTestStatusBar::ChangetxtPanelText()
{
	// TODO: Add your control notification handler code here
	if ((m_StatusBar1.IsSimple()?1:0)!=sbrNormal) return;
	ii = m_UpDownPanelIndex.GetPos32();
	m_StatusBar1.SetText(::GetWindowText(m_txtPanelText), ii-1, 0);
}

void CfrmTestStatusBar::OncbVisible()
{
	// TODO: Add your control notification handler code here
	m_StatusBar1.ShowWindow(m_cbVisible.GetCheck()==BST_CHECKED ? SW_SHOW : SW_HIDE);
}
void CfrmTestStatusBar::OncbEnabled()
{
	// TODO: Add your control notification handler code here
	m_StatusBar1.EnableWindow(m_cbEnabled.GetCheck()==BST_CHECKED);
}


void CfrmTestStatusBar::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: Add your message handler code here and/or call default

	short Button, Shift; float x, y;
	Button = Shift = 0;
	x = y = 0;

	switch(pScrollBar->GetDlgCtrlID())
	{
		case UpDownPanelIndex: {
			if (nSBCode==SB_ENDSCROLL) {
				UpDownPanelIndex_Change();
				break;
			}

			break;
		}

	}

	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}