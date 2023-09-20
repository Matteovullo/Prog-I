/*Date due matrici 4×4 calcolarne la somma 
(la somma tra matrici si calcola commando i contenuti delle celle nella stessa posizione).*/

#include <iostream>

using namespace std;

int main(){
    int a[4][4];
    int c=0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            a[i][j] = c;
            c++;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int b[4][4];
    c=0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            b[i][j] = c;
            c++;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int somma[4][4];

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            somma[i][j]=a[i][j]+b[i][j];
            cout << somma[i][j] << " ";
        }
        cout << endl;
    }
}