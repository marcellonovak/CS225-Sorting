#pragma once
#include <iostream>
#include <string>
using namespace std;

class Array {
protected:
	int array[5]; //feel free to change the size
	int steps;
	//we need to figure out how we are measuring seconds
public:
	Array(int len);
	~Array();
	int setArray();
	int setSteps();
	friend ostream& operator<<(ostream& os, Array& arr);
};

class NamedArray : public Array {
private:
	string name;
public:
	NamedArray();
	~NamedArray();
	string setName();
};