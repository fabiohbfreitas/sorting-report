import pandas as pd
import matplotlib.pyplot as plt

# Load the CSV data into a pandas DataFrame
df = pd.read_csv('sort.csv')

# Create the column graph with a logarithmic scale
plt.figure(figsize=(10, 6))
df.plot(kind='bar', x='size', y=['bubblesort', 'mergesort', 'quicksort'], rot=0, logy=True)

# Add labels and title
plt.xlabel('Tamanho Array')
plt.ylabel('Tempo (segundos)')
plt.title('Algoritmos de Ordenação (Escala logarítmica)')
plt.legend()

# Save the graph as an image file
plt.savefig('sorting_algorithms.png', dpi=300)
