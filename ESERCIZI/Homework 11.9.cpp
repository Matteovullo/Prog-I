#include <iostream>

using namespace std;

int main(){
	//Codificare in C++ un programma che chiede all’utente di inserire due numeri decimali maggiori di zero e diversi tra 
	//loro (ES: 10.2 e 24.7), ed un numero intero N.
	//• il programma calcola lo arrotondamento per eccesso o
	//per difetto di entrambi i numeri, a seconda che la parte
	//decimale sia maggiore o uguale a 0.5 oppure minore di
	//0.5 rispettivamente. Siano a e b i due numeri ottenuti,con a < b.
	//• per ogni numero a ≤ p ≤ b, calcola e stampa la somma degli N-1 numeri minori di p e la somma dei 2N numeri maggiori di p;
	
	double a,b;
	int c,p;
	cout<<"ins. num decimale diverso da zero: " ; cin>>a;
	cout<<"ins. num decimale diverso da zero e diverso da quello precedente: " ; cin>>b;
	cout<<"ins. num intero: " ; cin>>c;
	cout<<"ins. num intero: " ; cin>>p;
	int a1=a+0.5;
	int b1=b+0.5;
	if (a1<b1)
	{
		while(a1<=p<=b1)
		{
			p--;
			p=p+p;
			cout<<p<<endl;
			p++;
			p=2*p;
			cout<<p<<endl;
		}
	}
}
