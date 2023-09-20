/*Scrivere un programma C che legge una sequenza di
numeri interi e li mette nella prima riga della
matrice M. La lettura della sequenza termina
quando alla prima riga della matrice M sono stati
assegnati 50 interi oppure quando viene letto il
secondo numero intero negativo.*/

#include <iostream>

using namespace std;

int main(){

    int M [50][50];
    int i=0;
    int c=0;
    do
    {
        cout << "Inserire un elemento" ;
        cin >> M[0][i];
        if(M[0][i] < 0)
            c++;
        
        i++;
    } while (i<50 && c<2);

        
}