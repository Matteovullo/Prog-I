#include <iostream>

using namespace std;
int main(){
	/*Scrivere un programma che prenda i seguenti input da tastiera:

l’importo di un ordine,

un ulteriore dato in input che indica se uno o piu’ articoli hanno un prezzo promozionale,

un dato finale in input che indica se l’ordinante ha una tessera cliente.

Il programma dovra stampare l’importo totale dell’ordine aggiornato in base alle seguenti specifiche:

Se l'importo dell'ordine e' minore o uguale a 100 euro, applica uno sconto del 10%.
Se l'importo dell'ordine e' maggiore di 100 euro e comunque minore o uguale di 1000 euro, allora:
se l'utente possiede la tessera applica uno sconto del 20%
nel caso in cui l'utente non possiede la tessera:
se ad uno o piu' articoli e' stato applicato un prezzo promozionale, applica uno sconto del 15 %;
altrimenti applica uno sconto del 18%;
Se l'importo dell'ordine e' maggiore di 1000 euro, applica uno sconto del 30% alla differenza tra l'importo totale dell'ordine e 1000 euro. 
Applica la scontistica prevista al punto b sui rimanenti 1000 euro.
Si utilizzi il costrutto switch ove possibile.*/

int ordine;
bool tessera,promozione;

cout<<"totale ordine: ";cin>>ordine;
cout<<"hai la tessera? (1=si 0=no)";cin>>tessera;
cout<<"E' un articolo in promozione? (1=si 0=no)";cin>>promozione;

if(ordine<=100){
	ordine*=0.1;
	cout<<ordine;
}

if (ordine>100 && ordine<=1000){
	if(tessera==1){
		ordine*=0.2;
		cout<<ordine;
	}if(promozione==1)
		ordine*=0.15;
		cout<<ordine;
	}else{
		ordine*=0.18;
		cout<<ordine;
	}
	
if(ordine>1000){
	ordine=(ordine-1000)*0.3;
	cout<<ordine;
}
}


