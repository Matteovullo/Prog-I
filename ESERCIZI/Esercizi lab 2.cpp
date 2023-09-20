/*Scrivere un metodo che prenda come parametro formale una matrice S di dimensione n×m di stringhe ed una stringa X,
 e modifichi con un ‘*’ ogni carattere delle stringhe in S contenenti la sottostringa X. N.B.: Non è possibile usare substr.*/

#include <iostream>
#define n 2
#define m 3
using namespace std;

void func(string* **a,string x){
	
	for(int i=0; i<n; i++){
		for(int j=0; i<m; j++){
			if(a[i][j].find(x)){
				a[i][j]='*';
			}
		}
	}
	
}

int main(){
	string **a=new string *[n][m];
	
	for(int i=0; i<n; i++){
		a[i]=new string *[n][m];
		for(int j=0; j<m; j++){
			a[i][j]=new string [n][m];
		}
	}
	
}