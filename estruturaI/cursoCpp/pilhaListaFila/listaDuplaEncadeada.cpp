#include <iostream>
#include <list> // Para list
using namespace std;

int main() {
    // 1. list: Lista duplamente encadeada
    cout << "Exemplo de list:" << endl;
    list<int> numerosList;
    // Adicionando elementos ao final da lista
    numerosList.push_back(10);
    numerosList.push_back(20);
    numerosList.push_back(30);
    // Adicionando elementos ao in�cio da lista
    numerosList.push_front(5);
    numerosList.push_front(1);
    // Exibindo os elementos da lista
    cout << "Elementos da lista antes da exclus�o: ";
    for (int num : numerosList) {
        cout << num << " ";
    }
    cout << endl;
    // Excluindo o primeiro elemento da lista
    if (!numerosList.empty()) {
        numerosList.pop_front();
    }
    // Excluindo o �ltimo elemento da lista
    if (!numerosList.empty()) {
        numerosList.pop_back();
    }
    // Exibindo os elementos da lista ap�s a exclus�o
    cout << "Elementos da lista ap�s a exclus�o: ";
    for (int num : numerosList) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
