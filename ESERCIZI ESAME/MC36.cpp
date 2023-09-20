/*
36.Scrivere un metodo che prenda in input una 
matrice di stringhe di dimensioni n×m, due stringhe x 
e y e due short k e w; il metodo restituisca la 
percentuale di colonne della matrice che contengono 
almeno k stringhe contenenti almeno w caratteri 
presenti sia in x che in y. NB: si assuma, per 
semplicità, che ognuna delle stringhe della matrice non 
che le stringhe x e y non contengano lo stesso 
carattere più di una volta
*/

#include <iostream>
#include <string>
#define n 3
#define m 3

using namespace std;

int fun(string **a, string x, string y, short k, short w){
	string str;
	int count1, count2, count_stringhe, count_colonne;
	double percentuale;
	
	for(int j=0; j<m; j++){
		count_stringhe=0;
		for(int i=0; i<n; i++){
			count1=0;
			count2=0;
			for(int c=0; c<a[i][j].length(); c++){
				char q=a[i][j][c];
				for(int u=0; u<x.length(); u++){
					if(q=x[u]){
						count1++;
					}
				}
				for(int e=0; e<y.length(); e++){
				if(q=y[e]){
					count2++;
				}
			}
		}
		if(count1 >=w && count2 >= w){
			count_stringhe++;
		}
	}
		if(count_stringhe >= k){
			count_colonne++;
		}
	}

	percentuale=(count_colonne/(double)m)*100;
	return percentuale;

}

int main(){
	string **Q = new string *[n];
	
	for(int i=0; i<n; i++){
		Q[i] = new string [m];
		for(int j=0; j<n; j++){
			Q[i][j]="ciao";
		}
	}
	
	cout<<fun(Q,"a","o",1,3);
}
