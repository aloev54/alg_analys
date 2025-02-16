namespace SortTimeComparison
{
    public static class Helpers
    {
        public static void PrintArray(int[] Array)
        {
            foreach (var item in Array)
            {
                System.Console.Write(item + " ");
            }
            System.Console.WriteLine();
        }
    }
}