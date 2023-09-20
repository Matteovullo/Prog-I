/*L’utente inserisce una matrice composta da numeri interi. Il programma dopo avere 
chiesto all’utente di inserire i valori di tutte le celle, scambia le righe pari con quelle dispari. 
Le dimensioni della matrice inserita dall’utente sono fissate all’interno del programma.*/

#include <iostream>

using namespace std;

int main(){
    int n, m;
    cout << "Inserire dimensione delle righe";
    cin >> n;
    cout << "Inserire dimensioni delle colonne";
    cin >> m;

    int a[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << "Inserire il valore alla posizone: " << i << " " << j;
            cin >> a[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    int b[n];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i%2 == 0){
                b[j]=a[i][j];
            }
            else{
                a[i][j]=b[j];
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

}

