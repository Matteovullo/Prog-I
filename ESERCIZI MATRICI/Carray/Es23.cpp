/*Se A una matrice m×n e B una matrice p×q, allora il loro
prodotto di Kronecker A x B è una matrice mxp×nxq definita
a blocchi nel modo seguente:*/

#include <iostream>

using namespace std;

int **fun(int **A, int m, int n, int **B, int p, int q){
    int **array=new int*[m*p];
    for(int i=0; i<m*p; i++){
        array[i]=new int[n*p];
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            for(int h=0; h<p; h++){
                for(int k=0; k<q; k++){
                array[i][h+q]=A[j][i]*B[i][h];  
                cout << array[i][h+q] << " ";
                }
            }
            cout << endl;
        }
    }

    return array;
} 

int main(){
    int **A=new int*[2];
    for(int i=0; i<2; i++){
        A[i]=new int[2];
        for(int j=0; j<2; j++){
            A[i][j]=1;
        }
    }

    int **B=new int*[2];
    for(int i=0; i<2; i++){
        B[i]=new int[2];
        for(int j=0; j<2; j++){
            B[i][j]=1;
        }
    }

    fun(A, 2, 2, B, 2, 2);
}