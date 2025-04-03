#include <iostream>
#include <stack>
using namespace std;
 
class Pilha {
    int tam, topo, v[10];
 
    public:
    Pilha (int tamanho, int topo, int v[]);
 
    void empilhar (int n) {
        if(topo < tam-1){
            topo++;
            v[topo] = n;
        }
        else {
            cout << "Pilha cheia" << endl;
        }
    }
 
    int desempilhar ()  {
        
    };

    void imprimir();
 
};