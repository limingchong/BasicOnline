// DlgProxy.h : header file
//

#if !defined(AFX_DLGPROXY_H__C5F714D3_A5E4_4AA9_9BA1_5654F739C642__INCLUDED_)
#define AFX_DLGPROXY_H__C5F714D3_A5E4_4AA9_9BA1_5654F739C642__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CClientDlg;

/////////////////////////////////////////////////////////////////////////////
// CClientDlgAutoProxy command target

class CClientDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CClientDlgAutoProxy)

	CClientDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CClientDlg* m_pDialog;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientDlgAutoProxy)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CClientDlgAutoProxy();

	// Generated message map functions
	//{{AFX_MSG(CClientDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CClientDlgAutoProxy)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CClientDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROXY_H__C5F714D3_A5E4_4AA9_9BA1_5654F739C642__INCLUDED_)
