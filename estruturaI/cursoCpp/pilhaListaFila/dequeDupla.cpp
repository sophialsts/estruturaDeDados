#include <iostream>
#include <deque> // Para deque
using namespace std;
int main() {
    // 2. deque: Fila de duas extremidades (double-ended queue)
    cout << "Exemplo de deque:" << endl;
    deque<int> numerosDeque;
    // Adicionando elementos ao final do deque
    numerosDeque.push_back(100);
    numerosDeque.push_back(200);
    numerosDeque.push_back(300);
    // Adicionando elementos ao início do deque
    numerosDeque.push_front(50);
    numerosDeque.push_front(10);
    // Exibindo os elementos do deque
    cout << "Elementos do deque antes da exclusão: ";
    for (int num : numerosDeque) {
        cout << num << " ";
    }
    cout << endl;
    // Excluindo o primeiro elemento do deque
    if (!numerosDeque.empty()) {
        numerosDeque.pop_front();
    }
    // Excluindo o último elemento do deque
    if (!numerosDeque.empty()) {
        numerosDeque.pop_back();
    }
    // Exibindo os elementos do deque após a exclusão
    cout << "Elementos do deque após a exclusão: ";
    for (int num : numerosDeque) {
        cout << num << " ";
    }
    cout << endl;
    // Acessando elementos específicos do deque
    if (!numerosDeque.empty()) {
        cout << "Primeiro elemento do deque: " << numerosDeque.front() << endl;
    }
    if (!numerosDeque.empty()) {
        cout << "Último elemento do deque: " << numerosDeque.back() << endl;
    }
    return 0;
}
