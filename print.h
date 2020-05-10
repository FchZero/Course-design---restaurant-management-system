#if !defined(AFX_PRINT_H__4ABDF5CE_F99B_4822_AADB_2FF6295A8797__INCLUDED_)
#define AFX_PRINT_H__4ABDF5CE_F99B_4822_AADB_2FF6295A8797__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// print.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// print dialog

class print : public CDialog
{
// Construction
public:
	print(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(print)
	enum { IDD = IDD_print };
	CString	m_namee;
	CString	m_orderr;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(print)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(print)
	virtual void OnOK();
	afx_msg void Onnamee();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINT_H__4ABDF5CE_F99B_4822_AADB_2FF6295A8797__INCLUDED_)
