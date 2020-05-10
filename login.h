#if !defined(AFX_LOGIN_H__86CA6E3C_7E61_47E7_A3CE_DD9D314282BF__INCLUDED_)
#define AFX_LOGIN_H__86CA6E3C_7E61_47E7_A3CE_DD9D314282BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// login.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// login dialog

class login : public CDialog
{
// Construction
public:
	login(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(login)
	enum { IDD = IDD_LOG };
	int		m_pass;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(login)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(login)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGIN_H__86CA6E3C_7E61_47E7_A3CE_DD9D314282BF__INCLUDED_)
