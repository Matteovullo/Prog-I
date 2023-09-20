#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	//Scrivere un programma in C++ in cui il programma chiede all’utente di inserire tre
    //numeri in forma decimale con almeno 8 cifre decimali (NB: il programma non deve
    //necessariamente controllare che utente abbia inserito un numero con almeno 8 cifre
    //decimali). Il programma conserva i valori, ne calcola la media e stampa il risultato
    //con un numero di cifre decimali pari a 6.
	float a,b,c,media;
	cout<<"ins a: "; cin>>a;
	cout<<"ins b: "; cin>>b;
	cout<<"ins c: "; cin>>c;
	media=(a+b+c)/2;
	cout<<scientific<<setprecision(6)<<fixed<<media<<endl;
	
}