namespace SortTimeComparison
{
    public static class ArrayGenerator
    {
        public static int[] GenerateSortedArray(int n)
        {
            int[] Array = Enumerable.Range(1, n).ToArray();
            return Array;
        }

        public static int[] GenerateReversedSortedArray(int n)
        {
            int[] Array = Enumerable.Range(1, n).Reverse().ToArray();
            return Array;
        }

        public static int[] GenerateRandomArray(int n)
        {
            Random random = new Random();
            int[] Array = Enumerable.Range(1, 100).OrderBy(i => random.Next()).ToArray();
            return Array;
        }
    }
}