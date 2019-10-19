// linkedStack.h: interface for the linkedStack class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINKEDSTACK_H__54B665DE_2CE8_4329_AED9_95FEAAAAE128__INCLUDED_)
#define AFX_LINKEDSTACK_H__54B665DE_2CE8_4329_AED9_95FEAAAAE128__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "charLinkedStack.h"

class linkedStack  
{
public:
	linkedStack();
	virtual ~linkedStack();
	bool stackEmpty();
	//bool stackFull();
	bool getTop( elementType& value );
	bool push( elementType value );
	bool pop();
	int length();
	void displayStack();
	int isp( char  _operator );//栈内优先级
	int icp( char _operator );//栈外优先级
	double doOperator( elementType value1, elementType value2, char _operator );
	void calculate( char* Str );
	charLinkedStack cls;
	bool isPopOrder();
	bool judge(const elementType *sour, int s1, const elementType *dest, int s2 );
	void linkedStack::printValidPopStackSequence( int n, elementType *A, int cur );
	friend ostream &operator<< ( ostream &os, const linkedStack &a )
	{
		//for ( int i = 0; i < a.top + 1; i ++ )
		//{
		//	if (a.top == -1)
		//		return os;
		//	os << a.data[i];
		//}
		LStack *tmp = a.top;
		int column = 0;
		while( tmp->link )
		{
			//cout << tmp->data << " ";
			if( tmp->link == NULL )
				return os;
				//break;
			//os << tmp->data << " ";
			os << setw(7) << setiosflags(ios::left) << tmp->data << " ";
			column ++;
			if( column % 10 == 0 )
				os << setw(7) << setiosflags(ios::left) << endl;
			tmp = tmp->link;
		}
		os << endl;

		return os;
	}
private:
	LStack *top;
	int len;
};

#endif // !defined(AFX_LINKEDSTACK_H__54B665DE_2CE8_4329_AED9_95FEAAAAE128__INCLUDED_)
