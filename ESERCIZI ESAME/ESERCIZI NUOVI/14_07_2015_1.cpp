/*Esercizio 1 (punti 15) (scrivere la soluzione di seguito)
Scrivere un metodo che prenda in input un array di stringhe A e un intero h e restituisca un
puntatore al primo carattere di una sottostringa di lunghezza h comune a tutte le stringhe di
A; NULL in caso contrario.*/

#include <iostream>

using namespace std;

char *fun(string *A, int n, int h){
    char c='\0';
    char *t=&c;
    string sup="";
    int d=0;

    for(int i=0; i<n; i++){
        string str=A[i];
        for(int l=0; l<str.length(); l++){
            for(int u=l; u<str.length(); u++){
                sup+=str[u];
                d++;
                if(d == h){
                    break;
                }
            }
            c=0;
            cout << sup << endl;
            for(int j=i+1; j<n; j++){ 
                if(A[j].find(sup) != string::npos && sup.length() == h){
                    c=sup[0];
                    return t;
                }
            }
            sup="";
        }
    }
    return nullptr;
}

int main(){
    string *A=new string [3];

    A[0]="ciao";
    A[1]="cia";
    A[2]="ggg";

    cout << fun(A, 3, 3);

}