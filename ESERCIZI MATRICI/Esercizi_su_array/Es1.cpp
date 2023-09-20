/*Scrivere un programma che chiede all’utente
di riempire una matrice, la stampa, cerca, se
esiste, la prima occorrenza dello 0 e dice in
che posizione è stata trovata */

#include <iostream> 

using namespace std;

int fun(int **A, int n ,int m){

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(A[i][j] == 0){
                return i,j;
            }
        }
    }
    return -1;
}




