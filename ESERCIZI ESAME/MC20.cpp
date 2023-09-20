/*
20.Scrivere un metodo che prenda in input una 
matrice di puntatori a stringhe S di dimensione nm, 
una stringa s1 ed uno short k, e restituisca la 
percentuale di stringhe, tra quelle presenti nelle prime 
k colonne di S, che siano piu lunghe di s1. NB: si 
assuma k<=m.
*/
 
#include <iostream>
#include <string>
#define n 2
#define m 2
using namespace std;

double fun(string* s[n][m], string s1, short k){
	const double p=100.0;
	double percentuale;
	int count;
	int num_stringhe=n*k;
	string str;
	
	for(int j=0; j<k; j++){
		for(int i=0; i<n; i++){
			if(s[i][j]){
			str=*s[i][j];
			if(str.length() > s1.length()){
				count++;
			}
		}
		}
	}
	percentuale=(count/(double)num_stringhe)*p;
	return percentuale;
}

int main(){
	string* matrice[n][m];
	
	matrice[0][0] = new string("Addd");
	matrice[0][1] = new string("aaaa");
	matrice[1][0] = new string("Addd");
	matrice[1][1] = new string("Addd");
	
	cout<<fun(matrice,"a",2);
}
