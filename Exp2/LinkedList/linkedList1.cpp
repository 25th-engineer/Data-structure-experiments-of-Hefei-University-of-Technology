// linkedList1.cpp: implementation of the linkedList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "linkedList1.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

linkedList::linkedList()
{
	head = NULL;
	len = 0;
}

linkedList::~linkedList()
{
	LList* tmp = head;
	//for( int i = 0; i < len; i ++ )
	while( tmp->next )
	{
		LList *q = tmp;
		tmp = tmp->next;
		delete q;
	}
}

bool linkedList::initiateLinkedList()
{
	std::ios::sync_with_stdio(false);
	head = new LList;
	if( !head )
	{
		cout << "初始化失败！" << endl;
		return false;
	}
	head->next = NULL;
	return true;
}

bool linkedList::createLinkedListRail( int length )
{
	std::ios::sync_with_stdio(false);
	initiateLinkedList();
	LList* rail = head;
	for( int i = 1; i <= length; i ++ )
	{
		LList* tmp = new LList;
		int num;
		cin >> num;
		//num = i + 1;
		tmp->data = num;
		tmp->next = rail->next;
		rail->next = tmp;
		rail = tmp;
		len ++;
	}
	return true;
}

bool linkedList::createLinkedListFront( int length )
{
	std::ios::sync_with_stdio(false);
	initiateLinkedList();
	for( int i = 0; i < length; i ++ )
	{
		int num;
		cin >> num;
		//num = i + 1;
		LList* tmp = new LList;
		tmp->data = num;
		tmp->next = head->next;
		head->next = tmp;
		len ++;
	}
	return true;
}

void linkedList::addLinkedListNodeLast( int value )
{
	//ios::sync_with_stdio(false);
	
	LList* tmp = head;
	LList* last = NULL;
	while(tmp)
	{
		last = tmp;
		tmp = tmp->next;
	}
	LList* PNew = new LList;
	PNew->data = value;
	PNew->next = NULL;
	last->next = PNew;
	len ++;
}

bool linkedList::isEmpty()
{
	return head->next == NULL;
}

void linkedList::printLinkedList()
{
	std::ios::sync_with_stdio(false);
	if( isEmpty() )
	{
		cout << "空链表，无法打印！" << endl;
		return;
	}
	LList* tmp = head->next;
	int column = 0;
	while(tmp)
	{
		cout << setiosflags(ios::left) << setw(3) << tmp->data << " ";
		column ++;
		if( column % 10 == 0 )
			cout << endl;
		tmp = tmp->next;
	}
	cout << endl;
}

int linkedList::linkedListLength()
{
	if( isEmpty() )
	{
		cout << "空链表！" << endl;
		return -1;
	}
	int l = 0;
	LList* tmp = head->next;
	while(tmp)
	{
		tmp = tmp->next;
		l ++;
	}
	return l;
	//return len;
}

bool linkedList::getElementByPosition( int pos, int& value )
{
	ios::sync_with_stdio(false);
	if( isEmpty() )
	{
		cout << "链表为空！获取元素失败！" << endl;
		return false;
	}
	if( pos > len )
	{
		cout << "位置大于表长！获取元素失败！" << endl;
		return false;
	}
	if( pos <= 0 )
	{
		cout << "位置必须大于0！获取元素失败！" << endl;
		return false;
	}
	int index = 0;
	LList* tmp = head;
	while(tmp)
	{
		if( index == pos )
		{
			//cout << tmp->data;
			value = tmp->data;
			return true;
		}
		tmp = tmp->next;
		index ++;
	}
	return true;
}

bool linkedList::insertListByPosition( int pos, int value )
{
	ios::sync_with_stdio(false);
	if( isEmpty() )
	{
		cout << "链表为空！插入元素失败！" << endl;
		return false;
	}
	else if( pos > len )
	{
		cout << "位置大于表长且差值大于1！删除元素失败！" << endl;
		return false;
	}
	else if( pos == len )
	{
		cout << "将会直接把新节点接在链表尾部！" << endl;
		addLinkedListNodeLast( value );
		return true;
	}
	else if( pos <= 0 )
	{
		cout << "位置必须大于0！插入元素失败！" << endl;
		return false;
	}
	int index = 0;
	LList* tmp = head;
	while( index != pos - 1 && tmp )
	{
		index ++;
		tmp = tmp->next;
	}
	if( tmp == NULL )
	{
		cout << "位置大于表长且不在表长的后一位！插入元素失败！" << endl;
		return false;
	}
	LList* PNew = new LList;
	PNew->data =  value;
	PNew->next = tmp->next;
	tmp->next = PNew;
	len ++;
	return true;
}

bool linkedList::getElementByValue( int& pos, int value )
{
	ios::sync_with_stdio(false);
	if( isEmpty() )
	{
		cout << "链表为空！获取元素失败！" << endl;
		return false;
	}
	int index = 1;
	LList* tmp = head->next;
	while(tmp)
	{
		if( tmp->data == value )
		{
			pos = index;
			return true;
		}
		tmp = tmp->next;
		index ++;
	}
	return false;
}

bool linkedList::removeListNodeByPosition( int pos, int& value )
{
	ios::sync_with_stdio(false);
	if( isEmpty() )
	{
		cout << "链表为空！删除元素失败！" << endl;
		return false;
	}
	if( pos > len )
	{
		cout << "位置大于表长！删除元素失败！" << endl;
		return false;
	}
	if( pos <= 0 )
	{
		cout << "位置必须大于0！删除元素失败！" << endl;
		return false;
	}
	LList* tmp = head;
	int index = 0;
	while( index != pos - 1 && tmp )
	{
		tmp = tmp->next;
		index ++;
	}
	LList* PDel = tmp->next;
	value = PDel->data;
	tmp->next = tmp->next->next;
	delete PDel;
	len --;
	return true;
}

bool linkedList::insertListSort( int value )
{
	ios::sync_with_stdio(false);
	if( isEmpty() )
	{
		cout << "链表为空！插入元素失败！" << endl;
		return false;
	}
	LList* tmp = head;
	while( tmp->next && tmp->next->data < value )//下一个节点的data比value小就继续循环
	//写成下面这样导致比最后一个节点的data大的value无法插入！因为循环结束时tmp->next为NULL，无法插入。
	//while( tmp && tmp->next->data < value )
	{
		//if( tmp->data < value )
			tmp = tmp->next;
	}
	LList* PNew = new LList;
	PNew->data = value;
	PNew->next = tmp->next;
	tmp->next = PNew;
	return true;
}

bool linkedList::oddEvenSort( linkedList& LA,linkedList& LB )
{
	ios::sync_with_stdio(false);
	if( isEmpty() )
	{
		cout << "原链表为空！分配元素失败！" << endl;
		return false;
	}
	//if( !LA.head->next && !LB.head->next )
	if( !LA.head && !LB.head )
	{
		LA.initiateLinkedList();
		LB.initiateLinkedList();
	}
	LList* tmp = head->next;
	while(tmp)
	{
		if( tmp->data >= 0 && ( tmp->data & 1 ) )
			LA.addLinkedListNodeLast( tmp->data );
		//else if( tmp->data >= 0 && !( tmp->data & 1 ) )
		else
			LB.addLinkedListNodeLast( tmp->data );
		tmp = tmp->next;
	}
	return true;
}
