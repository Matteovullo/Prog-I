#include <iostream>
#include <cmath>
#define n 10
using namespace std;


int somma_elementi(double *a){
	double somma_elementi=0;
	for(int i=0; i<n; i++){
		somma_elementi+=a[i];
	}
	int risultato=round(somma_elementi);
	return risultato;
}

int main(){
	double a[n];
	for(int i=0; i<n; i++){
		cout<<"inserire numero: ";cin>>a[i];
	}
	cout<<somma_elementi(a);
}