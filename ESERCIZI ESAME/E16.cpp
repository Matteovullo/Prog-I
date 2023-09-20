/*
[Esercizio 16]
Scrivere un metodo che prenda in input una matrice S di puntatori a stringhe di dimensione n × m ed un array B di short
di dimensione m e che restituisca uno short che rappresenti l’indice della riga in S con il maggior numero di stringhe aventi
lunghezza minore o uguale del corrispondente numero nello array B (NB: in pratica la lunghezza della stringa di indici (i,j) va
confrontata con il numero di indice j in B).
*/

#include <string>
#include <iostream>
using namespace std;

#define n 2
#define m 2

short fun(string* s[n][m], short *b){
	int index;
	int count=0;
	int max;
	
	for(int i=0; i<n; i++){
		count=0;
		for(int j=0; j<m; j++){
			if((*s[i][j]).length()<=b[j]){
				count++;
			}
		}
		if(count>max){
			max=count;
			index=i;
		}
	}
	return index;
}

int main(){
	string* matrice[n][m];
	matrice[0][0] = new string("a");
	matrice[0][1] = new string("a");
	matrice[1][0] = new string("a");
	matrice[1][1] = new string("a");
	
	short* k=new short [m];
	
	for(int i=0; i<m; i++){
		k[i]=1;
	}
	
	cout<<fun(matrice,k);
}
