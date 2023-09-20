/*Data una matrice 6×6 verificare se è simmetrica rispetto alla diagonale principale.
(per diagonale principale si intende quella che va dall’elemento [0][0] all’elemento [5][5])
Una matrice si dice simmetrica rispetto rispetto alla diagonale principale se è uguale alla sua trasposta.
La trasposta di una matrice si ottiene prendendo in ordine le righe della matrice originale e facendole 
diventare le colonne della matrice trasposta.*/

#include <iostream>

using namespace std;

int main(){
    int a[6][6];
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            a[i][j]=1;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    int at[6][6];
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            at[i][j]=a[j][i];
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int c=0;

    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            if(at[i][j] == a[i][j])
                c++;
        }
    }
    if(c == 36)
        cout << "La matrice è simmetrica" << endl;
    else
        cout << "La matrice non è simmetrica" << endl;
}