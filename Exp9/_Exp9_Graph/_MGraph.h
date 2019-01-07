#include "stdafx.h"
//#include "stdafx.cpp"

class graph
{
public:
	graph();
	~graph();
	void createMGraph( elementType v[], int n, elementType ed[][2], weight c[], int e, int d );
	void printGraph( int d );
	int getVertexPos( elementType x );
	int firstNeighbor( int v );
	int nextNeighbor( int v, int w );
	int numberOfVertices();
	int numberOfEdges();
	elementType getValue( int v );
	weight getWeight( int v, int w );
	
	void DFS();
	void BFS();
	
	void DFSTravel();
	void BFSTravel();

private:
	MGraph MG;
};
