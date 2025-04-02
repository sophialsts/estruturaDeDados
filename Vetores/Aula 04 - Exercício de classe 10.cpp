#include <iostream>
#include <vector>

using namespace std;

// Classe Aluno
class Aluno {
private:
    vector<float> notas; // Vetor para armazenar as 4 notas

public:
    // M�todo para adicionar uma nota ao aluno
    void adicionarNota(float nota) {
        notas.push_back(nota);
    }

    // M�todo para calcular a m�dia das notas
    float calcularMedia() {
        float soma = 0;
        for (float nota : notas) {
            soma += nota;
        }
        return soma / notas.size();
    }

    // M�todo para verificar se o aluno foi aprovado ou reprovado
    void verificarAprovacao() {
        float media = calcularMedia();
        cout << "M�dia: " << media << " - ";
        if (media > 7) {
            cout << "Aluno aprovado!" << endl;
        } else {
            cout << "Aluno reprovado!" << endl;
        }
    }
};

int main() {
    int N; // N�mero de alunos
    cout << "Digite o n�mero de alunos: ";
    cin >> N;

    // Vetor para armazenar os alunos
    vector<Aluno> turma;

    // Loop para entrada dos dados de cada aluno
    for (int i = 0; i < N; i++) {
        cout << "\n--- Aluno " << i + 1 << " ---" << endl;
        Aluno aluno;

        // Loop para entrada das 4 notas de cada aluno
        for (int j = 0; j < 4; j++) {
            float nota;
            cout << "Digite a nota " << j + 1 << ": ";
            cin >> nota;
            aluno.adicionarNota(nota);
        }

        // Adiciona o aluno ao vetor da turma
        turma.push_back(aluno);
    }

    // Loop para exibir a m�dia e verificar a aprova��o de cada aluno
    cout << "\n--- Resultados ---" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Aluno " << i + 1 << " - ";
        turma[i].verificarAprovacao();
    }

    return 0;
}
