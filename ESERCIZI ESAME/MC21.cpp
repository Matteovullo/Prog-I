/*
21.Scrivere un metodo che prenda in input una 
matrice di double D ed un intero a, e restituisca il 
valore booleano true se esiste almeno una colonna in 
D nella quale la somma di una qualsiasi coppia di 
elementi adiacenti, approssimata all'intero piu vicino, 
sia uguale ad a.
*/

#include <iostream>
#include <cmath>
#define n 2
#define m 2
using namespace std;

bool fun(double **d, int a){
	double somma;
	bool valore;
	
	for(int j=0; j<m; j++){
		for(int i=0; i<n-1; i++){
			somma+=d[i][j]+d[i+1][j];
			if(round(somma)==a){
				valore=true;
				break;
			}else{
				valore=false;
				somma=0.0;
				continue;
			}
		}
		if(valore){
			break;
		}
	}
	return valore;
}

int main(){
	double **a=new double *[n];
	
	for(int i=0; i<n; i++){
		a[i]=new double [n];
		for(int j=0; j<m; j++){
			a[i][j]=1.8;
		}
	}
	
	cout<<fun(a,3);
}
