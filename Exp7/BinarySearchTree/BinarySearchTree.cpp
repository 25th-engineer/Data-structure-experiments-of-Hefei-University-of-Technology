// BinarySearchTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BSTree.h"

int main(int argc, char* argv[])
{
	BSTree BST1;
	elementType value;
	while( cin >> value )
	{
		if( value == "##" )
		{
			break;
		}
		BST1.createBinarySearchTree( BST1.getRootNode(), value );
	}
	BST1.preOrderTraversal( BST1.getRootNode() );
	cout << endl;
	BST1.inOrderTraversal( BST1.getRootNode() );
	cout << endl;
	return 0;
}
