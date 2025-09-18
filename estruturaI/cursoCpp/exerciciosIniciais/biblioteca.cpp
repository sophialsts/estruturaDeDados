#include <iostream>
#include <vector>

using namespace std;

class Livro{

    private:
        string titulo;
        string autor;
        int ID;
        int ano;

    public:

    //getters
    string getTitle() const {return titulo;}
    string getWriter() const {return autor;}
    int getID() const {return ID;}
    int getYear() const {return ano;}

    Livro(string T, string A, int id, int year){
        this->titulo = T;
        this->autor = A;
        this->ID = id;
        this->ano = year;
    }

};

vector<Livro> biblioteca;

void inserirLivro(){

    string nomeLivro;
    string nomeAutor;
    string ignora;
    int id;
    int anoPubli;

    getline(cin,ignora);
    cout << "Digite o nome do livro que deseja inserir:";
    getline(cin,nomeLivro);
    cout << "Digite o nome do autor:";
    getline(cin, nomeAutor);
    cout << "Digite o ID:";
    cin >> id;
    cout << "Digite o ano de Publicação:";
    cin >> anoPubli;

    Livro novoLivro(nomeLivro, nomeAutor, id, anoPubli);

    biblioteca.push_back(novoLivro);
    cout << "Seu livro foi inserido!" << endl;

}

void listarLivros(){

    cout << "Essa é a coleção de livros disponíveis na biblioteca: " << endl;

    if(biblioteca.empty()) cout << "Não existem livros cadastrados." << endl;
    else{
        for(const auto& livro : biblioteca){
            cout << "---------------------------------" << endl;
            cout << "Livro:" << livro.getTitle() << endl;
            cout << "Escritor: " << livro.getWriter() << endl;
            cout << "Data de Publicação: " << livro.getYear() << endl;
            cout << "Número de ID: " << livro.getID() << endl;
            cout << "---------------------------------" << endl;
        }
    }
}

void excluirLivro(){

    string name;
    string ignora;
    int cont = 0;

    getline(cin,ignora);
    cout << "Digite o nome do livro que deseja excluir: ";
    getline(cin,name);

    if(biblioteca.empty()) {
        cout << "Não existem livros cadastrados." << endl;
        
        return;
    }
    else {
        for(const auto& livro : biblioteca){
            if(livro.getTitle() != name ) {
                cont++;
                continue;
            }
            else {
                biblioteca.erase(biblioteca.begin() + cont);
                cout << "O livro foi excluído da biblioteca." << endl;
                return;
            }
        }
    }

    cout << "Esse livro não está registrado" << endl;
    return;

}

void pesquisarLivro(){

    string name;
    string ignora;

    getline(cin,ignora);
    cout << "Digite o nome do livro que deseja pesquisar: " << endl;
    getline(cin,name);

    if(biblioteca.empty()) {
        cout << "Não existem livros cadastrados." << endl;
        return;
    }
    else {
        for(const auto& livro : biblioteca){
            if(livro.getTitle() != name) continue;
            else {
                cout << "Livro encontrado!" << endl;
                cout << "---------------------------------" << endl;
 *               cout << "Livro:" << livro.getTitle() << endl;
                cout << "Escritor: " << livro.getWriter() << endl;
                cout << "Data de Publicação: " << livro.getYear() << endl;
                cout << "Número de ID: " << livro.getID() << endl;
                cout << "---------------------------------" << endl;
                return;
            }
        }
    }

    cout << "Esse livro não está registrado" << endl;
    return;

}

void menu(){

    int op;

    do{

        cout << "Sistema de gestão da biblioteca Sophis" << endl;
        cout << "1 - Inserir Livro" << endl;
        cout << "2 - Listar Livros" << endl;
        cout << "3 - Excluir Livro pelo ID" << endl;
        cout << "4 - Pesquisar Livro" << endl;
        cout << "5 - Sair" << endl;
        cout << endl;
        cout << "Digite sua opção: ";
        cin >> op;

        switch(op){
            case 1:
                inserirLivro();
                break;
            case 2:
                listarLivros(); 
                break;
            case 3:
                excluirLivro();
                break;
            case 4:
                pesquisarLivro();
                break;
            case 5:
                break;
        }

    } while (op != 5);

    cout << "Obrigado por usar a biblioteca de Sophis!";

}

int main(){

    menu();

}

