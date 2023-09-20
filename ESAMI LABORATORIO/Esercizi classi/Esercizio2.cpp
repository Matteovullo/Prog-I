/*Scrivere un metodo che prenda come parametro formale 
una matrice S di dimensione n×m di stringhe ed una stringa X,
e modifichi con un ‘*’ ogni carattere delle stringhe in S 
contenenti la sottostringa X. N.B.: Non è possibile usare 
substr.*/

#include <iostream>
using namespace std;
#define N 2

void fun(string **S, int n, int m, string X){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(S[i][j].find(X) != string::npos){
                /*for(int h=0; h<S[i][j].length() ; h++){
                    char c=S[i][j][h];
                    for(int l=0; l<X.length(); l++){
                        if(X[l] == c){
                            S[i][j][h]='*';
                        }
                    }
                }*/
                for(int h=0; h<S[i][j].length(); h++){
                    S[i][j][h]='*';
                }
            }
        }
    }
}

int main(){
    string **s=new string*[N];
    for(int i=0; i<N; i++){
        s[i]=new string[N];
        for(int j=0; j<N; j++){
            s[i][j]="ciao";
        }
    }
    fun(s, 2, 2, "p");
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << s[i][j] << endl;
        }
    }
}