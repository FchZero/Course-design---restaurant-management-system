// customer.cpp: implementation of the customer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "restaurant.h"
#include "customer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

customer::customer(string names,string ordert,string times,int moneys,int tnums,string phones,int peoples,string notes)
{
	name = names;
	money = moneys;
	tnum = tnums;
	phone = phones;
	people = peoples;
	note = notes;
	time = times;
	ordertime = ordert;

}


customer::~customer()
{

}
customer::customer()
{
	name = " ";
}
