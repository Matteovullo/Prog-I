/*• Scrivere un programma che chiede all’utente
di riempire una matrice, la stampa, cerca, se
esiste, la prima posizione in cui appare lo 0,
l’ultima posizione in cui appare lo 0 e la
posizione mediana in cui appare lo 0 e dice in
che posizione sono state trovate. */

#include <iostream>

using namespace std;

void fun(int **A, int n, int m){
    bool found=false;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(A[i][j]==0){
                found=true;
                cout << "Prima posizione: " << i << "," << j << endl;
                break;
            }
        }
        if(found)
            break;
    }

    bool found2=false;
    for(int i=n-1; i>0; i--){
        for(int j=n-1; j>0; j--){
            if(A[i][j]==0){
                found2=true;
                cout << "Ultima posizione: " << i << "," << j << endl;
                break;
            }
        }
        if(found2)
            break;
    }


    int c=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(A[i][j]==0){
                c++;
            }
        }
    }

    int mediana=0;
    if(c%2 == 0)
        mediana=c/2;
    else
        mediana=(c/2)+1;

    
    bool found3=false;
    int l=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(A[i][j]==0){
                l++;
            }
            if(l == mediana)
                found3=true;
                cout << "Posizione mediana è:" << i << "," << j << endl;
                break;
        }
        if(found)
            break;
    }

}