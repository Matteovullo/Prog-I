/*
34.Scrivere un metodo che prenda in input una 
matrice di puntatori a stringhe S di dimensioni n×m, 
una stringa x ed un array di double W di dimensione 
m; il metodo restituisca un array di bool R di 
dimensione m tale che l’i-esimo elemento di R sarà 
true se e solo se il rapporto tra il numero di stringhe 
della i-esima colonna di S delle quali x è sottostringa 
ed il numero n è minore o uguale dello i-esimo 
elemento di W. NB: Si presti attenzione alle stringhe 
mancanti!
*/

#include <string>
#include <iostream>
using namespace std;
#define n 2
#define m 2

bool* fun(string* s[n][m], string x, double* w){
	bool* arr=new bool [n];
	int count;
	
	for(int j=0; j<m; j++){
		count=0;
		for(int i=0; i<n; i++){
			if(s[i][j]){
				if((*s[i][j]).find(x)!=string::npos){
					count++;
				}
			}
		}
		if(count/(double)n <= w[j]){
			arr[j]=true;
		}else{
			arr[j]=false;
		}
	}
	return arr;
}

void stampa(bool *array_stampa){
    for(int i=0; i<m; i++){
        cout<<array_stampa[i]<<endl;
    }
}

int main(){
	string* matrice[n][n];
	
	matrice[0][0] = new string("a");
	matrice[0][1] = new string("a");
	matrice[1][0] = new string("a");
	matrice[1][1] = new string("a");
	
	double* l=new double [m];
	
	for(int i=0; i<m; i++){
		l[i]=0.0;
	}
	
	bool* array_1=new bool [m];
	array_1=fun(matrice,"a",l);
    stampa(array_1);
}
