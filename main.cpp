#include <iostream>
#include <fstream>
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
* -move all vector.h code to vector.cpp
*/

//VECTOR OBJECT
VectorObj::VectorObj(int len): len(len) {
	swaps = 0;
	for (int i = 0; i < len; i++) {
		vect.push_back(rand() % 101);  // Creating a random vector of integers
	}
}
VectorObj::~VectorObj() {}

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

void printDataMain(NamedVectorObj& vect) {
	cout << "Unsorted vector: ";
	vect.printData(vect);
}

int main() {
	srand(time(0));
	HANDLE mConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// File to write to
	ofstream logfile;
	logfile.open("log.txt");
	logfile << "Current time: " << __TIME__ << endl;

	//SERIOUS SORTS
	//selection sort
	SetConsoleTextAttribute(mConsole, 1);
	cout << "SELECTION SORT*************************" << endl;
	SetConsoleTextAttribute(mConsole, 15);
	NamedVectorObj short1("selection short", 5);
	printDataMain(short1);
	selectionSort(short1, logfile);
	cout << short1 << endl;

	NamedVectorObj medium1("selection medium", 10); 
	printDataMain(medium1);
	selectionSort(medium1, logfile);
	cout << medium1 << endl; 

	NamedVectorObj long1("selection long", 25);
	printDataMain(long1);
	selectionSort(long1, logfile);
	cout << long1 << endl;

	//bubble sort
	SetConsoleTextAttribute(mConsole, 2); 
	cout << "BUBBLE SORT*************************" << endl;
	SetConsoleTextAttribute(mConsole, 15);
	NamedVectorObj short2("bubble short", 5);
	printDataMain(short2);
	bubbleSort(short2, logfile);
	cout << short2 << endl;

	NamedVectorObj medium2("bubble medium", 10);
	printDataMain(medium2);
	bubbleSort(medium2, logfile);
	cout << medium2 << endl;

	NamedVectorObj long2("bubble long", 25);
	printDataMain(long2);
	bubbleSort(long2, logfile);
	cout << long2 << endl;

	//insertion sort
	SetConsoleTextAttribute(mConsole, 6); 
	cout << "INSERTION SORT*************************" << endl;
	SetConsoleTextAttribute(mConsole, 15);
	NamedVectorObj short3("insertion short", 5);
	printDataMain(short3);
	insertionSort(short3, logfile);
	cout << short3 << endl;

	NamedVectorObj medium3("insertion medium", 10);
	printDataMain(medium3);
	insertionSort(medium3, logfile);
	cout << medium3 << endl;

	NamedVectorObj long3("insertion long", 25);
	printDataMain(long3);
	insertionSort(long3, logfile);
	cout << long3 << endl;

	//SILLY SORTS :))
	//CAN ONLY RUN ON AN VECTOR WITH 6 OR LESS ELEMENTS
	SetConsoleTextAttribute(mConsole, 12);
	cout << "SILLY SORTS!!!!!*************************" << endl;
	SetConsoleTextAttribute(mConsole, 15);
	NamedVectorObj short4("bogo sort", 6);
	printDataMain(short4);
	bogoSort(short4, logfile);
	cout << short4 << endl;


	logfile.close();
	SetConsoleTextAttribute(mConsole, 15);
	return 0;
}