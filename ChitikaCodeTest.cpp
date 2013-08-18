// ChitikaCodeTest.cpp : Driver Program
//

#include<iostream>
#include "common.h"
#include "DataHandler.h"
using namespace std;

//Strategies possible Data Loading 
enum operationLoadQuery{
	File,
	Stream,
	Network
};

//Strategies Possible for Data Structure
enum operationQueryDataStructure{
	Trie,
	Lucene,
	CustomIndex
};


int main(int argc, char * argv[])
{
	
	if(argc < 2)
	{
   		cout << "No user query" << endl;
		return 0;
	}

	DataHandler *dh = new DataHandler();
	dh->performOperation(File, Trie);


	dh->getStoredData();
	dh->LoadToMemory();

	//TODO	: QueryParser class
	//		: Class defines the strategy to use the user input query
	//			whether to use the exact query or remove stop words from it 
	//			and then perform search

	//TODO	: OutputDisplay class
	//		: Class defines the logic and size of the output results,
	//			

	string query(argv[1]);	
	cout << "User Query = " << query << endl;
	
	Heap minheap;
	dh->obj_l->suggestions(query, minheap);
	minheap.print();
	return 0;
}

