/*Scrivere una classe Ora_giorno che permetta di 
rappresentare l’ora del giorno in ore e minuti 
(formato 24 ore). La classe deve sovraccaricare 
l’operatore << per stampare l’ora nel formato 
HH:MM e gli operatori ++ e -- 
(sia prefissi che postfissi) per 
incrementare/decrementare l’ora di minuti.*/

#include <iostream>
using namespace std;

class Ora_giorno{
    int ora;
    int minuti;

    public:
        Ora_giorno(){
            ora=0;
            minuti=0;
        }
        ostream& put(ostream& os){
            os << ora << ":" << minuti  << endl;
            return os;
        }
        Ora_giorno &operator++(){
            if(minuti == 60){
                minuti=1;
                ora++;
            }else if(minuti < 60){
                minuti++;
            }else{
                minuti=minuti-60;
                ora++;
            }
            return *this;
        }
        Ora_giorno operator++(int){
            Ora_giorno aux=*this;
            if(minuti == 60){
                minuti=1;
                ora++;
            }else if(minuti < 60){
                minuti++;
            }else{
                minuti=minuti-60;
                ora++;
            }
            return aux;
        }
        Ora_giorno &operator--(){
            minuti--;
            if(minuti < 0){
                ora--;
                minuti=minuti+60;
            }
            return *this;
        }
        Ora_giorno operator--(int){
            Ora_giorno aux=*this;
            minuti--;
            if(minuti < 0){
                ora--;
                minuti=minuti+60;
            }
            return aux;
        }
};

ostream& operator<<(ostream& os, Ora_giorno obj){
    return obj.put(os);
}

int main(){
    Ora_giorno o;
    o++;
    ++o;
    o--;
    --o;
    cout << o;
}
