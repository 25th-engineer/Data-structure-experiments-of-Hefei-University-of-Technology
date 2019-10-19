// BinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "_Binary_Tree.h"
#include "charLinkedQueue.h"


void test1()
{
	_Binary_Tree BT1;
	elementType strLine[100][3];
	int nRow = 0, nLen = 0;
	binTree index;
	BT1.readFileToArray(strLine,nLen);
	//BT1._Binary_Tree();
	
	BT1.createBinaryTree( index,strLine, nLen, nRow);
	
	cout << "The preorder traversal of sequence is" << endl;
	BT1.preOrderTraverse(BT1.getNodePoint());
	cout << endl;
	cout << "The middle order traversal of sequence is" << endl;
	BT1.inOrderTraverse(BT1.getNodePoint()); 
	cout << endl;
	cout << "The post order traversal of sequence is" << endl;
	BT1.postOrderTraverse(BT1.getNodePoint()); 
	cout << endl;
	cout << "The level order traversal of sequence is" << endl;
	BT1.levelOrderTraverse( BT1.getNodePoint() );
	cout << endl;
	int n = 1;
	BT1.level( BT1.getNodePoint() , n );
	cout << "BTree height: "<< BT1.height( BT1.getNodePoint() ) << endl;
	cout << "Total node: " << BT1.numberOfBTreeNode( BT1.getNodePoint() ) << endl;
	int m = 0;
	cout << "Leaf node: " << BT1.numberOfBTreeLeafNode( BT1.getNodePoint(), m ) << endl;
	int a = 0;
	BT1.numberOfNodeDegreeTwo( BT1.getNodePoint(), a );
	cout << "Node degree two: " << a << endl;
}

void test2()
{
	_Binary_Tree BT1;
	elementType strLine[100][3];
	int nRow = 0, nLen = 0;
	binTree index;
	BT1.readFileToArray(strLine,nLen);
	//BT1._Binary_Tree();
	
	BT1.createBinaryTree( index,strLine, nLen, nRow);
	char ch;
	int key;
	cout << "Please input a letter as operational character and a number to choose the operation,separated by space.\n\"1\" for searching parent-node£¬\"2\" for searching sibiling-node and \"3\" for searching child-node." << endl;
	while( cin>> ch >> key )
	{
		if( key == 1 )
		{
			bool flag = false;
			bitNode *index = NULL;
			index = BT1.getParent( BT1.getNodePoint(), ch );
			if( index && index != BT1.getNodePoint() )
				cout << ch << " parent ---- " << index->data << endl;
			else if( index && index->data == ch )
				cout << ch << " is the root node, no parent." << endl;
			else if(index)
				cout << ch << " parent ---- " << index->data << endl;
		}
		else if( key == 2 )
		{
			BT1.getSibling( BT1.getNodePoint(), ch );
		}
		else if( key == 3 )
		{
			bool flag;
			BT1.getChild( BT1.getNodePoint(), ch, flag );
		}
		//Sleep( 1000 * 60 );
		//system( "cls" );
		//cout << "Please input a letter as operational character and a number to choose the operation,separated by space.\n\"1\" for searching parent-node£¬\"2\" for searching sibiling-node and \"3\" for searching child-node." << endl;
	}
}

void test3()
{
	_Binary_Tree BT1;
	elementType strLine[100][3];
	int nRow = 0, nLen = 0;
	binTree index;
	BT1.readFileToArray(strLine,nLen);
	//BT1._Binary_Tree();
	
	BT1.createBinaryTree( index,strLine, nLen, nRow);

	elementType value;
	int cnt = 0;
	cout << "Please input a letter and the program will judge it in which layer of the binary-tree!" << endl;
	while( cin >> value )
	{
		int number = 1;
		BT1.levelJudge( BT1.getNodePoint(), value , number, 1 );
		cout << value << " ---- " << number << " level!" << endl;
		cnt ++;
		//Sleep( 1000 * 60 );
		if( cnt % 10 == 0 )
			system( "cls" );
		
		cout << "Please input a letter and the program will judge it in which layer of the binary-tree!" << endl;
	}
}

void test4()
{
	elementType str[10000];
	cout << "Please input a character array that will be transformed to the elements of a binary tree.\nAttention the typed array must extend for the complete binary tree!" << endl;
	while( cin >> str )
	{
		_Binary_Tree BT1(str);
		cout << "The preorder traversal of sequence is" << endl;
		BT1.preOrderTraverse(BT1.getNodePoint());
		cout << endl;
		cout << "The middle order traversal of sequence is" << endl;
		BT1.inOrderTraverse(BT1.getNodePoint()); 
		cout << endl;
		cout << "The post order traversal of sequence is" << endl;
		BT1.postOrderTraverse(BT1.getNodePoint()); 
		cout << endl;
		cout << "The level order traversal of sequence is" << endl;
		BT1.levelOrderTraverse( BT1.getNodePoint() );
		cout << endl;
		int n = 1;
		BT1.level( BT1.getNodePoint() , n );
		cout << "BTree height: "<< BT1.height( BT1.getNodePoint() ) << endl;
		cout << "Total node: " << BT1.numberOfBTreeNode( BT1.getNodePoint() ) << endl;
		int m = 0;
		cout << "Leaf node: " << BT1.numberOfBTreeLeafNode( BT1.getNodePoint(), m ) << endl;
		int a = 0;
		BT1.numberOfNodeDegreeTwo( BT1.getNodePoint(), a );
		cout << "Node degree two: " << a << endl;
		Sleep( 1000 * 60 );
		system( "cls" );
		cout << "Please input a character array that will be transformed to the elements of a binary tree.\nAttention the typed array must extend for the complete binary tree!" << endl;
	}
}

void test5()
{
	_Binary_Tree BT1;
	elementType strLine[100][3];
	int nRow = 0, nLen = 0;
	binTree index;
	BT1.readFileToArray(strLine,nLen);
	//BT1._Binary_Tree();
	
	BT1.createBinaryTree( index,strLine, nLen, nRow);
	cout << "The program will exchange the left subtree and right subtree of the file-inputed binary tree!" << endl;
	cout << "The origin binary tree is as follow:" << endl;

	cout << "The preorder traversal of sequence is" << endl;
	BT1.preOrderTraverse(BT1.getNodePoint());
	cout << endl;
	cout << "The middle order traversal of sequence is" << endl;
	BT1.inOrderTraverse(BT1.getNodePoint()); 
	cout << endl;
	cout << "The post order traversal of sequence is" << endl;
	BT1.postOrderTraverse(BT1.getNodePoint()); 
	cout << endl;
	cout << "The level order traversal of sequence is" << endl;
	BT1.levelOrderTraverse( BT1.getNodePoint() );
	cout << endl;

	BT1.exchangeLeftAndRightSibling( BT1.getNodePoint() );
	cout << "The following for the exchange of binary tree:" << endl;
	cout << "The preorder traversal of sequence is" << endl;
	BT1.preOrderTraverse(BT1.getNodePoint());
	cout << endl;
	cout << "The middle order traversal of sequence is" << endl;
	BT1.inOrderTraverse(BT1.getNodePoint()); 
	cout << endl;
	cout << "The post order traversal of sequence is" << endl;
	BT1.postOrderTraverse(BT1.getNodePoint()); 
	cout << endl;
	cout << "The level order traversal of sequence is" << endl;
	BT1.levelOrderTraverse( BT1.getNodePoint() );
	cout << endl;
}

void test6()
{
	_Binary_Tree BT1;
	elementType strLine[100][3];
	int nRow = 0, nLen = 0;
	binTree index;
	BT1.readFileToArray(strLine,nLen);
	//BT1._Binary_Tree();
	
	BT1.createBinaryTree( index,strLine, nLen, nRow);
	cout << "The program will copy the file-inputed binary tree to another empty one!" << endl;
	_Binary_Tree BT2;

	cout << "The origin binary tree is as follow:" << endl;
	cout << "The preorder traversal of sequence is" << endl;
	BT1.preOrderTraverse(BT1.getNodePoint());
	cout << endl;
	cout << "The middle order traversal of sequence is" << endl;
	BT1.inOrderTraverse(BT1.getNodePoint()); 
	cout << endl;
	cout << "The post order traversal of sequence is" << endl;
	BT1.postOrderTraverse(BT1.getNodePoint()); 
	cout << endl;
	cout << "The level order traversal of sequence is" << endl;
	BT1.levelOrderTraverse( BT1.getNodePoint() );
	cout << endl;

	cout << "The empty binary tree is as follow:" << endl;

	cout << "The preorder traversal of sequence is" << endl;
	BT2.preOrderTraverse(BT2.getNodePoint());
	cout << endl;
	cout << "The middle order traversal of sequence is" << endl;
	BT2.inOrderTraverse(BT2.getNodePoint()); 
	cout << endl;
	cout << "The post order traversal of sequence is" << endl;
	BT2.postOrderTraverse(BT2.getNodePoint()); 
	cout << endl;
	cout << "The level order traversal of sequence is" << endl;
	BT2.levelOrderTraverse( BT2.getNodePoint() );
	cout << endl;
	
	cout << "The following for the copy of binary tree:" << endl;

	BT1.copyBTree( BT2.getNodePoint(), BT1.getNodePoint() );

	cout << "The preorder traversal of sequence is" << endl;
	BT2.preOrderTraverse(BT2.getNodePoint());
	cout << endl;
	cout << "The middle order traversal of sequence is" << endl;
	BT2.inOrderTraverse(BT2.getNodePoint()); 
	cout << endl;
	cout << "The post order traversal of sequence is" << endl;
	BT2.postOrderTraverse(BT2.getNodePoint()); 
	cout << endl;
	cout << "The level order traversal of sequence is" << endl;
	BT2.levelOrderTraverse( BT2.getNodePoint() );
	cout << endl;

}

void test7()
{
	_Binary_Tree BT1;
	elementType strLine[100][3];
	int nRow = 0, nLen = 0;
	binTree index;
	BT1.readFileToArray(strLine,nLen);
	//BT1._Binary_Tree();
	
	BT1.createBinaryTree( index,strLine, nLen, nRow);
	cout << "The program will output the paths that each leaf node of the binary tree to the root node." << endl;

	cout << "The origin binary tree is as follow:" << endl;
	cout << "The preorder traversal of sequence is" << endl;
	BT1.preOrderTraverse(BT1.getNodePoint());
	cout << endl;
	cout << "The middle order traversal of sequence is" << endl;
	BT1.inOrderTraverse(BT1.getNodePoint()); 
	cout << endl;
	cout << "The post order traversal of sequence is" << endl;
	BT1.postOrderTraverse(BT1.getNodePoint()); 
	cout << endl;
	cout << "The level order traversal of sequence is" << endl;
	BT1.levelOrderTraverse( BT1.getNodePoint() );
	cout << endl;

	int pathLength = 0;
	elementType *path = new char[ BT1.numberOfBTreeNode( BT1.getNodePoint() ) ];
	BT1.allLeafToRootPath( BT1.getNodePoint(), path, pathLength );
	
}

void test8()
{
	_Binary_Tree BT1;
	elementType strLine[100][3];
	int nRow = 0, nLen = 0;
	binTree index;
	BT1.readFileToArray(strLine,nLen);
	//BT1._Binary_Tree();
	
	BT1.createBinaryTree( index,strLine, nLen, nRow);
	cout << "The program will ouput the level order traversal of the file-inputed binary tree." << endl;
	cout << "The level order traversal of sequence is" << endl;
	BT1.levelOrderTraverse( BT1.getNodePoint() );
	cout << endl;
}

void test9()
{
	_Binary_Tree BT1;
	char strLine[100][3];
	int nRow = 0, nLen = 0;
	binTree index;
	BT1.readFileToArray(strLine,nLen);
	//BT1._Binary_Tree();
	
	BT1.createBinaryTree( index,strLine, nLen, nRow);
	
	cout << "Please input two character and the program will output their nearset ancestor." << endl;
	elementType ch1, ch2;
	while( cin >> ch1 >> ch2 )
	{
		//BT1.nearestAncestor( binTree BT, bitNode *BNode1, bitNode *BNode2 );
		bitNode *index1 = BT1.getNodePoint( BT1.getNodePoint(), ch1 );
		
		if(!index1)
		{
			cout << ch1 << " is not in the binary tree!" << endl;
		}
		
		bitNode *index2 = BT1.getNodePoint( BT1.getNodePoint(), ch2 );
		
		if(!index2)
		{
			cout << ch2 << " is not in the binary tree!" << endl;
		}
		
		if( index1 && index2 )
		{
			bitNode *target = BT1.nearestAncestor( BT1.getNodePoint(), index1, index2 );
			cout << "The nearset ancestor of " << ch1 << " and " << ch2 << " is " << target->data << endl;
		}
		cout << "Please input two character and the program will output their nearset ancestor." << endl;
	}
}

void test10()
{
	_Binary_Tree BT1;
	char strLine[100][3];
	int nRow = 0, nLen = 0;
	binTree index;
	BT1.readFileToArray(strLine,nLen);
	//BT1._Binary_Tree();
	
	BT1.createBinaryTree( index,strLine, nLen, nRow);
	cout << "The program will output the longest path of the binary tree." << endl;
	int pathLength = 0, longestLength = 0;
	elementType *path1 = new char[ BT1.numberOfBTreeNode( BT1.getNodePoint() ) ];
	elementType *longestPath = new char[ BT1.numberOfBTreeNode( BT1.getNodePoint() ) ];
	BT1.binaryTreeLongestPath( BT1.getNodePoint(), path1, pathLength, longestPath, longestLength );
	cout << "Longest path:" << endl;
 	for( int i = longestLength; i >= 0; i -- )
	{
		if( i!= 0 )
			cout << longestPath[i] << " --> ";
		else
			cout << longestPath[i] << endl;
		
	}
}

int main(int argc, char* argv[])
{
	//test1();
	test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	//test9();
	//test10();
	return 0;
}
