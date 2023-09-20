/*
[Esercizio 3] Scrivere un metodo che prenda in input tre parametri formali: una matrice di stringhe S di dimensioni n×m,
un array di caratteri C che contiene elementi distinti, ed un float w. Il metodo restituisca true se esiste almeno una riga o una
colonna della matrice tale che la percentuale di caratteri di C presenti in essa `e maggiore di w.
*/

#include <iostream>
using namespace std;
#define n 3
#define m 3

bool fun(string **s, char *c, float w){
	int count1, count2,countc1, countc2;
	double percentuale;
	string aux1, aux2;
	
	for(int i=0; i<n; i++){
		count1=0;
		countc1=0;
		for(int j=0; j<m; j++){
			aux1=s[i][j];
			for(int u=0; u<(s[i][j]).length(); u++){
				for(int h=0; h<n; h++){
					countc1+=s[i][j].length();
					if(aux1[u]==c[h]){
						count1++;
					}
				}
			}
		}
		percentuale= (count1/ (double)countc1)*100;
		if(percentuale>=w) return true;
	}
	
	for(int j=0; j<m; j++){
		count2=0;
		countc2=0;
		for(int i=0; i<n; i++){
			aux2=s[i][j];
			for(int u=0; u<(s[i][j]).length(); u++){
				for(int h=0; h<n; h++){
					countc2+=s[i][j].length();
					if(aux2[u]==c[h]){
						count2++;
					}
				}
			}
		}
		percentuale= (count2/ (double)countc2)*100;
		if(percentuale>w) return true;
		else return false;
	}
}

int main(){
	string **d=new string *[n];
	
	for(int i=0; i<n; i++){
		d[i]=new string [m];
		for(int j=0; j<m; j++){
			d[i][j]="ciao";
		}
	}
	
	char *h=new char [n];
	
	h[0]='a';
	h[1]='c';
	h[2]='g';
	
	cout<<fun(d,h,50);
}
