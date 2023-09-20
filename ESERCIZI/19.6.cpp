/*Definire una funzione che prende in input un array
monodimensionale di caratteri e restituisce l’indice dell’ultima
consonante che si trova nello array in input.*/

#include <iostream>

using namespace std;

int func(char *a,int n){
	int count=0;
		if(strstr(a[i],'a') || a[i]!='e' || a[i]!='i' || a[i]!='o' || a[i]!='u'){
			count=i;     
		}
	}
	return count;
}

int main(){
	int n=5;
	char *a=new char[n]{'ar','r',0};
	cout<<func(a,5);             
}          