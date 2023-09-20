/*Assegnata una matrice di interi, di
Riempimenti N ed M, si determinino
gli eventuali punti di sella
Punti di sella di una matrice sono gli
elementi che sono massimi della riga
e della colonna di appartenenza */

#include <iostream>

using namespace std;

void fun(int **A, int n, int m){

    for(int i=0; i<n; i++){
        int index;
        int max=A[i][0];
        for(int j=0; j<m; j++){
            if(A[i][j] > max){
                max = A[i][j];
                index=j;
            }
        }
        for(int k=0; k<n; k++){
            if(A[i][index] > max){
                max = A[i][index];
                index=j ;
            }  
        }
    }
}

int main(){

}