/*Memorizzare in un array bidimensionale 10 x 10 la tavola pitagorica, quella delle 
tabelline, e stampare il contenuto della matrice 
(nella prima riga si dovrà trovare la tabellina del 1: 1 2 3 4 5 6 7 8 9 10).*/

#include <iostream>

using namespace std;

int main(){
    int a[10][10];
    for(int i=0; i<10; i++){
        int num=1+i;
        for(int j=0; j<10; j++){
            a[i][j]=num*(j+1);
        }
    }
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}