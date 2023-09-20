#include <iostream>

using namespace std;

int main(){
	/*Come secondo esercizio implementativo, implementare il crivello
di Eratostene. La funzione che implementerete usa come
parametro un intero n e poi utilizza un array dinamica per
memorizzare tutti i numeri primi minori di n calcolati.*/

int n;

cout<<"ins. n: ";cin>>n;

int V[n];

int i=0,k=0;
while (i<n){
	if(n-1%2!=0 || n-1%3!=0 || n-1%5!=0 || n-1&7!=0 || n-1%11!=0)

	while(k<n){
		while(i<n){
			V[k][i]=n-1;
		}
	}
	n--;
	
}

}