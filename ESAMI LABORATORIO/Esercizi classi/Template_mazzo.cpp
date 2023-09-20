/*Definire una classe template Mazzo che implementi 
un mazzo di carte di tipo C (C è il tipo definito 
dal template). Costruire dunque due tipi di carte 
CartaSiciliana e CartaPoker. Il costruttore di 
Mazzo costruisce il mazzo di carta in maniera 
opportuna a seconda del tipo template ricevuto 
in fase di instanziazione. 
Scrivere un programma che instanzi due mazzi 
di carte siciliane e da poker.*/

#include<string>

#define BASTONI 0
#define COPPE 1
#define ORO 2
#define SPADE 3

#define ASSO 1
#define DUE 2
#define TRE 3
#define QUATTRO 4
#define CINQUE 5
#define SEI 6
#define SETTE 7
#define DONNA 8
#define CAVALLO 9
#define RE 10
#define NUM 40

#include <iostream>
using namespace std;

class CartaSiciliana {
    short seme;
    short figura;
    public:
        CartaSiciliana(short f, short s) : seme(s), figura(f) {}
        short getSeme() {return seme;}
        short getFigura() {return figura;}
        string nome() {
            string s;

            switch(figura) {
                case ASSO:
                s+="asso";
                break;
            case DUE:
                s+="due";
                break;
            case TRE:
                s+="tre";
                break;
            case QUATTRO:
                s+="quattro";
                break;
            case CINQUE:
                s+="cinque";
                break;
            case SEI:
                s+="sei";
                break;
            case SETTE:
                s+="sette";
                break;
            case DONNA:
                s+="donna";
                break;
            case CAVALLO:
                s+="cavallo";
                break;
            case RE:
                s+="re";
                break;
            default:
                s+="figura sconosciuta";
                break;
            }

            s += " di ";

            switch (seme){
            case BASTONI:
                s += "bastoni";
                break;
            case SPADE:
                s += "spade";
                break;
            case COPPE:
                s += "coppe";
                break;
            case ORO:
                s += "oro";
                break;
            default:
                s += "seme sconosciuto";
                break;
            }
            return s;
        }
};

class CartaPoker{
    short seme;
    short figura;
    public:
        CartaPoker(short f, short s) : seme(s), figura(f) {}
        short getSeme() {return seme;}
        short getFigura() {return figura;}
};

template<typename C>
class Mazzo {
    C **carte;

    public:
        Mazzo() {
            carte=new C*[NUM];
            for(int i=0; i<NUM; i++){
                carte[i] = nullptr;
            }
        }
        C* getCarta(int i) {return carte[i];}
};

int main(){
    Mazzo<CartaSiciliana> m1;
    Mazzo<CartaPoker> m2;
}
