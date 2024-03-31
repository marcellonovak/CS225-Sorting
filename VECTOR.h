// Vector Object Header
// Used to create arrays and named arrays

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class VectorObj {
protected:
	vector<int> sort;
	int swaps;
public:
	VectorObj(int len); //randomize 
	~VectorObj();
};

class NamedVectorObj : public VectorObj {
private:
	string name;
public:
	NamedVectorObj(string name, int len);
	~NamedVectorObj();
	friend ostream& operator<<(ostream& os, NamedVectorObj& v);
};