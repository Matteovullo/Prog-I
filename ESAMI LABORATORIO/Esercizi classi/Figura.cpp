/*Dichiarare la classe astratta Figura con le 
funzioni virtuali area e perimetro che abbia 
come classi derivate le figure geometriche 
cerchio, quadrato e rettangolo.*/

#include <iostream>
using namespace std;

class Figura{
    public:
        Figura(){}
        virtual double perimetro()=0;
        virtual double area()=0;
};

class Cerchio : public Figura{
    private:
        const double pi=3.14;
        double raggio;

    public:
        Cerchio(double raggio) : Figura(){
            this->raggio=raggio;
        }
        double perimetro(){
            return 2*pi*raggio;
        }
        double area(){
            return pi*raggio*raggio;
        }
};

class Quadrato : public Figura{
    private:
        double lato;

    public:
        Quadrato(double lato) : Figura(){
            this->lato=lato;
        }
        double perimetro(){
            return lato*4;
        }
        double area(){
            return lato*lato;
        }
};

class Rettangolo : public Figura{
    private:
        double altezza, base;

    public:
        Rettangolo(double altezza, double base){
            this->altezza=altezza;
            this->base=base;
        }
        double perimetro(){
            return (base+altezza)*2;
        }
        double area(){
            return base*altezza;
        }
};

int main(){
    Cerchio c(2.0);
    Quadrato q(2.0);
    Rettangolo r(2.0, 3.0);
    cout << c.perimetro() << endl;
    cout << c.area() << endl;
    cout << q.perimetro() << endl;
    cout << q.area() << endl;
    cout << r.perimetro() << endl;
    cout << r.area() << endl;
}
