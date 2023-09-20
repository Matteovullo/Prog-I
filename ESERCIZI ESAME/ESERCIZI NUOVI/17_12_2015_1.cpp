/*Scrivere un metodo che prenda in input una matrice quadrata di stringhe nxn e restituisca true se
esiste una stringa nella diagonale secondaria avente i primi tre caratteri coincidenti con gli ultimi tre
di una qualunque stringa nella diagonale principale, false altrimenti.*/

#include <iostream>

using namespace std;

bool fun(string **A, int n){
    int j;
    string h="";
    string l="";

    for(int i=0, j=n-1; i<n; i++, j--){
        string s=A[i][j];
        if(s.length() >= 3){
            h=s.substr(0,3);
        }
        for(int k=0; k<n; k++){
            string f=A[k][k];
            if(f.length() >= 3){
                l=f.substr(f.length()-3);
            }
            if(h == l)
                return true;
        }
    }

    return false;
}

int main(){
    string **A=new string*[3];
    for(int i=0; i<3; i++){
        A[i]=new string [3];
        for(int j=0; j<3; j++){
            A[i][j]="ciao";
        }
    }

    A[1][1]="grrgsrtgwt";

    cout << fun(A, 3);
}