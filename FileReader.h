#pragma once
#include "common.h"
#include "DbReader.h"

class FileReader :
	public CDbReader
{
	
	qDataVector &vec;
public:
	string filename;
	bool getData();
	void free();

	FileReader(qDataVector &v);
	~FileReader(void);
};
