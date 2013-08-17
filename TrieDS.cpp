#include "TrieDS.h"


//SYMBOL_SIZE: Supporting ASCII character set in a string
#define SYMBOL_SIZE (127)

int CHAR_TO_INDEX(char ch)
{
	return (int)ch;
}

TrieDS::TrieDS(void)
{
	initialize();
}

Node* TrieDS::getNode(void)
{
    Node* pNode = new Node();
    return pNode;
}
 
//root is the dummy node
void TrieDS::initialize()
{
    root = getNode();
    count = 0;
}
 
// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void TrieDS::insert(string &key, int occuranceCount)
{
    int level;
	int length = key.length();
    int index;
    Node *pCrawl;
 
    count++;
    pCrawl = root;
 
    for( level = 0; level < length; level++ )
    {
		index = CHAR_TO_INDEX(key[level]);
        if( !pCrawl->children[index] )
        {
            pCrawl->children[index] = getNode();
        }
 
        pCrawl = pCrawl->children[index];
    }
 
    // mark last node as leaf
    pCrawl->setValue(occuranceCount);
}
 
// Returns hit count, if key presents in trie else 0
int TrieDS::search(string key)
{
    int level;
    int length = key.length();
    int index;
    Node *pCrawl;
 
    pCrawl = root;
 
    for( level = 0; level < length; level++ )
    {
        index = CHAR_TO_INDEX(key[level]);
 
        if( !pCrawl->children[index] )
        {
            return 0;
        }
 
        pCrawl = pCrawl->children[index];
    }
 
	if(pCrawl->getValue())
		return pCrawl->getValue();
	else return 0;
}
 
//Get the paths from the user query and traverse all suggestions
void TrieDS::traverse(Node *pCrawl, string key,int index, Heap &minheap)
{
      
   if(!pCrawl)
   {
        return ;
   }
 
   if(pCrawl->getValue()!=0)
   {
	   //cout << key << " : " << pCrawl->getValue() <<  endl;
	   stringData *tmpQ = new stringData(key, pCrawl->getValue());
	   minheap.push(tmpQ);
   }
 
   for(int i=0;i<SYMBOL_SIZE;i++)
   {
       if(pCrawl->children[i])
	   {
		   string temp = key + char(i);
		   traverse(pCrawl->children[i], temp,i, minheap);
	   }    
   }
}

//travel down the trie upto the prefix and then look for suggestion using traverse function
int TrieDS::suggestions(string key, Heap &minheap)
{
    int level,i;
	int length = key.length();
    int index;
    Node *pCrawl = root;

    if(key.empty())
    {
        printf("The input is NULL!!");
        return 0;
    }
 
    for( level = 0; level < length; level++ )
    {
        index = CHAR_TO_INDEX(key[level]);
 
        if( !pCrawl->children[index] )
        {
	        printf("Prefix is not present");
            return 0;
        }
        pCrawl = pCrawl->children[index];
    }
	traverse(pCrawl, key,index, minheap);
}

void TrieDS::removeAll(Node *n)
{
	if (!n) return;
	for(int i=0;i<SYMBOL_SIZE;i++)
	{
		Node *current = n->children.at(i);
		if(current)
			removeAll(current);
	}
	delete n;
}
void TrieDS::LoadData(qDataVector &v)
{
	for(int i = 0; i < v.size(); i++)
    {
		insert(v.at(i)->query,v.at(i)->hits);
    }

}
void TrieDS::free()
{
	delete this;
}

TrieDS::~TrieDS()
{
	removeAll(root);
}
