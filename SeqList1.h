// SeqList1.h: interface for the SeqList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SEQLIST1_H__5F69CE41_7D8B_4396_BAAE_F849B1FD54D1__INCLUDED_)
#define AFX_SEQLIST1_H__5F69CE41_7D8B_4396_BAAE_F849B1FD54D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class SeqList  
{
public:
	SeqList();
	virtual ~SeqList();
	void printList();
	int Length();
	int locate( elementType value );//返回第一个值为value的位置，没有则返回-1
	bool isEmpty();//判空
	bool isFull();//判满
	bool getElement( int pos, elementType& value );//获取pos位置的值
	bool insertList( int pos, elementType value );//在pos位置前插入value值
	bool insertList_1( elementType value );//在尾部插入value值
	bool deleteListNode( int pos, elementType& value );//按位置删除元素
	bool deleteListNode_1( int value );//按值删除元素
	bool deleteListNode_2( int value );//按值删除所有对应元素

	bool incInsert( int value );//插入保持递增有序
	bool oddEvenSort( SeqList& LA, SeqList& LB);//顺序表奇数偶数分类
	bool intersectionSet( SeqList& LA, SeqList& LB, SeqList& LC );//求两递增顺序表交集
	bool delRepeatedNode();//删除重复元素
	bool delRepeatedNode_2();//删除重复元素
	bool unionSet( SeqList& LA, SeqList& LB );//求并集

	bool unionSet( SeqList& LA, SeqList& LB, SeqList& LC );//求并集
	bool subTractSet( SeqList& LA, SeqList& LB, SeqList& LC );// 求差集

	bool intersectionSet( SeqList& LA, SeqList& LB );//求交集
	bool subTractSet( SeqList& LA, SeqList& LB );// 求差集

	bool subSet( SeqList& LA, SeqList& LB );//判断A是否为B的子集

	int midSearch( SeqList& LA, SeqList& LB );//输出两等长升序序列的中位数


	//bool SeqList::delRepeatedNode( SeqList& L );
private:
	elementType Arr[maxn];//存放表元素的数组
	size_t listSize;//记录当前顺序表的大小
};

#endif // !defined(AFX_SEQLIST1_H__5F69CE41_7D8B_4396_BAAE_F849B1FD54D1__INCLUDED_)
