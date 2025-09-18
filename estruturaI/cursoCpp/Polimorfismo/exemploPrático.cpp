#include <iostream>
using namespace std;

class Animal {  
public:  
    virtual void makeSound() {  
        cout << "Som genérico" << endl;  
    }  
};  

class Dog : public Animal {  
public:  
    void makeSound() override {  
        cout << "Latido" << endl;  
    }  
};  

class Cat : public Animal {  
public:  
    void makeSound() override {  
        cout << "Miado" << endl;  
    }  
};  

int main(){

    Dog meuDog;

    meuDog.makeSound();

}
