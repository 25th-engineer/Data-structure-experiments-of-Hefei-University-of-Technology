#pragma once
/* AVL tree */

#include "AVLnode.h"
template <class T>
class AVLTree
{
public:
	AVLTree(void);
	~AVLTree(void);
	bool insert(T key);
	void deleteKey(const T key);
	void printBalance();
	void inOrderTraverse();
	void preOrderTraverse();
	void postOrderTraverse();
	void display();

	AVLNode<T>* RR_Rotate(AVLNode<T> *AVLB);		//rotate left
													//����RR������ƽ��ʱ��Ҫ��������ת
	AVLNode<T>* LL_Rotate(AVLNode<T> *AVLB);		//rotate right
													//����LL������ƽ��ʱ��Ҫ��������ת
	AVLNode<T>* LR_Rotate(AVLNode<T> *AVLB);	//rotate left then right
	AVLNode<T>* RL_Rotate(AVLNode<T> *AVLB);	//rotate right then left
	AVLNode<T>* getRootNode();
	void reBalance(AVLNode<T> *AVLB);
	int height(AVLNode<T> *AVLB);
	void setBalance(AVLNode<T> *AVLB);
	void printBalance(AVLNode<T> *AVLB);
	void clearNode(AVLNode<T> *AVLB);
	void inOrderTraverse(AVLNode<T> *AVLB);
	void preOrderTraverse(AVLNode<T> *AVLB);
	void postOrderTraverse(AVLNode<T> *AVLB);

	void display(AVLNode <T>*AVLB, int space, int colour);

private:
	AVLNode<T> *root;
};
