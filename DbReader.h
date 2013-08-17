#pragma once
#include "common.h"

class CDbReader
{
enum OP_LoadType{
	File,
	Stream,
	Network
};
public:
	static CDbReader* getObject(int type, qDataVector &qDVector);
	virtual bool getData() = 0;
	virtual void free() = 0;

	CDbReader(void);
	virtual ~CDbReader(void);
};
