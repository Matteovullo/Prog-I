/*Si definisca un oggetto Point2D che rappresenti 
punti nello spazio 2D a coordinate double. 
Si inseriscano dei metodi sovraccaricati 
(overloaded) per effettuare:
sum: La somma con un altro Point2D: il metodo 
deve prendere in input un Point2D e restituire 
un nuovo Point2D somma dei due punti 2D;
sum: La somma con uno scalare (tipo double).
sum: La somma dei valori delle coordinate 
(nessun input).
prod: Il prodotto con uno scalare;
prod: Il prodotto punto a punto con un altro punto 
2D (prodotto di Hadamard - 
https://en.wikipedia.org/wiki/Hadamard_product_
(matrices));
Si scriva un programma che istanzi e usi diversi 
Point2D.*/

#include <iostream>
using namespace std;

class Point2D{
        private:
            double p1,p2;

        public:
            Point2D(double p1, double p2){
                this->p1=p1;
                this->p2=p2;
            }
            void stampa(){
                cout << "(" << p1 << ", " << p2 << ")" << endl;
            }
            double getX(){
                return p1;
            }
            double getY(){
                return p2;
            }
            Point2D sum(Point2D p){
                Point2D p3(p1+p.getX(), p2+p.getY());
                return p3;
            }
            Point2D sum(double scalare){
                Point2D p3(p1+scalare, p2+scalare);
                return p3;
            }
            Point2D sum(){
                Point2D p3(p1+p2, p1+p2);
                return p3;
            }
            Point2D prod(double scalare){
                Point2D p3(p1*scalare, p2*scalare);
                return p3;
            }
            Point2D prod(Point2D p){
                Point2D p3(p1*p.getX(), p2*p.getY());
                return p3;
            }
};

int main(){
    Point2D p1(1.5, 2.5);
    Point2D p2(1.0, 2.0);
    Point2D p3(3.5, 4.5);
    Point2D sum=p1.sum(p2);
    sum.stampa();
    sum=p2.sum(2.1);
    sum.stampa();
    sum=p3.sum();
    sum.stampa();
    sum=p1.prod(1.0);
    sum.stampa();
    sum=p2.prod(p3);
    sum.stampa();
}
