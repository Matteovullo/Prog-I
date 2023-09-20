/*26.Scrivere un metodo che prenda in input una 
matrice quadrata Q di dimensioni n x n di puntatori a 
stringhe e due short m e k e restituisca il valore 
booleano true se la diagonale secondaria di Q contiene 
almeno m stringhe con un numero di vocali minore o 
uguale a k. NB: Si assuma m<=n.*/

#include <string>
#include <iostream>
using namespace std;
#define n 2

bool fun(string *q[n][n], short m, short k){
	int count_vocali;
	int j;
	bool valore;
	int count_stringhe;
		
	for(int i=0, j=n-1; i<n; i++, j--){
		count_vocali=0;
		for(int c=0; c<(*q[i][j]).length(); c++){
			char l=(*q[i][j])[k];
			if(l=='a' || l=='e' || l=='i' || l=='o' || l=='u' || l=='A' || l=='E' || l=='I' || l=='O' || l=='U'){
				count_vocali++;
			}
		}
		if(count_vocali<=k){
			count_stringhe++;
		}
	}
	if(count_stringhe>=m){
		valore=true;
	}else{
		valore=false;
	}
	return valore;
}

int main(){
	/*int n=3;
	string* **a=new string **[n];
	
	for(int i=0; i<n; i++){
		a[i]=new string *[n];
	}
	
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			*a[i][j]="i";
		}
	}*/
	
	string* matrice[n][n];
	
	matrice[0][0] = new string("a");
	matrice[0][1] = new string("aaaaa");
	matrice[0][2] = new string("a");
	matrice[1][0] = new string("aaaaa");
	
	cout<<fun(matrice,2,1);
}

