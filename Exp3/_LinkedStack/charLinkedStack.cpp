// charLinkedStack.cpp: implementation of the charLinkedStack class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "charLinkedStack.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

charLinkedStack::charLinkedStack()
{
	top = new CLStack;
	if( !top )
	{
		cerr << "Space allocating falied!Error in linkedStack::linkedStack()!" << endl;
	}
	top->link = NULL;
	//top = NULL;
	len = 0;
}

charLinkedStack::~charLinkedStack()
{
	while(top)
	{
		CLStack *q = top;
		top = top->link;
		delete q;
	}
	top = NULL;
}

bool charLinkedStack::stackEmpty()
{
	//follow style is not suitable for the code
	//return top == NULL;
	return top->link == NULL;
}

bool charLinkedStack::getTop( elementType1& value )
{
	if( stackEmpty() )
	{
		//cerr << "Stack is Empty!Error in linkedStack::getTop!" << endl;
		value = '#';
		return false;
	}
	value = top->data;
	return false;
}

bool charLinkedStack::push( elementType1 value )
{
	CLStack *newNode = new CLStack;
	if( !newNode )
	{
		cerr << "Space allocating falied!" << endl;
		return false;
	}
	newNode->data = value;
	newNode->link = top;
	top = newNode;
	len ++;
	return true;
}

bool charLinkedStack::pop()
{
	if( stackEmpty() )
	{
		cerr << "Stack is empty!Error in linkedStack::pop()!" << endl;
		return false;
	}
	CLStack *tmp = top;
	
	top = top->link;
	delete tmp;
	len --;
	return true;
}

int charLinkedStack::length()
{
	if( stackEmpty() )
	{
		cerr << "Stack is empty!Error in linkedStack::length()" << endl;
		return -1;
	}
	int cnt = 0;
	CLStack *tmp = top;
	while( tmp->link )
	{
		tmp = tmp->link;
		cnt ++;
	}
	return cnt;
}

void charLinkedStack::displayStack()
{
	if( stackEmpty() )
	{
		cerr << "Stack is empty!Error in linkedStack::displayStack()" << endl;
		return;
	}
	CLStack *tmp = top;
	int column = 0;
	while( tmp->link )
	{
		cout << setw(7) << setiosflags(ios::left) << tmp->data << " ";
		//cout << tmp->data << " ";
		column ++;
		if( column % 10 == 0 )
			cout << setw(7) << setiosflags(ios::left) << endl;
		tmp = tmp->link;
	}
	cout << endl;
}

CPStack charLinkedStack::topValue()
{
	return top->link;//write as "return top;" is not available
}

void charLinkedStack::decToHex( ll value )
{
	ll tmp = value;
	while(tmp)
	{
		ll mod = tmp % 16;
		if( mod <= 9 )
		{
			push( (char) ( mod + '0' ) );
		}
		else
		{
			switch(mod)
			{
			case 10:
				push('A');
				break;
			case 11:
				push('B');
				break;
			case 12:
				push('C');
				break;
			case 13:
				push('D');
				break;
			case 14:
				push('E');
				break;
			case 15:
				push('F');
				break;
			default:
				cerr << "Error in void charSeqStack::transfor()" << endl;
				break;
			}
		}
		tmp /= 16;
	}
}

bool charLinkedStack::brancheMatch( char *Str )
{
	
	int i = 0;
	char ch = Str[i];
	elementType1 ch1 = NULL;
	while( ch != '\0' )
	{
		if( ch == '(' || ch == '[' || ch == '{' )
		{
			push(ch);
			
		}
		else if( ch == ')' || ch == ']' || ch == '}' )
		{
			//ch1 = NULL;
			if( !stackEmpty() )
			{
				//ch1 = NULL;
				getTop(ch1);
				//把下面这句话放到下面这个if判断里面结果就正确了
				//pop();
				//cout << (*this) << endl;
				if( ( ch == ')' && ch1 == '(' ) || 
					( ch == ']' && ch1 == '[' ) || ( ch == '}' && ch1 == '{' ) )
				{
					//ch = NULL;
					//ch1 = NULL;
					pop();
					//continue;
				}	//ch = Str[ ++ i ];
				
				else if( ( ch == ')' && ch1 != '(' ) || 
					( ch == ']' && ch1 != '[' ) || ( ch == '}' && ch1 != '{' ) )
					return false;
			}
			
			else //if( stackEmpty() && !ch1 )
				return false;
		}
		
		ch = Str[ ++ i ];
	}
	if( stackEmpty() )
	{
		return true;
	}
	
	while( !stackEmpty() )
	{
		pop();
		
	}
	
	return false;
}
 
bool charLinkedStack::judge(const char *sour, const char *dest)		//不比更改两个序列的内容，所以可加const修饰限定符
{
     assert(sour);//断言可防止NULL指针的传入(避免传入指针引起程序崩溃的问题)
     assert(dest);
	//stack<char> ss;//借助库函数创建一个栈
	charLinkedStack ss;
	if (strlen(sour) != strlen(dest)) //如果两个序列不一样长，自然是非法的序列
		return false;
 
	ss.push(*sour++); //将首元素压栈
	while (*dest != '\0')  
	{
 
		if (ss.stackEmpty() && *sour != '\0') //如果栈为空且入栈序列未结束，则不断压入元素
			ss.push(*sour++);
		char x;
		ss.getTop(x);
		while (*dest != x && *sour != '\0') 
		{
			ss.push(*sour++);//如果出栈元素和栈顶元素不匹配则继续压入元素
			ss.getTop(x);
		}
		ss.getTop(x);
		if (*dest == x )  //如果两者相等，将该元素弹出，且指针指向出栈序列的下一位置上
		{
			dest++;
			ss.pop();
			continue;
		}
		ss.getTop(x);
		if (*sour == '\0'&& x != *dest)  //如果一直不相等，知道入栈序列结束仍为匹配上，说明出栈序列非法
		{
			return false;
		}
	}
	return true;//否则序列合法
}