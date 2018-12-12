// BinarySearchTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BSTree.h"

//这是EasyX的官方网站： https://www.easyx.cn/

void test1()
{
	HANDLE hOut; 
 
    //  获取输出流的句柄
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	BSTree BST1;
	elementType value;
	vector<elementType>VI;
	while( cin >> value )
	{
		if( (char)value == '#' && value != 35/*-999*/ ) //细节处理：一定要加 && value != 35，因为 # 的ASCII码是35，
		{												//不加的话在输入数字“35”而不是“#”时循环也会终止
			break;
		}
		else
		{
			VI.push_back(value);
		}
		
	}
	BST1.createBinarySearchTree( BST1.getRootNode(), VI );

	SetConsoleTextAttribute(hOut, 
                            FOREGROUND_RED | // 前景色_红色
                            FOREGROUND_BLUE |// 前景色_蓝色
                            FOREGROUND_INTENSITY);// 加强

	cout << "PreOrder:" << endl;
	BST1.preOrderTraversal( BST1.getRootNode() );
	cout << endl;
	cout << "InOrder:" << endl;
	BST1.inOrderTraversal( BST1.getRootNode() );
	cout << endl;
	cout << "PostOrder:" << endl;
	BST1.postOrderTraversal( BST1.getRootNode() );
	cout << endl;
	
	SetConsoleTextAttribute(hOut, 
                            FOREGROUND_RED |   // 前景色_红色
                            FOREGROUND_GREEN | // 前景色_绿色
                            FOREGROUND_BLUE ); // 前景色_蓝色

	return;
}

void test2()
{
	HANDLE hOut; 
 
    //  获取输出流的句柄
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);  

	BSTree BST1;
	elementType value;
	vector<elementType>VI;
	
	while( cin >> value )
	{
		if( (char)value == '#' && value != 35/*-999*/ ) //细节处理：一定要加 && value != 35，因为 # 的ASCII码是35，
		{												//不加的话在输入数字“35”而不是“#”时循环也会终止
			break;
		}
		else
		{
			VI.push_back(value);
		}
		
	}
	
	BST1.createBinarySearchTree( BST1.getRootNode(), VI );

	_BSTree index = NULL;	

	SetConsoleTextAttribute(hOut, 
                            FOREGROUND_RED | // 前景色_红色
                            FOREGROUND_BLUE |// 前景色_蓝色
                            FOREGROUND_INTENSITY);// 加强
                           
	cout << "PreOrder:" << endl;

	BST1.preOrderTraversal( BST1.getRootNode() );
	cout << endl;
	cout << "InOrder:" << endl;
	BST1.inOrderTraversal( BST1.getRootNode() );
	cout << endl;
	cout << "PostOrder:" << endl;
	BST1.postOrderTraversal( BST1.getRootNode() );
	cout << endl;

	
	
	//elementType key = ;// = 545;
	//下面这句话不会运行
	//cin >> key;
	
	elementType Arr[] = { 150, 70, 160, 190, 10, 55, 175 };

	for( int j = 0; j < sizeof(Arr) / sizeof(elementType); j ++ )
	{
		if( BST1.search( BST1.getRootNode(), Arr[j], index ) )
		{
			SetConsoleTextAttribute(hOut, 
                            FOREGROUND_BLUE |      // 前景色_蓝色
                            FOREGROUND_INTENSITY ); // 前景色_加强
			cout << Arr[j] << " is in the binary search tree." << endl;
			SetConsoleTextAttribute(hOut, 
                            FOREGROUND_RED |   // 前景色_红色
                            FOREGROUND_GREEN | // 前景色_绿色
                            FOREGROUND_BLUE ); // 前景色_蓝色
		}
		else
		{
			SetConsoleTextAttribute(hOut, 
                            FOREGROUND_RED |       // 前景色_红色
                            FOREGROUND_INTENSITY ); // 前景色_加强
			cout << Arr[j] << " is not in the binary search tree." << endl;
			SetConsoleTextAttribute(hOut, 
                            FOREGROUND_RED |   // 前景色_红色
                            FOREGROUND_GREEN | // 前景色_绿色
                            FOREGROUND_BLUE ); // 前景色_蓝色
		}
	}
	
	//无法实现下面这样输入数值判断其是否存在
	/*
	BSTNode *father = NULL, *target = NULL;
	
	elementType key;
	while( cin >> key )
	{
		//target = NULL;
		if( (char)key == '#' && key != 35 ) 
		{												
			break;
		}
		else
			target = BST1.search( BST1.getRootNode(), key, father );
		
		if(!target)
		{
			cout << "No!" << endl;
		}
		else
		{
			cout << "Yes!" << endl;
		}
		
	}
	*/	

	return;
}

void test3()
{
	HANDLE hOut; 
 
    //  获取输出流的句柄
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);  

	BSTree BST1;
	elementType value;
	vector<elementType>VI;
	
	while( cin >> value )
	{
		if( (char)value == '#' && value != 35/*-999*/ ) //细节处理：一定要加 && value != 35，因为 # 的ASCII码是35，
		{												//不加的话在输入数字“35”而不是“#”时循环也会终止
			break;
		}
		else
		{
			VI.push_back(value);
		}
		
	}
	
	BST1.createBinarySearchTree( BST1.getRootNode(), VI );

	_BSTree index = NULL;	

	SetConsoleTextAttribute(hOut, 
                            FOREGROUND_BLUE |      // 前景色_蓝色
                            FOREGROUND_INTENSITY ); // 前景色_加强
	cout << "The origin binary search tree is as follow:" << endl;
    SetConsoleTextAttribute(hOut, 
                            FOREGROUND_RED | // 前景色_红色
                            FOREGROUND_BLUE |// 前景色_蓝色
                            FOREGROUND_INTENSITY);// 加强

	cout << "PreOrder:" << endl;

	BST1.preOrderTraversal( BST1.getRootNode() );
	cout << endl;
	cout << "InOrder:" << endl;
	BST1.inOrderTraversal( BST1.getRootNode() );
	cout << endl;
	cout << "PostOrder:" << endl;
	BST1.postOrderTraversal( BST1.getRootNode() );

	cout << endl;

	

	elementType Arr[] = { 30, 150, 100 };
	for( int i = 0; i < sizeof(Arr) / sizeof(elementType); i ++ )
	{	
		_BSTree index = BST1.getRootNode();
		//BST1.deleteNode1( index, Arr[i] );
		BST1.deleteNode2( index, Arr[i] );
		SetConsoleTextAttribute(hOut, 
                            FOREGROUND_BLUE |      // 前景色_蓝色
                            FOREGROUND_INTENSITY ); // 前景色_加强
		cout << "After deleting node " << Arr[i] << ", the current binary search tree is as follow:"<< endl;

		SetConsoleTextAttribute(hOut, 
                            FOREGROUND_RED | // 前景色_红色
                            FOREGROUND_BLUE |// 前景色_蓝色
                            FOREGROUND_INTENSITY);// 加强

		cout << "PreOrder:" << endl;

		BST1.preOrderTraversal( BST1.getRootNode() );
		cout << endl;
		cout << "InOrder:" << endl;
		BST1.inOrderTraversal( BST1.getRootNode() );
		cout << endl;
		cout << "PostOrder:" << endl;
		BST1.postOrderTraversal( BST1.getRootNode() );
		cout << endl;

	}
	SetConsoleTextAttribute(hOut, 
                            FOREGROUND_RED |   // 前景色_红色
                            FOREGROUND_GREEN | // 前景色_绿色
                            FOREGROUND_BLUE ); // 前景色_蓝色
	return;
}


int main(int argc, char* argv[])
{
	//test1();
	//test2();
	test3();
	return 0;
}
