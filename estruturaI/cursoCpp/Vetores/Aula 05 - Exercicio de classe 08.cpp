#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v; // Declara um vector de inteiros
    int x;

    cout << "Informe os elementos do Vector ou -1 para encerrar:" << endl;

    // Loop para adicionar elementos ao vector
    while (cin >> x && x >= 0) {
        v.push_back(x); // Função push_back adiciona elemento no final e aloca espaço
    }

    // Exibe os elementos do vector
    cout << "Os elementos do Vector sao:" << endl;
    for (int i = 0; i < v.size(); i++) { // size retorna a quantidade de elementos
        cout << v[i] << endl;
    }

    v.clear(); // Função clear remove todos os elementos de um vector

    cout << "Informe novos elementos do Vector ou -1 para encerrar:" << endl;

    // Loop para adicionar novos elementos ao vector
    while (cin >> x && x >= 0) {
        v.push_back(x);
    }

    // Exibe os elementos do vector novamente
    cout << "Os elementos do vector agora sao:" << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }

    return 0;
}
