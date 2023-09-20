#include <iostream>

using namespace std;

int main(){
	/*Utilizza un ciclo for realizzare un algoritmo che esegua la somma e la media di n numeri inseriti da tastiera 
	con n acquisito a sua volta da tastiera.*/
	
	int x,i,n,somma=0;
float media=0;
cout<<"n:";cin>>n;
for(i=0;i<n;i++){
     cout<<“ins:”;cin>>x;
     somma+=x;
}//fine for
media=(float)somma/n;
cout<<somma<<" -- "<<media;
}//fine main