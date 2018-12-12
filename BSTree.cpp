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
	//head = NULL;
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

void BSTree::preOrderTraversal( _BSTree BST/*, int space*/ )
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

		//for( int i  = 0; i < space; i ++ )
		//	cout << " ";
		//cout << BST->data << endl;
		//preOrderTraversal( BST->leftChidld, space + 5 );
		//preOrderTraversal( BST->rightChild, space + 5 );
	}
}

void BSTree::inOrderTraversal( _BSTree BST/*, int space*/ )
{
	ios::sync_with_stdio(false);
	if(BST)
	{
		inOrderTraversal( BST->leftChidld );
		cout << BST->data << " "; 
		inOrderTraversal( BST->rightChild );

		//inOrderTraversal( BST->leftChidld, space + 5 );
		//for( int i  = 0; i < space; i ++ )
		//	cout << " ";
		//cout << BST->data << endl; 
		//inOrderTraversal( BST->rightChild, space + 5 );
	}
}

void BSTree::postOrderTraversal( _BSTree BST/*, int space*/ )
{
	ios::sync_with_stdio(false);
	if(BST)
	{
		postOrderTraversal( BST->leftChidld );
		postOrderTraversal( BST->rightChild );
		cout << BST->data << " ";

		/*
		postOrderTraversal( BST->leftChidld, space + 5 );
		postOrderTraversal( BST->rightChild, space + 5 );
		for( int i  = 0; i < space; i ++ )
			cout << " ";
		cout << BST->data << endl;
		*/
	}
}

void BSTree::createBinarySearchTree( _BSTree BST, /*elementType value*/vector<elementType>VI )
{
	//BST = NULL;
	head = NULL;
	for( int i = 0; i < VI.size(); i ++ )
	{
		insert( head, VI[i] );
	}
	return;
	/*
	while( cin >> value )
	{
		if( value == "#" )
		{
			return;
		}
		else
			insert( head, value );
	}
	
	for( int i = 0; i < value; i ++ )
	{
		elementType key;
		cout << "input: ";
		cin >> key;
		insert( head, key );
	}
	*/
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
	/*
	if(!head)
	{
		cerr << "The binary search tree empty.Error in BSTNode *BSTree::search( _BSTree BST, elementType value, _BSTree &father )." << endl;
		return NULL;
	}
	*/
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

bool BSTree::deleteNode1( _BSTree &BST, elementType value )
{
	ios::sync_with_stdio(false);
	//if(!head)
	if(!BST)
	{
		cerr << "The binary search tree does not exit.Error in bool BSTree::deleteNode( _BSTree BST, elementType value )" << endl;
		return false;
	}
	BSTNode *newNode, *target, *father;
	//target = search( head, value, father );
	target = search( BST, value, father );
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
	//if( target == head )					//被删结点是根结点
	if( target == BST )
	{
		//head = newNode;
		BST = newNode;
	}
	else if( newNode && ( newNode->data < father->data ) )		//重新链接，保持二叉排序树
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

void BSTree::deleteNode2( _BSTree &BST, elementType value )
{
	if(BST)
	{
		if( value < BST->data )
		{
			deleteNode2( BST->leftChidld, value );
		}
		else if( value > BST->data )
		{
			deleteNode2( BST->rightChild, value );
		}
		else
		{
			removeNode1(BST);
		}
	}
}

void BSTree::deleteNode2_1( _BSTree &BST, elementType value )	//迭代删除指定结点，待调试！
{
	BSTNode *target = NULL;
	while( BST || BST->data != value )
	{
		target = BST;
		if( value < target->data )
		//if( value < BST->data )
			BST = BST->leftChidld;
		else
			BST = BST->rightChild;
	}
	removeNode1(target);
	//removeNode1(BST);
}

void BSTree::deleteNode3( _BSTree &BST, elementType value )
{
	if(BST)
	{
		if( value < BST->data )
		{
			deleteNode2( BST->leftChidld, value );
		}
		else if( value > BST->data )
		{
			deleteNode2( BST->rightChild, value );
		}
		else
		{
			removeNode2(BST);
		}
	}
}
/*
在二叉查找树中删除一个给定的结点p有三种情况

(1)结点p无左右子树，则直接删除该结点，修改父节点相应指针

(2)结点p有左子树（右子树），则把p的左子树（右子树）接到p的父节点上

(3)左右子树同时存在，则有三种处理方式

	a.找到结点p的中序直接前驱结点s，把结点s的数据转移到结点p，然后删除结点s，
	由于结点s为p的左子树中最右的结点，因而s无右子树，删除结点s可以归结到情况(2)。
	严蔚敏数据结构P230-231就是该处理方式。
	b.找到结点p的中序直接后继结点s，把结点s的数据转移到结点p，然后删除结点s，
	由于结点s为p的右子树总最左的结点，因而s无左子树，删除结点s可以归结到情况(2)。
	算法导论第2版P156-157该是该处理方式。
	c.到p的中序直接前驱s，将p的左子树接到父节点上，将p的右子树接到s的右子树上，然后删除结点p。
*/
void BSTree::removeNode1( _BSTree &BST )
{
	BSTNode *target = NULL;
	if( !BST->leftChidld )
	{
		target = BST;
		BST = BST->rightChild;
		delete target;
	}
	else if( !BST->rightChild )
	{
		target = BST;
		BST = BST->leftChidld;
		delete target;
	}
	else
	{
		BSTNode *newNode = NULL;
		target = BST;
		newNode = BST->leftChidld;		//左子树根结点	
		while( newNode->rightChild )	//寻找 BST 结点的中序前驱结点，即以 BST->leftChild为根结点的子树中的最右结点
		{
			target = newNode;			//*target 指向 *BST 的父结点		
			newNode = newNode->rightChild;			//*newNode 指向 *BST 的中序前驱结点
		}
		BST->data = newNode->data;		//*newNode 的数据传給 *BST 的数据，然后删除结点 *newNode
		if( target != BST )				//BST->leftChidld 的右子树非空，这句话等价于 if( !( target == BST ) )
		{
			target->rightChild = newNode->leftChidld;	//*newNode 的左子树接到 *target 的右子树上 
		}
		else
		{
			target->leftChidld = newNode->leftChidld;	//*newNode 的左子树接到 *target 的左子树上
		}
		delete newNode;					//删除结点 *newNode
	}
}

//注意 while 循环体：
//如果 BST 左子树为空，则 while 循环体不执行，那么 target 就不会发生改变。 
//然而一开始 target == BST。
//反过来说，如果 BST 左子树不为空，则 while 执行，那么 target 就会发生改变。
//target 改变了，就和 BST 不一样。
//所以就可以表明 BST 左子树非空。

void BSTree::removeNode2( _BSTree &BST )
{
	BSTNode *target = NULL;
	if( !BST->leftChidld )
	{
		target = BST;
		BST = BST->rightChild;
		delete target;
	}
	else if( !BST->rightChild )
	{
		target = BST;
		BST = BST->leftChidld;
		delete target;
	}
	else
	{
		BSTNode *newNode = NULL;
		target = BST;
		newNode = BST->rightChild;		//右子树根结点
		while( newNode->leftChidld )	//寻找 BST 结点的中序前驱结点，即以 BST->leftChild为根结点的子树中的最左结点
		{
			target = newNode;			//*target 指向 *BST 的父结点
			newNode = newNode->leftChidld;		//*newNode 指向 *BST 的中序后继结点
		}
		BST->data = newNode->data;		//*newNode 的数据传給 *BST 的数据，然后删除结点 *newNode
		if( target != BST )				//BST->leftChidld 的左子树非空，这句话等价于 if( !( target == BST ) )
		{
			target->leftChidld = newNode->rightChild;		//*newNode 的右子树接到 *target 的左子树上 
		}
		else
		{
			target->rightChild = newNode->rightChild;		//*newNode 的右子树接到 *target 的右子树上 
		}
		delete newNode;					//删除结点 *newNode
	}
}

//注意 while 循环体：
//如果 BST 右子树为空，则 while 循环体不执行，那么 target 就不会发生改变。 
//然而一开始 target == BST。
//反过来说，如果 BST 右子树不为空，则 while 执行，那么 target 就会发生改变。
//target 改变了，就和 BST 不一样
//所以就可以表明 BST 右子树非空。


void BSTree::removeNode3( _BSTree &BST )		
{
	BSTNode *target = NULL;
	if( !BST->leftChidld )
	{
		target = BST;
		BST = BST->rightChild;
		delete target;
	}
	else if( !BST->rightChild )
	{
		target = BST;
		BST = BST->leftChidld;
		delete target;
	}
	else
	{
		BSTNode *newNode = NULL;
		target = BST;
		newNode = BST->leftChidld;			//左子树根结点
		while( newNode->rightChild )		//寻找 BST 结点的中序前驱结点，即以 BST->leftChild为根结点的子树中的最右结点
		{
			//target = newNode;
			newNode = newNode->rightChild;
		}
		newNode->rightChild = target->leftChidld;		//*target 的左子树接到 *newNode 的左子树上
		target = target->leftChidld;					//*target 的左子树接到父结点上
		delete target;					//删除结点 *target
	}
}