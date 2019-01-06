// SeqList.h: interface for the SeqList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SEQLIST_H__50235134_2934_4E06_B7C7_DB7B8CCB6924__INCLUDED_)
#define AFX_SEQLIST_H__50235134_2934_4E06_B7C7_DB7B8CCB6924__INCLUDED_

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
	SeqList( int length, double choice );
	virtual ~SeqList();
	void display();
	//int partition( int left, int right );
	void partition( int left, int right );
	int getArrayLength();
	//void quickSort( int lower, int upper );
	void showSwapingAndComparingTimesAndArrayLength();
	void judgeIncreasingSequence();
private:
	T *Arr;
	int arraySize;
	int swapTimes;
	int compareTimes;
};

#endif // !defined(AFX_SEQLIST_H__50235134_2934_4E06_B7C7_DB7B8CCB6924__INCLUDED_)
