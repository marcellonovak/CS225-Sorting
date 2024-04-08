// Selection Sort Function
// Takes in an array and sorts it using the selection sort algorithm

#pragma once 

#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <fstream>
#include <numeric>
#include <vector>

#include "VECTOR.h"
#include "SortSelection.h"

using namespace std;

void selectionSort(NamedVectorObj& vect, ofstream& logfile) {
    int i, j, minIndex;
    int n = vect.getSize();


    // Save the original buffer of std::cout
    auto coutBuf = cout.rdbuf();
    // Redirect cout to logfile
    cout.rdbuf(logfile.rdbuf());

    // Log initial array state
    cout << "Initial array: ";
    vect.printData(vect);

    // For each element in the array except the last one
    for (i = 0; i < n - 1; i++) {

        // Set minIndex to the current index
        minIndex = i;

        // Find the index of the minimum element in the remaining unsorted part
        for (j = i + 1; j < n; j++) {
            if (vect.getIndex(j) < vect.getIndex(minIndex)) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        if (i != minIndex) { // Only swap if needed
            vect.swapIndex(i, minIndex);
        }

        // Log the state of the vector after each swap
        cout << "After swap " << (i + 1) << ": ";
        vect.printData(vect);
    }

    // Restore the original cout buffer so it points to the console again
    cout.rdbuf(coutBuf);
}
