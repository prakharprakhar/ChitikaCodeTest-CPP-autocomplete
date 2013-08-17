
#pragma once
#include "common.h"
#include "Heap.h"

class CLoader
{
	enum OP_DSType{
	Trie,
	Lucene,
	CustomIndex
};
public:
	static CLoader* getObject(int dstype, qDataVector &qDVector);
	virtual void LoadData(qDataVector &qDVector) = 0;
	virtual int search (string query) = 0;
	virtual int suggestions(string key, Heap &) = 0;
	virtual void free() = 0;
public:
	CLoader(void);
	virtual ~CLoader(void);
};
