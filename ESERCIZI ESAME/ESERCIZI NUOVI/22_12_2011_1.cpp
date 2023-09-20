/*
Esercizio 1:
Scrivere un metodo che prenda in input due array A e B di int di lunghezza n ed m rispettivamente,
e restituisca una matrice di dimensione nxm di int contenente il prodotto AxB se in A tutti gli
elementi sono distinti e la matrice identità altrimenti.*/

#include <iostream>

using namespace std;

int **fun(int *A, int *B, int n, int m){

    int **C=new int*[n];
    for(int i=0; i<n; i++){
        C[i]=new int[m];
    }
    bool found=true;
    
    for(int i=0; i<n; i++){
        int y=A[i];
        for(int j=i+1; j<n; j++){
            if(A[i] == A[j]){
                    found = false;
                    break;
            }
        }
        if(!found){
            break;
        }
    }
    cout << found << endl;

    if(!found){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                C[i][j]=1;
            }
        }
    }else{
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                C[i][j]=A[i]*B[j];
            }
        }
    }

    for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << C[i][j] << " ";
            }
            cout << endl;
        }

    return C;




}

int main(){
    int *A=new int[2];
    int *B=new int[3];

    for(int i=0; i<2; i++)
        A[i]=2;

    for(int j=0; j<3; j++)
        B[j]=5;

    A[0]=2;
    A[1]=5;
    B[0]=4;
    B[1]=4;
    B[2]=4;
    fun(A, B, 2, 3);

}