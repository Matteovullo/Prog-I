#include <iostream>

using namespace std;

int determinante(int **A, int n){
    int determinante;
    if(n == 2){
        determinante=((A[1][1]*A[2][2])-(A[1][2]*A[2][1]));
    }
    if( n == 3){
        determinante=(((A[1][1]*A[2][2]*A[3][3])+(A[1][2]*A[2][3]*A[3][1])+(A[1][3]*A[2][1]*A[3][2]))-((A[1][3]*A[2][2]*A[3][1])+(A[1][1]*A[2][3]*A[3][2])+(A[1][2]*A[2][1]*A[2][3])));
    }
    if (n >= 4){
        for(int i=0; i<n; i++){
            determinante+=(A[i][0])*(complementi_algebrici(A, n, i, 1));
        }
    }
    return determinante;
}