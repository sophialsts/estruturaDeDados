#include <iostream>
using namespace std;

class Veículo {
protected:
    string marca;
    string modelo;
    int ano;
    float velocidade;

public:
    Veículo(string Marca, string Modelo, int Ano, float Velocidade) 
        : marca(Marca), modelo(Modelo), ano(Ano), velocidade(Velocidade) {}

    virtual void exibirDados() {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Ano: " << ano << endl;
        cout << "Velocidade: " << velocidade << " km/h" << endl;
    }

    void acelerar() {
        cout << "Acelerando...." << endl;
    }

    void frear() {
        cout << "Freando...." << endl;
    }

    virtual ~Veículo() {}
};

class Carro : public Veículo {
private:
    int numPortas;

public:
    Carro(string Marca, string Modelo, int Ano, float Velocidade, int NumPortas)
        : Veículo(Marca, Modelo, Ano, Velocidade), numPortas(NumPortas) {}

    void ligarArCondicionado() {
        cout << "Ligando ar condicionado...." << endl;
    }

    void exibirDados() override {
        Veículo::exibirDados();
        cout << "Número de portas: " << numPortas << endl;
    }

};

class Moto : public Veículo {
private:
    int cilindradas;

public:
    Moto(string Marca, string Modelo, int Ano, float Velocidade, int Cilindradas)
        : Veículo(Marca, Modelo, Ano, Velocidade), cilindradas(Cilindradas) {}

    void empinar() {
        cout << "Empinando moto...." << endl;
    }

    void exibirDados() override {
        Veículo::exibirDados();
        cout << "Número de cilindradas: " << cilindradas << endl;
    }
};

int main() {

    Carro meucarro("Chevrolet", "Classic", 2010, 80, 4);
    Moto minhamoto("Honda", "Nsei", 2015, 70, 150);

    meucarro.exibirDados();
    meucarro.acelerar();
    meucarro.ligarArCondicionado();
    meucarro.frear();

    cout << endl;

    minhamoto.empinar();
    minhamoto.acelerar();
    minhamoto.exibirDados();
    minhamoto.frear();

    return 0;
}
