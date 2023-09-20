#include <iostream>

using namespace std;

int main(){
	/*Si scriva un programma che:
Dichiara le variabili int x e y;

Inizializza x con il valore 12;

Inizializza y con il valore 21;

Dichiara il puntatore costante a int ptr e lo inizializza con l’indirizzo di x;

Somma a y il valore di x dereferenziando il puntatore ptr.*/

int x=12,y=21;

const int *ptr=&x;

y+=*ptr;

cout<<y;


}