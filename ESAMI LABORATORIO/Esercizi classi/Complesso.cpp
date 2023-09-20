/*Creare una classe Complesso per la gestione dei 
numeri complessi (un numero complesso è costituito 
da due numeri reali double: parte reale e parte immaginaria),
Le operazioni da implementare sono le seguenti:
un costruttore che prenda in input due doble e 
inizializzi lo stato dell’oggetto;
un metodo stampa che permette di stampare 
il numero complesso;
dei metodi somma, divisione, prodotto e 
sottrazione che prendano in input un numero complesso e 
permettano di effettuare le operazioni aritmetiche 
tra l’oggetto di cui sono funzioni membro e quello 
ricevuto in input.*/

#include <iostream>

using namespace std;

class Complesso{
    private:
        double reale;
        double immaginaria;

    public:
        Complesso(){
            reale=0;
            immaginaria=0;
        }
        Complesso(double reale, double immaginaria){
            this->reale=reale;
            this->immaginaria=immaginaria;
        }
        double getReale(){
            return reale;
        }
        double getImmaginaria(){
            return immaginaria;
        }
        void stampa(){
            cout << reale << "+i(" << immaginaria << ")" << endl;
        }
        void somma(Complesso c){
            reale+=c.getReale();
            immaginaria+=c.getImmaginaria();
        }
        void differenza(Complesso c){
            reale-=c.getReale();
            immaginaria-=c.getImmaginaria();
        }
        void prodotto(Complesso c){
            reale=(reale*c.getReale())-(immaginaria*c.getImmaginaria());
            immaginaria=(reale*c.getImmaginaria())-(immaginaria*c.getReale());
        }
        void divisiome(Complesso c){
            reale=((reale*c.getReale())+(immaginaria*c.getImmaginaria()))/((c.getReale()*c.getReale())+(c.getImmaginaria()*c.getImmaginaria()));
            immaginaria=((immaginaria*c.getReale())-(reale*c.getImmaginaria()))/((c.getReale()*c.getReale())+(c.getImmaginaria()*c.getImmaginaria()));
        }
};

int main(){
    return 0;
}