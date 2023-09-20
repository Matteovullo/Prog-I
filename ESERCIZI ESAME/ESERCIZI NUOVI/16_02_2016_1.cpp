/*Scrivere un metodo che prenda in input una matrice nxm di int, e
restituisca un bool che indichi se esiste in una colonna una sequenza
palindroma di numeri (es: 45254)*/

#include <iostream>

using namespace std;

bool fun(int **A, int n, int m){
    int c=1;

    for(int j=0; j<m; j++){
        for(int k=0; k<n; k++){
            for(int h=0; h<n-1-k; h++){
                if(A[k+h][j] == A[n-1-k][j]){
                    c++; 
                }
                if(c == n-1-k){
                    return true;
                }
            }
            c=1;
        }
    }
    return false;
}

int main(){

    int **A=new int *[3];

    for(int i=0; i<3; i++){
        A[i]=new int[3];
    }

    A[0][0]=1;
    A[1][0]=0;
    A[2][0]=5;
    A[0][1]=6;
    A[1][1]=7;
    A[2][1]=8;
    A[0][2]=9;
    A[1][2]=10;
    A[2][2]=11;

    cout << fun(A, 3, 3); 

}