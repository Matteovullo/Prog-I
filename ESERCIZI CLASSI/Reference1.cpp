/*
Si definisca una classe Persona che abbia come variabili le stringhe nome e cognome. 
Si definisca una classe Automobile che abbia come variabili la stringa modello e un riferimento proprietario 
a un oggetto di tipo Persona. Definire metodi e costruttori in maniera opportuna. 
Costruire un programma che permetta 
di creare due persone e tre automobili. Dopo aver costruito le automobili, 
è possibile cambiarne i proprietari? Perché?
*/

#include <iostream>
using namespace std;

class Persona{
	public:
		string nome;
	string cognome;
		Persona(string nome,string cognome){
    		this->nome=nome;
    		this->cognome=cognome;
		}
		string getAnagrafica(){
    		cout<<" la persona si chiama"<<endl;
    		return this->nome;
		}
};

class Automobile{
	private:
		string modello;
    	Persona *proprietario;
	public:
		Automobile(string modello, Persona *proprietario){
			this->modello=modello;
			this->proprietario=proprietario;
		}
		void getDati(){
			cout<<"il modello"<<endl<<this->modello;
			cout<<" e di proprieta di"<<endl<<this->proprietario->nome<<endl<<this->proprietario->cognome<<endl;
		}
};

int main(){
	Persona p1("gabriele","riggi");
    Persona p2("matteo","vullo");
    Automobile auto1("ferrarigt",&p1);
    Automobile &ref_alias1=auto1;
    Automobile auto2("lambo",&p1);
    Automobile &ref_alias2=auto2;
    Automobile auto3("panda",&p2);
    Automobile &ref_alias3=auto3;
    ref_alias1.getDati();
    ref_alias2.getDati();
    ref_alias3.getDati();
}
