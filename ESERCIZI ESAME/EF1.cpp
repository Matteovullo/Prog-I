/*Scrivere una funzione che prenda in input una matrice quadrata A di short, 
e restituisca un bool che indichi se la diagonale principale è identica 
(procedendo dall’alto verso il basso) alla secondaria.*/

#include <iostream>
using namespace std;
#define n 3

bool fun(short **a){
    int j,count;
    bool valore;

    for(int i=0, j=n-1; i<n; i++, j--){
        if(a[i][i] == a[i][j]){
            count++;
        }
    }
    if(count == n){
        valore=true;
    }else{
        valore=false;
    }
    return valore;
}

int main(){
    short **s=new short *[n];
    for(int i=0; i<n; i++){
        s[i]=new short [n];
        for(int j=0; j<n; j++){
            s[i][j]=0;
        }
    }

    cout<<fun(s);
}