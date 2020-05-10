#if !defined(AFX_SEARCHDLG_H__D12C092B_D429_4415_848A_C8EC9DA119E7__INCLUDED_)
#define AFX_SEARCHDLG_H__D12C092B_D429_4415_848A_C8EC9DA119E7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// searchdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// searchdlg dialog
#include"jiucan.h"
class searchdlg : public CDialog
{
// Construction
public:
	searchdlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(searchdlg)
	enum { IDD = IDD_DIALOG5 };
	CString	m_names;
	int		m_tables;
	CString	m_phones;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(searchdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(searchdlg)
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEARCHDLG_H__D12C092B_D429_4415_848A_C8EC9DA119E7__INCLUDED_)
