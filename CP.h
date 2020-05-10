#if !defined(AFX_CP_H__F08ACF7B_4591_41D3_BA64_33165C016AA4__INCLUDED_)
#define AFX_CP_H__F08ACF7B_4591_41D3_BA64_33165C016AA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CP.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCP dialog

#include"price.h"
#include"jiucan.h"
class CCP : public CDialog
{
// Construction
public:
	CCP(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCP)
	enum { IDD = IDD_DIALOG7 };
	CListCtrl	m_list;
	int		m_incp;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCP)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCP)
	virtual BOOL OnInitDialog();
	afx_msg void Onadd();
	afx_msg void Ondelete();
	afx_msg void OnPaint();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CP_H__F08ACF7B_4591_41D3_BA64_33165C016AA4__INCLUDED_)
