#pragma once
/* AVL node */
template <class T>
class AVLNode
{
public:
	T key;
	int balance;
	AVLNode *leftChild, *rightChild, *parent;

	AVLNode(T k, AVLNode *p) : key(k), balance(0), parent(p),leftChild(NULL), rightChild(NULL) {}
	~AVLNode();
};
