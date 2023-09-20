/*18.Scrivere un metodo che prenda in input una 
matrice di puntatori a stringhe M e due numeri short 
senza segno, k ed s, e restituisca il numero di colonne 
contenenti almeno k stringhe con un numero di lettere 
vocali minore di s.*/

#include <iostream>
#include <string>
#define n 2

using namespace std;

int fun(string* m[n][n], unsigned short k, unsigned short s){
	int count_vocali=0;
	int count_stringhe=0;
	int count_colonne=0;
	
	for(int j=0; j<n; j++){
		count_stringhe=0;
		for(int i=0; i<n; i++){
			for(int k=0; k<(*m[i][j]).length(); k++){
				char c=(*m[i][j])[k];
				if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
					count_vocali++;
			}
			if(count_vocali<s){
				count_stringhe++;
				count_vocali=0;
			}
		}
	}
	if(count_stringhe>=k){
		count_colonne++;
		}
	}
	return count_colonne;
}

int main(){
	string* matrice[n][n];
	
	matrice[0][0] = new string("a");
	matrice[0][1] = new string("a");
	matrice[1][0] = new string("a");
	matrice[1][1] = new string("a");
	
	cout<<fun(matrice,10,5);
}

