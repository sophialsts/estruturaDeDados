#include <iostream>
using namespace std;

struct nodo {
    int info;
    struct nodo *ant, *prox;
};

class Quest11 {
    private: 
    nodo *inicio, *fim;

    public:
    Quest11() {
        inicio = nullptr;
        fim = nullptr;
    }

    void inserir(int n) {
        nodo *novo, *atual;
        novo = new nodo();

        if(novo == nullptr) return;

        novo->info = n;

        if(inicio == nullptr) {
            novo->ant = nullptr;
            novo->prox = nullptr;
            inicio = novo;
            fim = novo;
            return;
        }

        atual = inicio;

        while((atual->prox != nullptr) && (novo->info > atual->info)) atual = atual->prox;

            if((atual->prox == nullptr) && (novo->info > atual->info)) { //fim
                atual->prox = novo;
                novo->ant = atual;
                novo->prox = nullptr;
                fim = novo;
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

    void inverteNos() {
        if (inicio == nullptr) {
            cout << "Não tem nós, não há como inverter";
            return;
        }
        else if (inicio->prox == nullptr) {
            cout << "Só há um nó, não dá para inverter";
            return;
        }
        else if (inicio->prox->prox == nullptr) {
            cout << "Para inverter os nós, precisa no mínimo 3.";
            return;
        }

        nodo *esq = inicio;
        nodo *dir = fim;
        nodo *novoInicio = nullptr;
        nodo *ultimo = nullptr;
        bool ladoEsq = true; 

        while (esq != dir && esq->ant != dir) {
            nodo* atual;

            if (ladoEsq) {
                atual = esq;
                esq = esq->prox;
            } else {
                atual = dir;
                dir = dir->ant;
            }

            if (novoInicio == nullptr) { //caso seja a primeira iteração
                novoInicio = atual;
                atual->ant = nullptr;
                ultimo = atual;
            } else {  //demais só vai adicionando dps
                ultimo->prox = atual;
                atual->ant = ultimo;
                ultimo = atual;
            }

            ladoEsq = !ladoEsq; //pra ir mudando de lado
        }

        // Último(s) nó(s) centrais
        if (esq == dir) { //quantidade de nós ímpar
            ultimo->prox = esq;
            esq->ant = ultimo;
            ultimo = esq;
        } else if (esq->prox == dir) { //quantidade de nós par
            ultimo->prox = esq;
            esq->ant = ultimo;
            esq->prox = dir;
            dir->ant = esq;
            ultimo = dir;
        }

        ultimo->prox = nullptr;
        inicio = novoInicio;
        fim = ultimo;
}


    void listar() {
        nodo *atual;
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

    Quest11 exemplo;
    exemplo.inserir(5);
    exemplo.inserir(7);
    exemplo.inserir(10);
    exemplo.inserir(13);
    exemplo.inserir(15);
    exemplo.inserir(17);
    //exemplo.inserir(19);
    //exemplo.inserir(22);
    //exemplo.inserir(15);
    exemplo.inverteNos();
    //exemplo.inserir(2);
    exemplo.listar();
    
    
}