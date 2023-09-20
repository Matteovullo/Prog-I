#include <iostream>
#include <cmath>
using namespace std;
int main (){
	float cateto_a,cateto_b,ipotenusa,somma;
	cout <<"inserire cateto a: "; cin >> cateto_a;
	cout <<"inserire cateto b: "; cin >> cateto_b;
	
	if(cateto_a>0 && cateto_b>0){
		
		cateto_a=pow(cateto_a,2);
		cateto_b=pow(cateto_b,2);
		somma=cateto_a+cateto_b;
		ipotenusa=sqrt(somma);
		
	cout << "Il valore dell'ipotenusa e': " << ipotenusa;
	 }
	 else{
		cout << "inserisci solo valori positivi, ritenta";}
}