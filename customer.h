// customer.h: interface for the customer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CUSTOMER_H__C7ED8950_8E13_4809_A83E_F149BE6C93A4__INCLUDED_)
#define AFX_CUSTOMER_H__C7ED8950_8E13_4809_A83E_F149BE6C93A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
using namespace std;


class customer  
{
public:
	customer(string names,string ordert,string times,int moneys,int tnums,string phones,int peoples,string notes);
	virtual ~customer();
	customer();
	string name;
	int tnum;
    string phone;
	int people;
	string note;
	string time;
	int money;
	string ordertime;
};

#endif // !defined(AFX_CUSTOMER_H__C7ED8950_8E13_4809_A83E_F149BE6C93A4__INCLUDED_)
