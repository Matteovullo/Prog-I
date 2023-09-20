/*Si scriva un programma in linguaggio C che stampi sullo standard output il
contenuto di un quadrato magico di dimensione n, con n dispari. Un quadrato
magico di ordine n contiene i primi n numeri naturali ( 1, 2, 3, …., n2 ) disposti in
modo tale che la somma dei numeri su ogni riga, su ogni colonna e sulle due
diagonali principali sia sempre la stessa.*/

#include <iostream>

using namespace std;

bool fun(int **A, int n){

    int array1[n];

    //righe
    for(int i=0; i<n; i++){
        int somma=0;
        for(int j=0; j<n; j++){
            somma+=A[i][j];
        }
        array1[i]=somma;
        if(i > 0 && array1[i-1] != array1[i]){
            return false;
        }
    }

    int array2[n];

    //colonne
    for(int j=0; j<n; j++){
        int somma=0;
        for(int i=0; i<n; i++){
            somma+=A[i][j];
        }
        array2[j]=somma;
        if(j > 0 && array2[j-1] != array2[j]){
            return false;
        }
    }

    //diagonale principale e secondaria
    int j;
    int somma1=0;
    int somma2=0;
    for(int i=0, j=n; i<n; i++, j--){
        somma1+=A[i][i];
        somma2+=A[i][j];
    }

    int array3[2];
    array3[0]=somma1;
    array3[1]=somma2;

    for(int i=0; i<n; i++){
        if(array1[i] != array2[i])
            return false;
    }

    for(int i=0; i<2-1; i++){
        if(array3[i] != array3[i+1] && array1[i] != array3[i]){
            return false;
        }
    }

    return true;




}

int main(){
    int **A=new int*[3];
    for(int i=0; i<3; i++){
        A[i]=new int[3];
        for(int j=0; j<3; j++){
            A[i][j]=1;
        }
    }
    A[0][0]=2;

    cout << fun(A, 3) << endl;
}