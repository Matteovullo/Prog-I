/*
[Esercizio 18]
Scrivere un metodo che preveda un parametro formale matrice A di double di dimensioni n × k ed un array B di interi di
dimensione n, e restituisca l’indice della colonna in A che contiene il maggior numero di elementi tali che l’approssimazione
dell’elemento stesso al numero intero pi`u vicino sia uguale al corrispondente elemento intero in B (NB: in pratica il generico
elemento di indice (i,j) va confrontato con l’elemento in B di indice i).
*/
#include <iostream>
#include <cmath>
using namespace std;
#define n 3
#define k 3

int fun(double **a, int *b){
	int max=0;
	int count=0;
	int index=0
	4;
	
	for(int j=0; j<k; j++){
		count=0;
		for(int i=0; i<n; i++){
			if(round(a[i][j])==b[i]){
				count++;
			}
		}
		if(count>max){
			max=count;
			index=j;
		}
	}
	return index;
}

int main(){
	double **d=new double *[n];
	
	for(int i=0; i<n; i++){
		d[i]=new double [k];
		for(int j=0; j<k; j++){
			d[i][j]=1.2;
		}
	}
	
	int *h=new int [n];
	
	for(int i=0; i<n; i++){
		h[i]=1;
	}
	
	cout<<fun(d,h);
}
