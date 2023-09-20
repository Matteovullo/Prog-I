/*Simulazione prova initenere
esercizio 1
Scrivere una funzione che prenda come parametri formali una matrice bidimensionale A di double (usare un doppio puntatore
a double) e due interi M e N indicanti le dimensioni della matrice (dunque M x N) e restituisca una matrice B di double di
dimensioni (N x M) il cui elemento B[i][j] sia pari a A[j][i] se A[j][i] `e maggiore di un numero casuale s compreso tra 0 e 1, mentre
sia uguale a A[i%M][j%N] altrimenti.
*/

#include <cstdlib>
#include <ctime>

double** fun(double **a, int n,int m){
	srand(time(0));
	
	double **b=new double *[n];
	
	for(int i=0; i<n; i++){
		b[i]=new double [n];
		for(int j=0; j<m; j++){
			double s=rand()/double(RAND_MAX);
			if(a[i][j]>s){
				b[i][j]=a[i][j];
			}else{
				b[i][j]=a[i%m][j%n];
			}
		}
	}
	
	return b;
}

#include <iostream>
using namespace std;

int main(){
	int n=2;
	int m=3;
	double **c=new double *[n];
		for(int i=0; i<n; i++){
		    c[i]=new double [n];
	    }
	    
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<<"inserire un numero in virgola mobile: ";
			cin>>c[i][j];
		}
	}
	
	cout<<fun(c,2,3);
	
}