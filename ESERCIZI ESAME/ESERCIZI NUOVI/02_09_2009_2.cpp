/*Esercizio 2:
Scrivere un metodo che prenda in input un array S di stringhe, e restituisca un boolean che indichi
se la stringa x contiene più vocali o più consonanti, dove x è la concatenazione, nell'ordine, di tutti i
caratteri di posto pari delle stringhe in S di indice dispari.
P.S.: Tutti i caratteri sono in minuscolo.*/

#include <iostream>

using namespace std;


bool fun(string *S, int n){
    string x="";
    string vocali="aeiouAEIOU";
    int v=0;
    int c=0;

    for(int i=1; i<n; i+=2){
        for(int j=0; j<S[i].length(); j+=2){
            x+=S[i][j];
        }
    }

    cout << x << endl;

    for(int i=0; i<x.length(); i++){
        if(vocali.find(x[i]) != string::npos)
            v++;
    }

    cout << v << endl;

    for(int i=0; i<x.length(); i++){
        if(vocali.find(x[i]) == string::npos)
            c++;
    }

    cout << c << endl;

    if(v>c)
        return true;
    else if(c>v)
        return false;
    else if(c==v)
        cout << "Errore!" << endl;
        return -1;

}

int main(){
    string a[3];
    for(int i=0; i<3; i++){
        a[i]="acc";
    }

    cout << fun(a,3);
}