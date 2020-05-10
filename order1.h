#if !defined(AFX_ORDER1_H__1B5B0F0E_6BFD_4F74_AA36_41FD0E22ED1F__INCLUDED_)
#define AFX_ORDER1_H__1B5B0F0E_6BFD_4F74_AA36_41FD0E22ED1F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// order1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// order dialog

class order : public CDialog
{
// Construction
public:
	order(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(order)
	enum { IDD = IDD_DIALOG2 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(order)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(order)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ORDER1_H__1B5B0F0E_6BFD_4F74_AA36_41FD0E22ED1F__INCLUDED_)
