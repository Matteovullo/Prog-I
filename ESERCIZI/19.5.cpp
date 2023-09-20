/*Definire una funzione che prende in input un array
monodimensionale di caratteri e restituisce il numero di vocali
presenti nello array*/

#include <iostream>

using namespace std;

int func(char *a,int n){
	int count=0;
	for(int i=0; i<n; i++){
		if(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u'){
			count ++;
		}
	}
	return count;
}

int main(){
	int n=5;
	char *a=new char[n]{'a','e'};
	
	cout<<func(a,5);
}
