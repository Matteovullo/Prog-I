#include <iostream>
#include <cmath>
using namespace std;

int main(){
	/*Si scriva un programma che dichiari un array monodimensionale di float e lo inizializzi con degli zero.
	 Il programma dovrà poi inserire all’interno di ciascuna posizione di indice i il numero 2i3.*/
	
	
	float x[5]={};
	
	float p=0;
	
	for(int i=0; i<5; i++){
		p= pow(2,i);
		x[i]= p/3;
		cout << "[" << x[i] << "]";
		cout << "\n";
	}
	
}