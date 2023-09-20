/*Memorizzare in un array bidimensionale 5 per 5 tutti zeri tranne nelle celle della 
diagonale principale dove memorizzare uno
(non usare l’inizializzazione con parentesi grafe nemmeno per gli zeri)*/

#include <iostream>

using namespace std;

int main(){
    int a[5][5];
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(i==j) a[i][j]=1;
            else a[i][j]=0;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}