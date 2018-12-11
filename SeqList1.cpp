// SeqList1.cpp: implementation of the SeqList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SeqList1.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SeqList::SeqList()
{
	listSize = 0;
}

SeqList::~SeqList()
{
	cout << this << " 顺序表已销毁！" << endl;
}

void SeqList::printList()
{
	if( isEmpty() )
	{
		cout << "顺序表为空！无法打印！" << endl;
	}
	int column = 0;
	for( int i = 0; i < listSize; i ++ )
	{
		cout<< setiosflags(ios::left) << setw(5) << Arr[i] << " ";
		if( ++ column % 10 == 0 )
			cout << endl;
	}
	cout << endl;
}

int SeqList::Length()
{
	return listSize;
}

int SeqList::locate( elementType value )
{
	for( int i = 0; i < listSize; i ++ )
		if( Arr[i] == value )
			return i + 1;
	return -1;
}

bool SeqList::isEmpty()
{
	return listSize == 0;
}

bool SeqList::isFull()
{
	return listSize == maxn;
}

bool SeqList::getElement( int pos, elementType& value )
{
	if( isEmpty() )
	{
		cout << "顺序表为空！查询失败！" << endl;
		return false;
	}
	if( pos > listSize )
	{
		cout << "查询位置超过当前顺序表容量！查询失败！" << endl;
		return false;
	}
	if( pos <= 0 )
	{
		cout << "查询位置必须大于0！查询失败！" << endl;
		return false;
	}
	value = Arr[pos];
	return true;
}

bool SeqList::insertList( int pos, elementType value )
{
	if( isFull() )
	{
		cout << "顺序表已满！插入失败！" << endl;
		return false;
	}
	if( pos > listSize )
	{
		cout << "插入位置超过当前顺序表容量！插入失败！" << endl;
		return false;
	}
	if( pos <= 0 )
	{
		cout << "插入位置必须大于0！插入失败！" << endl;
		return false;
	}
	for( int i = listSize - 1; i >= pos - 1; i -- )
		Arr[ i + 1 ] = Arr[i];
	Arr[ pos - 1 ] = value;
	listSize ++;//一定不能少！
	return true;//一定不能少！
}

bool SeqList::insertList_1( elementType value )
{
	if( isFull() )
	{
		cout << "顺序表已满！插入失败！" << endl;
		return false;
	}
	Arr[ listSize ++ ] = value;
	return true;//一定不能少！
}

bool SeqList::deleteListNode( int pos, elementType& value )
{
	if( isEmpty() )
	{
		cout << "顺序表为空！删除失败！" << endl;
		return false;
	}
	if( pos > listSize )
	{
		cout << "删除位置大于表长！删除失败！" << endl;
		return false;
	}
	if( pos <= 0 )
	{
		cout << "删除位置必须大于0！删除失败！" << endl;
		return false;
	}
	value = Arr[ pos - 1 ];
	//for( int i = pos; i < listSize - 1; i ++ )
	for( int i = pos; i < listSize; i ++ )
		Arr[ i - 1 ] = Arr[i];
	listSize --;//一定不能少！
	return true;//一定不能少！
}

bool SeqList::deleteListNode_1( int value )
{
	if( isEmpty() )
	{
		cout << "顺序表为空！删除失败！" << endl;
		return false;
	}
	if( locate(value) == -1 )
	{
		cout << "表中无此元素！删除失败！" << endl;
		return false;
	}
	int index = locate(value);
	for( int i = index - 1; i < listSize; i ++ )
		Arr[i] = Arr[ i + 1 ];
	listSize --;//一定不能少！否则会出现已失效的位置仍占有先前元素的错误！
	return true;//一定不能少！
	/*精简版如下！
	void delete(int A[],int key,int& n) 
	{ 
		int i,j; 
		for(i=0;i<n&&A[i]-key;i++); //查找key值元素 
		if(i>=n) 
			cout<<"not found"<<endl; 
		else
		{ 
			for(j=i;j<n-1;A[j]=A[j+1],j++);//若找到，将该元素后边的值向前覆盖 
			--n;//数组长度减1 
		} 
	}
	--------------------- 
	作者：castle_kao 
	来源：CSDN 
	原文：https://blog.csdn.net/castle_kao/article/details/53487610?utm_source=copy 
	版权声明：本文为博主原创文章，转载请附上博文链接！
	*/
}

bool SeqList::deleteListNode_2( int value )
{
	if( isEmpty() )
	{
		cout << "顺序表为空！删除失败！" << endl;
		return false;
	}
	if( locate(value) == -1 )
	{
		cout << "表中无此元素！删除失败！" << endl;
		return false;
	}
	int cnt = 0;
	for( int i = 0; i < listSize; i ++ )
		if( Arr[i] == value )
			cnt ++;
	while( cnt -- )
	{
		int pos = locate(value), data;
		deleteListNode( pos, data );
	}
	return true;
}

bool SeqList::incInsert( int value )
{
	if( isFull() )
	{
		cout << "顺序表已满！插入失败！" << endl;
		return false;
	}
	int index = -1;
	if( value <= Arr[0] )
	{
		for( int k = listSize; k>= 0; k -- )
			Arr[ k + 1 ] = Arr[k];
		Arr[0] = value;
		listSize ++;
		return true;
	}
	else if( value > Arr[0] && value < Arr[ listSize - 1 ] )
	{
		for( int i = 0; i < listSize; i ++ )
		{
			if( Arr[i] >= value )
			{
				index = i;
				break;
			}
			else
				continue;
		}
	
		for( int j = listSize; j >= index; j -- )
		{
			Arr[ j + 1 ] = Arr[j];
		}
		Arr[index] = value;
		listSize ++;
		return true;
	}
	else
	{
		Arr[listSize] = value;
		listSize ++;
		return true;
	}
}

bool SeqList::oddEvenSort( SeqList& LA, SeqList& LB )//奇数偶数分类
{
	if( isFull() )
	{
		cout << "原顺序表已满！插入失败！" << endl;
		return false;
	}
	for( int i = 0; i < listSize; i ++ )
	{
		if( Arr[i] & 1 )
			LA.insertList_1( Arr[i] );
		else
			LB.insertList_1( Arr[i] );
	}
	return true;
}

bool SeqList::intersectionSet( SeqList& LA, SeqList& LB, SeqList& LC )
{
	int ia, ib;
	if( LA.isEmpty() || LB.isEmpty() )
	{
		cout << "至少有一个顺序表为空！插入失败！" << endl;
		return false;
	}
	for( ia = 0, ib = 0; ia < LA.listSize, ib < LB.listSize; )
	{
		if( ia == LA.listSize - 1 || ib == LB.listSize - 1 )
			//break;
			return true;
		if( LA.Arr[ia] == LB.Arr[ib] )
		{
			LC.insertList_1( LB.Arr[ib] );
			ia ++;
			ib ++;
		}
		else if( LA.Arr[ia] < LB.Arr[ib] )
		{
			ia ++;
			continue;
		}
		else 
		{
			ib ++;
			continue;
		}
	}
	return true;
}

bool SeqList::delRepeatedNode()
{	
	if( isEmpty() )
	{
		cout << "顺序表为空！插入失败！" << endl;
		return false;
	}
	int x;
	for( int i = 0; i < listSize - 1; i ++ )
	{
		for( int j = i + 1; j < listSize; j ++ )
			if( Arr[i] == Arr[j] )
			{
				//for( int k = j; k < listSize - 1; k ++ )
					//Arr[k] = Arr[ k + 1 ];
				//listSize --;
				//deleteListNode( j, x );
				deleteListNode_1( Arr[i] );
				j --;//我花了一个小时来加这句话！
			}
		//i --;
	}
	return true;
}

bool SeqList::delRepeatedNode_2()
{
	if( isEmpty() )
	{
		cout << "顺序表为空！去重失败！" << endl;
		return false;
	}
	int i, j = 0, k;
	for( i = 1; i < listSize; i ++ )
    {
		k = 0;
	    while( ( k <= j ) && ( Arr[i] != Arr[k] ) )
	    {
			k ++;
	    }
	    if( k > j )
	    {
			j ++;
            Arr[j] = Arr[i];
	    }
	}
	listSize = j + 1;/*(1)、i 控制待处理区域，j  控制无重复区域。
(2)、k 用于遍历无重复区域与 i 中的元素进行对比，若没有重复就将当前 i 
	所指单元加入 j 控制的无重复区域中，无重复区域长度+1。*/
	return true;
}

bool SeqList::unionSet( SeqList& LA, SeqList& LB )
{
	if( LA.isEmpty() || LB.isEmpty() )
	{
		cout << "至少有一个顺序表为空！插入失败！" << endl;
		return false;
	}
	int i = 0, j = 0;
	while( i < LA.listSize && j < LB.listSize )
	{
		if( LA.Arr[i] == LB.Arr[j] )
		{
			i ++;
			j ++;
		}
		else if( LA.Arr[i] < LB.Arr[j] )
		{
			LA.insertList_1( LB.Arr[j] );
			i ++;
		}
		else if( LA.Arr[i] > LB.Arr[j] )
		{
			LA.insertList_1( LB.Arr[j] );
			j ++;
		}
	}
	while( j <  LB.listSize )
	{
		LA.insertList_1( LB.Arr[j] );
		j ++;
	}
	return true;
}

bool SeqList::unionSet( SeqList& LA, SeqList& LB, SeqList& LC )
{
	if( LA.isEmpty() || LB.isEmpty() )
	{
		cout << "至少有一个顺序表为空！插入失败！" << endl;
		return false;
	}
	int i = 0, j = 0;
	while( i < LA.listSize && j < LB.listSize )
	{
		if( LA.Arr[i] == LB.Arr[j] )
		{
			LC.insertList_1( LA.Arr[i] );
			//LC.insertList_1( LB.Arr[j] );
			i ++;
			j ++;
		}
		else if( LA.Arr[i] < LB.Arr[j] )
		{
			LC.insertList_1( LA.Arr[j] );
			i ++;
		}
		if( LA.Arr[i] > LB.Arr[j] )
		{
			LC.insertList_1( LB.Arr[j] );
			j ++;
		}
	}
	while( i <  LA.listSize )
	{
		LC.insertList_1( LA.Arr[i] );
		i ++;
	}
	while( j <  LB.listSize )
	{
		LC.insertList_1( LB.Arr[j] );
		j ++;
	}
	return true;
}

bool SeqList::subTractSet( SeqList& LA, SeqList& LB, SeqList& LC )
{
	if( LA.isEmpty() || LB.isEmpty() )
	{
		cout << "至少有一个顺序表为空！插入失败！" << endl;
		return false;
	}
	for( int i = 0; i < LA.listSize; i ++ ) 
	{ 
		int j = 0; 
		while( j < LB.listSize && LB.Arr[j] != LA.Arr[i] ) 
			j ++; 
		if( j == LB.listSize ) //表示A->data[i]不在B中，将其放到C中 
			//C->data[ k++]=A->data[i];
			LC.insertList_1( LA.Arr[i] );
	}
	return true;
}

bool SeqList::intersectionSet( SeqList& LA, SeqList& LB )
{
	if( LA.isEmpty() || LB.isEmpty() )
	{
		cout << "至少有一个顺序表为空！插入失败！" << endl;
		return false;
	}
	int i = 0, j = 0;
	while( i < LA.listSize && j < LB.listSize )
	{
		if( LA.Arr[i] == LB.Arr[j] )
		{
			i ++;
			j ++;
		}
		else if( LA.Arr[i] < LB.Arr[j] )
		{
			i ++;
		}
		else
		{
			//LA.deleteListNode_1( LA.Arr[i] );
			j ++;
		}
	}
	LA.listSize = i;
	
	return true;
}

bool SeqList::subTractSet( SeqList& LA, SeqList& LB )
{
	if( LA.isEmpty() || LB.isEmpty() )
	{
		cout << "至少有一个顺序表为空！插入失败！" << endl;
		return false;
	}
	int i = 0, j = 0;
	while( i < LA.listSize && j < LB.listSize )
	{
		if( LA.Arr[i] == LB.Arr[j] )
		{
			LA.deleteListNode_1( LA.Arr[i] );
			i ++;
			j ++;
		}
		else if( LA.Arr[i] < LB.Arr[j] )
		{
			i ++;
		}
		else
		{
			j ++;
		}
	}
	return true;
}

bool SeqList::subSet( SeqList& LA, SeqList& LB )
{
	int i = 0, j = 0;
	while( i < LA.listSize && j < LB.listSize )
	{
		if( LA.Arr[i] == LB.Arr[j] )
		{
			i ++;
			j ++;
		}
		else if( LA.Arr[i] > LB.Arr[j] )
		{
			j ++;
		}
		else
		{
			return false;	
		}
	}
	if( i >= LA.listSize )
		return true;
	else
		return false;
	
}

int SeqList::midSearch( SeqList& LA, SeqList& LB )
{
	int start1 = 0, end1 = LA.listSize - 1, m1, start2 = 0, end2 = LB.listSize - 1, m2;
	//分别表示序列A和B的首位数、末位数和中位数
 
	while( start1 != end1 || start2 != end2 )
	{
		m1 = (start1 + end1) / 2;
		m2 = (start2 + end2) / 2;
		if ( LA.Arr[m1] == LB.Arr[m2] )
			return LA.Arr[m1];   //满足条件 1)
 
		if( LA.Arr[m1] < LB.Arr[m2] ) // 满足条件 2)
		{  
			if(  (start1 + end1 ) % 2 == 0 )  //若元素个数为奇数
			{  
				start1 = m1;  //舍弃A中间点以前的部分且保留中间点
				end2 = m2;  //舍弃B中间点以后的部分且保留中间点
			}
			else				//元素个数为偶数
			{ 
				start1 = m1 + 1;  //舍弃A中间点及中间点以前部分
				end2 = m2;  //舍弃B中间点以后部分且保留中间点
			}
		}
		else
		{  //满足条件3)
			if( ( start2 + end2 ) % 2 == 0 )   //若元素个数为奇数
			{ 
				end1 = m1;    //舍弃A中间点以后的部分且保留中间点
				start2 = m2;    //舍弃B中间点以前的部分且保留中间点
			}
			else     //元素个数为偶数
			{  
				end1 = m1;    //舍弃A中间点以后部分且保留中间点
				start2 = m2 + 1;    //舍弃B中间点及中间点以前部分
			}
		}
	}
	return  LA.Arr[start2] < LB.Arr[start2] ? LA.Arr[start1] : LB.Arr[start2];
}

/*
最后这个问题我不懂，上网查了之后明白。先将网上的解析与出处粘贴在此：
这里涉及到数据结构中顺序表的实现、删除、插入、查找等知识，请查看：数据结构 -> 线性表
问题描述：

一个长度为L (L>=1)的升序序列S，处在第[L/2]个位置的数称为S的中位数。例如，若序列S1=(11, 13, 15, 17, 19)，则S1的中位数是15，两个序列的中位数是含它们所有元素的升序序列的中位数。例如，若S2= (2, 4，6，8, 20)，则S1和S2的中位数是11。现在有两个等长升序序列A和B，试设计一个在时间和空间两方面都尽可能高效的算法，找出两个序列A和B的中位数。要求：
1) 给出算法的基本设计思想。
2) 根据设计思想，釆用C或C++或Java语言描述算法，关键之处给出注释。
3) 说明你所设计算法的时间复杂度和空间复杂度。

该题为2011年研究生考试计算机联考真题。
问题解答：

(1)算法的基本设计思想如下：

分别求两个升序序列A、B的中位数，设为a和b,求序列A、B的中位数过程如下：

1) 若a=b，则a或b即为所求中位数，算法结束。

2) 若a<b，则舍弃序列A中较小的一半，同时舍弃序列B中较大的一半，要求两次舍弃的长度相等。

3) 若a>b，则舍弃序列A中较大的一半，同时舍弃序列B中较小的一半，要求两次舍弃的长度相等。

(2)算法实现如上

在保留的两个升序序列中，重复过程1)、2)、3)，直到两个序列中均只含一个元素时为止，较小者即为所求的中位数。
(3)算法的时间复杂度为O(log2n)，空间复杂度为O(1)。
--------------------- 
作者：mishidemudong 
来源：CSDN 
原文：https://blog.csdn.net/u010159842/article/details/47037487?utm_source=copy 
版权声明：本文为博主原创文章，转载请附上博文链接！
*/