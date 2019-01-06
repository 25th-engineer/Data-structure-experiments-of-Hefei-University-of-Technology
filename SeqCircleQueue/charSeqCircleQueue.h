// charSeqCircleQueue.h: interface for the charSeqCircleQueue class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHARSEQCIRCLEQUEUE_H__FBB4F8DD_2EF9_43A6_8E23_FD7E4C56908E__INCLUDED_)
#define AFX_CHARSEQCIRCLEQUEUE_H__FBB4F8DD_2EF9_43A6_8E23_FD7E4C56908E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class charSeqCircleQueue  
{
public:
	charSeqCircleQueue();
	virtual ~charSeqCircleQueue();
	bool emptyCharSeqCircleQueue();
	bool fullCharSeqCircleQueue();
	bool enQueue( elementType1 value );
	bool deQueue( elementType1 &value );
	bool getFront( elementType1 &value );
	int length();
	friend ostream &operator<<( ostream &os, charSeqCircleQueue &cscq )
	{
		if( ( cscq._front - 1 ) % maxn == cscq._rear )
			return os;
		int column  = 0;
		for( int i = cscq._front; i % maxn != cscq._rear; i = ( i + 1 ) % maxn )
		{
			os << setw(3) << setiosflags(ios::left) << cscq.data[i] << " ";
			column ++;
			if( column % 10 == 0 )
				os << endl;
		}
		os << endl;
	}
private:
	elementType1 data[maxn];
	int _front;
	int _rear;

};

#endif // !defined(AFX_CHARSEQCIRCLEQUEUE_H__FBB4F8DD_2EF9_43A6_8E23_FD7E4C56908E__INCLUDED_)
