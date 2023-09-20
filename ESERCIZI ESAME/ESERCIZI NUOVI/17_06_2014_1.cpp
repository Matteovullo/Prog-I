/*Esercizio 1:
Scrivere un metodo che prenda in input una matrice A di long, e restituisca il valore della
sommatoria per i del max(A, i), dove max(A, i) è una funzione che restituisce il massimo elemento
presente nella i-esima riga di A.*/

#include <iostream>

using namespace std;

long maxA(int i, long **A, int m){
    long max=A[i][0];
    for(int j=0; j<m; j++){
        if(A[i][j] > max)
            max=A[i][j];
    }
    cout << max << endl;
    return max;
}

long fun(long **A, int n, int m){
    long somma=0;
    for(int i=0; i<n; i++){
        somma+=maxA(i, A, m);
    }
    return somma;
}

int main(){
    long **Z=new long*[3];
    int c=0;
    for(int i=0; i<3; i++){
        Z[i]=new long[3];
        for(int j=0; j<3; j++){
            Z[i][j]=c;
            c++;
        }
    }

    cout << fun(Z, 3, 3) << endl;
}
