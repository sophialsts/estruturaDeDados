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
            inicio = novo;
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
            else { //
                if(atual == inicio) { //elemento é o primeiro
                    novo->prox = inicio;
                    inicio = novo;
                }
                else {
                    //atual->info >= novo->info
                    anterior->prox = novo;
                    novo->prox = atual;
                }
            }
        }
    }

    void deletar(int n) {
        if(inicio == nullptr) {
            cout << "Não há itens para deletar" << endl;
            return;
        }

        nodo *atual = inicio;
        nodo *anterior = nullptr;

        while(atual != nullptr) {
            if(atual->info == n) {
                if(anterior != nullptr) {
                    anterior->prox = atual->prox;
                }
                else {
                    inicio = atual->prox;
                }
                delete atual;
                cout << "Item deletado" << endl;
                break;
            }
            anterior = atual;
            atual = atual->prox;
        }
    }

    void listar () {
        if(inicio == nullptr){
            cout << "Não há itens para listar" << endl;
            return;
        }

        nodo *atual = inicio;
        int i = 1;

        while(atual != nullptr) {
            cout << i << "° elemento = " << atual->info << endl;
            i++;
            atual = atual->prox;
        }
    }
};

int main() {

    ListaOrdenada minhaLista;
    minhaLista.inserir(3);
    minhaLista.deletar(3);
    minhaLista.listar();

}