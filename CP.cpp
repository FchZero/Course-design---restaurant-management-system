// CP.cpp : implementation file
//

#include "stdafx.h"
#include "restaurant.h"
#include "CP.h"
#include "jiucan.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCP dialog


CCP::CCP(CWnd* pParent /*=NULL*/)
	: CDialog(CCP::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCP)
	m_incp = 0;
	//}}AFX_DATA_INIT
}


void CCP::DoDataExchange(CDataExchange* pDX)
{

	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCP)
	DDX_Control(pDX, IDC_LIST4, m_list);
	DDX_Text(pDX, IDC_EDIT1, m_incp);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCP, CDialog)
	//{{AFX_MSG_MAP(CCP)
	ON_BN_CLICKED(IDC_BUTTON1, Onadd)
	ON_BN_CLICKED(IDC_BUTTON2, Ondelete)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCP message handlers

int jiucan::mt = 0;
BOOL CCP::OnInitDialog() 
{
	
	CDialog::OnInitDialog();
	int n = 0;

	m_list.InsertColumn(n++,_T("菜谱号"),LVCFMT_CENTER,70);//插入列头
	m_list.InsertColumn(n++,_T("菜名"),LVCFMT_CENTER,100);
	m_list.InsertColumn(n++,_T("菜系"),LVCFMT_CENTER,60);
	m_list.InsertColumn(n++,_T("价格"),LVCFMT_CENTER,60);
	m_list.InsertColumn(n++,_T("备注"),LVCFMT_CENTER,150);

	int nRow = m_list.InsertItem(1,"1");
	m_list.SetItemText(nRow,1,"清蒸竹笋");
	m_list.SetItemText(nRow,2,"粤菜");
	m_list.SetItemText(nRow,3,"15.00");
	m_list.SetItemText(nRow,4,"特别好吃");
	
	n = m_list.InsertItem(0,"2");
		m_list.SetItemText(n,1,"小葱拌豆腐");
		m_list.SetItemText(n,2,"东北菜");
		m_list.SetItemText(n,3,"15.00");
    	m_list.SetItemText(n,4,"美容养颜");

	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);//设置扩展样式，整行选中以及网格线

		n = m_list.InsertItem(0,"3");
		m_list.SetItemText(n,1,"红烧肉");
		m_list.SetItemText(n,2,"川菜");
		m_list.SetItemText(n,3,"35.00");
    	m_list.SetItemText(n,4,"肥而不腻！");
			
	     n = m_list.InsertItem(0,"4");
		m_list.SetItemText(n,1,"拔丝地瓜");
		m_list.SetItemText(n,2,"东北菜");
		m_list.SetItemText(n,3,"25.00");
    	m_list.SetItemText(n,4,"小孩大人都爱吃");

		n = m_list.InsertItem(0,"5");
		m_list.SetItemText(n,1,"话梅猪脚");
		m_list.SetItemText(n,2,"川菜");
		m_list.SetItemText(n,3,"50.00");
    	m_list.SetItemText(n,4,"丰富的胶原蛋白！");

		n = m_list.InsertItem(0,"6");
		m_list.SetItemText(n,1,"卤水双拼");
		m_list.SetItemText(n,2,"粤菜");
		m_list.SetItemText(n,3,"78.00");
    	m_list.SetItemText(n,4,"好吃！");

		n = m_list.InsertItem(0,"7");
		m_list.SetItemText(n,1,"黄油蜂蜜");
		m_list.SetItemText(n,2,"粤菜");
		m_list.SetItemText(n,3,"56.00");
    	m_list.SetItemText(n,4,"甜而不腻！");

		n = m_list.InsertItem(0,"8");
		m_list.SetItemText(n,1,"香茅大明虾");
		m_list.SetItemText(n,2,"川菜");
		m_list.SetItemText(n,3,"88.00");
    	m_list.SetItemText(n,4,"鲜！");

		n = m_list.InsertItem(0,"9");
		m_list.SetItemText(n,1,"栗子焖鸡");
		m_list.SetItemText(n,2,"川菜");
		m_list.SetItemText(n,3,"58.00");
    	m_list.SetItemText(n,4,"香气四溢！");


		n = m_list.InsertItem(0,"10");
		m_list.SetItemText(n,1,"银丝羹");
		m_list.SetItemText(n,2,"甜品");
		m_list.SetItemText(n,3,"52.00");
    	m_list.SetItemText(n,4,"甜美");




	
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCP::Onadd() 
{
	UpdateData(TRUE);

	price CP[10];
	ifstream in("cp.txt",ios_base::in);
	for(int i =0;i<10;i++)
	{
		in>>CP[i].cpnum;
		in>>CP[i].prices;
	}
	in.close();		


	
	ofstream fname;

	
    CString s2;
	s2.Format(_T("%d"),jiucan::mt);//int -> Cstring
	const size_t newsize = 100;
	char s22[newsize];
	strcpy(s22,s2);//将Cstring 转为 char 型


	fname.open(s22,ios_base::app);//创建了一个以餐桌号为名字的文件用来存储定菜信息
	fname<<m_incp;//把菜号存入文件
	fname<<" ";//空格作为间隔
	fname.close();
	



	int ccp[100];//用于存放读入的菜谱号
	i = 0;
	ifstream inn;
	inn.open(s22,ios_base::in);
	while(!inn.eof())
	{
		inn>>ccp[i];
		i++;
	}

    string ss="";//用于连接文本
	int  k = i;//用于计数
    for(i = 0;i<k-1;i++)
	{
		stringstream s2;
		s2<<ccp[i];
		string s3 = s2.str();
		ss += s3;
		ss +=" ";
	}
	

	CString str(ss.c_str());
	GetDlgItem(IDC_print)->SetWindowText(str);

	AfxMessageBox("增加成功！");
	
	
	
	// TODO: Add your control notification handler code here
	
}

void CCP::Ondelete() 
{
	UpdateData(TRUE);
	CString s2;
	s2.Format(_T("%d"),jiucan::mt);//int -> Cstring
	const size_t newsize = 100;
	char s22[newsize];
	strcpy(s22,s2);//将Cstring 转为 char 型

//读入已有的点菜信息
	int c[100];
	for(int i = 0;i<100;i++) c[i] = 0;

	ifstream in;
	in.open(s22,ios_base::in);
	i= 0;
	while(!in.eof())
	{
		in>>c[i];
		i++;
	}
	in.close();

	for(int j = 0;j<100&&c[j]!=0;j++)
	{
		if(m_incp == c[j])
		{
			c[j] = 55;
			break;
		}//要删掉的菜置为55
	}

//重新存入点菜信息
	ofstream out(s22,ios_base::out);
	for(j =0;(j<100)&&(c[j]!=0);j++)
	{
		if(c[j] != 55) out<<c[j]<<" ";
		else continue;
	}
	out.close();

	int ccp[100];//用于存放读入的菜谱号
	i = 0;
	ifstream inn;
	inn.open(s22,ios_base::in);
	while(!inn.eof())
	{
		inn>>ccp[i];
		i++;
	}

    string ss="";//用于连接文本
	int  k = i;//用于计数
    for(i = 0;i<k-1;i++)
	{
		stringstream s2;
		s2<<ccp[i];
		string s3 = s2.str();
		ss += s3;
		ss +=" ";
	}
		CString str(ss.c_str());
	GetDlgItem(IDC_print)->SetWindowText(str);

	
	AfxMessageBox("删除成功!");


	
	
	
}

void CCP::OnPaint() 
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
		bmp99.LoadBitmap(IDB_BITMAP6);//载入资源中图片
		BITMAP m_bitmap;
		bmp99.GetBitmap(&m_bitmap);//将图片载入位图中
		CBitmap *pbmpOld = dcBmp.SelectObject(&bmp99);
		dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcBmp,0,0,m_bitmap.bmWidth,m_bitmap.bmHeight,SRCCOPY);//使图像相形状可变  
	}
}

void CCP::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
