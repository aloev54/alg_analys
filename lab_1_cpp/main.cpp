#include <iostream>
#include <vector>
#include <chrono>
#include <time.h>
#include <stack>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

class arraySort
{
public:

    arraySort()
    {
        arraySize = 0;
    }

    arraySort(size_t size)
    {
        arraySize = size;
    }

    bool isEmpty();

    void printArray();

    void fillArray(size_t count);

    void fillIncreasing(size_t count);
    void fillDecreasing(size_t count);
    void fillRandom(size_t count);



    
    void insertionSort();      
    void gnomeSort(size_t i, size_t j);  
    void selectionSort();      
    

    void quickSort(size_t first, size_t last);  
    void mergeSort(size_t left, size_t right);  
    void heapSort();           



    void getArrayFromUser();

    size_t arraySize;
    std::vector<int> Array;

private:
    void merge(size_t left, size_t mid, size_t right);  
    void heapify(size_t n, size_t i);                   
};

bool arraySort::isEmpty()
{
    if (this->arraySize == 0)
    {
        return true;
    }
    return false;
}

void arraySort::printArray()
{
    if (this->isEmpty())
    {
        cout << "Array is empty" << endl;
    }
    else
    {
        for (size_t i = 0; i < this->arraySize; i++)
        {
            cout << this->Array[i] << " ";
        }
        cout << endl;
    }
}

void arraySort::fillArray(size_t count)
{
    arraySize = count;
    Array.clear();
    for (size_t i = 0; i < count; i++)
    {
        Array.push_back(rand() % 100 + 1);
    }
}

void arraySort::fillIncreasing(size_t count)
{
    arraySize = count;
    Array.clear();
    for (size_t i = 0; i < count; i++)
    {
        Array.push_back(i);
    }
}

void arraySort::fillDecreasing(size_t count)
{
    arraySize = count;
    Array.clear();
    for (size_t i = count; i > 0; i--)
    {
        Array.push_back(i);
    }
}

void arraySort::fillRandom(size_t count)
{
    arraySize = count;
    Array.clear();
    for (size_t i = 0; i < count; i++)
    {
        Array.push_back(rand() % 1000 + 1);
    }
}

// ==================== НЕРЕКУРСИВНЫЕ СОРТИРОВКИ ====================

void arraySort::insertionSort()
{
    for (size_t i = 0; i < this->arraySize - 1; i++)
    {
        int key = i + 1;
        int tmp = this->Array[key];
        size_t j = i + 1;
        while (j > 0 && tmp < this->Array[j - 1])
        {
            this->Array[j] = this->Array[j - 1];
            key = j - 1;
            j = j - 1;
        }
        this->Array[key] = tmp;
    }
}

void arraySort::gnomeSort(size_t i, size_t j)
{
    if (i > this->arraySize || j > this->arraySize)
    {
        return;
    }
    while (i < this->arraySize)
    {
        if (this->Array[i - 1] <= this->Array[i])
        {
            i = j;
            j++;
        }
        else
        {
            int t = this->Array[i];
            this->Array[i] = this->Array[i - 1];
            this->Array[i - 1] = t;
            i--;
            if (i == 0)
            {
                i = j;
                j++;
            }
        }
    }
}

void arraySort::selectionSort()
{
    for (size_t i = 0; i < arraySize - 1; i++)
    {
        size_t minIndex = i;
        for (size_t j = i + 1; j < arraySize; j++)
        {
            if (Array[j] < Array[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swap(Array[i], Array[minIndex]);
        }
    }
}

// ==================== РЕКУРСИВНЫЕ СОРТИРОВКИ ====================

void arraySort::quickSort(size_t first, size_t last)
{
    if (first + 1 < last) 
    {
        int mid, tmp;
        size_t f = first, l = last;
        mid = this->Array[(f + l) / 2]; 
        do
        {
            while (this->Array[f] < mid && f <= last)
                f++;
            while (this->Array[l] > mid && l >= first)
                l--;
            if (f <= l) 
            {
                tmp = this->Array[f];
                this->Array[f] = this->Array[l];
                this->Array[l] = tmp;
                f++;
                l--;
            }
        } while (f <= l);
        if (first < l) quickSort(first, l);
        if (f < last) quickSort(f, last);
    }
}

void arraySort::mergeSort(size_t left, size_t right)
{
    if (left < right)
    {
        size_t mid = left + (right - left) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}

void arraySort::merge(size_t left, size_t mid, size_t right)
{
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;
    
    vector<int> leftArr(n1), rightArr(n2);
    
    for (size_t i = 0; i < n1; i++)
        leftArr[i] = Array[left + i];
    for (size_t j = 0; j < n2; j++)
        rightArr[j] = Array[mid + 1 + j];
    
    size_t i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            Array[k] = leftArr[i];
            i++;
        }
        else
        {
            Array[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    while (i < n1)
    {
        Array[k] = leftArr[i];
        i++;
        k++;
    }
    
    while (j < n2)
    {
        Array[k] = rightArr[j];
        j++;
        k++;
    }
}

void arraySort::heapSort()
{
    for (int i = arraySize / 2 - 1; i >= 0; i--)
        heapify(arraySize, i);
    
    for (int i = arraySize - 1; i > 0; i--)
    {
        swap(Array[0], Array[i]);
        heapify(i, 0);
    }
}

void arraySort::heapify(size_t n, size_t i)
{
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;
    
    if (left < n && Array[left] > Array[largest])
        largest = left;
    
    if (right < n && Array[right] > Array[largest])
        largest = right;
    
    if (largest != i)
    {
        swap(Array[i], Array[largest]);
        heapify(n, largest);
    }
}

void arraySort::getArrayFromUser()
{
    Array.clear();
    cout << "Enter " << arraySize << " numbers: " << endl;
    for (size_t i = 0; i < this->arraySize; i++)
    {
        int a;
        cin >> a;
        this->Array.push_back(a);
    }
}

unsigned long long tick(void)
{
    using namespace std::chrono;
    return duration_cast<nanoseconds>(high_resolution_clock::now().time_since_epoch()).count();
}

// Функция для записи результатов в CSV файл
void writeToCSV(const string& filename, const string& algorithm, const string& arrayType, 
                int size, double time_ms)
{
    ofstream file(filename, ios::app);
    if (file.is_open())
    {
        file << algorithm << "," << arrayType << "," << size << "," << time_ms << endl;
        file.close();
    }
}

void time()
{
    // Создаем CSV файл с заголовком
    ofstream file("sorting_times.csv");
    if (file.is_open())
    {
        file << "Algorithm,ArrayType,Size,Time(ms)" << endl;
        file.close();
    }
    
    double sum = 0;
    int repeat = 10; // Уменьшим для более быстрого тестирования
    int begin = 100;
    int step = 100;
    int last = 1000;

    vector<string> arrayTypes;
    arrayTypes.push_back("Random");
    arrayTypes.push_back("Increasing");
    arrayTypes.push_back("Decreasing");
    
    for (const string& arrayType : arrayTypes)
    {
        cout << "============== TESTING " << arrayType << " ARRAYS ==========" << endl;
        
        for (int j = begin; j <= last; j += step)
        {
            cout << "Size: " << j << endl;
            
            
            {
                arraySort array, arrayTmp;
                if (arrayType == "Random") array.fillRandom(j);
                else if (arrayType == "Increasing") array.fillIncreasing(j);
                else array.fillDecreasing(j);
                
                arrayTmp.arraySize = array.arraySize;
                arrayTmp.Array = array.Array;
                
                for (int i = 0; i < repeat; i++)
                {
                    const auto start = tick();
                    array.insertionSort();
                    const auto end = tick();
                    const auto res = end - start;
                    sum += res;
                    array.Array = arrayTmp.Array;
                }
                double avg_time_ms = (sum / repeat) / 1000000.0; // Конвертируем в миллисекунды
                writeToCSV("sorting_times.csv", "InsertionSort", arrayType, j, avg_time_ms);
                cout << "Insertion sort: " << avg_time_ms << " ms" << endl;
            }
            sum = 0;
            
            {
                arraySort array, arrayTmp;
                if (arrayType == "Random") array.fillRandom(j);
                else if (arrayType == "Increasing") array.fillIncreasing(j);
                else array.fillDecreasing(j);
                
                arrayTmp.arraySize = array.arraySize;
                arrayTmp.Array = array.Array;
                
                for (int i = 0; i < repeat; i++)
                {
                    const auto start = tick();
                    array.selectionSort();
                    const auto end = tick();
                    const auto res = end - start;
                    sum += res;
                    array.Array = arrayTmp.Array;
                }
                double avg_time_ms = (sum / repeat) / 1000000.0;
                writeToCSV("sorting_times.csv", "SelectionSort", arrayType, j, avg_time_ms);
                cout << "Selection sort: " << avg_time_ms << " ms" << endl;
            }
            sum = 0;
            
            {
                arraySort array, arrayTmp;
                if (arrayType == "Random") array.fillRandom(j);
                else if (arrayType == "Increasing") array.fillIncreasing(j);
                else array.fillDecreasing(j);
                
                arrayTmp.arraySize = array.arraySize;
                arrayTmp.Array = array.Array;
                
                for (int i = 0; i < repeat; i++)
                {
                    const auto start = tick();
                    array.quickSort(0, array.arraySize - 1);
                    const auto end = tick();
                    const auto res = end - start;
                    sum += res;
                    array.Array = arrayTmp.Array;
                }
                double avg_time_ms = (sum / repeat) / 1000000.0;
                writeToCSV("sorting_times.csv", "QuickSort", arrayType, j, avg_time_ms);
                cout << "Quick sort: " << avg_time_ms << " ms" << endl;
            }
            sum = 0;
             
            cout << endl;
        }
    }
    
    cout << "Results saved to sorting_times.csv" << endl;
}

void getData()
{
    arraySort array(5), array1(5), array2(5), array3(5), array4(5), array5(5);
    array.getArrayFromUser();
    array1.Array = array.Array;
    array2.Array = array.Array;
    array3.Array = array.Array;
    array4.Array = array.Array;
    array5.Array = array.Array;

    cout << "Original array: ";
    array.printArray();

    cout << "===== Insertion sort =====" << endl;
    array.insertionSort();
    array.printArray();

    cout << "===== Selection sort =====" << endl;
    array1.selectionSort();
    array1.printArray();

    cout << "===== Gnome sort =====" << endl;
    array2.gnomeSort(1, 2);
    array2.printArray();

    cout << "===== Quick sort =====" << endl;
    array3.quickSort(0, array3.arraySize - 1);
    array3.printArray();

    cout << "===== Merge sort =====" << endl;
    array4.mergeSort(0, array4.arraySize - 1);
    array4.printArray();

    cout << "===== Heap sort =====" << endl;
    array5.heapSort();
    array5.printArray();
}

int main()
{
    
    cout << "=== COMPARATIVE ANALYSIS OF SORTING ALGORITHMS ===" << endl;
    time();
    
    system("python3 plots.py");

    system("rm  sorting_times.csv");
    return 0;
}