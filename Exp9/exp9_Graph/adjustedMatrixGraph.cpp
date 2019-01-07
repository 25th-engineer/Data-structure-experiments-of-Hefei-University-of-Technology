// adjustedMatrixGraph.cpp: implementation of the adjustedMatrixGraph class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "adjustedMatrixGraph.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

template<class T>
adjustedMatrixGraph<T>::adjustedMatrixGraph()
{
	
}

template<class T>
adjustedMatrixGraph<T>::~adjustedMatrixGraph()
{
	delete data;
	delete adjustedMatrix;
}
