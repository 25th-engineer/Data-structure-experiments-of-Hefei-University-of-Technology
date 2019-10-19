// SeqList.cpp: implementation of the SeqList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SeqList.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

template<class T>
SeqList<T>::SeqList()
{
	arraySize = swapTimes = compareTimes = 0;
	readDataFromFile();
}

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
	freopen( "x5.in", "r", stdin );
	ios::sync_with_stdio(false);
	HANDLE hOut; 
    //  获取输出流的句柄
    hOut = GetStdHandle(STD_OUTPUT_HANDLE); 
	srand( time(NULL) );
	Arr = new T[length];
	arraySize = swapTimes = compareTimes = 0;
	SetConsoleTextAttribute(hOut, 128 | 8 | 3 );
	cout << "Please enter the elements of the array sequence in turn:" << endl;
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
void SeqList<T>::readDataFromFile()
{
	ios::sync_with_stdio(false);
	HANDLE hOut; 
    //  获取输出流的句柄
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	char fileName[50];
	SetConsoleTextAttribute(hOut, 8 | 7 );
	cout << "Please input the name of the file:" << endl;
	cin >> fileName;

	freopen( fileName, "r", stdin );
	int _size = 1;
	Arr = (T*)malloc( sizeof(T) * _size );
	//arraySize ++;
	int length = 0, value;
	//while( scanf( "%d", &value ) != EOF )
	while( cin >> value )
	{
		Arr[arraySize] = value;
		//length ++;
		arraySize ++;
		//if( length >= _arraySize )
		//{
			//_size ++;
		T *Arr2 = (T*)realloc( Arr, sizeof(T) * 2 );
		if(Arr2)
		{
			Arr = Arr2;
		}
		//}
	}
	//cout << length;
	cout << _size << endl;
	/*
	Arr = new T[length];
	cout << length << endl;

	FILE *fp = fopen( fileName, "r" );
	int i = 0;
	//int j = 0;
	//for( i = 0; i)
	while( fscanf( fp, "%d", &Arr[i] ) != EOF )
	{
		i ++;
	}
	
	fclose(fp);
	*/
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
	int column = 0;
	for( int i = 0; i < arraySize; i ++ )
	{
	
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
	SetConsoleTextAttribute(hOut, 8 | 5 );
	cout << "Array length = " << arraySize << endl;
	cout << "Comparing times = " << compareTimes << endl;
	cout << "Swaping times = " << swapTimes << endl;
	//SetConsoleTextAttribute(hOut, 8 | 7 );
}

template<class T>
void SeqList<T>::judgeIncreasingSequence()
{
	bool flag = true;
	for( int i = 1; i < arraySize; i ++ )
	{
		if( Arr[i] >= Arr[ i - 1 ] )
		{
			continue;
		}
		else
		{
			!flag;
			cout << "Not increasing." << endl;
			cout << i - 1 << "-th --- " << Arr[ i - 1 ] << endl;
			cout << i << "-th ---- " << Arr[i] << endl;
			//return;
		}
	}
	if(!flag)
	{
		cout << "Completely increasing." << endl;
	}
	return;
}

template<class T>
void SeqList<T>::shellSort( int dh )
{
	while(dh)
	{
		for( int i = dh; i < arraySize; i ++ )
		{
			int tmp = Arr[i], j;
			for( j = i; j >= dh && Arr[ j - dh ] > tmp; j -= dh, compareTimes ++ )
			{
				Arr[j] = Arr[ j - dh ];
				swapTimes ++;
			}
			Arr[j] = tmp;
		}
		//dh /= 2;
		dh *= 0.618; //经过实践证明，“黄金分割比”确实能够达到最佳（小）的比较与交换次数
	}
}