/*************************************************************************
	> File Name: _linkedList.cpp
	> Author: Xef Utah刁肥宅
	> Mail: u25th_engineer@163.com 
	> Created Time: 2019年01月03日 星期四 11时36分13秒
 ************************************************************************/

#include "stdafx.h"
#include "linkedList1.h"
#include "linkedList1.cpp"
 

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false);
	freopen( "1.in", "r", stdin );
	
	linkedList L1;//, L2;	
	int n;
	cin >> n;
	L1.createLinkedListFront(n);
	cout << "原表表长为：" << endl;
	cout << L1.linkedListLength() << endl;
	cout << "原表元素为：" << endl;
	L1.printLinkedList();
	return 0;
}
