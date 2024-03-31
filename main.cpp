#include <iostream>
#include <string>
#include "VECTOR.h"
using namespace std;

//VECTOR OBJECT
VectorObj::VectorObj(int len): len(len) {
	swaps = 0;
	for (int i = 0; i < len; i++) {
		sort.push_back(i) = rand() % 101;
	}
}

VectorObj::~VectorObj() {
	cout << "peace out bby" << endl;
}

//NAMED VECTOR OBJECT
NamedVectorObj::NamedVectorObj(string name, int len) : VectorObj(len), name(name) {}

NamedVectorObj::~NamedVectorObj() {
	cout << "peace out i'm sorted" << endl;
}

ostream& operator<<(ostream& os, NamedVectorObj& v) {
	os << "Name of sort: " << v.name << endl << "Swaps needed: " << v.swaps << endl << "Sorted vector: ";
	for (int i = 0; i < v.len; i++) {
		os << v.sort[i];
	}
	os << endl;
	return os;
}

int main() {
	NamedVectorObj short1("selection sort", 5);
	cout << short1;
	return 0;
}