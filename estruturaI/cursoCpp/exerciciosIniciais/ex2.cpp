#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Classe base para Usuário
class Usuario {
protected:
    string matricula;
    string endereco;
    string tipoUsuario;

public:
    Usuario(string matricula, string endereco, string tipoUsuario)
        : matricula(matricula), endereco(endereco), tipoUsuario(tipoUsuario) {}

    void exibirInformacoes() {
        cout << "Matricula: " << matricula << ", Endereco: " << endereco
             << ", Tipo: " << tipoUsuario << endl;
    }

    string getMatricula() {
        return matricula;
    }
};

// Classe para Autor
class Autor {
private:
    string nome;
    string nacionalidade;

public:
    Autor(string nome, string nacionalidade)
        : nome(nome), nacionalidade(nacionalidade) {}

    void exibirInformacoes() {
        cout << "Autor: " << nome << ", Nacionalidade: " << nacionalidade << endl;
    }

    string getNome() {
        return nome;
    }
};

// Classe para Editora
class Editora {
private:
    string nome;
    int anoEdicao;

public:
    Editora(string nome, int anoEdicao)
        : nome(nome), anoEdicao(anoEdicao) {}

    void exibirInformacoes() {
        cout << "Editora: " << nome << ", Ano de Edicao: " << anoEdicao << endl;
    }

    string getNome() {
        return nome;
    }
};

// Classe para Obra
class Obra {
private:
    string titulo;
    string tipoObra;
    string idioma;
    string midia;
    vector<Autor*> autores;
    Editora* editora;

public:
    Obra(string titulo, string tipoObra, string idioma, string midia)
        : titulo(titulo), tipoObra(tipoObra), idioma(idioma), midia(midia), editora(nullptr) {}

    void adicionarAutor(Autor* autor) {
        autores.push_back(autor);
    }

    void definirEditora(Editora* editora) {
        this->editora = editora;
    }

    void exibirInformacoes() {
        cout << "Obra: " << titulo << ", Tipo: " << tipoObra << ", Idioma: " << idioma
             << ", Midia: " << midia << endl;
        cout << "Autores: " << endl;
        for (Autor* autor : autores) {
            autor->exibirInformacoes();
        }
        if (editora) {
            editora->exibirInformacoes();
        }
    }

    string getTitulo() {
        return titulo;
    }
};

// Classe para Biblioteca
class Biblioteca {
private:
    vector<Usuario*> usuarios;
    vector<Obra*> obras;

public:
    void cadastrarUsuario(Usuario* usuario) {
        usuarios.push_back(usuario);
    }

    void cadastrarObra(Obra* obra) {
        obras.push_back(obra);
    }

    void emprestarObra(string matricula, string titulo) {
        for (Usuario* usuario : usuarios) {
            if (usuario->getMatricula() == matricula) {
                for (Obra* obra : obras) {
                    if (obra->getTitulo() == titulo) {
                        cout << "Obra '" << titulo << "' emprestada para o usuario '" << matricula << "'." << endl;
                        return;
                    }
                }
                cout << "Obra '" << titulo << "' nao encontrada." << endl;
                return;
            }
        }
        cout << "Usuario '" << matricula << "' nao encontrado." << endl;
    }

    void devolverObra(string matricula, string titulo) {
        for (Usuario* usuario : usuarios) {
            if (usuario->getMatricula() == matricula) {
                for (Obra* obra : obras) {
                    if (obra->getTitulo() == titulo) {
                        cout << "Obra '" << titulo << "' devolvida pelo usuario '" << matricula << "'." << endl;
                        return;
                    }
                }
                cout << "Obra '" << titulo << "' nao encontrada." << endl;
                return;
            }
        }
        cout << "Usuario '" << matricula << "' nao encontrado." << endl;
    }
};

// Função principal
int main() {
    Biblioteca biblioteca;
    
    // Cadastro de Usuários
    Usuario* usuario1 = new Usuario("2023001", "Rua A, 123", "Aluno");
    Usuario* usuario2 = new Usuario("2023002", "Rua B, 456", "Professor");
    biblioteca.cadastrarUsuario(usuario1);
    biblioteca.cadastrarUsuario(usuario2);

    // Cadastro de Autores
    Autor* autor1 = new Autor("Machado de Assis", "Brasileiro");
    Autor* autor2 = new Autor("Stephen Hawking", "Britânico");

    // Cadastro de Editoras
    Editora* editora1 = new Editora("Editora Brasil", 2000);
    Editora* editora2 = new Editora("Editora Inglaterra", 1998);

    // Cadastro de Obras
    Obra* obra1 = new Obra("Dom Casmurro", "Livro científico", "Português", "Papel");
    obra1->adicionarAutor(autor1);
    obra1->definirEditora(editora1);

    Obra* obra2 = new Obra("Uma Breve História do Tempo", "Livro científico", "Inglês", "Digital");
    obra2->adicionarAutor(autor2);
    obra2->definirEditora(editora2);

    biblioteca.cadastrarObra(obra1);
    biblioteca.cadastrarObra(obra2);

    // Emprestar e devolver obras
    biblioteca.emprestarObra("2023001", "Dom Casmurro");
    biblioteca.emprestarObra("2023002", "Uma Breve História do Tempo");
    biblioteca.devolverObra("2023001", "Dom Casmurro");

    // Exibir informações
    cout << "\nInformacoes dos Usuarios:" << endl;
    usuario1->exibirInformacoes();
    usuario2->exibirInformacoes();

    cout << "\nInformacoes das Obras:" << endl;
    obra1->exibirInformacoes();
    obra2->exibirInformacoes();

    // Liberar memória
    delete usuario1;
    delete usuario2;
    delete autor1;
    delete autor2;
    delete editora1;
    delete editora2;
    delete obra1;
    delete obra2;

    return 0;
}
