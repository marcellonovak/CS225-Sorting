    #define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <numeric>
#include <vector>

#include "VECTOR.h"
#include "SortBogo.h"
#include <random>

using namespace std;

bool isSorted(NamedVectorObj& vect) {
    int n = vect.getSize();
    for (int i = 1; i < n; i++) {
        if (vect.getIndex(i - 1) > vect.getIndex(i)) {
            return false;
        }
    }
    return true;
}

void shuffle(NamedVectorObj& vect) {
    int n = vect.getSize();
    static std::random_device rd;
    static std::default_random_engine rng(rd());

    for (int i = 0; i < n; i++) {
        int randomIndex = std::uniform_int_distribution<int>(i, n - 1)(rng);
        vect.swapIndex(i, randomIndex);
    }
}

void bogoSort(NamedVectorObj& vect) {
    // Base case: stop if the vector is sorted
    if (isSorted(vect)) {
        return;
    }

    // Recursive case: shuffle the vector and try again
    shuffle(vect);
    bogoSort(vect);
}