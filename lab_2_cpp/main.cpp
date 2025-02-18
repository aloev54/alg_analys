#include "iostream"
#include "vector"
#include "fstream"
#include "LevenshteinAlgorithms.h"
#include "StrGenerator.h"
#include "LevenshteinBenchmark.h"

using namespace std;

const int k = 10;

int main() {
    vector<int> N = {50, 100, 150, 200, 250};
    string filePath = "../levenshtein_times.csv";

    ofstream file(filePath);
    if (file.is_open()) {
        file << "Algorithm,Size,Time(ms)\n";
        file.close();
    } else {
        cerr << "Failed to open file: " << filePath << endl;
        return 1;
    }

    LevenshteinBenchmark::CalculateTimeAndSave(N, LevenshteinAlgorithms::levenshteinWithoutRecursive,
                                               StrGenerator::generateRandomString,
                                               "levenshteinWithoutRecursive",
                                               filePath, k);
    LevenshteinBenchmark::CalculateTimeAndSave(N, LevenshteinAlgorithms::levenshteinWithRecursive,
                                               StrGenerator::generateRandomString,
                                               "levenshteinWithRecursive", filePath,
                                               k);
//    LevenshteinBenchmark::CalculateTimeAndSave(N, LevenshteinAlgorithms::levenshteinWithCacheRecursive,
//                                               StrGenerator::generateRandomString,
//                                               "levenshteinWithCacheRecursive",
//                                               filePath, k);
    LevenshteinBenchmark::CalculateTimeAndSave(N, LevenshteinAlgorithms::levenshteinDamerauDistance,
                                               StrGenerator::generateRandomString,
                                               "levenshteinDamerauDistance",
                                               filePath, k);

    string command = "python3 ../plots.py " + filePath;
    int result = system(command.c_str());

    if (result != 0) {
        cerr << "Failed to run Python script." << endl;
        return 1;
    }

    return 0;
}
