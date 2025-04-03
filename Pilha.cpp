#include <iostream>
using namespace std;
 
class Pilha {
    private:
    int tam, topo, v[10];
 
    public:
    Pilha (int tamanho, int topo) {
        this->tam = tamanho;
        this->topo = topo;
    }
 
    void empilhar (int n) {
        if(topo <= tam-1){
            this->topo++;
            this->v[topo] = n;
            this->tam++;
           // cout << v[topo-1] << endl;
        }
        else {
            cout << "Pilha cheia" << endl;
        }
    }
 
    void desempilhar ()  {
        if(this->topo == -1){
            cout << "Pilha vazia" << endl;
        }
        else {
            this->topo--;
            this->tam--;
            /*não tem problema só decrementar porque o que estava presente no vetor vai ser sobrescrito pelos novos elementos empilhados*/
        }
    };

    void imprimir() {
        for (int i=0;i<this->tam;i++) {
            cout << this->v[i] << endl;
        }
    }

};

int main () {
    Pilha novaPilha = Pilha(0, -1);
    novaPilha.empilhar(1);
    novaPilha.empilhar(2);
    novaPilha.empilhar(3);
    novaPilha.imprimir();

}