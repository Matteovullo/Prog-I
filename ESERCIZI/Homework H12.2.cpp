/*
Codificare un programma in linguaggio C++ che chieda
all’utente di inserire TRE numeri da tastiera. L’utente può
inserire numeri interi o decimali.
Il programma dovrà calcolare e stampare l’arrotondamento al
valore intero più vicino di ogni numero inserito dallo utente.
*/

#include <iostream>
using namespace std;
int main (){
	float a,b,c;
	cout <<"inserire un numero decimale o con la virgola:"; cin>> a;
	cout <<"inserire un numero decimale o con la virgola:"; cin>> b;
	cout <<"inserire un numero decimale o con la virgola:"; cin>> c;
	
	int ia=a+0.5;
	int ib=b+0.5;
	int ic=c+0.5;
	
	cout << "Il numero intero piu'' vicino al primo numero inserito e': " << ia << endl;
			cout << "Il numero intero piu' vicino al secondo numero inserito e': " << ib << endl;
			cout << "Il numero intero piu' vicino al terzo numero inserito e': " << ic;
		
	return 0;
}