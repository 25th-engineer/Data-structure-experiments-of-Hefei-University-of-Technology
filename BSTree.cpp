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

BSTNode *BSTree::search( _BSTree BST, elementType value )//�ݹ����
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

BSTNode *BSTree::search( _BSTree BST, elementType value, _BSTree &father )//��������
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
	if( !target )//����ʧ�ܣ���ɾ��
	{
		cerr << "Node-deleting failed!\n" << value << " is not in the binary search tree.\n" << "Error in bool BSTree::deleteNode( _BSTree BST, elementType value )." << endl;
		return false;
	}
	if( target->leftChidld && target->rightChild )//��ɾ��������� *target ���ӽڵ�
	{
		newNode = target->rightChild;			//�� target �������� newNode
		father = target;
		while( newNode->leftChidld )
		{
			father = newNode;
			newNode = newNode->leftChidld;
		}
		target->data = newNode->data;		//�� *newNode �����ݴ��o *target
		target = newNode;					//�ҵ����������Ϊ��ɾ�����
	}
	if( target->leftChidld )			//�����ӣ���¼�ǿպ��ӽ��
	{
		newNode = target->leftChidld;
	}
	else
	{
		newNode = target->rightChild;
	}
	//if( target == head )					//��ɾ����Ǹ����
	if( target == BST )
	{
		//head = newNode;
		BST = newNode;
	}
	else if( newNode && ( newNode->data < father->data ) )		//�������ӣ����ֶ���������
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

void BSTree::deleteNode2_1( _BSTree &BST, elementType value )	//����ɾ��ָ����㣬�����ԣ�
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
�ڶ����������ɾ��һ�������Ľ��p���������

(1)���p��������������ֱ��ɾ���ý�㣬�޸ĸ��ڵ���Ӧָ��

(2)���p�����������������������p�������������������ӵ�p�ĸ��ڵ���

(3)��������ͬʱ���ڣ��������ִ���ʽ

	a.�ҵ����p������ֱ��ǰ�����s���ѽ��s������ת�Ƶ����p��Ȼ��ɾ�����s��
	���ڽ��sΪp�������������ҵĽ�㣬���s����������ɾ�����s���Թ�ᵽ���(2)��
	��ε�����ݽṹP230-231���Ǹô���ʽ��
	b.�ҵ����p������ֱ�Ӻ�̽��s���ѽ��s������ת�Ƶ����p��Ȼ��ɾ�����s��
	���ڽ��sΪp��������������Ľ�㣬���s����������ɾ�����s���Թ�ᵽ���(2)��
	�㷨���۵�2��P156-157���Ǹô���ʽ��
	c.��p������ֱ��ǰ��s����p���������ӵ����ڵ��ϣ���p���������ӵ�s���������ϣ�Ȼ��ɾ�����p��
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
		newNode = BST->leftChidld;		//�����������	
		while( newNode->rightChild )	//Ѱ�� BST ��������ǰ����㣬���� BST->leftChildΪ�����������е����ҽ��
		{
			target = newNode;			//*target ָ�� *BST �ĸ����		
			newNode = newNode->rightChild;			//*newNode ָ�� *BST ������ǰ�����
		}
		BST->data = newNode->data;		//*newNode �����ݴ��o *BST �����ݣ�Ȼ��ɾ����� *newNode
		if( target != BST )				//BST->leftChidld ���������ǿգ���仰�ȼ��� if( !( target == BST ) )
		{
			target->rightChild = newNode->leftChidld;	//*newNode ���������ӵ� *target ���������� 
		}
		else
		{
			target->leftChidld = newNode->leftChidld;	//*newNode ���������ӵ� *target ����������
		}
		delete newNode;					//ɾ����� *newNode
	}
}

//ע�� while ѭ���壺
//��� BST ������Ϊ�գ��� while ѭ���岻ִ�У���ô target �Ͳ��ᷢ���ı䡣 
//Ȼ��һ��ʼ target == BST��
//������˵����� BST ��������Ϊ�գ��� while ִ�У���ô target �ͻᷢ���ı䡣
//target �ı��ˣ��ͺ� BST ��һ����
//���ԾͿ��Ա��� BST �������ǿա�

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
		newNode = BST->rightChild;		//�����������
		while( newNode->leftChidld )	//Ѱ�� BST ��������ǰ����㣬���� BST->leftChildΪ�����������е�������
		{
			target = newNode;			//*target ָ�� *BST �ĸ����
			newNode = newNode->leftChidld;		//*newNode ָ�� *BST �������̽��
		}
		BST->data = newNode->data;		//*newNode �����ݴ��o *BST �����ݣ�Ȼ��ɾ����� *newNode
		if( target != BST )				//BST->leftChidld ���������ǿգ���仰�ȼ��� if( !( target == BST ) )
		{
			target->leftChidld = newNode->rightChild;		//*newNode ���������ӵ� *target ���������� 
		}
		else
		{
			target->rightChild = newNode->rightChild;		//*newNode ���������ӵ� *target ���������� 
		}
		delete newNode;					//ɾ����� *newNode
	}
}

//ע�� while ѭ���壺
//��� BST ������Ϊ�գ��� while ѭ���岻ִ�У���ô target �Ͳ��ᷢ���ı䡣 
//Ȼ��һ��ʼ target == BST��
//������˵����� BST ��������Ϊ�գ��� while ִ�У���ô target �ͻᷢ���ı䡣
//target �ı��ˣ��ͺ� BST ��һ��
//���ԾͿ��Ա��� BST �������ǿա�


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
		newNode = BST->leftChidld;			//�����������
		while( newNode->rightChild )		//Ѱ�� BST ��������ǰ����㣬���� BST->leftChildΪ�����������е����ҽ��
		{
			//target = newNode;
			newNode = newNode->rightChild;
		}
		newNode->rightChild = target->leftChidld;		//*target ���������ӵ� *newNode ����������
		target = target->leftChidld;					//*target ���������ӵ��������
		delete target;					//ɾ����� *target
	}
}