// _SeqCircleQueue.cpp: implementation of the _SeqCircleQueue class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "_SeqCircleQueue.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

_SeqCircleQueue::_SeqCircleQueue()
{
	_front = _rear = 0;
}

_SeqCircleQueue::~_SeqCircleQueue()
{
	ios::sync_with_stdio(false);
	cout << "The _SeqCircleQueue destruction has been called!" << endl;
}

bool _SeqCircleQueue::emptySeqCircleQueue()
{
	return _front == _rear;
} 

bool _SeqCircleQueue::fullSeqCircleQueue()
{
	return ( _rear + 1 ) % maxn == _front;
}

bool _SeqCircleQueue::enQueue( elementType value )
{
	if( fullSeqCircleQueue() )
	{
		cerr << "Seq-Circle-Queue is full!Error in _SeqCircleQueue::enQueue()!" << endl;
		return false;
	}
	data[_rear] = value;
	_rear = ( _rear + 1 ) % maxn;
	return true;
}

bool _SeqCircleQueue::deQueue( elementType &value )
{
	if( emptySeqCircleQueue() )
	{
		cerr << "Seq-Circle-Queue is empty!Error in _SeqCircleQueue::popFront()!" << endl;
		return false;
	}
	value = data[_front];
	_front = ( _front + 1 ) % maxn;
	return true;
}

bool _SeqCircleQueue::getFront( elementType &value )
{
	if( emptySeqCircleQueue() )
	{
		cerr << "Seq-Circle-Queue is empty!Error in _SeqCircleQueue::getFront()!" << endl;
		return false;
	}
	value = data[_front];
	return true;
}

int _SeqCircleQueue::length()
{
	if( emptySeqCircleQueue() )
	{
		cerr << "Seq-Circle-Queue is empty!Error in _SeqCircleQueue::length()!" << endl;
		return -1;
	}
	return ( _rear - _front + maxn ) % maxn;
}

void _SeqCircleQueue::oddOrEven( elementType value )
{
	if( value & 1 )
	{
		enQueue(value);
		cout << value << " will be added to the queue!" << endl;
		cout << (*this);
	}
	else if( !( value & 1) && value != 0 )
	{
		elementType x;
		deQueue(x);
		cout << x << " has been deleted from the queue!" << endl;
		cout << (*this);
	}
	else //if( value == 0 )
	{
		cout << "The _SeqCircleQueue::oddOrEven() has been stoped!" << endl;
		return;
	}
}