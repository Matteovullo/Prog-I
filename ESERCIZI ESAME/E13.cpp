/*
Esercizio 13] Scrivere un metodo che preveda due parametri formali matrici di interi, A e B di dimensioni k × n ed
n × k rispettivamente, e restituisca uno array monodimensionale di k elementi double in cui lo i-esimo elemento sia uguale alla
differenza tra la media aritmetica degli elementi della riga i-esima di A ed il minimo valore degli elementi della colonna i-esima
di B.
*/

#include <iostream>
using namespace std;
#define n 3
#define k 3

double* fun(int **a, int **b){
	double* c=new double [k];
	
	for(int i=0; i<k; i++){
		int somma=0;
		int min=b[i][0];
		for(int j=0; j<n; j++){
			somma+=a[i][j];
			if(b[i][j]<min){
				min=b[i][j];
			}
		}
		double media=somma/(double)n;
		c[k]=media-min;
	}
	return c;
}

void stampa(double *array_stampa){
    for(int i=0; i<n; i++){
        cout<<fixed<<array_stampa[i]<<endl;
      }
}

int main(){
	int **d=new int *[k];
	
	for(int i=0; i<n; i++){
		d[i]=new int [k];
		for(int j=0; j<k; j++){
			d[i][j]=1;
		}
	}
	
	int **h=new int *[n];
	
	for(int i=0; i<n; i++){
		h[i]=new int [k];
		for(int j=0; j<k; j++){
			h[i][j]=1;
		}
	}
	
	double* f=new double [k];
	f=fun(d,h);
	stampa(f);
}
