#include <iostream>
using namespace std;

bool vero_o_falso(int n,int m,double w, double v){
	int a[n][m];
	int somma_colonna=0;
	bool valore=false;
	
	for (int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<<"inserire un numero intero: ";cin>>a[i][j];
		}
	}
	
	for(int j=0; j<m; j++){
		for(int i=0; i<n; i++){
			somma_colonna+=a[i][j];
			if(i==n-1){
				if(somma_colonna/n <= v && somma_colonna/n >=w){
					return valore=true;
					break;
				}else{
					continue;
				}
			}
		}
	}
}


int main(){
	cout<< vero_o_falso(2,2,2.5,3.5);
}