#include"automobile.h"


automobile::automobile(string modello,persona *proprietario){
	this->modello=modello;
	this->proprietario=proprietario;
}
void automobile::getDati(){
	cout<<"il modello"<<endl<<this->modello;
	cout<<"e di proprieta di"<<endl<<this->proprietario->nome<<endl<<this->proprietario->cognome<<endl;
	
}
