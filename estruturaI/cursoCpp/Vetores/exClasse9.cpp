#include <iostream>
#include <vector>

using namespace std;

int main(){

    int i = 0;
    int menor,maior;
    int quantMenos = 0, quantMais = 0;
    float media = 0;
    vector<int> idades;

    cout << "Digite a idade das pessoas, condição para parada: idade = 0" << endl;

    while(true){

        cin >> idades[i];

        if(idades[i] == 0) break;

        if(i == 0) {
            menor = idades[i];
            maior  = idades[i];
        }
        else if(idades[i] < menor) menor = idades[i];
        else maior = idades[i];

        i++;
    }

    for(int j=0;j<i;j++){
        media += idades[j];
    }

    media /= i;

    cout << "A menor idade foi: " << menor << endl;
    cout << "A maior idade foi: " << maior << endl;

    for(int j=0;j<i;j++){
        if(idades[j] < media) quantMenos++;
        else quantMais++;
    }

    cout << "Existem " << quantMenos << " pessoas com idade menor que a média." << endl;
    cout << "Existem " << quantMais << " pessoas com idade maior ou igual a média." << endl;

    cout << "Idades em ordem crescente -> ";
    for(int j=0;j<i;j++){
        for(int k=j+1;k<i;k++){
            if(idades[j] > idades[k]){
                int aux = idades[j];
                idades[j] = idades[k];
                idades[k] = aux;
            }
        }
    }

    for(int k=0;k<i;k++){
        cout << idades[k] << " ";
    }

    cout << "Idades em ordem decrescente -> ";
    for(int j=0;j<i;j++){
        for(int k=j+1;k<i;k++){
            if(idades[j] < idades[k]){
                int aux = idades[j];
                idades[j] = idades[k];
                idades[k] = aux;
            }
        }
    }

    for(int k=0;k<i;k++){
        cout << idades[k] << " ";
    }

}