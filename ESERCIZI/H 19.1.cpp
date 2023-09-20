/*Definire una funzione che prende in input due argomenti double e
restituisce il valore somma degli argomenti arrotondato all’intero
piu’ vicino.*/

#include <iostream>

using namespace std;

int somma(double a,double b){
	int a1=a+0.5;
	int b1=b+0.5;
	return a1+b1;
}

int main(){
	int sum= somma(4.8,5.4);
	cout<<sum;
}