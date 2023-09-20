/*Scrivere un metodo che prenda in input una stringa S e un carattere C e restituisca una nuova stringa
da cui sono state rimosse tutte le occorrenze di C.*/

#include <iostream>

using namespace std;

string fun(string s, char c){
    string l="";

    for(int i=0; i<s.length(); i++){
        if(s[i] != c){
            l+=s[i];
        }
    }

    return l;
}

int main(){
    string s="ciaaaaaaaaaaaaao";
    cout << fun("ciaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaao", 'p');
}