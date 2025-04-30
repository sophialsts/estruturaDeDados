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

    void retirar(int n) {
        nodo2 *atual;

        if(inicio == nullptr) return;

        atual = inicio;

        while((atual != nullptr) && (n != atual->info)) atual = atual->prox;

            if(atual == nullptr) {
                cout << "Número não está na lista para se retirar";
            }
            else {
                if((inicio == atual) && atual->prox == nullptr) { //o elemento é o único da lista
                    atual = nullptr; 
                    return;
                }
                else if(inicio == atual) { //o elemento é o primeiro da lista(tem outros depois)
                    inicio = inicio->prox;
                    inicio->ant = nullptr; //ou atual = nullptr;
                }
                else {
                    if(atual->prox == nullptr) atual->ant->prox = nullptr; //elemento encontrado é o último da lista
                    else {
                        atual->ant->prox = atual->prox;
                        atual->prox->ant = atual->ant;
                    }
                }
                delete atual;
            }
    }

    void listar() {
        nodo2 *atual;
        int i = 1;

        atual = inicio;
        cout << "Lista:" <<endl;
        while(atual != nullptr) {
            cout << "Elemento " << i << "º: " << atual->info << endl;
            atual = atual->prox;
            i++;
        }

        cout << "Fim da lista." << endl;
    }

};

int main() {

    ListaDupla myList;
    myList.inserir(2);
    myList.inserir(5);
    myList.inserir(1);
    myList.inserir(3);
    myList.listar();
    myList.retirar(3); //falha de segmentação
    myList.listar();

}