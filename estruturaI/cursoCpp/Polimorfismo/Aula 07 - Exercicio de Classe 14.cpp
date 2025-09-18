#include <iostream>
#include <string>
#include <vector>
#include <locale.h>

using namespace std;

// Classe base
class Veiculo {
protected:
    string modelo;
public:
    Veiculo(const string& modelo) : modelo(modelo) {}

    // M�todo virtual para c�lculo da emiss�o de poluentes
    virtual double calcularEmissao() const = 0;

    // M�todo para exibir informa��es do ve�culo
    void exibirInfo() const {
        cout << "Modelo: " << modelo << ", Emiss�o: " << calcularEmissao() << " g/km" << endl;
    }
};

// Classe derivada Carro
class Carro : public Veiculo {
private:
    double fatorEficiencia;
public:
    Carro(const string& modelo, double fatorEficiencia) 
        : Veiculo(modelo), fatorEficiencia(fatorEficiencia) {}

    double calcularEmissao() const override {
        return 120 * fatorEficiencia;
    }
};

// Classe derivada Caminhao
class Caminhao : public Veiculo {
private:
    double fatorCarga;
public:
    Caminhao(const string& modelo, double fatorCarga) 
        : Veiculo(modelo), fatorCarga(fatorCarga) {}

    double calcularEmissao() const override {
        return 300 * fatorCarga;
    }
};

// Classe derivada Moto
class Moto : public Veiculo {
private:
    double fatorIdade;
public:
    Moto(const string& modelo, double fatorIdade) 
        : Veiculo(modelo), fatorIdade(fatorIdade) {}

    double calcularEmissao() const override {
        return 50 * fatorIdade;
    }
};

int main() {
	setlocale(LC_ALL,"Portuguese_Brazil");
    // Vetor de ponteiros para Veiculo
    vector<Veiculo*> veiculos;

    // Adicionando ve�culos ao vetor
    veiculos.push_back(new Carro("Sedan", 0.9));
    veiculos.push_back(new Caminhao("Caminh�o de Carga", 1.5));
    veiculos.push_back(new Moto("Moto Esportiva", 1.5));

    // Calculando e exibindo a emiss�o de cada ve�culo
    double emissaoTotal = 0;
    for (size_t i = 0; i < veiculos.size(); ++i) {
        veiculos[i]->exibirInfo();
        emissaoTotal += veiculos[i]->calcularEmissao();
    }

    // Exibindo a emiss�o total
    cout << "Emiss�o total de poluentes: " << emissaoTotal << " g/km" << endl;

    // Liberar mem�ria
    for (size_t i = 0; i < veiculos.size(); ++i) {
        delete veiculos[i];
    }

    return 0;
}
