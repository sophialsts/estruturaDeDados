#include <iostream>
using namespace std;

//Sobrecarga de Fun��es:

void print(int i) {  
    cout << "Inteiro: " << i << endl;  
}  

void print(double d) {  
    cout << "Double: " << d << endl;  
}  

//Sobrecarga de Operadores:

class Complex {  
public:  
    Complex operator+(Complex const& obj) {  
        // Implementção da soma  
    }  
};  
