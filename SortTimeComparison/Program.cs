using System.Diagnostics;
using System.Globalization;
using System.Text;

namespace SortTimeComparison
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] N = { 50, 100, 150, 200, 250 };

            string filePath = "sorting_times.csv";

            File.WriteAllText(filePath, "Algorithm,ArrayType,Size,Time(ms)\n");

            SortingBenchmark.CalculateTimeAndSave(N, SortingAlgorithms.BubbleSort, ArrayGenerator.GenerateSortedArray, "BubbleSort", "л.с", filePath);
            SortingBenchmark.CalculateTimeAndSave(N, SortingAlgorithms.BubbleSort, ArrayGenerator.GenerateReversedSortedArray, "BubbleSort", "х.c", filePath);
            SortingBenchmark.CalculateTimeAndSave(N, SortingAlgorithms.InsertionSort, ArrayGenerator.GenerateSortedArray, "InsertionSort", "л.с", filePath);
            SortingBenchmark.CalculateTimeAndSave(N, SortingAlgorithms.BubbleSort, ArrayGenerator.GenerateReversedSortedArray, "InsertionSort", "х.c", filePath);
            SortingBenchmark.CalculateTimeAndSaveQuick(N, ArrayGenerator.GenerateRandomArray, "л.с", filePath);
            SortingBenchmark.CalculateTimeAndSaveQuick(N, ArrayGenerator.GenerateSortedArray, "х.c", filePath);
        }
    }
}

/*
1. Bubble sort
    л.с - O(n), массив уже отсортирован
    х.с - O(n^2), массив отсортирован в обратном порядке

2. Insertion Sort
    л.с - O(n), массив уже отсортирован
    х.с - O(n^2), массив отсортирован в обратном порядке

3. Quick Sort 
    л.с - O(nlogn), если опорный элемент делит массив на две примерно равные части
    х.с - O(n^2), если опорный элемент всегда выбирается как минимальный или максимальный, и массив делится на части размером 1 и n-1
*/
