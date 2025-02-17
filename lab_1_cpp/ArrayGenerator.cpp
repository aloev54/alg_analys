//
// Created by Алоев Артем on 17.02.2025.
//

#include "ArrayGenerator.h"

vector<int> ArrayGenerator::GenerateSortedArray(int n) {
    vector<int> array(n);
    for (int i = 0; i < n; ++i) {
        array[i] = i + 1;
    }
    return array;
}

vector<int> ArrayGenerator::GenerateReversedSortedArray(int n) {
    vector<int> array = GenerateSortedArray(n);
    reverse(array.begin(), array.end());
    return array;
}

vector<int> ArrayGenerator::GenerateRandomArray(int n) {
    vector<int> array = GenerateSortedArray(100);
    random_device rd;
    mt19937 g(rd());
    shuffle(array.begin(), array.end(), g);
    return array;
}
