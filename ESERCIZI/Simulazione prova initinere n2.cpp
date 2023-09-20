/*Simulazione prova initenere
esercizio 2
Scrivere una funzione che prenda come parametro una matrice A di dimensione N x M di stringhe e restituisca una stringa
che contenga tutte le vocali delle stringhe nelle posizioni A[i][j] tali che A[i][j] `e pi`u lunga di A[j%N][i%M] di almeno i+j unit`a.
*/

#include<string>
#include <sstream>
#define n 2
#define m 3

using namespace std;

string fun(string a[n][m]){
	stringstream vocali;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(a[i][j].length>=(a[j%n][i%m].length)+i+j){
				for(int h=0; h<a[i][j].length; h++){
					char c=a[i][j][h];
					if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
						vocali<<c;
					}
				}
			}
		}
	}
	return vocali.str();
}