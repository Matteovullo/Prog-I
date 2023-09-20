#include <iostream>
#include <string>
using namespace std;
int main (){
	/*
Si scriva un programma che:
Dichiara due variabili di tipo stringa nome e cognome;

Assegna a nome il proprio nome e a cognome il proprio cognome;

Dichiara una variabile di tipo stringa nome_completo e assegna ad essa la stringa “Il mio nome è nome cognome”, 
dove nome e cognome rappresentano il proprio nome e cognome;

Stampa a schermo il valore dell’ultima stringa definita.*/

string nome="matteo";
string cognome="vullo";
string s=" ";
string nome_completo=nome+" "+cognome;

cout<<nome_completo;

}