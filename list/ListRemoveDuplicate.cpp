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
        nodo *anterior, *atual;

        if(novo == nullptr) {
            return;
        }

        novo->info = n;
        if(inicio == nullptr) {
            inicio = novo; //move novo para inicio
            inicio->prox = nullptr;
        }
        else {
            atual = inicio; //ponteiro que vai percorrer para verificar onde encaixar o elemento
            while((atual != nullptr) && atual->info < novo->info) {
                anterior = atual;
                atual = atual->prox;
            }

            if(atual == nullptr) { //elemento vai ser colocado por último
                anterior->prox = novo;
                novo->prox = nullptr;
            }
            else if(atual == inicio){ //elemento é o primeiro
                novo->prox = inicio;
                inicio = novo;
            }
            else {
                anterior->prox = novo;
                novo->prox = atual;
            }
        }
    }

    void listar () {
        if(inicio == nullptr){
            cout << "Não há itens para listar" << endl;
            return;
        }

        cout << "Lista ";
        cout << endl;

        nodo *atual = inicio;
        int i = 1;
        
        while(atual != nullptr) {
            cout << i << "° elemento = " << atual->info << endl;
            i++;
            atual = atual->prox;
        }

    }

    void removeRepetidos() {
        nodo *atual = inicio;

        while(atual != nullptr && atual->prox != nullptr) {
        nodo *aux = atual;
            while(aux->prox != nullptr){
                if(atual->info == aux->prox->info) {
                    nodo *removeRepetido = aux->prox;
                    aux->prox = removeRepetido->prox;
                    delete removeRepetido;
                }
                else aux = aux->prox;
            }

            atual = atual->prox;

        }

    }

};

int main() {

    ListaOrdenada minhaLista;
    minhaLista.inserir(3);
    minhaLista.inserir(5);
    minhaLista.inserir(4);
    minhaLista.inserir(4);
    minhaLista.inserir(2);
    minhaLista.inserir(2);
    minhaLista.removeRepetidos();
    minhaLista.listar();

}