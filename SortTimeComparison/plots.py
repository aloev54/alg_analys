import matplotlib.pyplot as plt
import pandas as pd

file_path = "/Users/aloevartyom/Documents/dev/cs/ConsoleApp1/sorting_times.csv"

df = pd.read_csv(file_path)

df_ls = df[df["ArrayType"] == "л.с"]
df_hc = df[df["ArrayType"] == "х.c"]

fig, axes = plt.subplots(1, 2, figsize=(12, 5))
fig.suptitle(
    "Время работы алгоритмов сортировки в зависимости от размера массива", fontsize=14)


def plot_graph(ax, df_subset, title):
    for algo in df_subset["Algorithm"].unique():
        subset = df_subset[df_subset["Algorithm"] == algo]
        ax.plot(subset["Size"], subset["Time(ms)"],
                marker='o', linestyle='-', label=algo)
    ax.set_title(title)
    ax.set_xlabel("Размер массива")
    ax.set_ylabel("Время (мс)")
    ax.legend()
    ax.grid(True)


plot_graph(axes[0], df_ls, "Алгоритмы на л.с")
plot_graph(axes[1], df_hc, "Алгоритмы на х.c")

plt.tight_layout(rect=[0, 0, 1, 0.96])
plt.show()
