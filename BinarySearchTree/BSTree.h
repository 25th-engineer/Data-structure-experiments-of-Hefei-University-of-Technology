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
	BSTNode *search( _BSTree BST, elementType value );//µÝ¹é²éÕÒ
	BSTNode *search( _BSTree BST, elementType value, _BSTree &father );//µü´ú²éÕÒ
	BSTNode *getRootNode();
	bool insert( _BSTree BST, elementType value );
	bool deleteNode( _BSTree BST, elementType value );
	void createBinarySearchTree( _BSTree BST, elementType value );
	void destroy( _BSTree BST );
	void preOrderTraversal( _BSTree BST );
	void inOrderTraversal( _BSTree BST );
private:
	BSTNode *head;
};

#endif // !defined(AFX_BSTREE_H__37E371A7_E165_4AC3_898B_DDF38B0F87D8__INCLUDED_)
