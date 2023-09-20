/*
Esercizio 2:
Scrivere un metodo che prenda in input una matrice A di stringhe, e restituisca un boolean che
indichi se esiste una colonna in cui siano presenti due stringhe l'una inversa dell'altra.*/

#include <iostream>

using namespace std;

bool fun(string **A, int n, int m){

    int c=0;
    bool found1=true;;
    bool found2=false;
    int inverso=0;

    for(int j=0; j<m; j++){
        for(int i=0; i<n; i++){
            string h=A[i][j];
            cout << A[i][j] << endl;
            for(int k=i+1; k<n; k++){
                found1=true;
                cout << A[k][j] << endl;
                if(A[k][j].length() == h.length()){
                    for(int y=0; y<h.length(); y++){
                        if(h[y] != (A[k][j])[A[k][j].length()-1-y]){
                                found1=false;
                                break;
                            }
                        }
                    }
                }
                if(found1) 
                    inverso++;
                    cout << inverso << endl;
            }
        if(inverso >= 2){
            found2=true;
            break;
        }
        inverso=0;
    }

    return found2;
}

int main(){
    string **A=new string *[3];

    for(int i=0; i<3; i++){
        A[i]=new string[3];
    }

    A[0][0]="c";
    A[0][1]="ei";
    A[0][2]="c";
    A[1][1]="ciao";
    A[0][1]="ciao";
    A[1][1]="ciao";
    A[2][1]="ciao";
    A[0][2]="ciao";
    A[1][2]="ciao";
    A[2][2]="ciao";

    cout << fun(A, 3, 3);


}