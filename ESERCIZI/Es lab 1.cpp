/*Scrivere una funzione che prenda in input una matrice quadrata A di short,
 e restituisca un bool che indichi se la diagonale principale è identica (procedendo dall’alto verso il basso) alla secondaria.*/

#include <iostream>
#define n 3
using namespace std;

bool func(short **a){
	bool valore;
	int count=0;
	for(int i=0; i<n; i++){
		if(a[i][i]==a[i][n-i-1]){
			count++;
		}
		if(count==3){
			valore=true;
		}else{
			valore=false;
		}
	}
	return valore;
}

int main(){
	short **a=new short*[n];
	cout<< func(a);
}