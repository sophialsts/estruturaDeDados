#include <iostream>
#include <iomanip> // Para usar fixed e setprecision

using namespace std;

int main() {
    int N, idade, soma = 0;
    float media;

    cout << "Informe a quantidade de alunos da turma: ";
    cin >> N;

    if (N > 0) {
        int v_idade[N]; // Vetor para armazenar as idades

        // Loop para ler as idades dos alunos
        for (int i = 0; i < N; i++) {
            cout << "Informe a idade do Aluno " << i + 1 << ": ";
            cin >> idade;
            v_idade[i] = idade; // Armazena a idade no vetor
            soma += idade; // Soma as idades
        }

        // Cálculo da média
        media = (float) soma / N;

        // Exibição da média formatada com duas casas decimais
        cout << fixed << setprecision(2);
        cout << "A média das idades é: " << media << endl;

        // Exibição das idades iguais ou maiores que a média
        cout << "Os alunos com idade igual ou maior que a média " << media << " são:" << endl;
        for (int i = 0; i < N; i++) {
            if (v_idade[i] >= media) {
                cout << "A idade " << v_idade[i] << " do Aluno " << i + 1 << " é maior ou igual à média." << endl;
            }
        }
    } else {
        cout << "A quantidade de alunos deve ser maior que zero." << endl;
    }

    return 0;
}
