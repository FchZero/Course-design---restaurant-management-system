// restaurantDlg.h : header file
//

#if !defined(AFX_RESTAURANTDLG_H__93C7FB0E_F654_4FBF_B33D_D467B1F2EB94__INCLUDED_)
#define AFX_RESTAURANTDLG_H__93C7FB0E_F654_4FBF_B33D_D467B1F2EB94__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRestaurantDlg dialog

class CRestaurantDlg : public CDialog
{
// Construction
public:
	CRestaurantDlg(CWnd* pParent = NULL);	// standard constructor


// Dialog Data
	//{{AFX_DATA(CRestaurantDlg)
	enum { IDD = IDD_RESTAURANT_DIALOG };
	CString	m_time;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRestaurantDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRestaurantDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton2();
	afx_msg void Onpay();
	afx_msg void OnTIME();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButton1();
	afx_msg void OnButton3();
	afx_msg void OnButton5();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnButton6();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()


};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESTAURANTDLG_H__93C7FB0E_F654_4FBF_B33D_D467B1F2EB94__INCLUDED_)
