/*Scrivere un metodo che prende in input una matrice quadrata A di n x n puntatori a stringhe, e
restituisca un puntatore ad una stringa ottenuta concatenando tutti i caratteri centrali delle stringhe
di lunghezza dispari presenti nella diagonale secondaria di A.*/

#include <iostream>

using namespace std;

string *fun(string ***A, int n){
    string h="";
    string *k=&h;
    int j;
    for(int i=0, j=n-1; i<n; i++, j--){
        //cout << "ok" << endl;
        if(A[i][j]){
            if((*A[i][j]).length()%2 != 0){
                int len=(*A[i][j]).length();
                //cout << len << endl;
                h+=(*A[i][j])[len];
            }
        }
    }
    //cout << *k << endl;
    return k;
}

int main(){
    string ***A=new string**[2];
    for(int i=0; i<2; i++)
        A[i]=new string*[2];

    A[0][0]=new string("cia");
    A[0][1]=new string("ciaoo");
    A[1][0]=new string("ciaoo");
    A[1][1]=new string("ciaoo");

    string *g=fun(A, 2);

    cout << *g << endl;
    
}