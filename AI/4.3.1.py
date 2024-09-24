import numpy as np
import matplotlib.pyplot as plt

# Генерация массива случайных значений
np.random.seed(42)  # для воспроизводимости результатов
array_size = 10000
random_array = np.random.uniform(0, 1, array_size)

# Вычисление среднего и медианы
mean_value = np.mean(random_array)
median_value = np.median(random_array)

print(f"Среднее значение: {mean_value:.4f}")
print(f"Медианное значение: {median_value:.4f}")

# Создание точечной диаграммы рассеяния
plt.figure(figsize=(10, 6))
plt.scatter(range(array_size), random_array, alpha=0.5)
plt.axhline(y=mean_value, color='r', linestyle=':', label='Среднее')
plt.axhline(y=median_value, color='g', linestyle='--', label='Медиана')
plt.xlabel('Индекс')
plt.ylabel('Значение')
plt.title('Диаграмма рассеяния случайных значений')
plt.legend()
plt.grid(True)
plt.show()