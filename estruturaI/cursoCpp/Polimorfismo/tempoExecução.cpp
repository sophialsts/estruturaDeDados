#include <iostream>
using namespace std;

//Funções Virtuais:

class Base {  
public:  
    virtual void show() {  
        cout << "Base class" << endl;  
    }  
};  

class Derived : public Base {  
public:  
    void show() override {  
        cout << "Derived class" << endl;  
    }  
};  

//Uso

Base* b = new Derived();  
b->show();  // Output: "Derived class"  
