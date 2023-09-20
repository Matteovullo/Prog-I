/*Si scriva un programma che chiede all’utente
di riempire una matrice NxN (con N costante
globale predefinita) di interi e stampa la
lunghezza della sequenza più lunga
orizzontale, verticale o diagonale di numeri
uguali consecutivi.*/

#include <iostream>

using namespace std;

void fun(int **A, int n){

    //orizontale
    int max1=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int c=1;
            for(int k=j+1; k<n; k++){
                if(A[i][k] == A[i][k-1]){
                    c++;
                    if(c > max1){
                    max1=c;
                    }
                }else{
                    c=1;
                }
            }
            
        }
    }

    cout << max1 << endl;

    //verticale
    int max2=0;
    for(int j=0; j<n; j++){
        for(int i=0; i<n; i++){
            int c=1;
            for(int k=i+1; k<n; k++){
                if(A[k][j] == A[k-1][j]){
                    c++;
                    if(c > max2){
                        max2=c;
                    }
                }else{
                    c=1;
                }
            }
        }
    }

    cout << max2 << endl;

    //diagonale superiore
    int max3;
    for(int k=0; k<n-1; k++){
        int c=1;
        for(int i=0; i<n-1-k; i++){
            for(int h=i+1; h<n-1-k; h++){
                if(A[i+k+1][h+1] == A[i+k][h]){
                    c++;
                    if(c > max3){
                        max3=c++;
                    }
                }else{
                    c=1;
                }
            }
        }
    }

    //diagonale inferiori
    for(int k=0; k<n-1; k++){
        int c=1;
        for(int j=0; j<n-1-k; j++){
            for(int h=j+1; h<n-1-k; h++){
                if(A[h+1][j+k+1] == A[h][j+k]){
                    c++;
                    if(c > max3){
                        max3=c++;
                    }
                }else{
                    c=1;
                }
            }
        }
    }

    //diagonale principale e secondaria
    int j;
    for(int i=0, j=n-1; i<n; i++, j--){
        int c=1;
        for(int k=i+1; k<n; k++){
            if(A[k][k] == A[k-1][k-1]){
                c++;
                if(c > max3){
                    max3=c;
                }
            }else{
                c=1;
            }
        }
        for(int k=j+1; k<n; k++){
            if(A[k][k] == A[k-1][k-1]){
                c++;
                if(c > max3){
                    max3=c;
                }
            }else{
                c=1;
            }
        }
    }
    




}

int main(){

}