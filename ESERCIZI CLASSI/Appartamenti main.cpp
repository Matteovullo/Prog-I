#include "Appartamento.cpp"

int main(){
	Persona p1("Matteo","Vullo", 19);
	Persona p2("Valentino", "Vacirca", 20);
	Stanza s1("stanza da letto",5.0,3.0);
	Stanza s2("cucina",6.0,4.0);
	Bagno b(2.0,3.0);
	Bivani biv;
	biv.sommario(s1,s2,b);
	cout<<biv.superficie(s1,s2,b)<<endl;
	biv.propietario(p1);
}
