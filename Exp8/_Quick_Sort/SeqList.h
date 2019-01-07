// SeqList.h: interface for the SeqList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SEQLIST_H__34D9279D_7451_4571_9850_83A56C89D72D__INCLUDED_)
#define AFX_SEQLIST_H__34D9279D_7451_4571_9850_83A56C89D72D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

template<class T>
class SeqList  
{
public:
	SeqList( int length );
	SeqList( int length, char key );
	SeqList( int length, int choice );
	virtual ~SeqList();
	void display();
	int partition( int left, int right );
	int getArrayLength();
	void quickSort( int lower, int upper );
	void showSwapingAndComparingTimesAndArrayLength();
	void judgeIncreasingSequence();
private:
	T *Arr;
	int arraySize;
	int swapTimes;
	int compareTimes;
};

#endif // !defined(AFX_SEQLIST_H__34D9279D_7451_4571_9850_83A56C89D72D__INCLUDED_)
