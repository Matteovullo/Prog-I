/*Scrivere un metodo che prenda come parametro formale una matrice 
S di dimensione n×m di stringhe ed una stringa X, e restituisca una 
stringa di ‘*’ la cui lunghezza è pari al numero di stringhe in S contenenti 
la sottostringa X. N.B.: Non è possibile usare substr.*/

#include <iostream>
using namespace std;
#define n 3
#define m 3

string fun(string **s, string x){
    int count;
    string str="";

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(s[i][j].find(x) != string::npos){
                count++;
            }
        }
    }
    if(count > 0){
    for(int l=0; l<count; l++){
        str+='*';
    }
    }
    return str;
}

int main(){
    string **s=new string *[n];
    for(int i=0; i<n; i++){
        s[i]=new string [m];
        for(int j=0; j<m; j++){
            s[i][j]="ciao";
        }
    }

    cout<<fun(s,"c");
}