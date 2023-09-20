#include <iostream>
#define n 10
using namespace std;

/*Si definisca una funzione sum che prende in input due array monodimensionali della stessa dimensione n 
(anche questo parametro è un input alla funzione) e restituisce un vettore contenente la somma elemento per elemento dei due vettori.*/

int* sum(int *a, int *b){
	int *v=new int[n];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			v[i]=a[i]+b[i];
		}
	}
	return v;
}

int main(){
	int *a=new int[n]{1,2,3,4,5};
	int *b=new int[n]{1,2,3};
	int *v=sum(a,b);
	for(int i = 0; i < n; i++){
		cout << i << ": " << v[i] << endl;
	}
	delete[] v;
	v = nullptr;
}

