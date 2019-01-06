// graph.h: interface for the graph class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRAPH_H__DCEAD452_3268_4013_A2FC_E3357383B4A7__INCLUDED_)
#define AFX_GRAPH_H__DCEAD452_3268_4013_A2FC_E3357383B4A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "adjustedMatrixGraph.h"

template<class T>
class graph  
{
public:
	graph( T *array[] );//adjustedMatrix
	graph( T *array[][], string tip );
	void createAdjustedMatrixGraphFromFile( char fileName[] );
	void createLinkedListGraphFromFile( char fileName[] );
	virtual ~graph();
	void DFS();
	void BFS();
	void BFSTravel();
	void DFSTravel();
	int countEdge();
	
private:
	//T *adjustedMatrix;
	//T *linkedList;
	adjustedMatrixGraph AMG;
	
};

#endif // !defined(AFX_GRAPH_H__DCEAD452_3268_4013_A2FC_E3357383B4A7__INCLUDED_)
