/*Memorizzare una matrice di dimensioni 6×6 e verificare se è “somma-palindroma-per-riga” 
ovvero se la somma degli elementi nella prima riga è uguale alla somma degli elementi nell’ultima, 
se la somma degli elementi della seconda è uguale a quella degli elementi della penultima, ecc.*/

#include <iostream>

using namespace std;

int main(){
    int a[6][6];
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            a[i][j]=0;
        }
    }

    for(int i=0; i<3; i++){
        int somma1=0;
        int somma2=0;
        for(int j=0; j<6; j++){
            somma1+=a[i][j];
        }
        for(int h=0; h<6; h++){
            somma2+=a[6-i-1][h];
        }
        if(somma1 == somma2)
            cout<< "riga " << i << " è palindroma con la riga " << 6-i-1 << endl;
    }
}