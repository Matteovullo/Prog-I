/*Data una matrice 9×9 verificare se la somma delle celle delle due diagonali è uguale.*/

#include <iostream>

using namespace std;

int main(){
    int a[9][9];
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            a[i][j]=0;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    int somma1=0, somma2=0;
    int j;
    for(int i=0, j=8; i<9; i++, j--){
        somma1+=a[i][i];
        somma2+=a[i][j];
    }
    if(somma1 == somma2){
        cout << "La somma degli elementi della diagonale principale è uguale alla somma degli elementi della diagonale secondaria!" << endl;
    }
}