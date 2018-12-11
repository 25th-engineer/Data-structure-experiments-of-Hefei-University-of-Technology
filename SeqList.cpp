// SeqList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SeqList1.h"

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false);
	//freopen( "x1.in", "r", stdin );
	freopen( "7_3.in", "r", stdin );

	int n;
	/*
	SeqList L1;
	if( L1.isEmpty() )
	{
		cout << "空表！" << endl;
	}
	cin >> n;
	for( int i = 0; i < n; i ++ )
	{
		int num;
		cin >> num;
		L1.insertList_1(num);
	}
	cout << "原顺序表：" << endl;
	L1.printList();
	int t1, t2, t3, t4, t5;//5,n,1,n+1,0 
	L1.deleteListNode( 5, t1 );
	L1.printList();

	

	//freopen( "x1.out", "w", stdout );
	//printf( "%d\n", (bool)-1 );
	SeqList L1;
	if( L1.isEmpty() )
	{
		cout << "空表！" << endl;
	}
	
	cin >> n;
	for( int i = 0; i < n; i ++ )
	{
		int num;
		cin >> num;
		L1.insertList_1(num);
	}	
	cout << "当前表长为：" << L1.Length() << endl;
	L1.printList();
	L1.insertList( 5, -1 );
	cout << "当前表长为：" << L1.Length() << endl;
	L1.printList();
	int data;
	L1.deleteListNode( 4, data );
	cout << "值为 " << data << " 的元素已删除！" << endl;
	

	L1.deleteListNode_1(6);
	cout << L1.Length() << endl;
	L1.printList();

	L1.deleteListNode_1(7);
	cout << "当前表长为：" << L1.Length() << endl;
	L1.printList();

	int delKey = 2;
	L1.deleteListNode_2(delKey);
	cout << "所有值为" << delKey << "元素删除后，" << "当前表长为：" << L1.Length() << endl;
	L1.printList();
	
	SeqList L2;
	if( L2.isEmpty() )
	{
		cout << "空表！" << endl;
	}
	for( int j = 0; j < maxn; j ++ )
	{
		L2.insertList_1( j + 1 );
	}
	if( L2.isFull() )
	{
		cout << "表满！" << endl;
	}
	cout << "当前表长为：" << L2.Length() << endl;
	L2.printList();//改为	L1.printList();  会有意想不到的效果！
	
	
	SeqList L3;
	cin >> n;
	for( int k = 0; k < n; k ++ )
	{
		int num;
		cin >> num;
		L3.insertList_1(num);
	}	
	cout << "原顺序表：" << endl;
	L3.printList();
	L3.incInsert(25);//25，85，110和8
	L3.printList();
	L3.incInsert(85);
	L3.printList();
	L3.incInsert(110);
	L3.printList();
	L3.incInsert(8);
	L3.printList();
	*/

	/*
	SeqList L4, LA, LB;
	cin >> n;
	for( int k1 = 0; k1 < n; k1 ++ )
	{
		int num;
		cin >> num;
		L4.insertList_1(num);
	}	
	L4.printList();
	L4.oddEvenSort( LA, LB );
	LA.printList();
	LB.printList();
	
	
	SeqList L5, L6, LTmp;
	int m;
	cin >> n;
	for( int i1 = 0; i1 < n; i1 ++ )
	{
		int num;
		cin >> num;
		L5.insertList_1(num);
	}

	cin >> m;
	for( int i2 = 0; i2 < m; i2 ++ )
	{
		int num1;
		cin >> num1;
		L6.insertList_1(num1);
	}
	LTmp.intersectionSet( L5, L6, LTmp );
	L5.printList();
	L6.printList();
	LTmp.printList();
	*/
	
	cin >> n;
	SeqList L7, L7_1;
	for( int j2 = 0; j2 < n; j2 ++ )
	{
		int num2;
		cin >> num2;
		L7.insertList_1(num2);
		L7_1.insertList_1(num2);
	}
	cout << "原顺序表：" << endl;
	L7.printList();
	cout << "法1去重后，顺序表：" << endl;
	L7.delRepeatedNode();
	L7.printList();
	cout << "原顺序表：" << endl;
	L7_1.printList();
	L7_1.delRepeatedNode_2();
	cout << "法2去重后，顺序表：" << endl;
	L7_1.printList();
	/*
	SeqList L8, L9, L10;
	int m;
	cin >> n;
	for( int i3 = 0; i3 < n; i3 ++ )
	{
		int num3;
		cin >> num3;
		L8.insertList_1(num3);
	}
	cin >> m;
	for( int i4 = 0; i4 < m; i4 ++ )
	{
		int num4;
		cin >> num4;
		L9.insertList_1(num4);
	}
	L8.printList();
	L9.printList();
	//L8.unionSet( L8, L9, L10 );
	//L8.subTractSet( L8, L9, L10 );
	if( L8.subSet( L8, L9 ) )
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	L8.printList();
	cout << L8.Length() << endl;
	//L10.printList();
	//cout << L10.Length() << endl;
	
	SeqList L11, L12;
	int m;
	cin >> n;
	for( int j4 = 0; j4 < n; j4 ++ )
	{
		int num5;
		cin >> num5;
		L11.insertList_1(num5);
	}
	cin >> m;
	for( int j5 = 0; j5 < m; j5 ++ )
	{
		int num6;
		cin >> num6;
		L12.insertList_1(num6);
	}
	cout << L11.midSearch( L11, L12 ) << endl;
	*/
	return 0;
}
