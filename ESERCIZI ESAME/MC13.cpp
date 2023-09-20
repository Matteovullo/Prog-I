/*
13.Scrivere un metodo che prenda come parametri 
formali una matrice quadrata A n×n di puntatori a char 
e restituisca in output un bool che indichi se esiste una 
colonna in A identica alla diagonale principale di A. 
*/

#include<iostream>
using namespace std;
#define n 2

bool fun(char* a[n][n]){
	char *b=new char [n];
	bool valore;
	int j,count;
	
	for(int j=0; j<n; j++){
		for(int i=0; i<n; i++){
			if(i==j){
				b[i]=*a[i][j];
			}
			}
		}
	
	for(int j=0; j<n; j++){
		for(int i=0; i<n; i++){
			if((*a[i][j])==b[i]){
				count++;
			}
		}
		if(count==n){
			valore=true;
			break;
		}else{
			valore=false;
			continue;
		}
	}
	return valore;
}

int main(){
	char* matrice[n][n];
	matrice[0][0] = new char('a');
	matrice[0][1] = new char('a');
	matrice[1][0] = new char('a');
	matrice[1][1] = new char('a');
	
	cout<<fun(matrice);
}
