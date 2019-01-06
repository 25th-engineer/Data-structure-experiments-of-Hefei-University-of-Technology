// SeqStack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SeqStack1.h"
#include <iostream>

using namespace std;
int main(int argc, char* argv[])
{
	SeqStack ss1;
	ss1.push(0);
	charSeqStack css1, css2;
	char Str[] = "#2+5*(2+3)*6/2-4#";
	//12+5*£¨2+3£©*6/2-4
	//char Str[] = "#(1+(5-3)*2+9)/2#";
	//char Str[] = "#(1+2)*3#";
	//char Str[] = "#(1)#";
	//char Str[] = "#1*2+3#";
	//char Str[] = "#1+1#";
	//char Str[] = "#1#";
	for( int i = 0; Str[i] != '\0'; i ++ )
		css2.push( Str[i] );

	cout << "Start Calculation." << endl;
	cout << "expression:" << css2 << endl;
	ss1.calculate( css1, css2 );
	cout << "Calculation Done!" << endl;

	double x;
	if( ss1.getTop(x) )
		cout << x << endl;
	cin.get();
	return 0;
}
