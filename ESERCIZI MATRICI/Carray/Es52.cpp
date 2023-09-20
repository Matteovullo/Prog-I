/*Assegnata una matrice quadrata d’ordine N determinare la somma degli elementi
sulla diagonale principale e le somme degli elementi su ciascuna delle diagonali
parallele alla principale.*/

#include <iostream>

using namespace std;

void fun(int **A, int n){
    int somma=0;
    int sdia=0;
    //int m=((n-1)*2)+1;

    /*int *diag=new int[m];
    for(int i=0; i<n; i++){
        sdia+=A[i][i];
    }
    diag[0]=sdia;
    */

    for(int i=0; i<n-1; i++){
        //for(int j=0; j<n-2; j++){
            somma=0;
            for(int k=0; k<n-1-i; k++){
                somma+=A[k][i+k+1];
            }
            cout << "Somma diagonale superiore " << i+1 << " è: " << somma << endl;
        }
        //diag[i+1]=somma;

    for(int i=0; i<n-1; i++){
            somma=0;
            for(int k=0; k<n-1-i; k++){
                somma+=A[i+k+1][k];
            }
            cout << "Somma diagonale inferiore " << i+1 << " è: " << somma << endl;
        }
        //diag[(m/2)+1]=somma;

    //return diag;

}

int main(){
    int **B=new int *[5];
    for(int i=0; i<5; i++){
        B[i]=new int[5];
        for(int j=0; j<5; j++){
            B[i][j]=1;
        }
    }

    /*nt *C=fun(B,3);

    for(int i=0; i<5; i++){
        cout << C[i] << " ";
    }*/

    fun(B,5);

}