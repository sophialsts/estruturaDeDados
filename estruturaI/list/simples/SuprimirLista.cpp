#include <iostream>
using namespace std;

/*Objetivo desse código era passar uma lista simples e retornar os números apontando pra quantas vezes eles aparecem
Ex: 1 1 2 3 3 4
Retorno: 1 -> 2 -> 2 -> 1 -> 3 -> 2 -> 4*/

struct nodo {
    struct nodo *prox;
    int valor;
};

class SuprimirLista {

    private:
    nodo *inicio, *suprimidos, *usados;

    public:
    SuprimirLista() { 
        inicio = nullptr; 
        suprimidos = nullptr;
        usados = nullptr;
        }

    void suprimeLista() {
        nodo *aux, *atual, *auxUsados, *fimUsados, *fimSuprimidos;

        if(inicio == nullptr){
            cout << "Não tem lista";
            return; //não tem elemento 
        }    
        else if(inicio->prox == nullptr) { //só tem um elemento
            nodo *novo1 = new nodo();
            nodo *novo2 = new nodo();
            novo1->valor = inicio->valor;
            novo2->valor = 1;
            suprimidos = novo1;
            suprimidos->prox = novo2;
            usados = novo1;
            return;
        }

        atual = inicio->prox; 
        aux = inicio;
        usados = nullptr;
        fimUsados = nullptr;
        while(atual != nullptr) {
            
            while(aux != nullptr) { //criar a lista de usados
                    bool encontrado = false;
                    auxUsados = usados;

                    while(auxUsados != nullptr) {
                        if(aux->valor == auxUsados->valor) {
                            encontrado = true;
                            break;
                        }
                        auxUsados = auxUsados->prox;
                    }

                    if(!encontrado) {
                        nodo *novo = new nodo();
                        novo->valor = aux->valor;
                        novo->prox = nullptr;
        
                        if(usados == nullptr) {
                            usados = novo;
                            fimUsados = novo;
                        }
                        else {
                            fimUsados->prox = novo; 
                            fimUsados = novo; //se não fizer isso, o endereço do fim não atualiza apesar de já apontar pro novo fim
                        }
                    }

                    aux = aux->prox;
                } 

                //garantir que os 2 ponteiros voltem pro estado inicial
                auxUsados = usados;
                aux = inicio;


                /*nodo *mostraUsados = usados;
                while(mostraUsados != nullptr) {
                    cout << mostraUsados->valor;
                    mostraUsados = mostraUsados->prox;
                }*/

                bool eRepetido = false;

                if(atual->valor == auxUsados->valor) {
                        eRepetido = true;
                    }
                else {
                    while(auxUsados->prox != nullptr) {
                        if(atual->valor == auxUsados->valor) {
                            eRepetido = true;
                            break;
                        }
                        auxUsados = auxUsados->prox;
                    }
                } //ver se o elemento que eu vou verificar já existe em usados

                nodo *prox1 = new nodo();
                nodo *prox2 = new nodo();
                prox1->valor = atual->valor;

                //colocando quantidade de vezes que o número atual aparece na lista em prox2
                if(!eRepetido) {
                    prox2->valor = 1;
                }
                else {
                    int cont = 0;
                    aux = inicio; 
                    while(aux != nullptr) {
                        if(atual->valor == aux->valor) cont++;
                        aux = aux->prox;
                    }
                    prox2->valor = cont;
                }

                // 
                if(suprimidos == nullptr) { //não precisou usar prox aqui porque antes prox1 já foi colocado para apontar para prox2
                    suprimidos = prox1;
                    fimSuprimidos = prox2;
                    suprimidos->prox = fimSuprimidos;
                    // antes estava assim suprimidos->prox = fimSuprimidos;
                    // só que fimSurprimidos estava com lixo, pois não foi atribuído ainda. ou você atribui prox2 a ele antes de apontar ou aponta direto pra prox2
                    fimSuprimidos->prox = nullptr;
                }
                else {
                    fimSuprimidos->prox = prox1; 
                    fimSuprimidos = prox1; 
                    fimSuprimidos->prox = prox2;
                    fimSuprimidos = prox2;
                    fimSuprimidos->prox = nullptr;
                }

                atual = atual->prox;
            }

    }

    void criarLista(int num) {
        nodo *novo = new nodo();

        novo->valor = num;
        if(inicio == nullptr) {
            inicio = novo;
            return;
        }
        else if(inicio->prox == nullptr) {
            inicio->prox = novo;
            return;
        }

        nodo *aux = inicio;
        while(aux->prox != nullptr) {
            aux = aux->prox;
        }

        aux->prox = novo;
    }

    void listar() {
        nodo *aux = inicio;

        while(aux != nullptr) {
            cout << aux->valor << endl;
            aux = aux->prox; 
        }

        return;
    }

    void listarSuprimidos() {
        int i = 0;
        nodo *aux = suprimidos;

        while(aux != nullptr) {
            cout << aux->valor;
            if(aux->prox != nullptr) cout << " -> ";
            else cout << endl;
            aux = aux->prox; 
        }

        return;
    }

}; 

int main() {

    SuprimirLista teste;
    teste.criarLista(4);
    teste.criarLista(4);
    teste.criarLista(5);
    teste.criarLista(6);
    //teste.listar();
    teste.suprimeLista();
    teste.listarSuprimidos();
}