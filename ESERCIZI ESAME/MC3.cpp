/*Scrivere un metodo che prenda in input un 
parametro formale matrice quadrata Q di interi ed un 
double w, e restituisca un valore booleano true se 
esiste almeno una colonna della matrice Q tale che il 
rapporto tra la somma degli elementi della colonna 
stessa e la somma degli elementi della diagonale 
secondaria di Q sia maggiore di w. */

#include <iostream>
#define n 3
using namespace std;

bool func(int **q, double w){

 	bool valore;
 	int somma_colonna=0;
 	int somma_diagonale=0;
 	int j;
 	double rapporto;
 	
 	for(int i=0, j=n-1; i<n; i++, j--){
 		somma_diagonale+=q[i][j];
	}
	
 	for(int j=0; j<n; j++){
 		somma_colonna=0;
 		for(int i=0; i<n; i++){
 			somma_colonna+=q[i][j];
 			}
 			rapporto=somma_colonna/somma_diagonale;
 			if(rapporto>w){
 				valore=true;
 				break;
			}else{
				continue;
			}
	}
	return valore;
}

int main(){
	int **a=new int *[n];
	
	for(int i=0; i<n; i++){
		a[i]=new int [n];
	}
	
	int x=0;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			a[i][j]=x;
			x++;
		}
	}
	
	cout<<func(a,0.7);
}

 	