// BSTree.h: interface for the BSTree class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BSTREE_H__37E371A7_E165_4AC3_898B_DDF38B0F87D8__INCLUDED_)
#define AFX_BSTREE_H__37E371A7_E165_4AC3_898B_DDF38B0F87D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class BSTree  
{
public:
	BSTree();
	virtual ~BSTree();
	BSTNode *search( _BSTree BST, elementType value );//�ݹ����
	BSTNode *search( _BSTree BST, elementType value, _BSTree &father );//��������
	BSTNode *getRootNode();
	bool insert( _BSTree BST, elementType value );

	bool deleteNode1( _BSTree &BST, elementType value );	//ɾ��ָ����㣬failed
	void deleteNode2( _BSTree &BST, elementType value );	//�ݹ�ɾ��ָ�����
	void deleteNode2_1( _BSTree &BST, elementType value );	//����ɾ��ָ����㣬�����ԣ�
	void deleteNode3( _BSTree &BST, elementType value );

	void removeNode1( _BSTree &BST );
	void removeNode2( _BSTree &BST );
	void removeNode3( _BSTree &BST );

	void createBinarySearchTree( _BSTree BST, vector<elementType>VI/*elementType value*/ );
	void destroy( _BSTree BST );
	void preOrderTraversal( _BSTree BST/*, int space*/ );
	void inOrderTraversal( _BSTree BST/*, int space*/ );
	void postOrderTraversal( _BSTree BST/*, int space*/ );
private:
	BSTNode *head;
};

#endif // !defined(AFX_BSTREE_H__37E371A7_E165_4AC3_898B_DDF38B0F87D8__INCLUDED_)
