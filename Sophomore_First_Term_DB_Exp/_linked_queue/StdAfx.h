// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__009A1125_2F9A_4B93_9830_51B9398EBC52__INCLUDED_)
#define AFX_STDAFX_H__009A1125_2F9A_4B93_9830_51B9398EBC52__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include <stdc++.h>
//#include <iostream>

using namespace std;

typedef int elementType;
typedef char elementType1;

typedef struct node
{
	elementType data;
	struct node *link;
}LNode, *PNode;

typedef struct charNode
{
	elementType1 data;
	struct charNode *link;
}CLNode, *CPNode;

//typedef struct linkedQueue
//{
//	LNode *_front, *_rear;
//}LQueue, *PQueue;

// TODO: reference additional headers your program requires here

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__009A1125_2F9A_4B93_9830_51B9398EBC52__INCLUDED_)
