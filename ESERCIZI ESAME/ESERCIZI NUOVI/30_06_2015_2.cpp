/*Scrivere un metodo che prenda in input una matrice quadrata A di interi e restituisca true se esiste
una diagonale nella matrice triangolare inferiore A, parallela a quella principale, contenente due
numeri opposti, false altrimenti.*/

#include <iostream>

using namespace std;

bool fun(int **A, int n){

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n-1-i; j++){
            if(n-1-i >= 2){
                int c=-A[j][j-i-1];
                cout << c << endl;
                for(int k=j+1; k<n-i-1; k++){
                    cout << -c << endl;
                    if(A[k][k-i-1] == c){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main(){
    int **A=new int*[3];

    for(int i=0; i<3; i++){
        A[i]=new int[3];
        for(int j=0; j<3; j++){
            A[i][j]=2;
        }
    }

    A[1][0]=-2;
    A[2][1]=-2;

    cout << fun(A, 3);
}