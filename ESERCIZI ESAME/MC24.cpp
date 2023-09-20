/*
24.Scrivere un metodo che prenda in input una 
matrice di stringhe S di dimensioni n m, uno short k, 
ed una stringa w. Il metodo restituisca il valore 
booleano true se esiste almeno una riga in P tale che 
la stringa w sia sottostringa di un numero di stringhe 
della riga stessa che sia minore o uguale a k. 
*/

#include <iostream>
#include <string>
using namespace std;
#define n 3
#define m 4

bool fun(string **s, short k, string w){
	int count;
	bool valore;
	
	for(int i=0; i<n; i++){
		count=0;
		for(int j=0; j<m; j++){
			if(s[i][j].find(w)!=string::npos){
				count++;
			}
		}
		if(count<=k){
			valore=true;
			break;
		}else{
			valore=false;
			continue;
		}
	}
	return valore;
}
int main(){
	string **a=new string *[n];
	
	for(int i=0; i<n; i++){
		a[i]=new string [m];
		for(int j=0; j<m; j++){
			a[i][j]="allll";
		}
	}
	
	cout<<fun(a,10,"a");
}
