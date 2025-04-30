// fazer a lista normal, e fazer 2 sublistas de pares e ímpares baseado nessa lista principal

#include <iostream>
using namespace std;

struct nodo2 {
    int info;
    struct nodo2 *ant, *prox, *proxIgual;
};

class ListaDupla {
    private:
    nodo2 *inicio, *impares, *pares;

    public:
    ListaDupla() { 
        inicio = nullptr;
        impares = nullptr;
        pares = nullptr;
     }

    void inserir(int n) {
        nodo2 *novo, *atual;
        novo = new nodo2();

        if(novo == nullptr) return;

        novo->info = n;

        if(inicio == nullptr) { //vai ser o primeiro elemento
            novo->ant = nullptr;
            novo->prox = nullptr;
            inicio = novo;
            if(novo->info % 2) {
                impares->proxIgual = nullptr;
                impares = novo;
            }
            else {
                pares->proxIgual = nullptr;
                pares = novo;
            }
            return;
        }

        atual = inicio;

        while((atual->prox != nullptr) && (novo->info > atual->info)) atual = atual->prox;

            if((atual->prox == nullptr) && (novo->info > atual->info)) { //fim
                atual->prox = novo;
                novo->ant = atual;
                novo->prox = nullptr;
                if(novo->info % 2) {
                    impares->proxIgual = novo;
                    impares->proxIgual->proxIgual = nullptr;
                }
                else {
                    pares->proxIgual = novo;
                    pares->proxIgual->proxIgual = nullptr;
                }
                return;
            }
            else if(atual == inicio) { //inicio
                novo->prox = inicio;
                inicio->ant = novo;
                novo->ant = nullptr;
                inicio = novo;
                if(novo->info % 2) {
                    novo->prox = impares;
                    impares = novo;
                }
                else {
                    novo->prox = pares;
                    pares = novo;
                }
                return;
            }
            else { //meio
                novo->ant = atual->ant;
                atual->ant->prox = novo;
                novo->prox = atual;
                atual->ant = novo;
                if(novo->info % 2) {
                    novo->prox = impares;
                    impares = novo;
                }
                else {
                    novo->prox = pares;
                    pares = novo;
                }
            }

    }

};

int main() {

}
