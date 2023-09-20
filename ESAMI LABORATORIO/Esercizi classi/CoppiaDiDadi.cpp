/*Progettare e implementare una classe CoppiaDiDadi composta 
da due oggetti Dado a sei facce. Creare un file main.cpp che 
implementi una funzione main che tiri più volte l’oggetto 
CoppiaDiDadi contando il numero di doppi sei realizzati.*/

#include <iostream>
using namespace std;
#include<ctime>

class Dado {
    private:
        short valore; //questo attributo contiene il valore attuale del dado
                      //si tratta del valore della faccia rivolta verso l'alto
    public:
        Dado(); //costruttore di default
        Dado(time_t); //costruttore alternativo che permette di impostare un particolare seed
        void lancia(); //lancia il dado
        short getValore(); //legge il valore del dado
};

Dado::Dado() {
    // imposta il seed di default
    srand(time(0));
    lancia(); //lanciamo il dado appena creato
}

Dado::Dado(time_t seed) {
    srand(seed); //impostiamo il seed ricevuto in input
    lancia(); //lanciamo il dado appena creato
}

void Dado::lancia() {
    valore = rand()%6 + 1 ; //numero casuale tra 1 e 6
}

short Dado::getValore() {
    return valore;
}

class CoppiaDiDadi{
    private:
        Dado d1;
        Dado d2;

    public:
        CoppiaDiDadi(){}
        void lanciac(){
            d1.lancia();
            d2.lancia();
        }
        short get1(){
            return d1.getValore();
        }
        short get2(){
            return d2.getValore();
        }
};

int main(){
    CoppiaDiDadi c;
    int count=0;
    for(int i=0; i<10; i++){
        c.lanciac();
        if(c.get1() == c.get2())
            count++;
    }
    cout << count << endl;
}
