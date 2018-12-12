// SeqList.h: interface for the SeqList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SEQLIST_H__58D90762_85EC_4BBB_94EA_068A582CCD81__INCLUDED_)
#define AFX_SEQLIST_H__58D90762_85EC_4BBB_94EA_068A582CCD81__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class SeqList  
{
public:
	SeqList();
	virtual ~SeqList();
	bool seqListFull();
	bool seqListEmpty();
	void randomInsert( elementType number );
	void insert( elementType value );
	void showLength();
	elementType binarySearch( elementType value );
	friend ostream &operator<<( ostream &os, SeqList &SL )
	{
		if( SL.length == -1 )
		{
			return os;
		}
		int column = 0;
		for( int i = 1; i <= SL.length; i ++ )
		{
			os << setw(6) << setiosflags( ios::left ) << SL.Arr[i] << " ";
			column ++;
			if( column % 10 == 0 )
				os << endl;
		}
		os << endl;
	}

private:
	elementType Arr[maxn];
	int length;

};

#endif // !defined(AFX_SEQLIST_H__58D90762_85EC_4BBB_94EA_068A582CCD81__INCLUDED_)
