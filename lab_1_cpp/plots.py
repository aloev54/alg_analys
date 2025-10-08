import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv('sorting_times.csv')

algorithms = data['Algorithm'].unique()
array_types = data['ArrayType'].unique()


for array_type in array_types:
    plt.figure(figsize=(10, 5)) 
    for algorithm in algorithms:
        subset = data[(data['Algorithm'] == algorithm) & (data['ArrayType'] == array_type)]
        plt.plot(subset['Size'], subset['Time(ms)'], marker='o', label=algorithm)
    
    plt.title(f'Тип массива: {array_type}')
    plt.xlabel('Размер массива')
    plt.ylabel('Время (мс)')
    plt.legend()
    plt.tight_layout()
    plt.show()  