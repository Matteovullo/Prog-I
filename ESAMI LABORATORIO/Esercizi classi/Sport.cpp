/*Progettare una gerarchia di classi con la classe 
base Sport, dalla quale derivano le clasis Calcio, 
Pallacanestro, Pallavvolo.*/

#include <iostream>
using namespace std;

class Sport{
    protected:
        string nome;

    public:
        Sport(string nome){
            this->nome=nome;
        }
        virtual void stampa()=0;
};

class Calcio : public Sport{
    private:
        const int giocatori=11;

    public:
        Calcio(string nome) : Sport(nome){}
        void stampa(){
            cout << "Sport calcio, nome squadra: " << nome << endl;
        }
};

class Pallacanestro : public Sport{
    private:
        const int giocatori=5;

    public:
        Pallacanestro(string nome) : Sport(nome){}
        void stampa(){
            cout << "Sport pallacanestro, nome squadra: " << nome << endl;
        }
};

class Pallavolo : public Sport{
    private:
        const int giocatori=7;

    public:
        Pallavolo(string nome) : Sport(nome){}
        void stampa(){
            cout << "Sport pallavolo, nome squadra: " << nome << endl;
        }
};

int main(){
    Calcio c("A");
    Pallacanestro p("B");
    Pallavolo pa("C");
    c.stampa();
    p.stampa();
    pa.stampa();
}
