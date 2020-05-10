#if !defined(AFX_CP1_H__CD61D3E9_3F13_455F_B847_54457CFEA5CF__INCLUDED_)
#define AFX_CP1_H__CD61D3E9_3F13_455F_B847_54457CFEA5CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CP1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCP1 dialog

class CCP1 : public CDialog
{
// Construction
public:
	CCP1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCP1)
	enum { IDD = IDD_DIALOG9 };
	CListCtrl	m_list;
	int		m_incp;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCP1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCP1)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CP1_H__CD61D3E9_3F13_455F_B847_54457CFEA5CF__INCLUDED_)
