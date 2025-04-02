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

    // Método virtual para cálculo da emissão de poluentes
    virtual double calcularEmissao() const = 0;

    // Método para exibir informações do veículo
    void exibirInfo() const {
        cout << "Modelo: " << modelo << ", Emissão: " << calcularEmissao() << " g/km" << endl;
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

    // Adicionando veículos ao vetor
    veiculos.push_back(new Carro("Sedan", 0.9));
    veiculos.push_back(new Caminhao("Caminhão de Carga", 1.5));
    veiculos.push_back(new Moto("Moto Esportiva", 1.5));

    // Calculando e exibindo a emissão de cada veículo
    double emissaoTotal = 0;
    for (size_t i = 0; i < veiculos.size(); ++i) {
        veiculos[i]->exibirInfo();
        emissaoTotal += veiculos[i]->calcularEmissao();
    }

    // Exibindo a emissão total
    cout << "Emissão total de poluentes: " << emissaoTotal << " g/km" << endl;

    // Liberar memória
    for (size_t i = 0; i < veiculos.size(); ++i) {
        delete veiculos[i];
    }

    return 0;
}
