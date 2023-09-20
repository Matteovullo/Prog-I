/*Data la classe Punto2D definita in precedenza, 
sovraccaricare gli operatori:
+ per effettuare la somma tra due punti o la 
somma tra un punto e uno scalare;
- per effettuare la differenza tra due punti 
o la differenza tra un punto e uno scalare;
* per effettuare il prodotto tra due punti o 
il prodotto tra un punto e uno scalare;
<< Per stampare una rappresentazione del punto 
(es. (2,3));*/

#include <iostream>
using namespace std;

class Point2D {
    double x, y;
    public:
        Point2D(double _x, double _y) : x(_x), y(_y) {}
        Point2D(): x(0), y(0) {}
        double getX() {return x;}
        double getY() {return y;}
        Point2D operator*(Point2D a){
            return Point2D(a.x*x, a.y*y);
        }
        Point2D operator*(double a){
            return Point2D(a*x, a*y);
        }
        friend ostream& operator<<(ostream &, Point2D);
};

ostream& operator<<(ostream &os, Point2D p){
    os << "(" << p.getX() << ", " << p.getY() << ")" << endl;
    return os;
}

Point2D operator+(Point2D a, Point2D b){
    return Point2D(a.getX()+b.getX(), a.getY()+b.getY());
}


Point2D operator+(Point2D a, double b){
    return Point2D(a.getX()+b, a.getY()+b);
}

Point2D operator-(Point2D a, Point2D b){
    return Point2D(a.getX()-b.getX(), a.getY()-b.getY());
}

Point2D operator-(Point2D a, double b){
    return Point2D(a.getX()-b, a.getY()-b);
}

int main(){
    Point2D p1(1.5, 2.5);
    Point2D p2(2.5, 3.5);
    cout<< p1;
    cout<< p2;
    Point2D p3=p1+p2;
    cout << p3;
    p3=p1-p2;
    cout << p3;
    p3=p1*p2;
    cout << p3;
    p3=p1+2.5;
    cout << p3;
    p3=p1-0.5;
    cout << p3;
    p3=p1*1.5;
    cout << p3;
}