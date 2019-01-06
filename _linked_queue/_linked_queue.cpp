// _linked_queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "charLinkedQueue.h"
#include "linkedQueue.h"

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false);
	//srand( time(NULL) );
	linkedQueue LQ1;
	/*
	charLinkedQueue CLQ1;
	
	//if( CLQ1.emptyCharLinkedQueue() )
		//cout << "The queue is empty!" << endl;
	elementType1 value;
	while( cin >> value )
	//while( ~scanf( "%c", &value ) && value != '#' )
	//cin >> value;
	//scanf( "%c", &value );
	{
		if( isdigit(value) || isalpha(value) )
		{
			cout << value << " will be added to the end of the queue" << endl;
			CLQ1.enQueue(value);
			cout << "The current queue is as follow:" << endl << CLQ1;
			cout << "The current length of the queue is " << CLQ1.length() << endl;
		}
			
		if( value == '#' )
			break;
	}
	
	if( LQ1.emptyLinkedQueue() )
		cout << "The queue is empty!" << endl;
	elementType value;
	while( cin >> value )
	{
		if( (char)value != '#' )
		{
			cout << value << " will be added to the end of the queue" << endl;
			LQ1.enQueue(value);
			cout << "The current queue is as follow:" << endl << LQ1;
			cout << "The current length of the queue is " << LQ1.length() << endl;
		}
		else
			break;
	}
	
	cout << "The current length of the queue is " << LQ1.length() << endl;
	*/
	for( int i = 1; i <= 10; i ++ )
		LQ1.enQueue(i);
	cout << "The origin queue is as follow:" << endl << LQ1;
	cout << "The current length of the queue is " << LQ1.length() << endl;
	/*
	for( int j = 0; j < 10; j ++ )
	{
		int value;
		int key = rand() % 3 + 1;
		//cout << key << " ";
		if( key == 1 )//get the queue-front data
		{
			LQ1.getFront(value);
			cout << "The data of queue-front = " << value << endl;
		}
		else if( key == 2 )//delete the queue-front data
		{
			LQ1.deQueue(value);
			cout << value << " has been deleted from the queue!" << endl;
			cout << "The current queue is as follow:" << endl << LQ1;
			cout << "The current length of the queue is " << LQ1.length() << endl;
		}
		else//add data to the end of the queue
		{
			value = rand() % 100 + 2;
			cout << value << " will be added to the end of the queue" << endl;
			LQ1.enQueue(value);
			cout << "The current queue is as follow:" << endl << LQ1;
			cout << "The current length of the queue is " << LQ1.length() << endl;
		}
	
	}
	*/

	
	for( int j = 1; j <= 10; j ++ )
	{
		elementType value = rand() % 100 + 2;
		cout << "The current value = " << value << endl;
		LQ1.oddOrEven(value);
	}
	LQ1.oddOrEven(0);
	/**/
	/*
	if( CSCQ1.emptyCharSeqCircleQueue() )
		cout << "Empty!" << endl;

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
