// searchdlg.cpp : implementation file
//

#include "stdafx.h"
#include "restaurant.h"
#include "searchdlg.h"
#include"customer.h"
#include"print.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// searchdlg dialog


searchdlg::searchdlg(CWnd* pParent /*=NULL*/)
	: CDialog(searchdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(searchdlg)
	m_names = _T("");
	m_tables = 0;
	m_phones = _T("");
	//}}AFX_DATA_INIT
}


void searchdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(searchdlg)
	DDX_Text(pDX, IDC_EDITname, m_names);
	DDX_Text(pDX, IDC_EDITtable, m_tables);
	DDX_Text(pDX, IDC_EDITphone, m_phones);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(searchdlg, CDialog)
	//{{AFX_MSG_MAP(searchdlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton3)
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// searchdlg message handlers

void searchdlg::OnButton1() 
{
	int kk;
	ifstream k("k.txt",ios_base::in);
	int kkk;
	k>>kkk;
	k.close();
	customer cc[100];
	string m;
	string l;
	UpdateData(TRUE);
	m = m_names.GetBuffer(15);
	int ii = 0;
	ifstream in("customer.txt",ios_base::in);
	while(kkk>0)
	{
			in>>cc[ii].name;
			in>>cc[ii].ordertime;
			in>>cc[ii].time;
			in>>cc[ii].money;
			in>>cc[ii].tnum;
			in>>cc[ii].phone;
			in>>cc[ii].people;
			in>>cc[ii].note;		
			ii++;
			kkk--;
	};
	in.close();

	int flag = 0;
	for(int j = 0;j<ii+1;j++)
	{
		if(cc[j].name==" ")
		{
			break;
		}
		else
		{
			if(m.compare(cc[j].name)==0)
			{
				flag = 1;
				kk = j;			
				break;
			}
		}
	}

	if(flag == 1)
	{	
		string a,b,c,z,p,s1,s2,s3,s4,s5,s6,s7,s8,ss;
		ss ="";
		int d,e,f;
		s1 = "姓名:";	
		s2 = "订餐时间:";
		s3 = "就餐时间:";
		s4 = "定金:";
		s5 = "餐桌编号:";
		s6 = "联系电话:";
		s7 = "用餐人数:";
		s8 = "备注:";
		a = cc[kk].name;
		b = cc[kk].ordertime;
		c = cc[kk].time;
		z = cc[kk].note;
		d = cc[kk].tnum;
		stringstream s9;
		s9<<d;
		string tn = s9.str();
		e = cc[kk].money;
		stringstream s10;
		s10<<e;
		string mo = s10.str();
		f = cc[kk].people;
		stringstream s11;
		s11<<f;
		string pe = s11.str();
		p = cc[kk].phone;
		ss += s1;
		ss += a;
		ss +="\r\n";
		ss += s2;
		ss += b;
		ss +="\r\n";
		ss += s3;
		ss += c;
		ss +="\r\n";
		ss += s4;
		ss += mo;
		ss +="\r\n";
		ss += s5;
		ss += tn;
		ss +="\r\n";	
		ss += s6;
		ss += p;
		ss +="\r\n";
		ss += s7;
		ss += pe;
		ss +="\r\n";
		ss += s8;
		ss += z;

		
		CString str(ss.c_str());

	
	
	GetDlgItem(IDC_Sp)->SetWindowText(str);			
			
	}
	if(flag == 0)
	{
		AfxMessageBox("没有找到该客户！");
	}

	
}

void searchdlg::OnButton2() 
{
	int kk;
	ifstream k("k.txt",ios_base::in);
	int kkk;
	k>>kkk;
	k.close();
	customer cc[100];
	string m;
	string l;
	UpdateData(TRUE);
	m = m_phones.GetBuffer(100);
	int ii = 0;
	ifstream in("customer.txt",ios_base::in);
	while(kkk>0)
	{
			in>>cc[ii].name;
			in>>cc[ii].ordertime;
			in>>cc[ii].time;
			in>>cc[ii].money;
			in>>cc[ii].tnum;
			in>>cc[ii].phone;
			in>>cc[ii].people;
			in>>cc[ii].note;		
			ii++;
			kkk--;
	};
	in.close();

	int flag = 0;
	for(int j = 0;j<ii+1;j++)
	{
		if(m.compare(cc[j].phone)==0)
			{
				flag = 1;
				kk = j;			
				break;
			}

	}
	if(flag == 1)
	{	
		string a,b,c,z,p,s1,s2,s3,s4,s5,s6,s7,s8,ss;
		ss ="";
		int d,e,f;
		s1 = "姓名:";	
		s2 = "订餐时间:";
		s3 = "就餐时间:";
		s4 = "定金:";
		s5 = "餐桌编号:";
		s6 = "联系电话:";
		s7 = "用餐人数:";
		s8 = "备注:";
		a = cc[kk].name;
		b = cc[kk].ordertime;
		c = cc[kk].time;
		z = cc[kk].note;
		d = cc[kk].tnum;
		stringstream s9;
		s9<<d;
		string tn = s9.str();
		e = cc[kk].money;
		stringstream s10;
		s10<<e;
		string mo = s10.str();
		f = cc[kk].people;
		stringstream s11;
		s11<<f;
		string pe = s11.str();
		p = cc[kk].phone;
		ss += s1;
		ss += a;
		ss +="\r\n";
		ss += s2;
		ss += b;
		ss +="\r\n";
		ss += s3;
		ss += c;
		ss +="\r\n";
		ss += s4;
		ss += mo;
		ss +="\r\n";
		ss += s5;
		ss += tn;
		ss +="\r\n";	
		ss += s6;
		ss += p;
		ss +="\r\n";
		ss += s7;
		ss += pe;
		ss +="\r\n";
		ss += s8;
		ss += z;
		
		CString str(ss.c_str());

	
	
	GetDlgItem(IDC_Sp)->SetWindowText(str);			
			
	}
	if(flag == 0)
	{
		AfxMessageBox("没有找到该客户！");
	}
}

void searchdlg::OnButton3() 
{
	int kk;
	ifstream k("k.txt",ios_base::in);
	int kkk;
	k>>kkk;
	k.close();
	customer cc[100];
	int m;
	string l;
	UpdateData(TRUE);
	m = m_tables;
	int ii = 0;
	ifstream in("customer.txt",ios_base::in);
	while(kkk>0)
	{
			in>>cc[ii].name;
			in>>cc[ii].ordertime;
			in>>cc[ii].time;
			in>>cc[ii].money;
			in>>cc[ii].tnum;
			in>>cc[ii].phone;
			in>>cc[ii].people;
			in>>cc[ii].note;		
			ii++;
			kkk--;
	};
	in.close();

	int flag = 0;
	for(int j = 0;j<ii+1;j++)
	{
		if(cc[j].tnum==m)
			{
				flag = 1;
				kk = j;			
				break;
			}

	}
	if(flag == 1)
	{	
		string a,b,c,z,p,s1,s2,s3,s4,s5,s6,s7,s8,ss;
		ss ="";
		int d,e,f;
		s1 = "姓名:";	
		s2 = "订餐时间:";
		s3 = "就餐时间:";
		s4 = "定金:";
		s5 = "餐桌编号:";
		s6 = "联系电话:";
		s7 = "用餐人数:";
		s8 = "备注:";
		a = cc[kk].name;
		b = cc[kk].ordertime;
		c = cc[kk].time;
		z = cc[kk].note;
		d = cc[kk].tnum;
		stringstream s9;
		s9<<d;
		string tn = s9.str();
		e = cc[kk].money;
		stringstream s10;
		s10<<e;
		string mo = s10.str();
		f = cc[kk].people;
		stringstream s11;
		s11<<f;
		string pe = s11.str();
		p = cc[kk].phone;
		ss += s1;
		ss += a;
		ss +="\r\n";
		ss += s2;
		ss += b;
		ss +="\r\n";
		ss += s3;
		ss += c;
		ss +="\r\n";
		ss += s4;
		ss += mo;
		ss +="\r\n";
		ss += s5;
		ss += tn;
		ss +="\r\n";	
		ss += s6;
		ss += p;
		ss +="\r\n";
		ss += s7;
		ss += pe;
		ss +="\r\n";
		ss += s8;
		ss += z;
		
		CString str(ss.c_str());

	
	
	GetDlgItem(IDC_Sp)->SetWindowText(str);			
			
	}
	if(flag == 0)
	{
		AfxMessageBox("没有找到该客户！");
	}	
}

HBRUSH searchdlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

		switch(pWnd->GetDlgCtrlID())
	{
	case IDC_STATIC1:
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0,0,0));
	case IDC_STATIC2:
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0,0,0));
	case IDC_STATIC3:
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0,0,0));
		return(HBRUSH)GetStockObject(HOLLOW_BRUSH);
	default:break;
	}

	
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void searchdlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{//防止调用重画函数
		//CDialog::OnPaint();
		CPaintDC dc(this);
		CRect rect;
		GetClientRect(&rect);//获取对话框长宽
		CDC dcBmp;//定义并创建一个内存设备环境
		dcBmp.CreateCompatibleDC(&dc);
		CBitmap bmp99;
		bmp99.LoadBitmap(IDB_BITMAP8);//载入资源中图片
		BITMAP m_bitmap;
		bmp99.GetBitmap(&m_bitmap);//将图片载入位图中
		CBitmap *pbmpOld = dcBmp.SelectObject(&bmp99);
		dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcBmp,0,0,m_bitmap.bmWidth,m_bitmap.bmHeight,SRCCOPY);//使图像相形状可变  
	}
}

void searchdlg::OnOK() 
{
	jiucan dlg;
	dlg.DoModal();
	
	CDialog::OnOK();
}

void searchdlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
