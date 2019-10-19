// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__C76F8A03_DD16_4544_9FF3_EF3FC0E70632__INCLUDED_)
#define AFX_STDAFX_H__C76F8A03_DD16_4544_9FF3_EF3FC0E70632__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <time.h>
//#include <windows.h>
#include <string>
#include <iomanip>
#include <graphics.h>
#include <cmath>

using namespace std;

typedef struct rec
{
	int data;
	int index;
	bool active;   //节点未出局，则是true，其它false   
}Rec;

// TODO: reference additional headers your program requires here

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__C76F8A03_DD16_4544_9FF3_EF3FC0E70632__INCLUDED_)
