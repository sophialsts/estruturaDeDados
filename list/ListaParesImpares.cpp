// fazer a lista normal, e fazer 2 sublistas de pares e ímpares baseado nessa lista principal

#include <iostream>
using namespace std;

struct nodo2 {
    int info;
    struct nodo2 *ant, *prox;
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
        bool isEven;
        novo = new nodo2();

        if(novo == nullptr) return;

        novo->info = n;

        if(novo->info % 2) isEven = false;
        else isEven = true;

        if(inicio == nullptr) { //vai ser o primeiro elemento
            novo->ant = nullptr;
            novo->prox = nullptr;
            inicio = novo;
            if(isEven) {
                impares->prox = nullptr;
                impares = novo;
            }
            else {
                pares->prox = nullptr;
                pares = novo;
            }
            return;
        }

        atual = inicio;

        while((atual->prox != nullptr) && (novo->info > atual->info)) atual = atual->prox;

            if((atual->prox == nullptr) && (novo->info > atual->info)) { //adicionar o novo no fim
                atual->prox = novo;
                novo->ant = atual;
                novo->prox = nullptr;
                if(isEven) {
                    impares->prox = novo;
                    impares->prox->prox = nullptr;
                }
                else {
                    pares->prox = novo;
                    pares->prox->prox = nullptr;
                }
                return;
            }
            else if(atual == inicio) { //adicionar o novo no inicio (1ª posição)
                novo->prox = inicio;
                inicio->ant = novo;
                novo->ant = nullptr;
                inicio = novo;
                if(isEven) {
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
                if(isEven) {
                    
                }
                else {

                }
            }
        }

};

int main() {

}
