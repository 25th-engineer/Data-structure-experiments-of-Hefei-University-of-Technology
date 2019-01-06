// BinarySearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SeqList.h"

void test1()
{
	ios::sync_with_stdio(false);
	SeqList SL1;
	elementType number;
	cin >> number;
	SL1.randomInsert( number );
	cout << SL1;
	elementType value;
	for( int i = 0; i < number; i ++ )
	{
		cin >> value;
		if( SL1.binarySearch(value) != -1 )
		{
			cout << value << " is in the sequence list." << endl;
		}
		else
		{
			cout << value << " is not in the sequence list." << endl;
		}
	}
}

void test2()
{
	ios::sync_with_stdio(false);
	SeqList SL1;
	elementType value;
	while( cin >> value )
	{
		if( value == -999 )
		{
			break;
		}
		SL1.insert(value);
	}
	SL1.showLength();
	cout << SL1;
	
	elementType key;
	while( cin >> key )
	{
		//cin >> key;
		if( key == -99 )
		{
			//break;
			return;
		}
		if( SL1.binarySearch(key) != -1 )
		{
			cout << key << " is in the sequence list." << endl;
		}
		else
		{
			cout << key << " is not in the sequence list." << endl;
		}
	}
	
}

int main(int argc, char* argv[])
{
	test2();
	
	return 0;
}
