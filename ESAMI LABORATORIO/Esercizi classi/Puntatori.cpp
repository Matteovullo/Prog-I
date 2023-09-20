/*Si scriva un programma che:

Inizializza un array arr di 5 int: 1, 2, 3, 4, 5;

Dichiara un puntatore a interi ptr;

Assegna a ptr l’indirizzo del numero 3;

Sostituisce il numero 3 con -1 dereferenziando il puntatore ptr.

Stampa tutti i valori dell’array utilizzando il puntatore ptr e l’aritmetica dei puntatori.*/

/*Si scriva un programma che:
Dichiara le variabili int x e y;
Inizializza x con il valore 12;
Inizializza y con il valore 21;
Dichiara il puntatore costante a int ptr e lo inizializza con l’indirizzo di x;
Somma a y il valore di x dereferenziando il puntatore ptr.*/

#include <iostream>
using namespace std;

int main(){
    int array[5]={1, 2, 3, 4, 5};
    int *ptr;
    ptr=&array[2];
    *ptr=-1;
    for(int i=0; i<5; i++){
        cout << *array+i << endl;
    }

    int x=12,y=21;
    const int *ptr1=&x;
    y+=*ptr1;
    cout << y << endl;

    /*Si scriva un programma che:

Inizializza le variabili float x e y;

Stampa a schermo la differenza tra gli indirizzi di x e y usando l’operatore di referenziazione &.*/

    float x1, x2;
    cout << &x1-&x2 << endl;

    /*Si dichiari un array `array` di double contenente i seguenti 5 elementi: [2.0, 4.2, 9.6, 9.2, 0.1].
    Facendo uso della aritmetica dei puntatori:
    Si cambi il valore del terzo elemento in 9.9;
    Si sostituisca il valore del primo elemento nella somma dei valori dell’ultimo e del quarto elemento;
    Si mostrino a schermo tutti i valori dell’array in sequenza inversa.*/

    double array1[5]={2.0, 4.2, 9.6, 9.2, 0.1};
    *(array1+2)=9.9;
    *(array1)=*(array1+4)+*(array1+5);
    for(int i=4; i>=0; i--){
        cout << *(array1+i) << endl;
    }
}