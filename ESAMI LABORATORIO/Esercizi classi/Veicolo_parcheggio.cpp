/*Si costruisca una classe Veicolo con i seguenti attributi:
modello;
numero di ruote;
tipologia 
(può essere motociclo, automobile, furgone o mezzo pesante).
Si costruisca dunque una classe Parcheggio con i 
seguenti attributi:
capienza;
indirizzo;
un array di puntatori a Veicolo.
La classe Parcheggio 
deve possedere dei metodi che permettono di:
inserire un veicolo nel parcheggio 
(prende in input un puntatore a Veicolo e restituisce 
il numero di stallo);
rimuovere un veicolo dal parcheggio 
(prende in input il numero di stallo e restituisce un 
puntatore a Veicolo);
calcolare la tariffa dato un veicolo e un numero di giorno. 
La tariffa è ottenuta moltiplicando il numero di giorni 
per 4.5 per le automobili, 3.5 per i motocicli, 
5 per i furgoni e 7 per i mezzi pesanti;
contare quanti veicoli sono presenti nel parcheggio;
calcolare il numero di stalli liberi;
restituire il numero del primo stallo libero.
I metodi implementati devono effettuare i controlli necessari 
per assicurarsi che gli inserimenti e le rimozioni siano 
consistenti (es. controllare che non si ecceda la capienza 
massima).*/

#include <iostream>

using namespace std;

class Veicolo{
    private:
        string modello;
        int ruote;
        string tipologia;

    public:
        Veicolo(string modello, int ruote, string tipologia){
            this->modello=modello;
            this->ruote=ruote;
            this->tipologia=tipologia;
        }
        string getTipologia(){
            return tipologia;
        }
};

class Parcheggio{
    private:
        int capienza;
        int indirizzo;
        Veicolo **v;

    public:
        Parcheggio(int capienza, int indirizzo){
            this->capienza=capienza;
            this->indirizzo=indirizzo;
            v=new Veicolo*[capienza];
            for(int i=0; i<capienza; i++){
                v[i]=nullptr;
            }
        }
        int inserire(Veicolo *p){
            for(int i=0; i<capienza; i++){
                if(v[i]==nullptr){
                    v[i]=p;
                    return i;
                }
            }
            return -1;
        }
        Veicolo* rimuovere(int i){
            if(i < capienza){
                Veicolo *p=v[i];
                v[i]=nullptr;
                return p;
            }
            return nullptr;
        }
        double tariffa(int i, int g){
            if(i < capienza){
                if(v[i]->getTipologia() == "automobile"){
                    return g*4.5;
                }
                if(v[i]->getTipologia() == "motciclo"){
                    return g*3.5;
                }
                if(v[i]->getTipologia() == "furgone"){
                    return g*5;
                }
            }
            return -1;
        }
        int numero_veicolo(){
            int c=0;
            for(int i=0; i<capienza; i++){
                if(v[i])
                    c++;
            }
            return c;
        }
        int stalli_liberi(){
            int c=0;
            for(int i=0; i<capienza; i++){
                if(v[i]==nullptr)
                    c++;
            }
            return c;
        }
        int primo(){
            for(int i=0; i<capienza; i++){
                if(v[i]==nullptr)
                    return i;
            }
            return -1;
        }
};

int main(){
    Parcheggio p(10, 1);
    Veicolo v("Audi", 4, "automobile");
    Veicolo *ptr=&v;
    p.inserire(ptr);
    cout << p.primo() << endl;
    cout << p.stalli_liberi() << endl;
    cout << p.numero_veicolo() << endl;
    cout << p.tariffa(0, 10) << endl;
    p.rimuovere(0);
    cout << p.stalli_liberi() << endl;
}