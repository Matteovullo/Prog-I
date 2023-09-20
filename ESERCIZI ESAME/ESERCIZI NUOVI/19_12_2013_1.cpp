/*Esercizio 1:
Scrivere un metodo che prenda in input una matrice const A[7][10] di float, e restituisca l'indice di
una riga il cui elemento massimo è strettamente minore dei valori medi della riga soprastante e di
quella sottostante o restituisca il valore -1 se tale riga non esiste.
N.B.: Non è possibile usare array ausiliari.*/

#include <iostream>
#include <ctime>

using namespace std;

int fun(float **A){

    float somma1, somma2;

    for(int i=0; i<7; i++){
        float max=A[i][0];
        for(int j=0; j<10; j++){
            if(A[i][j] > max){
                max=A[i][j];
            }
        }
        if(i != 0){
            somma1=0;
            somma2=0;
            for(int k=0; k<10; k++){
                somma1+=A[i+1][k];
            }
            for(int k=0; k<10; k++){
                somma2+=A[i-1][k];
            }
            cout << somma1 << endl;
            cout << somma2 << endl;
        }
        if(max < somma1/10 && max < somma2/10){
            return i;
        }
        cout << somma1/10 << endl;
    }
    cout << "Non ho trovato nessuna riga" << endl;
    return -1;

}

int main(){
    srand(time(0));
    float **B=new float *[7];
    for(int i=0; i<7; i++){
        B[i]=new float [10];
        for(int j=0; j<10; j++){
            B[i][j]=rand()%2;
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << fun(B);




}