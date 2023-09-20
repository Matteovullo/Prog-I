/*
[Esercizio 17] Scrivere un metodo che prenda un parametro formale matrice di stringhe S di dimensione n × m 
e due array di caratteri C
e D di egual dimensione n e restituisca un array di short nel quale il generico elemento di posto i contiene 
il numero di stringhe
che iniziano con il carattere di C avente indice i e finiscono con il carattere in D avente indice i.
*/

#include <string>
#include <iostream>
using namespace std;

#define n 3
#define m 3

short* fun(string **s, char *c, char *d){
	short *a=new short [n];
	int count=0;
	char c1;
	char c2;
	string aux;
	
	for(int i=0; i<n; i++){
		count=0;
		for(int j=0; j<m; j++){
			aux=s[i][j];
			if(aux[0]==c[i] && aux[aux.length()-1]==d[i]){
				count++;
			}	
		}
		a[i]=count;
	}
	return a;
}

void stampa(short *array_stampa){
    for(int i=0; i<n; i++){
        cout<<fixed<<array_stampa[i]<<endl;
      }
}

int main(){
	string** p=new string *[n];
	
	for(int i=0; i<n; i++){
		p[i]=new string [n];
		for(int j=0; j<m; j++){
			p[i][j]="ciao";
		}
	}
	
	char* o=new char [n];
	
	for(int i=0; i<n; i++){
		o[i]='p';
	}
	
	char* k=new char [n];
	
	for(int i=0; i<n; i++){
		k[i]='l';
	}
	
	short* array_1=new short [n];
    array_1=fun(p,o,k);
    stampa(array_1);

}
