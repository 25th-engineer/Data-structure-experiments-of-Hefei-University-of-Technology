// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__239FA301_F6C5_4AE4_BD82_5EB3365C7ECB__INCLUDED_)
#define AFX_STDAFX_H__239FA301_F6C5_4AE4_BD82_5EB3365C7ECB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include <stdc++.h>
#include <graphics.h>

using namespace std;

//�� elementType ��Ϊ int ����˳�����ʵ��Ҫ�󣻶�������Ϊ string ����������ַ����ȣ�
//��ʱ�Ĵ�С��ϵĬ��ΪΪ�ֵ���
//typedef string elementType;
typedef int elementType;

//Ϊ��ͼ���棬����EasyX���������ɫ����һ��
//����EasyX�Ĺٷ���վ�� https://www.easyx.cn/

typedef struct node
{
	elementType data;
	struct node *leftChidld, *rightChild; 
}BSTNode, *_BSTree;

// TODO: reference additional headers your program requires here

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__239FA301_F6C5_4AE4_BD82_5EB3365C7ECB__INCLUDED_)
