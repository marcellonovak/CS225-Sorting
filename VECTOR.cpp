#pragma once 

#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <fstream>
#include <numeric>
#include <vector>
#include <algorithm>

#include "VECTOR.h"

using namespace std;

//VECTOR OBJECT
VectorObj::VectorObj(int len) : len(len) {
	swaps = 0;
	for (int i = 0; i < len; i++) {
		vect.push_back(rand() % 101);  // Creating a random vector of integers
	}
}
VectorObj::~VectorObj() {}

void VectorObj::swapIndex(int i, int j) {
	if (i != j) { // Check to prevent unnecessary swaps
		swap(vect[i], vect[j]);
		swaps++; // Keeping track of the swaps
	};
};

//NAMED VECTOR OBJECT
NamedVectorObj::NamedVectorObj(string name, int len) : VectorObj(len), name(name) {}

NamedVectorObj::~NamedVectorObj() {
	cout << "peace out i'm outta here :)" << endl;
}

void NamedVectorObj::printData(NamedVectorObj& vect) {
	for (int i = 0; i < vect.getSize(); i++) {
		cout << vect.vect[i];
		if (i < vect.getSize() - 1) {
			cout << ", ";
		}
	}
	cout << endl;
}

bool NamedVectorObj::isSorted(NamedVectorObj& vect) {
	bool ans;
	ans = is_sorted(vect.vect.begin(), vect.vect.end());
	return ans;
}

ostream& operator<<(ostream& os, NamedVectorObj& vect) {
	os << "Name of sort: " << vect.name << endl << "Swaps needed: " << vect.swaps << endl << "Sorted vector: ";
	for (int i = 0; i < vect.vect.size(); i++) {
		os << vect.vect[i];
		if (i < vect.vect.size() - 1) {
			cout << ", ";
		}
	}
	os << endl;
	return os;
}
