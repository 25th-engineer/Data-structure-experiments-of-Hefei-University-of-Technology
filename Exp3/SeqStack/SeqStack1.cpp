// SeqStack1.cpp: implementation of the SeqStack class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SeqStack1.h"
#include <iostream>
#include <iomanip>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
using namespace std;
SeqStack::SeqStack()
{
	top = -1;
}

SeqStack::~SeqStack()
{	
}

bool SeqStack::stackEmpty()
{
	return top == -1;
}

bool SeqStack::stackFull()
{
	return top == maxLength - 1;
}

bool SeqStack::getTop( elementType& value )
{
	if( stackEmpty() )
	{
		cout << "???ив????????ив" << endl;
		return false;
	}
	value = data[top];
	return true;
}

bool SeqStack::push( elementType value )
{
	if( stackFull() )
	{
		cout << "?и▓ив????ив" << endl;
		return false;
	}
	top ++;
	data[top] = value;
	return true;
}

bool SeqStack::pop()
{
	if( stackEmpty() )
	{
		cout << "??ив????ив" << endl;
		return false;
	}
	top --;
	return true;
}

int SeqStack::length()
{
	if( stackEmpty() )
	{
		cout << "??ив" << endl;
		return -1;
	}
	return top + 1;
}

void SeqStack::displayStack()
{
	if( stackEmpty() )
	{
		cout << "??ив????ив" << endl;
		return;
	}
	int column = 0;
	for( int i = 0; i <= top; i ++ )
	{
		cout << setw(6) << setiosflags( ios::left ) << data[i];
		column ++;
		if( column % 10 == 0 )
			cout << endl;
	}
}

int SeqStack::isp( char _operator )
{
	switch(_operator)
	{
	case '#' :
		return 0;
		break;
	case '(':
		return 6;
		break;
	case '*':
		return 5;
		break;
	case '/':
		return 5;
		break;
	case '+':
		return 3;
		break;
	case '-':
		return 3;
		break;
	case ')':
		return 1;
		break;
	}

	cerr << "Error in SeqStack::isp" << endl;
	return -1;
}

int SeqStack::icp( char _operator )
{
	switch(_operator)
	{
	case '#' :
		return 0;
		break;
	case '(':
		return 1;
		break;
	case '*':
		return 4;
		break;
	case '/':
		return 4;
		break;
	case '+':
		return 2;
		break;
	case '-':
		return 2;
		break;
	case ')':
		return 6;
		break;
	}

	cerr << "Error in SeqStack::icp" << endl;
	return -1;
}

double SeqStack::doOperator( elementType value1, elementType value2, elementType1 _operator )
{
	switch(_operator)
	{
	case '+':
		return value1 + value2;
		break;
	case '-':
		return value1 - value2;
		break;
	case '*':
		return value1 * value2;
		break;
	case '/':
		if( fabs(value2) < 0.0001 )
		{
			cout << "Divided by 0!" << endl;
			return -1000000;
		}
		else
			return value1 / value2;
		break;
	}

	cerr << "Error in SeqStack::doOperator" << endl;
	return -1;
}

void SeqStack::calculate( charSeqStack& css1, charSeqStack& css2 )//?????? css2 ?им????????? css1 ?
{
	char ch, ch1;
	int i = 0, j = 0;
	double a, b;
	css2.pop();
	css2.getTop(ch);
	css2.pop();
	
	// when the top of css2 is not '#' or the top of css is not empty.
	while( css1.topValue() != -1 || ch != '#' )
	{
		// when the top of css2 is a number, put it into ss1
		if( isdigit(ch) )
		{
			push( (int)( ch - '0' ) );
			css2.getTop(ch);
			css2.pop();
		}

		// when the top of css2 is not a number,
		else
		{
			css1.getTop(ch1);
			if (ch1 == ')' && ch == '(')
			{
				css1.pop();
				css2.getTop(ch);
				css2.pop();
				continue;
			}
			if( isp(ch1) < icp(ch) )
			{
				css1.push(ch);
				css2.getTop(ch);
				css2.pop();
			}
			else if( isp(ch1) >= icp(ch) )
			{
				getTop(a);
				pop();
				getTop(b);
				pop();
				push( doOperator( a, b, ch1 ) );
				css1.pop();
			}			
		}

	}
 	
}