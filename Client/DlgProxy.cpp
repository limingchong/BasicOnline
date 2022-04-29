// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "Client.h"
#include "DlgProxy.h"
#include "ClientDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClientDlgAutoProxy

IMPLEMENT_DYNCREATE(CClientDlgAutoProxy, CCmdTarget)

CClientDlgAutoProxy::CClientDlgAutoProxy()
{
	EnableAutomation();
	
	// To keep the application running as long as an automation 
	//	object is active, the constructor calls AfxOleLockApp.
	AfxOleLockApp();

	// Get access to the dialog through the application's
	//  main window pointer.  Set the proxy's internal pointer
	//  to point to the dialog, and set the dialog's back pointer to
	//  this proxy.
	ASSERT (AfxGetApp()->m_pMainWnd != NULL);
	ASSERT_VALID (AfxGetApp()->m_pMainWnd);
	ASSERT_KINDOF(CClientDlg, AfxGetApp()->m_pMainWnd);
	m_pDialog = (CClientDlg*) AfxGetApp()->m_pMainWnd;
	m_pDialog->m_pAutoProxy = this;
}

CClientDlgAutoProxy::~CClientDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CClientDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CClientDlgAutoProxy, CCmdTarget)
	//{{AFX_MSG_MAP(CClientDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CClientDlgAutoProxy, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CClientDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IClient to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {D79AA202-CF23-4DBD-AF54-AB4D54252785}
static const IID IID_IClient =
{ 0xd79aa202, 0xcf23, 0x4dbd, { 0xaf, 0x54, 0xab, 0x4d, 0x54, 0x25, 0x27, 0x85 } };

BEGIN_INTERFACE_MAP(CClientDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CClientDlgAutoProxy, IID_IClient, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {5A9AE766-9C83-4A55-867C-2A29AE792FF1}
IMPLEMENT_OLECREATE2(CClientDlgAutoProxy, "Client.Application", 0x5a9ae766, 0x9c83, 0x4a55, 0x86, 0x7c, 0x2a, 0x29, 0xae, 0x79, 0x2f, 0xf1)

/////////////////////////////////////////////////////////////////////////////
// CClientDlgAutoProxy message handlers
