// Selection Sort Function Header
// Takes in an array and sorts it using the selection sort algorithm

#pragma once 

// Standard io libraries + warning muffler
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm> // include for swap
#include "VECTOR.h"
#include "SortSelection.h"

using namespace std;

void selectionSort(NamedVectorObj& vect) {
    int i, j, minIndex;
    int n = vect.getSize();

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
        swap(minIndex, i);
        vect.setSwaps(vect.getSwaps() + 1);
    }
}
