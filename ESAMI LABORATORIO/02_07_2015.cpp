#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>
#include <string>
#include <sstream>
#include <climits>

using namespace std;

class Dipendenti{
    private:
        int ID;
        string nome;
        string cognome;
        Dipendenti *next;

    public:
        Dipendenti(int ID, string nome, string cognome){
            this->ID=ID;
            this->nome=nome;
            this->cognome=cognome;
        }
        ~Dipendenti(){}
        string getNome(){
            return nome;
        }
        string getCognome(){
            return cognome;
        }
        int getID(){
            return ID;
        }
};

class Ufficio{
    private:
        int ID;
        string nome_uff;

    protected:
        Dipendenti** elenco;
        int dim;

    public:
        Ufficio(string nome_ufficio, int ID, int dim){
            this->nome_uff=nome_ufficio;
            elenco=new Dipendenti*[dim];
            for(int i=0; i<dim; i++){
                elenco[i]=nullptr;
            }
            this->dim=dim;
        }
        ~Ufficio(){
            delete[] elenco;
        }
        void inserimento(int ID, string nome, string cognome){
            for(int i=0; i<dim; i++){
                if(elenco != nullptr){
                    elenco[i]=new Dipendenti(ID, nome, cognome);
                }
            }
        }
        void visualizza(){}
        void visualizza_elenco(int ID){
            for(int i=0; i<dim; i++){
                if(elenco[i]->getID() == ID){
                    cout << "ID corrispondente al dipentente: " << elenco[i]->getNome() << ", " << elenco[i]->getCognome() << endl;
                }
            }
        }
        void visualizza_tutto(){
            for(int i=0; i<dim; i++){
                cout << "Dipentente " << i << " : " << elenco[i]->getNome() << ", " << elenco[i]->getCognome() << ", " << elenco[i]->getID() << endl; 
            }
        }
        int getIDu(){
            return ID;
        }
        int getDim(){
            return dim;
        }
        int getDipendenti(int i){
            return elenco[i]->getID();
        }
        void set(int i){
            this->ID=i;
        }
        void uffico_in_comune(int x, int y, Ufficio &u){
            for(int i=0; i<dim; i++){
                for(int j=0; j<u.dim; j++){
                    if(getDipendenti(i) == u.getDipendenti(j)){
                        cout << "Dipendente " << (*elenco[i]).getNome() << "in comune" << endl;
                    }
                }
            }
        }
};

int main(){
    Ufficio u("Office", 1, 10);
    u.inserimento(1, "Matteo", "Vullo");
    u.inserimento(2, "Matteo", "Vullo");
    u.inserimento(3, "Matteo", "Vullo");
    u.inserimento(4, "Matteo", "Vullo");
    u.inserimento(5, "Matteo", "Vullo");
    u.inserimento(6, "Matteo", "Vullo");
    u.inserimento(7, "Matteo", "Vullo");
    u.inserimento(8, "Matteo", "Vullo");
    u.inserimento(9, "Matteo", "Vullo");
    u.inserimento(10, "Matteo", "Vullo");

    int x=10;
    int y=5;
    int c=0;
    Ufficio u2("Uffico", 20, 10);

    //punto 1
    if(u.getIDu() != x){
        for(int i=0; i<u.getDim(); i++){
            if(y != u.getDipendenti(i)){
                c++;
            }
        }
        if(c==u.getDim()){
            u2.set(x);
            u2.inserimento(y, "Matteo", "Vullo");
        }
    }

    //punto 2
    if(u.getIDu() == x){
        for(int i=0; i<u.getDim(); i++){
            if(y != u.getDipendenti(i)){
                c++;
            }
        }
        if(c==u.getDim()){
            u2.inserimento(y, "Matteo", "Vullo");
        }
    }

    //punto 3
    if(u.getIDu() != x){
        for(int i=0; i<u.getDim(); i++){
            if(y == u.getDipendenti(i)){
                u2.set(x);
                u2.inserimento(y, "Matteo", "Vullo");
            }
        }
    }

    //punto 4
    if(u2.getIDu() == x){
        for(int i=0; i<u.getDim(); i++){
            if(y == u.getDipendenti(i)){
                
            }
        }
    }

    //punto 5

    //punto b
    u.visualizza_tutto();
    u2.visualizza_tutto();
}
