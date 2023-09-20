/*Esercizio 1
Scrivere un metodo che prenda in input due matrici quadrate A e B di char, e restituisca un boolean
che indichi se esiste una riga di A identica ad una colonna di B.*/

#include <iostream>

using namespace std;

bool fun(char **A, char **B, int n, int m){
    if(n != m)
        return false;

    char array[n];

    for(int z=0; z<n; z++){
        for(int h=0; h<n; h++){
            array[h]=A[h][z];
        }
        for(int j=0; j<n; j++){
            int c=0;
            for(int i=0; i<n; i++){
                if(array[i] == B[i][j])
                    c++;
            }
            cout << c << endl;
            if(c==n)
                return true;
        }
    }
    return false;
}

int main(){
    char **a=new char*[4];
    for(int i=0; i<4; i++){
        a[i]=new char[4];
        for(int j=0; j<4; j++){
            if(i != j)
                a[i][j]='b';
            else
                a[i][j]='b';
            
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    char **b=new char*[3];
    for(int i=0; i<3; i++){
        b[i]=new char[3];
        for(int j=0; j<3; j++){
            if(i != j)
                b[i][j]='b';
            else
                b[i][j]='b';
            
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    cout << a[0][1] << endl;
    cout << b[1][0] << endl;
    cout << fun(a,b,4,3) << endl;





}



