// SeqStack1.cpp: implementation of the SeqStack class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SeqStack.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

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
		cout << "Õ»¿Õ£¡·ÃÎÊÕ»¶¥ÔªËØÊ§°Ü£¡" << endl;
		return false;
	}
	value = data[top];
	return true;
}

bool SeqStack::push( elementType value )
{
	if( stackFull() )
	{
		cout << "Õ»Âú£¡Ñ¹Õ»Ê§°Ü£¡" << endl;
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
		cout << "Õ»¿Õ£¡µ¯Õ»Ê§°Ü£¡" << endl;
		return false;
	}
	top --;
	return true;
}

int SeqStack::length()
{
	if( stackEmpty() )
	{
		cout << "Õ»¿Õ£¡" << endl;
		return -1;
	}
	return top + 1;
}

void SeqStack::displayStack()
{
	if( stackEmpty() )
	{
		cout << "Õ»¿Õ£¡ÎÞ·¨´òÓ¡£¡" << endl;
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
	case '%':
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
	case '%':
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
	case '%':
		if( fabs(value2) < 0.0001 )
		{
			cout << "Divided by 0!" << endl;
			return -1000000;
		}
		else
			return (int)value1 % (int)value2;
		break;
		
	}

	cerr << "Error in SeqStack::doOperator" << endl;
	return -1;
}

void SeqStack::calculate( char* Str )
{
	charSeqStack css1;
	char ch1;
	int i = 0;
	double a, b;
	
	int level = 0;
	int temp = 0;
 
	while ( Str[i] != '\0' )
	{
		i ++;
	}
	i = i - 2;
	while( css1.topValue() != -1 || Str[i] != '#' )
	{
		char ch = Str[i];
		if ( isdigit(ch) )
		{
			temp = temp + pow( 10, level ) * int( ch - '0' );
			level ++;
			i --;
		}
		else
		{
			if (level)
			{
				push(temp);
				temp = 0;
				level = 0;
			}
			css1.getTop(ch1);
			if ( ch1 == ')' && ch == '(' )
			{
				css1.pop();
				i --;
				continue;
			}
			if ( isp(ch1) < icp(ch) )
			{
				css1.push(ch);
				i --;
			}
			else if (isp(ch1) >= icp(ch))
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

	if (level)
	{
		push(temp);
	}
 	
}