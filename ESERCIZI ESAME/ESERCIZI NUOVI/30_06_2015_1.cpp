/*Scrivere un metodo che prenda in input un vettore A di n numeri interi positivi e due indici i e
j (con 0 ≤ i,j < n e i≠j) e restituisca una permutazione di A in cui l'ordine di tutti gli elementi è
preservato, ad eccezione dell’elemento di indice j che viene inserito all’indice i.
Es: A={0,1,2,3,4,5,6,7,8,9}, i=2, j=7 ----> A’={0,1,7,2,3,4,5,6,8,9}
Es: A={0,1,2,3,4,5,6,7,8,9}, i=6, j=3 ----> A’={0,1,2,4,5,6,3,7,8,9}*/

#include <iostream>

using namespace std;

unsigned int* fun(unsigned int *A, int n, int i, int j){
    unsigned int *B=new unsigned int[n];
    for(int i=0; i<n; i++){
        B[i]=A[i];
    }

    unsigned int temp=B[i];
    B[i]=A[j];
    B[j]=temp;

    return B;
}

int main(){
    unsigned int *A=new unsigned int[4];
    int c=0;
    for(int i=0; i<4; i++){
        A[i]=c;
        cout << A[i] << " ";
        c++;
    }    
    unsigned int *B=fun(A, 4, 1, 2);

    for(int i=0; i<4; i++){
        cout << B[i] << " ";
    }
}