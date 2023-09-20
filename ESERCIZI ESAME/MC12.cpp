/*
12.Scrivere un metodo che prenda come parametri 
formali una matrice A di stringhe ed uno short w, e 
restituisca in output un bool che indichi se esiste una 
riga di A in cui siano presenti almeno due stringhe 
consecutive in cui i primi w caratteri della prima 
stringa siano uguali agli ultimi w caratteri della 
seconda stringa (nello stesso ordine).
*/

#include <iostream>
#define n 3
#define m 3
using namespace std;

bool fun(string **a, short w){
	bool valore;
	string s1;
	string s2;
	for(int i=0; i<n; i++){
		for(int j=0; j<m-1; j++){
			if(a[i][j].substr(0,w) == a[i][j+1].substr(a[i][j+1].length()-w,w)){
				valore=true;
				break;                                                           
			}else{
				valore=false;
				continue;
			}
		}
		if(valore){
			break;
		}
	}
	return valore;
}

int main(){
	string** b=new string *[n];
	
	for(int i=0; i<n; i++){
		b[i]=new string [n]; 
		for(int j=0; j<n; j++){
			b[i][j]="iiiii";
		}
	}
	
	cout<<fun(b,2);
}
