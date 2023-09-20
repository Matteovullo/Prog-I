/*Scrivere un metodo che prenda in input una matrice quadrata A di interi e restituisca un bool che
indichi se esiste una riga contenente tre numeri consecutivi la cui somma è uguale alla somma di
due numeri, non necessariamente consecutivi, di una stessa colonna di A.*/

#include <iostream>

using namespace std;

bool fun(int **A, int n){
    int somma;
    int c=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            somma+=A[i][j];
            c++;
            if(c == 3){
                for(int y=0; y<n; y++){
                    for(int k=0; k<n; k++){
                        int x=A[k][y];
                        for(int w=k+1; w<n; w++){
                            if(x+A[w][y] == somma){
                                return true;
                            }
                        }
                    }
                }
                c=0;
                somma=0;
            }
        }
    }
    return false;
}

int main(){

    int **A=new int*[3];
    for(int i=0; i<3; i++){
        A[i]=new int [3];
        for(int j=0; j<3; j++){
            A[i][j]=1;
        }
    }

    A[1][0]=2;

    cout << fun(A, 3);
}