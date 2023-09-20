/*Esercizio 2:
Scrivere un metodo che prenda in input un array bidimensionale A di stringhe, e restituisca una
stringa contenente la concatenazione, nell'ordine, di tutte le vocali di indice pari delle stringhe
presenti nella penultima colonna di A.*/

#include <iostream>

using namespace std;

string fun(string **A, int n, int m){
    string x="";

    for(int i=0; i<n; i++){
        string l=A[i][m-2];
        for(int i=0; i<l.length(); i+=2){
            x+=l[i];
        }
    }
    return x;
}

int main(){
    string **B=new string *[3];
    for(int i=0; i<3; i++){
        B[i]=new string[3];
        for(int j=0; j<3; j++){
            //B[i][j]="ciao";
            //cout << B[i][j] << endl;
        }
        //cout << endl;
    }

    B[0][0]="ciao";
    B[0][1]="ciao";
    B[0][2]="ciao";
    B[1][0]="ei";
    B[1][1]="ei";
    B[1][2]="ei";
    B[2][0]="ciao";
    B[2][1]="ciao";
    B[2][2]="ciao";

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << B[i][j] << endl;
        }
        cout << endl;
    }

    cout << endl;
    cout << fun(B,3,3);

}