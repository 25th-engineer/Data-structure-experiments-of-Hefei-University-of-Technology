// _Tree_Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SeqList.h"
#include "SeqList.cpp"

void test1()
{
	
	ios::sync_with_stdio(false);
	HANDLE hOut; 
    //  获取输出流的句柄
    hOut = GetStdHandle(STD_OUTPUT_HANDLE); 
	SetConsoleTextAttribute(hOut, 8 | 7 );
	cout << "Please input the size of the origin random-value array:" << endl;
	//SeqList<int> SL1( 10000, 1 );
	int number;
	cin >> number;
	SeqList<int> SL1( number );

	//freopen( "x1.out", "w", stdout );

	SetConsoleTextAttribute(hOut, 128 | 8 | 2 );
	cout << "The origin sequence array is as follow:" << endl;

	SetConsoleTextAttribute(hOut, 128 | 8 | 1 );
	SL1.display();

	SetConsoleTextAttribute(hOut, 128 | 8 | 2 );
	cout << "After sorted:" << endl;
	//int y = SL1.getArrayLength() - 1;
	//int x = 0;
	int *index = SL1.getArray();
	SL1.treeSelectSort( index, SL1.getArrayLength() );
	
	SetConsoleTextAttribute(hOut, 128 | 8 | 4 );
	SL1.display();

	SetConsoleTextAttribute(hOut, 8 | 5 );

	//SL1.showSwapingAndComparingTimesAndArrayLength();
	SL1.judgeIncreasingSequence();
	//SetConsoleTextAttribute(hOut, 128 | 8 | 2 );
	SetConsoleTextAttribute(hOut, 128 | 8 | 2 );
}

void test2()
{
	ios::sync_with_stdio(false);
	HANDLE hOut; 
    //  获取输出流的句柄
    hOut = GetStdHandle(STD_OUTPUT_HANDLE); 
	SetConsoleTextAttribute(hOut, 8 | 7 );
	cout << "Please input the size of the origin decreasing array:" << endl;
	//SeqList<int> SL1( 10000, 1 );
	int number;
	cin >> number;
	SeqList<int> SL1( number, 1 );

	SetConsoleTextAttribute(hOut, 128 | 8 | 2 );
	cout << "The origin sequence array is as follow:" << endl;

	SetConsoleTextAttribute(hOut, 128 | 8 | 1 );
	SL1.display();

	SetConsoleTextAttribute(hOut, 128 | 8 | 2 );
	cout << "After sorted:" << endl;
	//int y = SL1.getArrayLength() - 1;
	//int x = 0;
	SL1.treeSelectSort( SL1.getArray(), SL1.getArrayLength() );
	
	SetConsoleTextAttribute(hOut, 128 | 8 | 4 );
	SL1.display();

	SetConsoleTextAttribute(hOut, 8 | 5 );

	//SL1.showSwapingAndComparingTimesAndArrayLength();
	SL1.judgeIncreasingSequence();
	//SetConsoleTextAttribute(hOut, 128 | 8 | 2 );
	SetConsoleTextAttribute(hOut, 128 | 8 | 2 );
}

void test3()
{
	ios::sync_with_stdio(false);
	HANDLE hOut; 
    //  获取输出流的句柄
    hOut = GetStdHandle(STD_OUTPUT_HANDLE); 
	SetConsoleTextAttribute(hOut, 8 | 7 );
	cout << "Please input the size of the origin increasing array:" << endl;
	//SeqList<int> SL1( 10000, 1 );
	int number;
	cin >> number;
	SeqList<int> SL1( number, '@' );

	SetConsoleTextAttribute(hOut, 128 | 8 | 2 );
	cout << "The origin sequence array is as follow:" << endl;

	SetConsoleTextAttribute(hOut, 128 | 8 | 1 );
	SL1.display();

	SetConsoleTextAttribute(hOut, 128 | 8 | 2 );
	cout << "After sorted:" << endl;
	//int y = SL1.getArrayLength() - 1;
	//int x = 0;
	SL1.treeSelectSort( SL1.getArray(), SL1.getArrayLength() );
	
	SetConsoleTextAttribute(hOut, 128 | 8 | 4 );
	SL1.display();

	SetConsoleTextAttribute(hOut, 8 | 5 );

	//SL1.showSwapingAndComparingTimesAndArrayLength();
	SL1.judgeIncreasingSequence();
	//SetConsoleTextAttribute(hOut, 128 | 8 | 2 );
	SetConsoleTextAttribute(hOut, 128 | 8 | 2 );
}

void test4()
{
	ios::sync_with_stdio(false);
	//freopen( "x4.in", "r", stdin );
	HANDLE hOut; 
    //  获取输出流的句柄
    hOut = GetStdHandle(STD_OUTPUT_HANDLE); 
	
	//SetConsoleTextAttribute(hOut, 8 | 7 );
	cout << "Please input the size of the origin array:" << endl;
	//SeqList<int> SL1( 10000, 1 );
	int number;
	cin >> number;
	SeqList<int> SL1( number, 1.0 );
	//SL1.readDataFromFile();

	SetConsoleTextAttribute(hOut, 128 | 8 | 2 );
	cout << "The origin sequence array is as follow:" << endl;

	SetConsoleTextAttribute(hOut, 128 | 8 | 1 );
	SL1.display();

	SetConsoleTextAttribute(hOut, 128 | 8 | 2 );
	cout << "After sorted:" << endl;
	//int y = SL1.getArrayLength() - 1;
	//int x = 0;
	SL1.treeSelectSort( SL1.getArray(), SL1.getArrayLength() );
	
	SetConsoleTextAttribute(hOut, 128 | 8 | 4 );
	SL1.display();

	SetConsoleTextAttribute(hOut, 8 | 5 );

	//SL1.showSwapingAndComparingTimesAndArrayLength();
	SL1.judgeIncreasingSequence();
	//SetConsoleTextAttribute(hOut, 128 | 8 | 2 );
	SetConsoleTextAttribute(hOut, 128 | 8 | 2 );
}

void test()
{
	ios::sync_with_stdio(false);
	HANDLE hOut; 
    //  获取输出流的句柄
    hOut = GetStdHandle(STD_OUTPUT_HANDLE); 
	int choose;//, times = 0;
	//char choose;
	//string choose;
	while(1)
	{
		SetConsoleTextAttribute(hOut, 8 | 7 );
		cout << "Please input one number to select the mode:" << endl;
		cout << "1 for generating an origin random-value array sequence." << endl;
		cout << "2 for generating an origin decreasing array sequence." << endl;
		cout << "3 for generating an origin increasing array sequence." << endl;
		//cout << "4 for reading a file from the disk to generate an origin array sequence." << endl;
		cout << "4 for keyboard typing to generate an origin array sequence." << endl;
		cout << "5 to clear the screen." << endl;
		cout << "0 for exit." << endl;
		cin >> choose;
		
		switch(choose)
		{
		case 1:
			test1();
			break;
		case 2:
			test2();
			break;
		case 3:
			test3();
			break;
		case 4:
			test4();
			break;
		case 5:
			system( "cls" );
			break;
		case 0:
			return;
		default:
			SetConsoleTextAttribute(hOut, 8 | 6 );
			cout << "You made a wrong input,please check and input again!" << endl;
			SetConsoleTextAttribute(hOut, 8 | 7 );
			break;
		}
	}
}

int main(int argc, char* argv[])
{
	
	HANDLE hOut; 
    //  获取输出流的句柄
    hOut = GetStdHandle(STD_OUTPUT_HANDLE); 
	test();
	//test1();
	system( "cls" );
	printf( "Bye!\n" ); 
	Sleep( 1000 * 5 );
	SetConsoleTextAttribute(hOut, 8 | 7 );
	return 0;
}
