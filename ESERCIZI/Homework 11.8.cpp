#include <iostream>
#include <cmath>
using namespace std;

int main(){
	//Codificare in linguaggio C++ un algoritmo che stampi le prime N potenze di 2, dove N `e un parametro scelto dall’utente(input da tastiera).
	int n,potenza,pot;
	pot=1;
	cout<<"ins. n: "; cin>>n;
	while (pot<=n)
	{
		potenza=pow(2,pot);
		pot++;
		cout<<potenza<<endl;
	}
}