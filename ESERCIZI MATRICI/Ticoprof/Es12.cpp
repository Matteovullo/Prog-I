/*Verificare se in una matrice 5×5 in ogni cella è memorizzato il prodotto dei suoi indici di riga e di colonna.*/

#include <iostream>

using namespace std;

int main(){
    int a[5][5];
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            a[i][j]=i*j;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    int c=0;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(a[i][j] == i*j)
             c++;
        }
    }
    if(c == 25)
        cout << "Ogni elemento della matrice contiene il suo prodotto dell' indice di riga e di colonna" << endl;
    else
        cout << "Ogni elemento della matrice non contiene il suo prodotto dell' indice di riga e di colonna" << endl;
}