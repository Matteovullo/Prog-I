#include "Stanza.h"
#include "Persona.cpp"

class Trivani{
	private:
		double superficie_;
	public:
		Trivani(){}
		double superdicie(Stanza s1, Stanza s2, Stanza s3, Bagno b){
			superficie_=s1.getSuperficie()+s2.getSuperficie()+s3.getSuperficie()+b.getSuperficie();
			return superficie_;		
		}	
		void propietario(Persona p){
			cout<<"L' appartamento e' di: "<<p.getNome()<<" "<<p.getCognome()<<endl;
		}
		void sommario(Stanza s1, Stanza s2, Stanza s3, Bagno b){
			cout<<"L' appartamento e' composto da: "<<endl;
			cout<<"1 stanza da letto di dimenzioni: ";
			cout<<s1.getSuperficie()<<" metri quarati"<<endl;
			cout<<"1 stanza da letto di dimenzioni: "<<endl;
			cout<<s2.getSuperficie()<<" metri quarati"<<endl;
			cout<<"1 stanza cucina di dimenzioni: "<<endl;
			cout<<s3.getSuperficie()<<" metri quarati"<<endl;
			cout<<"1 bagno di dimenzioni: "<<endl;
			cout<<b.getSuperficie()<<" metri quarati"<<endl;
		}
};