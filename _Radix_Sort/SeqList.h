// SeqList.h: interface for the SeqList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SEQLIST_H__136D8D2A_8AA4_45E9_B1DF_285C02F2B3F2__INCLUDED_)
#define AFX_SEQLIST_H__136D8D2A_8AA4_45E9_B1DF_285C02F2B3F2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//#include "Rec.h"

template<class T>
class SeqList  
{
public:
	SeqList();
	SeqList( int length );
	SeqList( int length, char key );
	SeqList( int length, int choice );
	SeqList( int length, double choice );
	virtual ~SeqList();
	void display();
	void readDataFromFile();

	void countSort( int p );
	void radixSort();

	int getArrayLength();
	T *getArray();
	void showSwapingAndComparingTimesAndArrayLength();
	void judgeIncreasingSequence();
private:
    T *Arr;
	int arraySize;
	int swapTimes;
	int compareTimes;
};

#endif // !defined(AFX_SEQLIST_H__136D8D2A_8AA4_45E9_B1DF_285C02F2B3F2__INCLUDED_)
