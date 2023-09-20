/*Scrivere un metodo che prenda in input una matrice quadrata di interi A, e restituisca true se
esiste una diagonale, parallela alla diagonale principale, la cui somma degli elementi è un
multiplo di 7; false altrimenti.*/

#include <iostream>

using namespace std;

bool fun(int **A, int n){
    int j;
    int somma=0;
    
    for(int k=0; k<n-1; k++){
        somma=0;
        for(int i=0, j=i+k+1; i<n-1-k; i++, j++){
            somma+=A[i][j];
            cout << A[i][j] << endl;
        }
        if(somma%7 == 0)
            return true;
    }
    somma=0;

    for(int k=0; k<n-1; k++){
        somma=0;
        for(int i=0, j=i+k+1; i<n-1-k; i++, j++){
            somma+=A[j][i];
            cout << A[j][i] << endl;
        }
        if(somma%7 == 0)
            return true;
    }

    return false;
}

int main(){
    int **A=new int*[3];
    for(int i=0; i<3; i++){
        A[i]=new int[3];
    }

    A[0][0]=13;
    A[0][1]=1;
    A[0][2]=13;
    A[1][0]=13;
    A[1][1]=13;
    A[1][2]=13;
    A[2][0]=13;
    A[2][1]=13;
    A[2][2]=13;

    cout << fun(A, 3);
}