/*Scrivere un metodo che prenda in input una 
matrice A di numeri interi e due double w e v, e 
restituisca il valore booleano true se esiste almeno una 
colonna di A in cui la media dei suoi elementi e 
compresa tra w e v. NB: Si assuma che w <=v. */

#include<iostream>
using namespace std;

bool func(int **a, int n, int m, double w, double v){
	bool valore;
	double somma_colonna=0;

	for(int j=0; j<m; j++){
		somma_colonna=0;
		for(int i=0; i<n; i++){
			somma_colonna+=a[i][j];
		}
		if(somma_colonna/n <= v && somma_colonna/n >=w){
			valore=true;
			break;
		}else{
			continue;
		}
	}
	return valore;
}

int main(){
	int n=3;
	int m=3;
	int **a=new int *[n];
	
	for(int i=0; i<n; i++){
		a[i]=new int [n];
	}
	
	int x=0;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			a[i][j]=x;
			x++;
		}
	}
	
	cout<<func(a,3,3,0.1,10.0);
}