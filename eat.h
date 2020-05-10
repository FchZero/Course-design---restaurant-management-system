#if !defined(AFX_EAT_H__A5C53900_D66E_4357_9542_FE0D69670C30__INCLUDED_)
#define AFX_EAT_H__A5C53900_D66E_4357_9542_FE0D69670C30__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// eat.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Ceat dialog
#include<string>

class Ceat : public CDialog
{
// Construction
public:
	Ceat(CWnd* pParent = NULL);   // standard constructor
	BOOL Ceat::OnInitDialog();

// Dialog Data
	//{{AFX_DATA(Ceat)
	enum { IDD = IDD_DIALOG3 };
	CListCtrl	m_cp;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Ceat)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Ceat)
	afx_msg void Oneatlistok();
	afx_msg void Oncp(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void Onincp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EAT_H__A5C53900_D66E_4357_9542_FE0D69670C30__INCLUDED_)
