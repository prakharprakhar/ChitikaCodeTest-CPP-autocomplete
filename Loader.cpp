/*
		: Depending upon the Data Loading strategy invokes the respective derived class
*/
#include "Loader.h"
#include "TrieDS.h"

CLoader::CLoader(void)
{
}

CLoader::~CLoader(void)
{
}
CLoader* CLoader::getObject(int dsType, qDataVector &qDVector)
{
	CLoader* obj_l = NULL;
	if(dsType == Trie)
	{
		obj_l = new TrieDS();
	}
	else if(dsType == Lucene)
	{
		//to be implemented
		//obj_l = new LuceneDS();
	}
	else if(dsType == CustomIndex)
	{
		//to be implemented
		//obj_l = new CustomIndexDS();
	}
	return obj_l;
}
