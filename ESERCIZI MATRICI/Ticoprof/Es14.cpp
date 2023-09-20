/*Es 14. Verificare se tutte le celle dei “bordi” di una matrice 6×6 contengono
 lo stesso valore (per bordi di una matrice si intendono la prima e l’ultima riga e la prima e l’ultima colonna).*/

#include <iostream>

using namespace std;

int main(){
    int a[5][5];
    int c=0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            a[i][j] = c;
            c++;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    bool valore = true;
    for (int k = 0; k < 6-1; k++){
        if (a[0][k] != a[0][k + 1])
            valore = false;
        break;
    }
    for (int k = 0; k < 6-1; k++){
        if (a[k][0] != a[k+1][0])
            valore = false;
        break;
    }
    for (int k = 0; k < 6-1; k++){
        if (a[5][k] != a[5][k + 1])
            valore = false;
        break;
    }
    for (int k = 0; k < 6-1; k++){
        if (a[k][5] != a[k + 1][5])
            valore = false;
        break;
    }
    if(valore)
        cout << "Tutte le celle dei “bordi” contengono lo stesso valore" << endl;
    else
        cout << "Tutte le celle dei “bordi” non contengono lo stesso valore" << endl;
}