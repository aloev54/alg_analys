#include "iostream"
#include "vector"
#include "fstream"
#include "SortingBenchmark.h"
#include "SortingAlgorithms.h"
#include "ArrayGenerator.h"

using namespace std;

const int k = 10;

int main() {
    vector<int> N = {50, 100, 150, 200, 250};
    string filePath = "../sorting_times.csv";

    ofstream file(filePath);
    if (file.is_open()) {
        file << "Algorithm,ArrayType,Size,Time(ms)\n";
        file.close();
    } else {
        cerr << "Failed to open file: " << filePath << endl;
        return 1;
    }

    SortingBenchmark::CalculateTimeAndSave(N, SortingAlgorithms::BubbleSort, ArrayGenerator::GenerateSortedArray,
                                           "BubbleSort", "л.с", filePath, k);
    SortingBenchmark::CalculateTimeAndSave(N, SortingAlgorithms::BubbleSort,
                                           ArrayGenerator::GenerateReversedSortedArray, "BubbleSort", "х.с", filePath,
                                           k);
    SortingBenchmark::CalculateTimeAndSave(N, SortingAlgorithms::BubbleSort, ArrayGenerator::GenerateRandomArray,
                                           "BubbleSort", "п.с", filePath, k);

    SortingBenchmark::CalculateTimeAndSave(N, SortingAlgorithms::InsertionSort, ArrayGenerator::GenerateSortedArray,
                                           "InsertionSort", "л.с", filePath, k);
    SortingBenchmark::CalculateTimeAndSave(N, SortingAlgorithms::InsertionSort,
                                           ArrayGenerator::GenerateReversedSortedArray, "InsertionSort", "х.с",
                                           filePath, k);
    SortingBenchmark::CalculateTimeAndSave(N, SortingAlgorithms::InsertionSort,
                                           ArrayGenerator::GenerateRandomArray, "InsertionSort", "п.с",
                                           filePath, k);

    SortingBenchmark::CalculateTimeAndSave(N, SortingAlgorithms::SelectionSort, ArrayGenerator::GenerateSortedArray,
                                           "SelectionSort", "л.с", filePath, k);
    SortingBenchmark::CalculateTimeAndSave(N, SortingAlgorithms::SelectionSort,
                                           ArrayGenerator::GenerateReversedSortedArray, "SelectionSort", "х.с",
                                           filePath, k);
    SortingBenchmark::CalculateTimeAndSave(N, SortingAlgorithms::SelectionSort,
                                           ArrayGenerator::GenerateRandomArray, "SelectionSort", "п.с",
                                           filePath, k);

    string command = "python3 ../plots.py " + filePath;
    int result = system(command.c_str());

    if (result != 0) {
        cerr << "Failed to run Python script." << endl;
        return 1;
    }

    return 0;
}
