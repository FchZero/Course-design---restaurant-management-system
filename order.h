#if !defined(AFX_ORDER_H__23642A68_2CBF_43D5_9E1E_312BB0E7BAE6__INCLUDED_)
#define AFX_ORDER_H__23642A68_2CBF_43D5_9E1E_312BB0E7BAE6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// order.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Corder dialog

class Corder : public CDialog
{
// Construction
public:
	Corder(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Corder)
	enum { IDD = IDD_DIALOG2 };
	int		m_moneycc;
	CString	m_namecc;
	CString	m_notecc;
	int		m_peoplecc;
	int		m_tablecc;
	CString	m_timecc;
	CString	m_ordertime;
	CString	m_phones;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Corder)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(Corder)
	afx_msg void Onorderyes();
	afx_msg void OnButton2();
	afx_msg void OnBs();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ORDER_H__23642A68_2CBF_43D5_9E1E_312BB0E7BAE6__INCLUDED_)
