#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

enum Disciplina { MATEMATICA, PORTUGUES, CIENCIAS };

struct Aluno {
    string nome;
    int matricula;
    float notas[3];
};

float calcularMedia(Aluno aluno) {
    float soma = 0;
    for (int i=0;i<3;i++) {
        soma += aluno.notas[i];
    }
    return soma/3;
}

void exibirDados(Aluno aluno) {
    cout << "Nome: " << aluno.nome << endl;
    cout << "Matrícula: " << aluno.matricula << endl;
    cout << "Notas: Matemática:. " << aluno.notas[MATEMATICA] 
         << ", Português: " << aluno.notas[PORTUGUES]
         << ", Ciências: " << aluno.notas[CIENCIAS] << endl;
    cout << "Média: " << calcularMedia(aluno) << endl;
    cout << endl;
}

int main() {

    int n;

    cout << "Quantos alunos deseja cadastrar? ";
    cin >> n;
    cin.ignore();

    map<int, Aluno> alunos;

    for(int i=0; i<n ; i++){
        Aluno aluno;
        cout << "\nAluno " << i + 1 << endl;
        cout << "Nome: ";
        getline(cin, aluno.nome);
        cout << "Matrícula: ";
        cin >> aluno.matricula;
        cout << "Nota em Matemática: ";
        cin >> aluno.notas[MATEMATICA];
        cout << "Nota em Português: ";
        cin >> aluno.notas[PORTUGUES];
        cout << "Nota em Ciências: ";
        cin >> aluno.notas[CIENCIAS];
        cin.ignore();

        alunos[aluno.matricula] = aluno;
    }

    cout << "\nDados dos Alunos:\n";
    for(const auto& par : alunos) {
        cout << "\nAluno " << par.first << ";\n";
        exibirDados(par.second);
    }


    return 0;

}

