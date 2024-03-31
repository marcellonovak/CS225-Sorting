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
	vector<int> vect;
	int swaps;
	int len;
public:
	VectorObj(int len); //randomize 
	~VectorObj();
	int getSize() {return len;}
	int getIndex(int i) {return vect[i];}
	int getSwaps() {return swaps;}
	void setSwaps(int s) {swaps = s;}
};

class NamedVectorObj : public VectorObj {
private:
	string name;
public:
	NamedVectorObj(string name, int len);
	~NamedVectorObj();
	friend ostream& operator<<(ostream& os, NamedVectorObj& v);
};