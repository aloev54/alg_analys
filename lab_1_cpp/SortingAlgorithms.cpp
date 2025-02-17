//
// Created by Алоев Артем on 17.02.2025.
//

#include "SortingAlgorithms.h"

#include <vector>

void SortingAlgorithms::BubbleSort(vector<int> &array) {
    int n = array.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int buf = array[j];
                array[j] = array[j + 1];
                array[j + 1] = buf;
            }
        }
    }
}

void SortingAlgorithms::InsertionSort(vector<int> &array) {
    int n = array.size();
    for (int i = 1; i < n; i++) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }
}

void SortingAlgorithms::SelectionSort(vector<int> &array) {
    int n = array.size();
    for (int i = 0; i < n - 1; i++) {

        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[min_idx]) {
                min_idx = j;
            }
        }

        if (min_idx != i) {
            int buf = array[i];
            array[i] = array[min_idx];
            array[min_idx] = buf;
        }
    }
}