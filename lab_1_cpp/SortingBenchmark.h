//
// Created by Алоев Артем on 17.02.2025.
//

#ifndef ALG_LAB1_TEST_SORTINGBENCHMARK_H
#define ALG_LAB1_TEST_SORTINGBENCHMARK_H

#include "vector"
#include "functional"
#include "string"
#include "fstream"
#include "ctime"
#include "iostream"

using namespace std;

class SortingBenchmark {
public:
    static void CalculateTimeAndSave(const std::vector<int>& N,
                                     const std::function<void(std::vector<int>&)>& sortMethod,
                                     const std::function<std::vector<int>(int)>& generateArrayMethod,
                                     const std::string& methodName,
                                     const std::string& arrayType,
                                     const std::string& filePath,
                                     int k);
};

#endif //ALG_LAB1_TEST_SORTINGBENCHMARK_H
