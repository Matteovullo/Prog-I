/*Esercizio kamicaze:
Scrivere un programma che preso in input una matrice formale di puntatori S 
a stringhe di dimensione m×n, un intero k, , preso in input un Array di interi
F di dimensione m, restituisca TRUE se almeno k righe, 
abbiano il numero di vocali minore o uguali all'elemento i-esimo di F.*/

#include <iostream>

using namespace std;

bool fun(string ***S, int n, int m, int k, int *F){

    string vocali="aeiouAEIOU";
    int c=0;
    int righe=0;

    for(int i=0; i<n; i++){
        c=0;
        for(int j=0; j<m; j++){
            for(int k=0; k<vocali.length(); k++){
                if((*S[i][j]).find(vocali[k]) != string::npos){
                    c++;
                }
            }
        }
        cout << c << endl;
        if(c <= F[i]){
            righe++;
        }
    }
    if(righe >= k)
        return true;
    else
        return false;
}



int main(){
    string ***S=new string **[3];

    for(int i=0; i<3; i++){
        S[i]=new string *[3];
        for(int j=0; j<3; j++){
           S[i][j]=new string("c");
        }
    }

    int *F=new int[3];
    for(int i=0; i<3; i++){
        F[i]=10;
    }

    cout << fun(S, 3, 3, 2, F);
}

