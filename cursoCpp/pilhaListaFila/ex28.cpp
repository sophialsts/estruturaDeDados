#include <iostream>
#include <queue>
using namespace std;

void imprimirElementosFila(queue<int> &fila) {
    cout << "Elementos da Fila:" << endl;
    while (!fila.empty()) {
        int elemento = fila.front();
        cout << elemento << endl;
        fila.pop();
    }
}

int main() {
    queue<int> fila;
    int n = 6, elemento;
    
    cout << "Informe os elementos da fila: " << endl;

    for(int i=0;i<n;i++){
        cin >> elemento;
        fila.push(elemento); 
    }

    cout << "Primeiro elemento da Fila: " << fila.front() << endl;
    cout << "Último elemento da Fila: " << fila.back() << endl;
    cout << "Os elementos da fila são: " << endl;
    for(int it = fila.begin();it=fila.end();it++)

    imprimirElementosFila(fila);
}