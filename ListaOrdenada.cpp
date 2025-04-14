#include <iostream>
using namespace std;

struct nodo {
    int info;
    struct nodo *prox;
};

class ListaOrdenada {
    private:
    nodo *inicio;

    public:

    ListaOrdenada() {
        inicio = nullptr;
    }

    void inserir(int n) {
        nodo *novo = new nodo();
        nodo *ant, *atual;

        if(novo == nullptr) {
            return;
        }

        novo->info = n;
        if(inicio == nullptr) {
            inicio->prox = nullptr;
            inicio = novo;
        }
        else {
            atual = inicio;
            while((atual != nullptr) && atual->info < novo->info) {
                ant = atual;
                atual = atual->prox;
            }

            if(atual == nullptr) {
                ant->prox = novo;
                atual = novo; //verificar
                novo->prox = nullptr;
            }
            else {
                if(atual == inicio) {
                    novo->prox = inicio;
                    inicio = novo;
                }
                else {
                    
                }
            }
        }

    }
};

int main() {

}