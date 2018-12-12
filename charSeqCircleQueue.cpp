// charSeqCircleQueue.cpp: implementation of the charSeqCircleQueue class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "charSeqCircleQueue.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

charSeqCircleQueue::charSeqCircleQueue()
{
	_front = _rear = 0;
}

charSeqCircleQueue::~charSeqCircleQueue()
{
	ios::sync_with_stdio(false);
	cout << "The charSeqCircleQueue destruction has been called!" << endl;
}

bool charSeqCircleQueue::emptyCharSeqCircleQueue()
{
	return _front == _rear;
} 

bool charSeqCircleQueue::fullCharSeqCircleQueue()
{
	return ( _rear + 1 ) % maxn == _front;
}

bool charSeqCircleQueue::enQueue( elementType1 value )
{
	if( fullCharSeqCircleQueue() )
	{
		cerr << "Seq-Circle-Queue is full!Error in charSeqCircleQueue::::enQueue()!" << endl;
		return false;
	}
	data[_rear] = value;
	_rear = ( _rear + 1 ) % maxn;
	return true;
}

bool charSeqCircleQueue::deQueue( elementType1 &value )
{
	if( emptyCharSeqCircleQueue() )
	{
		cerr << "Seq-Circle-Queue is empty!Error in charSeqCircleQueue::popFront()!" << endl;
		return false;
	}
	value = data[_front];
	_front = ( _front + 1 ) % maxn;
	return true;
}

bool charSeqCircleQueue::getFront( elementType1 &value )
{
	if( emptyCharSeqCircleQueue() )
	{
		cerr << "Seq-Circle-Queue is empty!Error in charSeqCircleQueue::::getFront()!" << endl;
		return false;
	}
	value = data[_front];
	return true;
}

int charSeqCircleQueue::length()
{
	if( emptyCharSeqCircleQueue() )
	{
		cerr << "Seq-Circle-Queue is empty!Error in charSeqCircleQueue::::length()!" << endl;
		return -1;
	}
	return ( _rear - _front + maxn ) % maxn;
}