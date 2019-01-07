// SeqStack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SeqStack.h"


int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false);
	FILE *fp = fopen( "x1.in", "r" );
	/*
	SeqStack ss1, ss2;
	charSeqStack css1, css2;
	ss1.push(0);
	char Str[] = "#222+555*(777+111)*666/888-999/333+444+(347)#";
	//char Str[] = "#12+5*(2+3)*6/2-4#";
	char Str1[] = "#9%3#";
	cout << 222+555*(777+111)*666/888-999/333+444+(347) << endl;
	for ( int i = 0; Str[i] != '\0'; i ++ )
	{
		if( Str[i] != '#' )
			//cout << Str[i];
			css1.push( Str[i] );
	}
	//cout << endl;

	//cout << "Start Calculation:200+500*(200+300)*600/200-400" << endl;
	cout << "Start Calculation:" << css1 << endl;
	ss1.calculate(Str);

	double x;
	if( ss1.getTop(x) )
		//cout << x << endl;
	//cin.get();
	cout << css1 << " = " << x << ",Calculation Done!" << endl;
	
	for (int j = 0; Str1[j] != '\0'; j ++ )
	{
		if( Str1[j] != '#' )
			//cout << Str1[j];
			css2.push( Str1[j] );
	}
	cout << endl;

	//cout << "Start Calculation:12+5*(2+3)*6/2-4" << endl;
	cout << "Start Calculation:" << css2 << endl;
	ss2.calculate(Str1);

	
	if( ss2.getTop(x) )
		//cout << x << endl;
		//cout << "12+5*(2+3)*6/2-4 = " << x << ",Calculation Done!" << endl;
		cout << css2 << " = " << x << ",Calculation Done!" << endl;
	

	charSeqStack css3;
	//css3.transfor(4);
	
	elementType _value;
	while( cin >> _value )
	{
		css3.baseTransform(_value);
		cout << css3;
		while( !css3.stackEmpty() )
		{	
			css3.pop();
		}
		cout << endl;
	}
	//css3.displayStack();
	*/
	charSeqStack css4;
	char Str[1000]; //= "{[()]}"; //= "(1+1)[]{}{";
	
	//int i = 0;
	//while( Str[ i ++ ] != '\0' )
	//{
	//	css4.push(Str[i]);
	//}
	
	while( fgets( Str, 100, fp ) != NULL )
	{
		//gets(Str);
		//cin >> Str;
		if( css4.brancheMatch(Str) )
			cout << Str << " ---- legal!" << endl;
		else
			cout << Str << " ---- illegal!" << endl;
	}
	
	cin.get();
	//cout << "The screen will be closed in 2 minutes" << endl;
	//Sleep( 1000 *120 );
	return 0;
}
