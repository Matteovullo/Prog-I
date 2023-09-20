#include <iostream>
#include <limits>
using namespace std;
/*Si definisca una funzione che permetta di calcolare l’area di un triangolo. 
Scrivere un programma che usi la funzione definita chiedendo all’utente di inserire base e altezza del triangolo.*/

float area_triangolo(float base,float altezza) {
    return (base*altezza)/2;
}

int main (){
	float base,altezza;
	
	cout << "Introdurre una base: ";
	bool done = false;
	do {
		cin >> base;
		if (cin.fail()) {
			cerr << "Errore! Inserire un numero un virgola mobile: ";                                              
			cin.clear();
			cin.ignore (numeric_limits<streamsize>::max() , '\n') ;
		}
		else			                                            
			done = true;
	} while(!done);
	
cout << "Introdurre un altezza: ";
	bool done_1 = false;
	do {
		cin >> altezza;
		if (cin.fail()) {
			cerr << "Errore! Inserire un numero in virgola mobile: ";                                              
			cin.clear();
			cin.ignore (numeric_limits<streamsize>::max() , '\n') ;
		}
		else			                                            
			done = true;
	} while(!done_1);
	
	cout<< area_triangolo;
}