// filemanager.cpp: implementation of the filemanager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "restaurant.h"
#include "filemanager.h"
#include <fstream>
#include "table.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
int filemanager::count = 0;
filemanager::filemanager()
{

}

filemanager::~filemanager()
{

}
void filemanager::csave(customer c)
{
	int i;
	filemanager::count++;
	ofstream out;
	ifstream in("table.txt",ios_base::in);//改变餐桌状态为不可预订
	table T[50];
	for(i = 0;i<50;i++)
	{
		T[i].tbnum = in.get();
		T[i].state = in.get();
		T[i].people = in.get();
	}
	in.close();
	T[c.tnum].state = 0;
	ofstream outc("table.txt",ios_base::out);
	for(i = 0;i<50;i++)
	{
		outc<<T[i].tbnum<<" "<<T[i].state<<" "<<T[i].people<<" "<<endl;
	}
	outc.close();


	
	out.open("customer.txt",ios_base::out||ios_base::app);
	out<<c.name<<" "<<c.time<<" "<<c.tnum<<" "<<c.phone<<" "<<c.people<<" "<<c.note<<" "<<endl;//将客户信息保存到文件中
	out.close();	
	
}/*
void filemanager::removec(customer);
	void tablesave();
	void tableread();
	void cread();
	void csave();
	void csearchname(string names);
	void csearchtable(int tnums);
	void csearchphone(long phones);*/