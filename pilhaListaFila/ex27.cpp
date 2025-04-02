#include <iostream> 
#include <stack>    // biblioteca para usar a pilha
using namespace std; 

int main(){ 
    stack<int> pilha; // declara��o da pilha com o tipo de dado
    int n,elemento;
    cout << "Qual o numero de elementos da Pilha? " << endl;
    cin >> n;
    cout << "Quais os elementos da Pilha? " << endl;
    for(int i=0;i<n;i++){ 
        cin >> elemento;
	    pilha.push(elemento); // push permite empilhar os dados (FILO)
    } 

    cout << "Os elementos da pilha são: " << endl;
    while(!pilha.empty()) {
            cout << pilha.top() << " " << endl;
            pilha.pop();
    };

    return 0;

}

