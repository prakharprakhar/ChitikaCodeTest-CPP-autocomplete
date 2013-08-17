
#include "DataHandler.h"
#include "algorithm"

DataHandler::DataHandler(void):obj_l(NULL),obj_r(NULL)
{
}

static bool rem(stringData* element) 
{ 
	delete element; 
	return true;
}

DataHandler::~DataHandler(void)
{
	obj_r->free();
	obj_l->free();
	remove_if(qDVector.begin(),qDVector.end(),rem);
}

void DataHandler::performOperation(int loadType, int dsType)
{	
	obj_r = CDbReader::getObject(loadType, qDVector);
	obj_l = CLoader::getObject(dsType, qDVector);
}
void DataHandler::getStoredData()
{
	obj_r->getData();
}

void DataHandler::LoadToMemory()
{
	obj_l->LoadData(qDVector);
}
void DataHandler::doOp()
{

}