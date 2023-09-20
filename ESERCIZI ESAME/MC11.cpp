/*Scrivere un metodo che prenda come parametri 
formali una matrice quadrata A n×n di puntatori ad int 
e restituisca in output un bool che indichi se la somma 
degli elementi puntati dalla diagonale sottostante la 
diagonale secondaria è divisibile per n. */

#include <iostream>
#define n 2
using namespace std;

bool func(int* a[n][n]){
	int somma=0;
	bool valore;
	for(int i=n-1; i>0; i--){
		somma+=*a[n-1][i];
	}
	if(somma%n==0){
		valore=true;
	}else{
		valore=false;
	}
	return valore;
}

int main(){
	int* matrice[n][n];
	
	matrice[0][0] = new int(1);
	matrice[0][1] = new int(2);
	matrice[1][0] = new int(3);
	matrice[1][1] = new int(5);
	
	cout<<func(matrice);
}

