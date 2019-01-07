// charSeqStack.cpp: implementation of the charSeqStack class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "charSeqStack.h"
#include <iostream>
#include <iomanip>

using namespace std;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

charSeqStack::charSeqStack()
{
	top = -1;
}

charSeqStack::~charSeqStack()
{

}

bool charSeqStack::stackEmpty()
{
	return top == -1;
}

bool charSeqStack::stackFull()
{
	return top == maxLength - 1;
}

bool charSeqStack::getTop( elementType1& value )
{
	if( stackEmpty() )
	{
		value = '#';
		cout << "???ив????????ив" << endl;
		return false;
	}
	value = data[top];
	return true;
}

bool charSeqStack::push( elementType1 value )
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

bool charSeqStack::pop()
{
	if( stackEmpty() )
	{
		cout << "??ив????ив" << endl;
		return false;
	}
	top --;
	return true;
}

int charSeqStack::length()
{
	if( stackEmpty() )
	{
		cout << "??ив" << endl;
		return -1;
	}
	return top + 1;
}

void charSeqStack::displayStack()
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

int charSeqStack::topValue()
{
	return top;
}
