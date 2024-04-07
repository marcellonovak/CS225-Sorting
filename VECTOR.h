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
	void swapIndex(int i, int j) {
		if (i != j) { // Check to prevent unnecessary swaps
			swap(vect[i], vect[j]);
			swaps++; // Keeping track of the swaps
		};
	};
};

class NamedVectorObj : public VectorObj {
private:
	string name;
public:
	NamedVectorObj(string name, int len);
	~NamedVectorObj();

	void printData(NamedVectorObj& vect) {
		for (int i = 0; i < vect.getSize(); i++) {
			cout << vect.vect[i];
			if (i < vect.getSize() - 1) {
				cout << ", ";
			}
		}
		cout << endl;
	}

	friend ostream& operator<<(ostream& os, NamedVectorObj& v);
};