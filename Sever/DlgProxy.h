// DlgProxy.h : header file
//

#if !defined(AFX_DLGPROXY_H__B5BD6CE0_6A3A_4DF9_B276_A135F15CF05B__INCLUDED_)
#define AFX_DLGPROXY_H__B5BD6CE0_6A3A_4DF9_B276_A135F15CF05B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSeverDlg;

/////////////////////////////////////////////////////////////////////////////
// CSeverDlgAutoProxy command target

class CSeverDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CSeverDlgAutoProxy)

	CSeverDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CSeverDlg* m_pDialog;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSeverDlgAutoProxy)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CSeverDlgAutoProxy();

	// Generated message map functions
	//{{AFX_MSG(CSeverDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CSeverDlgAutoProxy)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CSeverDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROXY_H__B5BD6CE0_6A3A_4DF9_B276_A135F15CF05B__INCLUDED_)
