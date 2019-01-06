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
			!flag;
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
void SeqList<T>::fixUpTree( Rec *tree, int pos )
{
	int i = pos;
	if ( i  %  2 )   //i位于右子树  
		tree[ ( i - 1 ) / 2 ] = tree[ i + 1 ];   //左孩子上升到父节点   
	else
		tree[ ( i - 1 ) / 2 ] = tree[ i - 1 ];   //右孩子上升到父节点   
	i = ( i - 1 ) / 2;
	int j;
	while (i)     //上升到根节点，则终止循环   
	{
		i % 2 ? j = i + 1 : j = i - 1;     //确定i的兄弟j的下标   
		if ( !tree[i].active || !tree[j].active )  //左右孩子有一个为空   
		{
			if ( tree[i].active )
				tree[ (i - 1) / 2 ] = tree[i];
			else
				tree[ (i - 1) / 2 ] = tree[j];
		}
		else  //左右孩子都不为空   
		{
			if ( tree[i].data <= tree[j].data )
				tree[ ( i - 1 ) / 2 ] = tree[i];
			else
				tree[ ( i - 1 ) / 2 ] = tree[j];
		}
		i = ( i - 1 ) / 2;   //回到上一层   
	}
}

template<class T>
void SeqList<T>::treeSelectSort( T a[], int n )
{
	int i = 0;
	while ( pow( double(2), i ) < n )
		i ++;
	int leaf = pow( 2, i );   //完全二叉树叶子节点个数   
	int size = 2 * leaf - 1;   //树节点总数  提示3  
	Rec *tree = new Rec[size];  //顺序存储一棵树   
	for ( i = 0; i < leaf; i ++ )
	{
		if (i < n )
		{
			//leaf-1是叶子节点的起始下标
			tree[ i + leaf - 1 ].data = a[i];
			tree[ i + leaf - 1 ].index = i;
			tree[ i + leaf - 1 ].active = true;
		}
		else//叶子节点下标从 leaf-1+n开始，后面都是空的，无此参赛者  
			tree[ i + leaf - 1 ].active = false;    
	}
	i = leaf - 1;    //提示3  
	int j;
	while (i)   //上升到根节点，则终止循环   
	{
		j = i;
		while ( j < 2 * i )   //下面的提示4  
		{
			//无右节点或右节点已出局，即使存在右节点，其值域也比左节点大  
			if ( ! tree[j + 1].active || tree[j + 1].data > tree[j].data )  
				tree[ ( j - 1 ) / 2 ] = tree[j];
			else
				tree[ ( j - 1 ) / 2 ] = tree[j + 1];
			j += 2;     //两两比较   
		}
		i = ( i - 1 ) / 2;  //回到上一层    
	}
	i = 0;
	while ( i < n - 1 ) //确定剩下的n-1个节点的次序   
	{
		a[i] = tree[0].data;
		tree[ leaf - 1 + tree[0].index ].active = false; //出局，不参与下一轮
		//每次出局后都需调整
		fixUpTree( tree, leaf - 1 + tree[0].index );
		i ++;
	}
	a[ n - 1 ] = tree[0].data;  //最后一个归位   
	delete []tree;
}