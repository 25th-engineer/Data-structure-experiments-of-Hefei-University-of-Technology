// SeqStack1.h: interface for the SeqStack class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SEQSTACK1_H__55EE245C_A5F8_47D4_9510_B3BA6C85FF63__INCLUDED_)
#define AFX_SEQSTACK1_H__55EE245C_A5F8_47D4_9510_B3BA6C85FF63__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "charSeqStack.h"

typedef double elementType;
class SeqStack  
{
public:
	SeqStack();
	virtual ~SeqStack();
	bool stackEmpty();
	bool stackFull();
	bool getTop( elementType& value );
	bool push( elementType value );
	bool pop();
	int length();
	void displayStack();
	int isp( elementType1 _operator );//栈内优先级
	int icp( elementType1 _operator );//栈外优先级
	charSeqStack css;
	double doOperator( elementType value1, elementType value2, elementType1 _operator );
	void calculate( char* Str );
	
	friend ostream &operator<< ( ostream &os, const SeqStack &a )
	{
		for ( int i = 0; i < a.top + 1; i ++ )
		{
			if (a.top == -1)
				return os;
			os << a.data[i];
		}

		return os;
	}
	
private:
	elementType data[maxLength];
	int top;
};

#endif // !defined(AFX_SEQSTACK1_H__55EE245C_A5F8_47D4_9510_B3BA6C85FF63__INCLUDED_)
