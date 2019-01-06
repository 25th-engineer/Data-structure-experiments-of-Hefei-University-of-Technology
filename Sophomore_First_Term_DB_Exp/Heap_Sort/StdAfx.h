// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__79E0691C_78C1_4C1B_B38A_7FAD52D0C03D__INCLUDED_)
#define AFX_STDAFX_H__79E0691C_78C1_4C1B_B38A_7FAD52D0C03D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include <string>
#include <iomanip>
#include <graphics.h>

using namespace std;

typedef int elementType;

typedef struct MaxHeap
{
	int length;
	elementType *array;
}heap;

// TODO: reference additional headers your program requires here

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__79E0691C_78C1_4C1B_B38A_7FAD52D0C03D__INCLUDED_)
