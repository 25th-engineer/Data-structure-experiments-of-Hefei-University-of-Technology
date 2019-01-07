/*************************************************************************
  > File Name: _MGraph.cpp
  > Author: Xef Utah刁肥宅
  > Mail: u25th_engineer@163.com 
  > Created Time: 2019年01月03日 星期四 21时37分31秒
 ************************************************************************/

#include "_MGraph.h"
//#include "stdafx.h"

graph::graph()
{
	
}

graph::~graph()
{
	
}

int graph::getVertexPos( elementType x )
{
	for( int i = 0; i < MG.numVertices; i ++ )
	{
		if( MG.verticesList[i] == x )
			return i;
	}
	return -1;
}

int graph::firstNeighbor( int v )
{
	if( v != -1 )
	{
		for( int i = 0; i < MG.numVertices; i ++ )
		{
			if( MG.edge[v][i] > 0 && MG.edge[v][i] < maxWeight )
				return i;
		}
	}
	return -1;
}

int graph::nextNeighbor( int v, int w )
{
	if( v != -1 && w != -1 )
	{
		for( int i = w + 1; i < MG.numVertices; i ++ )
		{
			if( MG.edge[v][i] > 0 && MG.edge[v][i] < maxWeight )
				return i;
		}
	}
	return -1;
}

int graph::numberOfVertices()
{
	return MG.numVertices;	
}

int graph::numberOfEdges()
{
	return MG.numEdges;
}

elementType graph::getValue( int v )
{
	if( v != -1 )
	{
		return MG.verticesList[v];
	}
	else
	{
		return impossibleValue;
	}
}

weight graph::getWeight( int v, int w )
{
	if( v != -1 && w != -1 )
	{
		return MG.edge[v][w];
	}
	else
	{
		return impossibleWeight;
	}
}


void graph::createMGraph( elementType v[], int n, elementType ed[][2], weight c[], int e, int d )
{
	MG.numVertices = n;
	MG.numEdges = e;
	for( int i = 0; i < MG.numVertices; i ++ )
	{
		MG.verticesList[i] = v [i];
		for( int j = 0; j < MG.numVertices; j ++ )
		{
			MG.edge[i][j] = ( i == j ) ? 0 : maxWeight;
		}
	}

	for( int i = 0; i < MG.numEdges; i ++ )
	{
		int a = getVertexPos( ed[i][0] );
		int b = getVertexPos( ed[i][1] );
		MG.edge[a][b] = c [i];
		if( d == 0 )
			MG.edge[b][a] = c[i];
	}

}


















