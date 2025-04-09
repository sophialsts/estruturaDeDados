#include <iostream>
using namespace std;
 
struct Nodo {
    int info;
    struct Nodo* prox;
};
 
class PilhaD {
    private:
    Nodo *topo;
 
    public:
    PilhaD() {
        topo = nullptr;
    }

    int verificaPilha() {
        if(topo == nullptr) {
            return 0;
        }
        else {
            return 1;
        }
    }
 
    void empilhar(int n) {
        Nodo *novo;
        novo = new Nodo();
 
        if(novo == nullptr) {
            cout << "Falha na alocação de memória" << endl;
            return;
            }
 
        novo->info = n;
        novo->prox = topo; //como topo foi inicializado com nullptr, se a pilha tiver vazia aqui tbm vai ter esse valor
        topo = novo;
    }
 
    int desempilhar() {
        if(!verificaPilha()) {
            cout << "A pilha está vazia." << endl;
            return -1;
        }
        int valor = topo->info; //guardando info do topo
        Nodo *temp = this->topo;
        topo = topo->prox;
 
        if(temp == nullptr) {
            cout << "Falha na alocação de memória" << endl;
            return -1;
        }
 
       delete temp;
       return valor;
 
    }
 
    void listar() {
        if(!verificaPilha()) {
            cout << "A pilha está vazia." << endl;
            return;
        }
        
        Nodo *temp = topo;

        cout << temp->info << endl;
        while(temp->prox != nullptr) {
            temp = temp->prox;
            cout << temp->info << endl;
        }

        delete temp;

    }

};
 
int main() {
    
    PilhaD pilha;
    pilha.empilhar(2);
    pilha.empilhar(3);
    pilha.listar();
 
    /*(*novo).info = 3   ==    novo->info=3 */
}