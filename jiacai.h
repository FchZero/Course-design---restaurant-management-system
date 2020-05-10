#if !defined(AFX_JIACAI_H__48FABCC8_8751_4C6D_99D5_56FF98DB82F3__INCLUDED_)
#define AFX_JIACAI_H__48FABCC8_8751_4C6D_99D5_56FF98DB82F3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// jiacai.h : header file
//
#include"CP.h"
/////////////////////////////////////////////////////////////////////////////
// jiacai dialog

class jiacai : public CDialog
{
// Construction
public:
	jiacai(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(jiacai)
	enum { IDD = IDD_DIALOG8 };
	CButton	m_JC_OK;
	CButton	m_JC_CANCEL;
	int		m_table;
    static	int  mt;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(jiacai)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(jiacai)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnChangeEdit1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JIACAI_H__48FABCC8_8751_4C6D_99D5_56FF98DB82F3__INCLUDED_)
