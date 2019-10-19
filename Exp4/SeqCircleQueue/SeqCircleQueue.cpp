// SeqCircleQueue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "_SeqCircleQueue.h"
#include "charSeqCircleQueue.h"
//#include <windows.h>

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false);
	srand( time(NULL) );
	_SeqCircleQueue SCQ1;
	//charSeqCircleQueue CSCQ1;
	//if( SCQ1.emptySeqCircleQueue() )
		//cout << "Empty!" << endl;
	for( int i = 1; i <= 10; i ++ )
		SCQ1.enQueue(i);
	cout << "The origin queue is as follow:" << endl << SCQ1;
	for( int j = 1; j <= 5; j ++ )
	{
		elementType value = rand() % 100 + 2;
		SCQ1.oddOrEven(value);
	}
	SCQ1.oddOrEven(0);
	/*
	if( CSCQ1.emptyCharSeqCircleQueue() )
		cout << "Empty!" << endl;
	//a,b,c,d,f,g
	CSCQ1.enQueue('a');
	CSCQ1.enQueue('b');
	CSCQ1.enQueue('c');
	CSCQ1.enQueue('d');
	CSCQ1.enQueue('f');
	CSCQ1.enQueue('g');
	cout << CSCQ1.length() << endl;
	cout << CSCQ1;
	
	SCQ1.enQueue(4);//4£¬7£¬8£¬12£¬20£¬50
	SCQ1.enQueue(7);
	SCQ1.enQueue(8);
	SCQ1.enQueue(12);
	SCQ1.enQueue(50);
	cout << SCQ1.length() << endl;
	cout << SCQ1;
	
	elementType x;
	if( SCQ1.deQueue(x) )
	{
		cout << x << endl;
	}
	cout << SCQ1;
	if( SCQ1.getFront(x) )
		cout << x << endl;
	cout << SCQ1.length() << endl;
	
	if( SCQ1.fullSeqCircleQueue() )
		cout << "Full!" << endl;
	*/
	cin.get();
	//Sleep( 1000 * 120 );
	return 0;
}
