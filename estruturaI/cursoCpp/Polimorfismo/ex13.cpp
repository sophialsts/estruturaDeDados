#include <iostream>

using namespace std;

class Animal{

    public:
        virtual void makeSound() const{
            cout << "Som genérico de um animal";
        }

        void makeSound()(const string& message) const{
            cout << message;
        }

};

class Dog : public Animal{

    public:
        void makeSound() override {
            cout << "Latido de cachorro" << endl;
        }

};

class Cat : public Animal{

    public:
        void makeSound() override{
            cout << "Miado de gato";
        }

};


int main(){

    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();

    animal1->makeSound();
    animal2->makeSound();

    Animal genericAnimal;
    genericAnimal.makeSound("Olá, eu sou um bixo!");

    delete animal1;
    delete animal2;
}