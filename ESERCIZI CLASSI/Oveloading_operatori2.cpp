/*Si recuperi la classe Complesso implementata in un precedente esercizio e 
si sovraccarichino gli operatori:

+;

-;

*;

<<;

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
		friend Complesso operator+(Complesso a, Compesso b);
		friend Complesso operator-(Complesso a, Compesso b);
		friend Complesso operator*(Complesso a, Compesso b);
		friend ostream& operator<<(ostream &o, Complesso);
};

Complesso operator-(Complesso a, Compesso b){
	return Compesso(a.getParteReale-b.getParteReale, a.getParteImmaginaria-b.getParteImmaginaria);
}

Complesso operator*(Complesso a, Compesso b){
	return Compesso(a.getParteReale*b.getParteReale, a.getParteImmaginaria*b.getParteImmaginaria);
}

Complesso operator+(Complesso a, Compesso b){
	return Compesso(a.getParteReale+b.getParteReale, a.getParteImmaginaria+b.getParteImmaginaria);
}

ostream& operator<<(ostream &o, Complesso c){
	o<<"Parte reale: "<<c.getParteReale<<"Parte immaginaria: "<<c.getParteImmaginaria;
	return o;
}

