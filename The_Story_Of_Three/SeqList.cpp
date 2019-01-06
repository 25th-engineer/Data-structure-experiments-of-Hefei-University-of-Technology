// SeqList.cpp: implementation of the SeqList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SeqList.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

template<class T>
SeqList<T>::SeqList( int length )
{
	ios::sync_with_stdio(false);
	srand( time(NULL) );
	Arr = new T[length];
	arraySize = swapTimes = compareTimes = 0;
	for( int i = 0; i < length; i ++ )
	{
		int value = rand() % ( 10000 - 100 + 1 ) + 100;
		Arr[i] = value;
		arraySize ++;
	}
}

template<class T>
SeqList<T>::SeqList( int length, char key )
{
	ios::sync_with_stdio(false);
	srand( time(NULL) );
	Arr = new T[length];
	arraySize = swapTimes = compareTimes = 0;
	int maxValue = -999;
	for( int i = 0; i < length; )
	{
		int value = rand() % ( 10000 - 100 + 1 ) + 100;
		value = max( value, maxValue);
		if( value != maxValue )
		{
			maxValue = value;
			Arr[i] = value;
			i ++;
			arraySize ++;
		}
		else
		{
			maxValue += rand() % 100 + 50;
			Arr[i] = maxValue;
			i ++;
			arraySize ++;
		}
	}
}

template<class T>
SeqList<T>::SeqList( int length, int choice )
{
	ios::sync_with_stdio(false);
	srand( time(NULL) );
	Arr = new T[length];
	arraySize = swapTimes = compareTimes = 0;
	for( int i = 0; i < length; i ++ )
	{
		//int value = rand() % ( 10000 - 100 + 1 ) + 100;
		//Arr[i] = value;
		Arr[i] = i + 1;
		arraySize ++;
	}
}

template<class T>
SeqList<T>::SeqList( int length, double choice )
{
	ios::sync_with_stdio(false);
	srand( time(NULL) );
	Arr = new T[length];
	arraySize = swapTimes = compareTimes = 0;
	for( int i = 0; i < length; i ++ )
	{
		//int value = rand() % ( 10000 - 100 + 1 ) + 100;
		//Arr[i] = value;
		//Arr[i] = i + 1;
		cin >> Arr[i];
		arraySize ++;
	}
}

template<class T>
SeqList<T>::~SeqList()
{
	ios::sync_with_stdio(false);
	delete []Arr;
	arraySize = 0;
	cout << "The destruction has been called." << endl;
}

template<class T>
void SeqList<T>::display()
{
	ios::sync_with_stdio(false);
	HANDLE hOut; 
    //  获取输出流的句柄
    hOut = GetStdHandle(STD_OUTPUT_HANDLE); 
	int column = 0;
	for( int i = 0; i < arraySize; i ++ )
	{
		if( Arr[i] % 3 == 0 )
		{
			SetConsoleTextAttribute(hOut, 128 | 8 | 1 );
		}
		if( Arr[i] % 3 == 1 )
		{
			SetConsoleTextAttribute(hOut, 128 | 8 | 2 );
		}
		if( Arr[i] % 3 == 2 )
		{
			SetConsoleTextAttribute(hOut, 128 | 8 | 3 );
		}

		cout << setw(6) << setiosflags(ios::left) << Arr[i] << " ";
		column ++;
		
		if( column% 10 == 0 )
		{
			cout << endl;
		}
	}
	//SetConsoleTextAttribute(hOut, 8 | 7 );
	cout << endl;
}

/*
template<class T>
int SeqList<T>::partition( int left, int right )
{
	int pivot = Arr[left];
	while( left < right )
	{
		while( pivot <= Arr[right] && left < right )
		{
			compareTimes ++;
			right --;
		}
		if( left != right )
		{
			//left ++;
			Arr[left] = Arr[right]; 
			swapTimes ++;
			left ++;
		}
		while( Arr[left] <= pivot && left < right )
		{
			compareTimes ++;
			left ++;
		}
		if( left != right )
		{
			//right --;
			Arr[right] = Arr[left];
			swapTimes ++;
			right --;
		}
	}
	Arr[left] = pivot;
	return left;
}
*/

/*
template<class T>
void SeqList<T>::quickSort( int lower, int upper )
{
	//upper -= 1;
	int pivot = partition( lower, upper );
	//int pivot = partition( lower, upper );
	if( lower < pivot )
	{
		//pivot -= 1;
		quickSort( lower, pivot - 1);
		//quickSort( lower, pivot);
	}
	if( pivot < upper )
	{
		//pivot += 1;
		quickSort( pivot + 1, upper );
		//quickSort( pivot, upper );
	}
}
*/

template<class T>
int SeqList<T>::getArrayLength()
{
	return arraySize;
}

template<class T>
void SeqList<T>::showSwapingAndComparingTimesAndArrayLength()
{
	ios::sync_with_stdio(false);
	HANDLE hOut; 
    //  获取输出流的句柄
    hOut = GetStdHandle(STD_OUTPUT_HANDLE); 
	SetConsoleTextAttribute(hOut, 8 | 4 );
	cout << "Array length = " << arraySize << endl;
	cout << "Comparing times = " << compareTimes << endl;
	cout << "Swaping times = " << swapTimes << endl;
	SetConsoleTextAttribute(hOut, 8 | 7 );
}

template<class T>
void SeqList<T>::judgeIncreasingSequence()
{
	for( int i = 1; i < arraySize; i ++ )
	{
		if( Arr[i] >= Arr[ i - 1 ] )
		{
			continue;
		}
		else
		{
			cout << "Not increasing." << endl;
			cout << i - 1 << "-th --- " << Arr[ i - 1 ] << endl;
			cout << i << "-th ---- " << Arr[i] << endl;
			//return;
		}
	}
	cout << "Completely increasing." << endl;
	return;
}

template<class T>
void SeqList<T>::partition( int lower, int upper )
{
	int step = lower;
	while( step <= upper )
	{
		if( Arr[step] % 3 == 0  )
		{
			compareTimes ++;
			swap( Arr[step], Arr[lower] );
			swapTimes ++;
			lower ++;
		}
		step ++;
	}
	step = upper;
	while( step >= lower )
	{
		if( Arr[step] % 3 == 2 )
		{
			compareTimes ++;
			swap( Arr[step], Arr[upper] );
			swapTimes ++;
			upper --;
		}
		step --;
	}
}