/*Caricare una matrice con le date di un anno letto da tastiera. 
La matrice è costituita da 7 colonne, corrispondenti ai giorni della settimana, 
e da 53 righe, una per ogni settimana dell’anno. Ogni data deve essere inserita 
nella colonna corrispondente al giorno della settimana. Infine stampare il calendario dell’anno.*/

#include <iostream>

using namespace std;

int main(){
    int calendario[53][7];
    int c=1;
    for(int i=0; i<53; i++){
        for(int j=0; j<7; j++){
            calendario[i][j]=c;
            c++;
            cout << calendario[i][j] << " ";
            if(c == 32){
            c=1;
        }
        }
        cout << endl;
    }
}