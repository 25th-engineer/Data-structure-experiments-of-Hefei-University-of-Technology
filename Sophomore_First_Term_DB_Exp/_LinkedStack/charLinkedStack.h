// charLinkedStack.h: interface for the charLinkedStack class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHARLINKEDSTACK_H__CBB1096F_5E0D_4725_8583_A16EF4EA8502__INCLUDED_)
#define AFX_CHARLINKEDSTACK_H__CBB1096F_5E0D_4725_8583_A16EF4EA8502__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class charLinkedStack  
{
public:
	charLinkedStack();
	virtual ~charLinkedStack();
	bool stackEmpty();
	//bool stackFull();
	bool getTop( elementType1& value );
	bool push( elementType1 value );
	bool pop();
	int length();
	void displayStack();
	CPStack topValue();
	void decToHex( long value );
	bool brancheMatch( char *Str );
	bool charLinkedStack::judge(const char *sour, const char *dest);
	friend ostream &operator<< ( ostream &os, const charLinkedStack &a )
	{
		//for ( int i = 0; i < a.top + 1; i ++ )
		//{
		//	if (a.top == -1)
		//		return os;
		//	os << a.data[i];
		//}
		CLStack *tmp = a.top;
		int column = 0;
		while( tmp->link )
		{
			//cout << tmp->data << " ";
			if( tmp->link == NULL )
				return os;
				//break;
			os << tmp->data;
			//os << setw(7) << setiosflags(ios::left) << tmp->data << " ";
			//column ++;
			//if( column % 10 == 0 )
				//os << setw(7) << setiosflags(ios::left) << endl;
			tmp = tmp->link;
		}
		os << endl;

		return os;
	}
private:
	CLStack *top;
	int len;

};

#endif // !defined(AFX_CHARLINKEDSTACK_H__CBB1096F_5E0D_4725_8583_A16EF4EA8502__INCLUDED_)
