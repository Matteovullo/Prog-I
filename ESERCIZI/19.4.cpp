/*Definire una funzione che prende in input un array
monodimensionale di interi senza segno e restituisce la media degli
elementi di tale array.*/
#include <iostream>

using namespace std;

float func(unsigned int *a, int n){
	float media;
	int somma=0;
	for(int i=0; i<n; i++){
		somma+=a[i];
	}
	media=somma/n;
	return media;
}

int main(){
	int n;
	unsigned int *a=new unsigned int[n];
	
	cout<<func(a,2);
}


