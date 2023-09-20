/*Assegnata una matrice di interi di riempimenti N ed M,
eliminare la riga in posizione K*/

#include <iostream>
#include <ctime>

using namespace std;

void fun(int **A, int n, int m, int k){

    int **B=new int*[n-1];
    for(int i=0; i<n-1; i++){
        B[i]=new int [m];
    }

    for(int i=0; i<n-1; i++){
        for(int j=0; j<m; j++){
            if(i == k){
                B[i][j]=A[i+1][j];
                cout << B[i][j] << " ";
            }
            if(i != k && i<k){
                B[i][j]=A[i][j];
                cout << B[i][j] << " ";
            }
            if(i > k){
                B[i][j]=A[i+1][j];
                cout << B[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main(){
    srand(time(0));
    int **C=new int *[4];
    for(int i=0; i<4; i++){
        C[i]=new int [4];
        for(int j=0; j<4; j++){
            C[i][j]=rand();
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    fun(C, 4, 4, 0);


}
