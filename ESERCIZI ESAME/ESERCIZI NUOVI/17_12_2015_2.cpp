/*Scrivere un metodo che prenda in input un vettore di interi e restituisca un bool che indichi se
esistono due numeri “più vicini” (cioè differenza in valore assoluto minima) la cui somma è un
multiplo di 7.*/

#include <iostream>

using namespace std;

bool fun(int *V, int n){
    int a=0;
    int b=1;
    int minabs=abs(V[a]-V[b]);

    for(int i=0; i<n; i++){
        int g=V[i];
        for(int j=i+1; j<n; j++){
            int h=abs(g-V[j]);
            if(h < minabs){
                minabs=g;
                a=i;
                b=j;
            }
        }
    }
    cout << a << endl;
    cout << b << endl;
    cout << V[a]+V[b] << endl;
    if((V[a]+V[b])%7 == 0){
        return true;
    }else{
        return false;
    }
}

int main(){
    int *A=new int[3];
    A[0]=71;
    A[1]=765;
    A[2]=0;

    cout << fun(A, 3);
}