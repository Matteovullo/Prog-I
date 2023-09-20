#include <iostream>
using namespace std;

int main(){
	/*Si scriva un programma che:

Inizializza un array arr di 5 int: 1, 2, 3, 4, 5;

Dichiara un puntatore a interi ptr;

Assegna a ptr l’indirizzo del numero 3;

Sostituisce il numero 3 con -1 dereferenziando il puntatore ptr.

Stampa tutti i valori dell’array utilizzando il puntatore ptr e l’aritmetica dei puntatori.*/

int x[5]={1,2,3,4,5};

int *ptr=&x[2];

*ptr= -1;

for(int i=-2; i<3; i++) {
cout<<"array ["<<i+2<<"]"<<*(ptr+i)<<endl;
}
	



}