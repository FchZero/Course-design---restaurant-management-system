// restaurantDlg.cpp : implementation file
//

#include "stdafx.h"
#include "restaurant.h"
#include "restaurantDlg.h"
#include "searchdlg.h"
#include "order.h"
#include  "jiucan.h"
#include  "jiacai.h"
#include  "pay.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
	

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRestaurantDlg dialog

CRestaurantDlg::CRestaurantDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRestaurantDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRestaurantDlg)
	m_time = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRestaurantDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRestaurantDlg)
	DDX_Text(pDX, IDC_TIME, m_time);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRestaurantDlg, CDialog)
	//{{AFX_MSG_MAP(CRestaurantDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON4, Onpay)
	ON_EN_CHANGE(IDC_TIME, OnTIME)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRestaurantDlg message handlers

BOOL CRestaurantDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	CString strTime;
	CTime tm;
	tm = CTime::GetCurrentTime();
	strTime = tm.Format("%y年%m月%d日%X");//格式化系统时间
	SetDlgItemText(IDC_TIME,strTime);//初始化编辑框显示
	SetTimer(1,1000,NULL);//启动定时器
	


	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRestaurantDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CRestaurantDlg::OnPaint() 
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
		bmp99.LoadBitmap(IDB_BITMAP1);//载入资源中图片
		BITMAP m_bitmap;
		bmp99.GetBitmap(&m_bitmap);//将图片载入位图中
		CBitmap *pbmpOld = dcBmp.SelectObject(&bmp99);
		dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcBmp,0,0,m_bitmap.bmWidth,m_bitmap.bmHeight,SRCCOPY);//使图像相形状可变  
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CRestaurantDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CRestaurantDlg::OnButton2() 
{
	Corder DLG;
	DLG.DoModal();
	
}
	// TODO: Add your control notification handler code here
	



void CRestaurantDlg::Onpay() 
{
	Cpay DLG;
	DLG.DoModal();
	// TODO: Add your control notification handler code here
	
}

void CRestaurantDlg::OnTIME() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}


void CRestaurantDlg::OnTimer(UINT nIDEvent) 
{
		CString strTime;
		CTime tm;
        tm = CTime::GetCurrentTime();
		strTime = tm.Format("%Y年%m月%d日  %H:%M:%S");
		SetDlgItemText(IDC_TIME,strTime);//显示系统时间
	
	
	CDialog::OnTimer(nIDEvent);
}

void CRestaurantDlg::OnButton1() 
{
	searchdlg dlg;
	dlg.DoModal();
	
}

void CRestaurantDlg::OnButton3() 
{

	jiucan dlg;
	dlg.DoModal();// TODO: Add your control notification handler code here
	
}

void CRestaurantDlg::OnButton5() 
{
exit(0);	// TODO: Add your control notification handler code here
	
}

HBRUSH CRestaurantDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
		// TODO: Change any attributes of the DC here

	
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CRestaurantDlg::OnButton6() 
{
	jiacai dlg;
	dlg.DoModal();	// TODO: Add your control notification handler code here
	
}
