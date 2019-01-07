#include "pch.h"
#include "AVLnode.h"


template <class T>
AVLNode<T>::~AVLNode()
{
	delete leftChild;
	delete rightChild;
}