/*Scrivere un metodo che prenda come parametro formale una matrice S di 
dimensione n×m di stringhe ed una stringa X, e modifichi con un ‘*’ ogni 
carattere delle stringhe in S contenenti la sottostringa X. N.B.: Non è possibile usare substr.*/

#include <iostream>
#define n 3
#define m 3
using namespace std;

void fun(string **s, string x){

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(s[i][j].find(x) != string::npos){
                for(int c=0; c<s[i][j].length(); c++){
                    char t=s[i][j][c];
                    for(int f=0; f<x.length(); f++){
                        char y=x[f];
                        if(t==y){
                            s[i][j][c]='*';
                        }
                    }
                }
            }
        }
    }

}

void stampa(string **array_stampa){

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<array_stampa[i][j]<<endl;
        }
    }

}

int main(){
    string **d=new string *[n];
    for(int i=0; i<n; i++){
        d[i]=new string [m];
        for(int j=0; j<m; j++){
            d[i][j]="ciao";
        }
    }

    fun(d,"ciao");

    stampa(d);

}