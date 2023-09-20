/*Assegnata una matrice di interi di riempimenti N ed M, inserire una
riga in posizione K tutta di un assegnato elemento elem*/

#include <iostream>

using namespace std;

int **fun(int **A, int n, int m, int righa, int elemento){
    int **B=new int*[n+1];
    for(int i=0; i<n+1; i++){
        B[i]=new int[m];
    }

    int **C=new int*[n+1];
    for(int i=0; i<n+1; i++){
        C[i]=new int [m];
        for(int j=0; j<m; j++){
            if(i != righa && i<righa){
                C[i][j]=A[i][j];
            }
            if(i > righa){
                C[i][j]=A[i-1][j];
            }
            if(i == righa){
                C[i][j]=elemento;
            }
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    /*for(int i=0; i<n+1; i++){
        for(int j=0; j<m; j++){
            if(i==righa){
                B[i][j]=elemento;
                cout << B[i][j] << " ";
            }
            else{
                B[i][j]=A[i][j];
                cout << B[i][j] << " ";
            }
        }
        cout << endl;
    }*/

    return C;

}

int main(){
    int **U=new int*[3];
    for(int i=0; i<3; i++){
        U[i]=new int[3];{
            for(int j=0; j<3; j++){
                U[i][j]=1;
                cout << U[i][j] << " ";
            }
            cout << endl;
        }
    }
    cout << endl;

    fun(U, 3, 3, 2, 5);

}