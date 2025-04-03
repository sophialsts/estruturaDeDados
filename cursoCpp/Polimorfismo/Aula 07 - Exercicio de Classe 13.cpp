#include <iostream>
#include <string>
#include <locale.h>

using namespace std;

// Classe base
class Animal {
public:
    // M�todo virtual para polimorfismo em tempo de execu��o
    virtual void makeSound() const {
        cout << "Som gen�rico de um animal" << endl;
    }

    // M�todo sobrecarregado para polimorfismo em tempo de compila��o
    void makeSound(const string& message) const {
        cout << "Animal diz: " << message << endl;
    }
};

// Classe derivada Dog
class Dog : public Animal {
public:
    void makeSound() const override {
        cout << "Latido do cachorro" << endl;
    }
};

// Classe derivada Cat
class Cat : public Animal {
public:
    void makeSound() const override {
        cout << "Miado do gato" << endl;
    }
};

int main() {
	setlocale(LC_ALL,"Portuguese_Brazil");
    // Polimorfismo em tempo de execu��o
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();

    animal1->makeSound(); // Deve imprimir "Latido do cachorro"
    animal2->makeSound(); // Deve imprimir "Miado do gato"

    // Polimorfismo em tempo de compila��o
    Animal genericAnimal;
    genericAnimal.makeSound("Ol�, eu sou um animal!"); // Deve imprimir "Animal diz: Ol�, eu sou um animal!"

    // Liberar mem�ria
    delete animal1;
    delete animal2;

    return 0;
}
