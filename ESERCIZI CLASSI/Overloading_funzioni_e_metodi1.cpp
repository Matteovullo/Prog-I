/*
Si definisca un oggetto Point2D che rappresenti punti nello spazio 2D a coordinate double. 
Si inseriscano dei metodi sovraccaricati (overloaded) per effettuare:
sum: La somma con un altro Point2D: il metodo deve prendere in input un Point2D e restituire un nuovo Point2D somma dei due punti 2D;
sum: La somma con uno scalare (tipo double).
sum: La somma dei valori delle coordinate (nessun input).
prod: Il prodotto con uno scalare;
prod: Il prodotto punto a punto con un altro punto 2D 
(prodotto di Hadamard - https://en.wikipedia.org/wiki/Hadamard_product_(matrices));
Si scriva un programma che istanzi e usi diversi Point2D.
*/

#include <iostream>
using namespace std;

class Point2D{
	double x;
	double y;
	public:
		Point2D(double x, double y){
			this->x=x;
			this->y=y;
		}
		double getx(){return x;}
		double gety(){return y;}
		Point2D sum(Point2D p){
			Point2D s(p.getx()+getx(), p.getx()+getx());
			return s;
		}
		Point2D sum(double h){
			Point2D s(getx()+h, gety()+h);
			return s;
		}
		double sum(){
			double s=getx()+gety();
			return s;
		}
		Point2D prod(double h){
			Point2D s(getx()*h, gety()*h);
			return s;
		}
		Point2D prod(Point2D p){
			Point2D s(p.getx()*getx(), p.getx()*getx());
			return s;
		}
};

int main(){
	Point2D p1(2.5,1.5);
	Point2D p2(2.5,1.5);
	//cout<<p1.sum(p2);
	//cout<<p1.sum(1.5);
	//cout<<p1.getx()<<endl;
	//cout<<p1.sum();
	Point2D p3(2.5,1.5);
	//cout<<p1.getx()<<endl;
	//cout<<p3.gety()<<endl;
	//cout<<p1.sum();
	p1.prod(2);
	cout<<p1.getx();
}
