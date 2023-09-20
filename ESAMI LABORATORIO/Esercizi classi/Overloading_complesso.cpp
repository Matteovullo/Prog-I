/*Si recuperi la classe Complesso implementata 
in un precedente esercizio e si sovraccarichino 
gli operatori:
+;
-;
*;
<<;
*/

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
        ostream& put(ostream& os){
            os << "(" << reale << ")+i(" << immaginaria << ")" << endl;
            return os;
        }
};

ostream& operator<<(ostream& os, Complesso c){
    return c.put(os);
}

Complesso operator+(Complesso a, Complesso b){
    return Complesso(a.getReale()+b.getReale(), a.getImmaginaria()+b.getImmaginaria());
}

Complesso operator-(Complesso a, Complesso b){
    return Complesso(a.getReale()-b.getReale(), a.getImmaginaria()-b.getImmaginaria());
}

Complesso operator*(Complesso a, Complesso b){
    return Complesso(a.getReale()*b.getReale(), a.getImmaginaria()*b.getImmaginaria());
}

int main(){
    Complesso c1(2.5, 3.5);
    Complesso c2(1.5, 3.5);
    Complesso c3=c1+c2;
    cout << c3;
    c3=c1-c2;
    cout << c3;
    c3=c1*c2;
    cout << c3;
}