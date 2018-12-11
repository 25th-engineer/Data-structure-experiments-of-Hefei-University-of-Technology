// linkedList1.h: interface for the linkedList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINKEDLIST1_H__4C3F34C9_D36C_43D6_97CF_A8E55FD6BD7D__INCLUDED_)
#define AFX_LINKEDLIST1_H__4C3F34C9_D36C_43D6_97CF_A8E55FD6BD7D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "StdAfx.h"

using namespace std;

class linkedList  
{
public:
	linkedList();//构造函数
	virtual ~linkedList();//析构函数，销毁单链表
	bool createLinkedListRail( int length );//尾插法构建单链表
	bool createLinkedListFront( int length );//头插法构建单链表
	void addLinkedListNodeLast( int value );//警告：必须初始化才能使用！
	//我尝试判断调用对象的链表是否初始化来作为是否调用该函数的依据，结果失败：无论如何判断，总是不能在零节点时插入
	bool initiateLinkedList();//初始化单链表
	bool isEmpty();//判断单链表是否为空
	bool getElementByPosition( int pos, int& value );//求单链表中第pos个元素（函数），若不存在，报错
	bool insertListByPosition( int pos, int value );//在第pos个结点前插入值为value的结点
	bool getElementByValue( int& pos, int value );//链表中查找元素值为x的结点，成功返回结点指针，失败报错。
	bool removeListNodeByPosition( int pos, int& value );//删除单链表中第pos个元素结点
	bool insertListSort( int value );//在一个递增有序的单链表L中插入一个值为value的元素，并保持其递增有序特性
	bool oddEvenSort( linkedList& LA,linkedList& LB );//将调用单链表中的元素按奇偶性分配給被调用的单链表LA与LB
	void printLinkedList();//打印单链表
	int linkedListLength();//返回单链表长度
private:
	LList *head;
	int len;
};

#endif // !defined(AFX_LINKEDLIST1_H__4C3F34C9_D36C_43D6_97CF_A8E55FD6BD7D__INCLUDED_)
