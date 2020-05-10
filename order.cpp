// order.cpp : implementation file
//

#include "stdafx.h"
#include "restaurant.h"
#include "order.h"
#include"customer.h"
#include"table.h"
#include<fstream>


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Corder dialog


Corder::Corder(CWnd* pParent /*=NULL*/)
	: CDialog(Corder::IDD, pParent)
{
	//{{AFX_DATA_INIT(Corder)
	m_namecc = _T("");
	m_notecc = _T("");
	m_peoplecc = 0;
	m_tablecc = 0;
	m_timecc = _T("");
	m_ordertime = _T("");
	m_phones = _T("");
	//}}AFX_DATA_INIT
}


void Corder::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Corder)
	DDX_Text(pDX, IDC_cname, m_namecc);
	DDX_Text(pDX, IDC_cnote, m_notecc);
	DDX_Text(pDX, IDC_cpeople, m_peoplecc);
	DDX_Text(pDX, IDC_ctable, m_tablecc);
	DDX_Text(pDX, IDC_ctime, m_timecc);
	DDX_Text(pDX, IDC_Eordertime, m_ordertime);
	DDX_Text(pDX, IDC_cphone, m_phones);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Corder, CDialog)
	//{{AFX_MSG_MAP(Corder)
	ON_BN_CLICKED(IDC_BUTTON1, Onorderyes)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_Bs, OnBs)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Corder message handlers
void Corder::Onorderyes() 
{
	//导入餐桌数据
	int i;
	UpdateData(TRUE);
	table T[50];
	ifstream in("table.txt",ios_base::in);	
	for(i = 0;i<50;i++)
	{
		in>>T[i].tbnum;
		in>>T[i].state;
		in>>T[i].people;
	}
	in.close();

		UpdateData(TRUE);
		if(T[m_tablecc-1].state != 0)
		{
		AfxMessageBox("该餐桌不可预订！请重新输入！");    	

		}
		else 
		{
			UpdateData(TRUE);//数据的读入
			string str1(m_namecc.GetBuffer(10));
			string str2(m_timecc.GetBuffer(10));
			string str3(m_notecc.GetBuffer(100));
			string str4(m_ordertime.GetBuffer(50));
			string str5(m_phones.GetBuffer(100));
			customer newc(str1,str4,str2,100,m_tablecc,str5,m_peoplecc,str3);
			T[newc.tnum-1].state =1;//更改餐桌状态
			ofstream outc("table.txt",ios_base::out);
			for(i = 0;i<50;i++)
			{
				outc<<T[i].tbnum<<" "<<T[i].state<<" "<<T[i].people<<" "<<endl;
			}
			outc.close();
	
    ofstream out;//保存客户信息到文件中
	out.open("customer.txt",ios_base::app);
	out<<newc.name<<" "<<newc.ordertime<<" "<<newc.time<<" "<<newc.money<<" "<<newc.tnum<<" "<<newc.phone<<" "<<newc.people<<" "<<newc.note<<endl;//将客户信息保存到文件中
	out.close();
	ifstream k("k.txt",ios_base::in);
	int kk;
	k>>kk;
	kk += 1;
	k.close();
	ofstream k2("k.txt",ios_base::out);//更新客户信息数量
	k2<<kk;
	k2.close();

	AfxMessageBox("预定成功!");
	
		}
	CDialog::OnCancel();
	// TODO: Add your control notification handler code here
	
}






void Corder::OnButton2() 
{
	PostMessage(WM_CLOSE,0,0);


	// TODO: Add your control notification handler code here
	
}

void Corder::OnBs() 
{ 

	int i =0;
    CString s,q,temp;
	string b,c,d,e,f,g,h;
	table T[50];
	ifstream in("table.txt",ios_base::in);//改变餐桌状态为不可预订
	
	for(i = 0;i<50;i++)
	{
		in>>T[i].tbnum;
		in>>T[i].state;
		in>>T[i].people;
	}
	in.close();


	
	temp +="空闲餐桌-可坐人数";
	temp +="\r\n";
	for(i = 0;i<50;i++)
	{
		if(T[i].state == 0)
		{
			s.Format (_T("%d"),T[i].tbnum,i+1);
			q.Format (_T("%d"),T[i].people,i+1);
			temp += "(";
			temp +=s;
			temp +=" ";
			temp +=q;
			temp +=")";
			temp +=" ";
		}
		if((i+1)%10 == 0)
		{
			temp += "\r\n";
		}
		GetDlgItem(IDC_sunorder)->SetWindowText(temp);
			
		
	}//UpdateData(FALSE);
	

	
}

void Corder::OnPaint() 
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
		CBitmap bmp11;
		bmp11.LoadBitmap(IDB_BITMAP2);//载入资源中图片
		BITMAP m_bitmap;
		bmp11.GetBitmap(&m_bitmap);//将图片载入位图中
		CBitmap *pbmpOld = dcBmp.SelectObject(&bmp11);
		dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcBmp,0,0,m_bitmap.bmWidth,m_bitmap.bmHeight,SRCCOPY);//使图像相形状可变  
	}
	
	// TODO: Add your message handler code here
	
	// Do not call CDialog::OnPaint() for painting messages
}

HBRUSH Corder::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
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
	case IDC_STATIC4:
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0,0,0));
	case IDC_STATIC5:
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0,0,0));
	case IDC_STATIC6:
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0,0,0));
	case IDC_STATIC7:
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0,0,0));	
	case IDC_STATIC8:
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0,0,0));
		return(HBRUSH)GetStockObject(HOLLOW_BRUSH);
	default:break;
	}
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}
