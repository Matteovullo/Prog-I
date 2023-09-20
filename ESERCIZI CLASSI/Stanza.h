#include <iostream>
#include <string>
using namespace std;

#include "bagno.h"

class Stanza{
	private: 
	    string nome;
	    double n;
	    double m;
	    
	public:
		Stanza(string nome, double n, double m){
			this->nome = nome;
			this->n = n;
			this->m = m;
		}
		
		string get_nome(){
			return nome;
		}
		
		void calcola_superficie(){
			cout<<"La superficie della stanza e' :"<<n*m<<endl;
		}
		double getSuperficie(){return n*m;}
};
