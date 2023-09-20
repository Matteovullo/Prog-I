/*Esercizio 2:
Scrivere un metodo che prenda in input una matrice A di stringhe ed una stringa Str, e restituisca un
boolean che indichi se Str è sottostringa di almeno metà delle stringhe presenti in una qualche riga
di A.*/

#include <iostream>
#include <cmath>

using namespace std;

bool fun(string **A, int n, int m, string Str){

    for(int i=0; i<n; i++){
        int c=0;
        for(int j=0; j<m; j++){
            if(A[i][j].find(Str) != string::npos){
                c++;
            }
        }
        cout << c << endl;
        if(c>=round(m/2)){
            return true;
        }
    }
    return false;

}

int main(){
    string **S=new string*[3];
    for(int i=0; i<3; i++){
        S[i]=new string[3];
        for(int j=0; j<3; j++){
            S[i][j]="ciao";
        }
    }
    string str="h";

    cout << fun(S, 3, 3, str); 
}