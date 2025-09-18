#include <iostream>
#include <vector>

using namespace std;

class Aluno {

    private:
        vector<float> notas;

    public:

    void adicionarNota(float nota){
        notas.push_back(nota);
    }

    float calcularMedia(){
        float soma = 0;

        for(float nota : notas) soma += nota;

        return soma/notas.size();
    }

    void verificaAprovação(){
        float media = calcularMedia();
        cout << "Média: " << media << "-";
        if(media > 7) cout << "Aluno aprovado!" << endl;
        else cout << "Aluno reprovado" << endl;
    }

}

int main(){

    int n;

    cout << "Digite o número de alunos: ";
    cin >> n;

    vector<Aluno> turma;

}