#include <iostream>

using namespace std;

int main(){
	/*Scrivi un programma che dato il prezzo netto di un prodotto (inserito in ingresso da tastiera) 
	lo sconti del 35% se tale prezzo è maggiore di 100€ e poi aggiunga l'IVA del 20% stampando a video il risultato finale.*/
	
	int prezzo,sconto,IVA;
	
	cout<<"prezzo: "; cin>>prezzo;
	
	if(prezzo>100)
 	{
		sconto=(prezzo*35)/100;
		prezzo=prezzo-sconto;
		IVA=(prezzo*20)/100;
		prezzo=prezzo+IVA;
		cout<<"prezzo finale: "<<prezzo<<endl;
 	}
 	else
	{
 	IVA=(prezzo*20)/100;
 	prezzo=prezzo+IVA;
 	cout<<"prezzo finale: "<<prezzo<<endl;
  	}
	
}