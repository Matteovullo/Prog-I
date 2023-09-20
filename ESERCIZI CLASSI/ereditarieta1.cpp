/*Definire una classe base Persona che contenga un’anagrafica generale comune a tutte 
le persone (nome, indirizzo, data di nascita, sesso, ecc.). Progettare una gerarchia di 
classi che contempli le seguenti classi: studente, impiegato, studente_impiegato. 
Scrivere un programma che legga da file informazioni per un vettore di persone: 
a) generale; b) studenti; c) impiegati; d) studenti impiegati.*/

#include <iostream>
using namespace std;

class Persona{
    string nome;
    string cognome;
    string indirizzo;
    string sesso;
    int data;
    public:
        Persona(string nome, stirng cognome, string indirizzo, string sesso, int data){
            this->nome=nome;
            this->cognome=cognome;
            this->indirizzo=indirizzo;
            this->sesso=sesso;
            this->data=data;
        }
        void stampa(){
            cout<<nome<<","<<cognome<<","<<indirizzo<<","<<sesso<<","<<data<<endl;
        }

};

class Studente: public Persona{
    public:
    Studente(string nome, stirng cognome, string indirizzo, string sesso, int data){
            this->nome=nome;
            this->cognome=cognome;
            this->indirizzo=indirizzo;
            this->sesso=sesso;
            this->data=data;
        }
};

class Impegato: public Studente{
    public:
    Impiegato(string nome, stirng cognome, string indirizzo, string sesso, int data){
            this->nome=nome;
            this->cognome=cognome;
            this->indirizzo=indirizzo;
            this->sesso=sesso;
            this->data=data;
        }
};

class Studente_impiegato: public Persona, public Studente, public Impiegato{
    public:
    Studente_Impiegato(string nome, stirng cognome, string indirizzo, string sesso, int data){
            this->nome=nome;
            this->cognome=cognome;
            this->indirizzo=indirizzo;
            this->sesso=sesso;
            this->data=data;
        }
};

int main(){
    Studente s("Matteo","Vullo","Via PaoloBentivoglio","maschio",2002);
    s.stampa();
}
