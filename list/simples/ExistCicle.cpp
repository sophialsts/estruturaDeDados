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
        inicio = new nodo();
    }

    void testeListaCircular() {
        inicio->prox = new nodo();
        inicio->prox->prox = new nodo();
        inicio->prox->prox->prox = inicio->prox;
        
        if(existCicle()) {
            cout << "Encontrou ciclo!" << endl;
        } else {
            cout << "Não há ciclo." << endl;
        }
    }

    bool existCicle() {
        nodo *usados, *atual;

        if(inicio != nullptr) {
            usados = inicio;
            atual = inicio->prox;
        }

        while(atual != nullptr) {

            if(atual->prox == usados) {
                return true;
            }

            while(usados != atual) {
                if(atual->prox == usados) {
                    return true;
                }
                usados = usados->prox;
            }

            usados = inicio;
            atual = atual->prox;

        }

        if(atual == nullptr) return false;

    }

    /*void ciclo(nodo *inicio) {
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

    }*/
};

int main() {

    ExistCicle ex1;
    ex1.testeListaCircular();

}
