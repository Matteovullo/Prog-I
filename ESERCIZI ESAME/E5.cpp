/*
[Esercizio 5] Scrivere un metodo che prenda in input un parametro formale array A di interi di dimensioni n×m di elementi
distinti ed un array B di double di dimensioni k × n, e restituisca un array di n interi nel quale lo i-esimo elemento sia uguale
alla media aritmetica degli elementi presenti sia nella riga i-esima di A che nella colonna i-esima di B. NB: per decidere se un
elemento int della matrice A `e uguale ad un elemento double della matrice B si calcoli l’approssimazione all’intero pi`u vicino di
quest’ultimo.
*/

#include <iostream>
#include <cmath>
using namespace std;
#define n 3
#define m 3
#define k 3

int* fun(int **a, double **b){
	int somma1;
	double somma2;
	double media1, media2,media;
	int *c=new int [n];
	
	for(int i=0; i<n; i++){
		somma1=0;
		somma2=0;
		for(int j=0; j<m; j++){
			somma1+=a[i][j];
		}
		for(int l=0; l<k; l++){
			somma2+=b[i][l];
		}
		media1=somma1/(double)m;
		media2=somma2/k;
		media=media1+media2;
		c[i]=round(media);
	}
	return c;
}

void stampa(int *array_stampa){
    for(int i=0; i<n; i++){
        cout<<fixed<<array_stampa[i]<<endl;
	}
}

int main(){
	int **h=new int *[n];
	
	for(int i=0; i<n; i++){
		h[i]=new int [m];
		for(int j=0; j<m; j++){
			h[i][j]=1;
		}
	}
	
	double **o=new double *[k];
	
	for(int i=0; i<k; i++){
		o[i]=new double [n];
		for(int j=0; j<n; j++){
			o[i][j]=1.5;
		}
	}
	
	int *f=new int [n];
	f=fun(h,o);
	stampa(f);
}
