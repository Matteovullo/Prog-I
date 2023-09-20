/*
[Esercizio 4] Scrivere un metodo che prenda in input due parametri formali: una matrice A di dimensioni n × m ed una
matrice B di dimensioni k × n entrambe di interi positivi. Il metodo restituisca un array C di double di dimensione n nel quale
lo i-esimo elemento dello array C sia uguale al rapporto tra la somma degli elementi della riga i-esima di A e il prodotto degli
elementi della colonna i-esima di B.
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#define n 3
#define m 3
#define k 3


double* func(int **A,int **B){

    int somma=0;
    int prodotto=1;
    double rapporto;

    double *c=new double[n];

    for(int i=0; i<n; i++){
        somma=0;
        prodotto=1;
      for(int j=0;j<m;j++){
          somma+=A[i][j];
		}
      for(int e=0; e<k; e++){
          prodotto*=B[e][i];
		}
      c[i]=somma/(double)prodotto;
    }
     return c;
    }

void stampa(double *array_stampa)
  {
    for(int i=0; i<n; i++)
      {
        cout<<fixed<<array_stampa[i]<<endl;
      }
  }

int main(){
	int **a=new int *[n];
	
	for(int i=0; i<n; i++){
		a[i]=new int [n];
	}
	
	int **b=new int *[k];
	
	for(int i=0; i<k; i++){
		b[i]=new int [n];
	}
	
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			a[i][j]=5;
		}
	}
	
	for(int i=0; i<k; i++){
		for(int j=0; j<n; j++){
			b[i][j]=5;
		}
	}
	
	double *array_1=new double [n];
    array_1=func(a,b);
    stampa(array_1);
    /*for(int i=0; i<3; i++){
    	cout<<array_1[i]<<endl;
	}*/

}
