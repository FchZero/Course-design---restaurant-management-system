// jiucan.cpp : implementation file
//

#include "stdafx.h"
#include "restaurant.h"
#include "jiucan.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// jiucan dialog


jiucan::jiucan(CWnd* pParent /*=NULL*/)
	: CDialog(jiucan::IDD, pParent)
{
	//{{AFX_DATA_INIT(jiucan)
	m_table = 0;
	//}}AFX_DATA_INIT
}


void jiucan::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(jiucan)
	DDX_Text(pDX, IDC_Etable, m_table);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(jiucan, CDialog)
	//{{AFX_MSG_MAP(jiucan)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// jiucan message handlers

void jiucan::OnOK() 
{
	//��ȡ����״̬��Ϣ
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
	if(T[m_table-1].state == 0)//�������Ϊ����״̬
	{
        //�ı����״̬Ϊ����Ԥ��
		mt = m_table;//�������Ŵ��ݸ���һ������
		T[m_table-1].state = 2;
		ofstream outc("table.txt",ios_base::out);
		for(i = 0;i<50;i++)
		{
			outc<<T[i].tbnum<<" "<<T[i].state<<" "<<T[i].people<<" "<<endl;
		}
		outc.close();
		EndDialog(0);
		CCP dlg;
		dlg.DoModal();
		

	}
	else
	{
		UpdateData(TRUE);
		if(T[m_table-1].state == 2) 
		{
			AfxMessageBox("�ò������ھͲͣ�");
		}

		if(T[m_table-1].state == 1)
		{
		//��ȡ�ͻ���Ϣ
			int kk,i;
			ifstream k("k.txt",ios_base::in);
			int kkk;
			k>>kkk;
			k.close();

			customer cc[100];
			UpdateData(TRUE);
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
			for(int j = 0;j<ii;j++)
			{
				if(cc[j].tnum==m_table)
				{
					flag = 1;
					break;
				}
			}
			
		
			
			
			//�ı����״̬Ϊ����Ԥ��
			T[m_table-1].state = 3;
			ofstream outc("table.txt",ios_base::out);
			for(i = 0;i<50;i++)
			{
				outc<<T[i].tbnum<<" "<<T[i].state<<" "<<T[i].people<<" "<<endl;
			}
			outc.close();


            //ɾ���ͻ���Ϣ����
			string mm = "none";
			ifstream k1("k.txt",ios_base::in);
			k1>>kkk;
			k1.close();

			UpdateData(TRUE);
			int m = m_table;
			ii = 0;
			in.open("customer.txt",ios_base::in);
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
			flag = 0;
			for( j = 0;j<ii+1;j++)
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
				cc[kk].name = "none";
			}


//���¿ͻ���Ϣ���ļ���	

			ofstream out;
			out.open("customer.txt",ios_base::out);
			for(int l = 0;l<ii+1;l++)
			{
				if(mm.compare(cc[j].name) !=0)
				{
					out<<cc[j].name<<" "<<cc[j].ordertime<<" "<<cc[j].time<<" "<<cc[j].money<<" "<<cc[j].tnum<<" "<<cc[j].phone<<" "<<cc[j].people<<" "<<cc[j].note<<endl;//���ͻ���Ϣ���浽�ļ���
	             
				}
			} 
			out.close();
			if(flag == 0)
			{
				AfxMessageBox("û���ҵ��ÿͻ���");
			}	

			//���ͻ���k����1
			int k3 = 0;
			ifstream k4;
			k4.open("k.txt",ios_base::in);
			k4>>k3;
			k4.close();
			
			k3 = k3-1;
			ofstream k2("k.txt",ios_base::out);
			k2<<k3;
			k2.close();

	    	mt = m_table;//�������Ŵ��ݸ���һ������
			EndDialog(0);
			CCP dlg;//�򿪾Ͳʹ���
			dlg.DoModal();
		}
	}
}
