#include <iostream>
using namespace std;

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
        int cont = 0;
        nodo *aux, *atual, *auxUsados, *fimUsados;

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

        atual = inicio;
        aux = inicio;
        usados = nullptr;
        fimUsados = nullptr;
        //while(atual != nullptr) {
            
        while(aux != nullptr) {
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


            nodo *mostraUsados = usados;
            while(mostraUsados != nullptr) {
                cout << mostraUsados->valor;
                mostraUsados = mostraUsados->prox;
            }

            // avalie até aqui

            /*
            if(atual->valor == auxUsados->valor) {
                    cout << "Número repetido";
                }
            else {
                while(auxUsados->prox != nullptr) {
                    if(atual->valor == auxUsados->valor) {
                        return;
                    }
                    auxUsados = auxUsados->prox;
                }
            } //ver se o elemento que eu vou verificar a presença de repetidos já existe em usados

                aux = atual->prox;
                while(aux != nullptr) {
                    if(atual->valor == aux->valor) cont++;
                    aux = aux->prox;
                }

            nodo *prox1 = new nodo();
            nodo *prox2 = new nodo();
            prox1->valor = atual->valor;
            prox2->valor = cont;
            suprimidos->prox = prox1;
            prox1->prox = prox2;
            */
        //    atual = atual->prox;
        //}

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
        nodo *aux = suprimidos;

        while(aux != nullptr) {
            cout << aux->valor << endl;
            aux = aux->prox; 
        }

        return;
    }

}; 

int main() {

    SuprimirLista teste;
    teste.criarLista(4);
    teste.criarLista(4);/*
    teste.criarLista(4);
    teste.criarLista(5);*/
    //teste.listar();
    teste.suprimeLista();
    //teste.listarSuprimidos();
}