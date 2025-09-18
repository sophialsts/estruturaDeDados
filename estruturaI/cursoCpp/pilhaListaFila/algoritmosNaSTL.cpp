#include <iostream>
#include <vector>
#include <algorithm> // Para sort, find, count, min, max
using namespace std; // Adicionado para usar diretamente os nomes do namespace std
int main() {
    vector<int> numeros = {4, 2, 9, 1, 5, 9};
    // Exemplo de sort
    cout << "Lista original: ";
    for (int num : numeros) {
        cout << num << " ";
    }
    cout << endl;

    sort(numeros.begin(), numeros.end());
    cout << "Lista ordenada: ";
    for (int num : numeros) {
        cout << num << " ";
    }
    cout << endl;
    // Exemplo de find
    auto it = find(numeros.begin(), numeros.end(), 9);
    if (it != numeros.end()) {
        cout << "Elemento 9 encontrado na posição: " << it - numeros.begin() << endl;
    } else {
        cout << "Elemento 9 não encontrado." << endl;
    }
    // Exemplo de count
    int count_9 = count(numeros.begin(), numeros.end(), 9);
    cout << "O número 9 aparece " << count_9 << " vez(es) na lista." << endl;
    // Exemplo de min e max
    auto min = min_element(numeros.begin(), numeros.end());
    auto max = max_element(numeros.begin(), numeros.end());
    cout << "Menor elemento: " << *min << endl;
    cout << "Maior elemento: " << *max << endl;
    return 0;
}
