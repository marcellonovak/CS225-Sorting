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

void printDataMain(NamedVectorObj& vect) {
	cout << "Original vector: ";
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

	//USER INPUT SECTION
	int name = 0;
	int len;
	while (name != 5) {
		SetConsoleTextAttribute(mConsole, 5);
		cout << endl << "CHOOSE YOUR OWN ADVENTURE!!!!!**************" << endl;
		SetConsoleTextAttribute(mConsole, 15);
		cout << "enter the length of a vector between 5 and 100: ";
		cin >> len;
		while (!cin || len < 5 || len > 100) {
			cin.clear(); //clear error flag
			cin.ignore(INT_MAX, '\n');
			cout << "please enter a number between 5 and 100: "; //reprompt user
			cin >> len;
		}
		cout << "WHICH SORT WOULD YOU LIKE TO DO????" << endl;
		cout << "1. Selection Sort" << endl << "2. Bubble Sort" << endl << "3. Insertion Sort" << endl << "4. Bogo Sort" << endl << "5. Quit" << endl;
		cin >> name;
		while (!cin || name < 1 || name > 5) {
			cin.clear(); //clear error flag
			cin.ignore(INT_MAX, '\n');
			cout << "please enter a number between 1 and 5: "; //reprompt user
			cin >> name;
		}

		if (name == 1) {
			NamedVectorObj user("selection sort", len);
			printDataMain(user);
			selectionSort(user, logfile);
			cout << user << endl;
		}
		else if (name == 2) {
			NamedVectorObj user("bubble sort", len);
			printDataMain(user);
			bubbleSort(user, logfile);
			cout << user << endl;
		}
		else if (name == 3) {
			NamedVectorObj user("insertion sort", len);
			printDataMain(user);
			insertionSort(user, logfile);
			cout << user << endl;
		}
		else if (name == 4) {
			NamedVectorObj user("bogo sort", len);
			printDataMain(user);
			try {
				bogoSort(user, logfile);

			}
			catch (int m) {
				cout << "BOGO SORT CANNOT HAVE A LENGTH ABOVE " << m << endl;
			}
			if (user.getSize() > 6) {

			}
			else {
				cout << user << endl;
			}
		}
	}

		logfile.close();
		SetConsoleTextAttribute(mConsole, 15);
		return 0;

}