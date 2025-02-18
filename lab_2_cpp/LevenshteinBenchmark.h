//
// Created by Алоев Артем on 18.02.2025.
//

#ifndef LAB_2_CPP_LEVENSHTEINBENCHMARK_H
#define LAB_2_CPP_LEVENSHTEINBENCHMARK_H

#include "vector"
#include "functional"
#include "string"
#include "fstream"
#include "ctime"
#include "iostream"

using namespace std;

class LevenshteinBenchmark {
public:
    static void CalculateTimeAndSave(const vector<int>& N,
                                     const function<int(wstring, wstring, int, int)>& levenshteinMethod,
                                     const function<wstring(int)>& generateStringMethod,
                                     const string& methodName,
                                     const string& filePath,
                                     int k);
};

#endif //LAB_2_CPP_LEVENSHTEINBENCHMARK_H
