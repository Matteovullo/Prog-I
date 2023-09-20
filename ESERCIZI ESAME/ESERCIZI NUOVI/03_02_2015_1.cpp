/*Scrivere un metodo che prenda come parametro formale una matrice di numeri reali n x m, esamini
solamente gli elementi presenti nella terza colonna, e restituisca in output il prodotto dei due numeri
più “vicini” tra loro (cioè la cui differenza in valore assoluto è minima).*/

#include <iostream>

using namespace std;

int fun(int **A, int n, int m){
    int prodotto_finale;
    int min;
    if(m < 3){
        return -1;
    }else{
        for(int i=0; i<n-1; i++){
            int c=A[i+1][2]-A[i][2];
            int prodotto=A[i+1][2]*A[i][2];
            //cout << c << endl;
            //cout << prodotto << endl;
            if(i == 0){
                min=c;
                prodotto_finale=prodotto;
            }
            if(abs(c) < min){
                prodotto_finale=prodotto;
                min=abs(c);
            }
        }
        return prodotto_finale;
    }

}

int main(){
    int **A=new int*[2];
    int c=0;
    for(int i=0; i<2; i++){
        A[i]=new int [2];
        for(int j=0; j<2; j++){
            A[i][j]=c;
            c++;
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    cout << fun(A, 2, 2);
}