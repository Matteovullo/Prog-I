/*Si definisca una classe Persona che abbia come variabili le stringhe nome e cognome. 
Si definisca una classe Automobile che abbia come variabili la stringa modello e un riferimento 
proprietario a un oggetto di tipo Persona. Definire metodi e costruttori in maniera opportuna. 
Costruire un programma che permetta di creare due persone e tre automobili. 
Dopo aver costruito le automobili, è possibile cambiarne i proprietari? Perché?*/
//No, perche un reference deve essere inizializzata contestualmente alla sua creazione, e non puo essere cambiata.

#include <iostream>
using namespace std;

class Persona{
    private:
        string nome,cognome;

    public:
        Persona(string nome, string cognome){
            this->nome=nome;
            this->cognome=cognome;
        }
};

class Automobile{
    private:
        string modello;
        Persona *propitario;

    public:
        Automobile(string modello, Persona *p){
            this->modello=modello;
            propitario=p;
        }
        void change(Persona *p){
            propitario=p;
        }
};

int main(){
    Persona p1("Matteo", "Vullo");
    Persona p2("Matteo", "Vullo");
    Automobile a1("Audi", &p1);
    Automobile a2("Audi", &p2);
    Automobile a3("Audi", &p1);
    a1.change(&p1);
}