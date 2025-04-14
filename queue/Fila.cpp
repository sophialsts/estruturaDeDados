#include <iostream>
using namespace std;
#define MAX 10

class FilaArray {
private:
    int final = -1;
    int vetor[MAX];

public:
    FilaArray() {} 

    int getVetor(int p) {
        return vetor[p];
    }

    void setVetor(int pos, int valor) {
        vetor[pos] = valor;
    }

    void addNaFila(int numero) {
        if (final == MAX - 1) {
            cout << "Fila cheia";
        } else {
            final++;
            vetor[final] = numero;
            cout << "novo elemento adicionado: " << vetor[final] << endl;
        }
    }

    void removeDaFila() {
        if (final == -1) {
            cout << "Fila vazia.";
            return;
        } else {
            cout << "elemento removido: " << vetor[0] << endl;
            for (int i = 0; i < final; i++) {
                vetor[i] = vetor[i + 1];
            }
            final--;  
        }
    }

    void listarFila() {
        if (final == -1) {
            cout << "Fila vazia.";
            return;
        } else {
            cout << "Elementos na fila:" << endl;
            for (int i = 0; i <= final; i++) {  
                cout << vetor[i] << endl;
            }
        }
    }
};

int main() {
    FilaArray novaFila;
    novaFila.addNaFila(5);
    novaFila.addNaFila(10);
    novaFila.listarFila();
    novaFila.removeDaFila();
    novaFila.listarFila();
}