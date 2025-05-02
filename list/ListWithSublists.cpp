// fazer a lista normal, e fazer 2 sublistas de pares e ímpares baseado nessa lista principal

#include <iostream>
using namespace std;

struct nodo2 {
    int info;
    struct nodo2 *prox, *ant, *proxImpar, *proxPar; //usar ant para sublista
};

class ListWithSublists {
    private:
    nodo2 *inicio,*impares, *pares;
    nodo2 *auxPar, *auxImpar;

    public:
    ListWithSublists() { 
        inicio = nullptr;
        impares = nullptr;
        pares = nullptr;
        auxPar = nullptr;
        auxImpar = nullptr;
     }

     void inserir(int n) {
        nodo2 *novo = new nodo2();
        if (!novo) return; 
    
        novo->info = n;
        novo->prox = novo->ant = nullptr;
        novo->proxPar = novo->proxImpar = nullptr;
    
        // inserção na lista principal
        if (inicio == nullptr) { // lista vazia
            inicio = novo;
        } 
        else {
            nodo2 *atual = inicio;
            nodo2 *anterior = nullptr;
    
            while (atual != nullptr && atual->info < novo->info) {
                anterior = atual;
                atual = atual->prox;
            }
    
            if (anterior == nullptr) { //inicio
                novo->prox = inicio;
                inicio->ant = novo;
                inicio = novo;
            } 
            else { // insere no meio ou no final
                anterior->prox = novo;
                novo->ant = anterior;
                novo->prox = atual;
                if (atual != nullptr) {
                    atual->ant = novo;
                }
            }
        }
    
        // atualiza os pares e impares
        if (n % 2 == 0) { 
            if (pares == nullptr) {
                pares = auxPar = novo;
            } 
            else {
                auxPar->proxPar = novo; 
                auxPar = novo;
            }
        } 
        else { 
            if (impares == nullptr) {
                impares = auxImpar = novo;
            } 
            else {
                auxImpar->proxImpar = novo; 
                auxImpar = novo;
            }
        }
    }

        void listarCompleted() {
            nodo2 *atual;
            int i = 1;
    
            atual = inicio;
            cout << "Lista completa:" <<endl;
            while(atual != nullptr) {
                cout << "Elemento " << i << "º: " << atual->info << endl;
                atual = atual->prox;
                i++;
            }
    
            cout << "Fim da lista." << endl;
            cout << endl;
        }

        void listarPares() {
            nodo2 *atual;
            int i = 1;
    
            atual = pares;
            cout << "Sublista dos pares:" <<endl;
            while(atual != nullptr) {
                cout << "Elemento " << i << "º: " << atual->info << endl;
                atual = atual->proxPar;
                i++;
            }
    
            cout << "Fim da lista." << endl;
            cout << endl;
        }

        void listarImpares() {
            nodo2 *atual;
            int i = 1;
    
            atual = impares;
            cout << "Sublista dos ímpares:" <<endl;
            while(atual != nullptr) {
                cout << "Elemento " << i << "º: " << atual->info << endl;
                atual = atual->proxImpar;
                i++;
            }
    
            cout << "Fim da lista." << endl;
            cout << endl;
        }

};

int main() {

    ListWithSublists minhaLista;

    minhaLista.inserir(5);
    minhaLista.inserir(3);
    minhaLista.inserir(11);
    minhaLista.inserir(6);
    minhaLista.inserir(10);
    minhaLista.listarCompleted();
    minhaLista.listarImpares();
    minhaLista.listarPares();

}
