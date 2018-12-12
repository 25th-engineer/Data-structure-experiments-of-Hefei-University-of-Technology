// SeqList.cpp: implementation of the SeqList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SeqList.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SeqList::SeqList()
{
	length = 0;
}

SeqList::~SeqList()
{
	ios::sync_with_stdio(false);
	cout << "The SeqList destruction has been called!" << endl;
}

bool SeqList::seqListFull()
{
	return length == maxn - 1;
}

bool SeqList::seqListEmpty()
{
	return length == 0;
}

void SeqList::randomInsert( elementType number )
{
	ios::sync_with_stdio(false);
	if( seqListFull() )
	{
		cerr << "Inserting failed!The sequence list has been full.Error in void SeqList::randomInsert( int number )" << endl;
		return;
	}

	srand( time(NULL) );
	elementType last = -999;
	for( int i = 0; i < number; i ++ )
	{
		elementType key = rand() % ( 10000 - 100 + 1 ) + 100;
		if( key >= last )
		{
			length ++;
			Arr[length] = key;
			last = key;
		}
		else
		{
			i --;
		}
	}
}

void SeqList::insert( elementType value )
{
	ios::sync_with_stdio(false);
	if( seqListFull() )
	{
		cerr << "Inerting failed!The sequence list has been full.Error in void SeqList::insert( elementType value )" << endl;
		return;
	}

	length ++;
	Arr[length] = value;
}

elementType SeqList::binarySearch( elementType value )
{
	ios::sync_with_stdio(false);
	if( seqListEmpty() )
	{
		cerr << "Searching failed!The sequence list is empty.Error in elementType SeqList::binarySearch( elementType value )" << endl;
		return -1;
	}
	elementType lower = 0, upper = length;
	while( lower <= upper )
	{
		elementType mid = ( lower + upper ) >> 1; //+ 1;
		if( Arr[mid] == value )
		{
			return mid;
		}
		if( Arr[mid] >= value )
		{
			upper = mid - 1;
		}
		else
		{
			lower = mid + 1;
		}
	}
	return -1;
}

void SeqList::showLength()
{
	ios::sync_with_stdio(false);
	cout << length << endl;
}