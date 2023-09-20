/*
32.Scrivere un metodo che prenda in input una 
matrice quadrata di puntatori a stringhe e due caratteri 
c1 e c2. Calcolare O1 come numero di occorrenze del 
carattere c1 che figurano nella diagonale principale. 
CalcolareO2 come numero di occorrenze del carattere 
c2 che che figurano nella secondaria. Restituire il 
rapportoO1/O2. NB: si faccia attenzione alle stringhe 
mancante
*/

#include <string>
#include <iostream>
using namespace std;
#define n 3

double fun(string ***a, char c1, char c2){
	int o1, o2, j;

	for(int i=0, j=n-1; i<n; i++, j--){
		if(a[i][j] != nullptr){
			for(int c=0; c<(*a[i][j]).length(); c++){
				char p=(*a[i][j])[c];
				if(p==c1){
					o1++;
				}
			}
		}
		if(a[i][i] != nullptr){
			for(int t=0; t<(*a[i][i]).length(); t++){
				char u=(*a[i][i])[t];
				if(u==c1){
					o2++;
				}
			}
		}
	}

	return o1/(double)o2;

}

int main(){
	string ***matrice=new string **[n];
	for(int i=0; i<n; i++){
		matrice[i]=new string *[n];
		for(int j=0; j<n; j++){
			matrice[i][j]=new string("ciao");
		}
	}
	
	cout<<fun(matrice,'c','i')<<endl;

}
