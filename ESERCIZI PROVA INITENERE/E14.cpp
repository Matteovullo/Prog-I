/*
[Esercizio 14]
Scrivere un metodo che preveda un parametro formale array monodimensionale S 
di n puntatori a stringhe, ed inoltre una
matrice C di caratteri distinti ed uno short k, e restituisca un array di n 
puntatori a stringhe in cui il generico elemento di
indice i contiene un puntatore alla i-esima stringa in S solo se questa contiene 
almeno k caratteri in C, altrimenti nullptr.
*/

#include <iostream>
using namespace std;
#define n 3
#define m 3

string** fun(string* *s, char** c, short k){
	string** arr=new string *[n];

	for(int i=0; i<n; i++){
		string aux=*s[i];
		int count=0;
		for(int w=0; w<(*s[i]).length(); w++){
			char l=aux[w];
			for(int o=0; o<n; o++){
				for(int p=0; p<m; p++){
					if(l==c[o][p]){
						count++;
					}
				}
			}
		}
		if(count >= k) arr[i]=new string (*s[i])
		else arr[i]=nullptr;
	}
	return arr;
}

void stampa(string* *array_stampa){
    for(int i=0; i<n; i++){
        cout<<fixed<<*array_stampa[i]<<endl;
      }
}

int main(){
	string* *d=new string *[n];
	
	for(int i=0; i<n; i++){
		d[i]=new string("ciao");
	}
	
	char **h=new char *[n];
	for(int i=0; i<n; i++){
		h[i]=new char [n];
		for(int j=0; j<m; j++){
			h[i][j]='a';
		}
	}
	
	string* *f=new string *[n];
	for(int i=0; i<n; i++){
		f[i]=new string;
	}
	f=fun(d,h,2);
	stampa(f);
}

int ***a=new int **[n];
for(int i=0; i<n; i++) a[i]=new int *[n];
for(int j=0; j<m; j++) a[i][j]=new int(*b[i][j]);