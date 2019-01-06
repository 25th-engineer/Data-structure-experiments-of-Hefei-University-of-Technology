// linkedQueue.h: interface for the linkedQueue class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINKEDQUEUE_H__6DF75075_BE53_4235_872D_3381A1A450D0__INCLUDED_)
#define AFX_LINKEDQUEUE_H__6DF75075_BE53_4235_872D_3381A1A450D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "stdafx.h"


class linkedQueue  
{
public:
	linkedQueue();
	virtual ~linkedQueue();
	bool emptyLinkedQueue();
	//bool fullSeqCircleQueue();
	bool enQueue( elementType value );
	bool deQueue( elementType &value );
	bool getFront( elementType &value );
	int length();
	void oddOrEven( elementType value );
	friend ostream &operator<<( ostream &os, linkedQueue &lq )
	{
		/*
		if( ( scq._front - 1 ) % maxn == scq._rear )
			return os;
		int column  = 0;
		for( int i = scq._front; i % maxn != scq._rear; i = ( i + 1 ) % maxn )
		{
			os << setw(3) << setiosflags(ios::left) << scq.data[i] << " ";
			column ++;
			if( column % 10 == 0 )
				os << endl;
		}
		os << endl;
		*/
		if( lq._front == NULL )
			return os;
		LNode *tmp = lq._front;
		int column = 0;
		while( tmp != lq._rear->link )
		{
			os << setw(4) << setiosflags(ios::left) << tmp->data << " ";
			column ++;
			tmp = tmp->link;
			if( column % 10 == 0 )
				os << endl;
		}
		os << endl;
	}
private:
	LNode *_front;
	LNode *_rear;
};

#endif // !defined(AFX_LINKEDQUEUE_H__6DF75075_BE53_4235_872D_3381A1A450D0__INCLUDED_)
