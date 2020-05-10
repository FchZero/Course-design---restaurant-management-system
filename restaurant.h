// restaurant.h : main header file for the RESTAURANT application
//

#if !defined(AFX_RESTAURANT_H__2D2C5F6A_490A_4F8B_ADA6_B004DAFAE4CD__INCLUDED_)
#define AFX_RESTAURANT_H__2D2C5F6A_490A_4F8B_ADA6_B004DAFAE4CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRestaurantApp:
// See restaurant.cpp for the implementation of this class
//

class CRestaurantApp : public CWinApp
{
public:
	CRestaurantApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRestaurantApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRestaurantApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESTAURANT_H__2D2C5F6A_490A_4F8B_ADA6_B004DAFAE4CD__INCLUDED_)
