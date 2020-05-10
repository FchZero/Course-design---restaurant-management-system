#if !defined(AFX_JIUCAN_H__6BB9276C_5988_404F_AFBC_0E5176CC9733__INCLUDED_)
#define AFX_JIUCAN_H__6BB9276C_5988_404F_AFBC_0E5176CC9733__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// jiucan.h : header file
//
#include"CP.h"

/////////////////////////////////////////////////////////////////////////////
// jiucan dialog

class jiucan : public CDialog
{
// Construction
public:
	jiucan(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(jiucan)
	enum { IDD = IDD_DIALOG6 };
	int		m_table;
    static	int mt;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(jiucan)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(jiucan)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JIUCAN_H__6BB9276C_5988_404F_AFBC_0E5176CC9733__INCLUDED_)
