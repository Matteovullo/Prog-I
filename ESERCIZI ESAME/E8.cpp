/*
[Esercizio 8] Scrivere un metodo che prenda in input un parametro formale matrice A di interi di dimensioni n × m, uno
short k ed uno short w, e restituisca true se la matrice contiene almeno w colonne che contengono almeno una sequenza di interi
monotona crescente di lunghezza maggiore o uguale a k.
*/

#include <iostream>
using namespace std;
#define n 2
#define m 2

bool fun(int **a, short k,short w){
	int count1, count2;
	
	for(int j=0; j<m; j++){
		count1=0;
		for(int i=0; i<n-1; i++){
			if(a[i][j] < a[i+1][j] && (a[i+1][j]-a[i][j]) == 1){
				count1++;
			}else{
				count1=0;
			}
		}
		if(count1 >= k){
			count2++;
		}
	}
	if(count2 >= w) return true;
	else return false;
}

int main(){
	int **d=new int *[n];
		
	
	for(int i=0; i<n; i++){
		d[i]=new int [m];
	}
	
	d[0][0]=1;
	d[0][1]=1;
	d[1][0]=2;
	d[1][1]=2;
	
	cout<<fun(d,1,1);
}
