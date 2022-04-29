// SeverDlg.h : header file
//

#if !defined(AFX_SEVERDLG_H__528BBDBF_6E79_4A5A_894D_B5783E4B02DF__INCLUDED_)
#define AFX_SEVERDLG_H__528BBDBF_6E79_4A5A_894D_B5783E4B02DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSeverDlgAutoProxy;

/////////////////////////////////////////////////////////////////////////////
// CSeverDlg dialog

class CSeverDlg : public CDialog
{
	DECLARE_DYNAMIC(CSeverDlg);
	friend class CSeverDlgAutoProxy;

// Construction
public:
	CSeverDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CSeverDlg();

// Dialog Data
	//{{AFX_DATA(CSeverDlg)
	enum { IDD = IDD_SEVER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSeverDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CSeverDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	//{{AFX_MSG(CSeverDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnOpen();
	afx_msg void OnStop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEVERDLG_H__528BBDBF_6E79_4A5A_894D_B5783E4B02DF__INCLUDED_)
