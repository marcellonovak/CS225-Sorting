#include <iostream>
#include <string>
#include <windows.h>

#include "VECTOR.h"
#include "SortSelection.h"
#include "SortBubble.h"
#include "SortInsertion.h"
#include "SortBogo.h"

using namespace std;
/*TO_DO
* -excpetions
* -file i/o
* -move all vector.h code to vector.cpp
*/

//VECTOR OBJECT
VectorObj::VectorObj(int len): len(len) {
	swaps = 0;
	for (int i = 0; i < len; i++) {
		vect.push_back(rand() % 101);  // Creating a random vector of integers
	}
}

VectorObj::~VectorObj() {

}


//NAMED VECTOR OBJECT
NamedVectorObj::NamedVectorObj(string name, int len) : VectorObj(len), name(name) {}

NamedVectorObj::~NamedVectorObj() {
	cout << "peace out i'm sorted :)" << endl;
}

ostream& operator<<(ostream& os, NamedVectorObj& v) {
	os << "Name of sort: " << v.name << endl << "Swaps needed: " << v.swaps << endl << "Sorted vector: ";
	for (int i = 0; i < v.vect.size(); i++) {
		os << v.vect[i];
		if (i < v.vect.size() - 1) {
			cout << ", ";
		}
	}
	os << endl;
	return os;
}

void NamedVectorObj::printData(NamedVectorObj& vect) {
	cout << "unsorted vector: ";
	for (int i = 0; i < vect.getSize(); i++) {
		cout << vect.vect[i];
		if (i < vect.getSize() - 1) {
			cout << ", "; 
		}
	}
	cout << endl;
	
}

int main() {
	srand(time(0));
	HANDLE mConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	//SERIOUS SORTS
	//selection sort
	SetConsoleTextAttribute(mConsole, 1);
	cout << "SELECTION SORT*************************" << endl;
	SetConsoleTextAttribute(mConsole, 15);
	NamedVectorObj short1("selection short", 5);
	short1.printData(short1);
	selectionSort(short1);
	cout << short1 << endl;

	NamedVectorObj medium1("selection medium", 10); 
	medium1.printData(medium1); 
	selectionSort(medium1); 
	cout << medium1 << endl; 

	NamedVectorObj long1("selection long", 25);
	long1.printData(long1);
	selectionSort(long1);
	cout << long1 << endl;

	//bubble sort
	SetConsoleTextAttribute(mConsole, 2); 
	cout << "BUBBLE SORT*************************" << endl;
	SetConsoleTextAttribute(mConsole, 15);
	NamedVectorObj short2("bubble short", 5);
	short2.printData(short2);
	bubbleSort(short2);
	cout << short2 << endl;

	NamedVectorObj medium2("bubble medium", 10);
	medium2.printData(medium2);
	bubbleSort(medium2);
	cout << medium2 << endl;

	NamedVectorObj long2("bubble long", 25);
	long2.printData(long2);
	bubbleSort(long2);
	cout << long2 << endl;

	//insertion sort
	SetConsoleTextAttribute(mConsole, 6); 
	cout << "INSERTION SORT*************************" << endl;
	SetConsoleTextAttribute(mConsole, 15);
	NamedVectorObj short3("insertion short", 5);
	short3.printData(short3 );
	insertionSort(short3);
	cout << short3 << endl;

	NamedVectorObj medium3("insertion medium", 10);
	medium3.printData(medium3);
	insertionSort(medium3);
	cout << medium3 << endl;

	NamedVectorObj long3("insertion long", 25);
	long3.printData(long3);
	insertionSort(long3);
	cout << long3 << endl;

	//SILLY SORTS :))
	//CAN ONLY RUN ON AN VECTOR WITH 6 OR LESS ELEMENTS
	SetConsoleTextAttribute(mConsole, 12);
	cout << "SILLY SORTS!!!!!*************************" << endl;
	SetConsoleTextAttribute(mConsole, 15);
	NamedVectorObj short4("bogo sort", 6);
	short4.printData(short4);
	bogoSort(short4);
	cout << short4 << endl;

	SetConsoleTextAttribute(mConsole, 15);
	return 0;
}