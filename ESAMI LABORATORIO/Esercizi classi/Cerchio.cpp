/*Si costruisca una classe Cerchio che metta a disposizione metodi per calcolare il perimetro e l’area.*/

#include <iostream>

using namespace std;

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
};

int main(){
    Cerchio c(5);
    cout << c.area() << endl;
    cout << c.perimetro() << endl;
    return 0;
}