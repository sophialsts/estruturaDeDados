#include <iostream>
using namespace std;

struct nodo {
    int info;
    struct nodo *esq, *dir;
};

class Basic {
    public:
    nodo *raiz;

    Basic() { raiz = nullptr; }

    /*void inserir(nodo *raiz, int n) {
        nodo *atual, *pai;

        if(raiz == nullptr){
            raiz = new nodo();
            if(raiz == nullptr) exit(1);
            raiz->info = n;
            raiz->esq = nullptr;
            raiz->dir = nullptr;
            return;
        }
    
    
    }*/

    nodo* inserir(nodo *raiz, int n) { //método com recursão

        if(raiz == nullptr){
            raiz = new nodo();
            if(raiz == nullptr) exit(1);
            raiz->info = n;
            raiz->esq = nullptr;
            raiz->dir = nullptr;
            return raiz;
        }

        if(n > raiz->info) raiz->dir = inserir(raiz->dir, n);
        else {
            if(n < raiz->info) raiz->esq = inserir(raiz->esq, n);
            else cout << "Número repetido";
        }

        return raiz;

    }

    void emOrdem(nodo *raiz) {
        if(raiz == nullptr) return;
        emOrdem(raiz->esq);
        cout << raiz->info;
        emOrdem(raiz->dir);
    }

    int Buscar(nodo *raiz, int n) {
        if(raiz == nullptr) {
            return -1;
        }
        if(raiz->info == n) {
            return raiz->info;
        }

        if(raiz->info > n) {
            return Buscar(raiz->esq, n);
        }
        else {
            return Buscar(raiz->dir, n);
        }
    }

    int contarF(nodo *raiz) {
        if(raiz == nullptr) return 0;
        if(raiz->esq == nullptr && !raiz->dir)  return 1;

        return(contarF(raiz->esq) + contarF(raiz->dir));
        }

    void compararLados(nodo *raiz) {
        int e, d;
        if(raiz == nullptr) return;

        e = contarF(raiz->esq);
        d = contarF(raiz->dir);

        if(e > d) cout << "esquerda tem mais folhas";
        else if(e < d) cout << "esquerda tem menos folhas";
        else cout << "iguais";
    }

    int maiorFolha(nodo *raiz) {

        if(raiz->dir != nullptr) return maiorFolha(raiz->dir);
        else return raiz->info;
        
    }

    int contar(nodo *raiz) { //passar cont como 0

        if(raiz == nullptr) {
            return 0;
        }
        
        return (1 + contar(raiz->esq) + contar(raiz->dir));

    }


};

int main() {

    Basic arvore;
    int cont = 3;
    nodo *novo = arvore.inserir(arvore.raiz, 5);;

    novo = arvore.inserir(novo, 3);
    arvore.inserir(arvore.raiz, 1);
    arvore.inserir(arvore.raiz, 8);
    cout << arvore.contar(arvore.raiz);
    //arvore.emOrdem(arvore.raiz);  


}