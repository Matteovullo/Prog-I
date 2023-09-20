/*30.Scrivere un metodo che prenda in input una 
matrice di stringhe A e due numeri short senza segno, 
k ed s, e restituisca il valore booleano true se esiste 
almeno una riga di A contenente almeno k stringhe 
ognuna contenente un numero di lettere maiuscole 
minore di s.*/

#include <iostream>
#include <string>
#include <cctype>
#define n 2
#define m 2
using namespace std;

bool fun(string *a[n][m], unsigned short k,unsigned  short s){
	int count1;
	int count2;
	bool valore=false;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			string aux=*a[i][j];
			for(int h=0; h<(*a[i][j]).length(); h++){
				char c=aux[c];	
				if(isupper(c)){
					count1++;
					}
				}
				if(count1<s){
					count2++;
				}
			}
		if(count2>=k){
			valore=true;
			break;
		}else{
			continue;
		}
	}
		return valore;
	}
	
int main(){
	/*string **a=new string *[n];
	
	for(int i=0; i<n; i++){
		a[i]=new string [n];
	}
	
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			a[i][j]="Ciao";
		}
	}*/
	
	string* matrice[n][m];
	
	matrice[0][0] = new string("A");
	matrice[0][1] = new string("A");
	matrice[1][0] = new string("A");
	matrice[1][1] = new string("A");
	
	cout<<fun(matrice,2,1);
}