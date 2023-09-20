/*Scrivere un metodo che prenda in input una matrice A di stringhe ed una stringa Str, 
e restituisca un boolean che indichi se Str è sottostringa di tutte le stringhe presenti 
in una qualche colonna di A.*/

#include <iostream>
using namespace std;
#define n 3
#define m 3

bool fun(string **a, string str){

    for(int j=0; j<m; j++){
        int count=0;
        for(int i=0; i<n; i++){
            if(a[i][j].find(str) != string::npos){
                count++;
            }
        }
        if(count == n) return true;
        else continue;
    }
    return false;
}

int main(){
    string **s=new string *[n];
    for(int i=0; i<n; i++){
        s[i]=new string [m];
        for(int j=0; j<m; j++){
            s[i][j]="ciao";
        }
    }

    cout<<fun(s,"n");
}
