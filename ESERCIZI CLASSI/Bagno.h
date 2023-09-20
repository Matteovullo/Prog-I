#include<iostream>
using namespace std;

class Bagno{
	private:
		double n;
		double m;
	public: 
	    Bagno(double n, double m){
	    	this->n = n;
			this->m = m;
		}
		
		void calcola_superficie(){
			cout<<"La superficie del bagno e' :"<<n*m<<endl;
		}
		double getSuperficie(){return n*m;}
};