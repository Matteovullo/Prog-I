#include "GiornoMeseAnno.cpp"

class Data{
	private:
	public:	
		Data(){
		}		
		void stampa(Giorno g, Mese m, Anno a){          
			cout<<g.getGiornoDellaSettimana()<<" "<<g.getGiorno()<<" "<<m.getMese()<<" "<<a.getAnno()<<endl;
		}
		void differenza(Data d, Giorno g, Mese m, Anno a){
		}
};

int main(){
	Giorno a(20, "lunedi");
	Mese b(1, "genaio");
	Anno c(2222);
	Data d;
	d.stampa(a,b,c);  
}