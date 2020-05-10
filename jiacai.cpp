// jiacai.cpp : implementation file
//

#include "stdafx.h"
#include "restaurant.h"
#include "jiacai.h"
#include"CP1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// jiacai dialog


jiacai::jiacai(CWnd* pParent /*=NULL*/)
	: CDialog(jiacai::IDD, pParent)
{
	//{{AFX_DATA_INIT(jiacai)
	m_table = 0;
	//}}AFX_DATA_INIT
}


void jiacai::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(jiacai)
	DDX_Control(pDX, IDOK, m_JC_OK);
	DDX_Control(pDX, IDCANCEL, m_JC_CANCEL);
	DDX_Text(pDX, IDC_Etable, m_table);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(jiacai, CDialog)
	//{{AFX_MSG_MAP(jiacai)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// jiacai message handlers

void jiacai::OnOK() 
{
	//读取餐桌状态信息
	table T[50];
	ifstream inn("table.txt",ios_base::in);	
	for(int i = 0;i<50;i++)
	{
		inn>>T[i].tbnum;
		inn>>T[i].state;
		inn>>T[i].people;
	}
	inn.close();


	UpdateData(TRUE);


	if(T[m_table-1].state == 2||T[m_table-1].state == 3)
	{
		mt = m_table;//将餐桌号传递给下一个窗口
		EndDialog(0);
		CCP1 dlg;
		dlg.DoModal();
	}

	else
	{
		AfxMessageBox("该餐桌还未就餐！");

	}	
}



void jiacai::OnCancel() 
{
	CDialog::OnCancel();
}
