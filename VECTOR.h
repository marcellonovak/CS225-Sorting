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
	void setIndex(int i, int val) {vect[i] = val;}
	int getSwaps() { return swaps; }
	void swapIndex(int i, int j);
};

class NamedVectorObj : public VectorObj {
private:
	string name;
public:
	NamedVectorObj(string name, int len);
	~NamedVectorObj();
	void printData(NamedVectorObj& vect);
	friend ostream& operator<<(ostream& os, NamedVectorObj& v);
	bool isSorted(NamedVectorObj& vect);
};