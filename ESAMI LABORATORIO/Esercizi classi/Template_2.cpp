/*Definire una funzione template che permetta 
di scambiare i valori di due variabili di qualunque 
tipo.*/

#include <iostream>
using namespace std;

template<typename T>
void scambio(T a, T b){
    T aux=a;
    a=b;
    b=aux;
    cout << a << " " << b;
}

int main(){
    int a=5, b=7;
    scambio<int>(a, b);
}
