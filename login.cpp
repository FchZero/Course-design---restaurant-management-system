// login.cpp : implementation file
//

#include "stdafx.h"
#include "restaurant.h"
#include "login.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// login dialog


login::login(CWnd* pParent /*=NULL*/)
	: CDialog(login::IDD, pParent)
{
	//{{AFX_DATA_INIT(login)
	m_pass = 0;
	//}}AFX_DATA_INIT

}


void login::DoDataExchange(CDataExchange* pDX)
{

	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(login)
	DDX_Text(pDX, IDC_EDIT1, m_pass);
	//}}AFX_DATA_MAP

}


BEGIN_MESSAGE_MAP(login, CDialog)
	//{{AFX_MSG_MAP(login)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// login message handlers

void login::OnOK() 
{
	// TODO: Add extra validation here
	int real = 2019;
	UpdateData(TRUE);
	if(m_pass == real)
	{
		

	}
	else
	{
		AfxMessageBox("用户密码不正确！");
		return;
	}

	CDialog::OnOK();
}

void login::OnCancel() 
{
	exit(0);
	
	CDialog::OnCancel();
}

void login::OnPaint() 
{	if (IsIconic())
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
		bmp11.LoadBitmap(IDB_BITMAP3);//载入资源中图片
		BITMAP m_bitmap;
		bmp11.GetBitmap(&m_bitmap);//将图片载入位图中
		CBitmap *pbmpOld = dcBmp.SelectObject(&bmp11);
		dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcBmp,0,0,m_bitmap.bmWidth,m_bitmap.bmHeight,SRCCOPY);//使图像相形状可变  
	}
}

HBRUSH login::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
		// TODO: Change any attributes of the DC here
	switch(pWnd->GetDlgCtrlID())
	{
	case IDC_STATIC1:
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0,0,0));
		return(HBRUSH)GetStockObject(HOLLOW_BRUSH);
	default:break;
	}
	
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}
