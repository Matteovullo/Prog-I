#include <iostream>

using namespace std;

int main(){
	/*Usa un ciclo do-while per eseguire il prodotto di due numeri interi attraverso somme successive.*/
	
	int a,b,i,p;
	
	cout<<"ins. a: " ;cin>>a;
	cout<<"ins. b: " ;cin>>b;
	
	i=0;
	p=0;
	
	do
	{
	    p+=a;
		i++;
	}
	while(i<b);
	cout<<p;
	
}
