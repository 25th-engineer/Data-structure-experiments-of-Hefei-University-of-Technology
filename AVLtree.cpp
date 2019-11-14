#include "pch.h"
#include "AVLtree.h"


template <class T>
void AVLTree<T>::reBalance(AVLNode<T> *AVLB)
{
	setBalance(AVLB);

	if (AVLB->balance == -2)
	{
		if (height(AVLB->leftChild->leftChild) >= height(AVLB->leftChild->rightChild))
			AVLB = LL_Rotate(AVLB);
		else
			AVLB = LR_Rotate(AVLB);
	}
	else if (AVLB->balance == 2)
	{
		if (height(AVLB->rightChild->rightChild) >= height(AVLB->rightChild->leftChild))
			AVLB = RR_Rotate(AVLB);
		else
			AVLB = RL_Rotate(AVLB);
	}

	if (AVLB->parent != NULL)
	{
		reBalance(AVLB->parent);
	}
	else
	{
		root = AVLB;
	}
}

template <class T>
AVLNode<T>* AVLTree<T>::RR_Rotate(AVLNode<T> *AVLB)
{
	AVLNode<T> *tmp = AVLB->rightChild;
	tmp->parent = AVLB->parent;
	AVLB->rightChild = tmp->leftChild;

	if (AVLB->rightChild != NULL)
		AVLB->rightChild->parent = AVLB;

	tmp->leftChild = AVLB;
	AVLB->parent = tmp;

	if (tmp->parent != NULL)
	{
		if (tmp->parent->rightChild == AVLB)
		{
			tmp->parent->rightChild = tmp;
		}
		else
		{
			tmp->parent->leftChild = tmp;
		}
	}

	setBalance(AVLB);
	setBalance(tmp);
	return tmp;
}

template <class T>
AVLNode<T>* AVLTree<T>::LL_Rotate(AVLNode<T> *AVLB)
{
	AVLNode<T> *tmp = AVLB->leftChild;
	tmp->parent = AVLB->parent;
	AVLB->leftChild = tmp->rightChild;

	if (AVLB->leftChild != NULL)
		AVLB->leftChild->parent = AVLB;

	tmp->rightChild = AVLB;
	AVLB->parent = tmp;

	if (tmp->parent != NULL)
	{
		if (tmp->parent->rightChild == AVLB)
		{
			tmp->parent->rightChild = tmp;
		}
		else
		{
			tmp->parent->leftChild = tmp;
		}
	}

	setBalance(AVLB);
	setBalance(tmp);
	return tmp;
}

template <class T>
AVLNode<T>* AVLTree<T>::LR_Rotate(AVLNode<T> *AVLB)
{
	AVLB->leftChild = RR_Rotate(AVLB->leftChild);
	return LL_Rotate(AVLB);
}

template <class T>
AVLNode<T>* AVLTree<T>::RL_Rotate(AVLNode<T> *AVLB)
{
	AVLB->rightChild = LL_Rotate(AVLB->rightChild);
	return RR_Rotate(AVLB);
}

template <class T>
AVLNode<T>* AVLTree<T>::getRootNode()
{
	return root;
}

template <class T>
int AVLTree<T>::height(AVLNode<T> *AVLB)
{
	if (AVLB == NULL)
		return -1;
	return 1 + max(height(AVLB->leftChild), height(AVLB->rightChild));
}

template <class T>
void AVLTree<T>::setBalance(AVLNode<T> *AVLB)
{
	AVLB->balance = height(AVLB->rightChild) - height(AVLB->leftChild);
}

template <class T>
void AVLTree<T>::printBalance(AVLNode<T> *AVLB)
{
	ios::sync_with_stdio(false);
	if (AVLB != NULL)
	{
		printBalance(AVLB->leftChild);
		cout << AVLB->balance << " ";
		//std::cout << n->key << " ";
		printBalance(AVLB->rightChild);
	}
}

template <class T>
void AVLTree<T>::inOrderTraverse(AVLNode<T> *AVLB)
{
	ios::sync_with_stdio(false);
	if (AVLB)
	{
		inOrderTraverse(AVLB->leftChild);
		cout << AVLB->key << " ";
		inOrderTraverse(AVLB->rightChild);
	}
}

template <class T>
void AVLTree<T>::preOrderTraverse(AVLNode<T> *AVLB)
{
	if (AVLB)
	{
		cout << AVLB->key << " ";
		preOrderTraverse(AVLB->leftChild);
		preOrderTraverse(AVLB->rightChild);
	}
}

template <class T>
void AVLTree<T>::postOrderTraverse(AVLNode<T> *AVLB)
{
	ios::sync_with_stdio(false);
	if (AVLB)
	{
		postOrderTraverse(AVLB->leftChild);
		postOrderTraverse(AVLB->rightChild);
		cout << AVLB->key << " ";
	}
}

template <class T>
void AVLTree<T>::display(AVLNode <T>*AVLB, int space, int colour )
{
	ios::sync_with_stdio(false);
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (AVLB)
	{
		display(AVLB->rightChild, space + 1, colour + 1);
		SetConsoleTextAttribute(hConsole, 0x0008 | colour);
		//colour++;
		cout << endl;
		if (AVLB == root)
			cout << " Root ----> ";
		for (int i = 0; i < space && AVLB != root; i++)
			cout << "          ";
		cout << AVLB->key;
		display(AVLB->leftChild, space + 1, colour + 1);
	}
}

template <class T>
AVLTree<T>::AVLTree(void) : root(NULL) {}

template <class T>
AVLTree<T>::~AVLTree(void)
{
	delete root;
}

template <class T>
bool AVLTree<T>::insert(T key)
{
	if (root == NULL)
	{
		root = new AVLNode<T>(key, NULL);
	}
	else
	{
		AVLNode<T>  //这种风格我觉得不错
					//I appreciate this style of code
			*target = root, 
			*parent;

		while (1)
		{
			if (target->key == key)
				return false;

			parent = target;

			bool goLeft = target->key > key;
			target = goLeft ? target->leftChild : target->rightChild;

			if (target == NULL)
			{
				if (goLeft)
				{
					parent->leftChild = new AVLNode<T>(key, parent);
				}
				else
				{
					parent->rightChild = new AVLNode<T>(key, parent);
				}

				reBalance(parent);
				break;
			}
		}
	}

	return true;
}

template <class T>
void AVLTree<T>::deleteKey(const T delKey)
{
	if (root == NULL)
		return;

	AVLNode<T>
		*target = root,
		*parent = root,
		*delNode = NULL,
		*child = root;

	while (child != NULL)
	{
		parent = target;
		target = child;
		child = delKey >= target->key ? target->rightChild : target->leftChild;
		if (delKey == target->key)
			delNode = target;
	}

	if (delNode != NULL)
	{
		delNode->key = target->key;

		child = target->leftChild != NULL ? target->leftChild : target->rightChild;

		if (root->key == delKey)
		{
			root = child;
		}
		else
		{
			if (parent->leftChild == target)
			{
				parent->leftChild = child;
			}
			else
			{
				parent->rightChild = child;
			}

			reBalance(parent);
		}
	}
}

template <class T>
void AVLTree<T>::printBalance()
{
	ios::sync_with_stdio(false);
	printBalance(root);
	cout << endl;
}

template <class T>
void AVLTree<T>::inOrderTraverse()
{
	ios::sync_with_stdio(false);
	inOrderTraverse(root);
	cout << endl;
}

template <class T>
void AVLTree<T>::preOrderTraverse()
{
	ios::sync_with_stdio(false);
	preOrderTraverse(root);
	cout << endl;
}

template <class T>
void AVLTree<T>::postOrderTraverse()
{
	ios::sync_with_stdio(false);
	postOrderTraverse(root);
	cout << endl;
}

template <class T>
void AVLTree<T>::display()
{
	ios::sync_with_stdio(false);
	int color = 1;
	display(root, 1, color);
	cout << endl;
}