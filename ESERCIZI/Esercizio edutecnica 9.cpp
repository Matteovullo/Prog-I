#include <iostream>

using namespace std;

int main(){
	/*Scrivi un programma per il calcolo del fattoriale di un numero inserito da tastiera.*/
	
	int n;
	int i=1;
	int fatt=1;
	
	cout<<"ins. n: ";cin>>n;
	
	while(i<=n)
	{
		fatt=fatt*i;
		i++;
	}
	cout<<"fattoriale: "<<fatt<<endl;
}