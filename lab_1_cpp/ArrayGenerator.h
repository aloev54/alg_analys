//
// Created by Алоев Артем on 17.02.2025.
//

#ifndef ALG_LAB1_TEST_ARRAYGENERATOR_H
#define ALG_LAB1_TEST_ARRAYGENERATOR_H

#include "vector"
#include "algorithm"
#include "random"

using namespace std;

class ArrayGenerator {
public:
    static vector<int> GenerateSortedArray(int n);
    static vector<int> GenerateReversedSortedArray(int n);
    static vector<int> GenerateRandomArray(int n);
};

#endif //ALG_LAB1_TEST_ARRAYGENERATOR_H
