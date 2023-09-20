/*
Si implementino delle classi:
Giorno: rappresenta un giorno del mese espresso sia come numero che come giorno della settimana;
Mese: rappresenta un mese;
Anno: rappresenta un anno;
Le classi sopra definite dovranno avere gli opportuni costruttori e dovranno assicurarsi di ricevere input corretti 
(ad esempio Giorno dovrà rappresentare giorni compresi tra 1 e 31);
Definire dunque una classe Data che abbia come variabili membro tre oggetti di tipo Giorno, Mese e Anno. 
La classe dovrà avere un costruttore opportuno che controlli che la data inserita sia valida, un metodo stampa che mostri 
la data nel formato “Mercoledì 22 dicembre 2021”, e un metodo differenza che prenda in input un altro oggetto di tipo Data e
 calcoli il numero di giorni che intercorrono tra le due date.
Nota: un anno è bisestile se è divisibile per 4 ma non per 100.
*/

#include<cstdlib>
#include<iostream>
#include<string>
using namespace std;


class Giorno{
	private:
		int g;
		string gi;
	public:
		Giorno(int x,string s){
			if(x<0 || x>31){
				cerr<<"giorno non valido!";
			}
			g=x;
			gi=s;
		}
		string getGiornoDellaSettimana(){return gi;}
		int getGiorno(){return g;}
};

class Mese{
	private:
		int m;
		string me;
	public:
		Mese(int x, string l){
			if(x<0 || x>12){
				cerr<<"mese non valido!";
			}
			x=m;
			me=l;
		}
		string getMese(){return me;}
};

class Anno{
	private:
		int a;
	public:
		Anno(int x){
			x=a;
		}
		int getAnno(){return a;}
};
