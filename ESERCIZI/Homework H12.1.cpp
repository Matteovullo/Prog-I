/*
Codificare un programma in linguaggio C++ nel quale si 
chiedano all’utente due numeri in virgola mobile (a e b) da tastiera. 
Il programma deve calcolare e stampare la somma, la media,
ed il max tra i due numeri. Tutti gli output del programma dovranno essere in notazione
scientifica, con una precisione di 4 cifre dopo la virgola.
*/

#include <iostream>
#include <iomanip>
#include <cmath> 

using namespace std;
int main(){
	float a,b,media,somma,max;
	
	cout << "inserire un numero con la virgola: "; cin >> a;
	
	cout << "inserire un numero con la virgola: "; cin >> b;
	
	somma=a+b;
	
	cout << "La somma tra i due numeri e': " << scientific << fixed << setprecision(4) << somma << endl;
	
	media=a/b;
	media=media/2;
	
	cout << "La media tra i due numeri e': " << scientific << fixed << setprecision(4) << somma << endl;
	
	if (a>b) {
		max=a; 
		cout << "il massimo tra i due valori e':" << scientific << fixed << setprecision(4) << max << endl;
	}
	else{
		max=b;
		cout << "il massimo tra i due vaori e':" << scientific << fixed << setprecision(4) << max << endl;
	} 
return 0;
}