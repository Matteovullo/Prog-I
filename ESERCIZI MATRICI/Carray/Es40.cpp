/*Assegnata una matrice A[ N , M ] di interi, individuare in essa il minore di ordine K
che presenti la somma maggiore degli elementi.
Per tale minore produrre, oltre al valore della somma, le coordinate del vertice alto
sinistro*/

#include <iostream>

using namespace std;

void fun(int **A, int n, int m, int k){
    int minori=(n-k+1)*(m-k+1);
    int somma=0;
    int somma_max=0;

    for(int i=0; i<minori-1; k++){
        somma=0;
        if(i%2==0)
        for(int j=0; j<k; j++){
            for(int h=0; h<k; h++){
                    somma+=A[j][h];
                }
            }
        }
        else{
            for(int j=0+i; j<k+i; j++){
                for(int h=0; h<k+i; h++){
                    somma+=A[j][h];
                }
            }
        }
        cout << "La somma degli elementi della matrice di ordine " << k << " numero " << i << " è " << somma << endl;
    }

}

