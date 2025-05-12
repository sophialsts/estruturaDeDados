#include <iostream>
using namespace std;

/*Escreva uma função, em Cpp, para somar dois números inteiros. Cada número
está armazenado em uma lista simplesmente encadeada dinâmica, e cada nó
da lista contém um dígito de um número e um apontador para o próximo nó. O
primeiro nó de cada lista contém o dígito mais significativo (dígito mais à
esquerda do número) e o último nó de cada lista contém o dígito menos
significativo (dígito mais à direita do número). A função deve receber como
parâmetros o endereço do início da lista que contém o primeiro número e o
endereço do início da lista que contém o segundo (as duas listas já existem). A
função deve retornar o endereço do início da lista que conterá o número
correspondente à soma dos dois números. Veja o exemplo abaixo que soma os
números 581133 e 118:*/

struct nodo {
    int num;
    struct nodo *prox;
};

class SumLists{

    private:
    nodo *inicio1, *inicio2, *inicio3;

    public:
    SumLists() {
        inicio1 = nullptr;
        inicio2 = nullptr;
        inicio3 = nullptr;
    }

    void inserirLista1(int number) {
        nodo *novo = new nodo();

        novo->num = number;
        if(inicio1 == nullptr) {
            inicio1 = novo;
            return;
        }

        if(inicio1->prox == nullptr) {
            inicio1->prox = novo;
            return;
        }

        nodo *atual = inicio1;

        while(atual->prox != nullptr) {
            atual = atual->prox;
        }

        atual->prox = novo;

    }

    void inserirLista2(int number) {
        nodo *novo = new nodo();

        novo->num = number;
        if(inicio2 == nullptr) {
            inicio2 = novo;
            return;
        }

        if(inicio2->prox == nullptr) {
            inicio2->prox = novo;
            return;
        }

        nodo *atual = inicio1;

        while(atual->prox != nullptr) {
            atual = atual->prox;
        }

        atual->prox = novo;

    }

    void sumLists() {
        nodo *aux1, *aux2;
        nodo *atualResult = new nodo();

        aux1 = inicio1;
        aux2 = inicio2;
        inicio3 = atualResult;

        while(aux1->prox != nullptr && aux2->prox != nullptr){
            nodo *novo = new nodo();
            if(aux1->num + aux2->num >= 10) 
            atualResult->num = aux1->num + aux2->num;
            aux1 = aux1->prox;
            aux2 = aux2->prox;
            atualResult->prox = novo;
            atualResult = atualResult->prox;
        }

        if(aux1->prox == nullptr && aux2->prox == nullptr) {
            return;
        }


    }

    void listar1 () {
        if(inicio1 == nullptr){
            cout << "Não há itens para listar" << endl;
            return;
        }

        nodo *atual = inicio1;
        int i = 1;
        
        while(atual != nullptr) {
            cout << i << "° elemento = " << atual->num << endl;
            i++;
            atual = atual->prox;
        }

    }

    void listar2 () {
        if(inicio2 == nullptr){
            cout << "Não há itens para listar" << endl;
            return;
        }

        nodo *atual = inicio2;
        int i = 1;
        
        while(atual != nullptr) {
            cout << i << "° elemento = " << atual->num << endl;
            i++;
            atual = atual->prox;
        }

    }

    void listar3 () {
        if(inicio3 == nullptr){
            cout << "Não há itens para listar" << endl;
            return;
        }

        nodo *atual = inicio3;
        int i = 1;
        
        while(atual != nullptr) {
            cout << i << "° elemento = " << atual->num << endl;
            i++;
            atual = atual->prox;
        }

    }

};

int main() {

    SumLists objeto;

    objeto.inserirLista1(3);
    objeto.inserirLista1(5);
    objeto.inserirLista1(8);
    objeto.listar1();
}