/*(Esercizio adattato da Luis Joyanes Aguilar. 
Fondamenti di programmazione in C++. Mc Graw Hill. 
Seconda Edizione)
Scrivere una classe Razionale per i numeri 
razionali, cioè i numeri he possono essere 
rappresentati come frazioni (1/2, 3/5, ecc). 
La classe deve possedere un metodo stampa che 
stampi il contenuto dell’oggetto (es. 1/2). 
Sovraccaricare i seguenti opeartori in modo 
da permettere operazioni e confronti tra 
oggetti di tipo Razionale:
==;
<;
<=;
>;
>=;
+;
-;
*;
/.
Scrivere un programma che testi la correttezza del 
codice scritto.*/

#include <iostream>
using namespace std;

class Razionale{
    int numeratore, denominatore;
    double d;

    public:
        Razionale(int numeratore, int denominatore){
            this->numeratore=numeratore;
            this->denominatore=denominatore;
            d=0;
        }
        Razionale(double d){
            this->d=d;
        }
        int getNumeratore(){
            return numeratore;
        }
        int getDenominatore(){
            return denominatore;
        }
        void swap(){
            int aux=numeratore;
            numeratore=denominatore;
            denominatore=aux;
        }
        double change(){
            double d1=numeratore/(double)denominatore;
            d=d1;
            return d1;
        }
        bool operator==(Razionale r){
            if(numeratore == r.getNumeratore() && denominatore == r.getDenominatore())
                return true;
            else
                return false;
        }
        bool operator<(Razionale r){
            if(numeratore/(double)denominatore < r.getNumeratore()/(double)r.getDenominatore())
                return true;
            else
                return false; 
        }
        bool operator<=(Razionale r){
            if(numeratore/(double)denominatore <= r.getNumeratore()/(double)r.getDenominatore())
                return true;
            else
                return false; 
        }
        bool operator>(Razionale r){
            if(numeratore/(double)denominatore > r.getNumeratore()/(double)r.getDenominatore())
                return true;
            else
                return false; 
        }
        bool operator>=(Razionale r){
            if(numeratore/(double)denominatore >= r.getNumeratore()/(double)r.getDenominatore())
                return true;
            else
                return false; 
        }
        void stampa(){
            if(d==0)
                cout << numeratore << "/" << denominatore << endl;
            else
                cout << d << endl;
        }
};


Razionale operator+(Razionale r1, Razionale r2){
    if(r1.getDenominatore() == r2.getDenominatore()){
        return Razionale(r1.getNumeratore()+r2.getNumeratore(), r1.getDenominatore());
    }else{
        return Razionale(r1.change()+r2.change());
    }
}

Razionale operator-(Razionale r1, Razionale r2){
    if(r1.getDenominatore() == r2.getDenominatore()){
        return Razionale(r1.getNumeratore()-r2.getNumeratore(), r1.getDenominatore());
    }else{
        return Razionale(r1.change()-r2.change());
    }
}

Razionale operator*(Razionale r1, Razionale r2){
    return Razionale(r1.getNumeratore()*r2.getNumeratore(), r1.getDenominatore()*r2.getDenominatore());
}

Razionale operator/(Razionale r1, Razionale r2){
    r2.swap();
    return Razionale(r1.getNumeratore()*r2.getNumeratore(), r1.getDenominatore()*r2.getDenominatore());
}

int main(){
    Razionale r1(1, 2);
    Razionale r2(1, 3);
    Razionale r3=r1+r2;
    r3.stampa();
    r3=r1-r2;
    r3.stampa();
    r3=r1*r2;
    r3.stampa();
    r3=r1/r2;
    r3.stampa();
    bool b=r1==r2;
    cout << b;
    b=r1<r2;
    cout << b;
    b=r1<=r2;
    cout << b;
    b=r1>r2;
    cout << b;
    b=r1>=r2;
    cout << b;
}   
