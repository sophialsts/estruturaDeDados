#include <iostream>
using namespace std;
#define MAX 10
 
public class FilaArray {
 
    private:
        int final = -1;
        int vetor[MAX];
 
    public:
    FilaArray(int v) {
        this.first = v;
        this.vetor[0] = v;
        this.final = v;
    }
 
    int getVetor (int p) {
        return this.vetor[int p];
    }
 
    void setVetor (int pos, int valor) {
        this.vetor[pos] = valor;
    }
 
    void addNaFila (int numero) {
        if(this.final == MAX - 1) cout << "Fila cheia";
        else this.vetor[this.final++] = numero;
    }
 
    void removeDaFila() {
        int i,n;
        if(final == -1) {
            cout << "Fila vazia.";
            return;
        }
        else {
            for(int i=0;i<final;i++){
                this.vetor[i] = this.vetor[i+1];
                this.final--;
                
            }
        }
    }
 
    void listarFila () {
        int i;
        if(final == -1) {
            cout << "Fila vazia.";
            return;
        }
        else {
            for(int i=0;i<=final;i++){
                cout << this.vetor[i] << endl;
            }
        }
    }
 
}
 
int main () {
 
    FilaArray novaFila = new FilaArray(5);
 
}