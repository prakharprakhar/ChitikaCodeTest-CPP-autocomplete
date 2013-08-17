/*
	DataHandler works on Strategy pattern.
	Here strategy is to load the stored queries, and put those stored queries
	to the suitable data structure.
	
	Both these strategies are left to the implementation and are required parameters 
	to the context.

	This implementation can be treated as a hook for further strategy implementations, 
	without modifying the interface.

	CDbReader : Abstract class for reading the stored data
	CLoader   : Abstract class for loading the stored data into suggested datastructure

*/


#pragma once
#include "DbReader.h"
#include "Loader.h"

class DataHandler
{
	
	qDataVector qDVector;
public:

	CDbReader *obj_r;
	CLoader *obj_l;

	void getStoredData();
	void LoadToMemory();
	
	void performOperation(int loadType, int dsType);
	void doOp();
	DataHandler(void);
	virtual ~DataHandler(void);
};
