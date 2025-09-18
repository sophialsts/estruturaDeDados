#include <iostream>
#include <iomanip> // Para formata��o de sa�da
using namespace std;

// Defini��o da classe ContaBancaria
class ContaBancaria {
private:
    double saldo;

public:
    // Construtor
    ContaBancaria(double saldoInicial = 0.0) : saldo(saldoInicial) {}

    // Sobrecarga do operador -=
    ContaBancaria& operator-=(double valor) {
        if (valor > saldo) {
            cout << "Saldo insuficiente para debitar R$" + to_string(valor);
	        return *this;
        }else{
        	saldo -= valor;
        	return *this;
		}
    }

    // Sobrecarga do operador << para exibir o saldo
    friend ostream& operator<<(ostream& os, const ContaBancaria& conta);
};

// Implementa��o da fun��o friend para o operador <<
ostream& operator<<(ostream& os, const ContaBancaria& conta) {
    os << fixed << setprecision(2); // Formata para 2 casas decimais
    os << endl << "Saldo final: R$" << conta.saldo;
    return os;
}

int main() {
    double saldoInicial;
    int numContas;

    // Solicita ao usu�rio o saldo inicial
    cout << endl << "Informe o saldo inicial da conta: R$";
    cin >> saldoInicial;

    // Cria uma conta banc�ria com o saldo inicial informado
    ContaBancaria conta(saldoInicial);

    // Solicita ao usu�rio o n�mero de contas (despesas)
    cout << endl << "Informe o n�mero de contas (despesas): ";
    cin >> numContas;

    // Processa cada conta
    for (int i = 1; i <= numContas; i++) {
        double valor;
        cout << endl << "Informe o valor da conta " << i << ": R$";
        cin >> valor;

        // Usa o operador -= sobrecarregado para debitar o valor
        conta -= valor;
    }

    // Exibe o saldo final
    cout << conta << endl;

    return 0;
}