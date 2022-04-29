// Sever.h : main header file for the SEVER application
//

#if !defined(AFX_SEVER_H__315BBC2B_B25B_4C8B_95A6_E301126E2983__INCLUDED_)
#define AFX_SEVER_H__315BBC2B_B25B_4C8B_95A6_E301126E2983__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSeverApp:
// See Sever.cpp for the implementation of this class
//

class CSeverApp : public CWinApp
{
public:
	CSeverApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSeverApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSeverApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEVER_H__315BBC2B_B25B_4C8B_95A6_E301126E2983__INCLUDED_)
