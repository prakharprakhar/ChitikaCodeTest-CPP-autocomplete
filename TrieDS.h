#pragma once
#include "common.h"
#include "Loader.h"
#include "Heap.h"

class Node
{
	int value;
public:
	vector<Node*> children;
	Node(void):value(0), children(127)
	{};
	~Node(void)
	{};
	int getValue() const
	{
		return value;
	};
	void setValue(int x)
	{
		value = x;
	}
	
};


class TrieDS :
	public CLoader
{
	Node *root;
public:
	TrieDS(void);
	~TrieDS(void);
	
    int count;
	Node* getNode(void);
	void initialize();
	void insert(string &key,int occuranceCount);
	int search(string key);
	void traverse(Node* pCrawl, string key,int index,Heap &minheap);
	int suggestions(string key, Heap &);
	void removeAll(Node *n);
	void LoadData(qDataVector &qDVector);
	void free();
};
