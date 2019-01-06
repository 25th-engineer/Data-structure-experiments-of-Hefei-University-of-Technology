// _LinkedStack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "linkedStack.h"

/*
void test()
{
	ios::sync_with_stdio(false);
	//freopen( "x1.in", "r", stdin );
	FILE *fp = fopen( "x1.in", "r" );
	//cout << "werfe" << endl;
	linkedStack LS1;
	charLinkedStack CLS1, CLS2;
	for( int i = 1; i <= 113; i ++ )
	{
		//LS1.push(i);
	}
	//cout << LS1 << endl;
	//LS1.displayStack();

	for( int j = 0; j <= 26; j ++ )
	{
		//CLS1.push( (char)( 'A' + j ) );
	}
	/*
	char Str[] = "#12+5*(2+3)*6/2-4#";
	LS1.calculate(Str);
	cout << LS1;
	ll n;
	//while( cin >> n )
	{
		cin >> n;
		CLS1.decToHex(n);
		cout << CLS1;
		//CLS1.~charLinkedStack();
	}
	
	char Str2[1000];
	while(1)
	{
		gets(Str2);
		if(CLS2.brancheMatch(Str2) )
			cout << "YES!" << endl;
		else
			cout << "NO!" << endl;
	}
	//cout << CLS1;
	//cout << LS1.length() << endl;
	//int x;
	//LS1.getTop(x);
	//cout << x << endl;
	//LS1.pop();
	//LS1.getTop(x);
	//cout << endl;
	cin.get();
}
*/

int main(int argc, char* argv[])
{
	/*
	while(1)
	{
		test();
	}
	
	ios::sync_with_stdio(false);
	//freopen( "x1.in", "r", stdin );
	
	//freopen( "x1.out", "w", stdout );
	*/
	//FILE *fp = fopen( "x1.in", "r" );
	/*
	//cout << "werfe" << endl;
	linkedStack LS1;
	charLinkedStack CLS1, CLS2;
	//for( int i = 1; i <= 113; i ++ )
	//{
		//LS1.push(i);
	//}
	//cout << LS1 << endl;
	//LS1.displayStack();

	//for( int j = 0; j <= 26; j ++ )
//	{
		//CLS1.push( (char)( 'A' + j ) );
//	}
	
	linkedStack LS1;
	char Str[] = "#12+5*(2+3)*6/2-4#", Str2[] = "#34456%3+100*5+3-100#";
	LS1.calculate(Str);
	for( int i = 1;  Str[i] != '#' && i < strlen(Str); i++ )
		cout << Str[i];
	cout << " = " << LS1;
	LS1.pop();
	LS1.calculate(Str2);
	for( i = 1;  Str2[i] != '#' && i < strlen(Str2); i++ )
		cout << Str2[i];
	cout << " = " << LS1;
	
	charLinkedStack CLS1;
	ll n;
	while( cin >> n )
	{
		//cin >> n;
		CLS1.decToHex(n);
		cout << CLS1;
		while( !CLS1.stackEmpty() )
			CLS1.pop();
		//CLS1.~charLinkedStack();
	}
	
	charLinkedStack CLS2;
	char Str2[1000];
	while( fgets( Str2, 1000, fp ) != NULL )
	{
		//gets(Str2);
		if( CLS2.brancheMatch(Str2) )
			cout << Str2 << " ---> legal!" << endl;
		else
			cout << Str2 << " ---> illegal!" << endl;
	}
	
	linkedStack LS2;
	
	for( int i = 1; i <= 10; i ++ )
	{
		LS2.push(i);
	}
	
	LS2.push(1.0);
	LS2.push(4.0);
	LS2.push(2.0);
	LS2.push(3.0);
	
	cout << LS2 << endl;
	if( LS2.isPopOrder() )
		cout << " --- legal" <<endl;
	else
		cout << " --- illegal" << endl;
	
	linkedStack LS3;
	elementType Arr1[] = { 1, 2, 3, 4 }, Arr2[5];//, Arr2[] = { 1, 4, 2, 3 };
	//elementType Arr1[100], Arr2[100];

	int cnt = 0;
	
	while( cnt ++ < 24 )
	{
		//if( LS3.judgeIsLegal( Arr1, Arr2 ) )
		for( int i = 0; i < 5; i ++ )
			cin >> Arr2[i];
		if( LS3.judge( Arr1, 5, Arr2, 5 ) )
		{
			cout << setw(2) << cnt << " : ";
			for( int j = 0; j < 4; j ++ )
				cout << Arr2[j] << " ";
			cout << " ---> legal!" << endl;
		}
		else
		{
			//cout << cnt << " ---> NO!" << endl;
			cout << setw(2) << cnt << " : ";
			for( int j = 0; j < 4; j ++ )
				cout << Arr2[j] << " ";
			cout << " ---> illegal!" << endl;
		}
	}

	*/
	linkedStack  LS5;
	elementType A[8];
	cout << "The valid out-of-stack sequences of 1 to 7 are:" << endl;
	LS5.printValidPopStackSequence( 5, A, 0 );

	
	/*
	charLinkedStack ss;
	char Str[4];
	int cnt = 0;
	while( cnt ++ < 24 )
	{
		gets(Str);
		cout << cnt << " : " << Str << " --- " << ss.judge( "abcd",Str ) << endl;
	}
	*/
	cin.get();
	return 0;
}
