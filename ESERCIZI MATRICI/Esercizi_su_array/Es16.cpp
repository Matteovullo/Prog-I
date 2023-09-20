/*Una matrice quadrata Mat di dimensioni NxN (con N
costante predefinita) è diagonalmente dominante se la
somma dei valori assoluti degli elementi su ciascuna riga,
escluso l'elemento sulla diagonale principale, è minore del
valore assoluto dell'elemento corrispondente sulla
diagonale principale.
• Scrivere un programma che chiede all’utente di inserire i
valori di una matrice e stampa «Dominante» se la matrice è
diagonalmente dominante, «Non dominante» altrimenti.
• Si ricorda che la funzione int abs(int n) restituisce il valore
assoluto dell’intero n ricevuto come parametro.*/

#include <iostream>

using namespace std;

void fun(int **A, int n, int m){
    int somma=0,c=0;

    for(int i=0; i<n; i++){
        somma=0;
        for(int j=0; j<m; j++){
            if(i != j){
                somma+=abs(A[i][j]);
            }
        }
        cout << somma << endl;
        if(somma < abs(A[i][i])){
            c++;
        }
    }

    cout << "Elementi diagonalmente dominanti sono/è: " << c << endl;
}

int main(){
    //cout <<  abs(-6) << endl;
    //cout << valore_assoluto(-6) << endl;

    int **A=new int*[3];
    for(int i=0; i<3; i++){
        A[i]=new int [3];
        for(int j=0; j<3; j++){
            if(i == j)
                A[i][j]=-5;
            else
                A[i][j]=-1;

            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    fun(A, 3, 3);
}


