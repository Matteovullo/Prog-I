/*Scrivere un programma che chiede all’utente
di inserire una matrice NxN con elementi tutti
diversi. Se l’utente inserisce un numero già
inserito il programma lo avvisa dell’errore e
chiede nuovamente di inserire l’elemento.*/

#include <iostream>

using namespace std;

int main(){

    int n=10;

    int A[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){

            cout << "Inserire elemento: " ;
            cin >> A[i][j];
            for(int k=0; k<n; k++){
                for(int h=0; h<n; h++){
                    if(k != i && h != j){
                        if(A[i][j] == A[k][h])
                            cout << "Errore, inserire nuovamente l'elemento: ";
                            cin >> A[i][j];
                    }
                }
            }
        }
    }
}