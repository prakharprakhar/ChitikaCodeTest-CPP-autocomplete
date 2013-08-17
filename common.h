#pragma once

#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;


typedef struct stringData
{
	string query;
	int hits;
	stringData(string str, int x):query(str),hits(x)
	{}
}stringData;

typedef vector<stringData *> qDataVector;