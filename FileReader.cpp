
#include "FileReader.h"
using namespace std;
FileReader::FileReader(qDataVector &v):vec(v)
{

}

FileReader::~FileReader(void)
{
}
void FileReader::free()
{
	delete this;
}
bool FileReader::getData()
{
	ifstream myfile ("queryInfo.txt");
	if (myfile.is_open())
	{
		while ( myfile.good() )
		{
			string query,strHits;
			int hits;
			getline(myfile, query);
			getline(myfile, strHits);
			
			std::istringstream iss(strHits);
			iss >> hits;
			//cout << query << " : " << hits << endl;
			stringData *qdata = new stringData(query, hits);
			vec.push_back(qdata);
		}			
		myfile.close();
		return true;
	}

	else 
		cout << "Unable to open file" << endl; 
	return false;
}