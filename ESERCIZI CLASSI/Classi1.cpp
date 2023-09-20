/*
Si costruisca una classe Cerchio che metta a disposizione metodi per calcolare il perimetro e l’area.
*/

#include <cmath>
#include <iostream>
#include "Classi2.cpp"
using namespace std;

class Cerchio{
	private:
		double raggio;
	public:
		Cerchio(double r){
			raggio=r;
		}
		void set_values(double x){
			raggio=x;
		}
		double perimetro(){
			return raggio*3.14*2;
		}
		double area(){
			return (pow(raggio,2))*3.14;
		}
		bool encloses(Rettangolo r){
			bool valore;
			if(area()>=r.area()){
				valore=true;
			}else{
				valore=false;
			}
			return valore;
		}
};

int main(){
	Rettangolo re(5,3);
	Cerchio ce(7);
	cout<<ce.encloses(re);
}
