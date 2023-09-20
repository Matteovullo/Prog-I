/*Creare una classe Ora che abbia membri dati di tipo 
int per ore, minuti e secondi. Un costruttore inizializzerà 
questi dati a 0, mentre un altro li inizializzerà a valori 
passati al costruttore. Una funzione membro dovrà 
visualizzare l’ora in formato 11:59:59. Un’altra funzione 
membro sommerà l’oggetto di tipo Ora a un altro oggetto 
di tipo Ora preso in input come argomento. Una funzione 
principale main() deve creare due oggetti inizializzati 
con valori passati al costruttore e un terzo inizializzato 
con zeri. Stampare i valori dei tre oggetti, poi sommare 
il secondo al primo e il secondo al terzo e stampare i 
valori del primo e del terzo.*/

#include <iostream>

using namespace std;

class Ora{
    private:
        int ora;
        int minuti;
        int secondi;

    public:
        Ora(){
            ora=0;
            minuti=0;
            secondi=0;
        }
        Ora(int ora, int minuti, int secondi){
            this->ora=ora;
            this->minuti=minuti;
            this->secondi=secondi;
        }
        int getOra(){
            return ora;
        }
        int getMinuti(){
            return minuti;
        }
        int getSecondi(){
            return secondi;
        }
        void stampa(){
            cout << ora << ":" << minuti << ":" << secondi << endl;
        }
        void somma(Ora o){
            ora+=o.getOra();
            if(ora > 12)
                ora=ora%12;
            minuti+=o.getMinuti();
            if(minuti > 60){
                minuti=minuti%60;
                ora++;
            }
            secondi+=o.getSecondi();
            if(secondi > 60){
                secondi=secondi%60;
                minuti++;
            }
        }
};

int main(){
    Ora o1(10, 2, 30);
    Ora o2(11, 59, 57);
    Ora o3;
    o1.stampa();
    o2.stampa();
    o3.stampa();
    o1.somma(o2);
    o3.somma(o2);
    o1.stampa();
    o3.stampa();
}