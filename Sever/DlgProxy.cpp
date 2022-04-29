// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "Sever.h"
#include "DlgProxy.h"
#include "SeverDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSeverDlgAutoProxy

IMPLEMENT_DYNCREATE(CSeverDlgAutoProxy, CCmdTarget)

CSeverDlgAutoProxy::CSeverDlgAutoProxy()
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
	ASSERT_KINDOF(CSeverDlg, AfxGetApp()->m_pMainWnd);
	m_pDialog = (CSeverDlg*) AfxGetApp()->m_pMainWnd;
	m_pDialog->m_pAutoProxy = this;
}

CSeverDlgAutoProxy::~CSeverDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CSeverDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CSeverDlgAutoProxy, CCmdTarget)
	//{{AFX_MSG_MAP(CSeverDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CSeverDlgAutoProxy, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CSeverDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_ISever to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {BA67CCDE-6727-47F9-B39E-67153C4BBD36}
static const IID IID_ISever =
{ 0xba67ccde, 0x6727, 0x47f9, { 0xb3, 0x9e, 0x67, 0x15, 0x3c, 0x4b, 0xbd, 0x36 } };

BEGIN_INTERFACE_MAP(CSeverDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CSeverDlgAutoProxy, IID_ISever, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {47DF5983-DA51-462A-A086-237B59EF0ABE}
IMPLEMENT_OLECREATE2(CSeverDlgAutoProxy, "Sever.Application", 0x47df5983, 0xda51, 0x462a, 0xa0, 0x86, 0x23, 0x7b, 0x59, 0xef, 0xa, 0xbe)

/////////////////////////////////////////////////////////////////////////////
// CSeverDlgAutoProxy message handlers
