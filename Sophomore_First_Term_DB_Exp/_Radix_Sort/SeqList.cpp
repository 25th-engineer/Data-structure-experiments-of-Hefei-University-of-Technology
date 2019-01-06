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
	//freopen( "x2.in", "r", stdin );
	ios::sync_with_stdio(false);
	HANDLE hOut; 
    //  获取输出流的句柄
    hOut = GetStdHandle(STD_OUTPUT_HANDLE); 
	srand( time(NULL) );
	Arr = new T[length];
	arraySize = swapTimes = compareTimes = 0;
	SetConsoleTextAttribute(hOut, 128 | 8 | 3 );

	///----------------------
	
	//int str[] = {106,213,325,446,579,654,721,870,917,510,21,632,73,14,815,316,412,18,619,720,21,808,923,25,26};

	///----------------------

	cout << "Please enter the elements of the array sequence in turn:" << endl;

	//memcpy( Arr, str, 24 );

	for( int i = 0; i < length; i ++ )
	{
		cin >> Arr[i];
		arraySize ++;
	}
}
template<class T>
T *SeqList<T>::getArray()
{
	return Arr;
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
			flag = false;
			cout << "Not increasing." << endl;
			cout << i - 1 << "-th --- " << Arr[ i - 1 ] << endl;
			cout << i << "-th ---- " << Arr[i] << endl;
			//return;
		}
	}
	//cout << flag << endl;
	if(flag)
	{
		cout << "Completely increasing." << endl;
	}
	return;
}

template<class T>
void SeqList<T>::countSort( int p )
{
	T *output = new T[arraySize];
	int count[10];
	memset( count, 0, sizeof(count) );//keeping count if digits <=9

	for( int i = 0; i < arraySize; i ++ )
	{
		count[ ( Arr[i] / p ) % 10 ] ++;
	}

	//Applying counting sort so now the array contains actual position of the digits
	for( int j = 1; j < 10; j ++ )
	{
		count[j] += count[ j - 1 ]; 
	}
	
	//staring from N-1 helps to keep digits in order
	for( int k = arraySize - 1; k >= 0; k -- )
	{
		output[ count[ ( Arr[k] / p ) % 10 ] - 1 ] = Arr[k];
		count[ ( Arr[k] / p ) % 10 ] --;
	}

	for( int i1 = 0; i1 < arraySize; i1 ++ )
	{
		Arr[i1] = output[i1];
	}
}

template<class T>
void SeqList<T>::radixSort()
{
	T maxIndex = max( Arr[0], Arr[ arraySize - 1 ] );

	int p = 1, pass = 1;

	while( maxIndex / p )
	{
		countSort(p);
		cout << "After pass " << pass << "  : " ;
		display();
		pass ++;
		p *= 10;
	}
}