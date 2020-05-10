// pay.cpp : implementation file
//

#include "stdafx.h"
#include "restaurant.h"
#include "pay.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Cpay dialog


Cpay::Cpay(CWnd* pParent /*=NULL*/)
	: CDialog(Cpay::IDD, pParent)
{
	//{{AFX_DATA_INIT(Cpay)
	m_table = 0;
	m_payy = _T("");
	//}}AFX_DATA_INIT
}


void Cpay::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Cpay)
	DDX_Text(pDX, IDC_EDIT1, m_table);
	DDX_Text(pDX, IDC_payy, m_payy);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Cpay, CDialog)
	//{{AFX_MSG_MAP(Cpay)
	ON_BN_CLICKED(IDC_BUTTON2, Onback)
	ON_BN_CLICKED(IDC_BUTTON1, Onok)
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Cpay message handlers

void Cpay::Onback() 
{
PostMessage(WM_CLOSE,0,0);	// TODO: Add your control notification handler code here
	
}

void Cpay::Onok() 
{
	int i;int iflag = 0;
	table T[50];
	ifstream inn("table.txt",ios_base::in);//�ı����״̬Ϊ��Ԥ��
	
	for( i = 0;i<50;i++)
	{
		inn>>T[i].tbnum;
		inn>>T[i].state;
		inn>>T[i].people;
	}
	inn.close();
	UpdateData(TRUE);
	if(T[m_table-1].state == 3) iflag = 1;
	T[m_table-1].state= 0;
//�����ĺ�Ĳ�����Ϣ����

		ofstream outc("table.txt",ios_base::out);
			for(i = 0;i<50;i++)
			{
				outc<<T[i].tbnum<<" "<<T[i].state<<" "<<T[i].people<<" "<<endl;
			}
			outc.close();

	
	
	CString s2;
	s2.Format(_T("%d"),m_table);//int -> Cstring
	const size_t newsize = 100;
	char s22[newsize];
	strcpy(s22,s2);//��Cstring תΪ char ��
//��������˵���Ϣ
	int c[100];//�����ѵ���׺�
	int pay = 0;//Ӧ����Ǯ
	for(i = 0;i<100;i++) c[i] = 0;

	ifstream in;
	in.open(s22,ios_base::in);
	for(i = 0;i<100&&(!in.eof());i++)
	{
		in>>c[i];
	}
	in.close();

	for(int j = 0;j<100&&c[j]!=0;j++)
	{
		switch(c[j])
		{
		case 1:
			{
				pay += 15;
				break;
			}
		case 2:
			{
				pay += 15;
				break;
			}
		case 3:
			{
			    pay += 35;
				break;
			}
		case 4:
			{
				pay += 25;
				break;
			}
		case 5:
			{
				pay += 15;
				break;
			}
		case 6:
			{
					pay += 78;
				break;
			}
		case 7:
			{
					pay += 56;
				break;
			}
		case 8:
			{
					pay += 88;
				break;
			}
		case 9:
			{
					pay += 58;
				break;
			}
		case 10:
			{
					pay += 52;
				break;
			}
		}
	}

	//��ȡ����״̬��Ϣ
	if( iflag==1 ) pay -= 100;//�������Ϊ����״̬
	CString pay1;
	pay1.Format(_T("%d"),pay);
	GetDlgItem(IDC_payy)->SetWindowText(pay1); 

	
	
	//��յ�ǰ�˵���Ϣ	
	
	ofstream fname;
	fname.open(s22,ios_base::out);//������һ���Բ�����Ϊ���ֵ��ļ������洢������Ϣ
	fname<<"";
	fname.close();




	
}

HBRUSH Cpay::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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
		return(HBRUSH)GetStockObject(HOLLOW_BRUSH);
	default:break;
	}
	
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void Cpay::OnPaint() 
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
	{//��ֹ�����ػ�����
		//CDialog::OnPaint();
		CPaintDC dc(this);
		CRect rect;
		GetClientRect(&rect);//��ȡ�Ի��򳤿�
		CDC dcBmp;//���岢����һ���ڴ��豸����
		dcBmp.CreateCompatibleDC(&dc);
		CBitmap bmp99;
		bmp99.LoadBitmap(IDB_BITMAP7);//������Դ��ͼƬ
		BITMAP m_bitmap;
		bmp99.GetBitmap(&m_bitmap);//��ͼƬ����λͼ��
		CBitmap *pbmpOld = dcBmp.SelectObject(&bmp99);
		dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcBmp,0,0,m_bitmap.bmWidth,m_bitmap.bmHeight,SRCCOPY);//ʹͼ������״�ɱ�  
	}
}
