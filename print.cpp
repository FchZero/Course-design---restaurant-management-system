// print.cpp : implementation file
//

#include "stdafx.h"
#include "restaurant.h"
#include "print.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// print dialog


print::print(CWnd* pParent /*=NULL*/)
	: CDialog(print::IDD, pParent)
{
	//{{AFX_DATA_INIT(print)
	m_namee = _T("");
	m_orderr = _T("");
	//}}AFX_DATA_INIT
}


void print::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(print)
	DDX_Text(pDX, IDC_EDIT1, m_namee);
	DDX_Text(pDX, IDC_EDIT2, m_orderr);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(print, CDialog)
	//{{AFX_MSG_MAP(print)
	ON_EN_CHANGE(IDC_EDIT1, Onnamee)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// print message handlers

void print::OnOK() 
{
	customer cc[100];
	string m;
	string l;
	ifstream in("customer.txt",ios_base::in);
	int i = 0;
	while(getline(in,l))
	{
			in>>cc[i].name;
			in>>cc[i].ordertime;
			in>>cc[i].time;
			in>>cc[i].money;
			in>>cc[i].tnum;
			in>>cc[i].phone;
			in>>cc[i].people;
			in>>cc[i].note;

			i++;
		};
	in.close();
	CString ttt;
	ttt.Format(_T("%s"),cc[customer::k].name);
	UpdateData(FALSE);
	GetDlgItem(IDC_EDIT1)->SetWindowText(ttt);
	
	
	
	CDialog::OnOK();
}

void print::Onnamee() 
{
	
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}
