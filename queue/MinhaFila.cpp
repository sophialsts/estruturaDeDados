#include <iostream>
using namespace std;

struct nodo {
    int info;
    struct nodo *prox;
};

class Fila {
    private:
    nodo *inicio, *fim;

    public:
    Fila () {
        inicio = nullptr;
        fim = nullptr;
    }

    void inserir(int n) {
        nodo *novo = new nodo();

        if(novo == nullptr) {
            cout << "Sem memória";
            return;
        }
        novo->info = n;
        novo->prox = nullptr;

        if(inicio == nullptr) inicio = novo;
        else fim->prox = novo; //conecta o novo nó com o último fim(esse fim ainda não é novo porque não foi atualizado)
        fim = novo; //aqui atualiza o fim para ser novo
    }

    int retirar() {
        if(inicio == nullptr) {
            cout << "Sua fila está vazia" << endl;
            return -1;
        }

        nodo *aux = inicio;
        inicio = inicio->prox; //conectando nó 
        int n = aux->info; //colocando informação
        delete aux;
        return n;

        /*
        nodo *aux = inicio;
        int n = inicio->info;
        inicio = inicio->prox
        delete aux;
        return n;
        */

    }

    int verificaFila() {
        if(inicio == nullptr) {
            return 0;
        }
        else {
            return 1;
        }
    }

    void listar() {
        if(!verificaFila()) {
            cout << "A fila está vazia." << endl;
            return;
        }
        
        nodo *temp = inicio;

        while(temp != nullptr) {
            cout << temp->info << endl;
            temp = temp->prox;
        }

        delete temp;

    }

};

int main() {

    Fila minhaFilinha;

    minhaFilinha.inserir(10);
    minhaFilinha.inserir(9);
    minhaFilinha.inserir(8);
    minhaFilinha.listar();
    cout << "Essa foi a primeira fila." << endl;
    minhaFilinha.retirar();
    minhaFilinha.listar();
    cout << "Essa é a fila tirando um elemento" << endl;

    return 0;
}