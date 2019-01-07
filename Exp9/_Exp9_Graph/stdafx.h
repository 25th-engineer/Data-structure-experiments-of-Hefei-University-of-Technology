/*************************************************************************
	> File Name: stdafx.h
	> Author: Xef Utah刁肥宅
	> Mail: u25th_engineer@163.com 
	> Created Time: 2019年01月03日 星期四 21时19分44秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <functional>
#include <time.h>
#include <iomanip>
#define maxVertices 10000 + 3
#define maxEdges 300000 + 1
#define maxWeight 3276745
#define impossibleValue '#'
#define impossibleWeight -1

typedef char elementType;
typedef int weight;
 
typedef struct
{
	int numVertices, numEdges;
	elementType verticesList[maxVertices];
	weight edge[maxVertices][maxVertices];
}MGraph;
  
using namespace std;

