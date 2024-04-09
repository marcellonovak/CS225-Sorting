// Bogo Sort Function Header
// Takes in an array and sorts it using a bogo sort algorithm

#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>

#include "VECTOR.h"
#include "SortBogo.h"

using namespace std;

// Check if the array is sorted
bool isSorted(NamedVectorObj& vect) {
    int n = vect.getSize();
    for (int i = 1; i < n; i++) {
        if (vect.getIndex(i - 1) > vect.getIndex(i)) {
            return false;
        }
    }
    return true;
}

// Shuffling the array
void shuffle(NamedVectorObj& vect) {
    int n = vect.getSize();

    for (int i = 0; i < n; i++) {
        int randomIndex = rand() % 4;
        vect.swapIndex(i, randomIndex);
    }
}

// Save original cout buffer, global for easy access
streambuf* coutBufBogo = cout.rdbuf();
int i = 0;  // counter for number of swaps

void bogoSort(NamedVectorObj& vect, ofstream& logfile) {
    
    // Throw an exception if the array is too large (crashes)
    int max = 6;
    if (vect.getSize() > max) {
        throw max;
    }

    // Use a flag variable to check if cout has been redirected because of recursion
    static bool coutRedirected = false;

    // Check if we haven't redirected cout yet
    if (!coutRedirected) {
        // Redirect cout to logfile
        cout.rdbuf(logfile.rdbuf());
        coutRedirected = true;

        // Log initial array state
        cout << "Initial array: ";
        vect.printData(vect);
    }

    // Check if the array is sorted
    if (isSorted(vect)) {
        cout.rdbuf(coutBufBogo); // Restore the original cout buffer
        coutRedirected = false; // Reset the flag
        return;
    }

    else {
        shuffle(vect);
        // Log the state of the vector after each swap
        cout << "After swap " << i << ": ";
        vect.printData(vect);
        i++;
    }

    //new skill: recursion
    bogoSort(vect, logfile);
}