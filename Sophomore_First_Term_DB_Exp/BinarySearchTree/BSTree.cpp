// BSTree.cpp: implementation of the BSTree class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BSTree.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BSTree::BSTree()
{
	head = NULL;
	//head = new BSTNode;
	//head->leftChidld = head->rightChild = NULL;
}

BSTree::~BSTree()
{
	ios::sync_with_stdio(false);
	destroy(head);
	cout << "The binary search tree has been destroyed!" << endl;
}

void BSTree::destroy( _BSTree BST )
{
	if(BST)
	{
		destroy( BST->leftChidld );
		destroy( BST->rightChild );
		delete BST;
	}
}

void BSTree::preOrderTraversal( _BSTree BST )
{
	ios::sync_with_stdio(false);
	/*
	if(!BST)
	{
		cerr << "The binary search tree is empty.Error in void BSTree::preOrderTraversal( _BSTree BST )." << endl;
		return;
	}
	*/
	if(BST)
	{
		cout << BST->data << " ";
		preOrderTraversal( BST->leftChidld );
		preOrderTraversal( BST->rightChild );
	}
}

void BSTree::inOrderTraversal( _BSTree BST )
{
	ios::sync_with_stdio(false);
	if(BST)
	{
		inOrderTraversal( BST->leftChidld );
		cout << BST->data << " "; 
		inOrderTraversal( BST->rightChild );
	}
}

void BSTree::createBinarySearchTree( _BSTree BST, elementType value )
{
	//BST = NULL;
	//head = NULL;
	while( cin >> value )
	{
		if( value == "#" )
		{
			return;
		}
		insert( head, value );
	}
}

BSTNode *BSTree::getRootNode()
{
	return head;
}

BSTNode *BSTree::search( _BSTree BST, elementType value )//递归查找
{
	ios::sync_with_stdio(false);
	if(!head)
	{
		cerr << "The binary search tree is empty.Error in BSTNode *BSTree::search( _BSTree BST, elementType value )." << endl;
		return NULL;
	}
	else if( BST->data == value )
	{
		return BST;
	}
	else if( BST->data > value )
	{
		return search( BST->leftChidld, value );
	}
	else
	{
		return search( BST->rightChild, value );
	}
}

BSTNode *BSTree::search( _BSTree BST, elementType value, _BSTree &father )//迭代查找
{
	ios::sync_with_stdio(false);
	if(!head)
	{
		cerr << "The binary search tree empty.Error in BSTNode *BSTree::search( _BSTree BST, elementType value, _BSTree &father )." << endl;
		return NULL;
	}
	BSTNode *tmp = head;
	father = NULL;
	while( tmp && tmp->data != value )
	{
		father = tmp;
		if( value < tmp->data )
		{
			tmp = tmp->leftChidld;
		}
		else
		{
			tmp = tmp->rightChild;
		}
	}
	return tmp;
}

bool BSTree::insert( _BSTree BST, elementType value )
{
	//if(!head)
	//{
	//	cerr << "The binary search tree does not exit.Error in bool BSTree::insert( _BSTree BST, elementType value )" << endl;
	//	return false;
	//}
	BSTNode *newNode, *target, *father;

	target = search( head, value, father );
	if(target)
	{
		cerr << "Inserting failed!" << value << " has been exited in the binary search tree.\nError in bool BSTree::insert( _BSTree BST, elementType value )" << endl;
		return false;
	}
	newNode = new BSTNode;
	newNode->data =  value;
	newNode->leftChidld = newNode->rightChild = NULL;
	if(!head)
	{
		head = newNode;
	}
	else if( value < father->data )
	{
		father->leftChidld = newNode;
	}
	else
	{
		father->rightChild = newNode;
	}
	return true;
}

bool BSTree::deleteNode( _BSTree BST, elementType value )
{
	if(!head)
	{
		cerr << "The binary search tree does not exit.Error in bool BSTree::deleteNode( _BSTree BST, elementType value )" << endl;
		return false;
	}
	BSTNode *newNode, *target, *father;
	target = search( head, value, father );
	if( !target )//查找失败，不删除
	{
		cerr << "Node-deleting failed!\n" << value << " is not in the binary search tree.\n" << "Error in bool BSTree::deleteNode( _BSTree BST, elementType value )." << endl;
		return false;
	}
	if( target->leftChidld && target->rightChild )//被删结点有两个 *target 孩子节点
	{
		newNode = target->rightChild;			//找 target 的中序后继 newNode
		father = target;
		while( newNode->leftChidld )
		{
			father = newNode;
			newNode = newNode->leftChidld;
		}
		target->data = newNode->data;		//将 *newNode 的数据传給 *target
		target = newNode;					//找到的这个结点成为被删除结点
	}
	if( target->leftChidld )			//单孩子，记录非空孩子结点
	{
		newNode = target->leftChidld;
	}
	else
	{
		newNode = target->rightChild;
	}
	if( target == head )					//被删结点是根结点
	{
		head = newNode;
	}
	else if( newNode && newNode->data < father->data )		//重新链接，保持二叉排序树
	{
		father->leftChidld = newNode;
	}
	else
	{
		father->rightChild = newNode;
	}
	delete target;
	return true;
}