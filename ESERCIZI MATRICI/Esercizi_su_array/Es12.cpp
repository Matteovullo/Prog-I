/*Scrivere un programma che chiede all’utente
di inserire una matrice 20x30, poi (dopo aver
terminato la fase di inserimento) copia gli
elementi dispari in una seconda matrice 20x30
senza lasciare buchi, se non in fondo.
• Gli elementi in fondo (i "buchi") siano messi a
zero.*/

#include <iostream>

using namespace std;

int main(){
    int A[20][30];

    for(int i=0; i<20; i++){
        for(int j=0; j<30; j++){
            cout << "Inserire elemento: ";
            cin >> A[i][j];
        }
    }

    int B[20][30];
    for(int i=0; i<20; i++){
        for(int j=0; j<30; j++){
            if(A[i][j]%2 != 0){
                B[i][j]=A[i][j];
            }else{
                B[i][j]=0;
            }
        }
    }

}