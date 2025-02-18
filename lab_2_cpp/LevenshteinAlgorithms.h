//
// Created by Алоев Артем on 18.02.2025.
//

#ifndef LAB_2_CPP_LEVENSHTEINALGORITHMS_H
#define LAB_2_CPP_LEVENSHTEINALGORITHMS_H

#include "string"

using namespace std;

class LevenshteinAlgorithms {
public:
    static int levenshteinWithoutRecursive(wstring str_1, wstring str_2, int len_1, int len_2);
    static int levenshteinWithRecursive(wstring str_1, wstring str_2, int len_1, int len_2);
    static int levenshteinWithCacheRecursive(wstring str_1, wstring str_2, int len_1, int len_2, int **matrix);
    static int levenshteinDamerauDistance(wstring str_1, wstring str_2, int len_1, int len_2);
};

#endif //LAB_2_CPP_LEVENSHTEINALGORITHMS_H
