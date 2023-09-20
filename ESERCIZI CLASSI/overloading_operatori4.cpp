/*
Data la classe Punto2D definita in precedenza, sovraccaricare gli operatori:

+ per effettuare la somma tra due punti o la somma tra un punto e uno scalare;

- per effettuare la differenza tra due punti o la differenza tra un punto e uno scalare;

* per effettuare il prodotto tra due punti o il prodotto tra un punto e uno scalare;

<< Per stampare una rappresentazione del punto (es. (2,3));
*/
#include<iostream>
using namespace std;

class Point2D {
    double x, y;
    public:
        Point2D(double _x, double _y) : x(_x), y(_y) {}
        Point2D(): x(0), y(0) {}
        double getX() {return x;}
        double getY() {return y;}
        friend Point2D operator+(Point2D, Point2D);
        friend Point2D operator+(Point2D, double s);
        friend Point2D operator-(Point2D, Point2D);
        friend Point2D operator-(Point2D, double s);
        friend Point2D operator*(Point2D, Point2D);
        friend Point2D operator*(Point2D, double s);
        ostream& operator<<(ostream &s, Point2D p);
};

Point2D operator+(Point2D a, Point2D b){
    return Point2D(a.x+b.x, a.y+b.y);
}

Point2D operator+(Point2D a, double s){
    return Point2D(a.x+s, a.y+s);
}

Point2D operator-(Point2D a, Point2D b){
    return Point2D(a.x-b.x, a.y-b.y);
}

Point2D operator+(Point2D a, double s){
    return Point2D(a.x-s, a.y-s);
}

Point2D operator*(Point2D a, Point2D b){
    return Point2D(a.x*b.x, a.y*b.y);
}

Point2D operator*(Point2D a, double s){
    return Point2D(a.x*s, a.y+s);
}

ostream& operator<<(ostream &s, Point2D p) {
    s << "(" << p.x << "," << p.y << ")";
    return s;
}

int main() {
    Point2D p1(2,3);
    Point2D p2(3,3);

    Point2D p3 = p1+p2;
    cout << "("<<p3.getX() << "," << p3.getY() << ")" << endl;
}