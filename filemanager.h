// filemanager.h: interface for the filemanager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILEMANAGER_H__6F4F7A25_5774_454B_A52D_2723560CF3CD__INCLUDED_)
#define AFX_FILEMANAGER_H__6F4F7A25_5774_454B_A52D_2723560CF3CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include"customer.h"
#include"table.h"
class filemanager  
{
private:

public:
	filemanager();
	virtual ~filemanager();
	void removec(customer);
	void tablesave();
	void tableread();
	void cread();
	void csave(customer c);
	void csearchname(string names);
	void csearchtable(int tnums);
	void csearchphone(long phones);
	static int count;

};
 

#endif // !defined(AFX_FILEMANAGER_H__6F4F7A25_5774_454B_A52D_2723560CF3CD__INCLUDED_)
