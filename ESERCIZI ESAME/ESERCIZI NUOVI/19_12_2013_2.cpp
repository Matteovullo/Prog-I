/*
Esercizio 2:
Scrivere un metodo che prenda in input un array A di stringhe, e restituisca una stringa ottenuta
concatenando i primi 4 caratteri di tre stringhe in A che abbiano la stessa desinenza di due lettere o
restituisca la stringa vuota se le tre stringhe non esistono.
*/

#include <iostream>
#include <ctime>

using namespace std;

string fun(string *A, int n){

    string x="";
    string h="";
    int c=0;
    for(int i=0; i<n; i++){
        x="";
        c=1;
        if(A[i].length() >= 4){
            x+=A[i].substr(0,4);
            h=A[i].substr(A[i].length()-2,2);
        }
        for(int j=i+1; j<n; j++){
            if(A[j].substr(A[j].length()-2,2) == h && A[j].length() >= 4){
                x+=A[j].substr(0,4);
                c++;
            }
            cout << c << endl;
            if(c==3){
                return x;
            }
        }
    }
    cout << "Nessuna stringa trovata" << endl;
    return x="";

}

int main(){
    string *B=new string [6];
    B[0]="ciao";
    B[1]="c";
    B[2]="ciao";
    B[3]="ei";
    B[4]="eeeeee";
    B[5]="ciao";

    cout << fun(B, 6) << endl;
}