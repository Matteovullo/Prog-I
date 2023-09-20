/*Definire una funzione template che permetta di scambiare i valori di due variabili di qualunque tipo.*/

#include <iostream>
using namespace std;

template <typename T>
void change(T x, T y)
{
    T aux = x;
    x = y;
    y = aux;
}

int main()
{
    int x = 3;
    int y = 5;
    change<int>(x, y);
    cout <<x<<endl<<y;
}
