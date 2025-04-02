#include <iostream>

using namespace std;


int main(){

    int n;
    int idades[n];

    cout << "Digite a quantidade de alunos da turma: " << endl;
    cin >> n;

    cout << "Digite suas idades! " << endl;

    for(int i=0;i<n;i++){
        cin >> idades[i];
    }

    cout << "Idades na ordem inversa -> ";

    for(int j=n-1;j>=0;j--){
        cout << idades[j] << " ";
    }

    return 0;

}