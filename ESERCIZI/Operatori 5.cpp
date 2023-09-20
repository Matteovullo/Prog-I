#include <iostream>
#include <string>

using namespace std;
int main(){
	/*Si scriva un programma che:
Dichiara due variabili di tipo stringa nome e cognome;

Assegna a nome il proprio nome e a cognome il proprio cognome;

Dichiara una variabile booleana z e le assegna true se nome viene prima di cognome quando le stringhe sono ordinate lessicograficamente, 
mentre assegna false altrimenti;

Dichiara una variabile di tipo stringa nome_completo e assegna ad essa la stringa “Il mio nome è nome cognome”, 
dove nome e cognome rappresentano il proprio nome e cognome;
*/

string nome="matteo";
string cognome="vullo";
string space=" ";
string nome_completo=nome+space+cognome;

bool z;
if(nome>cognome){
	z=true;
	cout<<z;
}
else{
	z=false;
	cout<<z;
}

}