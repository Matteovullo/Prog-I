/*Scrivere un programma che calcola la somma di numeri double passati come argomenti da linea di comando.*/

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {

    double somma=0.0;
    for(int i=0; i<argc; i++)
        somma+=(double)(*argv[i]);

    cout << somma << endl;
}