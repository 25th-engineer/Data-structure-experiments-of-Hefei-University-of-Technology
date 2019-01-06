// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__2FE69ABE_CC01_4962_8147_FD6E39302FE4__INCLUDED_)
#define AFX_STDAFX_H__2FE69ABE_CC01_4962_8147_FD6E39302FE4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <stdc++.h>

using namespace std;

typedef double elementType;
typedef char elementType1;

typedef struct node
{
	elementType data;
	struct node *link;
}LStack, *PStack;

typedef struct Node
{
	elementType1 data;
	struct Node *link;
}CLStack, *CPStack;

typedef long ll;

// TODO: reference additional headers your program requires here

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__2FE69ABE_CC01_4962_8147_FD6E39302FE4__INCLUDED_)
