    #define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>

#include "VECTOR.h"
#include "SortBogo.h"

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
 

    for (int i = 0; i < n; i++) {
        int randomIndex = rand() % 4;
        vect.swapIndex(i, randomIndex);
    }
}

void bogoSort(NamedVectorObj& vect) {
    if (isSorted(vect)) {
        return;
    }

    shuffle(vect);
    //new skill: recursion
    bogoSort(vect);
}