#include <iostream>

using namespace std;

int main(){
	/*Scrivi un algoritmo che inseriti due numeri interi da tastiera esegua :
A)La loro somma se uno dei due è pari.
B)Il loro prodotto se tutti e due sono pari.
C)La loro divisione se nessuno dei due è pari.*/

int a,b,somma,prodotto,divisione;
cout<<"ins. a: " ;cin>>a;
cout<<"ins. b: " ;cin>>b;

if (a%2==0 || b%2==0)
{
somma=a+b;
cout<<somma;
}

if(a%2==0 && b%2==0)
{
prodotto=a*b;
cout<<prodotto;
}

if(a%2!=0 && b%2!=0)
{
	divisione=a/b,
	cout<<divisione;
}

}

