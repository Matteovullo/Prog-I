/*• Scrivere un programma che riempia una
matrice 20x30 chiedendo all’utente di inserire
gli elementi, ma inserendo nella matrice solo
gli elementi pari.
• Il programma termina quando la matrice è
piena.*/

#include <iostream>

using namespace std;

void fun(int **A){
    int help;
    for(int i=0; i<20; i++){
        for(int j=0; j<30; j++){
            cout << "Inserisci elemento: " << " " ;
            cin >> help;
            if(help%2 == 0)
                A[i][j]=help;
            else
                A[i][j]=INT_MAX;
            cout << endl;
        }
    }
}

int main(){
    int **A=new int *[20];
    for(int i=0; i<20; i++){
        A[i]=new int [30];
    }

    fun(A);
}