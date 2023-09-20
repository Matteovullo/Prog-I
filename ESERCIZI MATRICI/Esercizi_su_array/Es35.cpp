/*Si scriva una frammento di codice che usa una
matrice di interi NxN (con N costante predefinita)
e un array di caratteri.
• Ogni elemento dell’array contiene solo i caratteri
‘0’, ‘1’ o ‘\0’ e rappresenta una stringa che è la
codifica binaria di un intero. Il programma deve
stampare VERO se il numero decimale
corrispondente all’intero codificato in binario
nell’array è uguale alla media degli interi
contenuti nella matrice, FALSO altrimenti.*/

#include <iostream>

using namespace std;

bool fun(int **A, int n, int m, char *B, int k){

    double media=0;
    int somma=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            somma+=A[i][j];
        }
    }
    media=somma/(n*m);
    cout << media << endl;
    somma=0;

    for(int i=0; i<k; i++){
        somma+=(int)B[i];
    }
    cout << somma << endl;

    if(media == somma)
        return true;
    else
        return false;
}

int main(){
    int **A=new int *[3];
    for(int i=0; i<3; i++){
        A[i]=new int [3];
        for(int j=0; j<3; j++){
            A[i][j]=147;
        }
    }

    char *B=new char [3];
    B[0]='1';
    B[1]='1';
    B[2]='1';

    cout << (int)'1' << endl;

    cout << fun(A, 3, 3, B, 3);

}