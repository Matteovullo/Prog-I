/*Scrivere un metodo che prenda in input un array di n numeri interi e restituisca true se sono presenti
due valori che sono l’uno il doppio dell’altro, false altrimenti.*/

#include <iostream>

using namespace std;

bool fun(int *A, int n){

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(A[i] > A[j] && A[i]/A[j] == 2){
                return true;
            }else if(A[j]/A[i] == 2){
                return false;
            }
        }
    }

    return false;

}

int main(){
    int *A=new int[3];
    A[0]=20;
    A[1]=1;
    A[2]=1;

    cout << fun(A, 3); 
}