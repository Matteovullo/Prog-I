/*
Si definisca una classe Automobile con una variabile di stato stringa modello e una variabile intera 
progressivo.
Si definisca una classe Registro che contenga una variabile statica count e un array statico di 100 puntatori 
a oggetti di tipo Automobile. 
L’oggetto registro deve avere un metodo statico registra che prende in input un puntatore a Automobile e 
aggiunge il puntatore al 
primo elemento vuto (nullptr) dell’array statitico registro. Il metodo restituisce un intero 
progressivo ad ogni chiamata. 
Inserire anche un metodo count che restituisce il numero di puntatori non nulli in registro.
Il costruttore di Automobile prende in input una stringa _modello usata per inizializzare modello. 
Il costruttore chiama Registro::registra per “registrare” il nuovo veicono e salva il numero 
progressivo in progressivo.
Automobile deve anche includere un costruttore di copia che si assicuri che alla copia il 
nuovo veicolo copiato venga correttamente 
registrato.
Scrivere un programma che istanzi diversi oggetti Automobile e effettui delle copie. 
Si stampi dunque il numero di veicoli registrati.
*/

#include <iostream>
using namespace std;
#define n 10

class Automobile{
	string modello;
	int progressivo;
	public:
		Automobile(string modello){
			this->modello=modello;
			Registro::registra();
			count=progressivo;
		}
};

class Registro{
	static int count;
	Automobile *arr[n];
	public:
		Registro()
		static int registra(Automonile *a){
			int count
			for(int i=0; i<n; i++){
				if(arr[i]==nullptr){
					arr[i]=a;
				}
			}
			count++;
			return count;
		}
		int count(){
			int counter;
			if(arr[i] != nullptr){
				count++;
			}
			return counter;
		}
}
int Registro::counter=0;

int main(){
	return 0;
}
