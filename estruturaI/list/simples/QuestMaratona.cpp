#include <iostream>
using namespace std;

struct nodo {
    int valor;
    struct nodo *prox;
};

class QuestMaratona {

    private:
    nodo *inicio;

    public:

    QuestMaratona() { inicio = nullptr; }

    void criarLista() {

        if(inicio == nullptr) {
            char op = 's';
            int valor;
            while(op == 's'){
                cout << "Digite seu valor:";
                cin >> valor;
                nodo *novo = new nodo();
                novo->valor = valor;
                if(inicio == nullptr) {
                    inicio = novo;
                    inicio->prox = nullptr;
                }
                else if(inicio->prox == nullptr) {
                    novo->prox = nullptr;
                    inicio->prox = novo;
                }
                else {
                    nodo *aux = inicio;
                    while(aux->prox != nullptr) {
                        aux = aux->prox;
                    }
                    aux->prox = novo;
                    novo->prox = nullptr;
                }
                cout << "Deseja continuar?";
                cin >> op;
            }
        }


    }

    void listar() {

        nodo *atual = inicio;

        cout << "Lista: ";
        while(atual!=nullptr) {
            cout << atual->valor << " ";
            atual = atual->prox;
        }
        cout << endl;

    }

    int countLista() {

        if(inicio == nullptr) {
            cout << "Não há lista";
            return 0;
        }
        else {
            int i = 0;
            nodo *aux = inicio;
            while(aux != nullptr) {
                i++;
                aux = aux->prox;
            }
            return i;
        }
    }

    void insert() {

        if(inicio == nullptr) {
            cout << "Não há como inserir, não tem lista.";
            return;
        }

        int valor, posicao;

        cout << "Digite seu valor:";
        cin >> valor;

        cout << "Digite a posição que deseja inserir o valor:";
        cin >> posicao;

        int i = 0;
        nodo *aux = inicio;

        while(aux != nullptr) {
            i++;
            aux = aux->prox;
        }

        if(posicao > i+1) {
            cout << "Não há como colocar nessa posição.";
            return;
        }  
        else {
            aux = inicio;

            for(i=1; i<posicao-1; i++) {
                aux = aux->prox;
            }

            nodo *novo = new nodo();
            novo->valor = valor;
            novo->prox = aux->prox;
            aux->prox = novo;
        }

    }

    void remove() {
        int valor;

        cout << "Digite o valor que deseja retirar:";
        cin >> valor;

        nodo *atual = inicio;
        nodo *anterior = nullptr;

        while(atual != nullptr) {
            if(atual == inicio && atual->valor == valor) {
                cout << "Valor encontrado";
                if(atual->prox != nullptr) inicio = atual->prox;
                delete atual;
                return;
            }
            else if(atual->valor == valor) {
                cout << "Valor encontrado.";
                delete anterior;
                return;
            }

            anterior = atual;
            atual = atual->prox;
        }

        cout << "Seu valor não está na lista para ser deletado.";
        return;

    }

};

int main() {

    QuestMaratona exemplo;
    
    exemplo.criarLista();
    exemplo.listar();
    //cout << exemplo.countLista();
    //exemplo.insert();
    exemplo.remove();
    exemplo.listar();

}