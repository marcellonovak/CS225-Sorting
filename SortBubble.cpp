// Bubble Sort Function Header
// Takes in an array and sorts it using a bubble sort algorithm

#pragma once

#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

#include "VECTOR.h"
#include "SortBubble.h"

using namespace std;

void bubbleSort(NamedVectorObj& vect, ofstream& logfile) {
    string msg = "vector already sorted!";
	int n = vect.getSize();
	bool swapped = false;
    int range = vect.getSize();
    

    // Save the original buffer of std::cout
    auto coutBuf = cout.rdbuf();
    // Redirect cout to logfile
    cout.rdbuf(logfile.rdbuf());

    // Log initial array state
    cout << "Initial array: ";
    vect.printData(vect);

    do {
        swapped = false; // Reset flag to false on each new pass

        for (int i = 0; i < n - 1; i++) {
            if (vect.getIndex(i) > vect.getIndex(i + 1)) {
                vect.swapIndex(i, i + 1);
                swapped = true; // Set flag to true if a swap is made
            }

            // Log the state of the vector after each swap
            cout << "After swap " << (i + 1) << ": ";
            vect.printData(vect);
        }

    } while (swapped); // Continue until no more swaps are needed

    // Restore the original cout buffer so it points to the console again
    cout.rdbuf(coutBuf);
}