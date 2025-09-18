#include <iostream>
using namespace std;

struct nodo {
    int info;
    struct nodo *prox;
};

class ListaOrdenada {

    private:
    nodo *inicio;
    bool estaInvertido;

    public:

    ListaOrdenada() {
        inicio = nullptr;
        estaInvertido = false;
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
    

    void deletar (int n) {

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
                    inicio = atual->prox; //número identificado é o primeiro
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

        cout << "Lista ";
        if(estaInvertido) cout << "invertida";
        cout << endl;

        nodo *atual = inicio;
        int i = 1;
        
        while(atual != nullptr) {
            cout << i << "° elemento = " << atual->info << endl;
            i++;
            atual = atual->prox;
        }

    }

    void inverter () {

        if(inicio == nullptr || inicio->prox == nullptr){
            cout << "Não é possível inverter a lista" << endl;
            return;
        }

        nodo *ant = nullptr, *atual = inicio, *prox = nullptr;
        
        while(atual != nullptr) {
            prox = atual->prox;
            atual->prox = ant;
            ant = atual; //endereço de ant é o mesmo que atual
            atual = prox; //endereço de atual é o mesmo que prox(o antigo próximo)
        }

        inicio = ant;
        estaInvertido = !estaInvertido;

    }

};

int main() {

    ListaOrdenada minhaLista;
    minhaLista.inserir(3);
    minhaLista.inserir(5);
    minhaLista.inserir(4);
    minhaLista.inserir(2);
    minhaLista.deletar(2);
    minhaLista.listar();
    /*
    minhaLista.inverter();
    minhaLista.listar();
    minhaLista.deletar(4);
    minhaLista.listar();*/

}