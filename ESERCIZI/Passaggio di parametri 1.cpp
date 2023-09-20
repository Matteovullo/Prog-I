#include <iostream>

using namespace std;

/*Si definisca una funzione void che che prenda in input i riferimenti a due variabili x e y di tipo double
e ne scambi i valori, mettendo in x il valore di y e in y il valore di x.*/

double func(double x,double y){
    double *ptr1=&x;
	double *ptr2=&y;
	double z=x;
	x=*ptr2;
	y=z;
	return x,y;
}

int main(){
   double a=func(5,6);
   cout<<a;

}