/*Scrivere una funzione che prenda in input una matrice 
quadrata A di short, e restituisca un bool che indichi 
se la diagonale principale è identica (procedendo dall’alto 
verso il basso) alla secondaria.*/

#include <iostream>
using namespace std;

bool fun(short **A, int n){
    int c=0;
    int j=0;
    for(int i=0, j=n-1; i<n; i++, j--){
        if(A[i][i] == A[i][j]){
            c++;
        }
    }
    if(c==n){
        return true;
    }else{
        return false;
    }
}

int main(){
    short **a = new short*[5];
    for(int i=0; i<5; i++){
        a[i]=new short[5];
        for(int j=0; j<5; j++){
            a[i][j]=5;
        }
    }
    cout << fun(a, 5) << endl;
    a[0][0]=1;
    cout << fun(a, 5) << endl;
}
