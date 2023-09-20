#include <iostream>
#include <fstream>
using namespace std;

int main(){
	/*Si scriva un programma che chieda all’utente di inserire il proprio nome, cognome e codice fiscale e 
salvi i dati <nome>, <cognome> (dove <nome> e <cognome> sono il nome e il cognome dell’utente)
 in un file dal nome <codice_fiscale>.txt (dove <codice_fiscale> è il codice fiscale inserito dall’utente).*/
 
string nome,cognome,codice_fiscale;

cout<<"inserire nome: ";cin>>nome;
cout<<"inserire cognome: ";cin>>cognome;
cout<<"inserire codice_fiscale: ";cin>>codice_fiscale;

ofstream file("codice_fiscale.txt");
file << nome <<endl;;
file << cognome << endl;
file << codice_fiscale <<endl;

file.close();

}