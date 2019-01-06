// The_Story_Of_Three.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SeqList.h"
#include "SeqList.cpp"

void test1()
{
	SeqList<int> SL1(26);
	SL1.display();
	SL1.partition( 0, SL1.getArrayLength() - 1 );
	SL1.display();
	SL1.showSwapingAndComparingTimesAndArrayLength();
}

void test2()
{
	freopen( "x1.in", "r", stdin );
	SeqList<int> SL1( 27, 1.0 );
	SL1.display();
	SL1.partition( 0, SL1.getArrayLength() - 1 );
	SL1.display();
	SL1.showSwapingAndComparingTimesAndArrayLength();
}

void test3()
{
	freopen( "x2.in", "r", stdin );
	SeqList<int> SL1( 26, 1.0 );
	SL1.display();
	SL1.partition( 0, SL1.getArrayLength() - 1 );
	SL1.display();
	SL1.showSwapingAndComparingTimesAndArrayLength();
}

void test4()
{
	int length;
	cin >> length;
	SeqList<int> SL1(length);
	//SL1.display();
	SL1.partition( 0, SL1.getArrayLength() - 1 );
	//SL1.display();
	SL1.showSwapingAndComparingTimesAndArrayLength();
}

int main(int argc, char* argv[])
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}
