#include <iostream>
using namespace std;

struct nodo {
    int num;
    struct nodo *prox;
};

class ExistCicle {

    private:
    nodo *inicio;

    public:
    ExistCicle() {
        inicio = nullptr;
    }

    bool existCicle() {
        nodo *usados, *atual;

        if(inicio != nullptr) {
            atual = inicio;
            usados = inicio->prox;
        }

        while(usados->prox != nullptr) {
            do{
                if(atual->prox == usados) {
                    return true;
                }
                atual = atual->prox;
            } while(atual->prox != usados);
            usados = usados->prox;
            atual = inicio;
        }

        if(usados->prox == nullptr) {
            return false;
        }

    }

    void ciclo(nodo *inicio) {
        nodo *aux, *atual, *ciclo;
        ciclo = nullptr;
        atual = inicio;
        if(inicio == nullptr) {
            cout << "Vazio";
            return;
        }

        while(atual != nullptr) {
            aux = inicio;
            while(aux != atual) {
                if(atual->prox == aux) {
                    ciclo = aux;
                    break;
                }
                aux = aux->prox;
            }
            if(ciclo != nullptr) {
                //imprimeciclo();
                break;
            }
            atual = atual->prox;
            if(atual == nullptr) cout << "?";
        }

    }
};
