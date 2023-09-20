/*Scrivere un metodo che prenda in input una 
matrice quadrata A di numeri interi ed un double w, e 
restituisca il valore booleano true se il rapporto tra il 
minimo ed il massimo valore della diagonale 
secondaria di A e minore o uguale a w. */

#include <iostream>
using namespace std;
#define n 3

bool fun(int **a,double w){
	int max=a[0][0];
	int min=a[0][0];
	double rapporto;
	int j;
	bool valore;

	for(int i=0, j=n-1; i<n-1; i++, j--){      
		if(a[i][j]>max){
			max=a[i][j];
		}
		if(a[i][j]<min){
			min=a[i][i];
		}
	}
	rapporto=min/(double)max;
	if(rapporto <= w) return true;
	else return false;
}

//1 2 3
//4 5 6
//7 8 9
int main(){
	int **a=new int *[n];
	
	for(int i=0; i<n; i++){
		a[i]=new int [n];
	}
	
	int x=1;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			a[i][j]=x;
			x++;
		}
	}
	
	cout<<fun(a,0.12);
}
