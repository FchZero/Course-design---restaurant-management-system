// eat.cpp : implementation file
//

#include "stdafx.h"
#include "restaurant.h"
#include "eat.h"
#include "ListCtrl1cp.h"
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Ceat dialog


Ceat::Ceat(CWnd* pParent /*=NULL*/)
	: CDialog(Ceat::IDD, pParent)
{
	//{{AFX_DATA_INIT(Ceat)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Ceat::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Ceat)
	DDX_Control(pDX, IDC_LIST3, m_cp);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Ceat, CDialog)
	//{{AFX_MSG_MAP(Ceat)
	ON_BN_CLICKED(IDOK, Oneatlistok)
	ON_NOTIFY(NM_CLICK, IDC_LIST3, Oncp)
	ON_EN_CHANGE(IDC_EDIT1, Onincp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Ceat message handlers

void Ceat::Oneatlistok() 
{
	PostMessage(WM_CLOSE,0,0);//关闭当前窗口
	// TODO: Add your control notification handler code here
	
}


void Ceat::Oncp(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CString a = 'cp';
	CListCtrl m_cp;
	m_cp.InsertColumn(0,a,50,50);
	
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

BOOL Ceat::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_cp.InsertColumn(0,"菜谱号");
	m_cp.InsertColumn(1,"菜名");
	m_cp.InsertColumn(2,"种类");
	m_cp.InsertColumn(3,"单价");
	m_cp.InsertColumn(4,"简介");

	RECT rect;
	m_cp.GetWindowRect(&rect);
	int wid = rect.right-rect.left;
	m_cp.SetColumnWidth(0,wid/5);
	m_cp.SetColumnWidth(1,wid/5);
	m_cp.SetColumnWidth(2,wid/5);
	m_cp.SetColumnWidth(3,wid/5);
	m_cp.SetColumnWidth(4,wid/5);

	//单击选中一行
	m_cp.SetExtendedStyle(LVS_EX_FULLROWSELECT);





	return TRUE;
}

void Ceat::Onincp() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}
