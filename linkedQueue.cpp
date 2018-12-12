// linkedQueue.cpp: implementation of the linkedQueue class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "linkedQueue.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

linkedQueue::linkedQueue()
{
	_front = _rear = NULL;
}

linkedQueue::~linkedQueue()
{
	LNode *tmp = NULL;
	while( _front != _rear )
	{
		tmp = _front;
		_front = _front->link;
		delete tmp;
	}
	cout << "The linkedQueue destruction has been called!" << endl;
}

bool linkedQueue::emptyLinkedQueue()
{
	return _front == NULL;
}

bool linkedQueue::enQueue( elementType value )
{
	LNode *newNode = new LNode;
	if( !newNode )
	{
		cerr << "Space allocating falied!Error in linkedQueue::enQueue()!" << endl;
		return false;
	}
	newNode->data = value;
	newNode->link = NULL;
	if( emptyLinkedQueue() )
	{
		_front = _rear = newNode;
	}
	else
	{
		_rear->link = newNode;
		_rear = newNode;
	}
	return true;
}

bool linkedQueue::deQueue( elementType &value )
{
	if( emptyLinkedQueue() )
	{
		cerr << "Node deleting falied!Error in linkedQueue::deQueue()!" << endl;
		return false;
	}
	LNode *tmp = _front;
	value = _front->data;
	_front = _front->link;
	delete tmp;
	if( _front == NULL )
		_rear = NULL;
	return true;
}

bool linkedQueue::getFront( elementType &value )
{
	if( emptyLinkedQueue() )
	{
		cerr << "Queue is empty!\nNode-data acquiring falied!Error in linkedQueue::deQueue()!" << endl;
		return false;
	}
	value = _front->data;
	return true;
}

int linkedQueue::length()
{
	if( emptyLinkedQueue() )
	{
		cerr << "Queue is empty!" << endl;
		return -1;
	}
	LNode *tmp = _front;
	int _size = 0;
	while( tmp != NULL )
	{
		tmp = tmp->link;
		_size ++;
	}
	return _size;
}

void linkedQueue::oddOrEven( elementType value )
{
	if( value & 1 )
	{
		enQueue(value);
		cout << value << " will be added to the queue!" << endl;
		//cout << (*this);
		cout << "The current queue is as follow:" << endl << (*this);
		cout << "The current length of the queue is " << (*this).length() << endl;

	}
	else if( !( value & 1) && value != 0 )
	{
		elementType x;
		deQueue(x);
		cout << x << " has been deleted from the queue!" << endl;
		cout << (*this);
		cout << "The current queue is as follow:" << endl << (*this);
		cout << "The current length of the queue is " << (*this).length() << endl;
	}
	else //if( value == 0 )
	{
		cout << "The value = " << value << ", the _SeqCircleQueue::oddOrEven() has been stoped!" << endl;
		return;
	}
}