#include <iostream>

using namespace std;
int main(){
	/*Si dichiari un array `array` di double contenente i seguenti 5 elementi: [2.0, 4.2, 9.6, 9.2, 0.1].
Facendo uso della aritmetica dei puntatori:

Si cambi il valore del terzo elemento in 9.9;

Si sostituisca il valore del primo elemento nella somma dei valori dell’ultimo e del quarto elemento;

Si mostrino a schermo tutti i valori dell’array in sequenza inversa.*/

double x[]={2.0,4.2,9.6,9.2,0.1};

double *ptr1=&x[2];
*ptr1=9.9;

double *ptr2=&x;
*ptr2=9.2+0.1;

for(int i=0; i<5; i++){
	cout<<"array ["<<i<<"]"<<*ptr2<<endl;
}

}