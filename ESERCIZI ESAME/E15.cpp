/*
Esercizio 15]
Scrivere un metodo che preveda due parametri formali: una matrice A di stringhe ed una matrice B di short, entrambe di
dimensioni n×m. Il metodo restituisca uno array di n puntatori a stringhe nel quale il generico elemento di indice i sara' uguale
alla concatenazione delle sole stringhe della riga i-esima di A che hanno lunghezza pari o maggiore del corrispondente numero
in B.
*/

#include <iostream>
using namespace std;
#define n 3 
#define m 3

string* * fun(string **a, short **b){
	string* *s=new string *[n];
	for(int i=0; i<n; i++) s[i]=new string [n];
	int l;
	string str;
	
	for(int i=0; i<n; i++){
		str="";
		for(int j=0; j<m; j++){
			l=a[i][j].length();
			if(l >=b[i][j]){
				str+=a[i][j];
			}
		}
		s[i]=new string (str);
	}
	return s;  
}

void stampa(string* *array_stampa)
  {
    for(int i=0; i<n; i++)
      {
        cout<<fixed<<*array_stampa[i]<<endl;
      }
  }

int main(){
	string **d=new string *[n];
	
	for(int i=0; i<n; i++){
		d[i]=new string [m];
		for(int j=0; j<m; j++){
			d[i][j]="a";
		}
	}
	
	short **h=new short *[n];
	
	for(int i=0; i<n; i++){
		h[i]=new short [m];
		for(int j=0; j<m; j++){
			h[i][j]=1;
		}
	}
	
	string* *p=new string *[n];
	for(int i=0; i<n; i++){
		p[i]=new string [n];
	}
	
	p=fun(d,h);
	stampa(p);
}
