// order1.cpp : implementation file
//

#include "stdafx.h"
#include "restaurant.h"
#include "order1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// order dialog


order::order(CWnd* pParent /*=NULL*/)
	: CDialog(order::IDD, pParent)
{
	//{{AFX_DATA_INIT(order)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void order::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(order)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(order, CDialog)
	//{{AFX_MSG_MAP(order)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// order message handlers
