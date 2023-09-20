#include <iostream>

using namespace std;
int main(){
	/*Si scriva un programma che prenda in input dall’utente un valore numerico e lo divida per due ripetutamente finché 
	esso non diventa minore di 1. Si stampi il risultato a schermo.*/
	
	float x;
		
	cout<<"ins. numero: ";cin>>x;
	
	while(x>=1){
	    x/=2;
    }
	cout<<x;

}