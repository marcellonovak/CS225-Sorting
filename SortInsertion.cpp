// Insertion Sort Function
// Takes in an array and sorts it using the insertion sort algorithm

#pragma once 

#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <numeric>
#include <vector>

#include "VECTOR.h"
#include "SortInsertion.h"

using namespace std;

void insertionSort(NamedVectorObj& vect) {
	int i, j, key;
	int n = vect.getSize();

	// For each element in the array except the first one
	for (i = 1; i < n; i++) {
		key = vect.getIndex(i);
		j = i - 1;

		// Move elements of arr[0..i-1] that are greater than key to one position ahead of their current position
		while (j >= 0 && vect.getIndex(j) > key) {
			vect.swapIndex(j + 1, j);
			j = j - 1;
		}
		vect.setIndex(j + 1, key);
	}
}