#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

enum Disciplina { MATEMATICA, PORTUGUES, CIENCIAS };

class Aluno {

    private:
    string nome;
    int matricula;
    float notas[3];

    public:

    Aluno () {

    };

    string getName() const { return nome; }
    int getMatricula() const { return matricula; }
    float getNotas(int i) const { return notas[i]; } 

    void setName(string name) { this->nome = name; }
    void setMatricula(int mat) { this->matricula = mat; }
    void setNotas(int nota,int i) { this->notas[i] = nota; } 

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

};

int main() {

    int n;

    cout << "Quantos alunos deseja cadastrar? ";
    cin >> n;
    cin.ignore();

    map<int, Aluno> alunos;

    for(int i=0; i<n ; i++){
        Aluno aluno;
        string student;
        int matricula;
        int nota1;
        int nota2;
        int nota3;

        cout << "\nAluno " << i + 1 << endl;
        cout << "Nome: ";
        getline(cin, student);
        aluno.setName(student);
        cout << "Matrícula: ";
        cin >> matricula;
        aluno.setMatricula(matricula);
        cout << "Nota em Matemática: ";
        cin >> nota1;
        aluno.setNotas(nota1, MATEMATICA);
        cout << "Nota em Português: ";
        cin >> nota2;
        aluno.setNotas(nota2, PORTUGUES);
        cout << "Nota em Ciências: ";
        cin >> nota3;
        aluno.setNotas(nota3, CIENCIAS);
        cin.ignore();

        alunos[matricula] = aluno;
    }

    cout << "\nDados dos Alunos:\n";
    for(const auto& par : alunos) {
        Aluno estudante;
        cout << "\nAluno " << par.first << ";\n";
        estudante.exibirDados(par.second);
    }

    return 0;

}

