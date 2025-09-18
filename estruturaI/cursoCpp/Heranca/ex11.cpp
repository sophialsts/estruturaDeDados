#include <iostream>

using namespace std;

class Pessoa{

    protected:
        string nome;
        string endereço;
        string telefone;

    public:

        void exibirDados(){

        }

};

class pessoaFisica : public Pessoa {

    private:
        string CPF;
        string dataNascimento;

    public:

        void validarCPF(){

        }

};

class pessoaJuridica : public Pessoa {
    
    private:
        string CNPJ;
        string razaoSocial;

    public:

        void validaCNPJclass(){

        }

};