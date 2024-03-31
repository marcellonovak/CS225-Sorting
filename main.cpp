#include <iostream>
#include <string>
#include "VECTOR.h"
using namespace std;

//VECTOR OBJECT
VectorObj::VectorObj(int len): len(len) {
	swaps = 0;
	for (int i = 0; i < len; i++) {
		sort.push_back(rand() % 101);
	}
}

VectorObj::~VectorObj() {
	cout << "peace out bbygurl" << endl;
}

//NAMED VECTOR OBJECT
NamedVectorObj::NamedVectorObj(string name, int len) : VectorObj(len), name(name) {}

NamedVectorObj::~NamedVectorObj() {
	cout << "peace out i'm sorted" << endl;
}

ostream& operator<<(ostream& os, NamedVectorObj& v) {
	os << "Name of sort: " << v.name << endl << "Swaps needed: " << v.swaps << endl << "Sorted vector: ";
	for (int i = 0; i < v.sort.size(); i++) {
		os << v.sort[i] << ", ";  // M: Added space for readability
	}
	os << endl;
	return os;
}

int main() {
	srand(time(0));
	NamedVectorObj short1("selection short", 5);
	cout << short1;
	return 0;
}