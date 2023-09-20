/*Si costruisca una classe Rectangle che metta a disposizione metodi per calcolare perimetro e area. 
Si modifichi la classe Cicle (si veda l’esercizio precedente) inserendo un metodo encloses 
che prende in input un oggetto di classe Rectangle e restituisce 
true se il rettanglo è completamente contenuto all’interno del cerchio.*/

#include <iostream>

using namespace std;

class Rettangolo{
    private:
        double altezza;
        double base;

    public:
        Rettangolo(int a, int b) : altezza(a), base(b) {}
        double perimetro(){
            return (base+altezza)*2;
        }
        double area(){
            return base*altezza;
        }
};

class Cerchio{
    private:
        double raggio;
        const double pi=3.14;

    public:
        Cerchio(double r) : raggio(r) {}
        double perimetro(){
            return 2*pi*raggio;
        }
        double area(){
            return (raggio*raggio)*pi;
        }
        bool encloses(Rettangolo r){
            if(r.area() < area())
                return true;
            else
                return false;
        }
};

int main(){
    Cerchio c(1);
    Rettangolo r(2, 3);
    cout << c.encloses(r) << endl;
}

