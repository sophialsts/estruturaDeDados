#include <iostream> 
#include <stack>    // biblioteca para usar a pilha
using namespace std; 

int main(){ 
    stack<int> pilha; // declaração da pilha com o tipo de dado
    int n,elemento;
    cout << "Qual o numero de elementos da Pilha? " << endl;
    cin >> n;
    cout << "Quais os elementos da Pilha? " << endl;
    for(int i=0;i<n;i++){ 
        cin >> elemento;
	pilha.push(elemento); // push permite empilhar os dados (FILO)
    } 
   // retorna o elemento do topo (último) sem removê-lo
    cout << "O elemento do topo da Pilha e: "<< pilha.top() << endl; 
}

