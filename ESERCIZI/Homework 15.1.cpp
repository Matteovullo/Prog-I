#include <iostream>

using namespace std;

int main(){
	//Scrivere un programma in C++ nel quale si chiede all’utente un numero qualunque p. Successivamente:
	//• Se il numero p `e minore di 1, stampare un messaggio di errore.
	//• Se il numero p `e maggiore o uguale a 1, arrotondare il numero
	//stesso allo intero pi`u vicino e allocare un array di quella dimensione.
	//• Inizializzare lo array con valori a piacere per tre volte mediante un ciclo: i) con il costrutto for, ii) con il costrutto
	//while, iii) con il costrutto do-while.
	//• Stampare tutti i valori dello array con un ciclo usando un costrutto a scelta.
	
	int p;
	cout<<"ins p: "; cin>>p;
	if (p<1)
	{
		cout<<"errore!"<<endl;
	}
	else
	{
		int p1=p+0.5;
		int V[p1];
		int i=0;
		while(i<p1)
		{
			i++;
			V[i]=i*2;
		}
		
		
		for(int i; i<p1; i++)
		{
			V[i]=i*2;
			cout<<V[i]<<endl;
		}
		
		
		do 
		{
			int i=0;
		}while(i<p1);
		{
			V[i]=i*2;
			i++;
		}
	}
}
