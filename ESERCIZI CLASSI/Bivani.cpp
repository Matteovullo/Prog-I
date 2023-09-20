#include "Stanza.h"
#include "Persona.cpp"

class bivani{
	private:
		double superficie_;
	public: 
	    bivani(){
		}
	    void sommario(Stanza s1, Stanza s2, Bagno b){
	    	cout<<"Il bavano e' composto da: "<<endl;
	    	cout<<"1 stanza da letto di: "<<endl;
	    	cout<<s1.getSuperficie()<<" metri quadrati"<<endl;
	    	cout<<"1 stanza da letto di: "<<endl;
	    	cout<<s2.getSuperficie()<<" metri quadrati"<<endl;
	    	cout<<"1 cucina di: "<<endl;
	    	cout<<b.getSuperficie()<<" metri quadrati"<<endl;
		}
		double superficie(Stanza s1, Stanza s2, Bagno b){
			superficie_=s1.getSuperficie()+s2.getSuperficie()+b.getSuperficie();
			return superficie_;		
		}
		void propietario(Persona p){
			cout<<"Il propietario dell' appartamento e' :"<<p.getNome()<<" "<<p.getCognome()<<endl;		
		}
};