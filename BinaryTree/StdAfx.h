// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__02F8C78B_9F6E_45FF_BFCE_7F99B5AC9359__INCLUDED_)
#define AFX_STDAFX_H__02F8C78B_9F6E_45FF_BFCE_7F99B5AC9359__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <stdc++.h>
#include <windows.h>

using namespace std;

typedef char elementType;
typedef int elementType1;

typedef struct node
{
	elementType data;//刚开始应该写成将data写成string或者直接将整个函数写成模板的，写完了最后测试时
					//才发现现在的写法有诸多不便；但修改的话就又要重构一遍，懒得整了。
	struct node *leftChild, *rightChild;
}bitNode, *binTree;

typedef struct charNode
{
	//elementType data;
	bitNode *data;//the type must be bitNode*
	struct charNode *link;
}CLNode, *CPNode;


//typedef struct charNode
//{
	//elementType data;
	//struct charNode *leftChild, *rightChild;
//}charBitNode, *charBinTree;

// TODO: reference additional headers your program requires here

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__02F8C78B_9F6E_45FF_BFCE_7F99B5AC9359__INCLUDED_)
