/*Creare una classe Matita che serve per rappresentare delle matite e memorizzarne la lunghezza.
Creare una sottoclasse MatitaConGommino che serve per rappresentare delle matite con gommino, 
la classe memorizza le caratteristiche delle matite e il numero cancellature rimaste a 
disposizione tramite il gommino (tali matite partono con 10 possibilità di cancellature).*/

#include <iostream>

using namespace std;

class Matita{
    private:
        int len;

    public:
        Matita(int l) : len(l) {}
        int getLen(){
            return len;
        }
};

class Matitacongommino : public Matita{
    private:
        bool *vet;

    public:
        Matitacongommino(int m) : Matita(m){
            vet=new bool [10];
            for(int i=0; i<10; i++){
                vet[i]=true;
            }
        }
        int getLengommino(){
            return getLen();
        }
        int cancellature(){
            int c=0;
            for(int i=0; i<10; i++){
                if(vet[i]==true){
                    c++;
                }
            }
            return c;
        }
        void cancellare(int l){
            int c=0;
            for(int i=0; i<10; i++){
                if(vet[i]==true && c<l)
                    vet[i]==false;
                    c++;
            }
        }
};
