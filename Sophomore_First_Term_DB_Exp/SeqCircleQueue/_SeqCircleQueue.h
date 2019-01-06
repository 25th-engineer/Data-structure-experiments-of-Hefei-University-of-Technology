// _SeqCircleQueue.h: interface for the _SeqCircleQueue class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX__SEQCIRCLEQUEUE_H__FCBC0603_27E1_4352_833C_6BED9B418B96__INCLUDED_)
#define AFX__SEQCIRCLEQUEUE_H__FCBC0603_27E1_4352_833C_6BED9B418B96__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class _SeqCircleQueue  
{
public:
	_SeqCircleQueue();
	virtual ~_SeqCircleQueue();
	bool emptySeqCircleQueue();
	bool fullSeqCircleQueue();
	bool enQueue( elementType value );
	bool deQueue( elementType &value );
	bool getFront( elementType &value );
	int length();
	void oddOrEven( elementType value );
	friend ostream &operator<<( ostream &os, _SeqCircleQueue &scq )
	{
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
	}
private:
	elementType data[maxn];
	int _front;
	int _rear;

};

#endif // !defined(AFX__SEQCIRCLEQUEUE_H__FCBC0603_27E1_4352_833C_6BED9B418B96__INCLUDED_)
