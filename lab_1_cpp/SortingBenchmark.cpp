//
// Created by Алоев Артем on 17.02.2025.
//

#include "SortingBenchmark.h"

void SortingBenchmark::CalculateTimeAndSave(const std::vector<int>& N,
                                            const std::function<void(std::vector<int>&)>& sortMethod,
                                            const std::function<std::vector<int>(int)>& generateArrayMethod,
                                            const std::string& methodName,
                                            const std::string& arrayType,
                                            const std::string& filePath,
                                            int k) {
    ofstream file(filePath, ios::app);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filePath << endl;
        return;
    }

    for (int n: N) {
        double totalTime = 0;

        auto array = generateArrayMethod(n);

        for (int i = 0; i < k; ++i) {

            clock_t start = clock();
            sortMethod(array);
            clock_t end = clock();

            double time = double(end - start) / CLOCKS_PER_SEC * 1000; // Время в миллисекундах
            totalTime += time;
        }

        double averageTime = totalTime / k;
        file << methodName << "," << arrayType << "," << n << "," << averageTime << endl;
    }

    file.close();
}


//vector<int> generateRandomArray(int size) {
//    vector<int> array(size);
//    random_device rd;
//    mt19937 gen(rd());
//    uniform_int_distribution<> dis(1, 1000);
//
//    for (int &value: array) {
//        value = dis(gen);
//    }
//
//    return array;
//}
//
//void bubbleSort(vector<int> &array) {
//    int n = array.size();
//    for (int i = 0; i < n - 1; i++) {
//        for (int j = 0; j < n - i - 1; j++) {
//            if (array[j] > array[j + 1]) {
//                swap(array[j], array[j + 1]);
//            }
//        }
//    }
//}
//
