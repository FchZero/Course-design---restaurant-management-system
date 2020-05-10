#if !defined(AFX_PAY_H__1FBDBC35_4256_460C_BF3B_9353BC0006C3__INCLUDED_)
#define AFX_PAY_H__1FBDBC35_4256_460C_BF3B_9353BC0006C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// pay.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Cpay dialog

class Cpay : public CDialog
{
// Construction
public:
	Cpay(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Cpay)
	enum { IDD = IDD_DIALOG4 };
	int		m_table;
	CString	m_payy;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cpay)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(Cpay)
	afx_msg void Onback();
	afx_msg void Onok();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAY_H__1FBDBC35_4256_460C_BF3B_9353BC0006C3__INCLUDED_)
