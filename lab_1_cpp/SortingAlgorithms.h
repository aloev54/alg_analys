//
// Created by Алоев Артем on 17.02.2025.
//

#ifndef ALG_LAB1_TEST_SORTINGALGORITHMS_H
#define ALG_LAB1_TEST_SORTINGALGORITHMS_H

#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H

#include "vector"

using namespace std;

class SortingAlgorithms {
public:
    static void BubbleSort(vector<int>& array);
    static void InsertionSort(vector<int>& array);
    static void SelectionSort(vector<int>& array);
};

#endif

#endif //ALG_LAB1_TEST_SORTINGALGORITHMS_H
