// charSeqStack.h: interface for the charSeqStack class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHARSEQSTACK_H__A9958AD3_333A_41B4_B399_B6895C7AA8C5__INCLUDED_)
#define AFX_CHARSEQSTACK_H__A9958AD3_333A_41B4_B399_B6895C7AA8C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//#include "stdafx.h"

typedef char elementType1;
typedef long ll;
const int maxLength = 1000 + 13;

class charSeqStack  
{
public:
	charSeqStack();
	virtual ~charSeqStack();
	bool stackEmpty();
	bool stackFull();
	bool getTop( elementType1& value );
	bool push( elementType1 value );
	bool pop();
	int length();
	int topValue();
	void displayStack();
	void baseTransform( ll value );
	bool brancheMatch( char *Str );
	friend ostream &operator<< (ostream &os, const charSeqStack &a)
	{
		for (int i = a.top; i >= 0; i -- )
		{
			if (a.top == -1)
				return os;
			os << a.data[i];
		}

		return os;
	}

private:
	elementType1 data[maxLength];
	int top;
};


#endif // !defined(AFX_CHARSEQSTACK_H__A9958AD3_333A_41B4_B399_B6895C7AA8C5__INCLUDED_)
