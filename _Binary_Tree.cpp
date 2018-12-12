// _Binary_Tree.cpp: implementation of the _Binary_Tree class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "_Binary_Tree.h"
#include "charLinkedQueue.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


_Binary_Tree::_Binary_Tree()       //新建一个结点
{
	//BTree = NULL;
	BTree = new bitNode;
	BTree->leftChild = BTree->rightChild = NULL;
}

_Binary_Tree::~_Binary_Tree()
{
	destroy(BTree);//析构函数不能带参数，只能这么处理了
}

_Binary_Tree::_Binary_Tree( elementType *Arr )
{
	BTree = NULL;
	build(Arr);
}

void _Binary_Tree::build( elementType *Arr )
{
	if(BTree)
	  destroy(BTree);
    if( Arr[0] == '^' )
	{
		BTree = NULL;
		return;
    }
    BTree = new bitNode;
    BTree->leftChild = NULL;
    BTree->rightChild = NULL;
	BTree->data = Arr[0];
    createNode( BTree, Arr, 0 );
}

void _Binary_Tree::createNode( binTree BT, elementType *Arr, int number )
{
	bitNode *tmp = new bitNode;
    if( Arr[ number * 2 + 1 ] != '^' )
	{
		BT->leftChild =new bitNode ;
		tmp = BT->leftChild;
		tmp->data = Arr[ number * 2 + 1 ];
		tmp->leftChild = NULL;
		tmp->rightChild = NULL;
		createNode( tmp, Arr, number * 2 + 1 );
    }
    if( Arr[ number * 2 + 2 ] != '^' )
	{
		BT->rightChild =new bitNode ;
		tmp = BT->rightChild;
		tmp->data = Arr[ number * 2 + 2 ];
		tmp->leftChild = NULL;
		tmp->rightChild = NULL;
		createNode( tmp, Arr, number * 2 + 2 );
    }
}

bool _Binary_Tree::createBinaryTree( binTree &BT, elementType stringLine[100][3], int length, int &row )
{     
	if (row >= length || length == 0 )      //stringLine存数据的二维数组，row结点所在的位数，length结点的个数
		return false;
	if ( row == 0 )
		BT = BTree;
	else
		BT = new bitNode;//new下面是公用的，用if的目的是改变private里BTree里的值
	BT->data = stringLine[row][0];
	BT->leftChild = NULL;
	BT->rightChild = NULL;
	
	int nextRow = row;
	if ( stringLine[nextRow][1] == '1' )
	{
		++ row;
		createBinaryTree( BT->leftChild, stringLine, length, row );
	}
	if ( stringLine[nextRow][2] == '1' )
	{
		++row;
		createBinaryTree( BT->rightChild, stringLine, length, row );
	}
	return true;
}

bool _Binary_Tree::readFileToArray( elementType stringLine[100][3], int &length )
{
	FILE *fp;
	char str[100];
                
	cout << "Please input the file name(belike includes the file path):" << endl;
    char name[50];// = "bt10.btr";
    cin >> name;
	fp = fopen( name, "r" );
	if (!fp)
	{
		cout << "Reading file failed.Error in bool _Binary_Tree::readFileToArray( elementType stringLine[100][3], int &length )!" << endl;
		return false;
	}
	if (fgets(str, 1000, fp) != NULL)
	{
		if (strcmp(str, "BinaryTree\n") != 0)
		{
			cout << "Error!" << endl;
			fclose(fp);
			return false;
		}
	}
	length = 0;
	while (fscanf(fp, "%c %c %c\n", &stringLine[length][0], &stringLine[length][1], &stringLine[length][2]) != EOF)
	{
		length ++;
	}
	fclose(fp);
	return true;
}


bool _Binary_Tree::emptyBinaryTree()
{
	//if(BTree)
		//return BTree->leftChild == NULL && BTree->rightChild == NULL;
	//else
	return BTree == NULL;
}

bool _Binary_Tree::_exit( binTree BT, elementType value )
{
	if(!BT)
		return false;
		//return NULL;
	if( BT->data == value )
		return true;
		//return BT;
	//bitNode *index = _exit( BT->leftChild, value );
	bool flag = _exit( BT->leftChild, value );
	//if(!index)
	if(!flag)
	//_exit( BT->leftChild, value );
		_exit( BT->rightChild, value );
}

binTree _Binary_Tree::getNodePoint()
{
	//if( emptyBinaryTree() )
	//{
		//throw "Empty binary tree!Error in binTree _Binary_Tree::getNodePoint()!\n";
		//return NULL;
	//}
	return (*this).BTree;
}

binTree _Binary_Tree::getNodePoint( binTree BT, elementType value )
{
	/*
	if(!BT)
	{
		return NULL;
	}
	else
	{
		if( BT->data == value )
			return BT;
		else
		{
			bitNode *tmp;
			if( tmp = getNodePoint( BT->leftChild, value ) )
				return tmp;
			if( tmp = getNodePoint( BT->rightChild, value ) )
				return tmp;
			return NULL;
		}
	}
	*/
	if(!BT)
	{
		return NULL;
	}
	else
	{
		if( BT->data == value )
		{
			return  BT;
		}
		//getNodePoint( BT->leftChild, value );
		//getNodePoint( BT->rightChild, value );
		
		bitNode *tmp = getNodePoint( BT->leftChild, value );
		if(!tmp)
		{
			getNodePoint( BT->rightChild, value );
		}
		//follow statement can't be added to the code
		//return tmp;
	}
}

void _Binary_Tree::preOrderTraverse(binTree BT)   
{
	//if( emptyBinaryTree() )
//	{
		//throw "Empty binary tree!Error in void _Binary_Tree::PreOrderTraverse(binTree BT) !\n";
		//return;
	//}
	if (BT)  
	{
	     	cout << BT->data << " ";
			preOrderTraverse(BT->leftChild);
			preOrderTraverse(BT->rightChild);
	}
}

void _Binary_Tree::inOrderTraverse(binTree BT)   
{
	if (BT)   
	{
			inOrderTraverse(BT->leftChild);
	     	cout << BT->data << " ";
			inOrderTraverse(BT->rightChild);
	}
	//return 0;
}

void _Binary_Tree::postOrderTraverse( binTree BT )
{
	if (BT)  
	{
			postOrderTraverse(BT->leftChild);
			postOrderTraverse(BT->rightChild);
			cout << BT->data << " ";
	}
}

void _Binary_Tree::destroy( binTree BT )
{
	if(BT)
	{
		destroy( BT->leftChild );
		destroy( BT->rightChild );
		delete BT;
		BT = NULL;
	}
}

void _Binary_Tree::level( binTree BT, int number )
{

	if(BT)
	{
		level( BT->leftChild, number + 1 );
		///number +=3;
		//cout << number << endl;
		cout << BT->data << " level: " << number << endl;
		
		level( BT->rightChild, number + 1 );
		//number -=2;
	}
	//number --;
}

int _Binary_Tree::height( binTree BT )
{
	if(!BT)
	{
		return 0;
	}
	else
	{
		int i = height( BT->leftChild );
		int j = height( BT->rightChild );
		return i < j ? j + 1 : i + 1;

	}
}

int _Binary_Tree::numberOfBTreeNode( binTree BT )
{
	if(!BT)
		return 0;
	else
	{
		return numberOfBTreeNode( BT->leftChild ) + numberOfBTreeNode( BT->rightChild ) + 1;
	}
}

int _Binary_Tree::numberOfBTreeLeafNode( binTree BT, int &number )
{
	if(!BT)
	{
		return 0;
	}
	else
	{
		if( !BT->leftChild && !BT->rightChild )
			//number += 1;
			number ++;
			//return 1;
		else
		{
			numberOfBTreeLeafNode( BT->leftChild, number );
			numberOfBTreeLeafNode( BT->rightChild, number );
		}
		return number;	
	}
}

void _Binary_Tree::numberOfNodeDegreeTwo( binTree BT, int &number )
{
	if(!BT)
	{
		return;
	}
	else
	{
		if( BT->leftChild && BT->rightChild )
			//number += 1;
			number += 1;
			//return 1;
		//else
		//{
		numberOfNodeDegreeTwo( BT->leftChild, number );
		numberOfNodeDegreeTwo( BT->rightChild, number );
			//return numberOfNodeDegreeTwo( BT->leftChild, number ) + numberOfNodeDegreeTwo( BT->rightChild, number );
		//}
		//return number;	
	}
}

/*
void _Binary_Tree::family( binTree BT, elementType1 number )
{
	if(!BT)
	{
		return;
	}
	if( BT->leftChild->data == number || BT->rightChild->data == number )
	{
		cout << "parent ---- " << BT->data << endl;
		if( BT->leftChild->data == number && BT->rightChild )
		{
			cout << "rights sibling ---- " << BT->rightChild->data << endl;
		}
		if( BT->leftChild && BT->rightChild->data == number )
		{
			cout << "left sibling ---- " << BT->leftChild->data << endl;
		}
	}
	if( BT->data == number && ( BT->leftChild || BT->rightChild ) )
	{
		cout << ( BT->leftChild ? "left child ---- " : true ) << endl;
		cout << ( BT->rightChild ? "right child ---- " : true ) << endl;
	}
	family( BT->leftChild, number );
	family( BT->rightChild, number );
	//if( BT->data == number && BT-)
	//if( BT->leftChild->data == number &&)
}
*/

//bool _Binary_Tree::getParent( binTree BT, elementType number, bool flag )
void _Binary_Tree::getParent( binTree BT, elementType value, bool &flag )
{
	if(!BT)
	{
		//return false;
		return;
	}
	if( ( BT->leftChild && BT->leftChild->data == value ) || ( BT->rightChild ) && ( BT->rightChild->data == value ) )
	{
		flag = true;
		cout << value << " Parent ---- " << BT->data << endl;
		return;
		//return true;
	}
	/*
	if( BT && BT->rightChild->data == number )
	{
		cout << "parent ---- " << BT->data << endl;
		return true;
	}
	*/
	getParent( BT->leftChild, value, flag );
	getParent( BT->rightChild, value, flag );
}	

binTree _Binary_Tree::getParent( binTree BT, elementType value )
{
	
	if( !_exit( BT, value ) )
	{
		cerr << value << " is not in the binary tree!" << endl;
		cerr << "Error in binTree _Binary_Tree::getParent( binTree BT, elementType value )!" << endl;
		return NULL;
	}
	
	if(!BT)
	{
		return NULL;
	}
	if( BT->data == value )
	{
		return BT;
	}
	if( ( BT->leftChild && BT->leftChild->data == value ) || ( BT->rightChild && BT->rightChild->data == value ) )//|| BT->rightChild->data == value )
	{
		return BT;
	}
	bitNode *tmp = getParent( BT->leftChild, value );
	if(!tmp)
	{
		getParent( BT->rightChild, value );
	}
}

void _Binary_Tree::getSibling( binTree BT, elementType value, bool &flag )
{
	if(!BT)
	{
		cout << value << " No LeftSibling!" << endl << value << " No RightSibling!" << endl;
		return;
	}
	if( !flag &&  !BT->leftChild )//|| !BT->rightChild )//write as "if(!BT)" would result error
	{
		
		if( BT->rightChild )
		{
			getSibling( BT->rightChild, value, flag );
			//return;
		}
		else
		{
			//cout << value << " No LeftSibling!" << endl;
			return;
		}
		return;//why would deleting the statement cause error!
	}

	if( !flag && !BT->rightChild )
	{

		if( BT->leftChild )
		{
			getSibling( BT->leftChild, value, flag );
			
		}
		else
		{
			//cout << value << "No LeftSibling!" << endl;
			//cout << value << " No RightSibling!" << endl;
			return;
			
		}	
		return;//why would deleting the statement cause error!
	}
	if( BT->rightChild->data == value )
	{
		if( BT->leftChild )
		{
			flag = true;
			cout << value << " LeftSibling ---- " << BT->leftChild->data << endl;
			return;
		}
		else if( !BT->leftChild )
		{
			cout << value << " No LeftSibling!" << endl;
			return;
		}
		
	}
	if( BT->leftChild->data == value )
	{
		if( BT->rightChild )
		{
			flag = true;
			cout << value << " RightSibling ---- " << BT->rightChild->data << endl;
			return;
		}
		else if( !BT->rightChild )
		{
			cout << value << " No RightSibling!" << endl;
			return;
		}
	}
	getSibling( BT->leftChild, value, flag );
	if( !flag && BT->rightChild )
		getSibling( BT->rightChild, value, flag );
}

void _Binary_Tree::getSibling( binTree BT, elementType value )
{
	bitNode *parent = getParent( BT, value );
	
	if( BT->data == value )
	{
		cout << value << " is the root node,neither left sibling also useless right sibling!" << endl;
		return;
	}
	if( !_exit( BT, value ) )
	{
		cout << value << " is not in the binary-tree!" << endl;
		cerr << "Error in void _Binary_Tree::getSibling( binTree BT, elementType value )!" << endl;
		return;
	}
	if( parent->leftChild && parent->leftChild->data == value )
	{
		if( parent->rightChild )
		{
			cout << value << " RightSibling ---- " << parent->rightChild->data << endl;
			return;
		}
		else
		{
			cout << value << " No RightSibling!" << endl;
			return;
		}
	}
	if( parent->rightChild && parent->rightChild->data == value )
	{
		if( parent->leftChild )
		{
			cout << value << " LeftSibling ---- " << parent->leftChild->data << endl;
			return;
		}
		else
		{
			cout << value << " No LeftSibling!" << endl;
			return;
		}
	}
}

void _Binary_Tree::getChild( binTree BT, elementType value, bool &flag )//It costed me several minutes to   
{																		//write and almost one hour to 
	/*																	//perfect the function
	if( BT->leftChild )
	{
		getChild( BT->leftChild, value, flag );
	}
	if( BT->rightChild )
	{
		getChild( BT->rightChild, value, flag );
	}
	*/
	
	/*
	if( !BT->leftChild )//|| !BT->rightChild )
	{
		if(flag)
		{	
			cout << "No LeftChild! " << endl;
			flag = true;
			return;
		}
		else
		{
			cout << "No LeftChild! " << endl;
			flag = false;
		}
		//return;
	}
	if( !BT->rightChild )
	{
		if(flag)
		{
			cout << "No RightChild! " << endl;
			flag = true;
			return;
		}
		else
		{
			cout << "No RightChild! " << endl;
			flag = false;
		}
	}
	*/
	//if(!BT)
//	{
	//	return;
//	}
	if( !_exit( BT, value ) )
	{
		cerr << value << " is not in the binary tree!\nError in void _Binary_Tree::getChild( binTree BT, elementType value, bool &flag )" << endl;
		return;
	}
	if( BT->data == value )//at first I neglected this detail that resulted wrong judgement at root-node 
	{
		if( BT->leftChild )
		{
			flag = true;
			cout << value << " LeftChild ---- " << BT->leftChild->data << endl;
			
		}
		else
		{
			cout << "No LeftChild!" << endl;

		}
		if( BT->rightChild )
		{
			flag = true;
			cout << value << " RightChild ---- " << BT->rightChild->data << endl;
			return;
		}
		else
		{
			cout << "No RightChild! " << endl;
			return;
		}
	}
	if( !BT->leftChild )
	{
		if( BT->rightChild )
		{
			getChild( BT->rightChild, value, flag );
		}
		return;
		/*
		if(flag)
		{
			return;
		}
		else
		{
			flag = false;
			return;
		}*/
	}
	if( !BT->rightChild )
	{
		if( BT->leftChild )
		{
			getChild( BT->leftChild, value, flag );
		}
		return;
		//if(flag)
		//{
		//	flag = false;	
		//}
		/*
		if(flag)
		{
			return;
		}
		else
		{
			flag = false;
			return;
		}*/
	}
	/*
	if( BT->rightChild->data == value )
	{
		if( BT->rightChild->leftChild )
		{
			flag = true;
			cout << value << " LeftChild ---- " << BT->rightChild->leftChild->data << endl;
			//return;
		}
		else
		{
			cout << "No LeftChild!" << endl;
		}
		if( BT->rightChild->rightChild )
		{
			flag = true;
			cout << value << " RightChild ---- " << BT->rightChild->rightChild->data << endl;
			return;
		}
		else
		{
			cout << "No RightChild! " << endl;
			return;
		}
		//else
		//{
			//flag = false;
		//	return;
		//}
	}
	if( BT->leftChild->data == value )
	{
		if( BT->leftChild->leftChild )
		{
			flag = true;
			cout << value << " LeftChild ---- " << BT->leftChild->leftChild->data << endl;
			//return;
		}
		else
		{
			cout << "No LeftChild!" << endl;
		}
		if( BT->leftChild->rightChild )
		{
			flag = true;
			cout << value << " RightChild ---- " << BT->leftChild->rightChild->data << endl;
			return;
		}
		else
		{
			cout << "No RightChild! " << endl;
			return;
		}
		//else
		//{
			//flag = false;
		//	return;
		//}
	}
	*/
	getChild( BT->leftChild, value, flag );
	getChild( BT->rightChild, value, flag );
}

int _Binary_Tree::levelJudge( binTree BT, elementType value, int &number, int level )
{
	bitNode *position = getNodePoint( getNodePoint(), value );
	if(!position)
	{
		cout << "The value you typed is not in the binary tree!" << endl;
		//return -1;
		number = -1;
		return number;
	}
	/*
	int level;
	if ( BT == NULL )
		return 0;
	else if ( BT->data == value )
		return number;
	else
	{	
		number ++;
		level = levelJudge( BT->leftChild, value, number );	
		if ( level != 0 ) 
			return number;
		else	
		{
			//number ++;
			return levelJudge( BT->rightChild, value, number );
		}
	}
	*/
	if(BT)
	{
		if( BT->data == value )
		{
			//number ++;
			number = level;
		}
		//number ++;
		levelJudge( BT->leftChild, value, number, level + 1 );
		//number ++;
		levelJudge( BT->rightChild, value, number, level + 1);
	}
}

void _Binary_Tree::exchangeLeftAndRightSibling( binTree BT )
{
	if( BT && BT->leftChild && BT->rightChild )
	{
		bitNode *tmp = BT->leftChild;
		BT->leftChild = BT->rightChild;
		BT->rightChild = tmp;
		exchangeLeftAndRightSibling( BT->leftChild );
		exchangeLeftAndRightSibling( BT->rightChild );
	}
}

void _Binary_Tree::copyBTree( binTree BT1, binTree BT )
{
	bitNode *tmp = NULL;//new bitNode;
	BT1->data = BT->data;
	if( BT->leftChild )
	{
		BT1->leftChild = new bitNode;
		tmp = BT1->leftChild;
		tmp->leftChild = NULL;
		tmp->rightChild = NULL;
		copyBTree( tmp, BT->leftChild );
	}
	if( BT->rightChild )
	{
		BT1->rightChild = new bitNode;
		tmp = BT1->rightChild;
		tmp->leftChild = NULL;
		tmp->rightChild = NULL;
		copyBTree( tmp, BT->rightChild );
	}
}

void _Binary_Tree::levelOrderTraverse( binTree BT )
{
	clq.enQueue(BT);
	while( !clq.emptyCharLinkedQueue() )
	{
		//CLNode *tmp = NULL;
		clq.getFront(BT);
		cout << BT->data << " ";
		clq.deQueue();
		if( BT->leftChild != NULL )
		{
			clq.enQueue( BT->leftChild );
		}
		if( BT->rightChild != NULL )
		{
			clq.enQueue( BT->rightChild );
		}
	}
}

void _Binary_Tree::allLeafToRootPath( binTree BT, char *path, int &pathLength )
{
	if(BT)
	{
		if( !BT->leftChild && !BT->rightChild )
		{
			path[pathLength] = BT->data;
			cout << BT->data << " leaf to root path: " << endl;
			for( int i = pathLength; i >= 0; i -- )
			{
				if( i != 0 )
					cout << path[i] << " --> ";
				else
					cout << path[i] << "\n";
			}
			//cout << endl;
		}
		else
		{
			path[ pathLength ++ ] = BT->data;
			allLeafToRootPath( BT->leftChild, path, pathLength );
			allLeafToRootPath( BT->rightChild, path, pathLength );
			pathLength --;
		}
	}
}

void _Binary_Tree::binaryTreeLongestPath( binTree BT, elementType *path, int &pathLength, 
						   elementType *longestPath, int &longestLength )
{
	if(BT)
	{
		if( !BT->leftChild && !BT->rightChild )
		{
			path[pathLength] = BT->data;
			if( pathLength > longestLength)
			{
			//cout << BT->data << " leaf to root path: " << endl;
				//longestPath = pathLength;
				for( int i = pathLength; i >= 0; i -- )
				{
					/*
					if( i != 0 )
						cout << path[i] << " --> ";
					else
						cout << path[i] << "\n";
					*/
					longestPath[i] = path[i];
				}
				longestLength = pathLength;
			}
			//longestLength = pathLength;
			//cout << endl;
		}
		else
		{
			path[ pathLength ++ ] = BT->data;
			binaryTreeLongestPath( BT->leftChild, path, pathLength, longestPath, longestLength );
			binaryTreeLongestPath( BT->rightChild, path, pathLength, longestPath, longestLength );
			pathLength --;
		}
	}
}

binTree _Binary_Tree::nearestAncestor( binTree BT, bitNode *BNode1, bitNode *BNode2 )
{
//	if( !_exit( BT, BNode1->data ) )
	//{
	//	cout << BNode1->data << " is not in the binary tree!" << endl;
	//	return NULL;
	//}
	//if( !_exit( BT, BNode2->data ) )
	//{
	//	cout << BNode2->data << " is not in the binary tree!" << endl;
	//	return NULL;
	//}
	if( !BT || !BNode1 || !BNode2 )
	{
		//cout << "NO ANCESTOR!" << endl;
		return NULL;
	}
	if( BT == BNode1 || BT == BNode2 )
	{
		//cout << BT->data << endl;
		return BT;
	}
	bitNode *left = nearestAncestor( BT->leftChild, BNode1, BNode2 );
	bitNode *right = nearestAncestor( BT->rightChild, BNode1, BNode2 );
	if( left && right )
	{
		//cout << BT->data << endl;
		return BT;
	}
	else if(!left)
	{
		//cout << right->data << endl;
		return right;
	}
	else
	{
		//cout << left->data << endl;
		return left;
	}
}