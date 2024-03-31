// Array Object Header
// Used to create arrays and named arrays

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Array {
protected:
	vector<int> sort;
	int swaps;
public:
	Array(int len); //randomize 
	~Array();
};

class NamedArray : public Array {
private:
	string name;
public:
	NamedArray(string name, int len): Array(len), name(name){}
	~NamedArray() { cout << "Peace out i'm sorted"; }
	friend ostream& operator<<(ostream& os, Array& arr);
	void setName(string name);
};