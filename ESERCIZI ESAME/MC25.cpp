/*
25.Scrivere un metodo che prenda in input una 
matrice di interi M di dimensioni nx m, uno short k ed 
un double x, e restituisca il valore booleano true se 
esiste almeno una colonna in M contenente 
esattamente k coppie di elementi adiacenti tali che il 
rapporto tra il primo elemento ed il secondo elemento 
di ogni coppia sia minore di x. NB: Si assuma k <= n -
1 e si presti attenzione alle divisioni per zero!
*/

#include <iostream>
#define n 3
#define m 3
using namespace std;


bool fun(int **b, short k, double x){

	for(int j=0; j<m; j++){
		int count=0;
		for(int i=0; i<n-1; i++){
			if((b[i+1][j] != 0) && (b[i][j]/(double)b[i+1][j] < x))
				count++;
			if(count==k) return true;
		}
	}
	return false;

}

int main(){
	int **a=new int *[n];
	
	for(int i=0; i<n; i++){
		a[i]=new int [n];
		for(int j=0; j<m; j++){
			a[i][j]=2;
		}
	}
	
	cout<<fun(a,1,1.5);
}
