#pragma once

#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <numeric>
#include <algorithm> // include for swap
using namespace std;

int* bubbleSort(int arr[], int n) {
	bool swaps = false;

	for (int i = 0; i < n - 1; i++) {
		swaps = false;
		for (int j = 0; j < n - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				swaps = true;
			}
		}
		if (swaps == true) {
			break;
		}
	}

	return arr;
}
