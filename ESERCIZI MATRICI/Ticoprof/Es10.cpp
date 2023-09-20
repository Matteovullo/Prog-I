/* Data una matrice 5×5 di interi verificare se rispetta la seguente proprietà: il contenuto di ogni 
cella non deve essere maggiore di quello delle celle nelle righe e/o nelle colonne successive.*/

#include <iostream>

using namespace std;

int main(){
    int a[5][5];
    int c=0;

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            int l=a[i][j];
            for(int y=0; i<5; i++){
                for(int x=0; j<5; j++){
                    if(a[i][j] < a[x][y] && a[i][j] != a[x][y])
                        c++;
                }
            }
            if(c == 35){
                cout << "L' elemento " << a[i][j] << "non è maggiore di tutte le altre celle" << endl;
                c=0;
            }
            else{
                cout << "L' elemento " << a[i][j] << "è maggiore di tutte le altre celle" << endl;
                c=0;
            }
        }
    }
} 
