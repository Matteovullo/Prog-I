/*(Esercizio adattato da Luis Joyanes Aguilar. 
Fondamenti di programmazione in C++. Mc Graw Hill. 
Seconda Edizione)
Definire una classe base Persona che contenga un’
anagrafica generale comune a tutte le persone 
(nome, indirizzo, data di nascita, sesso, ecc.). 
Progettare una gerarchia di classi che contempli 
le seguenti classi: studente, impiegato, 
studente_impiegato. Scrivere un programma 
che legga da file informazioni per un vettore 
di persone: a) generale; b) studenti; c) impiegati; 
d) studenti impiegati.*/

#include <iostream>
using namespace std;

class Persona{
    protected:
    string nome, cognome, indirizzo, sesso;
    int data;

    public:
        Persona(string nome, string cognome, string indirizzo, string sesso, int data){
            this->nome=nome;
            this->cognome=cognome;
            this->indirizzo=indirizzo;
            this->sesso=sesso;
            this->data=data;
        }
};

class Studente : public Persona{
    public:
        Studente(string nome, string cognome, string indirizzo, string sesso, int data) : Persona(nome, cognome, indirizzo, sesso, data){}
};

class Studente_impiegato : public Persona{
    public:
        Studente_impiegato(string nome, string cognome, string indirizzo, string sesso, int data) : Persona(nome, cognome, indirizzo, sesso, data){}
};

class Impiegato : public Persona{
    public:
        Impiegato(string nome, string cognome, string indirizzo, string sesso, int data) : Persona(nome, cognome, indirizzo, sesso, data){}
};

int main(){
    Persona* vett[15];
    for(int i=0; i<15; i++){
        if(i < 5)
            vett[i]=new Studente("Matteo", "Vullo", "Contrada Fontanelle", "m", 2002);
        if(i >= 5 && i <10)
            vett[i]=new Studente_impiegato("Gabriele", "Riggi", "San Cataldo", "m", 2002);
        if(i>=10)
            vett[i]=new Impiegato("Carlo", "Spata", "Ragusa", "m", 2002);
    }
}

