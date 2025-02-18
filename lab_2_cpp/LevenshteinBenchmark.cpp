//
// Created by Алоев Артем on 18.02.2025.
//

#include "LevenshteinBenchmark.h"

void LevenshteinBenchmark::CalculateTimeAndSave(const vector<int> &N,
                                                const function<int(wstring, wstring, int, int)> &levenshteinMethod,
                                                const function<wstring(int)> &generateStringMethod,
                                                const string &methodName,
                                                const string &filePath,
                                                int k) {
    ofstream file(filePath, ios::app);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filePath << endl;
        return;
    }

    for (int n: N) {
        double totalTime = 0;

        wstring str1 = generateStringMethod(n);
        wstring str2 = generateStringMethod(n);

        for (int i = 0; i < k; ++i) {

            clock_t start = clock();
            levenshteinMethod(str1, str2, n, n);
            clock_t end = clock();

            double time = double(end - start) / CLOCKS_PER_SEC * 1000; // Время в миллисекундах
            totalTime += time;
        }

        double averageTime = totalTime / k;
        file << methodName << "," << n << "," << averageTime << endl;
    }

    file.close();
}

