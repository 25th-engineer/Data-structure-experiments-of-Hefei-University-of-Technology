#include "AVLtree.h"
#include "AVLtree.cpp"

int main()
{
    //std::cout << "Hello World!\n"; 
	ios::sync_with_stdio(false);
	AVLTree<int> AVLBT;
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "Inserting integer values 1 to 26" << std::endl;
	for (int i = 1; i <= 26; i++)
		AVLBT.insert(i);

	cout << "Printing the balance factor of each node: " << std::endl;
	SetConsoleTextAttribute(hConsole, 12);
	AVLBT.printBalance();
	SetConsoleTextAttribute(hConsole, 7);
	cout << "Printing key: " << std::endl;
	SetConsoleTextAttribute(hConsole, 0x0008 | 8);
	AVLBT.inOrderTraverse();
	AVLBT.display();
	//AVLTree<int> *root = avl.getRootNode();
	while (1)
	{
		SetConsoleTextAttribute(hConsole, 7);
		cout << "\n---------------------" << endl;
		cout << "AVL tree implementation" << endl;
		cout << "By Utah Xef developed" << endl;
		cout << "\n---------------------" << endl;
		cout << "1.insert element into the tree" << endl;
		cout << "2.display balanced AVL tree" << endl;
		cout << "3.preorder traversal" << endl;
		cout << "4.inorder traversal" << endl;
		cout << "5.postorder traversal" << endl;
		cout << "6.delete key" << endl;
		cout << "7.display the balance factor of each node" << endl;
		cout << "8.exit" << endl;
		cout << "enter your choice: ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "enter value to be inserted: ";
			int item;
			cin >> item;
			AVLBT.insert(item);
			break;
		case 2:
			if (AVLBT.getRootNode() == nullptr)
			{
				cout << "tree is empty" << endl;
				continue;
			}
			cout << "balanced avl tree:" << endl;
			AVLBT.display();
			break;
		case 3:
			cout << "preorder traversal:" << endl;
			SetConsoleTextAttribute(hConsole, 0x0008 | 9);
			AVLBT.preOrderTraverse();
			cout << endl;
			break;
		case 4:
			cout << "inorder traversal:" << endl;
			SetConsoleTextAttribute(hConsole, 0x0008 | 10);
			AVLBT.inOrderTraverse();
			cout << endl;
			break;
		case 5:
			cout << "postorder traversal:" << endl;
			SetConsoleTextAttribute(hConsole, 0x0008 | 11);
			AVLBT.postOrderTraverse();
			cout << endl;
			break;
		case 6:
			int value;
			cout << "Please input the value to delete:" << endl;
			cin >> value;
			AVLBT.deleteKey(value);
			break;
		case 7:
			cout << "The balance factor of each node:" << endl;
			SetConsoleTextAttribute(hConsole, 0x0008 | 14);
			AVLBT.printBalance();
			break;
		case 8:
			exit(1);
			break;
		default:
			cout << "Wrong choice" << endl;
			break;
		}

	}
	//std::cout << std::endl;
	std::cin.get();
}

