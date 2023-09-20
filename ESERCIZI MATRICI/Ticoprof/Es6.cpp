/*Es 6. Data una matrice 5×5 di interi e due numeri interi n e m 
verificare se tutte le celle della matrice hanno valori compresi tra n e m.*/

#include <iostream>

using namespace std;

int main(){
    int a[5][5];
    int n=0;
    int m=0;
    int c=0;
    
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            a[i][j]=0;
        }
    }

    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            if(a[i][n] >=n && a[i][j] <= m){
                c++;
            }
        }
    }

    if(c == 36)
        cout << "Tutte le celle della matrice hanno un numero compreso tra n e m" << endl;
    else
        cout << "Tutte le celle della matrice non hanno un numero compreso tra n e m" << endl;
}