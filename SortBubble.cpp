// Bubble Sort Function Header
// Takes in an array and sorts it using a bubble sort algorithm

#pragma once

#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <numeric>
#include <vector>

#include "VECTOR.h"

using namespace std;

void bubbleSort(NamedVectorObj& vect) {
	int n = vect.getSize();
	bool swapped = false;

    do {
        swapped = false; // Reset flag to false on each new pass

        for (int i = 0; i < n - 1; i++) {
            if (vect.getIndex(i) > vect.getIndex(i + 1)) {
                vect.swapIndex(i, i + 1);
                swapped = true; // Set flag to true if a swap is made
            }
        }
    } while (swapped); // Continue until no more swaps are needed
}