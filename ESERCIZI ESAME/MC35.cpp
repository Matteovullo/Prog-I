/*Scrivere un metodo che prenda in input una 
matrice Q di puntatori a int di dimensione n × m e due 
float a e b e restituisca un array di float di dimensione 
m tale che lo i-esimo elemento dello array contiene la 
media dei soli elementi della colonna i-esima compresi 
tra a e b (estremi inclusi). Nel confronto tra interi e 
numeri in virgola mobile si consideri l’arrotondamento 
di questi ultimi al numero intero più prossimo ad essi. 
NB: Si presti attenzione ai numeri mancanti!*/
#include <iostream>
#include <cmath>
using namespace std;
#define n 2
#define m 2

float* fun(int *q[n][m], float a, float b){
	float* l=new float[m];
	int count;
	int somma;
	float rapporto; 
	int a1;
	a1=round(a);
	int b1;
	b1=round(b);
	int s;
	
	for(int j=0; j<m; j++){
		somma=0;
		rapporto=0.0;
		count=0;
		for(int i=0; i<n; i++){
			if(q[i][j]!=nullptr){
				s=*q[i][j];
				if(s>=a1 && s<=b1){
				somma+=*q[i][j];
				count++;
				}
			}
		}
		rapporto=(float)somma/count;
		l[j]=rapporto;
	}
	return l;
}

void stampa(float *array_stampa){
    for(int i=0; i<n; i++){
        cout<<fixed<<array_stampa[i]<<endl;
      }
  }

int main(){
	int* matrice[n][m];
	
	matrice[0][0] = new int(1);
	matrice[0][1] = new int(1);
	matrice[1][0] = new int(2);
	matrice[1][1] = new int(5);
	
	float* arr=new float[m];
	arr=fun(matrice,0.1,5.5);
	stampa(arr);
}