def partition(array, low, high, isMiddle):
    
    if(isMiddle):
        pivot_index = (low + high) // 2     
        pivot = array[pivot_index]
    else:
        pivot_index = low
        pivot = array[low]

    i = low
    j = high

    while True:
        # avança i até achar algo >= pivô
        while array[i] < pivot:
            i += 1
        # recua j até achar algo <= pivô
        while array[j] > pivot:
            j -= 1

        if i >= j:
            return j  # ponto de corte

        # troca elementos fora do lugar
        array[i], array[j] = array[j], array[i]
        i += 1
        j -= 1

def quickSort(array, low, high, isMiddle):
    if low < high:
        pi = partition(array, low, high, isMiddle)
        quickSort(array, low, pi, isMiddle)       # esquerda (até o corte)
        quickSort(array, pi + 1, high, isMiddle)  # direita (depois do corte)
