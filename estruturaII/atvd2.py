import time
import pandas as pd
from algoritmos import quickSort, shellSort

data = pd.read_csv('ai_assistant_usage_student_life.csv')

colunas = ['SessionLengthMin','TotalPrompts', 'AI_AssistanceLevel', 'SatisfactionRating']

i=0
for x in colunas:
    print(f"{i} - {x}")
    i+=1
op = input("Escolha umas das colunas:")

op2 = input("1 - Pivô no início \n2 - Pivô no meio \nEscolha: \n")
    
pivotMiddle = True

if(op2 == '1'): 
    pivotMiddle = False
    
match op:
    case '0':
        coluna = colunas[0]
        arr = data[coluna].tolist() 
        arr2 = arr 
        inicial_quick_sort = time.time()
        quickSort(arr, 0, len(arr) - 1, pivotMiddle)
        final_quick_sort = time.time()
        print(f"Duração do Quick Sort foi: {final_quick_sort-inicial_quick_sort:.2}")
        print("Array ordenado pelo QuickSort:", arr[:15])
        inicial_shell_sort = time.time()
        shellSort(arr2)
        final_shell_sort = time.time()
        print(f"Duração do Shell Sort foi: {final_shell_sort-inicial_shell_sort:.2}")
        print("Array ordenado pelo ShellSort:", arr2[:15])
    case '1':
        coluna = colunas[1]
        arr = data[coluna].tolist()  
        quickSort(arr, 0, len(arr) - 1, pivotMiddle)
        print("Array ordenado:", arr[:15])
    case '2':
        coluna = colunas[2]
        arr = data[coluna].tolist()  
        quickSort(arr, 0, len(arr) - 1, pivotMiddle)
        print("Array ordenado:", arr[:15])
    case '3':
        coluna = colunas[3]
        arr = data[coluna].tolist()  
        quickSort(arr, 0, len(arr) - 1, pivotMiddle)
        print("Array ordenado:", arr[:15])