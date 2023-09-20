/*Scrivere un metodo che prenda in input una matrice A di float, 
e restituisca il valore di somma(min(A,j)), dove min(A, j) è 
la funzione che restituisce il minimo elemento presente nella 
j-esima colonna di A. N.B.: Non è possibile utilizzare array ausiliari.*/

#include <iostream>
using namespace std;
#define n 3
#define m 3

float fun(float **a){
    float somma;

    for(int j=0; j<m; j++){
        float min=a[0][j];
        for(int i=0; i<n; i++){
            if(a[i][j] < min){
                min=a[i][j];
            }
        }
        somma+=min;
    }

    return somma;
}

int main(){
    float **o=new float *[n];
    for(int i=0; i<n; i++){
        o[i]=new float [m];
        for(int j=0; j<m; j++){
            o[i][j]=2.5;
        }
    }

    cout<<fun(o);
}