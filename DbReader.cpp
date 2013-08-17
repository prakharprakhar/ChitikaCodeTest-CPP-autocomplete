/*
		: Depending upon the DB Loading strategy invokes the respective derived class
			Stored queries could be persist in a File, DB or stream 
*/
#include "DbReader.h"
#include "FileReader.h"

CDbReader::CDbReader(void)
{
}

CDbReader::~CDbReader(void)
{
}
CDbReader* CDbReader::getObject(int loadType, qDataVector &qDVector)
{
	CDbReader* obj_r;
	if(loadType == File)
	{
		obj_r = new FileReader(qDVector);
	}
	else if(loadType == Network)
	{
		//to be implemented
		//obj_r = new NetworkReader();
	}
	else if(loadType == Stream)
	{
		//to be implemented
		//obj_r = new StreamReader();
	}
	return obj_r;
}
