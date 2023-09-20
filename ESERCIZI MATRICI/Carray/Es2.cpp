/*Scrivere un programma che chiede all’utente
di riempire una matrice, la stampa, cerca, se
esiste, la prima occorrenza dello 0 e dice in
che posizione è stata trovata */

/*Scrivere un programma che chiede all’utente
di riempire una matrice, la stampa, cerca, se
esiste, la prima posizione in cui appare lo 0,
l’ultima posizione in cui appare lo 0 e la
posizione mediana in cui appare lo 0 e dice in
che posizione sono state trovate.*/

#include <iostream>

using namespace std;

int fun(int **A, int n, int m){

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(A[i][j] == 0){
                return i, j;
            }
        }
    }
}

int fun(int **A, int n, int m){
    int inizio_i=INT_MIN;
    int inizio_j=INT_MIN;
    int fine_i;
    int fine_j;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(inizio_i == INT_MIN && inizio_j == INT_MIN && A[i][j] == 0){
                inizio_i=i;
                inizio_j=j;
                c++;
            }else if(inizio_i != INT_MIN && inizio_j != INT_MIN && A[i][j] == 0){
                fine_i=i;
                fine_j=j;
                c++;
            }
        }
    }


}

int main(){

}