/*Scrivere un metodo che prenda in input un vettore di stringhe S e
restituisca un valore booleano che indichi se esiste una qualunque
sottostringa in comune tra loro, di almeno tre caratteri*/

#include <iostream>

using namespace std;

bool fun(string *S, int n){
    int c=0;
    int f=0;
    string r;
    int b=1;

    for(int i=0; i<n; i++){
        string l=S[i];
        for(int k=f; k<l.length(); k++){
            r+=l[k];
            c++;
            if(c >= 3){
                for(int g=i+1; g<n; g++){
                    if(S[g].find(r) != string::npos){
                        b++;
                    }
                }
                if(b == n){
                    return true;
                }
            }
            b=1;
        }
        r="";
        f++;
        c=0;
    }
    return false;
}

int main(){
    string *A=new string[3];

    A[0]="ciao";
    A[1]="eiii";
    A[2]="ciao";

    cout << fun(A, 3);
}