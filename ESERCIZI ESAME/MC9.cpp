/*
9.Scrivere un metodo che prenda in input un 
parametro formale matrice A di interi di dimensioni 
nxn ed un double w, e restituisca un valore booleano 
true se esiste almeno una colonna della matrice A per 
cui il rapporto tra la somma degli elementi della 
colonna stessa e la somma degli elementi della 
diagonale principale di A sia maggiore di w. 
*/
#include <iostream>
#define n 3
using namespace std;

bool fun(int **a,double w){
	double somma1,somma2;
	bool valore;
	double rapporto;
	
	for(int i=0; i<n; i++){
		somma1+=a[i][i];
	}
	
	for(int j=0; j<n; j++){
		rapporto=0;
		somma2=0;
		for(int i=0; i<n; i++){
			somma2+=a[i][j];
		}
		rapporto=somma1/(double)somma2;
		if(rapporto>w){
			valore=true;
			break;
		}else{
			valore=false;
			continue;
		}
	}
	return valore;
}

int main(){
	int** b=new int *[n];
	
	for(int i=0; i<n; i++){
		b[i]=new int [n]; 
		for(int j=0; j<n; j++){
			b[i][j]=1;
		}
	}
	
	cout<<fun(b,2.0);
}
