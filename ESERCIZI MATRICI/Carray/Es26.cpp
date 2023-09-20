/*Assegnata una matrice di interi A d’ordine N*M, determinare :
per ogni colonna il valore dello scarto tra l’elemento massimo e l’elemento minimo.
Modificare la matrice ponendo le colonne secondo l’ordinamento crescente degli
scarti calcolati*/

#include <iostream>
#include <ctime>

using namespace std;

int **fun(int **A, int n, int m){
    
    int **B=new int *[n];
    for(int i=0; i<n; i++)
        B[i]=new int [m];

    int arr[m];

    for(int j=0; j<m; j++){
        int min=A[j][0];
        int max=A[j][0];
        for(int i=0; i<n; i++){
            if(A[i][j] > max){
                max=A[i][j];
            }
            if(A[i][j] < min){
                min=A[i][j];
            }
        }
        arr[j]=max-min;
        cout << arr[m] << endl;
    }
    //cout << "ok" << endl;
    int index=0;

    for(int i=0; i<m; i++){
        int min=arr[0];
        for(int j=0; j<m; j++){
            if(arr[j] < min){
                min=arr[j];
                index=j;
            }
        }
        //cout << index << endl;
        for(int k=0; k<m; k++){
            B[i][k]=A[index][k];
            cout << B[k][i] << " ";
        }
        cout << endl; 
        arr[index]=INT_MAX;
    }

    return B;

}

int main(){
    srand(time(0));
    int **L=new int*[3];
    for(int i=0; i<3; i++){
        L[i]=new int[3];
        for(int j=0; j<3; j++){
            L[i][j]=rand()%50;
            cout << L[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    fun(L, 3, 3);
}