namespace SortTimeComparison
{
    public static class SortingAlgorithms
    {
        public static void BubbleSort(int[] Array)
        {
            bool swapped = false;

            for (int i = 0; i < Array.Length; i++)
            {
                for (int j = 0; j < Array.Length - i - 1; j++)
                {
                    if (Array[j] > Array[j + 1])
                    {
                        int buf = Array[j];
                        Array[j] = Array[j + 1];
                        Array[j + 1] = buf;
                        swapped = true;
                    }
                }
                if (!swapped)
                {   
                    break;
                }
            }
        }

        public static void InsertionSort(int[] Array)
        {
            for (int i = 1; i < Array.Length; i++)
            {
                int key = Array[i];
                int j = i - 1;

                while (j >= 0 && Array[j] > key)
                {
                    Array[j + 1] = Array[j];
                    j--;
                }

                Array[j + 1] = key;
            }
        }

        public static void QuickSort(int[] Array, int minInd, int maxInd)
        {
            if (minInd < maxInd)
            {
                int pivot = GetPivot(Array, minInd, maxInd);

                QuickSort(Array, minInd, pivot - 1);
                QuickSort(Array, pivot + 1, maxInd);
            }

        }

        private static int GetPivot(int[] Array, int minInd, int maxInd)
        {
            int pivot = Array[maxInd];
            int i = minInd - 1;

            for (int j = minInd; j < maxInd; j++)
            {
                if (Array[j] <= pivot)
                {
                    i++;
                    Swap(Array, i, j);

                }
            }
            Swap(Array, i + 1, maxInd);

            return i + 1;
        }

        private static void Swap(int[] Array, int i, int j)
        {
            int buf = Array[i];
            Array[i] = Array[j];
            Array[j] = buf;
        }
    }
}

