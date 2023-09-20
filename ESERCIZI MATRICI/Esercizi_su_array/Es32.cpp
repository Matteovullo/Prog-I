/*Si realizzi un programma in linguaggio C che, data una matrice
NxM di interi, trovi l’elemento per cui la media degli elementi
ad esso adiacenti sia massima. Si stampino le coordinate di
tale elemento ed il suo valore.
• Si considerino come adiacenti a ciascun elemento i quattro
elementi nelle quattro direzioni cardinali. Si tratti inoltre
l’ultima colonna come adiacente alla prima, e l’ultima riga
come adiacente alla prima. Si supponga che N ed M possano
variare tra 1 e 100. I valori di N ed M, così come i valori degli
elementi della matrice, vengono acquisiti da tastiera.*/

#include <iostream>

using namespace std;

void fun(int **A, int n, int m){
    int max=INT_MIN;
    int j_max;
    int i_max;
    int media=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i == 0 && j==0){
                media=A[i+1][j]+A[i][j+1]+A[n-1][j]+A[i][n-1];
            }
            if(i == n-1 && j==0){
                media=A[i-1][j]+A[i][j+1]+A[0][0]+A[i][n-1];
            }
            if(i == 0 && j==n-1){
                media=A[i-1][j-1]+A[i-1][j-1]+A[0][0]+A[n-1][n-1];
            }
            if(i == n-1 && j == n-1){
                media=A[i-1][j-1]+A[i+1][j+1]+A[0][j]+A[0][n-1];
            }
            if(i == 0 && j != 0){
                media=A[i+1][j]+A[i-1][j+1]+A[i][j+1]+A[n-1][j];
            }
            if(i != 0 && j == 0){
                media=A[i+1][j]+A[i-1][j]+A[i+1][j+1]+A[i][n-1];
            }
            if(i == n-1 && j != 0){
                media=A[i+1][j]+A[i-1][j-1]+A[i][j+1]+A[0][j];
            }
            if(i != 0  && j == n-1){
                media=A[i+1][j+1]+A[i-1][j]+A[i][j-1]+A[i][0];
            }
            if(i != 0 && j != 0 && i != n-1 && j != n-1){
                media=A[i-1][j-1]+A[i][j+1]+A[i+1][j]+A[i-1][j];
            }
            if(media > max){
                max=media;
                i_max=i;
                j_max=j;
            }
        }
    }
    cout << "Media max: " << media << ", indice di riga: " << i_max << ", indice di colonna: " << j_max << endl;
}

int main(){

}