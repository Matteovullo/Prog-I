/*Data una matrice m1 5×5 memorizzare in ogni cella di una matrice m2 5×5 la somma
 di tutte le celle della matrice m1 che non abbiano gli stessi indici di riga o colonna della cella in oggetto.*/

#include <iostream>

using namespace std;

int main(){
    int m1[5][5];
    int c=0;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            m1[i][j] = c;
            c++;
            cout << m1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    int somma=0;

    int m2[5][5];
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(i != j)
                somma+=m1[i][j];
        }
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            m2[i][j]=somma;
            cout << m2[i][j] << " ";
        }
        cout << endl;
    }


}
