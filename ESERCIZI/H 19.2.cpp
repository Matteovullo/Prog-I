/*Definire una funzione che prende in input due interi senza segno e
restituisce il rapporto (numero in virgola mobile) tra i due
argomenti. Se il divisore e’ zero, la funzione restituisce il valore -1.*/

#include <iostream>

using namespace std;

float rapporto(unsigned int a, unsigned int b){
	if(b==0){
		return -1;
	}else{
		float media=a/b;
		return media;
	}
}

int main(){
	cout<<rapporto (20.0,4.5);
}