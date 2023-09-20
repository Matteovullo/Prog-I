/*Definire una funzione che prende in input un array
monodimensionale di double e restituisce l’arrotondamento
all’intero piu’ vicino della somma degli elementi dello array.*/

#include <iostream>
#include <cmath>
using namespace std;

int arrotondamento(double*v,int n){
	int somma=0;
	for(int i=0; i<n; i++){
		somma+= v[i];
	}
	return round(somma);
}


int main(){
	int n=3;
	double v[n]={1.5,1.3};
	cout<<arrotondamento(v,n);
}