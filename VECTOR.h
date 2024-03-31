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
	NamedVectorObj(string name, int len): VectorObj(len), name(name){}
	~NamedVectorObj() { cout << "Peace out i'm sorted"; }

	void setName(string name);

	friend ostream& operator<<(ostream& os, VectorObj& arr);
};