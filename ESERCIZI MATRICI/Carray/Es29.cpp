/*Assegnata una matrice A (N * M) di elementi interi positivi e minori di 10 , per ogni
riga della matrice costruire il valore decimale ottenuto, procedendo sulla riga da
sinistra verso destra, considerando la differenza in valore assoluto fra ogni coppia
di elementi della riga
Si modifichi la matrice disponendo le righe secondo l’ordinamento crescente dei
valori calcolati*/

#include <iostream>

using namespace std;

int **fun(int **A, int n, int m){

    int **B=new int *[n];
    for(int i=0; i<n; i++)
        B[i]=new int [m];

    int *array1=new int [n-1];
    int *array2=new int [n];

    for(int i=0; i<n; i++){
        for(int j=1; j<n; j++){
            array1[j]=A[i][j]-A[i][j-1];
        }
        int c=n-1
        for(int h=0; h<n-1; h++){
            somma+=array1[i]*()
        }
    }
}
