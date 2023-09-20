#include <iostream>

using namespace std;
int main(){
	/*Si scriva un programma che:
Dichiara le variabili intere a, b, c;

Le inizializza rispettivamente con i valori 12, 18, 21;

Stampa a schermo la somma delle tre variabili;

Stampa a schermo il prodotto delle tre variabili;

Stampa il risultato di (a+b)/c;*/

/*int a=12,b=18,c=21;
cout<<a+b+c<<endl;
cout<<a*b*c<<endl;
cout<<(a+b)/c<<endl;*/

/*Si scriva un programma che:

Dichiara la variabile intera x e la pone pari a 2;

Dichiara la variabile intera y e la pone pari a 7;

Dichiara la variabile float z e le assegna il risultato in virgola mobile dell’espressione y/x;

Dichiara una variabile intera h e le assegna il valore arrotondato di z.*/

/*int x=2,y=7;
float z=float (y/x);
int h=z+0.5;
cout<<z<<endl<<h;*/


/*Si scriva un programma che:
Dichiara la variabile double x e le assegna il valore 3.2;

Divide il valore di x per due utilizzando un operatore di assegnamento composto;

Incrementa x di una unità utilizzando un operatore di incremento;

Dichiara una variabile booleana b e le assegna il valore di verità dell’espressione x>1;*/

double x=3.2;
x/=2;
x++;
bool b=x>1? true:false ;
cout<<b;


}