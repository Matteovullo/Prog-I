/*Scrivere un metodo che prenda in input una stringa S, e due indici i e j (0 ≤ i < j < lenght(S)), e
restituisca una nuova stringa T ottenuta da S invertendo i caratteri contenuti nell’intervallo [i, j].*/

#include <iostream>

using namespace std;

string fun(string S, int i, int j){

    string T=S;

    for(int x=i; x<j && j>i; x++){
        char temp=T[x];
        T[x]=T[j];
        T[j]=temp;
        j--;
    }
    
    cout << T << endl;
    return T;

}

int main(){
    string s="ciao";
    fun(s, 0, 3);
}