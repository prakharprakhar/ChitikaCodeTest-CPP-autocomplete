#pragma once
#include "common.h"

using namespace std;
#define TOP4 4

class Heap
{
	vector<stringData*> v;
	int maxheapSize;
public:
	Heap(void);
	~Heap(void);
	void push(stringData* x);
	void pop();
	int getMin();
	int getSizeLimit() 
		{ return maxheapSize;} ;
	void setSizeLimit() 
		{ maxheapSize = TOP4;};
	void print();
	
};
