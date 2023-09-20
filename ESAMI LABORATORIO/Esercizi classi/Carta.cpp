/*Progettare e implementare una classe Carta che 
rappresenti una carta da gioco. Ogni carta deve avere 
un seme e un valore. Definire dunque una classe Mazzo 
che rappresenti un mazzo di 40 carte. Il mazzo deve 
permettere di estrarre casualmente una carta, contare 
il numero di carte rimanenti e rimescolare le carte. 
Scrivere un programma che permetta di giocare contro 
il computer al gioco “sette e mezzo”.
NOTA: si implementi l’esercizio in maniera indipendente 
dagli esempi visti durante le lezioni di laboratorio.*/

#include <iostream>

using namespace std;

class Carta{
    protected:
        string seme;
        short valore;

    public:
        Carta(string seme, short valore){
            this->seme=seme;
            this->valore=valore;
        }
        short getValore(){
            return valore;
        }
};

class Mazzo{
    private:
        Carta **mazzo;
        int const dim=40;

    public:
        Mazzo(){
            mazzo=new Carta*[dim];
            for(int i=0; i<40; i++){
                int c=1;
                if(i>0 && i<10){
                    mazzo[i]=new Carta("Oro", c);
                    c++;
                }
                if(i == 10)
                    c=1;
                if(i>10 && i<20){
                    mazzo[i]=new Carta("Bastoni", c);
                    c++;
                }
                if(i == 20)
                    c=1;
                if(i>10 && i<20){
                    mazzo[i]=new Carta("Spade", c);
                    c++;
                }
                if(i == 30)
                    c=1;
                if(i>10 && i<20){
                    mazzo[i]=new Carta("Coppe", c);
                    c++;
                }
            }
        }
        int contacarte(){
            int c=0;
            for(int i=0; i<dim; i++){
                if(mazzo[i])
                    c++;
            }
            return c;
        }
        Carta* estrarre(){
            int r=0;
            do{
              r=rand()%(39-0+1)+1;  
            }while(mazzo[r]==nullptr);
            Carta *ptr;
            ptr=mazzo[r];
            mazzo[r]=nullptr;
            return ptr;
        }
        void reset(){
            for(int i=0; i<dim; i++){
                mazzo[i]=nullptr;
            }
            for(int i=0; i<40; i++){
                int c=1;
                if(i>0 && i<10){
                    mazzo[i]=new Carta("Oro", c);
                    c++;
                }
                if(i == 10)
                    c=1;
                if(i>10 && i<20){
                    mazzo[i]=new Carta("Bastoni", c);
                    c++;
                }
                if(i == 20)
                    c=1;
                if(i>10 && i<20){
                    mazzo[i]=new Carta("Spade", c);
                    c++;
                }
                if(i == 30)
                    c=1;
                if(i>10 && i<20){
                    mazzo[i]=new Carta("Coppe", c);
                    c++;
                }
            }
        }
        void mescolare(){
            reset();
            for(int i=0; i<dim; i++){
                if(mazzo[i]){
                    Carta *ptr=mazzo[i];
                    int r=rand()%(39-0+1)+1;
                    while(mazzo[r]){
                        r=rand()%(39-0+1)+1;
                    }
                    mazzo[i]=mazzo[r];
                    mazzo[r]=ptr;
                }
            }
        }
};

int main(){
    Mazzo m;
    double punteggio=0;
    while(punteggio < 7.5){
        bool c=true;
        do{
            cout << "Estrarre carta?" << endl;
            cin >> c;
            Carta *ptr=m.estrarre();
            punteggio+=ptr->getValore();
        }while(c);
    }
    if(punteggio >= 7.5){
        cout << "Hai perso, rirovare" << endl;
    }else{
        cout << "Punteggio ottenuto: " << punteggio << endl;
    }
}