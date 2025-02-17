import pandas as pd
import matplotlib.pyplot as plt

# Чтение данных из CSV файла
data = pd.read_csv('../sorting_times.csv')

# Уникальные алгоритмы и типы массивов
algorithms = data['Algorithm'].unique()
array_types = data['ArrayType'].unique()

# Создание графиков
fig, axes = plt.subplots(1, len(array_types), figsize=(15, 5))
fig.suptitle('Время работы алгоритмов сортировки')

for j, array_type in enumerate(array_types):
    ax = axes[j]
    for algorithm in algorithms:
        subset = data[(data['Algorithm'] == algorithm) & (data['ArrayType'] == array_type)]
        ax.plot(subset['Size'], subset['Time(ms)'], marker='o', label=algorithm)
    ax.set_title(f'Тип массива: {array_type}')
    ax.set_xlabel('Размер массива')
    ax.set_ylabel('Время (мс)')
    ax.legend()

plt.tight_layout()
plt.show()
