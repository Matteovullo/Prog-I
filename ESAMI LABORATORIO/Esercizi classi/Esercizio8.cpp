/*Scrivere un metodo che prenda in input una matrice A di float, e restituisca il valore di somma(min(A,j)), dove min(A, j) è 
la funzione che restituisce il minimo elemento presente nella j-esima colonna di A. N.B.: Non è possibile utilizzare array ausiliari.*/

#include <iostream>
using namespace std;
#include<stdio.h>
#include<string.h>

#define n 3
#define m 4

float min(float A[n][m], int j){
    float min=A[0][j];
    for(int i=0; i<n; i++){
        if(A[i][j] < min){
            min=A[i][j];
        }
    }
    cout << min << endl;
    return min;
}

float fun(float A[n][m]){
    float somma=0.0;
    for(int j=0; j<m; j++){
        somma+=min(A, j);
    }
    return somma;
}

/*int main(){
    float **a=new float*[2];
    for(int i=0; i<2; i++){
        a[i]=new float[2];
        for(int j=0; j<2; j++){
            a[i][j]=1.5;
        }
    }
    cout << fun(a, 2, 2) << endl;
}*/

/*#include<stdio.h>
#include<string.h>

#define n 3
#define m 4

float es8(float A[n][m]) {
	float sum = 0; //somma dei minimi trovati
	for (int j=1; j<m; j+=2) { //scorriamo le colonne pari (indici 1, 3, 5, ecc)
		//dobbiamo calcolare il minimo di questa colonna
		float min = A[0][j]; //assegniamo come minimo il primo valore della colonna
		for (int i=1; i<n; i++) {//scorriamo gli elementi della colonna a partire dal secondo elemento
			if(A[i][j]<min) //se il numero corrente è il nuovo minimo
				min=A[i][j]; //aggiorniamo il minimo
		} 
		sum+=min;
	}
	return sum;

}*/


int main() {

	float A[n][m] = {{1,1,5,7},{4,7,8,2},{5,5,2,2}};


	printf("Somma dei minimi delle colonne pari %0.2f\n",fun(A));
	
}

