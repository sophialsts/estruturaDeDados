#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;
 
struct nodo {
    string word;
    struct nodo *prox, *ant;
};
 
class CircularWord {
 
    private:
    nodo *inicio, *fim, *atual;
 
    public:
    CircularWord() {
        inicio = nullptr;
        fim = nullptr;
        atual = nullptr;
        }
 
    void createList(string palavra) {
        nodo *novo = new nodo();
 
        if(novo == nullptr) return;
        novo->word = palavra;
 
        if(inicio == nullptr) {
                novo->prox = novo;
                novo->ant = novo;
                inicio = novo;
                atual = novo;
                fim = novo;
                return;
            }
        else if(inicio->prox == nullptr) { //só tem um elemento
                inicio->prox = novo;
                inicio->ant = novo;
                novo->prox = inicio;
                novo->ant = inicio;
                fim = novo;
                return;
            }
 
        atual = inicio;
        while(atual->prox != inicio) {
            atual = atual->prox;
        }
 
        if(atual->prox == inicio) {
            novo->prox = inicio;
            novo->ant = atual;
            atual->prox = novo;
            fim = novo;
            inicio->ant = fim;
        }

        atual = inicio;
 
    }
 
    void listar () {
        if(inicio == nullptr){
            cout << "Não há itens para listar" << endl;
            return;
        }
 
        cout << "Lista ";
        cout << endl;
 
        nodo *aux = inicio;
        int i = 1;
        
        do {
            cout << i << "° elemento = " << aux->word << endl;
            i++;
            aux = aux->prox;
        }
        while(aux != inicio);
 
    }

    void editarPalavra() {
        string newWord;

        cout << "Digite a palavra que deseja substituir: ";
        cin >> newWord;

        atual->word = newWord;

    }

    void inserirPalavra() {
        nodo *novo = new nodo();
        string newWord;

        cout << "Digite a palavra que deseja inserir: ";
        cin >> newWord;

        novo->word = newWord;

        if(atual == nullptr){
            atual = novo;
            novo->prox = novo;
            novo->ant = novo;
            inicio = novo;
            atual = novo;
            fim = novo;
            return;
        }
        else {
            novo->prox = atual->prox;
            novo->ant = atual;
            atual->prox = novo;
        }

    }

    void voltarPalavra() {
        atual = atual->ant;
    }
 
    void passarPalavra() {
        atual = atual->prox;
    }

    void excluirPalavra() {
        if(atual == nullptr) {
            cout << "Lista vazia, nao há o que remover.";
            return;
        }

        nodo *aux = atual;

        if (atual->prox == atual) {
            inicio = nullptr;
            fim = nullptr;
            atual = nullptr;
            return;
        } 
        else {

        atual->ant->prox = atual->prox;
        atual->prox->ant = atual->ant;

        if (atual == inicio) {
            inicio = atual->prox;
        }

        if (atual == fim) {
            fim = atual->ant;
        }

        atual = atual->prox;
    }

        delete aux;
    }

    void menu() {
        char op = ' ';

        while(op != 'x'){
            if(inicio != nullptr) {
                cout << "Palavra atual: " << atual->word << endl;
                if(inicio->prox != inicio) {  // Verifica se há mais de um elemento
                    nodo *aux = inicio;
                    cout << "Frase: ";
                    do {
                        cout << aux->word << " ";
                        aux = aux->prox;
                    } while(aux != inicio);
                    cout << endl;
                }
            }

            cout << "Digite sua opção: ";
            cout << "e - editar, d - inserir, s - eliminar, < - anterior, > - posterior, l - listar, x - sair" << endl;
            cin >> op;
            switch(op){
                case 'e':
                    editarPalavra();
                    break;
                case 'd':
                    inserirPalavra();
                    break;
                case 's':
                    excluirPalavra();
                    break;
                case '<':
                    voltarPalavra();
                    break;
                case '>':
                    passarPalavra();
                    break;
                case 'l':
                    listar();
                    break;
                case 'x':
                    cout << "Você saiu" << endl;
                    return;
            }
            sleep(3);
            system("clear");
        }
    }
 
};
 
int main() {
 
    CircularWord lista;
    lista.createList("Tena");
    lista.createList("ama");
    lista.createList("sua");
    lista.createList("namorada");

    lista.menu();

    return 0;
 
}