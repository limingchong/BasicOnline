// SeverDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Sever.h"
#include "SeverDlg.h"
#include "DlgProxy.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSeverDlg dialog

IMPLEMENT_DYNAMIC(CSeverDlg, CDialog);

CSeverDlg::CSeverDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSeverDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSeverDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

CSeverDlg::~CSeverDlg()
{
	// If there is an automation proxy for this dialog, set
	//  its back pointer to this dialog to NULL, so it knows
	//  the dialog has been deleted.
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void CSeverDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSeverDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSeverDlg, CDialog)
	//{{AFX_MSG_MAP(CSeverDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_OPEN, OnOpen)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSeverDlg message handlers

BOOL CSeverDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	((CButton*)GetDlgItem(IDC_STOP))->SetCheck(TRUE);
	SetDlgItemText(IDC_PORT, _T("2049"));

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSeverDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSeverDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSeverDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

// Automation servers should not exit when a user closes the UI
//  if a controller still holds on to one of its objects.  These
//  message handlers make sure that if the proxy is still in use,
//  then the UI is hidden but the dialog remains around if it
//  is dismissed.

// Global varialbles

bool listening = false;
CWinThread* pThread = NULL;

unsigned int StartServer(LPVOID lParam);

void CSeverDlg::OnClose() 
{
	if (CanExit())
		CDialog::OnClose();
}

void CSeverDlg::OnOK() 
{
	if (CanExit())
		CDialog::OnOK();
}

void CSeverDlg::OnCancel() 
{
	if (CanExit())
		CDialog::OnCancel();
}

BOOL CSeverDlg::CanExit()
{
	// If the proxy object is still around, then the automation
	//  controller is still holding on to this application.  Leave
	//  the dialog around, but hide its UI.
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}

void CSeverDlg::OnOpen() 
{
	// TODO: Add your control notification handler code here
	if (listening == false){
		listening = true;
		pThread = new CWinThread(StartServer, (LPVOID)this);
		pThread->CreateThread(CREATE_SUSPENDED);
		pThread->ResumeThread();
		AfxMessageBox("Opened.");
	}
}

void CSeverDlg::OnStop() 
{
	// TODO: Add your control notification handler code here
	if (listening == true){
		listening = false;
		pThread->SuspendThread();
		delete pThread;
		pThread = NULL;
		AfxMessageBox("Closed.");
	}
}

unsigned int StartServer(LPVOID lParam)
{
	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return 1;
	}

	CSeverDlg* aDlg = (CSeverDlg*)lParam;

	CString port;
	aDlg->GetDlgItemText(IDC_PORT,port);
	UINT nPort = atoi(port);

	CSocket aSocket, serverSocket;
	if (!aSocket.Socket())
	{
		char szError[256] = { 0 };
		sprintf(szError, "Create Faild: %d", GetLastError());
		CString tempCS;
		tempCS.Format(_T("%s"), szError);
		AfxMessageBox(tempCS);
		return 1;
	}

	BOOL bOptVal = TRUE;
	int bOptLen = sizeof(BOOL);
	aSocket.SetSockOpt(SO_REUSEADDR, (void*)&bOptVal, bOptLen, SOL_SOCKET);

	if (!aSocket.Bind(nPort))
	{
		char szError[256] = { 0 };
		sprintf(szError, "Bind Faild: %d", GetLastError());
		CString tempCS;
		tempCS.Format(_T("%s"), szError);
		AfxMessageBox(tempCS);
		return 1;
	}

	if (!aSocket.Listen(10))
	{
		char szError[256] = { 0 };
		sprintf(szError, "Listen Faild: %d", GetLastError());
		CString tempCS;
		tempCS.Format(_T("%s"), szError);
		AfxMessageBox(tempCS);
		return 1;
	}

	while (listening)
	{
		if (aSocket.Accept(serverSocket))
		{
			char szRecvMsg[1024] = { 0 };
			char szOutMsg[1024] = { 0 };
			CString strText;
			serverSocket.Receive(szRecvMsg, 1024);
			sprintf(szOutMsg, "Received: %s\r\n", szRecvMsg);
			aDlg->GetDlgItemText(IDC_INFO, strText);
			strText += szOutMsg;
			aDlg->SetDlgItemText(IDC_INFO, strText);
			serverSocket.Send("Server received, done!", 50);
			serverSocket.Close();
		}

	}

	aSocket.Close();
	serverSocket.Close();
	return 0;
}