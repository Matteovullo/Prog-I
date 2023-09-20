#include <iostream>

using namespace std;

int main(){
	/*Scrivere un programma che inseriti da tastiera due numeri interi da tastiera ne stampi il maggiore;
	 se i due numeri sono uguali deve essere stampata la somma dei due numeri.*/
	 
	 int a,b,somma;
	 
	 cout<<"inserisci un numero: " ; cin>>a;
	 cout<<"inserisci un numero: " ; cin>>b;
	 
	if(a==b)
 	{
	 	somma=a+b;
	 	cout<<"somma: "<<somma<<endl;
   	}
	else
 	{
	 	if(a>b)
	 	{
		 cout<<"il numero piu' alto e'': "<<a<<endl;
     	}
         	else
         	{
     		 cout<<"il numero piu' alto e': "<<b<<endl;
	     	}
 	}
	 
}