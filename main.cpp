#include <iostream>
#include <string>
#include "VECTOR.h"
using namespace std;

//VECTOR OBJECT
VectorObj::VectorObj(int len) {
	swaps = 0;
	for (int i = 0; i < len; i++) {
		sort[i] = rand() % 101;
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
	os << "Name of sort: " << v.name << endl << "Swaps needed: " << v.swaps << endl;
	return os;
}

int main() {
	return 0;
}