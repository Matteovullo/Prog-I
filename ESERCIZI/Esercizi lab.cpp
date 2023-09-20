#include <iostream>
using namespace std;

/*Scrivere una funzione che prenda in input una matrice quadrata A di short, e restituisca un bool che indichi 
se la diagonale principale è identica (procedendo dall’alto verso il basso) alla secondaria.*/

bool func(short **a,int n){
	bool diag;
	int count;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(a[i][i]==a[n-i-1][i]){
				count++;
			}
			if (count == n-1){
				diag=true;
				break;
			}else{
				continue;
			}
		}
	}
	return diag;
}

int main(){
	short **a=new short*[2];
	for(int i=0; i<2; i++){
		a[i]=new short[2];
		for(int j=0; j<2; j++){
			a[i][j]	= 1	;
		}
	}
	
	
	if(func(a,2)) {
		cout << "Errore!" << endl;
	} else {
		cout << "Corretto." << endl;
	}

}