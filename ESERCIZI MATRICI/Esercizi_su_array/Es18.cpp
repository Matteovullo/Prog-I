/*Considerata una matrice A di N x M interi, definiamo claque una
sottomatrice 2 x 2 in cui la somma algebrica dei valori di una
diagonale sia pari a quella dell’altra diagonale. In figura sono
evidenziate le claque.
• Si scriva un programma che acquisisce una matrice N x M stampa il
numero di claque della matrice.*/

#include <iostream>

using namespace std;

void fun(int **A, int n, int m){
    int sottrazione1=0, sottrazione2=0,c=0;
    int y=(((n-2)+1)*((m-2)+1));
    
    for(int x=0; x<y; x++){
        for(int i=0; i<((n-2)+1); i++){
            for(int j=0; j<((m-2)+1); j++){
                sottrazione1=0;
                sottrazione2=0;
                for(int h=0, k=2; h<2; h++, k--){
                    sottrazione1=A[h+i+1][h+i+1]-A[h+i][h+i];
                    sottrazione2=A[h+i+1][k+j+1]-A[h+i][k+j];
                }
                cout << sottrazione1 << " " << sottrazione2 << " " << endl;
            }
            if(sottrazione1 == sottrazione2){
                c++;
            }
        }
    }

    cout << c << endl;
}

int main(){

    int **A=new int *[3];
    for(int i=0; i<3; i++){
        A[i]=new int[3];
        for(int j=0; j<3; j++){
            A[i][j]=1;
        }
    }

    fun(A, 3, 3);

}