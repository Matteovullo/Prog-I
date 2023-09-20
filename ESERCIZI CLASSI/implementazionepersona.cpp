#include "definizionepersona.h"


persona::persona(string nome,string cognome){
    this->nome=nome;
    this->cognome=cognome;
}

string persona::getAnagrafica(){
    cout<<" la persona si chiama"<<endl;
    return this->nome;

}
