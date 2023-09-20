/*• Scrivere un programma che chiede all’utente
di inserire una matrice NxN e stampa gli
elementi di tale matrice secondo un
ordinamento a spirale, partendo dalla cornice
più esterna e procedendo verso l’interno.*/

#include <iostream>

using namespace std;

void fun(int **A, int n){

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                cout << A[i][k] << " ";
                if(k == n-1){
                    for(int x=0; x<n; x++){
                        cout << A[x][k] << " ";
                    }
                }
                for(int y=n-1-i; y>0; y++){
                    cout << A[i][y] << " ";
                }
                for(int f=n-1-i; f>i+1; f++){
                    cout << A[f][i] << " ";
                }
                for(int u=)
            }
        }
    }
}

int main(){

}