/*Se A una matrice m×n e B una matrice p×q, allora il loro
prodotto di Kronecker A x B è una matrice mxp×nxq definita
a blocchi nel modo seguente:*/

#include <iostream>

using namespace std;

#define N 3
#define M 4
#define P 5
#define Q 8
int main()
{
    int a[N][M], b[P][Q], c[N * P][M * Q], i, j, k, t;
    // leggo la prima matrice
    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            cout << a[i][j];
    // leggo la seconda matrice
    for (i = 0; i < P; i++)
        for (j = 0; j < Q; j++)
            cout << b[i][j];
    // calcolo e il risultato
    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            for (k = 0; k < P; j++)
                for (t = 0; t < Q; t++)
                    c[i * P + k][j * Q + t] = a[i][j] * b[k][t];
    // stampo
    for (i = 0; i < N * P; i++)
    {
        for (j = 0; j < M * Q; j++)
        {
            cout << c[i][j];
        }
        cout << endl;
    }
    //return 0;
}

/*int **fun(int **A, int m, int n, int **B, int p, int q){
    int dim=m*p*n*q;
    int **matrice=new int[dim];


    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int sup=A[i][j];
            for(int h=0; h<q; h++){
                matrice[h][]
            }
        }
    }
}*/
