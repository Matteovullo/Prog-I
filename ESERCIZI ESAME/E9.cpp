/*
[Esercizio 9] Scrivere un metodo che prenda in input un parametro formale A matrice di stringhe di dimensione n × m,
ed una stringa s. Il metodo restituisca true se esistono almeno due stringhe in A che contengono la stringa s e che abbiano
differenti indici di riga e di colonna.
*/

#include <iostream>
using namespace std;
#define n 3
#define m 3

bool fun(string **a, string s){
	int count;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(i != j){
				if(a[i][j].find(s) != string::npos){
					count++;
				}
			}
		}
	}
	if(count >= 2) return true;
	else return false;
}

int main(){
	string **p=new string *[n];
	
	for(int i=0; i<n; i++){
		p[i]=new string [n];
		for(int j=0; j<n; j++){
			p[i][j]="ciao";
		}
	}
	
	string o="a";
	cout<<fun(p,o);
}
