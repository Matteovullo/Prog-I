#include <iostream>

using namespace std;

int main(){
	/*Utilizza un ciclo while per dividere due interi attraverso sottrazioni successive, fornendo in uscita il quoto e il resto della divisione.*/
	
	int n,d;
	int q=0,r=0;
	
	cout<<"ins. n: " ; cin>>n;
	cout<<"isn. d: " ; cin>>d;
	
	while(n>=d){
		n-=d;
		q++;
	}
	r=n;
	cout<<q<<" "<<r;
}