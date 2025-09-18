#include <iostream>
using namespace std;

struct nodo {
    int info;
    struct nodo *prox, *ant;
};

/*
a. retirar todos os elementos ímpares que são primos, e, gerar uma
outra lista contendo apenas os elementos retirados da lista inicial,
em ordem decrescente;
b. retirar todos os elementos pares da lista inicial.
*/

class Quest1 {

    private:
    nodo* inicio, *novaLista;

    public:
    Quest1() { 
        inicio = nullptr;
        novaLista = nullptr;
     }

    ~Quest1() {
        liberarLista(inicio);
        liberarLista(novaLista);
    }

    void liberarLista(nodo* lista) {
        while(lista != nullptr) {
            nodo* temp = lista;
            lista = lista->prox;
            delete temp;
        }
    }

    void criarLista(int n) {
        nodo *novo = new nodo();
    

        if(novo == nullptr) {
            return;
        }

        novo->info = n;
        novo->prox = nullptr;
        novo->ant = nullptr;

        if(inicio == nullptr) {
            inicio = novo; //move novo para inicio
            inicio->prox = nullptr;
        }
        else {
            nodo *anterior = nullptr;
            nodo *atual = inicio; //ponteiro que vai percorrer para verificar onde encaixar o elemento
            while((atual != nullptr) && atual->info < novo->info) {
                anterior = atual;
                atual = atual->prox;
            }

            if (anterior == nullptr) { // inserir no início
                novo->prox = inicio;
                inicio->ant = novo; 
                inicio = novo;
            } else {
                novo->prox = anterior->prox;
                novo->ant = anterior;
                
                if(anterior->prox != nullptr) {
                    anterior->prox->ant = novo; 
                }
                
                anterior->prox = novo;
            }

        }
    }

    void listar () {
        if(inicio == nullptr){
            cout << "Não há itens para listar" << endl;
            return;
        }

        cout << "Lista inicial" << endl;

        nodo *atual = inicio;
        int i = 1;
        
        while(atual != nullptr) {
            cout << i << "° elemento = " << atual->info << endl;
            i++;
            atual = atual->prox;
        }

        cout << endl;

    }

    void retiraImparesPrimos() {
        nodo *aux = inicio;

        while(aux != nullptr) { //percorre toda a lista normal
            bool ePrimo = false;
            bool eImpar = false;
            nodo *proximo = aux->prox; 

            if(aux->info % 2) eImpar = true;

            if(eImpar) {
                int num = 1;
                int divisores = 0;
                
                while(num <= aux->info) {
                    if(aux->info % num == 0) divisores++;
                    num++;
                }

                if(divisores == 2) {
                    ePrimo = true;
                }
            }

            if(ePrimo) {
                nodo *novo = new nodo();
                novo->info = aux->info;
                novo->prox = nullptr;
                novo->ant = nullptr;

                if(novaLista == nullptr) { //primeiro primo 
                    novaLista = novo;
                }
                else if(novo->info > novaLista->info) { //segundo primo
                    novo->prox = novaLista;
                    novaLista->ant = novo;
                    novaLista = novo;
                }
                else {
                    nodo *atual = novaLista;

                    while(atual->prox != nullptr && atual->prox->info > novo->info) {
                        atual = atual->prox; //enquanto não chegar ao final e o elemento atual for maior que novo, porque
                        // os maiores vem primeiro na lista, quando não for isso sai 
                    }

                    if(atual->prox == nullptr) { //chegou no final com o menor elemento
                        atual->prox = novo;
                        novo->ant = atual;
                        novo->prox = nullptr;
                    }
                    else { //vai colocar no meio, atual->prox->info é menor que novo->info
                        novo->prox = atual->prox;
                        novo->ant = atual;
                        atual->prox->ant = novo;
                        atual->prox = novo;
                    }
                }

                // remover o primo da lista principal
                if(aux == inicio) {
                    inicio = aux->prox;
                    if(inicio != nullptr) inicio->ant = nullptr;
                }
                else {
                    aux->ant->prox = aux->prox;
                    if(aux->prox != nullptr) aux->prox->ant = aux->ant;
                }

                delete aux;

            }
            aux = proximo;
        }

    }

    void listarNovaLista() {

        if(novaLista == nullptr){
            cout << "Não há itens para listar" << endl;
            return;
        }

        cout << "Lista de primos ímpares (ordem decrescente)" << endl;

        nodo *atual = novaLista;
        int i = 1;
        
        while(atual != nullptr) {
            cout << i << "° elemento = " << atual->info << endl;
            i++;
            atual = atual->prox;
        }

        cout << endl;

    }

};

int main() {

    Quest1 exemplo;
    exemplo.criarLista(3);
    exemplo.criarLista(5);
    exemplo.criarLista(11);
    exemplo.criarLista(8);
    exemplo.criarLista(7);
    exemplo.criarLista(2);
    exemplo.criarLista(13);
    
    cout << "Lista original:" << endl;
    exemplo.listar();
    
    exemplo.retiraImparesPrimos();
    
    cout << "Lista após remoção dos primos ímpares:" << endl;
    exemplo.listar();
    
    cout << "Lista de primos ímpares removidos:" << endl;
    exemplo.listarNovaLista();

}