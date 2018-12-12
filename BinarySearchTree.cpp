// BinarySearchTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BSTree.h"

//����EasyX�Ĺٷ���վ�� https://www.easyx.cn/

void test1()
{
	HANDLE hOut; 
 
    //  ��ȡ������ľ��
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	BSTree BST1;
	elementType value;
	vector<elementType>VI;
	while( cin >> value )
	{
		if( (char)value == '#' && value != 35/*-999*/ ) //ϸ�ڴ���һ��Ҫ�� && value != 35����Ϊ # ��ASCII����35��
		{												//���ӵĻ����������֡�35�������ǡ�#��ʱѭ��Ҳ����ֹ
			break;
		}
		else
		{
			VI.push_back(value);
		}
		
	}
	BST1.createBinarySearchTree( BST1.getRootNode(), VI );

	SetConsoleTextAttribute(hOut, 
                            FOREGROUND_RED | // ǰ��ɫ_��ɫ
                            FOREGROUND_BLUE |// ǰ��ɫ_��ɫ
                            FOREGROUND_INTENSITY);// ��ǿ

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
                            FOREGROUND_RED |   // ǰ��ɫ_��ɫ
                            FOREGROUND_GREEN | // ǰ��ɫ_��ɫ
                            FOREGROUND_BLUE ); // ǰ��ɫ_��ɫ

	return;
}

void test2()
{
	HANDLE hOut; 
 
    //  ��ȡ������ľ��
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);  

	BSTree BST1;
	elementType value;
	vector<elementType>VI;
	
	while( cin >> value )
	{
		if( (char)value == '#' && value != 35/*-999*/ ) //ϸ�ڴ���һ��Ҫ�� && value != 35����Ϊ # ��ASCII����35��
		{												//���ӵĻ����������֡�35�������ǡ�#��ʱѭ��Ҳ����ֹ
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
                            FOREGROUND_RED | // ǰ��ɫ_��ɫ
                            FOREGROUND_BLUE |// ǰ��ɫ_��ɫ
                            FOREGROUND_INTENSITY);// ��ǿ
                           
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
	//������仰��������
	//cin >> key;
	
	elementType Arr[] = { 150, 70, 160, 190, 10, 55, 175 };

	for( int j = 0; j < sizeof(Arr) / sizeof(elementType); j ++ )
	{
		if( BST1.search( BST1.getRootNode(), Arr[j], index ) )
		{
			SetConsoleTextAttribute(hOut, 
                            FOREGROUND_BLUE |      // ǰ��ɫ_��ɫ
                            FOREGROUND_INTENSITY ); // ǰ��ɫ_��ǿ
			cout << Arr[j] << " is in the binary search tree." << endl;
			SetConsoleTextAttribute(hOut, 
                            FOREGROUND_RED |   // ǰ��ɫ_��ɫ
                            FOREGROUND_GREEN | // ǰ��ɫ_��ɫ
                            FOREGROUND_BLUE ); // ǰ��ɫ_��ɫ
		}
		else
		{
			SetConsoleTextAttribute(hOut, 
                            FOREGROUND_RED |       // ǰ��ɫ_��ɫ
                            FOREGROUND_INTENSITY ); // ǰ��ɫ_��ǿ
			cout << Arr[j] << " is not in the binary search tree." << endl;
			SetConsoleTextAttribute(hOut, 
                            FOREGROUND_RED |   // ǰ��ɫ_��ɫ
                            FOREGROUND_GREEN | // ǰ��ɫ_��ɫ
                            FOREGROUND_BLUE ); // ǰ��ɫ_��ɫ
		}
	}
	
	//�޷�ʵ����������������ֵ�ж����Ƿ����
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
 
    //  ��ȡ������ľ��
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);  

	BSTree BST1;
	elementType value;
	vector<elementType>VI;
	
	while( cin >> value )
	{
		if( (char)value == '#' && value != 35/*-999*/ ) //ϸ�ڴ���һ��Ҫ�� && value != 35����Ϊ # ��ASCII����35��
		{												//���ӵĻ����������֡�35�������ǡ�#��ʱѭ��Ҳ����ֹ
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
                            FOREGROUND_BLUE |      // ǰ��ɫ_��ɫ
                            FOREGROUND_INTENSITY ); // ǰ��ɫ_��ǿ
	cout << "The origin binary search tree is as follow:" << endl;
    SetConsoleTextAttribute(hOut, 
                            FOREGROUND_RED | // ǰ��ɫ_��ɫ
                            FOREGROUND_BLUE |// ǰ��ɫ_��ɫ
                            FOREGROUND_INTENSITY);// ��ǿ

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
                            FOREGROUND_BLUE |      // ǰ��ɫ_��ɫ
                            FOREGROUND_INTENSITY ); // ǰ��ɫ_��ǿ
		cout << "After deleting node " << Arr[i] << ", the current binary search tree is as follow:"<< endl;

		SetConsoleTextAttribute(hOut, 
                            FOREGROUND_RED | // ǰ��ɫ_��ɫ
                            FOREGROUND_BLUE |// ǰ��ɫ_��ɫ
                            FOREGROUND_INTENSITY);// ��ǿ

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
                            FOREGROUND_RED |   // ǰ��ɫ_��ɫ
                            FOREGROUND_GREEN | // ǰ��ɫ_��ɫ
                            FOREGROUND_BLUE ); // ǰ��ɫ_��ɫ
	return;
}


int main(int argc, char* argv[])
{
	//test1();
	//test2();
	test3();
	return 0;
}
