// Selection Sort Function Header
// Takes in an array and sorts it using the selection sort algorithm

#pragma once 

// Standard io libraries + warning muffler
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <numeric>
#include <algorithm> // include for swap

using namespace std;

void selectionSort(int arr[], int n) {
    int i, j, minIndex;

    // For each element in the array except the last one
    for (i = 0; i < n - 1; i++) {

        // Set minIndex to the current index
        minIndex = i;

        // Find the index of the minimum element in the remaining unsorted part
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        swap(arr[minIndex], arr[i]);
    }
}
