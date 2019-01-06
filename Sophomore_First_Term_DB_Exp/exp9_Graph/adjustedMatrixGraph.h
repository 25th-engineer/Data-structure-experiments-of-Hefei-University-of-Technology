// adjustedMatrixGraph.h: interface for the adjustedMatrixGraph class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADJUSTEDMATRIXGRAPH_H__C325A1BF_C97F_484F_9D80_47374B74F0D8__INCLUDED_)
#define AFX_ADJUSTEDMATRIXGRAPH_H__C325A1BF_C97F_484F_9D80_47374B74F0D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


template<class T>
class adjustedMatrixGraph  
{
public:
	adjustedMatrixGraph();
	virtual ~adjustedMatrixGraph();
private:
//protected:
	T *data;
	T *verticeList;//the list of vertices
	T **adjustedMatrix;//the matrix of adjusted-edges
	int verticeNumber;
	int edgeNumber;
	string graphKind;

};

#endif // !defined(AFX_ADJUSTEDMATRIXGRAPH_H__C325A1BF_C97F_484F_9D80_47374B74F0D8__INCLUDED_)
