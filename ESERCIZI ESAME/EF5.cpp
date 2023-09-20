/*Scrivere un metodo che prenda come parametri formali una matrice A di stringhe ed uno short w, 
e restituisca in output un bool che indichi se esiste una riga di A in cui siano presenti 
almeno due stringhe in cui i primi w caratteri dell’una siano uguali agli ultimi w caratteri 
dell’altra (nello stesso ordine).*/

#include <iostream>
#define n 3
#define m 3
using namespace std;

bool fun(string **s, short w){
    int count;

    for(int i=0; i<n; i++){
        count=0;
        for(int j=0; j<m; j++){
            for(int k=0; k<m; k++){
                if(k != j){
                if(s[i][j].substr(0,w) == s[i][k].substr(s[i][k].length()-w,w)){
                    count++;
                }
                }
            }
        }
        if(count > 2) return true;
    }
    return false;
}

int main(){
    string **d=new string *[n];
    for(int i=0; i<n; i++){
        d[i]=new string [m];
        for(int j=0; j<m; j++){
            d[i][j]="abbgfgba";
        }
    }

    cout<<fun(d,2);

}