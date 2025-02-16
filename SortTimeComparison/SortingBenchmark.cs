using System.Diagnostics;
using System.Globalization;
using System.Text;

namespace SortTimeComparison
{
    public static class SortingBenchmark
    {
        public static void CalculateTimeAndSave(int[] N, Action<int[]> sortMethod, Func<int, int[]> generateArrayMethod, string methodName, string arrayType, string filePath)
        {
            CultureInfo culture = CultureInfo.InvariantCulture;
            StringBuilder sb = new StringBuilder();

            foreach (var n in N)
            {
                Stopwatch stopwatch = new Stopwatch();

                int[] Array = generateArrayMethod(n);

                sortMethod((int[])Array.Clone()); // костыль, видимо JIT шалит

                stopwatch.Start();

                sortMethod(Array);

                stopwatch.Stop();

                double time = stopwatch.Elapsed.TotalMilliseconds;

                sb.AppendLine($"{methodName},{arrayType},{n},{time.ToString(culture)}");
            }

            File.AppendAllText(filePath, sb.ToString());
        }

        public static void CalculateTimeAndSaveQuick(int[] N, Func<int, int[]> generateArrayMethod, string arrayType, string filePath)
        {
            CultureInfo culture = CultureInfo.InvariantCulture;
            StringBuilder sb = new StringBuilder();

            foreach (var n in N)
            {
                Stopwatch stopwatch = new Stopwatch();

                int[] Array = generateArrayMethod(n);

                SortingAlgorithms.QuickSort((int[])Array.Clone(), 0, Array.Length - 1);

                stopwatch.Start();

                SortingAlgorithms.QuickSort(Array, 0, Array.Length - 1);

                stopwatch.Stop();

                double time = stopwatch.Elapsed.TotalMilliseconds;

                sb.AppendLine($"QuickSort,{arrayType},{n},{time.ToString(culture)}");
            }

            File.AppendAllText(filePath, sb.ToString());
        }


    }
}