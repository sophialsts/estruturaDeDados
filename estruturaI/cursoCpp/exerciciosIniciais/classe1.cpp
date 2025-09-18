#include <iostream>
using namespace std;

class Livro {
private:
    string título;
    string autor;

public:
    int ID;

    Livro(int id, string T, string A){
        this->ID=id;
        this->título=T;
        this->autor=A;
    }

    void mostrarInfo() const {
        cout << "ID: " << ID << ", Livro: " << título << ", Autor: " << autor << endl;
    }
    
    void pesquisarPorTítulo(const string pesquisa) const {
        //return título == pesquisa;
        if(título == pesquisa) cout << "Está presente" << endl;
    }
};

int main(){
    Livro livro(1,"C Completo e Total", "Herbert Schildt ");
    livro.pesquisarPorTítulo("C Completo e Total");

    return 0;
}