#include <iostream>
#include <string>
using namespace std;

// Classe Usuário
class Usuario {
public:
    string matricula;
    string endereco;
    string tipoUsuario;

    // Método para exibir informações do usuário
    void exibirInformacoes() {
        cout << "Matricula: " << matricula << endl;
        cout << "Endereco: " << endereco << endl;
        cout << "Tipo de Usuario: " << tipoUsuario << endl;
    }
};

// Função principal
int main() {
    // Criando um objeto da classe Usuario
    Usuario usuario;

    // Inserindo um usuário manualmente
    usuario.matricula = "2023001";
    usuario.endereco = "Rua A, 123";
    usuario.tipoUsuario = "Aluno";

    // Exibindo as informações do usuário
    cout << "Informacoes do Usuario:" << endl;
    usuario.exibirInformacoes();

    return 0;
}
