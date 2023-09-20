/*
33.Scrivere un metodo che prenda in input una 
matrice quadrata A di puntatori ad interi e restituisca 
un double calcolato come il rapporto tra la somma 
degli elementi della diagonale principale di A e la 
somma degli elementi della diagonale secondaria di A 
stessa. NB: Si presti attenzione ai numeri mancanti! 
*/

#include <iostream>
#define n 3

using namespace std; 

double fun(int ***b){
	int j;
	int somma1, somma2;
	
	for(int i=0, j=n-1; i<n; i++, j--){
		if(b[i][i] != nullptr){
			somma1+=*b[i][i];
		}
		if(b[i][j] != nullptr){
			somma2+=*b[i][j];
		}
	}
	
	double rapporto=(double)somma1/somma2;
	return rapporto;

}

int main(){
	int ***a=new int **[n];
	
	for(int i=0; i<n; i++){
		a[i]=new int *[n];
		for(int j=0; j<n; j++){
			if(i==j){
				a[i][j]=new int(3);
			}else{
				a[i][j]=new int(2);
			}
		}
	}
	
	cout<<fun(a);
}
