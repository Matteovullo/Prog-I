/*Verificare se una matrice 6×6 è la matrice identità
 (la matrice identità è formata da zeri su tutte le celle tranne quelle della diagonale dove ci sono uni).*/

#include <iostream>

using namespace std;

int main(){
    int a[6][6];
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            a[i][j]=1;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    bool valore=true;
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            if(i == j){
                if(a[i][j] != 1){
                    valore=false;
                    break;
                    }
                }
            if(a[i][j] != 0){
                valore=false;
                break;
            }
        }
    }
    if(valore)
        cout << "La matrice è identità" << endl;
    else
        cout << "La matrice non è identità" << endl;
}