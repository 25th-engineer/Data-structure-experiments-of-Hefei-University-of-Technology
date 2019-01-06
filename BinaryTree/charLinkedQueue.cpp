// charLinkedQueue.cpp: implementation of the charLinkedQueue class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "charLinkedQueue.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

charLinkedQueue::charLinkedQueue()
{
	_front = _rear = NULL;
}

charLinkedQueue::~charLinkedQueue()
{
	CLNode *tmp = NULL;
	while( _front != _rear )
	{
		tmp = _front;
		_front = _front->link;
		delete tmp;
	}
	cout << "The charLinkedQueue destruction has been called!" << endl;
}

bool charLinkedQueue::emptyCharLinkedQueue()
{
	return _front == NULL;
}

bool charLinkedQueue::enQueue( bitNode *value )
{
	CLNode *newNode = new CLNode;
	if( !newNode )
	{
		cerr << "Space allocating falied!Error in charLinkedQueue::enQueue()!" << endl;
		return false;
	}
	newNode->data = value;
	newNode->link = NULL;
	if( emptyCharLinkedQueue() )
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

bool charLinkedQueue::deQueue( /*elementType &value*/ )
{
	if( emptyCharLinkedQueue() )
	{
		cerr << "Node deleting falied!Error in charLinkedQueue::deQueue()!" << endl;
		return false;
	}
	CLNode *tmp = _front;
	//value = _front->data;
	_front = _front->link;
	delete tmp;
	if( _front == NULL )
		_rear = NULL;
	return true;
}

bool charLinkedQueue::getFront( bitNode *&value )
{
	if( emptyCharLinkedQueue() )
	{
		cerr << "Queue is empty!\nNode-data acquiring falied!Error in charLinkedQueue::deQueue()!" << endl;
		return false;
	}
	value = _front->data;//原来我是注释掉的，导致输出一直是A；
	return true;
}

int charLinkedQueue::length()
{
	if( emptyCharLinkedQueue() )
	{
		cerr << "Queue is empty!" << endl;
		return -1;
	}
	CLNode *tmp = _front;
	int _size = 0;
	while( tmp != NULL )
	{
		tmp = tmp->link;
		_size ++;
	}
	return _size;
}