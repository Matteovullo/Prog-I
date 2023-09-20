/*
Creare una classe Complesso per la gestione dei numeri complessi
(un numero complesso è costituito da due numeri reali double: parte reale e parte immaginaria),
Le operazioni da implementare sono le seguenti:
un costruttore che prenda in input due doble e inizializzi lo stato dell’oggetto;
un metodo stampa che permette di stampare il numero complesso;
dei metodi somma, divisione, prodotto e sottrazione che prendano in input un numero complesso e
 permettano di effettuare le operazioni aritmetiche tra l’oggetto di cui sono funzioni membro e quello ricevuto in input.
*/

#include<iostream>
using namespace std;

class Complesso{
	private:
		double a,b;
	public:
		Complesso(double x,double y) : a(x), b(y) {};
		void stampa(){
			cout<<a<<"+"<<b;
		}
		double getParteReale(){return a;}
		double getParteImmaginaria(){return b;}
		void somma(Complesso s){
			a+=s.getParteReale();
			b+=s.getParteImmaginaria();
		}
		void divisione(Complesso s){
			a/=s.getParteReale();
			b/=s.getParteImmaginaria();
		}
		void prodotto(Complesso s){
			a*=s.getParteReale();
			b*=s.getParteImmaginaria();
		}
		void sottrazione(Complesso s){
			a-=s.getParteReale();
			b-=s.getParteImmaginaria();
		}
};

int main(){
	Complesso s(2.0,5.5);
	Complesso d(2.0,5.5);
	s.divisione(d);
	s.stampa();
	return 0;
}
