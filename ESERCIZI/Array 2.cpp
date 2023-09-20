#include <iostream>

using namespace std;

int main(){
	/*Si scriva un programma che dichiari un array 2×2 di stringhe e lo inizializzi con i valori:*/
	/*Si consideri l’array definito in precedenza. Si scorrano tutti gli elementi dell’array e
	si concatenino le stringhe in essi contenuti in una unica stringa.*/
	
	string x[2][2]={"tiger","tiger","burning","bright"};
	
	string somma;
	
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			somma+=x[i][j];
		}
	}
	
	cout<<somma;
	
}