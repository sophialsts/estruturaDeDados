#include <iostream>
using namespace std;

struct nodo2 {
    int info;
    struct nodo2 *ant, *prox;
};

class ListaDupla {
    private:
    nodo2 *inicio;

    public:
    ListaDupla() { inicio = nullptr; }

    void inserir(int n) {
        nodo2 *novo, *atual;
        novo = new nodo2();

        if(novo == nullptr) return;

        novo->info = n;

        if(inicio == nullptr) {
            novo->ant = nullptr;
            novo->prox = nullptr;
            inicio = novo;
            return;
        }

        atual = inicio;

        while((atual->prox != nullptr) && (novo->info > atual->info)) atual = atual->prox;

            if((atual->prox == nullptr) && (novo->info > atual->info)) { //fim
                atual->prox = novo;
                novo->ant = atual;
                novo->prox = nullptr;
                return;
            }
            else if(atual == inicio) { //inicio
                novo->prox = inicio;
                inicio->ant = novo;
                novo->ant = nullptr;
                inicio = novo;
                return;
            }
            else { //meio
                novo->ant = atual->ant;
                atual->ant->prox = novo;
                novo->prox = atual;
                atual->ant = novo;
            }

    }

};