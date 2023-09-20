/*
23.Scrivere un metodo che prenda in input un 
parametro formale matrice K di double di dimensioni n 
x m e due interi a e b, e restituisca un array A di short 
di dimensione m, in cui l'elemento A[i] e calcolato 
come il numero di elementi della colonna i-esima di K 
tali che, approssimati all'intero più vicino, siano 
compresi tra a e b (inclusi). NB: si assuma a < b. 
*/

#include <iostream>
#include <cmath>
using namespace std;
#define n 3
#define m 3

short* fun(double **k, int a, int b){
	short *l=new short [m];
	int count;
	
	for(int j=0; j<m; j++){
		count=0;
		for(int i=0; i<n; i++){
			if(round(k[i][j])>=a && round(k[i][j])<=b){
				count++;
			}
		}
		l[j]=count;
	}
	return l;
}

void stampa(short *array_stampa)
  {
    for(int i=0; i<n; i++)
      {
        cout<<fixed<<array_stampa[i]<<endl;
      }
  }

int main(){
	double **b=new double *[m];
	for(int i=0; i<n; i++){
		b[i]=new double [n];
		for(int j=0; j<m; j++){
			b[i][j]=5.0;
		}
	}
	
	short *array_1=new short [n];
    array_1=fun(b,1,2);
    stampa(array_1);
}
