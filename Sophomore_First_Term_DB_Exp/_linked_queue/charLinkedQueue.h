// charLinkedQueue.h: interface for the charLinkedQueue class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHARLINKEDQUEUE_H__91C9120D_49FD_417A_8336_57503196B63F__INCLUDED_)
#define AFX_CHARLINKEDQUEUE_H__91C9120D_49FD_417A_8336_57503196B63F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class charLinkedQueue  
{
public:
	charLinkedQueue();
	virtual ~charLinkedQueue();
	bool emptyCharLinkedQueue();
	//bool fullSeqCircleQueue();
	bool enQueue( elementType1 value );
	bool deQueue( elementType1 &value );
	bool getFront( elementType1 &value );
	int length();
	friend ostream &operator<<( ostream &os, charLinkedQueue &clq )
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
		if( clq._front == NULL )
			return os;
		CLNode *tmp = clq._front;
		int column = 0;
		while( tmp != clq._rear->link )
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
	CLNode *_front;
	CLNode *_rear;

};

#endif // !defined(AFX_CHARLINKEDQUEUE_H__91C9120D_49FD_417A_8336_57503196B63F__INCLUDED_)
