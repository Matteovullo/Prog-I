/*Creare una classe Scatola con gli opportuni attributi e metodi, 
per ogni scatola bisognerà memorizzare la dimensione dei lati e il suo peso, 
si potrà poi avere a disposizione le caratteristiche della scatola, ovvero le dimensioni dei lati, 
l’area della base, il volume, il peso, la densità media.
Creare la classe Giocoinscatola in cui andranno memorizzate oltre alle 
nformazioni della scatola anche il numero di giocatori e il nome del gioco.
Si crei inoltre per entrambe le classi un metodo print() che permette di 
stampare a schermo i valori degli attributi dell’istanza sul quale è richiamato.
Testare le classi con un opportuno main.
Tra le prove, far inserire le informazioni di due giochi da tastiera e poi 
dire quali tra i due ha il rapporto volume/numero di giocatori maggiore.*/

#include <iostream>

using namespace std;

class Scatola{
    private:
        double altezza;
        double lunghezza;
        double profondità;
        double peso;

    public:
        Scatola(double a, double b, double c, double d) : altezza(a), lunghezza(b), profondità(c), peso(d){}
        void print(){
            cout<< altezza << endl;
            cout<< lunghezza << endl;
            cout<< profondità << endl;
            cout<< peso << endl;
        }
        double base(){
            if(lunghezza=altezza)
            return lunghezza*altezza;
            else (lunghezza*altezza) / 2;
        }
        double getPeso(){
            return peso;
        }
        double getAltezza(){
            return altezza;
        }
        double getLunghezza(){
            return lunghezza;
        }
};

class Giocoinscatola : public Scatola{
    private:
        int giocatori;
        string nome_gioco;

    public:
        Giocoinscatola(double a, double b, double c, double d, int e, string f) : Scatola(a,b,c,d){
            giocatori=e;
            nome_gioco=f;
        }
        void print(){
            Scatola::print();
            cout<< giocatori << endl;
            cout<< nome_gioco << endl;
        }
};