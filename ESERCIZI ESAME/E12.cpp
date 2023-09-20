/*
[Esercizio 12] Scrivere un metodo che preveda un parametro formale matrice quadrata di stringhe di dimensioni 
n × n,
uno short k ed una stringa s, e restituisca un array di n puntatori a stringhe in cui il generico elemento 
di indice i contiene la
i-esima stringa della diagonale secondaria se questa ha lunghezza maggiore o uguale a k e inizia con la 
stringa s, altrimenti la
corrispondente stringa della diagonale principale.
*/

#include <iostream>
using namespace std;
#define n 3

string** fun(string **a, short k, string s){
	string **t=new string *[n];
	for(int i=0; i<n; i++) t[i]=new string();
	char arr[s.length()];
	int count;

	for(int i=0, j=n-1; i<n; i++,j--){
		count=0;	
		if(a[i][j].length() >= k){
			int p=0;
			for(int l=0; l<s.length(); l++){
				arr[l]=a[i][j][p];
				p++;
			}
			for(int y=0; y<s.length(); y++){
				if(arr[y]==s[y]){
					count++;
				}
			}
			if(count==s.length()){
				t[i]=new string (*a[i][j]);
			}else{
				t[i]=new string (*a[i][i]);
		}
		}else{
			t[i]=new string (*a[i][i]);
		}
	}
	return t;

}


void stampa(string **arr){
	for(int i=0; i<n; i++){
		cout<<"["<<i<<"]"<<" = "<<*arr[i]<<endl;
	}
}

int main(){

	string f="c";
	string **p=new string *[n];
	
	for(int i=0; i<n; i++){
		p[i]=new string [n];
		for(int j=0; j<n; j++){
			if(i==j){
				p[i][j]="sfge";
			}else{
				p[i][j]="ciao";
			}
		}
	}
	
	string **o=new string *[n];
	for(int i=0; i<n; i++){
		o[i]=new string [n];
	}
	
	o=fun(p,2,f);
	stampa(o);

}


