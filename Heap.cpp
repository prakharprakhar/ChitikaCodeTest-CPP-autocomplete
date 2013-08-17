
#include "Heap.h"
#include <algorithm>

Heap::Heap(void)
{
}

static bool rem(stringData* element) 
{ 
	delete element; 
	return true;
}
Heap::~Heap(void)
{
	remove_if(v.begin(),v.end(),rem);
}
bool comp(const stringData* a, const stringData* b)
{
	return b->hits < a->hits?true:false;
}
void Heap::print()
{
	if(v.empty())
		return;
	sort(v.begin(),v.end(),comp);
	cout << "Top 4 Hits are " << endl;
	for(int i=0;i<v.size();++i)
	{	
		cout << v.at(i)->hits << " " << v.at(i)->query;
		cout << endl;
	}
}

void Heap::push(stringData* x)
{
	if(v.size() == TOP4)
	{
		if(v.front()->hits < x->hits)
		{
			this->pop();
		}
		else
			return;
	}
		v.push_back(x); 
		push_heap (v.begin(),v.end(),comp);
}

void Heap::pop()
{
	if(v.empty()) return;
	pop_heap (v.begin(),v.end(),comp);
	v.pop_back();
}

int Heap ::getMin()
{
	if(v.empty())
		return 0;
	int val = v.front()->hits;
	return val;
}


